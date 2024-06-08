/* 2894. Divisible and Non-divisible Sums Difference
    You are given positive integers n and m.

    Define two integers, num1 and num2, as follows:

    num1: The sum of all integers in the range [1, n] that are not divisible by m.
    num2: The sum of all integers in the range [1, n] that are divisible by m.
    Return the integer num1 - num2.

    Just followed the prompt.  There were some underlying methods of determining what the answer should be without looping, but I took the intuitive way.
*/

class Solution {
public:
    int differenceOfSums(int n, int m) {
        int ans = 0;
        for (int i = 0; i < n +1; i++)
        {
            if(i % m == 0)
            {
                ans -= i;
            } else
            {
                ans += i;
            }
        }
        return ans;
    }
};


// Faster solution - not mine:
class LeetCodeSolution {
public:
    int differenceOfSums(int n, int m) {
       int ans=(n*(n+1))/2;
       ans-=m*(n/m*(n/m+1));
       return ans;
    }
};