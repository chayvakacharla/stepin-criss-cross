#include<Draw_board.h>


char Token(int i) {
    switch(i) {
        case -1:
            return 'X';
        case 0:
            return ' ';
        case 1:
            return 'O';
    }
}

int Draw_board(int positions[9]) {
    printf(" %c | %c | %c\n", Token(positions[0]), Token(positions[1]), Token(positions[2]));
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", Token(positions[3]), Token(positions[4]), Token(positions[5]));
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", Token(positions[6]), Token(positions[7]), Token(positions[8]));


    return Token(positions[3]); // for testing purpose.
}
