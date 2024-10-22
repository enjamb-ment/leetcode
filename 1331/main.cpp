/* 1331. Rank Transform of an Array
Given an array of integers arr, replace each element with its rank.

The rank represents how large the element is. The rank has the following rules:

Rank is an integer starting from 1.
The larger the element, the larger the rank. If two elements are equal, their rank must be the same.
Rank should be as small as possible.
*/
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map <int,int> ranker;
        vector<int> sortedArr(arr);

        sort(sortedArr.begin(), sortedArr.end());   //sort the array
        int rank = 1;

        for(int i = 0; i <sortedArr.size(); i++){
            if (i > 0 && sortedArr[i] > sortedArr[i - 1]) {
                rank++;                         //increment and assign rank
                                                //value as it moves down the
                                                //sorted array.  If it's the
                                                //same number, give the same
                                                //rank value.
            }
            ranker[sortedArr[i]] = rank;        //put rank values into map
                                                //against actual values
        }
        for (int i = 0; i < arr.size(); i++) {  //replace arr with
            arr[i] = ranker[arr[i]];            //value from map
        }
        return arr;
    }
};
