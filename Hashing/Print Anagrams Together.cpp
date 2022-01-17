class Solution
{
  public:
    vector<vector<string>>Anagrams(vector<string>&v)
    {
           unordered_map<string,vector<string>>mp;
           for(int i=0;i<v.size();i++)
           {
                string temp=v[i];
                sort(temp.begin(),temp.end());
                mp[temp].push_back(v[i]);
            }
            vector<vector<string>>ans;
            for(auto x : mp)
            {
                ans.push_back(x.second);
            }
        return ans;
    }
};
