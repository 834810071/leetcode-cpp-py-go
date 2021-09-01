#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        return recv(postorder, 0, postorder.size()-1);
    }

    bool recv(vector<int>& postorder, int l, int r) {
        if (l >= r) return true;
        int p = l;
        while (postorder[p] < postorder[r]) ++p;
        int mid = p;
        while (postorder[mid] > postorder[r]) ++mid;
        return mid == r && recv(postorder, l, p-1) && recv(postorder, p, r-1);
    }
};

int main(int argc, char** args) {
    Solution s = Solution();
    vector<int> arr = {1,6,3,2,5};
    cout << s.verifyPostorder(arr) << endl;
    arr = {1,3,2,6,5};
    cout << s.verifyPostorder(arr) << endl;
    return 0;
}