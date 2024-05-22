/*28. Find the Index of the First Occurrence in a String
    Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);               //I honestly didn't expect that to work.  It took me two submissions because I forgot "return"
    }
};

/*  Including this slower answer from leetcode because I thought it was interesting (specifically the checking needle vs substr):
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=needle.length(),m=haystack.length();  //establishes lengths for needle (substring) and haystack (large string)
        if(n>m)                                     // so that if the needle is longer, there's no way it's in the haystack, and so returns -1
            return -1;
        else if(n==m && needle!=haystack)           // and if they're the same length, but they're NOT the same, it returns -1
            return -1;
        else{
            for(int i=0;i<=m-n;i++)                 // beyond those above, it'll loop through the beginning of haystack and check to see if at that point...
            {
                string str=haystack.substr(i,n);    // the substring of haystack (starting at the iterator and having the length of needle)
                
                if(needle == str)                   // is the same thing.  And if it is, it reports out the matching value and returns the iterator as the result.
                {   cout<<needle<<" "<<str;
                    return i;
                }
            }
            return -1;
        }
        
    }
};
*/



int main()
{
    Solution solution;
    string haystack;
    string needle;

    cout << "enter a string for haystack: " << endl;
    cin >> haystack;
    
    //cin.clear();                                                      // not sure why this wasn't necessary this time. *shrugs*
    //cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    cout << "enter a string for needle: " << endl;
    cin >> needle;

    cout << "The index of needle in haystack is: " << solution.strStr(haystack,needle) << endl;
}