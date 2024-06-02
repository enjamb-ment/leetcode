/* 2. Add Two Numbers
    You are given two non-empty linked lists representing two non-negative integers. 
    The digits are stored in reverse order, and each of their nodes contains a single digit. 
    Add the two numbers and return the sum as a linked list.

    You may assume the two numbers do not contain any leading zero, except the number 0 itself.

    Example 1:
        [2] ---> [4] ---> [3]
        [5] ---> [6] ---> [4]
    ---------------------------
        [7] ---> [0] ---> [8]
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool carryFlag = false;
        int templ1 = 0, templ2 = 0, sum = 0;
        ListNode* placeholder = new ListNode();
        ListNode* result = placeholder;
        
        while (l1 != NULL || l2 != NULL || carryFlag)
        {
            if (l1 != NULL)
            {
                sum += l1 -> val;
                l1 = l1 -> next;
            }
            if (l2 != NULL)
            {
                sum += l2 -> val;
                l2 = l2 -> next;
            }
            
            sum += carryFlag;
            if (sum >= 10)
            {
                carryFlag = true;
            } else
            {
                carryFlag = false;
            }

            ListNode* newNode = new ListNode(sum % 10);
            result -> next = newNode;
            result = result -> next;

            sum = 0;
        }
        return placeholder -> next;
    }
};



// Thought I had something here...
            // if (templ1 + templ2 + carryFlag >= 10) // So, it'd run into issues if one of the ListNodes was longer than the other.
            // {
            //     sum = (templ1 + templ2 + carryFlag) % 10;
            //     carryFlag = true;
            //     result -> next;
            // } 
            // else
            // {
            //     sum = templ1 + templ2 + carryFlag;
            //     carryFlag = false;
            //     result -> next;
            // }