#include<iostream>
#include<vector>

using namespace std;


bool canThreePartsEqualSum(vector<int>& arr) {

    int sum = 0;
    for (int i = 0; i < arr.size(); i++) {
        sum = sum + arr[i];
    }

    if (sum % 3 != 0) return false;

    int first = -1;
    int second = -1;

    int first_sum = sum / 3;
    int second_sum = 2 * first_sum;

    sum = 0;

    for (int i = 0; i < arr.size(); i++) {

        sum = sum + arr[i];
        if (sum == first_sum and first == -1) {
            first = i;
        }

        else if (sum == second_sum and first != -1 and i != arr.size() - 1) {
            second = i;
            break;
        }

    }
    cout << first << " " << second << endl;

    if (first != -1 and second != -1) return true;

    return false;

}

int main() {

    vector<int> arr = {1, -1, 1, -1};
    bool res = canThreePartsEqualSum(arr);
    cout << res << endl;


    return 0;
}