// backtracking classic

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0] && find(board, i, j, 0, word, m, n))
                    return true;
            }
        }
        return false;
    }

private:
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool find(vector<vector<char>>& board, int i, int j, int idx,
              string& word, int m, int n) {
        if (idx == word.length())
            return true;

        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] == '$')
            return false;

        if (board[i][j] != word[idx])
            return false;

        char temp = board[i][j];
        board[i][j] = '$';

        for (auto& dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            if (find(board, new_i, new_j, idx + 1, word, m, n))
                return true;
        }

        board[i][j] = temp;
        return false;
    }
};
