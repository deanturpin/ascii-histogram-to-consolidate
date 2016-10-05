#include <iostream>
#include <map>
#include <unistd.h>

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
		cout << h.first << '\t' << string(h.second * 8, '-') << "| " << h.first << endl;

	// Fade each bin and delete when empty
	while (histogram.size()) {

		// Decrement
		// for_each
		for (auto &h : histogram) {
			--h.second;

			if (0 == h.second)
				histogram.erase(h.first);
		}

		// Jump to top of screen
		cout << "\x1b[A";
		cout << "\033[2J";

		for (const auto &h : histogram)
			cout << h.first << '\t' << string(h.second * 8, '-') << "| " << h.first << endl;

		usleep(500000);
	}

	cout << "C'est fini" << endl;

	return 0;
}
