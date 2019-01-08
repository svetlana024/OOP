#include <cstdlib>
#include <conio.h>
#include <iostream>
#include "Square.h"
#include "TStackItem.h"
#include "TStack.h"

int main() {
	TStack stack;

	stack.push(Square(1));
	stack.push(Square(2));
	stack.push(Square(4));

	std::cout << stack;
	Square s;
	s= stack.pop();
	std::cout << s;
	s = stack.pop();
	std::cout << s;
	s = stack.pop();
	std::cout << s + Square(6);
	_getch();
	return 0;
}
