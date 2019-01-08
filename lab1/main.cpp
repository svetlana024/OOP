#include <cstdlib>
#include <conio.h>
#include "Square.h"
#include "Rectangle.h"
#include "Trapeze.h"

int main(int argc, char** argv) {

	Figure *ptr = new Square(std::cin);
	ptr->Print();
	std::cout << ptr->Area() << std::endl;
	delete ptr;
	Figure *ptr2 = new Rectangle(std::cin);
	ptr2->Print();
	std::cout << ptr2->Area() << std::endl;
	delete ptr2;
	Figure *ptr3 = new Trapeze(std::cin);
	ptr3->Print();
	std::cout << ptr3->Area() << std::endl;
	delete ptr3;
	_getch();
	return 0;
}
