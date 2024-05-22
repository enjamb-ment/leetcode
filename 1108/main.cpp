/*1108. Defanging an IP Address
    Given a valid (IPv4) IP address, return a defanged version of that IP address.

    A defanged IP address replaces every period "." with "[.]".
*/

#include <iostream>

using namespace std;

class Solution {
public:
    string defangIPaddr(string address) {
        
        for (int i = 0; i < address.length(); i++)
        {
            if (address[i] == '.')
            {
                address.insert(i+1,"]"); // I chose insert() to add brackets around the period.
                address.insert(i,"[");   // leetcode example rebuilt the ip address using push_back() and replaced "." with "[.]"; negligable time difference, I guess
                i++;
            }
        }
        return address;
    }
};

int main()
{
    Solution solution;
    string input;
    cout << "enter an IP address: " << endl;
    cin >> input;

    cout << "The defanged IP address looks like: " << solution.defangIPaddr(input) << endl;;
}