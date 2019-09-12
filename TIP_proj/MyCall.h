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
	MyCall(Account& acc, int call_id = PJSUA_INVALID_ID);
	~MyCall();
	virtual void onCallState(OnCallStateParam& prm);
	virtual void onCallMediaState(OnCallMediaStateParam& prm);
};