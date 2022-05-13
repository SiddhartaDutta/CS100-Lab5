#include "gtest/gtest.h"

#include "HalfOPMock.hpp"
#include "NegativeOPMock.hpp"
#include "NineOPMock.hpp"
#include "ZeroOPMock.hpp"

#include "op_test.hpp"

#include "rand.hpp"
#include "mult.hpp"

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


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
