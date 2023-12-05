#include <iostream>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int i, j;
        for (i = 0; i < nums.size() - 1; i++)
        {
            for (j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    return {i, j};
                }
            }
        }
        return {i, j};
    };
};

Solution solution;

int main(int argc, char const *argv[])
{
    vector<int> obj;
    obj.push_back(2);
    obj.push_back(7);
    obj.push_back(11);
    obj.push_back(15);

    vector<int> res = solution.twoSum(obj, 13);
    for (auto &&i : res)
    {
        // cout << "123\n";
        cout << i;
    }

    /* code */
    return 0;
}
// @lc code=end
