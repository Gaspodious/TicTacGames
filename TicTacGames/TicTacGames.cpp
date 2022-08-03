#include <iostream>
#include <string>
using namespace std;

class TicTacGame {
private:
	char board[3][3] = {};
	void drawBoard() {
		system("cls");
		greetings();
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				cout << board[i][j] << ' ';
			}
			cout << "\n";
		}
	}
	int checkRulesToWin() {
		short playerWin = 0;
		if ((board[0][0] == 'x' && board[0][1] == 'x' && board[0][2] == 'x') ||
			(board[1][0] == 'x' && board[1][1] == 'x' && board[1][2] == 'x') ||
			(board[2][0] == 'x' && board[2][1] == 'x' && board[2][2] == 'x') ||
			(board[0][0] == 'x' && board[1][0] == 'x' && board[2][0] == 'x') ||
			(board[0][1] == 'x' && board[1][1] == 'x' && board[2][1] == 'x') ||
			(board[0][2] == 'x' && board[1][2] == 'x' && board[2][2] == 'x') ||
			(board[0][0] == 'x' && board[1][1] == 'x' && board[2][2] == 'x') ||
			(board[0][2] == 'x' && board[1][1] == 'x' && board[2][0] == 'x')) {
			playerWin = 1;
		}
		else
			if ((board[0][0] == 'o' && board[0][1] == 'o' && board[0][2] == 'o') ||
				(board[1][0] == 'o' && board[1][1] == 'o' && board[1][2] == 'o') ||
				(board[2][0] == 'o' && board[2][1] == 'o' && board[2][2] == 'o') ||
				(board[0][0] == 'o' && board[1][0] == 'o' && board[2][0] == 'o') ||
				(board[0][1] == 'o' && board[1][1] == 'o' && board[2][1] == 'o') ||
				(board[0][2] == 'o' && board[1][2] == 'o' && board[2][2] == 'o') ||
				(board[0][0] == 'o' && board[1][1] == 'o' && board[2][2] == 'o') ||
				(board[0][2] == 'o' && board[1][1] == 'o' && board[2][0] == 'o')) {
				playerWin = 2;
			}
		return playerWin;
	}
	void goesFirstPlayer() {
		string p1 = "";
		cout << "\nХодит Игрок 1 - ";
		if (restart == 'Y' || restart == 'y') {
			getline(cin, p1);
			restart = {};
		}
		for (;;) {
			getline(cin, p1);
			if (p1.size() == 1 && p1[0] == '1') {
				if (board[0][0] != 'x' && board[0][0] != 'o') {
					board[0][0] = 'x';
					break;
				}
				else {
					cout << "Так ходить нельзя! Повторите ход!\n";
				}
			}
			else if (p1.size() == 1 && p1[0] == '2') {
				if (board[0][1] != 'x' && board[0][1] != 'o') {
					board[0][1] = 'x';
					break;
				}
				else {
					cout << "Так ходить нельзя! Повторите ход!\n";
				}
			}
			else if (p1.size() == 1 && p1[0] == '3') {
				if (board[0][2] != 'x' && board[0][2] != 'o') {
					board[0][2] = 'x';
					break;
				}
				else {
					cout << "Так ходить нельзя! Повторите ход!\n";
				}
			}
			else if (p1.size() == 1 && p1[0] == '4') {
				if (board[1][0] != 'x' && board[1][0] != 'o') {
					board[1][0] = 'x';
					break;
				}
				else {
					cout << "Так ходить нельзя! Повторите ход!\n";
				}
			}
			else if (p1.size() == 1 && p1[0] == '5') {
				if (board[1][1] != 'x' && board[1][1] != 'o') {
					board[1][1] = 'x';
					break;
				}
				else {
					cout << "Так ходить нельзя! Повторите ход!\n";
				}
			}
			else if (p1.size() == 1 && p1[0] == '6') {
				if (board[1][2] != 'x' && board[1][2] != 'o') {
					board[1][2] = 'x';
					break;
				}
				else {
					cout << "Так ходить нельзя! Повторите ход!\n";
				}
			}
			else if (p1.size() == 1 && p1[0] == '7') {
				if (board[2][0] != 'x' && board[2][0] != 'o') {
					board[2][0] = 'x';
					break;
				}
				else {
					cout << "Так ходить нельзя! Повторите ход!\n";
				}
			}
			else if (p1.size() == 1 && p1[0] == '8') {
				if (board[2][1] != 'x' && board[2][1] != 'o') {
					board[2][1] = 'x';
					break;
				}
				else {
					cout << "Так ходить нельзя! Повторите ход!\n";
				}
			}
			else if (p1.size() == 1 && p1[0] == '9') {
				if (board[2][2] != 'x' && board[2][2] != 'o') {
					board[2][2] = 'x';
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
		drawBoard();
	}
	void goesSecondPlayer() {
		string p2 = "";
		cout << "\nХодит Игрок 2 - ";
		for (;;) {
			getline(cin, p2);
			if (p2.size() == 1 && p2[0] == '1') {
				if (board[0][0] != 'x' && board[0][0] != 'o') {
					board[0][0] = 'o';
					break;
				}
				else {
					cout << "Так ходить нельзя! Повторите ход!\n";
				}
			}
			else if (p2.size() == 1 && p2[0] == '2') {
				if (board[0][1] != 'x' && board[0][1] != 'o') {
					board[0][1] = 'o';
					break;
				}
				else {
					cout << "Так ходить нельзя! Повторите ход!\n";
				}
			}
			else if (p2.size() == 1 && p2[0] == '3') {
				if (board[0][2] != 'x' && board[0][2] != 'o') {
					board[0][2] = 'o';
					break;
				}
				else {
					cout << "Так ходить нельзя! Повторите ход!\n";
				}
			}
			else if (p2.size() == 1 && p2[0] == '4') {
				if (board[1][0] != 'x' && board[1][0] != 'o') {
					board[1][0] = 'o';
					break;
				}
				else {
					cout << "Так ходить нельзя! Повторите ход!\n";
				}
			}
			else if (p2.size() == 1 && p2[0] == '5') {
				if (board[1][1] != 'x' && board[1][1] != 'o') {
					board[1][1] = 'o';
					break;
				}
				else {
					cout << "Так ходить нельзя! Повторите ход!\n";
				}
			}
			else if (p2.size() == 1 && p2[0] == '6') {
				if (board[1][2] != 'x' && board[1][2] != 'o') {
					board[1][2] = 'o';
					break;
				}
				else {
					cout << "Так ходить нельзя! Повторите ход!\n";
				}
			}
			else if (p2.size() == 1 && p2[0] == '7') {
				if (board[2][0] != 'x' && board[2][0] != 'o') {
					board[2][0] = 'o';
					break;
				}
				else {
					cout << "Так ходить нельзя! Повторите ход!\n";
				}
			}
			else if (p2.size() == 1 && p2[0] == '8') {
				if (board[2][1] != 'x' && board[2][1] != 'o') {
					board[2][1] = 'o';
					break;
				}
				else {
					cout << "Так ходить нельзя! Повторите ход!\n";
				}
			}
			else if (p2.size() == 1 && p2[0] == '9') {
				if (board[2][2] != 'x' && board[2][2] != 'o') {
					board[2][2] = 'o';
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
		drawBoard();
	}
	void clearAndCreateBoard() {
		system("cls");
		greetings();
		char x = '0';
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				board[i][j] = ++x;
				cout << board[i][j] << " ";
			}
			cout << "\n";
		}
	}
public:
	char restart = {};
	void greetings() {
		cout << "Игра - крестики и нолики.\n"
			<< "Игорки ставят свои фигуры в поля от 1 до 9\n\n"
			<< "У игрока 1 - x\nУ игрока 2 - o\n\n";
	}
	void startGame() {
		clearAndCreateBoard();
		short cells = 9;
		for (;;) {
			if (checkRulesToWin() == 0) {
				goesFirstPlayer();
				--cells;
			}
			else if (checkRulesToWin() == 1) {
				cout << "\nИгра закончена!\n\nИгрок 1 - Победил!\nЖелаете начать заново?\nНажмите 'Y/y' - если хотите или любую другую, чтобы закончить - ";
				cin >> restart;
				cout << "\n";
				break;
			}
			if (checkRulesToWin() == 0) {
				goesSecondPlayer();
				--cells;
			}
			else if (checkRulesToWin() == 2) {
				cout << "\nИгра закончена!\n\nИгрок 2 - Победил!\nЖелаете начать заново?\nНажмите 'Y/y' - если хотите или любую другую, чтобы закончить - ";
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
		}
	}
};

int main() {
	setlocale(LC_ALL, "ru");
	TicTacGame game;
RESTART:
	game.startGame();
	if (game.restart == 'Y' || game.restart == 'y') {
		goto RESTART;
	}
	return 0;
}