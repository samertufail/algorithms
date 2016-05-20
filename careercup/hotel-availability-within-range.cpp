#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <set>
#include <math.h>
#include <cassert>
#include <ctime>
#include <fstream>
#include <sstream>
using namespace std;

/*
You are building a small command-line application to calculate hotel availability for a city.
Your application reads in two (2) data files, and outputs its answer to STDOUT.
Your application will read in:
· a list of hotels along with how many rooms each contains (in no particular order)
· a list of bookings that have been made (in no particular order)
Your application will then print the list of all hotels which have availability for check-in and check- out date range,
if any.
Do not worry about whether a specific room is available in a hotel for the entire booking period without switching rooms:
availability is defined as the hotel having at least one (1) available room for each night of the target stay,
regardless of whether it's the same room from day to day.

Data Files
hotels.csv
# Name, Rooms
Westin, 10
Best Western, 20
Hilton, 10
...

bookings.csv
# Name, Checkin, Checkout
Hilton, 2015-04-02, 2015-04-03
Hilton, 2015-04-02, 2015-04-04
Westin, 2015-05-01, 2015-05-20
*/

struct Schedule
{
	int date_;
	unsigned int occupancy_;
	int maxRoomsOccupied_;
	Schedule(int date, unsigned int occupancy) : date_(date), occupancy_(occupancy), maxRoomsOccupied_(0) {}
};

class Availiblity {
private:
	unordered_map<string, pair<int,vector<Schedule>>> hotelMap_; // key: Hotel Name - value: pair<rooms,schedule list>

	// Sorts a structure of schedule which holds checkin/out dates
	static bool sortSchedule(const Schedule &a, const Schedule &b)
	{
		return a.date_ < b.date_;
	}

	// Converts a string date of format 2015-03-02 to 20150302
	int NormalizeDate(string date)
	{
		stringstream dateStream(date); string year, month, day;
		getline(dateStream, year, '-'); getline(dateStream, month, '-'); getline(dateStream, day, '-');
		string conv(year + month + day);
		return stoi(conv);
	}

	void LoadData()
	{
		ifstream hotelsFile("K:/hotels.csv"); string line;
		// Get hotels data
		while (getline(hotelsFile, line))
		{
			stringstream lineStream(line);
			string name = "", rooms = "";
			getline(lineStream, name, ','); getline(lineStream, rooms, ',');
			hotelMap_[name] = make_pair<int, vector<Schedule>>(stoi(rooms), {});
		}

		// Get bookings data
		ifstream bookingsFile("K:/bookings.csv");
		while (getline(bookingsFile, line))
		{
			stringstream lineStream(line); string name = "", checkin = "", checkout = "";
			getline(lineStream, name, ','); getline(lineStream, checkin, ','); getline(lineStream, checkout, ',');
			hotelMap_[name].second.push_back(Schedule(NormalizeDate(checkin), 1));
			hotelMap_[name].second.push_back(Schedule(NormalizeDate(checkout), 0));
		}

		// Sort the rooms by date and at each date keep track of availabile and occupied rooms
		auto endMap = hotelMap_.end();
		for (auto it = hotelMap_.begin(); it != endMap; ++it)
		{
			sort((*it).second.second.begin(), (*it).second.second.end(), sortSchedule);
			int size = (*it).second.second.size(); int count = 0;
			for (int i = 0; i < size; ++i)
			{
				if ((*it).second.second[i].occupancy_ == 1)
				{ 
					count++; (*it).second.second[i].maxRoomsOccupied_ = count;
				}
				else
				{
					--count; (*it).second.second[i].maxRoomsOccupied_ = count;
				}
			}
		}
	}
public:
	Availiblity() { LoadData(); }

	// Will print availbility of all hotels within the date range
	void GetAvailibility(string startDate, string endDate)
	{
		int start = NormalizeDate(startDate); int end = NormalizeDate(endDate);
		if (start > end) { cout << "Checkin date is > checkout date" << endl; return; }
		// Sort the rooms by date and at each date keep track of availabile and occupied rooms
		auto endMap = hotelMap_.end();
		for (auto it = hotelMap_.begin(); it != endMap; ++it)
		{
			int size = (*it).second.second.size(); int maxCount = INT_MIN;
			for (int i = 0; i < size; ++i)
			{
				Schedule sched = (*it).second.second[i]; 
				// Get the Max Available
				if ((sched.date_ >= start && sched.date_ <= end) || sched.date_ <= start || sched.date_ >= end)
					maxCount = max(maxCount, sched.maxRoomsOccupied_);
			}

			if ((*it).second.first > maxCount)
				cout << (*it).first << " is available" << endl;
		}
	}
};

void runTests()
{
	Availiblity avail;
	avail.GetAvailibility("2015-04-20", "2015-04-22");
}

int main(int argc, char *argv[]) {
	runTests();
	getchar();
}