class Solution {
public:
    //USING RECURSION
    int fiboRec(int n)
    {
        //base case
        if(n ==0 || n == 1)
        {
            return n;
        }

        //recursive relation
        int ans = fiboRec(n-1) + fiboRec(n-2);
        return ans;
    }
    int fib(int n) {
        int ans = fiboRec(n);
        return ans;
    }
};