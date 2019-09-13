#include "MyAccount.h"

using namespace System::Windows::Forms;

void MyAccount::onRegState(OnRegStateParam& prm)
{
	AccountInfo ai = getInfo();
	std::cout << (ai.regIsActive ? "*** Register: code=" : "*** Unregister: code=") << prm.code << std::endl;
	
}

void MyAccount::onIncomingCall(OnIncomingCallParam& iprm)
{
	MyCall* call = new MyCall(*this, iprm.callId);
	CallInfo ci = call->getInfo();
	CallOpParam prm;
	std::string s = "Answer " + ci.remoteUri + "?";
	System::String^ remUri = gcnew System::String(s.c_str());
	if (MessageBox::Show(remUri, "Incoming call", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == DialogResult::Yes)
	{
		active_call = call;
		prm.statusCode = (pjsip_status_code)200;
		active_call->answer(prm);
	}
	else
	{
		prm.statusCode = PJSIP_SC_DECLINE;
		call->answer(prm);
		call->hangup(prm);
		delete call;
	}

}