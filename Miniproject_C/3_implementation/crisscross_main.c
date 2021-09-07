//Just cd to implementaion folder and "make run" to play.
//Ignore the warnings shown (they are not errors, the program will work fine), those are just the warnings for too much words returning from the function, which is only used for test purposes, not a part of the actual program.




#include<stdio.h>
#include<Best_score.h>
#include<Check_state.h>
#include<Draw_board.h>
#include<Player_input.h>

int main() {



    int board[9] = {0,0,0,0,0,0,0,0,0};

    printf("Choose X or O\nPlease enter 1 for X and 2 for O");
    int player=0;
    int p=0;
    int p2=0;
     
    scanf("%d",&player);
    if(player == 1){
        p=1;
        p2=-1;
    }
    else if(player == 2){
        p = -1;
        p2=1;
    }
    printf("\n");
    unsigned turn;
    for(turn = 0; turn < 9 && win(board) == 0; ++turn) {
        if((turn+player) % 2 == 0){
            int r=0;
            r = Bot(board, p);
            board[r] = p;
        }
        else {
            Draw_board(board);
            int r=0;

            r = user_input(board, p2);

            board[r] = p2;

        }
    }
    Check_state(board, p);

}
