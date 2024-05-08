#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
using std::string;

/*
class Solution {
public:
    int romanToInt(string s) {
        //mm... can't mix strings and integers in an array... or vector for that matter... python can do it in lists. :P
        int arr[13][2] = {
            {"I", 1},
            {"V", 5},
            {"X", 10},
            {"L", 50},
            {"C", 100},
            {"D", 500},
            {"M", 1000},
            {"IV", 4},
            {"IX", 10},
            {"XL", 40},
            {"XC", 90},
            {"CD", 400},
            {"CM", 900}
        };

//I don't understand structures I guess.  I think I ended up making a vector containing 2 'spots' per thing though, not that they're each set for their value and their letter...
        struct {
            int inum;
            string snum;
        } I, V, X, L, C, D, M, IV, IX, XL, XC, CD, CM;
        I.inum = 1, V.inum = 5, X.inum = 10, L.inum = 50, C.inum = 100, D.inum = 500, M.inum = 1000, IV.inum = 4, IX.inum = 9, XL.inum = 40, XC.inum = 90, CD.inum = 400, CM.inum = 900;
        I.snum = "I", V.snum = "V", X.snum = "X", L.snum = "L", C.snum = "C", D.snum = "D", M.snum = "M", IV.snum = "IV", IX.snum = "IX", XL.snum ="XL", XC.snum = "XC", CD.snum = "CD", CM.snum = "CM";

        int result = 0;
        auto count;

        //for each substring: IV, IX, XL, XC, CD, and CM, if exist add value to result; else find I, X, C and add value to result per each instance
        for (int i = 0; i < 13; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                if (s.find(arr[i]) > 0 && s.find(arr[i]) < 1000){
                    result = result + arr[i][j];
                    return result;
                }


            }
        }


        if (s.find("I") < 1000)
        {
            if (s.find("IV") < 1000)   
            {
                result = result + IV;
            }
            if(s.find("IX")  < 1000)
            {
                result = result + IX;
            }            
            count = std::ranges::count(s, "I");
            result = result + count*I;
            
        }
        if(s.find("XL")  < 1000)
        {
            result = result + XL;
        }
        
        if(s.find("XC")  < 1000)
        {
            result = result + XC;
        }
        
        if(s.find("CD")  < 1000)
        {
            result = result + CD;
        }

        if(s.find("CM")  < 1000)
        {
            result = result + CM;
        }

        count = std::ranges::count(s, V);
        result = result + count*V;
        count = std::ranges::count(s, X);
        result = result + count*X;
        count = std::ranges::count(s, L);
        result = result + count*L;
        count = std::ranges::count(s, C);
        result = result + count*C;
        count = std::ranges::count(s, D);
        result = result + count*D;
        count = std::ranges::count(s, M);
        result = result + count*M;

        return result;
    }
*/

// find all of th outliers and replace them with countable values: e.g. IV = IIII, IX = VIIII, XL = XXXX.
//  Then loop through and add together 1*(nI)+5*(nV)+10*(nX)...
class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        int length = s.length();

        string arrStr[13][2] = {
            {"IV", "IIII"},  //0
            {"IX", "VIIII"}, //1
            {"XL", "XXXX"},  //2
            {"XC", "LXXXX"}, //3
            {"CD", "CCCC"},  //4
            {"CM", "DCCCC"}, //5
            {"I", "I"},      //6
            {"V", "V"},      //7
            {"X", "X"},      //8
            {"L", "L"},      //9
            {"C", "C"},      //10 
            {"D","D"},       //11
            {"M","M"}};      //12
        int arrInt[7] = {1, 5, 10, 50, 100, 500, 1000};

        for (int i = 0; i < 7; i++)
        {
            size_t pos = 0;
            while ((pos = s.find(arrStr[i][0], pos)) != string::npos) {
                s.replace(pos, arrStr[i][0].length(), arrStr[i][1]);
                pos += s.length();
            }
            cout << s << endl;
        }


        for (int n = 0; n < s.length(); n++)
        {
            for (int j = 6; j < 13; j++) 
            {
                if (s[n] == arrStr[j][0][0])
                {
                    result = result + arrInt[j-6];
                }
            }
        }
        cout << result << endl;
        return result;
    }
};

int main(){
    Solution solution;
    string roman;
    cout << "Use I, V, X, L, C, D, and M to make a roman number: ";
    cin >> roman;
    cout << solution.romanToInt(roman);
}