#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
using std::string;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n-1; i++){
            for (int j = i+1; j <n; j++){
                if (nums[i] + nums[j] == target){
                    return {i,j};
                }
            }
        }
        return {};
    }
};


/*

This piece of code below will loop through the vector to display each item.  Save in memory for later!!
#include <algorithm>
#include <iterator>
*/
void display_vector(const vector<int> &v){
    std::copy(v.begin(), v.end(),
    std::ostream_iterator<int>(std::cout, " "));
}


int main (){
    Solution solution;
    vector <int> v;
    int input, targ;
    
    cout << "enter one int (that should be the sum of two of the vector values): ";
    cin >> targ;
    
    cout << "insert values into vector (non-integer to end): \n";
    while (cin >> input) { 
        v.push_back(input);
    }  
    /*for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl; */

    display_vector(solution.twoSum(v, targ));
}