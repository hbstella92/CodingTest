#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class UndergroundSystem {
public:
	unordered_map<int, pair<string, int>> customer;
	unordered_map<string, pair<int, int>> station;

	UndergroundSystem() {

	}

	void checkIn(int id, string stationName, int t) {
		customer[id] = make_pair(stationName, t);
	}

	void checkOut(int id, string stationName, int t) {
		string start = customer[id].first;
		int stime = customer[id].second;

		string info = start + '_' + stationName;
		station[info].first++;
		station[info].second += (t - stime);
	}

	double getAverageTime(string startStation, string endStation) {
		string info = startStation + '_' + endStation;
		int num_people = station[info].first;
		int total_hour = station[info].second;
		return (double)total_hour / num_people;
	}
};

int main() {
	UndergroundSystem* obj = new UndergroundSystem();
	obj->checkIn(45, "Leyton", 3);
	obj->checkIn(32, "Paradise", 8);
	obj->checkIn(27, "Leyton", 10);
	obj->checkOut(45, "Waterloo", 15);
	obj->checkOut(27, "Waterloo", 20);
	obj->checkOut(32, "Cambridge", 22);

	double ans = obj->getAverageTime("Paradise", "Cambridge");
	cout << ans << endl; // 14.00000

	ans = obj->getAverageTime("Leyton", "Waterloo");
	cout << ans << endl; // 11.00000

	obj->checkIn(10, "Leyton", 24);
	ans = obj->getAverageTime("Leyton", "Waterloo");
	cout << ans << endl; // 11.00000

	obj->checkOut(10, "Waterloo", 38);
	ans = obj->getAverageTime("Leyton", "Waterloo");
	cout << ans << endl; // 12.00000

	return 0;
}