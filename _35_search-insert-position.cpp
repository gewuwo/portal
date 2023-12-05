#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right)
        {
            // 1 2 3 4 5 6  
            int middle = left + (right - left) / 2;
            if (nums[middle] < target)
            {
                // target在右边
                left = middle + 1;
            } else if (nums[middle] > target)
            {
                right = middle - 1;
            } else
            {
                return middle;
            }
        }
        
        // 分别处理如下四种情况
        // 目标值在数组所有元素之前  [0, -1]
        // 目标值等于数组中某一个元素  return middle;
        // 目标值插入数组中的位置 [left, right]，return  right + 1
        // 目标值在数组所有元素之后的情况 [left, right]， 因为是右闭区间，所以 return right + 1
        return right + 1;
    }
};


int main(int argc, char const *argv[])
{
    vector<int> nums = {2,3,5};
    Solution solution;
    cout << solution.searchInsert(nums, 1) << endl;
    // cout << solution.searchInsert(nums, 3) << endl;
    // cout << solution.searchInsert(nums, 1) << endl;
    // cout << solution.searchInsert(nums, 2) << endl;
    return 0;
}
