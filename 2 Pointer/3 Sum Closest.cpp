/* Time :- O(N*N) Space :- O(1) */

class Solution
{
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=INT_MAX;
        int res=-1;

        for(int i=0;i<n-1;i++)
        {
            int l=i+1;
            int r=n-1;
            while(l<r)
            {
                int sum=nums[i]+nums[l]+nums[r];
                if(sum==target)
                {
                    return sum;
                }
                else if(sum>target)
                {
                    r--;
                }
                else
                {
                    l++;
                }
                if(abs(sum-target)<ans)
                {
                    ans=min(ans,abs(sum-target));
                    res=sum;
                }
            }
        }
        return res;    
    }
};
