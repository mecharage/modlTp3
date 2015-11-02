#include <gtest/gtest.h>
#include "test_Echantillon.inl"
#include "test_Histogramme.inl"

int main(int argc,char * argv[]) {
 ::testing::InitGoogleTest(&argc,argv);
 return RUN_ALL_TESTS();
}
