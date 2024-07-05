/* 2058. Find the Minimum and Maximum Number of Nodes Between Critical Points
A critical point in a linked list is defined as either a local maxima or a local minima.

A node is a local maxima if the current node has a value strictly greater than the previous node and the next node.

A node is a local minima if the current node has a value strictly smaller than the previous node and the next node.

Note that a node can only be a local maxima/minima if there exists both a previous node and a next node.

Given a linked list head, return an array of length 2 containing [minDistance, maxDistance] where minDistance is the minimum distance between any two distinct critical points and maxDistance is the maximum distance between any two distinct critical points. If there are fewer than two critical points, return [-1, -1].
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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {-1, -1};
        int minDistance = INT_MAX; //max permissible int value...
        ListNode* previousNode = head;
        ListNode* currentNode = head->next;
        int currentIndex = 1;
        int previousCriticalIndex = 0, firstCriticalIndex = 0;

        while (currentNode->next != nullptr) {
            if ((currentNode->val < previousNode->val && currentNode->val < currentNode->next->val) ||
                (currentNode->val > previousNode->val && currentNode->val > currentNode->next->val)) {
                    if (previousCriticalIndex == 0) {
                        previousCriticalIndex = currentIndex;
                        firstCriticalIndex = currentIndex;
                    } else {
                        minDistance = min(minDistance, currentIndex - previousCriticalIndex);
                        previousCriticalIndex = currentIndex;
                    }
                 }
                 currentIndex++;
                 previousNode = currentNode;
                 currentNode = currentNode->next;
        }
        if (minDistance != INT_MAX) {
            int maxDistance = previousCriticalIndex - firstCriticalIndex;
            ans = {minDistance, maxDistance};
        }

        return ans;
    }
};
