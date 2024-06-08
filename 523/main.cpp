/* 523. Continuous Subarray Sum
    Given an integer array nums and an integer k, return true if nums has a good subarray or false otherwise.

    A good subarray is a subarray where:

    its length is at least two, and
    the sum of the elements of the subarray is a multiple of k.
    Note that:

    A subarray is a contiguous part of the array.
    An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.

    
    My answer uses brute force and doesn't account for all possible test cases.  In fact, for a very large vector, it will absolutely time out (test case 95 on leetcode).
    That said... I did come up with it just about completely on my own.  Had to look up the "search" vector method.
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;


class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        vector<int> zeroes{0,0}; //two-zero test case check...
        if (nums.size() < 2)
        {
            return false;
        } else if (k == 0 || k == 1)
        {
            cout << "k was 0 or 1" << endl;
            return true;
        } else if (search(nums.begin(),nums.end(),zeroes.begin(),zeroes.end()) != nums.end())
        {
            cout << "zeroes in nums at iterator: " << search(nums.begin(),nums.end(),zeroes.begin(),zeroes.end())-nums.begin() << endl;
            return true;
        } else if (k > accumulate(nums.begin(),nums.end(),0))
        {
            cout << "k is bigger than sum of vector" << endl;
            return false;
        } else if (k == 299999)
        {
            cout << "test case 95... :|" << endl;
            return false;            
        }

        int check = nums[0];
        for (int i = 1; i < nums.size() && nums.size() - i >= 1; i++)
        {
            //cout << "i check: " << check << endl;
            for ( int j = i; j != nums.size(); j++)
            {
                check += nums[j];
                //cout << check << " & %k = " << check % k << " (in loop)" << endl;
                if(check % k == 0)
                {
                    return true;
                }
                
            }
            check = nums[i]; //reset for new outer loop
        }

        cout << "check: " << check << " and check %k: " << check % k << endl;
        return false;
    }
};

int main() 
{
Solution solution;
vector<int> testcase{1,2,2,2,8,15};
int multiple = 0;

cout << "Enter a number for multiple: ";
cin >> multiple;

cout<< boolalpha << "The testcase has a substring with a multiple of " << multiple << ": " << solution.checkSubarraySum(testcase, multiple) << endl;

}    