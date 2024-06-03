/* 344. Reverse String
    Write a function that reverses a string. The input string is given as an array of characters s.
    You must do this by modifying the input array in-place with O(1) extra memory.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    void reverseString(vector<char>& s) {
        auto end = s.end();
        for (int i = s.size()-1; i >= 0; i--)
        {
            s.push_back(s[i]);
        }
        s.erase(s.begin(),s.begin()+s.size()/2);
    
    cout << endl << "Backwards: ";
    for (int j = 0; j < v.size(); j++)
    {
        cout << s[j];
    }
    }
};

int main() 
{
    Solution solution;
    char input;
    vector<char> v;

    while (cin >> input && input != 0)
    {
        cin >> input;
        v.push_back(input);
    }
    cin.clear();

    cout << "Original: ";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i];
    }

    solution.reverseString(v);

}