/* 2769. Find the Maximum Achievable Number
Given two integers, num and t. A number is achievable if it can become equal to num after applying the following operation:

Increase or decrease the number by 1, and simultaneously increase or decrease num by 1.
Return the maximum achievable number after applying the operation at most t times.
*/

class Solution {
public:
    int theMaximumAchievableX(int num, int t) {
        return num + (t*2); //what was that question...??
    }
};

/*
Hint: Let x be the answer, it’s always optimal to decrease x in each operation and increase nums.

That's still confusing.  The math worked out, so it's gotta be some kind of stepwise thing where half of t represenst the number of iterations both numbers take, and num is the starting value...?
*/
