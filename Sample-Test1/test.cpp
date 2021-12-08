#include "pch.h"

#include <gtest/gtest.h>
//#include "D:\laba3Dinamic\number33\number33.h"
#include "../StaticLib1/framework.h"
#include <string>
#include <sstream>
#include <iostream>
//#include <iostream>
using namespace Prog3;



TEST(NumConstructor, Constructors)
{
    Prog3::Num L;
    char* x = L.getNum();
    std::string s = "00";
    for (int i = 0; i < L.getRealSize(); i++) {
        ASSERT_EQ(*x, s[i]);
        x++;
    }
    s = "-ADEF";
    Prog3::Num num1(s);
    char* y = num1.getNum();
    s = "FADEF";
    for (int i = 0; i < num1.getRealSize(); i++) {
        ASSERT_EQ(*y, s[i]);
        y++;
    }

    std::string f = "+13EDC";
    L.setNum(f);
    s = "013EDC";
    x = L.getNum();
    for (int i = 0; i < L.getRealSize(); i++) {
        ASSERT_EQ(*x, s[i]);
        x++;
    }
    f = "-13EDC";
    L.setNum(f);
    s = "F13EDC";
    x = L.getNum();
    for (int i = 0; i < L.getRealSize(); i++) {
        ASSERT_EQ(*x, s[i]);
        x++;
    }

    s = "+ADEF";
    Prog3::Num num2(s);
    y = num2.getNum();
    s = "0ADEF";

    for (int i = 0; i < num2.getRealSize(); i++) {
        ASSERT_EQ(*y, s[i]);
        y++;
    }
}


TEST(Operations, summ)
{
    std::string s = "+ADEF";
    std::string q;
    Prog3::Num num1(s);
    s = "+124AF";
    Prog3::Num num2(s);
    Prog3::Num y = num1 + num2;
    s = "01D29E";
    q = y.getNum();
    for (int i = 0; i < y.getRealSize(); i++) {
        ASSERT_EQ(q[i], s[i]);
    }
    num2.setNum("-124AF");

    y = num1 + num2;
    q = y.getNum();
    s = "F76C0";
    for (int i = 0; i < y.getRealSize(); i++) {
        ASSERT_EQ(q[i], s[i]);
    }

    num1.setNum("-AD452");
    y = num1 + num2;
    s = "FBF901";
    q = y.getNum();
    for (int i = 0; i < y.getRealSize(); i++) {
        // ASSERT_EQ(q[i], s[i]);
    }
    num2.setNum("+ACEFD");
    y = num1 + num2;
    q = y.getNum();
    s = "F555";

    for (int i = 0; i < y.getRealSize(); i++) {
        // ASSERT_EQ(q[i], s[i]);
    }

    num2.setNum("+FCEFD");
    y = num1 + num2;
    q = y.getNum();
    s = "04FAAB";
    for (int i = 0; i < y.getRealSize(); i++) {
        //  ASSERT_EQ(q[i], s[i]);
    }


}

TEST(equal, method) {

    Prog3::Num num1("+DF34");
    Prog3::Num num2("+DF34");
    bool x = (num2 == num1);
    ASSERT_EQ(true, x);
    num2.setNum("+ADEC");
    x = (num2 == num1);
    ASSERT_EQ(false, x);

}

