#include <iostream>;
#include <cstdlib>;
#include <ctime>;
using namespace std;

int diceRoll() {
	return rand() % 6 + 1;
}
//Player turn play
int playerTurn(int scorePlayer) {
	int pot = 0;
	char ch = ' ';
	//Display turn
	cout << "Player turn" << endl;
start:
	//Each time
	while (scorePlayer < 50)
	{
		//Call dice roll
		int rollVal = diceRoll();
		//Check if 1 then bust and return
		if (rollVal == 1) {
			cout << "Die Roll " << rollVal << " : BUST" << endl << endl;
			pot = 0;
			return scorePlayer;
		}
		//Otherwise repeatedly calculate
		else {
			//Increment pot value
			pot += rollVal;
			//Prompt for roll or hold
			cout << "Dice Roll : " << rollVal << "   Pot : " << pot << "    (R)oll again or (H)old?";
			cin >> ch;
			ch = toupper(ch);
			//Option error check
			while (ch != 'R' && ch != 'H') {
				cout << "You must enter R or H" << endl;
				cout << "             (R)oll again or (H)old?";
				cin >> ch;
				ch = toupper(ch);
			}
			//If ch is roll then increment score repeat again
			if (ch != 'R') {
				scorePlayer += rollVal;
				return scorePlayer;
			}
			else {
				scorePlayer += rollVal;
			}
		}
	}
	//Return score after
	return scorePlayer;
}
//AI Play
int AITurn(int AI) {
	int pot = 0, count = 0;
	char ch = ' ';
	cout << "AI turn" << endl;
	//Loop until computer turn reach 20 or score >=50
	while (count < 20 && AI < 50) {
		int rollVal = diceRoll();
		//Increment turn count
		count++;
		//Check BUST condition
		if (rollVal == 1) {
			cout << "Die Roll " << rollVal << " : BUST" << endl << endl;
			pot = 0;
			return AI;
		}
		//Otherwise Increment values
		else {
			pot += rollVal;
			cout << "Dice Roll : " << rollVal << "   Pot : " << pot << endl;
			AI += rollVal;
		}
	}
	return AI;
}
// Main Program
int main()
{
	//For different rand values
	srand(time_t(0));
	int scorePlayer = 0, AI = 0;
	bool turn = true;
	char ch = 'y';
	//Loop until user enter n
	while (ch == 'y') {
		//Turn selection for player first
		if (turn == true) {
			//Initial scores
			cout << "Score you: " << scorePlayer << "   AI: " << AI << endl << endl;
			//Loop until reach 50
			while (scorePlayer < 50 && AI < 50) {
				//Player got first turn
				scorePlayer = playerTurn(scorePlayer);
				//Check the winning state
				if (scorePlayer < 50) {
					cout << "Score you: " << scorePlayer << "   AI: " << AI << endl << endl;
					//Call AI play
					AI = AITurn(AI);
					//Check winning status
					if (AI < 50) {
						cout << "Score you: " << scorePlayer << "   AI: " << AI << endl << endl;
					}
				}
				cout << endl << endl;
			}
			//Winner display
			if (scorePlayer > AI) {
				cout << "You are the winner!!!!!!\nTotal Score : " << scorePlayer << endl << endl;
			}
			else {
				cout << "AI is the winner!!!!!!\nTotal Score : " << AI << endl << endl;
			}
			turn = false;
			scorePlayer = 0;
			AI = 0;
		}
		//Turn seclection for AI
		else {
			cout << "Score you: " << scorePlayer << "   AI: " << AI << endl << endl;
			//Loop until reach 50
			while (scorePlayer < 50 && AI < 50) {
				//AI got first turn
				AI = AITurn(AI);
				//Check winning status
				if (AI < 50) {
					cout << "\n\nScore you: " << scorePlayer << "   AI: " << AI << endl << endl;
					scorePlayer = playerTurn(scorePlayer);
					//Check the winning state
					if (scorePlayer < 50) {
						//Print current scores
						cout << "\n\nScore you: " << scorePlayer << "   AI: " << AI << endl << endl;
					}

				}
				cout << endl << endl;
			}
			//Winner display
			if (scorePlayer > AI) {
				cout << "You are the winner!!!!!! Total Score : " << scorePlayer << endl << endl;
			}
			else {
				cout << "AI is the winner!!!!!!\nTotal Score : " << AI << endl << endl;
			}
			turn = true;
			scorePlayer = 0;
			AI = 0;
		}
		//Repeat part
		cout << "Do you wnat to play again? (y/n)";
		cin >> ch;
		ch = tolower(ch);
		while (ch != 'y' && ch != 'n') {
			cout << "You must enter Y or N" << endl;
			cout << "        Do you wnat to play again? (y/n)";
			cin >> ch;
			ch = tolower(ch);
		}
	}
	//End
	cout << "                GOOD BYE!!!!!" << endl << endl;
	return 0;
}
