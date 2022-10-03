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
    SetUp("+20045678", "+203545678", "-123445678");
    EXPECT_FALSE(a == b);
    EXPECT_TRUE(a <= b);
    EXPECT_TRUE(a < b);
    EXPECT_FALSE(a >= b);
    EXPECT_FALSE(a > b);
    EXPECT_TRUE(a != b);
    EXPECT_TRUE(a + b > c);
    EXPECT_TRUE(b + c < b);
}

TEST_F(TestBigInt, test2) {
    SetUp("+500", "+2000", "+4");
    EXPECT_TRUE(a * c == b);
    EXPECT_TRUE(b / a == c);
}
TEST_F(TestBigInt, test3) {
    SetUp("-5000000", "+200000000000", "-40000");
    EXPECT_TRUE(a * c == b);
    EXPECT_TRUE(b / a == c);
    EXPECT_TRUE(b * c < a);
}
//test binary + with big numbers
TEST_F(TestBigInt, test4) {
    SetUp("+42949672950", "+42949672950", "+85899345900");
    EXPECT_TRUE(a + b == c);
    EXPECT_TRUE(c - b == a);
}
TEST_F(TestBigInt, test5){
    SetUp("+67", "+66", "+68");
    EXPECT_TRUE(++b == a);
    EXPECT_TRUE(a++ == b);
    EXPECT_TRUE(--c == b);
    EXPECT_TRUE(c-- == b);
}
int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    return 0;
}
