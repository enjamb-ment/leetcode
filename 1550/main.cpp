/* 1550. Three Consecutive Odds
Given an integer array arr, return true if there are three consecutive odd numbers in the array. Otherwise, return false.
*/

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int oddCount = 0;
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] % 2 != 0) {
                oddCount++;
                if (oddCount == 3) {
                    return true;
                }
            }
            if (arr[i] % 2 == 0) {
                    oddCount = 0;
            }
        }
        return false;
    }
};
