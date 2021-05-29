/*

Min Swaps : Given an array of size N, find the minimum number of swaps needed to make the array as sorted.

Sample Input
a = [5,4,3,2,1]

sample Output
2

Note: Sorting does not gurantee min swap

Sol:
- E.g arr = {2, 4, 5, 1, 3}
- We must know correct position of every element. Done by sorting O(N*logN).
- Find non intersecting cycles. For each cycle lo length N swaps required is N-1.
- E.g [2,4,5,1,3] one cycle(2,1,4) other cycle(5,3). Total swaps 2+1 = 3
- Complexity  = O(nlog(N) + N)

*/


#include "iostream"
#include "algorithm"
#include <vector>

using namespace std;


int minSwap(vector<int> arr) {

	int n = arr.size();

	pair<int, int> pr[n];

	for (int i = 0; i < n; i++) {

		pr[i].first = arr[i];
		pr[i].second = i;

	}

	sort(pr , pr + n);

	int result = 0;
	vector<bool> visited(n, false);

	// Main Function

	for (int i = 0; i < n; i++) {

		if ((visited[i] == true) or (i == pr[i].second)) continue;

		int count = 0;
		int next = i;
		while (visited[next] == false) {

			visited[next] = true;
			count++;
			next = pr[next].second;
		}

		result = result + count - 1;

	}

	return result;
}

int main() {

	vector<int> arr = {2, 4, 5, 1, 3};

	int result = minSwap(arr);
	cout << "Min. no. of swap is : " << result << endl;

	return 0;
}