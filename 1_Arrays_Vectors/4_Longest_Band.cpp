/*

Longest Band :
Given an array containing N integers, find length of longest band.
Band is defined as a subsequence which can be reordered in such a manner all element appear consecutive(i.e with absolute difference of 1 between meighbouring elements).
A longest band is the band(subsequence) which contains maximum integers.

*/


#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


int largestBand(vector<int> arr) {

	int largest = 0;
	unordered_set<int> s;

	for (auto i : arr) {
		s.insert(i);
	}

	for (auto i : arr) {
		int parent = i - 1;

		// Checking if parent exist
		if (s.find(parent) == s.end()) {
			int len = 0;
			int temp = i;
			while (s.find(temp) != s.end()) {
				len++;
				temp++;
			}
			largest = max(largest, len);
		}

	}

	return largest;
}

int main() {

	vector<int> arr = {1, 9, 3, 0, 18, 5, 2, 4, 10, 7, 12, 6};

	auto res = largestBand(arr);
	cout << "Largest Band is of length: " << res << endl;

	return 0;
}