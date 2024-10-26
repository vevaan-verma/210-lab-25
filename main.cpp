// COMSC-210 | Lab 25 | Vevaan Verma
#include <chrono>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
using namespace std::chrono;

/* FUNCTION PROTOTYPES */
long long raceVector();

// main() is the entry point of the program and drives the program
// arguments: none
// returns: int - the exit code of the program
int main() {

	cout << "Time taken by vector: " << raceVector() << " milliseconds" << endl; // output duration

	return 0;

}

long long raceVector() {

	auto start = high_resolution_clock::now(); // start time

	vector<int> v;

	auto end = high_resolution_clock::now(); // end time
	auto duration = duration_cast<milliseconds>(end - start); // duration
	return duration.count(); // return duration

}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/