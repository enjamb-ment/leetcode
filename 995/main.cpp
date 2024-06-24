/* 995. Minimum Number of K Consecutive Bit Flips
You are given a binary array nums and an integer k.

A k-bit flip is choosing a subarray of length k from nums and simultaneously changing every 0 in the subarray to 1, and every 1 in the subarray to 0.

Return the minimum number of k-bit flips required so that there is no 0 in the array. If it is not possible, return -1.

A subarray is a contiguous part of an array.
*/

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        vector<bool> flipped(nums.size(), false);

        int validFlipsFromPastWindow = 0;

        int flipCount = 0;

        for (int i = 0; i < nums.size(); i++){
            if (i >= k) {
                if (flipped[i -k]) {
                    validFlipsFromPastWindow--;
                }
            }
            if (validFlipsFromPastWindow % 2 == nums[i]) {
                if (i + k > nums.size()) {
                    return -1;
                }
                validFlipsFromPastWindow++;
                flipped[i] = true;
                flipCount++;
            }
        }
        return flipCount;
    }
};
