#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>


#include<Best_score.h>
#include<Check_state.h>
#include<Draw_board.h>
#include<Player_input.h>

#define PROJECT_NAME "crisscross"

void test_Token_X(void);
void test_Token_O(void);
void test_Draw_board(void);
void test_samespot_input(void);
void test_botresponse_diagonal(void);
void test_botresponse_vertical(void);
void test_botresponse_horizontal(void);
void test_win_state(void);
void test_lose_state(void);
void test_draw_state(void);


int main() {

if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();
  CU_pSuite suite = CU_add_suite(PROJECT_NAME, 0, 0);
  
   CU_add_test(suite, "Token", test_Token_X);
   CU_add_test(suite, "Token", test_Token_O);
   CU_add_test(suite, "Draw_board", test_Draw_board);
   CU_add_test(suite, "user_input", test_samespot_input);
   CU_add_test(suite, "Bot", test_botresponse_diagonal);
   CU_add_test(suite, "Bot", test_botresponse_vertical);
   CU_add_test(suite, "Bot", test_botresponse_horizontal);
   CU_add_test(suite, "Check_state", test_win_state);
   CU_add_test(suite, "Check_state", test_lose_state);
   CU_add_test(suite, "Check_state", test_draw_state);
   
   CU_basic_set_mode(CU_BRM_VERBOSE);
    
   CU_basic_run_tests();
     
   CU_cleanup_registry();
   
    return 0;
}

void test_Token_X(void){
  CU_ASSERT('X' == Token(-1));
  }
  
void test_Token_O(void){
  CU_ASSERT('O' == Token(1));
    }

void test_Draw_board(void){
    int i[9] = {0,0,0,-1,0,0,0,0,0};
     CU_ASSERT('X' == Draw_board(i));
}

void test_samespot_input(void){
    int i[9] = {0,0,0,3,0,0,0,0,0};
     CU_ASSERT('This box is filled!' == user_input(i, 3));
}

void test_botresponse_diagonal(void){
     int i[9] = {0,0,0,0,-1,0,0,0,-1};
    CU_ASSERT(0 == Bot(i, 1));
}

void test_botresponse_vertical(void){
    int i[9] = {1,-1,0,0,0,0,0,-1,0};
     CU_ASSERT(4 == Bot(i, 1));
}

void test_botresponse_horizontal(void){
    int i[9] = {1,0,0,0,0,0,0,-1,-1};
    CU_ASSERT(6 == Bot(i, 1));
}

void test_win_state(void){
    int i[9] = {0,0,0,1,1,1,0,0,0};
    CU_ASSERT('User Wins!!' == Check_state(i, -1));
}

void test_lose_state(void){
    int i[9] = {0,0,0,1,1,1,0,0,0};
     CU_ASSERT('User lose, computer wins!!' == Check_state(i, 1));
}

void test_draw_state(void){
    int i[9] = {1,1,-1,-1,1,1,1,-1,-1};
    CU_ASSERT('Its a Draw' == Check_state(i,1));
}


  
