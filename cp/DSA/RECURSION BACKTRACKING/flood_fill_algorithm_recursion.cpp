// USING DFS MAKING RECURSIVE CALLS
class Solution {
public:
    void dfs(vector<vector<int>> &image, int sr, int sc, int newColor, int row, int col, int source){
        if(sr<0 || sr>=row || sc<0 || sc>=col)
            return ;
        else if(image[sr][sc] != source)
            return ;
        
        image[sr][sc] = newColor ;
        dfs(image, sr-1, sc, newColor, row, col, source);
        dfs(image, sr+1, sc, newColor, row, col, source);
        dfs(image, sr, sc-1, newColor, row, col, source);
        dfs(image, sr, sc+1, newColor, row, col, source);
    }
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(newColor == image[sr][sc])
            return image ;
        int row = image.size() ;
        int col = image[0].size() ;
        int source = image[sr][sc] ;
        
        dfs(image, sr, sc, newColor, row, col, source) ;
        
        return image ;
    }
};