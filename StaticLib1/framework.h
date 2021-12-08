#pragma once

#define WIN32_LEAN_AND_MEAN             // Исключите редко используемые компоненты из заголовков Windows
#include <iostream>
#include <cmath>
#include <string>
namespace Prog3 {
    class Num;
    std::ostream& operator <<(std::ostream& out, const Num& num);
    std::istream& operator >>(std::istream& in, Num& num);
    class Num {
    private:
        static const  int size = 33;
        int realSize;
        char* number = nullptr;

    public:
        Num(Num&& st) : number(st.number), realSize(st.realSize) {
            st.number = nullptr;
        }

        int getRealSize() { return realSize; }
        ~Num() { delete[] number; }

        Num() : realSize(2) {
            number = new char[realSize];
            number[0] = '0';
            number[1] = '0';
        }
        Num(int hex);
        Num(const Num& number) {
            this->realSize = number.realSize;
            if (this->number != nullptr)
                delete[] this->number;
            this->realSize = number.realSize;
            this->number = new char[this->realSize];
            for (int i = 0; i < realSize; i++) {
                this->number[i] = number.number[i];
            }
        }

        Num(std::string s);
        Num& operator = (const Num& number);
        friend std::ostream& operator <<(std::ostream& out, const Num& num);
        friend std::istream& operator >>(std::istream& in, Num& num);
        void setNum(std::string s);
        bool operator ==(const Num& num) const;
        int checkEven();
        Num operator +(const Num& num2);
        void shiftLeft(int step);
        void shiftRight(int step) const;
        Num operator -(const Num& num2);
        char* getNum()const {
            char* x = number;
            return x;
        }

    };
}
