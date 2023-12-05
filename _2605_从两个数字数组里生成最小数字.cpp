#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int minNumber(vector<int> &nums1, vector<int> &nums2)
    {
        int min1 = 10, min2 = 10;
        int min = 10;
        for (auto &&i : nums1)
        {
            for (auto &&j : nums2)
            {
                if (i == j)
                {
                    min = i < min ? i : min;
                }
            }
        }
        if (min != 10)
        {
            return min;
        }

        for (auto &&i : nums1)
        {
            min1 = i < min1 ? i : min1;
        }

        for (auto &&i : nums2)
        {
            min2 = i < min2 ? i : min2;
        }

        return min1 < min2 ? min1 * 10 + min2 : min2 * 10 + min1;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums1 = {6,4,3,7,2,1,8,5};
    vector<int> nums2 = {6,8,5,3,1,7,4,2};
    int minNum = solution.minNumber(nums1,nums2);
    cout << minNum;
    return 0;
}
