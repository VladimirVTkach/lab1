#include <gtest/gtest.h>
#include "tests_runner.h"

int run_all_tests() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}

