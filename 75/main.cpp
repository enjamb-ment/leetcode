/* 75. Sort Colors
    Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, 
    with the colors in the order red, white, and blue.

    We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

    You must solve this problem without using the library's sort function.
        oh.  well.  it gave it to me.
*/


class Solution {
public:
    void sortColors(vector<int>& nums) {
        return sort(nums.begin(),nums.end());
    }
};

class Solution2 {           // cheeky
public:
    void sortColors(vector<int>& nums) {
        for (auto i = nums.begin(); i != nums.end(); ++i)
        rotate(upper_bound(nums.begin(), i, *i), i, i + 1);

    }
};