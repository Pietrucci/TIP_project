#include "MyCall.h"
#include "LoginWindow.h"

MyCall::MyCall(Account& acc, int call_id)
	: Call(acc, call_id)
{
	myAcc = (MyAccount*)& acc;
}

MyCall::~MyCall()
{
}

void MyCall::onCallState(OnCallStateParam& prm)
{
	PJ_UNUSED_ARG(prm);

	CallInfo ci = getInfo();
	std::cout << "*** Call: " << ci.remoteUri << " [" << ci.stateText
		<< "]" << std::endl;
}

void MyCall::onCallMediaState(OnCallMediaStateParam& prm)
{
	PJ_UNUSED_ARG(prm);

	unsigned i;
	CallInfo ci = getInfo();
	AudioMedia aud_med;
	AudioMedia& play_dev_med =
		Endpoint::instance().audDevManager().getPlaybackDevMedia();
	AudioMedia& cap_dev_med = Endpoint::instance().audDevManager().getCaptureDevMedia();

	try {
		// Get the first audio media
		aud_med = getAudioMedia(-1);
	}
	catch (...) {
		std::cout << "Failed to get audio media" << std::endl;
		return;
	}
	// And this will connect the call audio media to the sound device/speaker
	cap_dev_med.startTransmit(aud_med);
	aud_med.startTransmit(play_dev_med);
}