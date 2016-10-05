#include <iostream>
#include <vector>
#include <map>

int main() {

	using namespace std;

	struct packet {

		struct range {

			unsigned int min;
			unsigned int max;
			unsigned int interval;
		};

		range a;
		range b;
		range c;
	};

	// Create a batch of packets
	vector<packet> batch;
	
	batch.push_back({{20, 20, 1}, {2, 3, 1}, {2, 3, 1}});
	batch.push_back({{2, 2, 1}, {4, 4, 2}, {1, 9, 2}});
	batch.push_back({{2, 6, 1}, {2, 2, 1}, {2, 2, 1}});
	batch.push_back({{4, 9, 1}, {4, 4, 1}, {5, 9, 1}});

	// Create a histogram
	map<unsigned int, unsigned int> histogram;

	// Populate histogram
	for (const auto &p : batch)
		for (auto int i = p.a.min; i <= p.a.max; i += p.a.interval)
			++histogram[i];

	// Print histogram
	cout << "Size of histogram " << histogram.size() << endl;
	for (const auto &h : histogram)
		cout << h.first << '\t' << string(h.second * 10, '-') << "| " << h.second << endl;

	return 0;
}
