/* 2696. Minimum String Length After Removing Substrings
You are given a string s consisting only of uppercase English letters.

You can apply some operations to this string where, in one operation, you can remove any occurrence of one of the substrings "AB" or "CD" from s.

Return the minimum possible length of the resulting string that you can obtain.

Note that the string concatenates after removing the substring and could produce new "AB" or "CD" substrings.
*/

class Solution {
public:
    int minLength(string s) {
        while (s.find("AB") != -1 || s.find("CD") != -1) {
            while (s.find("AB") != -1) {
                s.erase(s.find("AB"),2);
            }
            while (s.find("CD") != -1) {
                s.erase(s.find("CD"),2);
            }
        }
//        cout << s << endl;
        return s.length();
    }
};
