/* 2469. Convert the Temperature
You are given a non-negative floating point number rounded to two decimal places celsius, that denotes the temperature in Celsius.

You should convert Celsius into Kelvin and Fahrenheit and return it as an array ans = [kelvin, fahrenheit].

Return the array (vector) ans. Answers within 10-5 of the actual answer will be accepted.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        vector<double> ans; 
        ans.push_back(celsius + 273.15);
        ans.push_back(celsius * 1.80 + 32.00);

        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << endl;
        }

        return ans;
    }
};

int main()
{
    Solution solution;
    double input;

    cout << "Enter a value for celsius (can be a decimal): " << endl;

    cin >> input;

    cout << "The following numbers are Celsius converted to Kelvin & Celsius converted to Fahrenheit: " << endl;

    solution.convertTemperature(input);
    
}