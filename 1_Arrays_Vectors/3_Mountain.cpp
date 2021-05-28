/*
     Write a function that takes input an array of distinct integers and returns the length of highest mountain.
     A mountain is defined as adjacent integers that are strictly increasing until they reach apeak at which it becomes strictly decreasing.
     Atleast 3 no. are required to form mountain.
 */

#include<iostream>
#include<vector>

using namespace std;


int mountain(vector<int> arr) {

	int largest = 0;

	for (int i = 1; i < arr.size() - 1;) {

		//Check for peak
		if (arr[i] > arr[i + 1] and arr[i] > arr[i - 1]) {

			int j = i;
			int len = 1;

			// Counting left
			while (j > 1 and arr[j] > arr[j - 1]) {
				j--;
				len++;
			}

			//counting right

			while ((i < arr.size() - 1) and (arr[i] > arr[i + 1])) {
				i++;
				len++;
			}

			largest = max(largest, len);


		}

		i++;

	}

	return largest ;

}

int main() {

	vector <int> arr = {5, 6, 1, 2, 3, 4, 5, 4, 3, 2, 0, 1, 2, 3, -2, 4};

	auto result = mountain(arr);
	cout << result << endl;

	return 0;
}