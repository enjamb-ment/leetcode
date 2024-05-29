/* 1404. Number of Steps to Reduce a Number in Binary Representation to One
    Given the binary representation of an integer as a string s, return the number of steps to reduce it to 1 under the following rules:
    If the current number is even, you have to divide it by 2.
    If the current number is odd, you have to add 1 to it.
    It is guaranteed that you can always reach one for all test cases.

    I got it, but I made a big mess of this one.  This code has everything, nested while loops inside of an iterated loop.  
    That's at least three different counters, and there's math that's most likely overcomplicated.  Like, it's binary, why am I doing %2 against it??
    Uffda.

    Turns out Python's got no limit to integers, so the code I made originally won't overflow.  So I'ma knock that out quick.
*/

#include <iostream>
#include <string>

using namespace std;

/*
//First attempt: brute force method following explanation TLEs (Time Limit Exceeded); e.g. convert binary to decimal, divide(2) or add(1) based on even or odd.
class Solution {
public:

    int binToDec(int binaryNum) {                   // I copied from https://www.geeksforgeeks.org/program-binary-decimal-conversion/
        int dec = 0;
        int base = 1;
        while (binaryNum)
            {
                int lastDigit = binaryNum % 10;
                binaryNum /= 10;
                dec += lastDigit * base;
                base *= 2;
            }
        return dec;
    };


    int numSteps(string s) {
        long count = 0;
        int sint = binToDec(stol(s));
        while (sint != 1)
        {
            if (sint % 2 == 0)
            {
                sint /= 2;
                count++;
            }
            else
            {
                sint += 1;
                count++;
            }
        }
        return count;
    }
};
*/


/*
The length of the string probably determines how many times it needs to be done, you can probably convert the string of ints in "s" into either values: 1 or 2 for steps per digit.
    nope.

Binary manipulation.  
    Even: Dividing a binary number by two is straightforward, remove zero from the end.
        e.g. 10110 / 2 == 1011
    Odd: Adding 1 to a binary number is less straightforward, from right to left set the last number to zero and if the next number is...
        1 - then make it zero, and make the next available zero number to its left a 1
        0 - then make it a 1
        special case - the whole number is 1's e.g. "1111", for this, set all 1's except the first one to 0 and add a zero to the right side

    The math itself isn't complicated, it's just base 2 addition and division.  But manual string manipulation to simulate it is a bit of a PIA.
*/


class Solution {
public:
    int numSteps(string s) {
        if (s.size() <= 1)
        {
            return 0;
        }

        int count = 0;
        while (s.size() != 1)
        {
            int i = s.size()-1;
            if (s[i] % 2) //odd when result 1 (true); even when result 0 (false)
            {
                int j = s.size()-1;
                s[j] = '0';
                while (s[j] != 0 && j > 0) // iterate backwards (j starts at s.size()-1 and decrements); whenever s[j] isn't zero, do the code
                {                          //   in order not to check a string with an iterator outside, keep code from running when j becomes zero
                    if (s[j-1] == '0')     // keep going through the numbers (iterating j) until the next value is a 0...
                        {                  //   then change it to a 1 and leave the loop
                            s[j-1] = '1'; 
                            break;
                        }
                    if (j - 1 == 0) // when j reaches the end of its iterating range then all of the numbers must have been 1 e.g. "111"
                        {
                            int k = 1;
                            while (k < s.size()) // special case; when all numbers are 1, set each number to 0, and push a zero to the end
                                {
                                    //cout << "k loop" << endl;
                                    s[k] = '0';
                                    k++;
                                }
                            s.push_back('0');
                        } 
                    j--;                        
                }
            } else
            {
                s.pop_back();
            }
            count++;
            //cout << "count: " << count << " s: " << s << endl;  // uncomment to see the stepwise action
        }
        return count;
    }
};

int main() 
{
    Solution solution;
    string binary;

    cout << "enter some binary (1's and 0's): " << endl;
    cin >> binary;

    cout << "it took " << solution.numSteps(binary) << " steps to reduce " << binary << " to One." << endl;
}