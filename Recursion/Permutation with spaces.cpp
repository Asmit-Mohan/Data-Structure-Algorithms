/* Time :- O[n*(2^n)] Space :- O[n*(2^n)] */

/* Solve function time complexity is O(N) beacuse of erase function and solve function is called O(2^n) times so overall time is --> O[n*(2^n)] */

class Solution
{
public:
    void solve(string s,string op,vector<string>&ans)
    {
        if(s.length()==0)
        {
           ans.push_back(op);
           return;
        }
        
        string op1=op;
        string op2=op;
        
        op1.push_back(s[0]);
        op2.push_back(' ');
        op2.push_back(s[0]);
        
        s.erase(s.begin()+0);
        
        solve(s,op1,ans);
        solve(s,op2,ans);
    }
    
    vector<string> permutation(string S)
    {
        vector<string>ans;
        string op="";
        op.push_back(S[0]);
        S.erase(S.begin()+0);
        solve(S,op,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};
