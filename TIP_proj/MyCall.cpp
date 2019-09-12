#include "MyCall.h"
#include "LoginWindow.h"

MyCall::MyCall(Account& acc, int call_id): Call(acc, call_id)
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
	CallInfo ci = getInfo();
	aud_med = getAudioMedia(-1);

	// And this will connect the call audio media to the sound device/speaker
	cap_dev_med.startTransmit(aud_med);
	aud_med.startTransmit(play_dev_med);
}