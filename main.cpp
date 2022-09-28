//
// Created by User on 01.09.2022.
//
#include <iostream>
#include <ctime>
#include <cstddef> // size_t
#include "BigInt.hpp"
#include <gtest/gtest.h>

class TestBigInt : public ::testing::Test {
public:
    BigInt a;
    BigInt b;
    BigInt c;

    void SetUp(std::string s1, std::string s2, std::string s3) {
        BigInt copy_a(s1);
        BigInt copy_b(s2);
        BigInt copy_c(s3);
        a = copy_a;
        b = copy_b;
        c = copy_c;
    }
};

TEST_F(TestBigInt, test1) {
    SetUp("+200", "+2035", "-1234");
    EXPECT_FALSE(a == b);
    EXPECT_TRUE(a <= b);
    EXPECT_TRUE(a < b);
    EXPECT_FALSE(a >= b);
    EXPECT_FALSE(a > b);
    EXPECT_TRUE(a != b);
    EXPECT_TRUE(a+b > c);
    EXPECT_TRUE(b+c < b);
}
//test binary +
TEST_F(TestBigInt, test2) {
    SetUp("+42949672950", "+42949672950", "+85899345900");
    EXPECT_TRUE(a + b == c);
    EXPECT_TRUE(c - b == a);
}

TEST_F(TestBigInt, test3) {
    SetUp("+654", "+345", "+225630");
    EXPECT_TRUE(a * b == c);
    EXPECT_TRUE(c / b = a);
}

int main(int argc, char **argv) {

/*    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();*/
    //BigInt a("+42949672950");
    //std::cout<<a<<"\n";
    unsigned long long int n = static_cast<unsigned long long int>(UINT_MAX)*2;
    std::cout<<(static_cast<unsigned int>(n) == UINT_MAX);
    return 0;
}
