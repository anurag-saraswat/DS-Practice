/*
Given an array containing N integers, and an number S denoting a target sum.
Find two distinct integers that can pair up to form target sum.
 */

#include "iostream"
#include <vector>
#include <unordered_set>
using namespace std;


vector<pair<int, int>> findSol(vector<int> arr , int sum) {

	vector<pair<int, int>> res;
	unordered_set<int> s;

	for (auto i : arr) {

		int num = sum - i;

		if (s.find(num) != s.end()) {

			pair<int, int> p1(num, i);
			res.push_back(p1);
		}
		s.insert(i);
	}
	return res;
}

int main() {

	vector<int> arr = {1, 2, 16, 4, 5, -6, 7, 8, 9};
	int sum = 10;

	auto res =  findSol(arr, sum);

	for (auto i : res) {
		cout << i.first << " " << i.second << endl;
	}
	return 0;
}