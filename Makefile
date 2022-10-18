all: run

run:
	@clang++ -o containers -Wall -Wextra -Werror -std=c++98 *.cpp

fclean:
	@rm containers
