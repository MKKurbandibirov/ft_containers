all: run

run:
	@clang++ -o containers -Wall -Wextra -Werror *.cpp --std=c++11

fclean:
	@rm containers
