/*
Minimum Difference :
Implement a function that takes in two non-empty arrays of integers,
finds the pair of number(one from each array) who absolute difference is closest to zero,
and returns a pair containing theses two numbers, with the first number from array.
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include <cmath>
using namespace std;


pair<int, int> minDifference(vector<int> a, vector<int> b) {
    //Complete this method

    pair<int, int> ans;
    int min = INT_MAX;
    for (auto i : a) {
        for (auto j : b) {

            if (abs(i - j) < min) {
                ans.first = i;
                ans.second = j;
                min = abs(i - j);
            }

            //cout << i << " " << j << " " << abs(i - j) << " " << min << endl;
        }
    }
    return ans;
}

int main() {

    vector<int> arr1 = {23, 5, 10, 17, 13};
    vector<int> arr2 = {26, 134, 135, 14, 19};

    auto res = minDifference(arr1, arr2);
    cout << res.first << " " << res.second << endl;

    return 0;
}