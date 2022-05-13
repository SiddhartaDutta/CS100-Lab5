#include "gtest/gtest.h"

#include "HalfOPMock.hpp"
#include "NegativeOPMock.hpp"
#include "NineOPMock.hpp"
#include "ZeroOPMock.hpp"

#include "op_test.hpp"

#include "add.hpp"

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


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


