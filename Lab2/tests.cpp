//
// Created by User on 29.10.2022.
//
#include <gtest/gtest.h>
#include "Life_Core.h"

using namespace life;
struct ParamList1 {
    std::vector<bool> a1;
    std::vector<bool> a2;
    int a3;
    int a4;
    int a5;
    int a6;
    //std::string s;
};
struct ParamList2 {
    std::vector<bool> univercity_test;
    std::vector<unsigned char> answer;
    int weight;
    int height;
    //std::string s;
};
struct ParamList3 {
    std::array<bool, 9> when_survival_;
    std::array<bool, 9> when_birth_;
    std::vector<bool> univercity_test;
    std::vector<bool> answer;
    int weight;
    int height;

};

class ParamTestLife_at : public ::testing::TestWithParam<ParamList1> {
};

class ParamTestLife_CountNeigbours : public ::testing::TestWithParam<ParamList2> {
};

class ParamTestLife_RecheckLife : public ::testing::TestWithParam<ParamList3> {
};

TEST_P(ParamTestLife_at, test1) {
    std::vector<bool> a1 = GetParam().a1;
    std::stringstream a1_string;
    std::string a1_str;
    std::string a2_str;
    std::vector<bool> a2 = GetParam().a2;
    std::stringstream a2_string;
    for (const auto &i: a2)
        a2_string << i;
    int a3 = GetParam().a3;
    int a4 = GetParam().a4;
    Life example(a1, a3, a4);
    int a5 = GetParam().a5;
    int a6 = GetParam().a6;
    example.at(a5, a6);
    example.PrintBoard(a1_string);
    a1_string >> a1_str;
    a2_string >> a2_str;
    EXPECT_TRUE(a1_str == a2_str);
    //std::string s = GetParam().s;
    //std::cout<<s<<std::endl;
}

TEST_P(ParamTestLife_CountNeigbours, test2) {
    std::vector<bool> univercity_test = GetParam().univercity_test;
    std::vector<unsigned char> answer = GetParam().answer;
    std::string neigbours_test_str;
    std::string answer_str;
    std::stringstream neigbours_test_string;
    std::stringstream answer_string;
    int weight = GetParam().weight;
    int height = GetParam().height;
    Life example(univercity_test, weight, height);
    for (size_t i = 0; i != weight * height; ++i)
        example.CountNeigbours(i);
    example.getNeighbours(neigbours_test_string);
    for (const auto &i: answer)
        answer_string << i;
    answer_string >> answer_str;
    neigbours_test_string >> neigbours_test_str;
    EXPECT_TRUE(neigbours_test_str == answer_str);
    //std::string s = GetParam().s;
    //std::cout<<s<<std::endl;
}

TEST_P(ParamTestLife_RecheckLife, test3) {
    std::vector<bool> answer = GetParam().answer;
    std::stringstream answer_string;
    std::stringstream univercity_test_string;
    std::string answer_str;
    std::string univercity_test_str;
    Life example(GetParam().univercity_test, GetParam().when_survival_, GetParam().when_birth_, GetParam().weight,
                 GetParam().height);
    example.RecountNeigbours();
    example.RecheckLife();
    example.PrintBoard(univercity_test_string);
    for (const auto &i: answer)
        answer_string << i;
    univercity_test_string >> univercity_test_str;
    answer_string >> answer_str;
    EXPECT_TRUE(answer_str == univercity_test_str);
}

INSTANTIATE_TEST_CASE_P

(ParamTestLife_at, ParamTestLife_at, testing::Values(
        ParamList1{{false, false, false, false, false, false, false, false, false},
                   {false, true, false, false, false, false, false, false, false}, 3, 3, 2,
                   1,/*"First test complete"*/},
        ParamList1{{false, true, true, false, false, false, false, false, false},
                   {false, true, true, false, false, false, false, true, false}, 3, 3, 2, 3/*"Second test complete"*/},
        ParamList1{{false, false, false, false, false, false, false, false, false},
                   {false, false, false, false, false, false, false, false, true}, 3, 3, 3, 3},
        ParamList1{{false, false, false, false, false, false, false, false, false},
                   {true, false, false, false, false, false, false, false, false}, 3, 3, 1, 1}));
INSTANTIATE_TEST_CASE_P

(ParamTestLife_CountNeigbours, ParamTestLife_CountNeigbours, testing::Values(
        ParamList2{{false, false, false, false, true, false, false, false, false}, {1, 1, 1, 1, 0, 1, 1, 1, 1}, 3,
                   3,/*"First test complete"*/},
        ParamList2{{true, false, true, false, true, false, true, false, true}, {4, 5, 4, 5, 4, 5, 4, 5, 4}, 3, 3}));
INSTANTIATE_TEST_CASE_P

(ParamTestLife_RecheckLife, ParamTestLife_RecheckLife, testing::Values(
        ParamList3{{false, false, false, false, false, false, false, false, false},
                   {false, false, false, false, false, false, false, false, false},
                   {true, true, true, true, true, true, true, true, true},
                   {false, false, false, false, false, false, false, false, false}, 3, 3}));
