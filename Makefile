all: run

run:
	@clang++ -o containers -Wall -Wextra *.cpp --std=c++98

fclean:
	@rm containers
