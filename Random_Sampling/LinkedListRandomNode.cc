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
    ListNode* nodeHead;

    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        nodeHead = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        ListNode* node = nodeHead;

        int val = node->val;
        for(int i = 1; node; i++){
            if(rand() % i == 0)
                val = node->val;
            node = node->next;
        }
        return val;
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
