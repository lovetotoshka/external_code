#include <iostream>
#include <limits>
#include <string>
#include <sstream>
#include <iomanip>
#include "../StaticLib1/framework.h"

using namespace Prog3;

void get_int(int& a) {
	const char* pr = "";
	do {
		std::cout << pr << std::endl;
		pr = "You are wrong  \\(-_-)/ repeat please!";
		std::cin >> a;
		if (!std::cin.good()) {
			std::cout << "Enter integer!" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else {
			break;
		}
	} while (true);
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return;
}

Num* create() {
	{
		int flag = 0;
		do {

			try {
				std::cout << "Enter hexadecimal number" << std::endl;
				std::string s;
				std::cin >> s;
				std::cout << std::endl;
				Num num2(s);
				//y2 = &num2;
				flag = 1;
				std::cout << std::endl;
				std::cout << num2;
				std::cout << std::endl;
				return &num2;
			}
			catch (const std::exception& ex) {
				std::cout << ex.what() << std::endl;
			}
		} while (!flag);
	}
}


int dialog() {
	int choise;
	Num* y1 = nullptr;
	Num* y2 = nullptr;
	Num* y3 = nullptr;
	Num* y4 = nullptr;
	do {
		std::cout << "Make your choice: --> \n" << std::endl;
		puts("Enter 1 to make num3 with constant \n"
			"Enter 2 to enter num2 \n"
			"Enter 3 to enter num1 \n"
			"Enter 4 to set  num4 \n"
			"Enter 5 to compare num1 and num2\n"
			"Enter 6 to summ  \n"
			"Enter 7 to shift left \n"
			"Enter 8 to shift right\n"
			"Enter 9 to check even\n"
			"Enter 10 to subtract num1 - num2\n"
			"Enter 11 to use empty constructor num4 \n"
			"Enter any Natural  to quit\n"
		);

		get_int(choise);
		switch (choise) {
		case (1):
		{
			int hex;
			std::cout << "Enter Hexademical number" << std::endl;
			std::string s;
			std::cin >> s;
			std::istringstream(s) >> std::hex >> hex;
			Num num1(hex);
			std::cout << num1 << std::endl;
		}
		break;
		case (2):
		{
			int flag = 0;
			do {

				try {
					std::cout << "Create hexadecimal number" << std::endl;
					Num num2;
					std::cin >> num2;
					std::cout << std::endl;
					y2 = &num2;
					flag = 1;
					std::cout << std::endl;
					std::cout << num2;
					std::cout << std::endl;

				}
				catch (const std::invalid_argument& ex) {
					std::cout << ex.what() << std::endl;
				}
			} while (!flag);
		}

		break;
		case (3):
		{
			int flag = 0;
			do {

				try {
					std::cout << "Enter hexadecimal number" << std::endl;
					std::string s;
					std::cin >> s;
					std::cout << std::endl;
					Num num2(s);
					y2 = &num2;
					flag = 1;
					std::cout << std::endl;
					std::cout << num2;
					std::cout << std::endl;

				}
				catch (const std::exception& ex) {
					std::cout << ex.what() << std::endl;
				}
			} while (!flag);
		}
		break;
		case (4): {
			Num num4;
			std::cout << num4;
			std::cout << std::endl;
			int flag = 0;
			do {

				try {
					std::cout << "Enter hexadecimal number" << std::endl;
					std::string s;
					std::cin >> s;
					std::cout << std::endl;
					Num num4;
					num4.setNum(s);
					y4 = &num4;
					flag = 1;
					std::cout << std::endl;
					std::cout << num4;
					std::cout << std::endl;

				}
				catch (const std::invalid_argument& ex) {
					std::cout << ex.what() << std::endl;
				}
			} while (!flag);

		}

				break;
		case (5): {
			std::cout << "Enter hexadecimal number" << std::endl;
			std::string s;
			std::cin >> s;
			std::cout << std::endl;
			Num num2(s);
			std::cout << "Enter hexadecimal number" << std::endl;
			std::cin >> s;
			std::cout << std::endl;
			Num num1(s);
			if (num1 == num2)
				std::cout << "numbers are equal" << std::endl;
			else
				std::cout << "numbers aren't equal" << std::endl;
		}
				break;
		case (6):

		{
			Num num1;
			Num num2;

			int flag = 0;
			do {

				try {
					std::cout << "Create hexadecimal number" << std::endl;
					std::string s;
					std::cin >> s;
					num1.setNum(s);
					flag = 1;
					std::cout << num1;
					std::cout << std::endl;

				}
				catch (const std::exception& ex) {
					std::cout << ex.what() << std::endl;
				}
			} while (!flag);

			flag = 0;
			do {

				try {
					std::cout << "Create hexadecimal number" << std::endl;
					std::string s;
					std::cin >> s;
					num2.setNum(s);
					flag = 1;
					std::cout << num2;
					std::cout << std::endl;

				}
				catch (const std::exception& ex) {
					std::cout << ex.what() << std::endl;
				}
			} while (!flag);
			try {
				Num summa = num1 + num2;
				std::cout << summa << std::endl;
			}
			catch (const std::exception& ex) {
				std::cout << ex.what() << std::endl;
			}
		}
		break;
		case (7):
		{
			int flag = 0;
			do {

				try {
					int step;
					Num num7("+ACDEFD");
					std::cout << std::endl;
					std::cout << num7;
					std::cout << std::endl;
					std::cout << "Enter step" << std::endl;
					std::cout << std::endl;
					std::cin >> step;
					std::cout << std::endl;
					num7.shiftLeft(step);
					flag = 1;
					std::cout << num7;
					std::cout << std::endl;

				}
				catch (const std::invalid_argument& ex) {
					std::cout << ex.what() << std::endl;
				}
			} while (!flag);
		}
		break;
		case (8):
		{
			int flag = 0;
			do {

				try {
					int step;
					std::cout << std::endl;
					Num num7("+EF12");
					std::cout << num7;
					std::cout << std::endl;
					std::cout << "Enter step" << std::endl;
					std::cin >> step;
					std::cout << std::endl;
					num7.shiftRight(step);
					flag = 1;
					std::cout << num7;
					std::cout << std::endl;
				}
				catch (const std::invalid_argument& ex) {
					std::cout << ex.what() << std::endl;
				}
			} while (!flag);
		}
		break;
		case (9):
		{
			int flag = 0;
			Num num;
			do {

				try {
					std::cout << "Enter hexadecimal number" << std::endl;
					std::string s;
					std::cin >> s;
					std::cout << std::endl;
					num.setNum(s);
					//y2 = &num2;
					flag = 1;
					std::cout << std::endl;
					std::cout << num;
					std::cout << std::endl;

				}
				catch (const std::exception& ex) {
					std::cout << ex.what() << std::endl;
				}
			} while (!flag);
			if (num.checkEven())
				std::cout << " number is even" << std::endl;
			else
				std::cout << " number is odd" << std::endl;
		}
		break;
		case (10):
		{
			Num num1;
			Num num2;

			int flag = 0;
			do {

				try {
					std::cout << "Create hexadecimal number" << std::endl;
					std::string s;
					std::cin >> s;
					num1.setNum(s);
					flag = 1;
					std::cout << num1;
					std::cout << std::endl;

				}
				catch (const std::exception& ex) {
					std::cout << ex.what() << std::endl;
				}
			} while (!flag);

			flag = 0;
			do {

				try {
					std::cout << "Create hexadecimal number" << std::endl;
					std::string s;
					std::cin >> s;
					num2.setNum(s);
					flag = 1;
					std::cout << num2;
					std::cout << std::endl;

				}
				catch (const std::exception& ex) {
					std::cout << ex.what() << std::endl;
				}
			} while (!flag);
			try {
				Num summa = num1 - num2;
				std::cout << summa << std::endl;
			}
			catch (const std::exception& ex) {
				std::cout << ex.what() << std::endl;
			}
		}

		break;
		default:
			choise = 0;
		}
	} while (choise != 0);
	return 1;
}
