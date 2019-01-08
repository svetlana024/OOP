#include "TStack.h"
#include <iostream>
#include <conio.h>
#include "Square.h"
#include "Trapeze.h"
#include "Rectangle.h"
#include "TTree.h"


int main(void) {
	TTree<TStack<Figure>, std::shared_ptr<Figure> > tree;
	unsigned int action;
	char figure_type;
	int criteria;
	while (true) {
		std::cout << "Menu:" << std::endl;
		std::cout << "1) Push figure" << std::endl;
		std::cout << "2) Remove by criteria" << std::endl;
		std::cout << "3) Print" << std::endl;
		std::cout << "0) Quit" << std::endl;
		std::cin >> action;

		if (action == 0) {
			break;
		}

		switch (action) {
		case 1: {
			std::shared_ptr<Figure> t;
			std::cout
				<< "Enter figure type: t - trapeze, s - square, r - rectangle: ";
			std::cin >> figure_type;
			switch (figure_type) {
			case 't': {
				t = std::make_shared<Trapeze>(std::cin);
				tree.insert(t);
				break;
			}
			case 's': {
				t = std::make_shared<Square>(std::cin);
				tree.insert(t);
				break;
			}
			case 'r': {
				t = std::make_shared<Rectangle>(std::cin);
				tree.insert(t);
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
			std::cout << "Enter criteria" << std::endl;
			std::cout << "1) By type\n2) Lesser than square\n";
			std::cin >> criteria;
			if (criteria == 1) {
				std::cout
					<< "Enter figure type: t - trapeze, s - square, r - rectangle: ";
				std::cin >> figure_type;
				switch (figure_type) {
				case 't':
					tree.removeByType(2);
					break;
				case 's':
					tree.removeByType(1);
					break;
				case 'r':
					tree.removeByType(3);
					break;
				}
				break;
			}
			else if (criteria == 2){
				size_t square;
				std::cout << "Enter square" << std::endl;
				std::cin >> square;
				tree.removeLesser(square);
			}
			else
				break;
		}
		case 3: {
			tree.inorder();
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