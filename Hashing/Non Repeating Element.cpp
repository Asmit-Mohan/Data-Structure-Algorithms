/* Time :- O(N) Space :- O(N) */

class Solution
{
    public:
    int firstNonRepeating(int arr[], int n) 
    { 
         unordered_map<int,int>mp;
         int res;
         for(int i=0;i<n;i++)
         {
            mp[arr[i]]++;
         }
         for(int i = 0; i < n; i++)
        {
            if(mp[arr[i]] == 1)
            {
                return arr[i];
            }
        }
        return 0;
    }
};
