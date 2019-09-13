#pragma once
#include <windows.h>
#include <pjsua2.hpp>
#include <iostream>
#include "ReferenceClass.h"
#include "MyCall.h"
using namespace pj;


class MyAccount : public Account
{
public:
	std::vector<Buddy*> buddies;
	MyCall* active_call;
public:

	virtual void onRegState(OnRegStateParam& prm);
	virtual void onIncomingCall(OnIncomingCallParam& iprm);
};

