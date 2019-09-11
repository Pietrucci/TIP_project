#pragma once
#include <windows.h>
#include <pjsua2.hpp>
#include <iostream>
#include "MyCall.h"
using namespace pj;

class MyAccount : public Account
{
public:
	std::vector<Call*> calls;

public:
	MyAccount();
	~MyAccount();

	void removeCall(Call* call);
	virtual void onRegState(OnRegStateParam& prm);
	virtual void onIncomingCall(OnIncomingCallParam& iprm);
};

