PROJECT_NAME = crisscross

BUILD = build

SRC = crisscross_main.c\
src/Best_score.c\
src/Check_state.c\
src/Draw_board.c\
src/Player_input.c\

TEST_SRC = src/Best_score.c\
src/Check_state.c\
src/Draw_board.c\
src/Player_input.c\
test/Test_crisscross.c\

TEST_OUTPUT = $(BUILD)/Test_$(PROJECT_NAME).out

INC	= -Iinc

PROJECT_OUTPUT = $(BUILD)/$(PROJECT_NAME).out

DOCUMENTATION_OUTPUT = documentation/html

$(PROJECT_NAME):all

.PHONY: run clean test  doc all

all: $(SRC) $(BUILD)
	gcc $(SRC) $(INC) -o $(PROJECT_OUTPUT).out
  
run:$(PROJECT_NAME)
	./$(PROJECT_OUTPUT).out
	
doc:
	make -C ./documentation


test:$(BUILD)
	gcc $(TEST_SRC) $(INC) -o $(TEST_OUTPUT) -lcunit
	./$(TEST_OUTPUT)
  
  
clean:
	rm -rf $(BUILD) $(DOCUMENTATION_OUTPUT)
  
  
 $(BUILD):
	mkdir build
