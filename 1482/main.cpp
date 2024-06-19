/* 1482. Minimum Number of Days to Make m Bouquets
You are given an integer array bloomDay, an integer m and an integer k.

You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.

The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.

Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.

BINARY SEARCH - start in the middle and move the bounds inward based on criteria
*/

class Solution {
public:
    int getNumberOfBouquets(vector<int>& bloomDay, int midPoint, int k) {
        int bouquets = 0;

        int count = 0;
        for (int i = 0; i < bloomDay.size(); i++)
        {
            if (bloomDay[i] <= midPoint)
            {
                count++;
            } else
            {
                count = 0;
            }

            if (count == k)
            {
                bouquets++;
                count = 0;
            }
        }
        return bouquets;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int start = 0;
        // int end = *max_element(bloomDay.begin(),bloomDay.end());
        int end = 0;
  

        for (int day : bloomDay)
        {
            end = max(end, day);
        }

        int ans = -1;

        while (start <= end)
        {
            int midPoint = (start + end)/2; // I didn't have this defined in the loop; was getting TLE bc start/end weren't changing
            
            if (getNumberOfBouquets(bloomDay, midPoint, k) >= m)
            {
                ans = midPoint;
                end = midPoint - 1;
            } else
            {
                start = midPoint + 1;
            }
        }
        return ans;
    }

};
