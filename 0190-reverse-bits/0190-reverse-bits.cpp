class Solution {
public:
    int reverseBits(int n) {
        //cal the last bit of the n
        int ans = 0;
        for(int i = 0; i< 32; i++)
        {
            int dig = (n & 1);
            n = n>>1;
            ans = (ans<<1) | dig;
        }

        return ans;
        //remove last bit from n
        //add that last bit to new ans
    }
};