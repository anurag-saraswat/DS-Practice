/*
Rains :
Given n non - negative integers representing an elevation map where width of each bar is 1,
compute how much water it can trap after raining.

solution: Compute left and right array

left = max(arr[i],arr[i-1]) starting from left
right = max(arr[size-i],arr[size-i-1]) starting from right

solution += min(left,right)- current height

*/


#include "iostream"
#include "vector"

using namespace std;

int rains(vector<int> arr) {

	int capacity = 0;
	int size = arr.size();

	vector<int> left(size, 0), right(size, 0);

	left[0] = arr[0];
	right[size - 1] = arr[size - 1];

	for (int i = 1; i < size; i++ ) {

		left[i] = max(left[i - 1], arr[i]);

		right[size - i - 1] = max(right[size - i], arr[size - i - 1]);

	}

	for (int i = 0; i < size; i++) {

		capacity += min(left[i], right[i]) - arr[i];

	}

	return capacity;
}

int main() {

	vector<int> arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

	auto result = rains(arr);

	cout << result << endl;

	return 0;
}