/* Time :- O(2^n) Space :- O(2^n) */

/* Refer To LUV Video for Time complexity analysis of any recursive function */

class Solution
{
public:
    void solve(int open,int close,string op,vector<string>&res)
    {
        if(open==0&&close==0)
        {
            res.push_back(op);
            return;
        }
        if(open>0)
        {
            string op1=op;
            op1.push_back('(');
            solve(open-1,close,op1,res);
        }
        if(close>open)
        {
            string op2=op;
            op2.push_back(')');
            solve(open,close-1,op2,res);
        }
        return;
        
    }
    vector<string> generateParenthesis(int n)
    {
         vector<string>res;
         string op;
         int open=n;
         int close=n;
         solve(open,close,op,res);
         return res;
    }
};
