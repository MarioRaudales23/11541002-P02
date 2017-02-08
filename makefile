main:	TreeNode.o Person.o Object.o Tree.o Employee.o main.o
	g++ TreeNode.o Person.o Object.o Tree.o main.o Employee.o -o run

Person.o:	Person.h Person.cpp Object.h
	g++ -c Person.cpp

Object.o: Object.h Object.cpp
	g++ -c Object.cpp

main.o:	main.cpp TreeNode.h Tree.h Person.h Object.h Employee.h
	g++ -c main.cpp
Employee.o:	Employee.cpp Employee.h Object.h
	g++ -c Employee.cpp
TreeNode.o:	TreeNode.h TreeNode.cpp Object.h
	g++ -c TreeNode.cpp
Tree.o:	TreeNode.h Object.h Tree.h Tree.cpp
	g++ -c Tree.cpp

clean:
	rm *.o
