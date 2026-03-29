class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // define size
        int m = matrix.size();
        int n = matrix[0].size();
        // ans array
        vector<int> ans;
        // sides
        int t = 0;
        int l = 0;
        int r = n - 1;
        int b = m - 1;

        while (t <= b && l <= r) {
            // top row printed
            // -> left to right
            // inc top
            for (int i = l; i <= r; i++) {
                ans.push_back(matrix[t][i]);
            }
            t++;

            // righmost col printed
            // ->top to bottom
            // dec rightmost
            for (int j = t; j <= b; j++) {
                ans.push_back(matrix[j][r]);
            }
            r--;

            // bottomlast row printed
            // rigth to left
            // dec bottomlast
            if (t <= b) {
                for (int k = r; k >= l; k--) {
                    ans.push_back(matrix[b][k]);
                }
                b--;
            }

            // leftmost col prrinted
            // bottom to up
            // leftmost inc
            if (l <= r) {
                for (int z = b; z >= t; z--) {
                    ans.push_back(matrix[z][l]);
                }
                l++;
            }
        }
        return ans;
    }
};