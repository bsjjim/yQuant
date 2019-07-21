#include "pch.h"
#include "Broker.h"

Broker::Broker(Asset& asset, ISource<Msg>& source)
	: asset_(asset)
	, source_(source)
	, logger(spdlog::stdout_color_mt("broker")) {

	logger->debug("Initializing");
}

void Broker::run() {
	logger->info("Started");
	while (true) {
		auto msg = receive(source_);

		logger->trace("Ordered: {}", msg.order_quantity);
		msg.filled_quantity = 2;
	}


	done();
}

 