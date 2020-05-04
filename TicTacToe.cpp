#include <iostream>

void gamePlay();
void printBoard();
bool checkSpot(int a, int b);
void checkWinner();
void endGame(char c);

char board[3][3];

using namespace std;

int main(){
    cout << "Welcome to Tic-Tac-Toe" << endl;
    gamePlay();

    return 0;
}

void gamePlay(){
    int xCoord, yCoord, turn = 1;
    printBoard();
    while(true){
        cout << "Enter an X coordinate: " << endl;
        cin >> xCoord;
        cout << "Enter a Y coordinate:" << endl;
        cin >> yCoord;

        if(checkSpot(xCoord, yCoord)){
            if (turn % 2 == 0){
                board[xCoord][yCoord] = 'X';
            }
            else
                board[xCoord][yCoord] = 'O';
            turn++;
            printBoard();
            checkWinner();
        }
    }

}

void printBoard(){
    cout << "  0   1   2  " << endl;
    cout << "-------------" << endl;
    for(int i = 0; i < 3; i++){
        cout << "|";
        for(int j = 0; j < 3; j++){
            cout << " " << board[i][j] << " |";
        }
        cout << "  " << i << endl;
    }
    cout << "-------------" << endl << endl;
}

bool checkSpot(int a, int b){

    if(board[a][b] != 'X' && board[a][b] != 'O')
        return true; //need to implement a way to make them enter correct nswer
    return false;
}

void checkWinner(){
    if(board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X') endGame('X');
    if(board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X') endGame('X');
    if(board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X') endGame('X');
    if(board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X') endGame('X');
    if(board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X') endGame('X');
    if(board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X') endGame('X');
    if(board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') endGame('X');
    if(board[2][0] == 'X' && board[1][1] == 'X' && board[0][2] == 'X') endGame('X');

    if(board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O') endGame('O');
    if(board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O') endGame('O');
    if(board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O') endGame('O');
    if(board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O') endGame('O');
    if(board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O') endGame('O');
    if(board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O') endGame('O');
    if(board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') endGame('O');
    if(board[2][0] == 'O' && board[1][1] == 'O' && board[0][2] == 'O') endGame('O');

}

void endGame(char c){
    cout << "The game has ended. " << c << " has won." << endl;
    exit(0);
}
