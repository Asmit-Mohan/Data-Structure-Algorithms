/* Time :- O(N) Space :- O(H) */

class Solution
{
  public:
    void mirror(Node* root)
    {
        if(root==NULL)
        {
            return;
        }
        mirror(root->left);
        mirror(root->right);
        Node* temp=root->left;
        root->left=root->right;
        root->right=temp;
    }
};
