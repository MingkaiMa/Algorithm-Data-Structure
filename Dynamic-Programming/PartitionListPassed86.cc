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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL)
            return NULL;
        
        if(head->next == NULL)
            return head;
        
        
        ListNode* smallHead = NULL;
        ListNode* smallCurr = NULL;
        ListNode* largeHead = NULL;
        ListNode* largeCurr = NULL;
        
        ListNode* curr = head;
        
        while(curr != NULL)
        {
            ListNode* saveNext = curr->next;
            if(curr->val < x)
            {
                if(smallHead == NULL)
                {
                    smallHead = curr;
                    smallCurr = smallHead;
                    smallCurr->next = NULL;
                }
                else
                {
                    smallCurr->next = curr;
                    smallCurr = smallCurr->next;
                    smallCurr->next = NULL;
                }
            }
            else
            {
                if(largeHead == NULL)
                {
                    largeHead = curr;
                    largeCurr = largeHead;
                    largeCurr->next = NULL;
                }
                else
                {
                    largeCurr->next = curr;
                    largeCurr = largeCurr->next;
                    largeCurr->next = NULL;
                }
            }
            
            curr = saveNext;
            //cout << curr->val << "\n";
        }
        
        

        if(smallHead == NULL)
            return largeHead;
        
        
        ListNode* temp = smallHead;
        while(temp->next != NULL)
        {
        
            temp = temp->next;   
        
        }
        
        temp->next = largeHead;
        
        
        
        
        return smallHead;
    }
};
