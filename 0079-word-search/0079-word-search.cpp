
class Solution {
public:

    bool solve(vector<vector<char>>& board,
               string& word,
               int row, int col,
               int index) {

        // Word complete
        if(index == word.size()) {
            return true;
        }

        // Boundary check
        if(row < 0 || col < 0 ||
           row >= board.size() ||
           col >= board[0].size()) {
            return false;
        }

        // Character mismatch
        if(board[row][col] != word[index]) {
            return false;
        }

        // Mark visited
        char ch = board[row][col];
        board[row][col] = '#';

        // Four directions
        bool found =
            solve(board, word, row+1, col, index+1) ||
            solve(board, word, row-1, col, index+1) ||
            solve(board, word, row, col+1, index+1) ||
            solve(board, word, row, col-1, index+1);

        // Backtrack
        board[row][col] = ch;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(board[i][j] == word[0]) {

                    if(solve(board, word, i, j, 0)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};
