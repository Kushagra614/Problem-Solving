class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        stack<int>st;
        int n = q.size();

    if(k>q.size())
    {
        exit(0);
    }
    for (int i = 0; i < k; i++)
    {
        //from queue to stack
        // int temp = q.front();
        st.push(q.front());
        q.pop();
        // st.push(temp);

       }
    while(!st.empty()){
     //from stack to queue
    //  int temp = st.top();
        q.push(st.top());
        st.pop();
        // q.push(temp);
    }

    for (int  i = 0; i < n-k; i++)
    {
        int temp = q.front();
        q.pop();
        q.push(temp);
    }
    return q;
    }
};
