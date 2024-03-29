#include "pch.h"
#include "CppUnitTest.h"
#include "../Library/Ticks.h"

using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(TicksTest) {
public:

	TEST_METHOD(CapacityTest) {
		auto sut = Ticks();

		auto expected = sut.capacity;
		auto actual = sut.prices.capacity();

		Assert::AreEqual(expected, actual);
	}

	TEST_METHOD(AddTest) {
		string line("AAAAAA 3000 10 1000000000");
		auto m = TickMsg::Parse(line);

		auto sut = Ticks();
		sut.AddTick(m);

		Assert::AreEqual(m.timestamp, sut.timestamp);
		Assert::AreEqual(m.price, sut.prices.front());
		Assert::AreEqual(m.price, sut.prices.data()[0]);
		Assert::AreEqual(m.quantity, sut.quantities.front());
		Assert::AreEqual(m.quantity, sut.quantities.data()[0]);

		// when timestamp is same, subsequent request should update bought_price and add quantity
		m.price *= 2;
		Assert::IsFalse(sut.AddTick(m));
		Assert::AreEqual(m.price, sut.prices.back());
		Assert::AreEqual(m.quantity * 2, sut.quantities.back());
	}

	TEST_METHOD(AddTest_Multiple) {
		auto count = 1000 * 1000;
		auto line = "AAAAAA 3000 10 1000000000";
		auto msg = TickMsg::Parse(line);

		auto sut = Ticks();
		// TODO use parallel_for
		for (auto i = 0; i < count; i++) {
			msg.timestamp += i;
			sut.AddTick(msg);
		}

		auto expected = count % (sut.capacity - sut.kNumKeep);
		auto actual = sut.prices.size();

		Assert::AreEqual(expected, actual);
	}
};
