#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int heapSize = nums.size();
        buildMaxHeap(nums, heapSize);
        for (int i = nums.size()-1; i >= nums.size() - k + 1; --i) {
            swap(nums[0], nums[i]);
            --heapSize;   
            modifyHeap(nums, 0, heapSize);
        }
        return nums[0];
    }

    void buildMaxHeap(vector<int>& nums, int heapSize) {
        for (int i = heapSize / 2; i >= 0; --i) {
            modifyHeap(nums, i, heapSize);
        }
    }

    void modifyHeap(vector<int>& nums, int i, int heapSize) {
        int l = i * 2 + 1, r = i * 2 + 2, lagest = i;
        if (l < heapSize && nums[l] > nums[lagest]) {
            lagest = l;
        }
        if (r < heapSize && nums[r] > nums[lagest]) {
            lagest = r;
        }
        if (lagest != i) {
            swap(nums[i], nums[lagest]);
            modifyHeap(nums, lagest, heapSize);
        }
    }
};

int main(int argc, char **argv) {
    Solution sol = Solution();
    vector<int> nums1{3,2,1,5,6,4};
    cout << sol.findKthLargest(nums1, 2) << endl; // 5
    vector<int> nums2{3,2,3,1,2,4,5,5,6};
    cout << sol.findKthLargest(nums2, 4) << endl; // 4
    return 0;
}