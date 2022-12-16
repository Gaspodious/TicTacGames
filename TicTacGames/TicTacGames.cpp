#include <iostream>
#include <string>

class TicTacGame {
private:
	char board[3][3] = {};
	void CreateBoard() {
		char x = '0';
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				board[i][j] = ++x;
			}
		}
	}
	void DrawBoard() {
		system("cls");
		Greetings();
		for (int i = 0; i < 3; ++i) {
			std::cout << "  ";
			for (int j = 0; j < 3; ++j) {
				(j < 2 ? std::cout << board[i][j] << " | " : std::cout << board[i][j]);
			}
			std::cout << (i < 2 ? "\n  --|---|--\n" : "\n");
		}
	}
	char CheckRulesToWin() {
		char player_Win = '0';
		if ((board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X') ||
			(board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X') ||
			(board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X') ||
			(board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X') ||
			(board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X') ||
			(board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X') ||
			(board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') ||
			(board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')) {
			player_Win = '1';
		}
		else
			if ((board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O') ||
				(board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O') ||
				(board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O') ||
				(board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O') ||
				(board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O') ||
				(board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O') ||
				(board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') ||
				(board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')) {
				player_Win = '2';
			}
		return player_Win;
	}
	void TurnsPlayers(const char& X_O) {
		std::string turn;
		for (bool b = true; b;) {
			std::getline(std::cin, turn);
			if (turn.size() == 1 && turn[0] >= '1' && turn[0] <= '9') {
				char temp_ch = '1';
				for (int i = 0; i < 3 && b; ++i) {
					for (int j = 0; j < 3 && b; ++j, ++temp_ch) {
						if (temp_ch == turn[0]) {
							if (board[i][j] != 'X' && board[i][j] != 'O') {
								board[i][j] = X_O;
								b = false;
							}
							else {
								std::cout << "Так ходить нельзя! Повторите ход!\n";
							}
						}
					}
				}
			}
			else {
				std::cout << "Так ходить нельзя! Повторите ход!\n";
			}
		}
		DrawBoard();
	}
public:
	char restart = {};
	void Greetings() {
		std::cout << "Игра - крестики и нолики.\n"
			<< "Два игорка ставят свои фигуры в поля от 1 до 9\n\n"
			<< "Фигуры первого игрока - X\nФигуры второго игрока - O\n\n";
	}
	void StartGame() {
		CreateBoard();
		DrawBoard();
		short cells = 9;
		for (;;) {
			if (CheckRulesToWin() == '0') {
				std::cout << "\nХодит Игрок 1 - ";
				TurnsPlayers('X');
				--cells;
			}
			else if (CheckRulesToWin() == '1') {
				std::cout << "\nИгра закончена!\n\nИгрок 1 - Победил!\nЖелаете начать заново?\nНажмите 'Y/y' - если хотите или любую другую, чтобы закончить - ";
				std::cin >> restart;
				std::cout << "\n";
				break;
			}
			if (cells == 0) {
				std::cout << "\nСвободные клетки закончились, ничья!\nЖелаете начать заново?\nНажмите 'Y/y' - если хотите или любую другую, чтобы закончить - ";
				std::cin >> restart;
				std::cout << "\n";
				break;
			}
			else if (CheckRulesToWin() == '0') {
				std::cout << "\nХодит Игрок 2 - ";
				TurnsPlayers('O');
				--cells;
			}
			else if (CheckRulesToWin() == '2') {
				std::cout << "\nИгра закончена!\n\nИгрок 2 - Победил!\nЖелаете начать заново?\nНажмите 'Y/y' - если хотите или любую другую, чтобы закончить - ";
				std::cin >> restart;
				std::cout << "\n";
				break;
			}
		}
	}
};

int main() {
	setlocale(LC_ALL, "ru");
RESTART:
	TicTacGame game;
	game.StartGame();
	if (game.restart == 'Y' || game.restart == 'y') {
		std::string BugFix;
		std::getline(std::cin, BugFix);
		goto RESTART;
	}
	return 0;
}