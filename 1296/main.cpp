/* 1296. Divide Array in Sets of K Consecutive Numbers
    Given an array of integers nums and a positive integer k, check whether it is possible to divide this array into sets of k consecutive numbers.

    Return true if it is possible. Otherwise, return false.
*/

#include <iostream>
#include <hash_map>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int,int> hashmap;

        if (nums.size() % k != 0)
        {
            return 0;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            hashmap[nums[i]]++;
        }

        for(auto it = hashmap.begin(); it != hashmap.end(); it++)
        {
            if (it->second > 0)
            {
                int count = it->second;
                for (int i = 0; i < k; i++)
                {
                    if (hashmap[it->first + i] < count)
                    {
                        return 0;
                    }
                    hashmap[it->first + i] -= count;
                }
            }
        }

        return 1;
    }
};