#include <cstdlib>
#include <iostream>
#include "TStack.h"
#include <conio.h>

 int main(int argc, char** argv) {

	TStack<Figure> stack;
	unsigned int action;

	while (true) {
		std::cout << "Menu:" << std::endl;
		std::cout << "1) Push figure" << std::endl;
		std::cout << "2) Pop figure" << std::endl;
		std::cout << "3) Print" << std::endl;
		std::cout << "4) Print size" << std::endl;
		std::cout << "0) Quit" << std::endl;
		std::cin >> action;

		if (action == 0) {
			break;
		}

		switch (action) {
		case 1: {
			char figure_type;
			std::shared_ptr<Figure> t;
			std::cout
				<< "Enter figure type: t - trapeze, s - square, r - rectangle: ";
			std::cin >> figure_type;
			switch (figure_type) {
			case 't': {
				t = std::make_shared<Trapeze>(std::cin);
				stack.push(t);
				break;
			}
			case 's': {
				t = std::make_shared<Square>(std::cin);
				stack.push(t);
				break;
			}
			case 'r': {
				t = std::make_shared<Rectangle>(std::cin);
				stack.push(t);
				break;
			}
			default: {
				std::cout << "Try more..." << std::endl;
				break;
			}
			}

			break;
		}
		case 2: {
			stack.pop();
			break;
		}
		case 3: {
			for (auto i : stack)
				std::cout << *i << std::endl;
			break;
		}

		case 4: {
			size_t size = stack.GetSize();
			std::cout << "size: " << size << std::endl;
			break;
		}
		default:
			std::cout << "Invalid action" << std::endl;
			break;
		}
	}
	_getch();
	return 0;
}