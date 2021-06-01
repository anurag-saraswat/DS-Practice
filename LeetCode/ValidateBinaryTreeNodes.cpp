#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>

using namespace std;


bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {

    unordered_set<int> set;

    vector<int> v(n, 0);


    for (int i = 0; i < n; i++) {
        int l = leftChild[i];
        int r = rightChild[i];

        if (l != -1) {
            v[l]++;
        }

        if (r != -1) {
            v[r]++;
        }
    }

    int root = -1;
    for (int i = 0; i < n; i++) {
        if (v[i] == 0) {
            root = i;
            break;
        }

    }

    if (root == -1) {
        return false;
    }

    queue<int> que;
    que.push(root);



    while (!que.empty()) {

        int ele = que.front();
        que.pop();

        if (set.find(ele) != set.end()) {
            return false;
        }

        set.insert(ele);

        if (leftChild[ele] != -1) {
            que.push(leftChild[ele]);
        }

        if (rightChild[ele] != -1) {
            que.push(rightChild[ele]);
        }

    }

    if (set.size() == n) return true;
    return false;


}


int main() {

    vector<int> leftChild = {3, -1, 1, -1} ;
    vector<int> rightChild = { -1, -1, 0, -1};

    int n = 4;

    bool res = validateBinaryTreeNodes(n, leftChild, rightChild);
    cout << res << endl;


    return 0;
}