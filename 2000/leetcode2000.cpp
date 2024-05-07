#include <iostream>
#include <string>
#include <vector>
using namespace std;
using std::string;
#include <bits/stdc++.h> 



class Solution {
public:
 

    string reversePrefix(string word, char ch) {
        vector <char> vecWord;
        vector <char> vecWord2;
        //vecWord.reserve(word.length());
        //vecWord2.reserve(word.length());

        auto iter = word.begin();
        
        if (word.back() == ch && count(word.begin(), word.end(), ch) == 1) {
            do {
            vecWord.push_back(*iter);
            ++iter;
            }
            while (iter != word.end());
                //reverse(vecWord.begin(), vecWord.end());
                string backstr(vecWord.begin(), vecWord.end());
                cout << "just back string: " << backstr << "\n" << endl;

            return backstr;

        } else if (count(word.begin(), word.end(), ch) >= 1){    
            
            do {
            vecWord.push_back(*iter);
            ++iter;
            }
            while (*iter != ch && iter != word.end());
                reverse(vecWord.begin(), vecWord.end());
                string backstr(vecWord.begin(), vecWord.end());
                cout << "back string: " << backstr << "\n" << endl;

            for (iter = word.begin()+vecWord.size(); iter < word.end(); iter++){
                vecWord2.push_back(*iter);
            }
            //reverse(vecWord2.begin(), vecWord2.end());
            string frontstr(vecWord2.begin(), vecWord2.end());
            cout << "front string: " << frontstr << "\n" << endl;
            
            return frontstr + backstr;
            

        } else {
            return word;
        }
        return word;
        }

};

/*
Here's what got high marks on leetcode...
class Solution {
public:
    string reversePrefix(string& word, char ch) {
        int r=word.find(ch);                //establishes the first element (char:ch) in the range (string:word) that's of equal value as the iterator.  if nothing, you get 'last' which must be -1...
        if (ch==-1) return word;            //if it doesn't find it, leave it alone
        int r0=(r-1)/2;                     //otherwise, set the starting value of the reverse prefix to (iterator#-1)/2; this part establishes the range of values to be swapped
                                            // e.g. abcded; d: r = the first d; int r0 = (4-1)/2 == 2; so...
        for(int i=0; i<=r0; i++)            // for the range of i = 0 (first location) while i <= r0 (count of how many items need to swap)...
            swap(word[i], word[r-i]);       // the outer most values swap, and then both ends move in (i gets bigger, and r-i gets smaller)
        return word;                        // sends word back.
    }
};*/



int main() {
    Solution solution;
    string word;// = "abcdefghij";
    char ch;// = 'd';
    
    cout << "next two entries are for a string of letters and then a single character\n";
    cin >> word >> ch;

    cout << solution.reversePrefix(word, ch);

}