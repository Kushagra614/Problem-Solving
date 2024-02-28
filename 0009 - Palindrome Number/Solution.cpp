class Solution {
public:
    int reverse(int x){
        long ans = 0;
        while(x){
            int digit = x % 10;
            ans = ans*10+digit;
            x = x/10;
        }
        return (int)ans;
    }
    bool isPalindrome(int x) {
        if(x==reverse(x) && x>=0){
            return true;
        } else {
            return false;
        }
    }
};
