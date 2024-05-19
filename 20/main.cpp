/*
20. Valid Parentheses
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
3. Every close bracket has a corresponding open bracket of the same type.
*/


#include <iostream>

using namespace std;

/*class Solution {
public:
    bool isValid(string s) 
    {
        int i = 0;
        string scheck;

        while (i < s.length())
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                scheck.push_back(s[i]);
            }

            if(scheck[scheck.back()] == '(' && s[i+1] == ')')
            {
                scheck.pop_back();
            }
            else if(scheck[scheck.back()] == '[' && s[i+1] == ']')
            {
                scheck.pop_back();
            }
            else if(scheck[scheck.back()] == '{' && s[i+1] == '}')
            {
                scheck.pop_back();
            }
            cout << scheck << endl;
            i++;
        }

        if(scheck.length() == 0)
        {
            return true;
        }
        else 
        {
            return false;
        }
    }
};*/


class Solution {
public:
    bool isValid(string s) 
    {
        int i = 1;
        string scheck;
        scheck.push_back(s[0]);

        if (s.front() == ')' || s.front() == ']' || s.front() == '}')
        {
            return false;
        }


        while (i < s.length())
            {
                scheck.push_back(s[i]);
                if(scheck.length() > 1)
                {
                    cout << "scheck loop: " << scheck.at(scheck.length()-2) << " " << scheck.back() << endl;
                    if(scheck.back() == ')' && scheck.at(scheck.length()-2) == '(')
                    {
                        cout << "\"() tripped\"" << endl;
                        scheck.pop_back();
                        scheck.pop_back();
                    }
                    else if(scheck.back() == ']' && scheck.at(scheck.length()-2) == '[')
                    {
                        cout << "\"[] tripped\"" << endl;
                        scheck.pop_back();
                        scheck.pop_back();
                    }
                    else if(scheck.back() == '}' && scheck.at(scheck.length()-2) == '{')
                    {
                        cout << "\"{} tripped\"" << endl;
                        scheck.pop_back();
                        scheck.pop_back();
                    }
                    /*else
                    {
                        return false;
                    }*/
                }
                cout << "scheck end of loop: " << scheck << endl;
                i++;
            }

        if(scheck.length() == 0 && s.length() >= 2 && s.length() % 2 == 0)
        {
            return true;
        }
        else 
        {
            return false;
        }
    }
};


/* #1 solution on leetcode uses a stack<char>, which I've not used yet... 
                            It also confirmed that you can set up nested conditionals in a single "if".  
                            And shows how to better organize long strings by just using linebreaks 
                            ...
                            Stacks kinda just look like vectors to me.  maybe it's a one-way vector like in Assembly?  Saves on memory...?
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (int i = 0; i < s.size(); i++) {                     //loop through string s. Pretty straightforward.
            if (!st.empty() && ((st.top() == '(' && s[i] == ')') //sets the condition that the stack st is not empty AND (nested) the three different bracket conditions for matching 
                || (st.top() == '[' && s[i] == ']')
                || (st.top() == '{' && s[i] == '}'))) {
                st.pop();                                        //if the stack isn't empty and any above conditions are true then pop() the last added char pops off the stack
            } else {
                st.push(s[i]);                                   //when any of the above conditions are false, add current string char to stack...
            }                                                    //     which will only ever be an open bracket, or an end bracket that doesn't match the last open.
        }                                                        //       How does this handle multiple nested brackets though. With the for loop, won't it skip the last bracket set?
                                                                 //     And note the first time the for loop runs, stack is empty, so it'll always push s[0].

        return st.empty() ? true : false;                        //shorthand conditional: is st.empty() true? if so true, otherwise false
    }
}; */



int main()
{
    Solution solution;
    string input;

    cout << "insert brackets into string (e.g. \"()[]{}\"): \n";
    cin >> input;

    cout << boolalpha << "String valid...?  CHECKING: " << solution.isValid(input) << endl;
}



/* 
I feel like this works similar to: check and see if it's a palindrome... almost.  
Something like "(({})[])" would still be valid despite not being a palindrome...

I need to think on what the rules are.

Move forward through the string until the next char is a closed bracket.  
    At that point, the closed bracket needs to be the same as the bracket before it.
Then, if the next bracket after that is an open bracket, follow the first loop again, otherwise, it'll be a closed bracket and should be # iterators back


Hints suggested putting the string into a stack and popping off an open parentheses every time the closed one would match up, kind of like pacman chomping through

string      stack
()[{}]  --> (
        --> ()  (pops off "()")
        --> [
        --> [{
        --> [{} (pops off "{}")
        --> []  (pops off "[]")
        
        if (string == "") {true}
        else {false}
*/