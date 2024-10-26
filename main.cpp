// COMSC-210 | Lab 25 | Vevaan Verma
#include <chrono>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <list>
#include <set>
#include <fstream>
using namespace std;
using namespace std::chrono;

enum DataStructure { VECTOR, LIST, SET }; // this enum is used to specify the data structure to use; it adds more convenience and readability to the code

/* FUNCTION PROTOTYPES */
long long raceReading(DataStructure dataStructure);
long long raceSorting(DataStructure dataStructure);

/* CONSTANTS */
const string FILE_NAME = "codes.txt"; // file name

/* GLOBAL VARIABLES */
ifstream fin;

// main() is the entry point of the program and drives the program
// arguments: none
// returns: int - the exit code of the program
int main() {

	fin.open(FILE_NAME); // open file

	if (!fin) { // if file does not exist

		cout << "Error: File " << FILE_NAME << " not found." << endl; // output error message
		return 1; // return error code

	}

	cout << setw(10) << "Operation" << setw(10) << "Vector" << setw(10) << "List" << setw(10) << "Set" << endl; // output header
	cout << setw(10) << "Read" << setw(10) << raceReading(VECTOR) << setw(10) << raceReading(LIST) << setw(10) << raceReading(SET) << endl; // output read duration

	fin.close(); // close file

	return 0;

}

// raceReading() reads codes from a file and stores them in a data structure
// arguments: DataStructure dataStructure - the data structure to store the codes in
// returns: long long - the duration of the operation in milliseconds
long long raceReading(DataStructure dataStructure) {

	fin.seekg(0, ios::beg); // go to beginning of file

	string code; // to hold the input codes
	auto start = high_resolution_clock::now(); // start time

	// this series of if statements can be replaced with a switch statement, but you can't create vectors or lists in a switch statement (I wasn't aware that this was a thing, but Visual Studio gives an error when I try to do so)
	if (dataStructure == VECTOR) { // if data structure is vector

		vector<string> v;

		while (!fin.eof()) { // while the end of the file has not been reached

			fin >> code; // read code
			v.push_back(code); // add code to vector

		}
	} else if (dataStructure == LIST) { // if data structure is list

		list<string> l;

		while (!fin.eof()) { // while the end of the file has not been reached

			fin >> code; // read code
			l.push_back(code); // add code to list

		}
	} else if (dataStructure == SET) { // if data structure is set

		set<string> s;

		while (!fin.eof()) { // while the end of the file has not been reached

			fin >> code; // read code
			s.insert(code); // add code to set

		}
	}

	auto end = high_resolution_clock::now(); // end time
	auto duration = duration_cast<milliseconds>(end - start); // duration
	return duration.count(); // return duration

}

// raceSorting() reads codes from a file, stores them in a data structure, and then sorts them
// arguments: DataStructure dataStructure - the data structure to store the codes in
// returns: long long - the duration of the operation in milliseconds
long long raceSorting(DataStructure dataStructure) {

	fin.seekg(0, ios::beg); // go to beginning of file

	string code; // to hold the input codes
	auto start = high_resolution_clock::now(); // start time

	// once again, this series of if statements can be replaced with a switch statement, but you can't create vectors or lists in a switch statement
	if (dataStructure == VECTOR) { // if data structure is vector

		vector<string> v;

		while (!fin.eof()) { // while the end of the file has not been reached

			fin >> code; // read code
			v.push_back(code); // add code to vector

		}

		sort(v.begin(), v.end()); // sort vector

	} else if (dataStructure == LIST) { // if data structure is list

		list<string> l;

		while (!fin.eof()) { // while the end of the file has not been reached

			fin >> code; // read code
			l.push_back(code); // add code to list

		}

		l.sort(); // sort list

	} else if (dataStructure == SET) { // if data structure is set

		return -1; // return -1 because sets are already sorted

	}

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