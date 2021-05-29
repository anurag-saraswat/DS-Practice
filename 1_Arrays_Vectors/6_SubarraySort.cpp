/*

Subarray Sort : Given an array of size atleast 2, find the smallest subarray that needs to be sorted in place so that entire input array becomes sorted.
if the input array is already sorted, the function should return[-1,-1], otherwiise return the start and end index of smallest subarray.

Sample Input
a1 = [1,2,3,4,5,8,6,7,9,10,11]

sample Output
[5,7]

1. Fist approach is to sort array and then compare element to find fist and last misplaced element.
    require O(n*logn + n)time and O(n) space complexity.
2. Second approach find maximum and minimum misplaced element.
3. Find index of misplaced element greater than minimum from left and vice versa from left.
*/

#include "iostream"
#include<vector>
#include <algorithm>
#include <climits>

using namespace std;


bool check(vector<int> arr , int index) {

	if (index == 0) {
		if (arr[index] > arr[index + 1]) return true;
	}

	else if (index == arr.size() - 1) {
		if (arr[index - 1] > arr[index]) return true;
	}

	else if ((arr[index - 1] > arr[index]) or arr[index + 1] < arr[index]) return true;


	return false;

}

pair<int, int> SubArraySort(vector<int> arr) {


	int minimum = INT_MAX;
	int maximum = INT_MIN;

	for (int i = 0; i < arr.size(); i++) {

		//cout << i << " " << check(arr, i) << endl;

		if (check(arr, i)) {
			maximum = max(maximum, arr[i]);
			minimum = min(minimum, arr[i]);
		}
	}


	int max = arr.size() - 1;
	while (arr[max] > maximum) {
		max--;
	}

	int min = 0;
	while (arr[min] < minimum) {
		min++;
	}



	return {min, max};


}


int main() {

	vector<int> arr = {1, 2, 3, 4, 5, 8, 6, 7, 9, 10, 11};

	auto result = SubArraySort(arr);

	cout << result.first << " " << result.second << endl;


	return 0;
}