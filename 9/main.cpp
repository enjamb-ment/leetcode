#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
using std::string;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x > 0 && x <= pow(2,31)-1){
            int y = x;
            vector <int> forward;

            while(y > 0){
                forward.push_back(y%10);
                y/=10;
                }
            
            unsigned int result = 0;
            for (auto d : forward){
                result = result * 10 + d;
                
            } if (x == result){
                return true;
            }
        } else if (x == 0){
                return true;
        } return false;
    }
};

int main(){
    int x = 0;
    cin >> x;
    Solution solution;
    cout << "Is palindrome: " << std::boolalpha << solution.isPalindrome(x) << endl;
}