class MedianFinder
{
    priority_queue<int>max_pq;
    priority_queue<int, vector<int>, greater<int>>min_pq;
    
    public:   
    void addNum(int num)
    {
        max_pq.push(num);
        
        if (max_pq.size() > min_pq.size())
        {
            int t = max_pq.top();
            min_pq.push(t);
            max_pq.pop();
        }
        
        if (min_pq.size() > max_pq.size())
        {
            int t = min_pq.top();
            max_pq.push(t);
            min_pq.pop();
        }
    }
    
    double findMedian()
    {    
        int max_pq_size = max_pq.size();
        int min_pq_size = min_pq.size();
        
        if (max_pq_size == min_pq_size) 
        {
            return (max_pq.top() + min_pq.top())/2.0;
        }
        else if (max_pq_size > min_pq_size)
        {
            return max_pq.top();
        }
        else
        {
            return min_pq.top();
        }
    }
};
