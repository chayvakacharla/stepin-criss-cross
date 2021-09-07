#include<Player_input.h>
#include<Best_score.h>

int Bot(int board[9], int b) {


    int move = -1;
    int score = -2;
    int i;
    for(i = 0; i < 9; ++i) {
        if(board[i] == 0) {
            board[i] = 1;
            int thisscore = -minimax(board, -1);
            board[i] = 0;
            if(thisscore > score) {
                score = thisscore;
                move = i;
            }
        }
    }
    return move;
}

int user_input(int board[9], int b) {

int move = 0;
if(b==3){           //for test purpose start
    move = 3;
    if(board[move] != 0){
    printf("This box is filled!\n");
    return 'This box is filled!';
    }
}                   // test stop
else {
do {
start:
printf("\nInput move ([0..8]): ");
scanf("%d", &move);
if(board[move] != 0) {
printf("This box is filled!\n");
goto start;
}
printf("\n");
} while (move >= 9 && board[move] == 0);
return move;
}
}
