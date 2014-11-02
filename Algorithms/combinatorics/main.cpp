#include <gtest/gtest.h>
#include "HeavySet.h"

TEST( TestFactorail, normalInput ){
    EXPECT_EQ( 1, factorial(0) );
    EXPECT_EQ( 120, factorial(5) );
}

TEST( functionFTest, normalInput){
    EXPECT_EQ( 38760 , F(7,14) ); 
}

int main(int argc,char **argv){
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}

