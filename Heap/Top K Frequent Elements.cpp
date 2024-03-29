/* Time :- O(Nlogk) Space :- O(K) */

class Solution
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        unordered_map<int, int> ump;
        for (int i=0;i<nums.size();i++)
        {
            ump[nums[i]]++;
        }
        for (auto i=ump.begin();i!=ump.end();i++)
        {
            pq.push({i->second, i->first});   
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
        vector<int> v;
        while (!pq.empty())
        {    
            v.push_back(pq.top().second);
            pq.pop();
        }
        return v;
    }
};
