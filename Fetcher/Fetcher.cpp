#include "pch.h"

using namespace std;
using namespace concurrency;

int main() {
	cout << "Starting Fetcher..." << endl;

	int major = 0;
	int minor = 0;
	int patch = 0;
	zmq_version(&major, &minor, &patch);
	clog << "ZeroMQ version: " << major << '.' << minor << '.' << patch << '\n';

	return EXIT_SUCCESS;
}


//while (true) {
//	try {
//		clog << "Getting a message..." << endl;
//		string line;
//		source_.getline(line);
//		auto msg = TickMsg::Parse(line);

//		if (getline(msgFile, line)) {
//			clog << "Got a message: " << line << endl;
//		} else {
//			clog << "End of file" << endl;
//			line = "QUIT";
//		}
		//if (holdingMap.contains(msg.symbol) 
	//	&& msg.bought_price <= holdingMap[msg.symbol].stoploss())
	//{
	//	std::clog << "Hits stoploss" << std::endl;
	//	// TODO Calculate quantity to sell; How will calculate the quantity?
	//	broker->Order(msg.symbol, -1);
	//}



//		// TODO send a message somewhere
//	} catch (ParsingException& ex) {
//		clog << "Ignored wrong message: " << ex.what() << endl;
//		continue;
//	} catch (QuitException) {
//		clog << "Quitting" << endl;
//		break;
//	}