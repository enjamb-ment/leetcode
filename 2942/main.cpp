/* 2942. Find Words Containing Character
You are given a 0-indexed array of strings words and a character x.

Return an array of indices representing the words that contain the character x.

Note that the returned array may be in any order.
*/

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        int index = 0;
        for (string word : words)
        { 
            auto it = find(word.begin(),word.end(),x);
            if (it != word.end())
            {
                ans.push_back(index);
                index++;
            } else
            {
                index++;
            }
        }
        return ans;
    }
};
