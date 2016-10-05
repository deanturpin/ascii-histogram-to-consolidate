#include <algorithm>
#include <iostream>
#include <unistd.h>
#include <map>

#include "sequence.h"

int main() {

	using namespace std;

	// Create histogram
	map<unsigned int, unsigned int> histogram;
	for (const auto &s : seq::uence)
		++histogram[s / 1200];

	// Fade each bin and delete when empty
	while (histogram.size()) {

		// Print histogram
		for_each (histogram.cbegin(), histogram.cend(), [] (auto &h) {
			cout << h.first << '\t' << string(h.second * 8, '-') << "| " << h.first << endl;
		});

		// Decrement each bin
		for (auto &h : histogram) {

			--h.second;

			if (0 == h.second)
				histogram.erase(h.first);
		}

		// Jump to top of screen
		cout << "\x1b[A";
		cout << "\033[2J";

		usleep(500000);
	}

	cout << "C'est fini" << endl;

	return 0;
}
