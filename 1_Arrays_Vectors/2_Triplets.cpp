/*
     Given an array containing N integers and a number S denoting a target sum.
     Find all distinct integers that can add up to form target sum. The number in each triplet shpuld be orderd ascending order and
     triplet sould be ordered to. Return empty array if no. such triplet exists.
 */


#include "iostream"
#include <algorithm>
#include <vector>

using namespace std;


vector<vector<int>> findTriplet(vector<int> arr, int sum) {

	vector<vector<int>> result;
	sort(arr.begin(), arr.end());

	for (int i = 0; i < (arr.size() - 3); i++) {

		int j = i + 1;
		int k = arr.size() - 1;

		while (j < k) {
			int temp_sum = arr[i] + arr[j] + arr[k];
			if (temp_sum == sum) {
				vector<int> ans = {arr[i] , arr[j] , arr[k]};
				result.push_back(ans);
				break;
			}
			else if (sum > temp_sum) {
				j++;
			}
			else {
				k--;
			}
		}

	}
	return result;
}


int main() {

	vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 0};
	int sum = 10;
	auto result = findTriplet(arr, 10);

	for (auto i : result) {
		for (auto j : i) {
			cout << j << "  ";
		}
		cout << endl;
	}

	return 0;
}