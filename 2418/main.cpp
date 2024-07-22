/* 2418. Sort the People
    You are given an array of strings names, and an array heights that consists of distinct positive integers. Both arrays are of length n.

    For each index i, names[i] and heights[i] denote the name and height of the ith person.

    Return names sorted in descending order by the people's heights.
*/

#include <iostream>
#include <vector>

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        unordered_map<int, string> heightAndName;

        for (int i = 0; i < names.size(); i++) {
            heightAndName[heights[i]] = names[i];
        }

        sort(heights.begin(), heights.end());

        vector<string> namesByHeight(names.size());

        for (int i = names.size() - 1; i >= 0; i--) {
            namesByHeight[names.size() - i - 1] = heightAndName[heights[i]];
        }
        return namesByHeight;
    }
};
