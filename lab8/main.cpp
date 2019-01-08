#include <cstdlib>
#include <iostream>
using namespace std;

#include "Figure.h"
#include "TStack.h"
#include <random>
#include<conio.h>

int main(int argc, char** argv) {
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(1, 10000);

	TStack<Figure> stack;
	unsigned int action;
	char figure_type;

	while (true) {
		std::cout << "Menu:" << std::endl;
		std::cout << "1) Push figure" << std::endl;
		std::cout << "2) Pop figure" << std::endl;
		std::cout << "3) Print" << std::endl;
		std::cout << "4) Standart sort" << std::endl;
		std::cout << "5) Parallel sort" << std::endl;
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
				std::cout << "Enter the way of IN: r - random sides, u - usual way: ";
				char way;
				std::cin >> way;
				switch (way) {
				case 'r': {
					int base_a = distribution(generator);
					int base_b = distribution(generator);
					int height = distribution(generator);
					t = std::make_shared<Trapeze>(base_a, base_b, height);
					stack.push(t);
					break;
				}
				case 'u':
					t = std::make_shared<Trapeze>(std::cin);
					stack.push(t);
					break;
				}
				break;
			}
			case 's': {
				std::cout << "Enter the way of IN: r - random sides, u - usual way: ";
				char way;
				std::cin >> way;
				switch (way) {
				case 'r': {
					int side_a = distribution(generator);
					t = std::make_shared<Square>(side_a);
					stack.push(t);
					break;
				}
				case 'u':
					t = std::make_shared<Square>(std::cin);
					stack.push(t);
					break;
				}
				break;
			}
			case 'r': {
				std::cout << "Enter the way of IN: r - random sides, u - usual way: ";
				char way;
				std::cin >> way;
				switch (way) {
				case 'r': {
					int side_a = distribution(generator);
					int side_b = distribution(generator);
					t = std::make_shared<Rectangle>(side_a, side_b);
					stack.push(t);
					break;
				}
				case 'u':
					t = std::make_shared<Rectangle>(std::cin);
					stack.push(t);
					break;
				}
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
			std::cout << "\t\tStandart Sort" << std::endl;
			stack.sort();
			std::cout << "\t\tDone" << std::endl;
			break;
		}
		case 5: {
			std::cout << "\t\tParallel Sort" << std::endl;
			stack.sort_parallel();
			std::cout << "\t\tDone" << std::endl;
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