/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if(head == NULL || head -> next ==  NULL)
    {
        return false;
    }
    else{
         
         struct ListNode *a = head;
         struct ListNode *b = head;
         while(b != NULL && b -> next != NULL)
         {
            a = a -> next;
            b = b -> next -> next;
            if( a == b )
            return true; 
        
         }
    }
    return false;
 }