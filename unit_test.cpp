#include "gtest/gtest.h"

#include "HalfOPMock.hpp"
#include "NegativeOPMock.hpp"
#include "NineOPMock.hpp"
#include "ZeroOPMock.hpp"

#include "op_test.hpp"

#include "add.hpp"
#include "sub.hpp"
#include "pow.hpp"
#include "rand.hpp"
#include "mult.hpp"
#include "div.hpp"

TEST(AddTest,AddNegNums){
       Base* element1 = new NegativeOPMock();
       Base* element2 = new NegativeOPMock();
       Base* add = new Add(element1,element2);
       double result = add->evaluate();
       EXPECT_EQ(result,-1974.65);
}

TEST(AddTest,AddPosNums){
       Base* element1 = new NineOPMock();
       Base* element2 = new HalfOPMock();
       Base* add = new Add(element1,element2);
       double result = add->evaluate();
       EXPECT_EQ(result,9.5);
}

TEST(AddTest,AddWithZero){
       Base* element1 = new ZeroOPMock();
       Base* element2 = new HalfOPMock();
       Base* add = new Add(element1,element2);
       double result = add->evaluate();
       EXPECT_EQ(result,0.5);

}

TEST(SubTest,SubSameNegNums){
       Base* element1 = new NegativeOPMock();
       Base* element2 = new NegativeOPMock();
       Base* subtract = new Sub(element1,element2);
       double result = subtract->evaluate();
       EXPECT_EQ(result,0);
}

TEST(SubTest,SubPosNums){
       Base* element1 = new NineOPMock();
       Base* element2 = new HalfOPMock();
       Base* subtract = new Sub(element1,element2);
       double result = subtract->evaluate();
       EXPECT_EQ(result,8.5);
}

TEST(SubTest,SubWithZero){
       Base* element1 = new ZeroOPMock();
       Base* element2 = new HalfOPMock();
       Base* subtract = new Sub(element1,element2);
       double result = subtract->evaluate();
       EXPECT_EQ(result,-0.5);

}

TEST(PowTest,RaisedBySameNum){
       Base* bas = new NineOPMock();
       Base* power = new NineOPMock();
       Base* exponent = new Pow(bas,power);
       double result = exponent->evaluate();
       EXPECT_EQ(result,387420489);
}

TEST(PowTest,RaisedByDifNum){
       Base* bas = new NineOPMock();
       Base* power = new HalfOPMock();
       Base* exponent = new Pow(bas,power);
       double result = exponent->evaluate();
       EXPECT_EQ(result,3);
}

TEST(PowTest,RaisedByZero){
       Base* bas = new HalfOPMock();
       Base* power = new ZeroOPMock();
       Base* exponent = new Pow(bas,power);
       double result = exponent->evaluate();
       EXPECT_EQ(result,1);

}

TEST(RandTest, RandEvaluate){
	Rand* test = new Rand();
	EXPECT_TRUE((test->evaluate() >= 0) && (test->evaluate() <= 99));
}

TEST(MultTest,MultiplyingBySameNum){
       Base* element1 = new HalfOPMock();
       Base* element2 = new HalfOPMock();
       Base* multiply = new Mult(element1,element2);
       double result = multiply->evaluate();
       EXPECT_EQ(result,0.25);
}

TEST(MultTest,MultiplyingByDifNum){
       Base* element1 = new HalfOPMock();
       Base* element2 = new NineOPMock();
       Base* multiply = new Mult(element1,element2);
       double result = multiply->evaluate();
       EXPECT_EQ(result,4.5);
}

TEST(MultTest,MultiplyingWithZero){
       Base* element1 = new ZeroOPMock();
       Base* element2 = new NineOPMock();
       Base* multiply = new Mult(element1,element2);
       double result = multiply->evaluate();
       EXPECT_EQ(result,0);

}

TEST(DivideTest,DividingBySameNum){
       Base* dividend = new NegativeOPMock();
       Base* divisor = new NegativeOPMock();
       Base* divide = new Div(dividend,divisor);
       double result = divide->evaluate();
       EXPECT_EQ(result,1);
}

TEST(DivideTest,DividingByDifNum){
       Base* dividend = new HalfOPMock();
       Base* divisor = new NineOPMock();
       Base* divide = new Div(dividend,divisor);
       double result = divide->evaluate();
       EXPECT_EQ(result,18);
}

TEST(DivideTest,DividingWithZero){
       Base* dividend = new NineOPMock();
       Base* divisor = new ZeroOPMock();
       Base* divide = new Div(dividend,divisor);
       double result = divide->evaluate();
       EXPECT_EQ(result,0);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}