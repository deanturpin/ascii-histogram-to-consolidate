#include <iostream>
#include <map>

#include "sequence.h"

int main() {

	using namespace std;

	// Create histogram
	map<unsigned int, unsigned int> histogram;
	for (const auto &s : seq::uence)
		++histogram[s / 1200];

	// Print histogram
	cout << "Size of histogram " << histogram.size() << endl;
	for (const auto &h : histogram)
		cout << h.first << '\t' << string(h.second * 8, '-') << '|' << endl;

	return 0;
}
