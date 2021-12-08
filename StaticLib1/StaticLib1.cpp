// StaticLib1.cpp : Определяет функции для статической библиотеки.
//

#include "pch.h"
#include "framework.h"

#include <iostream>
#include <strstream>
#include<string>
#include <cmath>
#define _SILENCE_TR1_NAMESPACE_DEPRECATION_WARNING
namespace Prog3 {
	std::ostream& Prog3::operator <<(std::ostream& out, const Num& num)
	{

		for (int i = 0; i <= num.realSize - 1; i++)
			out << num.number[i];
		out;
		return out;
	}
	char invert_int(char number);
	char gets_char(int number) {
		char hex = '0';
		if (number <= 9) {
			hex = '0' + number;
			return hex;
		}
		else
			hex = '7' + number;
		return hex;
	}

	Num::Num(int hex) {
		int count = 0;
		int tmp = hex;
		int flag = 1;
		if (hex < 0) {
			tmp = (-1) * hex;
			hex = (-1) * hex;
			flag = 0;
		}
		while (hex > 0) {
			hex /= 16;
			count++;
		}
		number = new char[count + 1];
		for (int i = count + 1; i--; i > 1) {
			number[i] = gets_char(tmp % 16);
			tmp /= 16;
		}
		realSize = count + 1;
		flag == 1 ? number[0] = '0' : number[0] = 'F';
	}

	Num::Num(std::string s) {
		realSize = s.length();
		if (s.length() == 0)
			throw std::invalid_argument("you did not enter a number");
		number = new char[realSize]; /// вот здесь может быть bad_alloc
		s[0] == '+' ? number[0] = '0' : number[0] = 'F';
		for (int i = 1; i < realSize; i++) {
			if (('0' <= s[i] && s[i] <= '9' || 'A' <= s[i] && s[i] <= 'F')) {
				number[i] = s[i];
			}
			else
				throw std::invalid_argument("It isn't hexademical number");
		}
	}

	std::istream& Prog3::operator >>(std::istream& in, Num& num) {
		std::string s;
		in >> s;
		num.setNum(s);
		return in;
	}

	/*Num& Num::operator = (const Num& number) {
		this->realSize = number.realSize;
		if (this->number != nullptr)
			delete[] this->number;
		this->realSize = number.realSize;
		this->number = new char[this->realSize];
		for (int i = 0; i < realSize; i++) {
			this->number[i] = number.number[i];
		}
		return *this;
	}*/




	Num& Num::operator = (const Num& number) {
		if (this == &number)
			return *this;
		char* tmp = new char[number.realSize];
		for (int i = 0; i < number.realSize; i++) {
			tmp[i] = number.number[i];
		}
		delete[] this->number;
		this->realSize = number.realSize;
		this->number = tmp;
		return *this;
	}

	void Num::setNum(std::string s) {
		realSize = s.length();
		if (s.length() == 0)
			throw std::invalid_argument("you did not enter a number");
		delete[] number;
		number = new char[realSize];
		if (s[0] == '-' || s[0] == '+') {
			if (s[0] == '+')
				number[0] = '0';
			else
				number[0] = 'F';
		}
		else
			throw std::invalid_argument("It isn't hexademical number");

		for (int i = 1; i < realSize; i++) {
			if (('0' <= s[i] && s[i] <= '9' || 'A' <= s[i] && s[i] <= 'F')) {
				number[i] = s[i];
			}
			else
				throw std::invalid_argument("It isn't hexademical number");
		}

	}

	void Num::shiftLeft(int step) {
		if (step < 0)
			throw std::invalid_argument("Step can't be < 0");
		char* tmp = new char[realSize + step];
		for (int i = 0; i < realSize; i++)
			tmp[i] = number[i];
		for (int i = realSize; i < realSize + step; i++) {
			tmp[i] = '0';
		}
		delete[] number;
		number = tmp;
		realSize += step;
	}

	void Num::shiftRight(int step)const {
		if (step < 0)
			throw std::invalid_argument("Step can't be < 0");

		for (int i = realSize - 1; i > step; i--) {
			number[i] = number[i - step];

		}
		for (int k = 1; k <= step; k++) {
			number[k] = '0';
		}
	}
	bool Num::operator ==(const Num& num) const {
		if (this->realSize != num.realSize)
			return false;
		for (int i = 0; i < realSize; i++) {
			if (this->number[i] != num.number[i])
				return false;
		}
		return true;
	}
	int Num::checkEven() {

		int last_digit = number[realSize - 1];

		if (last_digit % 2 == 0) {
			if (last_digit <= 57)
				return 1;
			else
				return 0;
		}
		else {
			if (last_digit <= 57)
				return 0;
			else
				return 1;

		}
	}

