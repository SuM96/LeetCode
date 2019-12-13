/*
Problem Website: https://leetcode.com/problems/add-two-numbers
Remarks: I might get back to this problem later. I wanted to do this problem without reversing the linked list and it works. The problem is that I overflowed the integer therefore I didn't pass the 1600 tests required in Leetcode. 
The test case it didn't work for was the input:
[1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1]
[5,6,4]
Overall it was a good problem. Not much to be said about it besides that I decided to not reverse the linked list.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* traversel1 = l1, *traversel2 = l2;
        long long decodel1 = 0; 
        long long decodel2 = 0;
        long long multiplier = 1;
        while(traversel1 != NULL || traversel2 != NULL) {
            if(traversel1 != NULL) {
                decodel1 += traversel1->val * multiplier;
                traversel1 = traversel1->next;
            }
            if(traversel2 != NULL) {
                decodel2 += traversel2->val * multiplier;
                traversel2 = traversel2->next;
            }
            multiplier *= 10;
        }
        long long solution = decodel1 + decodel2;
        cout << decodel1 << " " << decodel2 << endl;
        ListNode* reverseListSolution = new ListNode(solution % 10);
        ListNode* traverse = reverseListSolution;
        solution /= 10;
        while(solution != 0) {
            traverse->next = new ListNode(solution % 10);
            traverse = traverse->next;
            solution /= 10;

        }
        return reverseListSolution;
    }
};
