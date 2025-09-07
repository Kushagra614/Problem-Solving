class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pc; // min heap
        priority_queue<int>p; // max heap

        //insert all the ele of profits and capital 
        for(int i = 0;  i < capital.size(); i++)
        {
            int x = capital[i];
            int y = profits[i];
            pc.push({x,y});
        }

        while(k > 0)
        {
            while(!pc.empty() && w >= pc.top().first)
            {
                p.push(pc.top().second);
                pc.pop();
            }

            //if no profit
            if(p.empty()) break;

    
            w += p.top();
            p.pop();
            k--;
            
                
        }

        return w;

    }
};