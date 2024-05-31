/* 260. Single Number III
    Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. 
        Find the two elements that appear only once. You can return the answer in any order.

    You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.

    Brute forced this one again, and pretty sloppy.  Also slow 470 ms without the couts... D:
        I know there's a better way, something like sorting the vector first and checking if the number next to it is the same, push back to results if not...
            Might try making that quick.
*/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> doublenum;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) // loop i to check for what to check against
        {
            for (int j = 0; j < nums.size() && j != i; j++)
            {
                if (nums[i] == nums[j])
                {
                    doublenum.push_back(nums[i]);
                    doublenum.push_back(nums[i]);
                }
            }
        }

        cout << "doublenum: " << endl;
        for (int k = 0; k < doublenum.size(); k++)
        {
            cout << doublenum[k];
        }

        sort(nums.begin(),nums.end());
        sort(doublenum.begin(),doublenum.end());
        set_difference(nums.begin(),nums.end(),doublenum.begin(),doublenum.end(),back_inserter(result)); // bread and butter of this code.  
            // takes two sorted vectors and returns what is in the first vector that isn't also in the second vector 
            // (had to push_back two sets of any duplicates because when this checks it removes 1:1)
            // e.g.    1, 2, 2, 3, 3, 4, 5
            //  dupes:    2,    3
            //  reult: 1,    2,    3, 4, 5  vs expected: [1, 4, 5]
        
        cout << endl << "result: " << endl;
        for (int k = 0; k < result.size(); k++)
        {
            cout << result[k];
        }

        return result;
    }
};

class Solution2 {
public:
    vector<int> singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for (int i = nums.size()-1; i > 0; i--)
        {
            if(nums[i]==nums[i-1])
            {
            nums.erase(nums.begin()+i);
            i--;
            nums.erase(nums.begin()+i);
            }
        }
        return nums;
    }
};

int main() 
{
    Solution solution;
    Solution2 solution2;
    int input;
    vector<int> v;
    vector<int> nums;

    cout << "Make a vector using integers, using no more than two of the same: " << endl;
    while(cin >> input)
    {
        v.push_back(input);
    }
    cin.clear();

    cout << "The following numbers were used only once: " << endl;
    nums = solution2.singleNumber(v);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i];
    }

}