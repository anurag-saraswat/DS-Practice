/*
Frequency Count
Guive a sorted array which can contain repeated elements, and an element K, we need to find the frequency of a given element
input : [0,1,1,1,1,2,2,2,3,4,4,5,10]

first approach: Linear Search O(1) complexity

second approach: Find first occurence nad last occurence using Binary search

 */

#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

int firstOccur(vector<int> arr , int key) {

	int ans = -1;

	int s = 0, e = arr.size() - 1;

	while (s < e) {

		int m = (s + e) ;

		if (arr[m] == key) {
			e = m - 1;
			ans = m;
		}

		if (arr[m] < key) {
			s = m + 1;
		}
		else {
			e = m - 1;
		}


	}


	return ans;
}

int lastOccur(vector<int> arr , int key) {

	int ans = -1;

	int s = 0, e = arr.size() - 1;

	while (s < e) {

		int m = (s + e) ;

		if (arr[m] == key) {
			s = m + 1;
			ans = m;
		}

		if (arr[m] < key) {
			s = m + 1;
		}
		else {
			e = m - 1;
		}


	}


	return ans;
}

int main() {

	vector<int> arr = {0, 1, 1, 1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 4, 5, 10};
	int key = 3;

	if (lastOccur(arr, key) != -1 ) {
		cout << "Occurence of key " << key << " is " << lastOccur(arr, key) - firstOccur(arr, key) + 1 << endl;

		// In one line Using STL
		cout << "Occurence of key " << key << " is " << upper_bound(arr.begin(), arr.end(), key) - lower_bound(arr.begin(), arr.end(), key) << endl;
	}
	else {
		cout << "key not present" << endl;
	}

	return 0;
}