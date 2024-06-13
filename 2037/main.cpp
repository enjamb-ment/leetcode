/* 2037. Minimum Number of Moves to Seat Everyone
  There are n seats and n students in a room. You are given an array seats of length n, where seats[i] is the position of the ith seat. 
  You are also given the array students of length n, where students[j] is the position of the jth student.

  You may perform the following move any number of times:

  Increase or decrease the position of the ith student by 1 (i.e., moving the ith student from position x to x + 1 or x - 1)
  Return the minimum number of moves required to move each student to a seat such that no two students are in the same seat.

  Note that there may be multiple seats or students in the same position at the beginning.

Prompt made almost no sense to me, but the examples showed that the vectors of seats and students just needed to be sorted, and then each student
would then be in either their seat, or the next nearest seat they should be in.  So the difference would add up to how many moves it would take.
*/

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int ans = 0;
        sort(seats.begin(),seats.end());
        sort(students.begin(),students.end());

        for (int i = 0; i < students.size(); i++)
        {
            ans += abs(students[i]-seats[i]);
        }
        return ans;
    }
};
