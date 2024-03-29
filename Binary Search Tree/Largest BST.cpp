/* Approach 1 Brute Force Time :- O(N^2) Space :- Auxiliary Stack */

class Solution
{
    public:
    bool solve(Node* root,long minRange,long maxRange)
    {
          if(root==NULL)
          {
              return true;
          }
          if(root->data>=maxRange||root->data<=minRange)
          {
              return false;
          }
          bool temp1 = solve(root->left,minRange,root->data);
          bool temp2 = solve(root->right,root->data,maxRange);
          
          if(temp1&&temp2)
          {
              return true;
          }
          else
          {
              return false;
          }
    }
    
    bool isValidBST(Node* root)
    {
        return solve(root,LONG_MIN,LONG_MAX);    
    }
    
    void countNode(Node* root,int &count)
    {
        if(root!=NULL)
        {
            countNode(root->left,count);
            count++;
            countNode(root->right,count);
        }
    }
    
    int largestBst(Node *root)
    {
        int ans=INT_MIN;
        int count=0;
        
    	if(root==NULL)
    	{
    	    return ans;
    	}
    	if(isValidBST(root))
    	{
    	    countNode(root,count);
    	    ans=max(ans,count);
    	    return ans;
    	}
    	int temp1=largestBst(root->left);
    	int temp2=largestBst(root->right);
    	return max(temp1,temp2);
    }
};

/* Approach 2 Most Optimised Time :- O(N) Space :- O(1) */

class NodeValue
{
public:
    int maxNode, minNode, maxSize;    
    NodeValue(int minNode, int maxNode, int maxSize)
	{
             this->maxNode = maxNode;
             this->minNode = minNode;
             this->maxSize = maxSize;
        }
};

class Solution
{
    private:
    NodeValue solve(Node* root)
    {
        if (root==NULL)
	{
            return NodeValue(INT_MAX, INT_MIN, 0);
        }
        auto left  =  solve(root->left);
        auto right =  solve(root->right);
       
        if (left.maxNode < root->data && root->data < right.minNode)
	{
	      int value1 = min(root->data, left.minNode);
	      int value2 = max(root->data, right.maxNode);
	      int value3 = left.maxSize + right.maxSize + 1;
              return NodeValue(value1, value2, value3);
        }
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }
    
    public:
    int largestBst(Node *root)
    {
        return solve(root).maxSize;
    }
};
