// Tic Toc Toe Game by Royal Crystal OOP
#include <iostream>
#include <iomanip>
#include <thread>
#include <chrono>
using namespace std;
int turn;
void ClearScreen() {
	system("cls");
}
/*
	Class Map will draw map
*/
class TicTocToe {
	private:
		string space[9] = { "1","2","3","4","5","6","7","8","9" };
	public:
		void drawMap() {
			cout << endl << endl;
			cout << setw(20) << space[0] << "   |  " << space[1] << "  |  " << space[2] << endl;
			cout << setw(24) << "____|" << "_____" << "|____" << endl;
			cout << setw(20) << space[3] << "   |  " << space[4] << "  |  " << space[5] << endl;
			cout << setw(24) << "____|" << "_____" << "|____" << endl;
			cout << setw(20) << space[6] << "   |  " << space[7] << "  |  " << space[8] << endl;
			cout << setw(24) << "    |" << "     " << "|    " << endl;
			cout << "Player 1 : x , Player 2 : O \n\n\n";
		}
		void playersChoise(int ch , int &turn) {
			ch--;
			if (space[ch] != "O" && space[ch] != "X") {
				if (turn == 2) {
					cout << "Hehe";
					space[ch] = "O";
				}
				else if (turn == 1) {
					cout << "Hehe";
					space[ch] = "X";
				}
			}
			else {
				cout << "Filled by other player";
				turn--;
				this_thread::sleep_for(chrono::milliseconds(1200));
			}
		}
		int playerWin() {
			if (space[0] == space[1] && space[1] == space[2]) {
				if (space[0] == "O") {
					return 1;
				}
				else {
					return 0;
				}
			}
			else if (space[3] == space[4] && space[4] == space[5]) {
				if (space[3] == "O") {
					return 1;
				}
				else {
					return 0;
				}
			}
			else if (space[6] == space[7] && space[7] == space[8]) {
				if (space[6] == "O") {
					return 1;
				}
				else {
					return 0;
				}
			}
			else if (space[0] == space[4] && space[4] == space[8]) {
				if (space[0] == "O") {
					return 1;
				}
				else {
					return 0;
				}
			}
			else if (space[1] == space[4] && space[4] == space[7]) {
				if (space[1] == "O") {
					return 1;
				}
				else {
					return 0;
				}
			}
			else if (space[2] == space[5] && space[5] == space[8]) {
				if (space[2] == "O" ) {
					return 1;
				}
				else {
					return 0;
				}
			}
			else if (space[2] == space[4] && space[4] == space[6]) {
		
				if (space[2] == "O") {
					return 1;
				}
				else {
					return 0;
				}
			}
			else if (space[0] == space[3] && space[3] == space[6]) {
	
				if (space[0] == "O") {
					return 1;
				}
				else {
					return 0;
				}
			}
			else if (space[0] != "1" && space[1] != "2" && space[2] != "3" &&
				space[3] != "4" && space[4] != "5" && space[5] != "6" &&
				space[6] != "7" && space[7] != "8" && space[8] != "9") 
			{
				return 2;
			}
			return -1;
		}
};
void whichPlayer(int playerNum) {
	if (playerNum == 2) {
		cout << "Player 2 is Choosing : " << endl;
	}
	else if (playerNum == 1) {
		cout << "Player 1 is Choosing  : " << endl;
	}
}
int main() {
	TicTocToe tic;
	cout << "Select Which player to start game : " << endl;
	cin >> turn;
	while ( true ){
		ClearScreen();
		tic.drawMap();
		turn = (turn % 2) ? 1 : 2;
		whichPlayer(turn); // Player x  0 for player 1 and ... is choosing 
		int playerSpaceChoice;
		if (turn == 2) {
			cin >> playerSpaceChoice;
			tic.playersChoise(playerSpaceChoice, turn);
		}
		else if (turn == 1) {
			cin >> playerSpaceChoice;
			tic.playersChoise(playerSpaceChoice, turn);
		}
		cout << endl;
		if (tic.playerWin() == 1) {
			cout << "Player 2 Wins the game\n";
			break;
		}
		else if (tic.playerWin() == 0) {
			cout << "Player 1 Wins the game\n";
			break;
		}
		else if (tic.playerWin() == 2) {
			cout << "Draw!!" << endl;
			break;
		}
		turn++;
	}
}