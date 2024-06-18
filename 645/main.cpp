/* 645. Set Mismatch
You have a set of integers s, which originally contains all the numbers from 1 to n. 
Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, 
which results in repetition of one number and loss of another number.

You are given an integer array nums representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and return them in the form of an array.

Found a comment that gave the arithmetic to use.  Developed a solution based on that:
  expected sum = n*(n+1)/2 (which is just the equation for 1 + 2 + ... + n, but I haven't needed to think of that since college).
*/

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int expectedSum = nums.size()*(nums.size()+1)/2;
        int sum = accumulate(nums.begin(),nums.end(),0);
        auto repeat = adjacent_find(nums.begin(), nums.end());

        int missingNum = expectedSum - (sum - *repeat);

        vector<int> ans = {*repeat, missingNum};

        return ans;
    }
};

class notASolution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans{0,0};
        sort(nums.begin(),nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[0] != 1)
            {
                nums.insert(nums.begin(),1);
                ans[1] = 1;
            }
            if (nums[i] != i + 1 && ans[1] != 1)
            {
                ans[0] = nums[i];
                ans[1] = i+1;
                return ans;
            } else if (nums[i] != i + 1)
            {
                ans[0] = nums[i];
                return ans;
            }
        }

        return ans;
    }
};
