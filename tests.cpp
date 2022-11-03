//
// Created by User on 29.10.2022.
//
#include <gtest/gtest.h>
#include "Life_Core.h"
struct ParamList1
{
    std::vector<bool> a1;
    std::vector <bool> a2;
    int a3;
    int a4;
    int a5;
    int a6;
    //std::string s;
};
struct ParamList2
{
    std::vector<bool> univercity_test;
    std::vector <unsigned char> answer;
    int weight;
    int height;
    //std::string s;
};
struct ParamList3
{
    std::array<bool,9> when_survival_;
    std::array<bool,9> when_birth_;
    std::vector<bool> univercity_test;
    std::vector<bool> answer;
    int weight;
    int height;

};
class ParamTestLife_at : public ::testing::TestWithParam<ParamList1> {
};
class ParamTestLife_CountNeigbours : public ::testing::TestWithParam<ParamList2> {
};
class ParamTestLife_RecheckLife : public ::testing::TestWithParam<ParamList3>{
};
TEST_P(ParamTestLife_at, test1) {
    std::vector<bool> a1 = GetParam().a1;
    std::vector<bool> a2 = GetParam().a2;
    Life example;
    example.univercity = a1;
    int a3 = GetParam().a3;
    int a4 = GetParam().a4;
    example.weight_ = a3;
    example.height_ = a4;
    int a5 = GetParam().a5;
    int a6 = GetParam().a6;
    example.at(a5,a6);
    EXPECT_TRUE(example.univercity == a2);
    //std::string s = GetParam().s;
    //std::cout<<s<<std::endl;
}
TEST_P(ParamTestLife_CountNeigbours, test2) {
    std::vector<bool> univercity_test = GetParam().univercity_test;
    std::vector<unsigned char> answer = GetParam().answer;
    Life example;
    example.univercity = univercity_test;
    int weight = GetParam().weight;
    int height = GetParam().height;
    example.weight_ = weight;
    example.height_ = height;
    example.neighbours.resize(example.weight_ * example.height_);
    std::fill(example.neighbours.begin(), example.neighbours.end(), 0);
    for(size_t i = 0; i != weight*height;++i)
        example.CountNeigbours(i);
    EXPECT_TRUE(example.neighbours == answer);
    //std::string s = GetParam().s;
    //std::cout<<s<<std::endl;
}
TEST_P(ParamTestLife_RecheckLife, test3)
{
    std::vector<bool> answer = GetParam().answer;
    Life example;
    example.when_survival = GetParam().when_survival_;
    example.when_birth = GetParam().when_birth_;
    example.univercity = GetParam().univercity_test;
    example.weight_ = GetParam().weight;
    example.height_ = GetParam().height;
    example.neighbours.resize(example.weight_ * example.height_);
    std::fill(example.neighbours.begin(), example.neighbours.end(), 0);
    example.RecountNeigbours();
    example.RecheckLife();
    EXPECT_TRUE(example.univercity == answer);
}
INSTANTIATE_TEST_CASE_P(ParamTestLife_at,ParamTestLife_at,testing::Values(ParamList1{{false,false,false,false,false,false,false,false,false},{false,true,false,false,false,false,false,false,false},3,3,2,1,/*"First test complete"*/},ParamList1{{false,true,true,false,false,false,false,false,false},{false,true,true,false,false,false,false,true,false},3,3,2,3/*"Second test complete"*/},ParamList1{{false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false,true},3,3,3,3},ParamList1{{false,false,false,false,false,false,false,false,false},{true,false,false,false,false,false,false,false,false},3,3,1,1}));
INSTANTIATE_TEST_CASE_P(ParamTestLife_CountNeigbours,ParamTestLife_CountNeigbours,testing::Values(ParamList2{{false,false,false,false,true,false,false,false,false},{1,1,1,1,0,1,1,1,1},3,3,/*"First test complete"*/},ParamList2{{true,false,true,false,true,false,true,false,true},{4,5,4,5,4,5,4,5,4},3,3}));
INSTANTIATE_TEST_CASE_P(ParamTestLife_RecheckLife,ParamTestLife_RecheckLife,testing::Values(ParamList3{{false,false,false,false,false,false,false,false,false},{false,false,false,false,false,false,false,false, false},{true,true,true,true,true,true,true,true,true},{false,false,false,false,false,false,false,false,false},3,3}));
