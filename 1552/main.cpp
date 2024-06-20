/* 1552. Magnetic Force Between Two Balls
In the universe Earth C-137, Rick discovered a special form of magnetic force between two balls if they are put in his new invented basket. Rick has n empty baskets, the ith basket is at position[i], Morty has m balls and needs to distribute the balls into the baskets such that the minimum magnetic force between any two balls is maximum.

Rick stated that magnetic force between two different balls at positions x and y is |x - y|.

Given the integer array position and the integer m. Return the required force.
*/


class Solution {
public:
    
    bool canPlaceBalls(int x, vector<int> &position, int m){
        //does something that I can use to determine which way midpoint moves
        int prevBallPos = position[0], ballsPlaced = 1;

        for (int i = 1; i < position.size() && ballsPlaced < m; i++)
        {
            int currPos = position[i];
            if (currPos - prevBallPos >= x)
            {
                prevBallPos = currPos;
                ballsPlaced++;
            } 
        }
        return ballsPlaced == m; //true
    }

    int maxDistance(vector<int>& position, int m) {
        int ans = 0, n = position.size();
        sort(position.begin(),position.end());

        int low = 1, high = ceil(position[n -1] / (m - 1));

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (canPlaceBalls(mid, position, m))
            {
                ans = mid;
                low = mid + 1;
            } else
            {
                high = mid -1;
            }
        }
    
        return ans;
    }
};
