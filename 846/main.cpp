/* 846. Hand of Straights
    Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.

    Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, or false otherwise.
*/

#include <iostream>
#include <hash_map>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> hashmap;

        if (hand.size() % groupSize != 0)               // straightforward: skip to "Can't be ordered" when you can't evenly group the cards by the groupSize
        {
            return 0;
        }

        for (int i = 0; i < hand.size(); i++)           // Make a frequency map: keys/first (the card values) and values/second (the count of cards)
        {
            hashmap[hand[i]]++;                         // I don't know why this works. My understanding is it loops through all of the elements of the array hand.
        }                                               //                              Then inserts them into the map and increase count by one.
                                                        //                              Any duplicates will increase the second value per occurrence.



        for(auto it = hashmap.begin(); it != hashmap.end(); it++)
        {
            cout<<it->first<<"; "<<it->second<<" times" << endl;    // this displays the map
        }

        for(auto it = hashmap.begin(); it != hashmap.end(); it++)   // This bit gets hairy...
        {
            if (it->second > 0)                         // loop through the map, checking whether the count(second) of each iterator(it) is greater than 0; exists
            {
                int count = it->second;                 // establishes count variable for the current iterator(it)  
                for (int i = 0; i < groupSize; i++)     
                {                                       // loops from 0 to groupSize
                    if (hashmap[it->first + i] < count) // if the value of (it... +i) is less than count, then "Can't be ordered"
                    {                                   //  specifically, this checks if the next consecutive *value's* (e.g. 1, 2, 3, 4, 5, ... n) 
                        return 0;                       //  count (it->second)
                    }
                    hashmap[it->first + i] -= count;    // the next value's count is decremented.
                }
            }
        }
        return 1;                                       // if it makes it through all that and there's nothing left to do, then it can be sorted.
    }
};


/*
Maps...

mapping hand = [1,2,3,6,2,3,4,7,8]

    iterator (it)   |       key (first)     |       value (second)
    zero indexed    |        card value     |          count
------------------------------------------------------------------------
        0           |           1           |           1
        1           |           2           |           2
        2           |           3           |           2
        3           |           4           |           1
        4           |           6           |           1
        5           |           7           |           1
        6           |           8           |           1


*/