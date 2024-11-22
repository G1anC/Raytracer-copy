##
## EPITECH PROJECT, 2024
## rtx
## File description:
## Makefile
##

.DEFAULT_GOAL := all

NAME = raytracer
SRC = $(wildcard src/RayTracer/Primitives/*.cpp)
SRC += $(wildcard src/RayTracer/Render/*.cpp)
SRC += $(wildcard src/*.cpp src/**/*.cpp)
CFLAGS = -g -Wall -Wextra -std=c++20
CFLAGS += -lconfig++
CFLAGS += -I include
CFLAGS += -lsfml-graphics -lsfml-window -lsfml-system

TEST_SRC = $(wildcard tests/*.cpp)
SRC_DIRS = $(shell find src -mindepth 1 -type d)
BUILD_DIRS = $(patsubst src%, build%, $(SRC_DIRS))
OBJ = $(SRC:src/%.cpp=build/%.o)

build/%.o: src/%.cpp
	@g++ -c -o $@ $< $(CFLAGS)

$(OBJ): | setup_build

all: $(OBJ)
	@g++ -o $(NAME) $(OBJ) $(CFLAGS)

setup_build: $(SRC_DIRS)
	@mkdir -p $(BUILD_DIRS)
	
raytracer: all

clean:
	@rm -f $(OBJ)
	@rm -rf build
	@rm -f unit_tests*

fclean: clean
	@rm -f vgcore.*
	@rm -f $(NAME)

img:
	@rm -f screenshots/*.ppm
	@rm -f screenshots/*.png

re: fclean all

commit: fclean
	@make
	if [ $$? -ne 0 ]; then \
		exit 84; \
	fi
	@clear
	@git status
	@echo -e "\n"
	@read -p "Files to commit --> " FILES_TO_PUSH; \
	git add $$FILES_TO_PUSH
	@read -p "Commit Message --> " MSG; \
	git commit -m "$$MSG" && \
	git push origin main
	@clear

OBJ_WITHOUT_MAIN = $(filter-out src/main.o, $(OBJ))

tests_run: $(OBJ)
	@g++ -o unit_tests $(TEST_SRC) $(SRC_WITHOUT_MAIN) $(OBJ_WITHOUT_MAIN) -I./src --coverage -lcriterion
	@./unit_tests

.PHONY: all clean fclean re tests_run setup_build commit
