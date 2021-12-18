// ----------Unbeatable Tic Tac Toe Code-------------

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int max(int a, int b){
    return (a>b) ? a : b;
}

int min(int a, int b){
    return (a<b) ? a : b;
}

int printTheArray(char arr[3][3]){    //function to print the matrix
    for(int i=0;i<1;i++){
            for(int j=0;j<3;j++){
                printf(" %c ",arr[i][j]);
            }
            printf("\n");
        }
        for(int i=1;i<2;i++){
            for(int j=0;j<3;j++){
                printf(" %c ",arr[i][j]);
            }
            printf("\n");
        }
        for(int i=2;i<3;i++){
            for(int j=0;j<3;j++){
                printf(" %c ",arr[i][j]);
            }
            printf("\n");
        }
}

int horizontal(char arr[3][3]){    //check horizontal rows for winner
    for(int i=0;i<3;i++){
        if (arr[i][0]== arr[i][1] && arr[i][1]==arr[i][2] && arr[i][0]!=' ') {
            return true;  
        }
    }
    return false;
}

int vertical(char arr[3][3]){     //check vertical columns for winner
    for(int i=0;i<3;i++){
    if (arr[0][i]== arr[1][i] && arr[1][i]==arr[2][i] && arr[0][i]!=' ') {
        return true;   
    }
    }
    return false;
}


int diagonal(char arr[3][3]){     //check diagonals for winner
    if (arr[0][0]== arr[1][1]&&arr[1][1]== arr[2][2] && arr[0][0]!=' ') {
        return true;  
    }
    if(arr[0][2]== arr[1][1]&&arr[1][1]== arr[2][0] && arr[0][2]!=' ') {
        return true;  
    }
    return false;
}


bool gameOver(char arr[3][3])
{
    if(horizontal(arr) || vertical(arr) || diagonal(arr) )	return true;
    return false;
}


int minimax(char arr[3][3], int depth, bool ismaximizing){   //apply minimax algorithm
    int val = 0;
	int bestVal = 0;

    if(gameOver(arr)==true){
        //return 9 - depth;
         if(ismaximizing==true) return -1;
         if(ismaximizing==false) return 1;
    }
    else{
        if(depth<9){
            if(ismaximizing==true){   // if the player is the robot -> maximize
                bestVal= -9999;
                for(int i=0;i<3;i++){    // iteriate on the arr
                    for(int j=0;j<3;j++){
                        if(arr[i][j]==' ') {
                            arr[i][j]='x';      // try this move
                            val = minimax(arr, depth+1, false);
                            arr[i][j] = ' ';    // undo the move
                            if(val>bestVal){
                                bestVal = val;
                            }
                        }
                    }
                }
                // printf("depth: %d, score: %d\n", depth, bestVal);
                return bestVal;  //return best move for the robot
            }
            else{    // if the player is human -> minimize
                bestVal= 9999;
                for(int i=0;i<3;i++){
                    for(int j=0;j<3;j++){
                        if(arr[i][j]==' '){
                            arr[i][j]='o';
                            val = minimax(arr, depth+1, true);
                            arr[i][j] = ' ';
                            if(val<bestVal){
                                bestVal = val;
                            }
                        }
                    }
                }
                // printf("depth: %d, score: %d\n", depth, bestVal);
                return bestVal; //return the lowest score for the human
            }
        }
        else
            return 0;
    }

}

int bestMove(char arr[3][3], int moveIndex){
        int bestVal = -9999;
        int val =0;
        int row=0 , col=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(arr[i][j]== ' '){
                    arr[i][j]='x';
                    val = minimax(arr,moveIndex+1,false);
                    arr[i][j]= ' ';
                    //printf("%d\n", val);
                    if(val>bestVal){
                        bestVal=val;
                        row = i;
                        col = j;

                    }
                }
            }
        }
        arr[row][col] = 'X';
}


int move(char arr[3][3]){    //function to reserve the players' choosen spot
        int n;
        printf("choose your spot 1:9\n");
        scanf("%d",&n);
        if(n==1){
            if(arr[0][0]== ' ') {
                arr[0][0] = 'o';
            }
            else {
            printf("taken spot, try again\n");
            move(arr);
            }

        }
        else if(n==2){
            if(arr[0][1]== ' ') {
                arr[0][1] = 'o';

            }
            else {
            printf("taken spot, try again\n");
            move(arr);
            }
        }
        else if(n==3){
            if(arr[0][2]==' ') {
                arr[0][2] = 'o';

            }
            else {
            printf("taken spot, try again\n");
            move(arr);
            }
        }
        else if(n==4){
            if(arr[1][0]==' ') {
                arr[1][0] = 'o';

            }
            else {
            printf("taken spot, try again\n");
            move(arr);
            }
        }
        else if(n==5){
            if(arr[1][1]==' ') {
                arr[1][1] = 'o';

            }
            else {
            printf("taken spot, try again\n");
            move(arr);
            }
        }
        else if(n==6){
            if(arr[1][2]==' ') {
                arr[1][2] = 'o';

            }
            else {
            printf("taken spot, try again\n");
            move(arr);
            }
        }
        else if(n==7){
            if(arr[2][0]==' ') {
                arr[2][0] = 'o';

            }
            else {
            printf("taken spot, try again\n");
            move(arr);
            }
        }
        else if(n==8){
            if(arr[2][1]==' ') {
                arr[2][1] = 'o';

            }
            else {
            printf("taken spot, try again\n");
            move(arr);
            }
        }
        else if(n==9){
            if(arr[2][2]==' ') {
                arr[2][2] = 'o';

            }
            else {
            printf("taken spot, try again\n");
            move(arr);
            }
        }
        else{
            printf("invalid spot, try again\n");
            move(arr);
        }

}



int play(){

    int player=0;

    printf("\nChoose who starts first:\n");
    printf("\nPress 1 for Robot\nPress 2 for human\n");
    scanf("%d",&player);

    //In case of invalid player input
    if(player != 1 && player != 2){
        wrong_choice();
    }

        if(player == 1)
            printf("You choosed Robot to play first!\n");

        else if(player == 2)
            printf("You choosed Human to play first!\n");

    int moveIndex = 0;

    char arr[3][3];
    for(int i=0;i<3;i++){    //intialize the board
        for(int j=0;j<3;j++){
            arr[i][j]=' ';
        }
    }     
    while(gameOver(arr)==false && moveIndex!=9){

        if(player ==1){
            bestMove(arr,moveIndex);
            printf("The board after the Robot move:\n");
            printTheArray(arr);
            moveIndex++;
            player = 2;
        }
        else if(player ==2){
            move(arr);
            printf("The board after your move:\n");
            printTheArray(arr);
            moveIndex++;
            player = 1;
        }
    }

    if(gameOver(arr)==false && moveIndex == 9 ){
        printf("It's a draw\n");
        Restart();
    }

    else{
        if (player == 1)
            player = 2;
        else if (player == 2)
            player = 1;

        checkWinner(player);
    }

}

int Restart(){
    char playAgain;
    printf("Do you want to play again? (y/n)\n");
    scanf(" %c" , & playAgain);
    if (playAgain == 'y' || playAgain == 'Y')
        play();
    else if(playAgain == 'n' || playAgain == 'N')
        exit(0);
    else{
        printf("Invalid input!...Try again\n");
        Restart();
    }
}

int wrong_choice(){
        printf("Invalid input!...Try again\n");
        play();
}

void checkWinner(int turn){
    if (turn == 1)
        printf("Computer won!\n");    
    else
        printf("Human won!\n");

    Restart();
}

int main(){
    play();
}
