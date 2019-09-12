#pragma once
#include <windows.h>

#include <pjsua2.hpp>
#include <iostream>
class MyAccount;
using namespace pj;

class MyCall : public Call
{
private:
	MyAccount* myAcc;
public:
	bool isHold = false;
	bool isMuted = false;
	bool isDeafened = false;
	AudioMedia& play_dev_med = Endpoint::instance().audDevManager().getPlaybackDevMedia();
	AudioMedia& cap_dev_med = Endpoint::instance().audDevManager().getCaptureDevMedia();
	AudioMedia aud_med;
	MyCall(Account& acc, int call_id = PJSUA_INVALID_ID);
	~MyCall();
	virtual void onCallState(OnCallStateParam& prm);
	virtual void onCallMediaState(OnCallMediaStateParam& prm);
};