
void BSTtoDLL(TreeNode *root,TreeNode *&head)
{
    if(!root)return;
    BSTtoDLL(root->right,head); 

    root->right=head;
    if(head!=NULL)
    head->left=root;
    head=root;

    BSTtoDLL(root->left,head);
}

TreeNode * mergeDLL(TreeNode *h1,TreeNode *h2)
{

   TreeNode *head=NULL;
   TreeNode *tail=NULL;

   while(h1 && h2)
   {
       if(h1->data<h2->data)
       {
           if(!head)
           {
               head=h1; tail=h1;
           }
           else{
           tail->right=h1;
           h1->left=tail; tail=h1;
           }
           h1=h1->right;
       }
       else{
           if(!head)
           {
               head=h2; tail=h2;
           }
           else{
           tail->right=h2;
           h2->left=tail; tail=h2;
           }
           h2=h2->right;
       }
   }
   while(h1)
   {
       tail->right=h1;
       h1->left=tail; tail=h1;
       h1=h1->right;
   }

   while(h2)
   {
       tail->right=h2;
       h2->left=tail; tail=h2;
       h2=h2->right;
   }
   return head;
}
int count(TreeNode *head)
{
    int c=0;
    while(head)
    {
      c++; head=head->right;
    }
    return c;
}

TreeNode * DLLtoBST(TreeNode *&head,int n)
{
    if(n<=0 || head==NULL)return NULL;
    TreeNode *left = DLLtoBST(head,n/2);

    TreeNode *root=head;
    root->left=left;

    head=head->right;
    root->right=DLLtoBST(head,n-n/2-1);
    return root;
}
void ino(TreeNode *root,vector<int>&ans)
{
  if(!root)return;
  ino(root->left,ans);
  ans.push_back(root->data);
  ino(root->right,ans);
}
vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    TreeNode *head1=NULL;
    BSTtoDLL(root1,head1);
    head1->left=NULL;

    TreeNode *head2=NULL;
    BSTtoDLL(root2,head2);
    head2->left=NULL;
    
    TreeNode *finalhead=mergeDLL(head1,head2);

    int n=count(finalhead);

    TreeNode *finalroot=DLLtoBST(finalhead,n);

    vector<int>ans;
    ino(finalroot,ans);
    return ans;
}
