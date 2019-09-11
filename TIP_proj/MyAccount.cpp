#include "MyAccount.h"
#include "LoginWindow.h"
MyAccount::MyAccount()
{}
using namespace System::Windows::Forms;

MyAccount::~MyAccount()
{
	std::cout << "*** Account is being deleted: No of calls="
		<< calls.size() << std::endl;

	for (std::vector<Call*>::iterator it = calls.begin();
		it != calls.end(); )
	{
		delete (*it);
		it = calls.erase(it);
	}
}

void MyAccount::removeCall(Call* call)
{
	for (std::vector<Call*>::iterator it = calls.begin();
		it != calls.end(); ++it)
	{
		if (*it == call) {
			calls.erase(it);
			break;
		}
	}
}

void MyAccount::onRegState(OnRegStateParam& prm)
{
	AccountInfo ai = getInfo();
	std::cout << (ai.regIsActive ? "*** Register: code=" : "*** Unregister: code=")
		<< prm.code << std::endl;

}

void MyAccount::onIncomingCall(OnIncomingCallParam& iprm)
{
	Call* call = new MyCall(*this, iprm.callId);
	CallInfo ci = call->getInfo();
	CallOpParam prm;
	std::string s = "Answer " + ci.remoteUri + "?";
	System::String^ remUri = gcnew System::String(s.c_str());
	if (MessageBox::Show(remUri, "Incoming call", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == DialogResult::Yes)
	{
		calls.push_back(call);
		prm.statusCode = (pjsip_status_code)200;
		call->answer(prm);
	}
	else
	{
		prm.statusCode = PJSIP_SC_DECLINE;

		call->hangup(prm);
		delete call;
	}

}