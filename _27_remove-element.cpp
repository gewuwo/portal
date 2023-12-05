#include <vector>
#include <iostream>

using namespace std;

/**
给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。

不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并原地修改输入数组。

元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

示例 1: 给定 nums = [3,2,2,3], val = 3, 函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。 你不需要考虑数组中超出新长度后面的元素。

示例 2: 给定 nums = [0,1,2,2,3,0,4,2], val = 2, 函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。
*/

class Solution
{


// 快慢指针
public:
    int removeElement(vector<int> &nums, int val)
    {
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++)
        {
            if (val != nums[fastIndex])
            {
                nums[slowIndex++] = nums[fastIndex];
            }
        }
        return slowIndex;
    }

// 对撞指针
public:
    int removeElement(vector<int> &nums, int val)
    {
        int leftIndex = 0;
        int rightIndex = nums.size() - 1;
        while (leftIndex <= rightIndex)
        {
            // 找左边等于val的元素
            while (leftIndex <= rightIndex && nums[leftIndex] != val)
            {
                ++leftIndex;
            }
            // 找右边不等于val的元素
            while (leftIndex <= rightIndex && nums[rightIndex] == val)
            {
                --rightIndex;
            }
            // 将右边不等于val的元素覆盖左边等于val的元素
            if (leftIndex < rightIndex)
            {
                nums[leftIndex++] = nums[rightIndex--];
            }
        }
        return leftIndex; // leftIndex一定指向了最终数组末尾的下一个元素
    }
};