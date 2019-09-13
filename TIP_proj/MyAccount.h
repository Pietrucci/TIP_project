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
	//TIPproj::LoginWindow^ ref;
	//std::shared_ptr<TIPproj::LoginWindow> ref;

	//MyAccount(TIPproj::LoginWindow^ x) {
	//	auto y = x;
	//	//ref = x;

	//}

	//MyAccount(std::shared_ptr<TIPproj::LoginWindow> x) {
	//	auto y = x;
	//	ref = x;

	//}
public:

	virtual void onRegState(OnRegStateParam& prm);
	virtual void onIncomingCall(OnIncomingCallParam& iprm);
};

