#pragma once

#include "pch.h"
#include "Exceptions.h"

using namespace std;

struct SignalMsg {
	SignalMsg(const string& symbol, int strength)
		: symbol_(symbol), strength_(strength) {};

	// TODO Rename or override with << 
	const string& ToString() const {
		throw runtime_error("Not Implemented");
	};

	// TODO implement
	static SignalMsg Parse(const string& line) {
		throw runtime_error("Not Implemented");
		return SignalMsg("", 0);
	};

private:
	string symbol_;
	int strength_;
};
