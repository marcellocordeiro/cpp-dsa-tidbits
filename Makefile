compiler = g++
flags = -std=c++14 -Wall -Wextra -Werror -pedantic-errors -O2

test_name = test

t: compileTest #runTest cleanup

compileTest:
	@$(compiler) $(flags) $(test_name).cpp -o $(test_name)

runTest:
	@./$(test_name)

cleanup:
	@rm -f $(test_name)
	
# -f: ignore nonexistent files, never prompt
# @: don't print the command