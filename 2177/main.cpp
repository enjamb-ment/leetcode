/* 2177. Find Three Consecutive Integers That Sum to a Given Number
Given an integer num, return three consecutive integers (as a sorted array) that sum to num. If num cannot be expressed as the sum of three consecutive integers, return an empty array.
*/

class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<long long> ans;
        if (num % 3 == 0) {
            ans.push_back((num/3)-1);
            ans.push_back(num/3);
            ans.push_back((num/3)+1);
        }
        return ans;
    }
};
