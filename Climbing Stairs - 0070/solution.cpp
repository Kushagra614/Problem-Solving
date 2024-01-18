class Solution {
public:
    int climbStairs(int n) {
        //BASE CASE 
        if(n==0){
            return 1;

        }
        if(n==1){
            return 1;
        }
        int ans = climbStairs(n-1)+climbStairs(n-2);
        return ans;
    }
};
