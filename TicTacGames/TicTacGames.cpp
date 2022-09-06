#include <iostream>
#include <string>
using namespace std;

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
			cout << "  ";
			for (int j = 0; j < 3; ++j) {
				(j == 0 || j == 1 ? cout << board[i][j] << " | " : cout << board[i][j]);
			}
			cout << (i == 0 || i == 1 ? "\n  --|---|--\n" : "\n");
		}
	}
	char CheckRulesToWin() {
		short playerWin = '0';
		if ((board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X') ||
			(board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X') ||
			(board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X') ||
			(board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X') ||
			(board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X') ||
			(board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X') ||
			(board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') ||
			(board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')) {
			playerWin = '1';
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
				playerWin = '2';
			}
		return playerWin;
	}
	void GoesFirstPlayer() {
		string p1 = "";
		cout << "\nХодит Игрок 1 - ";
		for (;;) {
			getline(cin, p1);
			if (p1.size() == 1 && p1[0] == '1') {
				if (board[0][0] != 'X' && board[0][0] != 'O') {
					board[0][0] = 'X';
					break;
				}
				else {
					cout << "Так ходить нельзя! Повторите ход!\n";
				}
			}
			else if (p1.size() == 1 && p1[0] == '2') {
				if (board[0][1] != 'X' && board[0][1] != 'O') {
					board[0][1] = 'X';
					break;
				}
				else {
					cout << "Так ходить нельзя! Повторите ход!\n";
				}
			}
			else if (p1.size() == 1 && p1[0] == '3') {
				if (board[0][2] != 'X' && board[0][2] != 'O') {
					board[0][2] = 'X';
					break;
				}
				else {
					cout << "Так ходить нельзя! Повторите ход!\n";
				}
			}
			else if (p1.size() == 1 && p1[0] == '4') {
				if (board[1][0] != 'X' && board[1][0] != 'O') {
					board[1][0] = 'X';
					break;
				}
				else {
					cout << "Так ходить нельзя! Повторите ход!\n";
				}
			}
			else if (p1.size() == 1 && p1[0] == '5') {
				if (board[1][1] != 'X' && board[1][1] != 'O') {
					board[1][1] = 'X';
					break;
				}
				else {
					cout << "Так ходить нельзя! Повторите ход!\n";
				}
			}
			else if (p1.size() == 1 && p1[0] == '6') {
				if (board[1][2] != 'X' && board[1][2] != 'O') {
					board[1][2] = 'X';
					break;
				}
				else {
					cout << "Так ходить нельзя! Повторите ход!\n";
				}
			}
			else if (p1.size() == 1 && p1[0] == '7') {
				if (board[2][0] != 'X' && board[2][0] != 'O') {
					board[2][0] = 'X';
					break;
				}
				else {
					cout << "Так ходить нельзя! Повторите ход!\n";
				}
			}
			else if (p1.size() == 1 && p1[0] == '8') {
				if (board[2][1] != 'X' && board[2][1] != 'O') {
					board[2][1] = 'X';
					break;
				}
				else {
					cout << "Так ходить нельзя! Повторите ход!\n";
				}
			}
			else if (p1.size() == 1 && p1[0] == '9') {
				if (board[2][2] != 'X' && board[2][2] != 'O') {
					board[2][2] = 'X';
					break;
				}
				else {
					cout << "Так ходить нельзя! Повторите ход!\n";
				}
			}
			else {
				cout << "Так ходить нельзя! Повторите ход!\n";
			}
		}
		DrawBoard();
	}
	void GoesSecondPlayer() {
		string p2 = "";
		cout << "\nХодит Игрок 2 - ";
		for (;;) {
			getline(cin, p2);
			if (p2.size() == 1 && p2[0] == '1') {
				if (board[0][0] != 'X' && board[0][0] != 'O') {
					board[0][0] = 'O';
					break;
				}
				else {
					cout << "Так ходить нельзя! Повторите ход!\n";
				}
			}
			else if (p2.size() == 1 && p2[0] == '2') {
				if (board[0][1] != 'X' && board[0][1] != 'O') {
					board[0][1] = 'O';
					break;
				}
				else {
					cout << "Так ходить нельзя! Повторите ход!\n";
				}
			}
			else if (p2.size() == 1 && p2[0] == '3') {
				if (board[0][2] != 'X' && board[0][2] != 'O') {
					board[0][2] = 'O';
					break;
				}
				else {
					cout << "Так ходить нельзя! Повторите ход!\n";
				}
			}
			else if (p2.size() == 1 && p2[0] == '4') {
				if (board[1][0] != 'X' && board[1][0] != 'O') {
					board[1][0] = 'O';
					break;
				}
				else {
					cout << "Так ходить нельзя! Повторите ход!\n";
				}
			}
			else if (p2.size() == 1 && p2[0] == '5') {
				if (board[1][1] != 'X' && board[1][1] != 'O') {
					board[1][1] = 'O';
					break;
				}
				else {
					cout << "Так ходить нельзя! Повторите ход!\n";
				}
			}
			else if (p2.size() == 1 && p2[0] == '6') {
				if (board[1][2] != 'X' && board[1][2] != 'O') {
					board[1][2] = 'O';
					break;
				}
				else {
					cout << "Так ходить нельзя! Повторите ход!\n";
				}
			}
			else if (p2.size() == 1 && p2[0] == '7') {
				if (board[2][0] != 'X' && board[2][0] != 'O') {
					board[2][0] = 'O';
					break;
				}
				else {
					cout << "Так ходить нельзя! Повторите ход!\n";
				}
			}
			else if (p2.size() == 1 && p2[0] == '8') {
				if (board[2][1] != 'X' && board[2][1] != 'O') {
					board[2][1] = 'O';
					break;
				}
				else {
					cout << "Так ходить нельзя! Повторите ход!\n";
				}
			}
			else if (p2.size() == 1 && p2[0] == '9') {
				if (board[2][2] != 'X' && board[2][2] != 'O') {
					board[2][2] = 'O';
					break;
				}
				else {
					cout << "Так ходить нельзя! Повторите ход!\n";
				}
			}
			else {
				cout << "Так ходить нельзя! Повторите ход!\n";
			}
		}
		DrawBoard();
	}
public:
	char restart = {};
	void Greetings() {
		cout << "Игра - крестики и нолики.\n"
			<< "Два игорка ставят свои фигуры в поля от 1 до 9\n\n"
			<< "Фигуры первого игрока - X\nФигуры второго игрока - O\n\n";
	}
	void StartGame() {
		CreateBoard();
		DrawBoard();
		short cells = 9;
		for (;;) {
			if (CheckRulesToWin() == '0') {
				GoesFirstPlayer();
				--cells;
			}
			else if (CheckRulesToWin() == '1') {
				cout << "\nИгра закончена!\n\nИгрок 1 - Победил!\nЖелаете начать заново?\nНажмите 'Y/y' - если хотите или любую другую, чтобы закончить - ";
				cin >> restart;
				cout << "\n";
				break;
			}
			if (cells == 0) {
				cout << "\nСвободные клетки закончились, ничья!\nЖелаете начать заново?\nНажмите 'Y/y' - если хотите или любую другую, чтобы закончить - ";
				cin >> restart;
				cout << "\n";
				break;
			}
			else if (CheckRulesToWin() == '0') {
				GoesSecondPlayer();
				--cells;
			}
			else if (CheckRulesToWin() == '2') {
				cout << "\nИгра закончена!\n\nИгрок 2 - Победил!\nЖелаете начать заново?\nНажмите 'Y/y' - если хотите или любую другую, чтобы закончить - ";
				cin >> restart;
				cout << "\n";
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
		string BugFix;
		getline(cin, BugFix);
		goto RESTART;
	}
	return 0;
}