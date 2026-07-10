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
                ListNode*dummy = new ListNode(0);
                ListNode* temp = dummy; 
               while(l1!=nullptr && l2!=nullptr)
               {
    
                        ListNode* newnode = new ListNode(l1->val + l2->val);
                        temp -> next = newnode;
                        temp = temp -> next;
                    l1 = l1->next;
                    l2 = l2->next;
               }
               while(l1!=nullptr)
               {
                   ListNode* newnode = new ListNode(l1->val + 0);
                        temp -> next = newnode;
                        temp = temp -> next; 
                        l1 = l1 ->next;
               }
                while(l2!=nullptr)
               {
                   ListNode* newnode = new ListNode(l2->val + 0);
                        temp -> next = newnode;
                        temp = temp -> next; 
                        l2 =l2->next;
               }
               ListNode * head = dummy->next;
                while(head->next!=nullptr){
                        if(head -> val > 9)
                        {
                            head -> val = (head ->val)%10;
                            (head -> next) -> val +=1;
                           
                        }
                         head = head ->next;
                }
                if(head -> val > 9)
                {
                    head -> val = (head ->val)%10;
                    ListNode * newnode = new ListNode(1);
                    head ->next = newnode; 
                }
                return dummy -> next;
              
    }
};