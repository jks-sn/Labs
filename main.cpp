//
// Created by User on 01.09.2022.
//
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
    SetUp("+58767655", "-24387656565", "-1433205387270405075");
    EXPECT_TRUE(a * b == c);
    EXPECT_TRUE(c / a == b);
}

TEST_F(TestBigInt, test4) {
    SetUp("+42949672950", "+42949672950", "+85899345900");
    EXPECT_TRUE(a + b == c);
    EXPECT_TRUE(c - b == a);
}

TEST_F(TestBigInt, test5) {
    SetUp("+667877578434874379", "+667877578434874378", "+667877578434874380");
    EXPECT_TRUE(++b == a);
    EXPECT_TRUE(a++ == b);
    EXPECT_TRUE(--c == b);
    EXPECT_TRUE(c-- == b);
}

TEST_F(TestBigInt, test6) {
    SetUp("+59734578345435543", "+59734578345435543", "-54654535345435454");
    EXPECT_TRUE((BigInt(std::string(a)) == b));
    EXPECT_TRUE(BigInt(std::string(c)).sign);
}

TEST_F(TestBigInt, test7) {
    SetUp("+854595589459345983593485348534", "+345678976678", "-43");
    EXPECT_TRUE(c % BigInt(5) == BigInt(3));
    EXPECT_TRUE(a % b == BigInt("+26080687428"));

}

TEST_F(TestBigInt, test8) {
    SetUp("+876567898765678987656789", "-876567898765678987656789", "+5443987655678987656789");
    EXPECT_TRUE(a == (~(b) + BigInt(1)));
    EXPECT_TRUE(~(~(c)) == BigInt("+5443987655678987656789"));
}

TEST_F(TestBigInt, test9) {
    SetUp("+98765434567898765678", "+765678765678987436", "+97999862478748127682");
    EXPECT_TRUE((a ^ b) == c);
}

TEST_F(TestBigInt, test10) {
    SetUp("+1236528748514521486", "-99845651235598742014852", "-11872299507910396418");
    EXPECT_TRUE((a | b) == c);
}

TEST_F(TestBigInt, test11) {
    SetUp("+8546654648484840", "+7878798461236458", "+7420746011853032");
    EXPECT_TRUE((a & b) == c);
}


int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    return 0;
}
