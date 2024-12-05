class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int s_row = matrix.size();
        int s_col = matrix[0].size();

        vector< vector<int> > transpose(s_col, vector<int>(s_row,0));
        for(int i = 0; i<s_col; i++) {
            for(int j = 0; j<s_row; j++) {
                transpose[i][j] = matrix[j][i];
            }
        }
        return transpose;
    }
};
