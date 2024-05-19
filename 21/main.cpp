/*
21. Merge Two Sorted Lists
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

FULL DISCLOSURE:
    I hacked this together.  I had the general idea for the brute force solution figured out, but wasn't able to execute any of it on my own: 
            combine both lists into one thing (vector), then sort that one thing [sort(vector.begin(),vector.end())].
    !!! I need more exposure to working with *pointers*, structures, and linked lists.
    
    These two sites essentially answered the question:
        https://www.geeksforgeeks.org/merge-two-sorted-linked-lists/
        https://www.geeksforgeeks.org/create-linked-list-from-a-given-array/

*/

#include <iostream>
#include <list>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;


 // Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
//START: adding this stuff to be able to put ints into a ListNode

ListNode* newNode(int val){
    ListNode* temp = new ListNode;
    temp->val = val;
    temp->next = NULL;
    return temp;
}

// END: adding this stuff to be able to put ints into a ListNode...


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        vector<int>v;
        while(list1!=NULL)
        {
            v.push_back(list1->val);
            list1=list1->next;
        }
        while(list2!=NULL)
        {
            v.push_back(list2->val);
            list2=list2->next;
        }

        sort(v.begin(),v.end());

        
        ListNode *result = NULL; 
        for (int i = v.size()-1; i >= 0; i--)
        {
            ListNode *val = new ListNode(v[i]);
            val->next = result;
            result = val;
            cout << result->val << " ";
        }
        cout << endl;
        return result;
    }
};

int main()
{
    /* 
    Let us create two sorted linked lists to test
        the above functions. Created lists shall be:
    a: 5->10->15->40
    b: 2->3->20  
    
    Can probably work a cin loop here to build the lists.
    */
    ListNode* a = newNode(5);
    a->next = newNode(10);
    a->next->next = newNode(15);
    a->next->next->next = newNode(40);
  
    ListNode* b = newNode(2);
    b->next = newNode(3);
    b->next->next = newNode(20);
    
    
/*  int input = 0;

    cout << "insert values into first vector (non-integer to end): \n";
    while (cin >> input) { 
        l1.push_back(input);
    }  
    
    cin.clear();                                                   //These two things *clear* the status/error flag(s) of cin
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //and removes the last input(s) up to the most recent linebreak.  Note libraries <limits> and <sstream> were needed.

    cout << "insert values into second vector (non-integer to end): \n";
    while (cin >> input) { 
        l2.push_back(input);
    }  
*/
    Solution solution;
    cout << "merged list (listed tail-to-head): " << solution.mergeTwoLists(a,b);

}


/*
Using struct variable... which I don't particularly understand yet.  It's kinda like a class, isn't it?  I know you can associate different variable types in it unlike arrays.

Can I just pushback everything from one list to the other and tell it to sort itself...?
*/