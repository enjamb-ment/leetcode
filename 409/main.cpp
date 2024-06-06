/* 409. Longest Palindrome
    Given a string s which consists of lowercase or uppercase letters, return the length of the longest 
    palindrome that can be built with those letters.

    Letters are case sensitive, for example, "Aa" is not considered a palindrome.

    // essentially looking to count pairs. The string can make a palindrome of length 2*pair (+1 if an unpaired letter is left over).
        I think the python script did a better job of demonstrating...
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        set<char> check;                        // establishes a set (unordered; values won't repeat) "check" for characters
        int ans = 0;
        // set<char>::iterator it;  // not necessary

        for(char it : s)                        // establish loop, iterate through string "s" where char "it"
        {
            if(check.find(it) != check.end())   // look for it from s in check while not at end... 
            {
                check.erase(it);                // if it is in check, erase it and add 2 to answer (found a matching pair)
                ans += 2;
            } else
            {
                check.insert(it);
            }
        }
        //cout << ans << endl;

        if(!check.empty())
        {
            ans++;
        }
        return ans;
    }
};