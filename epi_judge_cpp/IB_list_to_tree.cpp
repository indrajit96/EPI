TreeNode* helper(int size,ListNode* A) {
    
    if(A == NULL) {
        return NULL;
    }
    cout<<size;

    ListNode * temp = A;
    TreeNode * head = NULL;
    int mid =0;
    head = new TreeNode(0);
    if(size == 1) {
        head->val = A->val;
        head->left = NULL;
        head->right = NULL;
        return head;
    }

    int i = 1;
    mid = size/2 + 1;
    while(i<mid) {
        temp = temp->next;
        i++;
    }
  
    head->val = temp->val;
    if(size%2)
    head->left = helper(mid,A);
    else
    head->left = helper(mid-1,A);
    head->right = helper(mid-1,temp->next);
    return head;
}

TreeNode* Solution::sortedListToBST(ListNode* A) {
    
    int size = 0;
    ListNode * temp = A;
    
    while(temp) {
        size++;
        temp = temp->next;
    }
 //   cout << size;
    return helper(size,A);
}
    
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the 
