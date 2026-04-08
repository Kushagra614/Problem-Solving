class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& image, int color, int startpt) {
        int n = image.size();
        int m = image[0].size();
        if (i < 0 || j < 0 || i >= n || j >= m || image[i][j] != startpt)
            return;

        image[i][j] = color;
        dfs(i + 1, j, image, color, startpt);
        dfs(i - 1, j, image, color, startpt);
        dfs(i, j + 1, image, color, startpt);
        dfs(i, j - 1, image, color, startpt);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        // check if that the start px colour is same as target color
        int n = image.size();
        int m = image[0].size();
        int startpt = image[sr][sc];
        if (startpt == color)
            return image;
        else {

            dfs(sr, sc, image, color, startpt);
            
        }
        return image;

        //-> image[sr][sc] != color
        // else apply traversal - dfs and chage colour to target color
        //-> start dfs, perform dfs only once
    }
};