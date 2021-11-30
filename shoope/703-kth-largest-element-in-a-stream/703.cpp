#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class KthLargest {
public:

    priority_queue<int, vector<int>, greater<int>> q;
    int k;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (auto num : nums) {
            add(num);
        }
    }
    
    int add(int val) {
        q.push(val);
        if (q.size() > this->k) {
            q.pop();
        }
        return q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

int main(int argc, char** args) {
    vector<int> nums = {4, 5, 8, 2};
    KthLargest kthLargest = KthLargest(3, nums);
    cout << kthLargest.add(3) << endl;   // return 4
    cout << kthLargest.add(5) << endl;   // return 5
    cout << kthLargest.add(10) << endl;  // return 5
    cout << kthLargest.add(9) << endl;   // return 8
    cout << kthLargest.add(4) << endl;   // return 8
    
    return 0;
}