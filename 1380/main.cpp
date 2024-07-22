/* 1380. Lucky Numbers in a Matrix
Given an m x n matrix of distinct numbers, return all lucky numbers in the matrix in any order.

A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.
*/

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> rowMin;
        vector<int> columnMax;
        int N = matrix.size(), M = matrix[0].size();

        for (int i = 0; i < N; i++) {
            int rMin = INT_MAX;
            for (int j = 0; j < M; j++) {
                rMin = min(rMin, matrix[i][j]);
            }
            rowMin.push_back(rMin);
        }
        for (int i = 0; i < M; i++) {
            int cMax = INT_MIN;
            for (int j = 0; j < N; j++) {
                cMax = max(cMax, matrix[j][i]);
            }
            columnMax.push_back(cMax);
        }

        vector<int> luckyNums;
        for (int i = 0; i< N; i++) {
            for (int j = 0; j < M; j++) {
                if (matrix[i][j] == rowMin[i] && matrix[i][j] == columnMax[j]) {
                    luckyNums.push_back(matrix[i][j]);
                }
            }
        }
        return luckyNums;
    }
};
