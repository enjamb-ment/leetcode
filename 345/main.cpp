/* 345. Reverse Vowels of a String
Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.
*/

class Solution {
public:
    string reverseVowels(string s) {
        string vowels;
        string rVowels;

        for (char c : s) {
            if (c == 'a'|| c == 'e'|| c == 'i'|| c == 'o'|| c == 'u'|| 
                c == 'A'|| c == 'E'|| c == 'I'|| c == 'O'|| c == 'U') {
                    vowels.push_back(c);
                }
        }
        reverse(vowels.begin(),vowels.end());
        int j = 0;

        for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'a'|| s[i] == 'e'|| s[i] == 'i'|| s[i] == 'o'|| s[i] == 'u'|| 
            s[i] == 'A'|| s[i] == 'E'|| s[i] == 'I'|| s[i] == 'O'|| s[i] == 'U') {
                rVowels.push_back(vowels[j]);
                j++;
            } else {
                rVowels.push_back(s[i]);
            }
        }
        return rVowels;
    }
};
