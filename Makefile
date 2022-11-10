all: run

run:
	@clang++ -o containers -Wall -Wextra -Werror *.cpp --std=c++17 -g -fsanitize=address 

fclean:
	@rm containers
