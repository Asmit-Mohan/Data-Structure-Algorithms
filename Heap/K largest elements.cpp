/* Time :- O(Nlogk) Space :- O(K) */

class Solution
{
    public:
    vector<int> kLargest(int arr[], int n, int k)
    {
         priority_queue <int, vector<int>, greater<int> > minh;
         for(int i=0;i<n;i++)
         {
             minh.push(arr[i]);
             if(minh.size()>k)
             {
                 minh.pop();
             }
         }
         vector <int> v;
        while(!minh.empty())
        {
           v.push_back(minh.top());
           minh.pop();
        }
        reverse(v.begin(),v.end());
        return v;
    }
};
