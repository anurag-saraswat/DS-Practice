#include "iostream"
#include "vector"
using namespace std;


int main() {

	vector<int> arr = {1, 2, 3, 4, 5, 10};

	// insert at end in constant time
	arr.push_back(15);
	arr.pop_back();//Size of vector
	cout << "Size of vector is : " << arr.size() << endl;

	//Size of vector
	cout << "Capicity of vector is : " << arr.capacity() << endl;


	//Printing elemnt of vector
	cout << "Element of array ";
	for (int i = 0 ; i < arr.size(); i++) {
		cout << arr[i] << ' ';

	}
	cout << endl << endl;


	//fill constructor
	//10 element with each value 7
	vector<int> arr1(10, 7);

	//Printing elemnt of vector
	cout << "Element of array ";
	for (int i = 0 ; i < arr1.size(); i++) {
		cout << arr1[i] << ' ';
	}
	cout << endl << endl;


	// 2-D Vector
	// Vector of vectors

	vector<vector<int>> arr2D = {
		{1, 2, 3, 4, 5},
		{1, 2, 3, 4},
		{1, 2, 3},
		{1, 2},
		{1}
	};

	//Printing Element od 2D Array
	cout << "Printing Element of 2D arrays";

	for (int i = 0; i < arr2D.size(); i++) {

		for (auto j : arr2D[i]) {
			cout << j << ' ';
		}
		cout << endl;

	}




	cout << endl;
	return 0;
}