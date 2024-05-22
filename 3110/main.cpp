/* 3110. Score of a String
    You are given a string s. The score of a string is defined as the sum of the absolute difference between the ASCII values of adjacent characters.

    Return the score of s.
*/

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Solution {
public:
    int scoreOfString(string s) {
        int score = 0;

        for (int i = 0; i < s.length()-1; i++)
        {
             //score += abs(int(s[i]) - int(s[i+1])); // converting the char to int is apparently not necessary
               score += abs(s[i] - s[i+1]);           // this does the same thing as the above.
        }
        return score;
    }
};

int main()
{
    Solution solution;
    string input;
    
    cout << "Enter a string of characters: " << endl;
    cin >> input;

    cout << "The score of the string is: " << solution.scoreOfString(input) << endl;
}


/*
    - Obviously there'll be a loop through each character in the string, comparing iter against iter+1
    - Next step would be, while in that loop, converting the char into its ASCII value... which is... easy?  can you just (int)char variable?
    - Absolute value is probably in the cmath library.  If it's not there, it's somewhere else.

*/