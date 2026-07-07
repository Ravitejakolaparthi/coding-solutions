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
    ListNode* reverseList(ListNode* head) {
        stack<int>s;
        if(head == nullptr)
        return head;        
        while(head)
        {
            s.push(head->val);
            head = head -> next;
        }

        ListNode*temp = new ListNode(s.top());
        s.pop();
        ListNode*dummy = temp;
        while(!s.empty())
        {
            ListNode * newnode = new ListNode(s.top());
            s.pop();
            temp -> next = newnode;
            temp = temp -> next;
            newnode = newnode -> next;
        }
        return dummy;
    }
};