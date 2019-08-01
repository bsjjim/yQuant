#pragma once
#include "pch.h"
#include "Asset.h"
#include "Msg.h"

using namespace std;
using namespace concurrency;

class Broker : public agent {
public:
	Broker(Asset& asset, ISource<Msg>& source, ITarget<Msg>& target);
	~Broker();

protected:
	void run() override;

	Asset& asset_;
	ISource<Msg>& source_;
	ITarget<Msg>& target_;

	static shared_ptr<spdlog::logger> logger;
};

