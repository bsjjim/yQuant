#include "pch.h"
#include "Ticks.h"

using namespace std;

Ticks::Ticks() : capacity(rand() % 9999 + 9999) {
	prices.reserve(capacity);
	quantities.reserve(capacity);
}

bool Ticks::AddTick(const TickMsg& m) {
	bool added = false;

	if (timestamp == m.timestamp) {
		prices.back() = m.price;
		quantities.back() += m.quantity;
	} else {
		AddValue(prices, m.price);
		AddValue(quantities, m.quantity);
		timestamp = m.timestamp;
		added = true;
	}

	return added;
}

void Ticks::AddValue(vector<double>& v, double value) {
	if (v.capacity() == v.size())
		DeleteOld(v, kNumKeep);
	v.emplace_back(value);
}

void Ticks::DeleteOld(vector<double>& v, size_t num_keep) {
	copy(v.end() - num_keep, v.end(), v.begin());
	v.erase(v.begin() + num_keep, v.end());
}

