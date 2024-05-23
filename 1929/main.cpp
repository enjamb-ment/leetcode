/* 1929. Concatenation of Array
    Given an integer array nums of length n, you want to create an array ans of length 2n where ans[i] == nums[i] and ans[i + n] == nums[i] for 0 <= i < n (0-indexed).

    Specifically, ans is the concatenation of two nums arrays.

    Return the array ans.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0; i < 2; i++)                     //the outer loop will run the inside twice
        {
            for (int j = 0; j < nums.size(); j++)       //the inner loop builds a new array ans, from nums (and then does it again) using push_back
            {
                ans.push_back(nums[j]);                 //the shortest answer on leetcode realized, half of the task is already done, and just pushes back the nums back onto itself
            }                                           // restrained by the size of nums.
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    vector<int> v;
    int input;

    cout << "insert values into vector (non-integer to end): \n";
    while (cin >> input) 
    { 
        v.push_back(input);
    }
    cin.get();

    cout << "The concatenated array looks like: " << endl;
    for (int i = 0; i < solution.getConcatenation(v).size(); i++)
    {
        cout << solution.getConcatenation(v)[i];
    }
    
}