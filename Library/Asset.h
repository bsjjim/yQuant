#pragma once
#include "pch.h"
#include "../Library/Holding.h"

using namespace std;
using namespace concurrency;

class Asset {
public:
	Asset(double cash);

	// TODO Asset(cash, socketTickFetcher, socketOrderProcessor)
	// TODO Consider the persistence of Cash. e.g. Load from a file or something 
	// TODO Subscribe holdings_ from TickFetcher
	// TODO Compare the current bought_price to calculated stoploss bought_price
	// TODO When stoploss activated, Send an Order

	void Bought(const string& symbol, double quantity, double bought_price);
	void Sold(const string& symbol, double quantity, double bought_price);
	double GetTotalRisk();

	double cash() const;
	double quantity(const string& symbol) const;
	double bought_price(const string& symbol) const;

private:
	atomic<double> cash_;
	concurrent_unordered_map<string, Holding> holdings_;
};

