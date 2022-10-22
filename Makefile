all: run

run:
	@clang++ -o containers -Wall -Wextra -Werror *.cpp --std=c++98

fclean:
	@rm containers
