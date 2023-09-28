#include <iostream>
#include <vector>

class TicTacToe {
public:
    enum class Player { PLAYER_X, PLAYER_O, NONE };

    TicTacToe(Player p1, Player p2) : currentPlayer(p1), winner(Player::NONE) {
        board.resize(3, std::vector<Player>(3, Player::NONE));
    }

    void play() {
        displayBoard();
        while (!isGameOver()) {
            makeMove();
            displayBoard();
            switchPlayer();
        }
        displayWinner();
    }

private:
    Player currentPlayer;
    Player winner;
    std::vector<std::vector<Player>> board;

    void displayBoard() const {
        std::cout << "Current board:\n";
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                char symbol = (board[i][j] == Player::PLAYER_X) ? 'X' : (board[i][j] == Player::PLAYER_O) ? 'O' : ' ';
                std::cout << symbol;
                if (j < 2) std::cout << " | ";
            }
            std::cout << std::endl;
            if (i < 2) std::cout << "---------\n";
        }
        std::cout << std::endl;
    }

    void makeMove() {
        int row, col;
        while (true) {
            std::cout << "Player " << (currentPlayer == Player::PLAYER_X ? 'X' : 'O') << ", enter row (1-3) and column (1-3): ";
            std::cin >> row >> col;
            if (isValidMove(row - 1, col - 1)) {
                board[row - 1][col - 1] = currentPlayer;
                break;
            } else {
                std::cout << "Invalid move. Try again.\n";
            }
        }
        checkWinner(row - 1, col - 1);
    }

    bool isValidMove(int row, int col) const {
        return (row >= 0 && row < 3) && (col >= 0 && col < 3) && (board[row][col] == Player::NONE);
    }

    void checkWinner(int row, int col) {
        if (checkRow(row) || checkColumn(col) || checkDiagonals()) {
            winner = currentPlayer;
        }
    }

    bool checkRow(int row) const {
        return (board[row][0] == currentPlayer && board[row][1] == currentPlayer && board[row][2] == currentPlayer);
    }

    bool checkColumn(int col) const {
        return (board[0][col] == currentPlayer && board[1][col] == currentPlayer && board[2][col] == currentPlayer);
    }

    bool checkDiagonals() const {
        return (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
               (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer);
    }

    bool isGameOver() const {
        return winner != Player::NONE || isBoardFull();
    }

    bool isBoardFull() const {
        for (const auto& row : board) {
            for (const auto& cell : row) {
                if (cell == Player::NONE) {
                    return false;
                }
            }
        }
        return true;
    }

    void displayWinner() const {
        if (winner == Player::NONE) {
            std::cout << "It's a draw!\n";
        } else {
            std::cout << "Player " << (winner == Player::PLAYER_X ? 'X' : 'O') << " wins!\n";
        }
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == Player::PLAYER_X) ? Player::PLAYER_O : Player::PLAYER_X;
    }
};

int main() {
    while (true) {
        TicTacToe::Player p1 = TicTacToe::Player::PLAYER_X;
        TicTacToe::Player p2 = TicTacToe::Player::PLAYER_O;
        TicTacToe game(p1, p2);
        game.play();

        std::cout << "Enter Y to replay, or any other key to quit: ";
        char ch;
        std::cin >> ch;
        if (ch != 'Y' && ch != 'y') {
            break;
        }
    }

    return 0;
}
