//
// Created by User on 03.11.2022.
//
#include <gtest/gtest.h>
#include "Life_Core.h"

int main(int argc, char *argv[]) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
