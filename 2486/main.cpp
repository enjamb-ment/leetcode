/* 2486. Append Characters to String to Make Subsequence
    You are given two strings s and t consisting of only lowercase English letters.

    Return the minimum number of characters that need to be appended to the end of s so that t becomes a subsequence of s.

    A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.
*/



class Attempt1 { // didn't work, ran through s & t simultaneously, but t can show up anywhere in s
public:
    int appendCharacters(string s, string t) {
        int substrlen = 0;
        int i = 0;

        if(s[0] != t[0])
        {
            return substrlen = t.size();
        } 

        while (s[i] == t[i] && substrlen >= 0)
        {
            substrlen = t.size()-i-1;
            cout << substrlen << endl;
            i++;
        }
        /*if(s[i] != t[i])
        {
            for (int j = substrlen; j < t.size(); j++)
            {
                s.push_back(t[j]);
            }
        }*/
        cout << "return at end: " << substrlen << endl;
        return substrlen >= 0 ? substrlen : 0;
    }
};

class Attempt2 {  // didn't work, looked for the shortest CONTIGUOUS string and simulated appending everything else to end.
public:
    int appendCharacters(string s, string t) {
        int substrlen = 0;


        for (int i = s.size()-1; i >= 0; i--)
        {
            while (s.find(t) == -1)
            {
                s.find(t);
                t.pop_back();
                substrlen++;
            } 
        }
        return substrlen;
    }
};

class Solution {
public:
    int appendCharacters(string s, string t) {
        int count = 0;

        for (auto ch: s)                // for each <<char>> in (:) string s...
        {
            count += t[count] == ch;    // count = count + TRUE (1) when t[iterator] is equal to the looped character or count = count + FALSE (0) when not equal to looped character. 
        }                               // how does this work with s="coaching" and t="coding"
        return t.size() - count;        // c...(+1) makes sense,
    }                                   // o...(+1) makes sense,
};                                      // a...(0) makes sense, 
                                        // c...(+1) ...?
                                        // h...(0)
                                        // i...(+1)
                                        // n...(+1)
                                        // g...(+1) 
                                  //---------------
                                        //       6 ... t.size() == 6 - count (6) = 0 != 4...