void convertIntoSortedDLL(BinaryTreeNode<int>* root, BinaryTreeNode<int>* &head)

{

    // base case

    if(root==NULL)

    return;
    convertIntoSortedDLL(root->right, head);

    root->right = head;
    if(head != NULL)
    head->left = root;
    head = root;
    convertIntoSortedDLL(root->left, head);
}  

BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root)
{
    BinaryTreeNode<int>* head = NULL;

    convertIntoSortedDLL(root, head);

    return head;

}
