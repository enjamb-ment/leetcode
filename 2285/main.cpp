/* 2285. Maximum Total Importance of Roads
You are given an integer n denoting the number of cities in a country. The cities are numbered from 0 to n - 1.

You are also given a 2D integer array roads where roads[i] = [ai, bi] denotes that there exists a bidirectional road connecting cities ai and bi.

You need to assign each city with an integer value from 1 to n, where each value can only be used once. The importance of a road is then defined as the sum of the values of the two cities it connects.

Return the maximum total importance of all roads possible after assigning the values optimally.
*/

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> degree(n, 0);

        for (vector<int>& edge : roads) {
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        
        sort(degree.begin(),degree.end());
        
        long long value = 1;
        long long totalImportance = 0;

        for (long long d : degree) {
            totalImportance += (value * d);
            value++;
        }
        return totalImportance;
    }
};
