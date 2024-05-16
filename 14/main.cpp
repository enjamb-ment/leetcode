#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <functional>

using namespace std;

//well... it works on leetcode.  Probably some issue with the libraries... <algorithm> & <numeric> to use min_element & accumulate (respectively..?)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        auto smallest = min_element(strs.begin(), strs.end(), [](const auto& s1, const auto& s2){
            return s1.size() < s2.size();
            });
            int strlength = smallest -> size();
            int count = 0;

            auto it = min_element(strs.begin(), strs.end(),
                            [](const auto& a, const auto& b) {
                                return a.size() < b.size();
                            });
            int strloc = distance(strs.begin(), it);
            cout << "location of shortest word in vector: " << strloc << endl;
            cout << "size of shortest word in vector: " << strlength << endl;
        if ( strs.size() == 1)
        {
            return strs[0];
        }
        for (int n = 0; n < strs.size(); n++)  //strs.size() should provide how many values are stored; looping through n should loop through the elements; use the shortest word as the word to compare against; answer will never be longer than that
        {
            int i = 0;
            int ncheck;
            while (strloc != n && i < strlength) //checks if i went to zero (nothing matched),  that the nth element isn't compared to itself), and that the position in the string matches
                {                   
                    //n iterates in the first for loop (through elements)
                    //i iterates in the while loop (comparing strings in elements)
                    cout << "while count: " << count << endl;
                    if (i == 0 && strs[strloc][i] != strs[n][i])
                    {
                        cout << "i was 0 and string did not match." << endl;
                        return "";
                    } 
                    else if (count > i && n != ncheck && strs[strloc][i] == strs[n][i])
                    {
                        strlength = count;
                        count = 1;
                        ncheck = n;
                    }
                    else if (count <= i && strs[strloc][i] == strs[n][i])
                    {
                        count = i + 1;
                    }
                    else
                    {
                        break;
                    }
                    cout << "loop count: " << count << ";" << "loop n: " << n << endl;
                i++;
                } 
        }
        cout << "final count: " << count << endl;
        string anslong = accumulate(strs.begin(), strs.end(), string{}); //this doesn't do what I thought it did. it returns whole elements
        string ans = anslong.substr(0,count);
        return ans;
    }
};

/*
class Solution {                                            //top answer on leetcode
public:
    string longestCommonPrefix(vector<string>& v) {
        string ans="";                                      //make a string variable for the answer... yep
        sort(v.begin(),v.end());                            //oh interesting.  okay, so now they're sorted alphabetically: e.g. 
                                                            //                          Vector elements before: flower flow flight 
                                                            //                          Vector elements after: flight flow flower
        int n=v.size();                                     //make an int for how many elements are in the vector
        string first=v[0],last=v[n-1];                      //initialize two new strings: first and last
                                                            //oh that's sneaky.  Anything in between is going to be matched better than the first one to the middle ones.

        for(int i=0;i<min(first.size(),last.size());i++){   //loop through the letters of each elements' string, not looping more than whichever one is smaller
            if(first[i]!=last[i]){                          //(the "min(first.size(),last.size()" function provides the length of whichever string is shorter)
                return ans;                                 //if the values begin not equal or if they become not equal, return ans ("" if they didn't match from the start)
            }
            ans+=first[i];                                  //else, ans = ans+ first[i] to concatenate a string, until the for loop ends.
        }
        return ans;                                         //return ans, which should looks like "f+l"                
    }
};
*/


/*                                                          //another answer from leetcode
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";                                         //seems unnecessary, but I guess you'd want to stipulate this in case there's a sneaky test case

        string pref = strs[0];                                               //establish a string variable pref for the first element of the vector strs[0]
        int prefLen = pref.length();                                         //establish an int variable for the length of the first string

        for (int i = 1; i < strs.size(); i++) {                              //iterate through the elements of the vector strs
            string s = strs[i];                                             
            while (prefLen > s.length() || pref != s.substr(0, prefLen)) {   //while loop (to be used for when you don't know how many things you'll need to iterate through... I goofed here)
                prefLen--;                                                   //
                if (prefLen == 0) {
                    return "";
                }
                pref = pref.substr(0, prefLen);
            }
        }

        return pref;        
    }
};
*/



int main()
{
    Solution solution;
    vector<string> words;
    string input;

    cout << "insert words into vector (\"ctrl+c\" to end): \n";
    while (cin >> input && input != "") { 
        words.push_back(input);
    }  
    cout << solution.longestCommonPrefix(words) << endl;

}


/*psuedocode: 
    for loop s[i] of each string in vector
    (if v1[i] == v2[i] == ... == vn[i]) {count++}   //I don't know how to add X conditionals for X amount of elements...
    return answer(v.begin(),v.end()+count];         //only count doesn't go up the way I wanted it to, because of how i'm looping through the different strings D:


saving this for later... just reads out vector strs

    cout << "\nVector elements are: "; 
    for (auto it = strs.begin(); it != strs.end(); it++) 
        {
            cout << *it << " "; 
        }
*/