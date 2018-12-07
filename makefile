plagiarismCatcher: main.o plagiarism.o
	c++ -std=c++0x -o plagiarismCatcher main.o plagiarism.o
main.o: main.cpp
	c++ -std=c++0x -c main.cpp
plagiarism.o: plagiarism.cpp
	c++ -o plagiarism.cpp