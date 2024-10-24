/* 2807. Insert Greatest Common Divisors in Linked List
Given the head of a linked list head, in which each node contains an integer value.

Between every pair of adjacent nodes, insert a new node with a value equal to the greatest common divisor of them.

Return the linked list after insertion.

The greatest common divisor of two numbers is the largest positive integer that evenly divides both numbers.
*/

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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        
    }
};

/* Between head & next, choose the smaller number and divide both head & next by smaller number, look for modulo 0; if not, decrease smaller number by 1 and repeat, keep going until smaller number = 0.  If ever head %[next-i] = 0 AND next %[next-i] = 0 then insert i.  then move on to the next pair.

My logic is sound, I just don't know how to navigate with pointers.
*/
