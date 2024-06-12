/* 1122. Relative Sort Array
  Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.

  Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2. 
  Elements that do not appear in arr2 should be placed at the end of arr1 in ascending order.
*/

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> numMap;
        vector<int> temp, ans;

        for (int i = 0; i < arr2.size(); i++)
        {
            numMap[arr2[i]] = 0;
        }

        for (int i = 0; i < arr1.size(); i++)
        {
           if (numMap.find(arr1[i]) != numMap.end())
           {
               numMap[arr1[i]]++;
           } else
           {
               temp.push_back(arr1[i]);
           }
        }
        
        sort(temp.begin(), temp.end());
        
        for (int i = 0; i < arr2.size(); i++)
        {
            for (int j = 0; j < numMap[arr2[i]]; j++)
            {
                ans.push_back(arr2[i]);
            }
        }
        
        for (int i = 0; i < temp.size(); i++)
        {
            ans.push_back(temp[i]);
        }

        
        return ans;
    }
};
