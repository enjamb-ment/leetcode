#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <sstream>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        for (int i = 0; i < nums2.size(); i++)    
        {
            nums1.push_back(nums2[i]);
        }
        
        if (nums1.size() % 2 == 0) //EVEN - need to find TWO median numbers and average
        {
            size_t n = nums1.size() / 2;
            nth_element(nums1.begin(), nums1.begin()+n, nums1.end());
            nth_element(nums1.begin(), nums1.begin()+n-1,nums1.end());
            return ((double)nums1[n]+(double)nums1[n-1])/2;
        }
        else /*if (nums1.size() % 2 == 1)*/ //ODD - works fine
        {
            size_t n = nums1.size() / 2;
            nth_element(nums1.begin(), nums1.begin()+n, nums1.end());
            return nums1[n];
        }
        //return 0;
    }
};


int main()
{
    Solution solution;
    vector<int> v1, v2;
    int input = 0;

    cout << "insert values into first vector (non-integer to end): \n";
    while (cin >> input) { 
        v1.push_back(input);
    }  
    
    cin.clear();                                                   //These two things *clear* the status/error flag(s) of cin
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //and removes the last input(s) up to the most recent linebreak.  Note libraries <limits> and <sstream> were needed.

    cout << "insert values into second vector (non-integer to end): \n";
    while (cin >> input) { 
        v2.push_back(input);
    }  
    
    cout << "The median is: " << solution.findMedianSortedArrays(v1, v2) << endl;
}