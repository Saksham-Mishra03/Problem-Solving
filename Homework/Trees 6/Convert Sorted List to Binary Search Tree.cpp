class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {

        if(head==NULL)
        return NULL;

        if(head->next==NULL)
        return new TreeNode(head->val);

        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* temp = slow;
        while(fast && fast->next)
        {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        TreeNode* root = new TreeNode(slow->val);
        temp->next = NULL;

        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);

        return root;
        
    }
};