	int gets_int(char number) { // преобразование шестнадцатиричного числа чара в инт.
		int digit = number;
		if ((int)number <= 57)
			return digit - '0';
		else
			return digit - '7';
	}



	char invert_int(char number) {
		int digit1 = gets_int(number);
		char hex = '0';
		int digit = 15 - digit1;
		if (digit <= 9) {
			hex = '0' + digit;
			return hex;
		}
		else
			hex = '7' + digit;
		return hex;


	}

	char summaHex(char number, int& flag) {
		int digit1 = gets_int(number);
		char hex = '0';
		int digit = digit1 + flag;
		if (digit >= 16) {
			digit -= 16;
			flag = 1;
			if (digit <= 9) {
				hex = '0' + digit;
				flag = 1;
				return hex;
			}
			else
				hex = '7' + digit;
			flag = 1;
			return hex;
		}
		else {
			flag = 0;
			if (digit <= 9) {
				hex = '0' + digit;
				return hex;
			}
			else
				hex = '7' + digit;
			return hex;

		}
	}

	char summ_for_2_hex(char number1, char number2, int& flag) {
		int digit1 = gets_int(number1);
		int digit2 = gets_int(number2);
		char hex = '0';
		int digit = digit1 + digit2 + flag;
		if (digit >= 16) {
			digit -= 16;
			flag = 1;
			if (digit <= 9) {
				hex = '0' + digit;
				flag = 1;
				return hex;
			}
			else
				hex = '7' + digit;
			flag = 1;
			return hex;
		}
		else {
			flag = 0;
			if (digit <= 9) {
				hex = '0' + digit;
				return hex;
			}
			else
				hex = '7' + digit;
			return hex;

		}
	}

	char* additional(char* number, int realSize) {
		number[0] = 'F';
		for (int i = 1; i < realSize; i++) {
			number[i] = invert_int(number[i]);
		}
		int flag = 1;
		for (int i = realSize - 1; i >= 1; i--) {  // добавляю единицу к инвертированному числу
			number[i] = summaHex(number[i], flag);
		}
		return number;

	}

	char* deleteZeroDigits(char* number, int& realSize) {
		int countZeroDigits = realSize;
		for (int i = 1; i <= realSize; i++) {
			if (number[i] != '0')
				break;
			if (number[i] != '0')
				realSize--;
		}
		if (realSize == 1) {
			char* newNumber = new char[2];
			newNumber[0] = '0';
			newNumber[1] = '0';
		}
		char* newNumber = new char[realSize];

		for (int i = 0; i < realSize; i++)
			newNumber[i] = number[i + countZeroDigits];
		delete[] number;
		return newNumber;


	}

	Num Num::operator+(const Num& num2) { // если число положительное оставляем его в прямом коде, если отрицательное, сначало переводим в обратный
		int maxSize;
		this->realSize <= num2.realSize ? maxSize = num2.realSize : maxSize = this->realSize;
		Num tmp;
		char* number1 = nullptr;
		char* number2 = nullptr;

		number1 = new char[maxSize];

		try {
			number2 = new char[maxSize];
		}
		catch (const std::bad_alloc&) {
			delete[] number1;
			throw std::bad_alloc();
		}
		int flag = 1;
		number1[0] = '0';
		if (this->realSize != maxSize) {
			for (int i = 1; i <= maxSize - this->realSize; i++)
				number1[i] = '0';
		}
		for (int l = 0; l < this->realSize; l++) {
			number1[l + maxSize - this->realSize] = this->number[l];
		}
		if (this->number[0] == 'F')
			additional(number1, this->realSize);
		flag = 1;
		number2[0] = '0';
		for (int l = maxSize - 1; l > 0; l--) {
			number2[l] = num2.number[l];
		}
		if (num2.realSize != maxSize) {
			for (int i = 1; i < maxSize - num2.realSize; i++)
				number1[i] = '0';
		}
		if (num2.number[0] == 'F')
			additional(number2, num2.realSize);
		char* TMP = nullptr;
		TMP = new char[maxSize + 1];
		tmp.realSize = maxSize + 1;
		flag = 0;
		for (int i = maxSize - 1; i >= 0; i--) {
			TMP[i + 1] = summ_for_2_hex(number1[i], number2[i], flag);

		}
		if (flag == 1)
			TMP[1] = '1';
		else
			TMP[1] = '0';
		flag = 0;
		if (TMP[0] == 'F') {
			TMP = additional(tmp.number, tmp.realSize);
		}
		int totalZeros = 0;
		for (int i = 0; i < tmp.realSize - 1; i++) { /// check
			if (TMP[i] == 'F' || (TMP[i] == '0' && TMP[i + 1] != '0')) {
				break;
			}
			else
				totalZeros++;
		}
		tmp.realSize -= totalZeros;
		delete[] tmp.number;
		tmp.number = nullptr;
		try {
			tmp.number = new char[tmp.realSize];;
		}
		catch (const std::bad_alloc&) {
			delete[] number1;
			delete[] number2;
			throw std::bad_alloc();
		}

		for (int i = totalZeros; i < tmp.realSize + totalZeros; i++) {
			tmp.number[i - totalZeros] = TMP[i];
		}
		delete[] TMP;
		delete[] number1;
		delete[] number2;
		//std::cout << tmp;
		return tmp;
	}


