#include<Best_score.h>

int win( int b[9]) {

    unsigned w[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
    int i;
    for(i = 0; i < 8; ++i) {
        if(b[w[i][0]] != 0 &&
           b[w[i][0]] == b[w[i][1]] &&
           b[w[i][0]] == b[w[i][2]])
            return b[w[i][2]];
    }
    return 0;
}
int minimax(int b[9], int p) {
    int winner = win(board);
    if(winner != 0) return winner*p;

   int move = -1;
    int score = -2;
    int i;
    for(i = 0; i < 9; ++i) {
        if(b[i] == 0) {
            b[i] = p;
            int thisScore = -minimax(board, player*-1);
            if(thisScore > score) {
                score = thisScore;
                move = i;
            }
            b[i] = 0;
        }
    }
    if(move == -1) return 0;
    return score;
}
