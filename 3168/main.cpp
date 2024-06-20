/* 3168. Minimum Number of Chairs in a Waiting Room
You are given a string s. Simulate events at each second i:

If s[i] == 'E', a person enters the waiting room and takes one of the chairs in it.
If s[i] == 'L', a person leaves the waiting room, freeing up a chair.
Return the minimum number of chairs needed so that a chair is available for every person who enters the waiting room given that it is initially empty.
*/

class Solution {
public:
    int minimumChairs(string s) {
        vector<int> occupancy;
        int chairs = 0;
        //int m = 0;

        for(char letter : s)
        {
            if (letter == 'E')
            {
                chairs++;
                occupancy.push_back(chairs);
                // m=max(m,chairs); //good way to keep a "this is the highest" value
            } else
            {
                chairs--;
                occupancy.push_back(chairs);
            }

        }
        return *max_element(occupancy.begin(),occupancy.end());
    }
};