	Num Num::operator -(const Num& num2) {
		int maxSize;
		this->realSize <= num2.realSize ? maxSize = num2.realSize : maxSize = this->realSize;
		Num tmp;
		char* number1 = nullptr;
		char* number2 = nullptr;
		try {
			number1 = new char[maxSize];
		}
		catch (const std::bad_alloc&) {
			throw std::bad_alloc();
		}
		try {
			number2 = new char[maxSize];
		}
		catch (const std::bad_alloc&) {
			delete[] number1;
			throw std::bad_alloc();
		}
		int flag = 1;
		number1[0] = '0';
		if (this->realSize != maxSize) {
			for (int i = 1; i <= maxSize - this->realSize; i++)
				number1[i] = '0';
		}
		for (int l = 0; l < this->realSize; l++) {
			number1[l + maxSize - this->realSize] = this->number[l];
		}
		if (this->number[0] == 'F')
			additional(number1, this->realSize);
		flag = 1;
		number2[0] = '0';
		for (int l = maxSize - 1; l > 0; l--) {
			number2[l] = num2.number[l];
		}
		if (num2.realSize != maxSize) {
			for (int i = 1; i < maxSize - num2.realSize; i++)
				number1[i] = '0';
		}
		if (num2.number[0] == '0')
			additional(number2, num2.realSize);

		char* TMP = nullptr;
		try {
			TMP = new char[maxSize];
		}
		catch (const std::bad_alloc&) {
			delete[] number1;
			delete[] number2;
			throw std::bad_alloc();
		}

		tmp.realSize = maxSize;
		flag = 0;
		for (int i = maxSize - 1; i >= 0; i--) {
			TMP[i] = summ_for_2_hex(number1[i], number2[i], flag);

		}
		char* OverFlow = nullptr;
		if (flag == 1) {
			maxSize += 1;

			try {
				OverFlow = new char[maxSize];
			}
			catch (const std::bad_alloc&) {
				delete[] number1;
				delete[] number2;
				delete[] TMP;
				throw std::bad_alloc();
			}
			for (int i = 1; i < maxSize; i++) {
				OverFlow[i + 1] = TMP[i];
			}
			TMP[0] == '0' ? OverFlow[1] = '1' : OverFlow[1] = 'E';
			OverFlow[0] = TMP[0];
			if (number1[0] == 'F' && number2[0] == 'F')
				OverFlow[0] = 'F';
		}
		else {
			try {
				OverFlow = new char[maxSize];
			}
			catch (const std::bad_alloc&) {
				delete[] number1;
				delete[] number2;
				delete[] TMP;
				throw std::bad_alloc();
			}
			for (int i = 0; i < maxSize; i++) {
				OverFlow[i] = TMP[i];
			}
		}
		flag = 0;

		if (OverFlow[0] == 'F') {
			OverFlow = additional(OverFlow, maxSize);
		}
		flag = 0;

		int totalZeros = 0;
		for (int i = 1; i < tmp.realSize - 1; i++) { /// check
			if (OverFlow[i] != '0') {
				break;
			}
			else
				totalZeros++;
		}
		tmp.realSize -= totalZeros;
		delete[] tmp.number;
		tmp.number = nullptr;
		try {
			tmp.number = new char[tmp.realSize];
		}
		catch (const std::bad_alloc&) {
			delete[] number1;
			delete[] number2;
			delete[] TMP;
			delete[] OverFlow;
			throw std::bad_alloc();
		}
		for (int i = totalZeros; i < tmp.realSize + totalZeros; i++) {
			tmp.number[i - totalZeros] = OverFlow[i];
		}
		tmp.number[0] = OverFlow[0];
		delete[] TMP;
		delete[] number1;
		delete[] number2;
		delete[] OverFlow;
		//std::cout << tmp;
		return tmp;
	}
}
