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
        
        
        queue<ListNode*> smallQueue;
        queue<ListNode*> largeQueue;
        
        
        
        ListNode* currNode = head;
        
        while(currNode != NULL)
        {
            
            if(currNode->val < x)
                smallQueue.push(currNode);
            
            else
                largeQueue.push(currNode);
        }
        
        
        ListNode* newHead = smallQueue.front();
        ListNode* newCurr = newHead;
        
        smallQueue.pop();
        
        while(!smallQueue.empty())
        {
            ListNode* tempNode = smallQueue.front();
            smallQueue.pop();
            newCurr->next = tempNode;
            newCurr = newCurr->next;
        }
        
        
        while(!largeQueue.empty())
        {
            ListNode* tempNode = largeQueue.front();
            largeQueue.pop();
            newCurr->next = tempNode;
            newCurr = newCurr->next;
        }
        
        newCurr->next = NULL;
        
        return newHead;
        
        
        
        
        
    }
};
