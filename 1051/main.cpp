/* 1051. Height Checker
    A school is trying to take an annual photo of all the students. The students are asked to stand in a single file line in non-decreasing order by height. Let this ordering be represented by the integer array expected where expected[i] is the expected height of the ith student in line.

    You are given an integer array heights representing the current order that the students are standing in. Each heights[i] is the height of the ith student in line (0-indexed).

    Return the number of indices where heights[i] != expected[i].
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int count = 0;
        vector<int> oldHeights = heights;       //or create a new vector with values from the old one: vector<int> expected(heights);
        
        sort(heights.begin(),heights.end());

        for (int i = 0; i < heights.size(); i++)
        {
            if (heights[i] != oldHeights[i])
            {
                count++;
            }
        }
        return count;
    }
};

int main() 
{
    Solution solution;
    vector<int> v;
    int input;

    cout << "Enter a series of integers.  Orders should be ascending, but if they're not, the \"checker\" should find them." << endl << "non-integer to end." << endl;
    while (cin >> input)
    {
        v.push_back(input);
    }
    cin.clear();

    cout << "There are " << solution.heightChecker(v) << " indicies where heights do not match the expected." << endl;
}


/*
Pretty straightforward.  Save the vector into another one, sort it, compare it to its original in a loop.

*/