TEST(substraction, Methods)
{
    std::string s = "+ADEF";
    std::string c;
    Prog3::Num num1(s);
    s = "+124AF";
    Prog3::Num num2(s);
    Prog3::Num y = num1 - num2;
    s = "F76C0";
    c = y.getNum();

    for (int i = 0; i < y.getRealSize(); i++) {
        ASSERT_EQ(c[i], s[i]);
    }
    num2.setNum("-124AF");

    y = num1 - num2;
    c = y.getNum();
    s = "01D29E";

    for (int i = 0; i < y.getRealSize(); i++) {
        ASSERT_EQ(c[i], s[i]);
    }

    num1.setNum("-AD452");
    y = num1 - num2;
    c = y.getNum();

    s = "F9AFA3";

    for (int i = 0; i < y.getRealSize(); i++) {
        ASSERT_EQ(c[i], s[i]);
    }

    num2.setNum("+ACEFD");
    y = num1 - num2;
    c = y.getNum();
    s = "F15A34F";


    for (int i = 0; i < y.getRealSize(); i++) {
        ASSERT_EQ(c[i], s[i]);
    }

    num2.setNum("+FCEFD");
    y = num1 - num2;
    c = y.getNum();
    s = "F1AA34F";

    for (int i = 0; i < y.getRealSize(); i++) {
        ASSERT_EQ(c[i], s[i]);
    }
}


TEST(shift, Methods)
{
    std::string s = "+ADEF";
    Prog3::Num num1(s);
    num1.shiftLeft(0);
    char* y = num1.getNum();
    s = "0ADEF";
    for (int i = 0; i < num1.getRealSize(); i++) {
        ASSERT_EQ(y[i], s[i]);
    }

    num1.shiftRight(0);
    for (int i = 0; i < num1.getRealSize(); i++) {
        ASSERT_EQ(y[i], s[i]);
    }

    num1.shiftLeft(2);
    y = num1.getNum();
    s = "0ADEF00";
    for (int i = 0; i < num1.getRealSize(); i++) {
        ASSERT_EQ(y[i], s[i]);
    }
    num1.shiftLeft(10);
    y = num1.getNum();
    s = "0ADEF000000000000";
    for (int i = 0; i < num1.getRealSize(); i++) {
        ASSERT_EQ(y[i], s[i]);
    }
    s = "+ADEF";
    num1.setNum(s);
    num1.shiftLeft(2);
    num1.shiftRight(2);
    s = "000ADEF";
    y = num1.getNum();
    for (int i = 0; i < num1.getRealSize(); i++) {
        ASSERT_EQ(y[i], s[i]);
    }

}

TEST(even, Methods) {
    std::string s = "+ADEF";
    Prog3::Num num1(s);
    int x = num1.checkEven();
    ASSERT_EQ(x, 0);
    num1.setNum("+ADEE");
    x = num1.checkEven();
    ASSERT_EQ(x, 1);
    num1.setNum("+0000");
    x = num1.checkEven();
    ASSERT_EQ(x, 1);

    num1.setNum("-ADEE");
    x = num1.checkEven();
    ASSERT_EQ(x, 1);

    num1.setNum("-ADEF");
    x = num1.checkEven();
    ASSERT_EQ(x, 0);

}


TEST(compare, Methods) {
    std::string s = "+ADEF";
    Prog3::Num num1(s);
    s = "+124AF";
    Prog3::Num num2(s);
    bool x = (num1 == num2);
    ASSERT_EQ(x, false);

    num2.setNum("-124AF");
    x = (num1 == num2);
    ASSERT_EQ(x, false);

    num1.setNum("-ADEF");
    x = (num1 == num2);
    ASSERT_EQ(x, false);

    num2.setNum("-ADEF");
    x = (num1 == num2);
    ASSERT_EQ(x, true);

    num2.setNum("+CDA3");
    num1.setNum("+CDA3");
    x = (num1 == num2);
    ASSERT_EQ(x, true);
}

TEST(exceptions, allMethods) {
    std::string s = "+AD4454545454545454545455F";
    Prog3::Num num1(s);
    ASSERT_ANY_THROW(Prog3::Num("asd"));
    ASSERT_ANY_THROW(Prog3::Num(""));
    ASSERT_ANY_THROW(num1.setNum(""));
    ASSERT_ANY_THROW(num1.setNum("asd"));
    ASSERT_ANY_THROW(num1.shiftLeft(-1));
    ASSERT_ANY_THROW(num1.shiftRight(-1));

}


int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

