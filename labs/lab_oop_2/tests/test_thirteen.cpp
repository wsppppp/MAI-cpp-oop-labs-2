#include <gtest/gtest.h>
#include "thirteen.h"

TEST(ThirteenTest, ConstructorAndToString) {
    Thirteen t1("A5");
    EXPECT_EQ(t1.to_string(), "A5");

    Thirteen t2("00A");
    EXPECT_EQ(t2.to_string(), "A");

    Thirteen t3("0");
    EXPECT_EQ(t3.to_string(), "0");

    Thirteen t4("C");
    EXPECT_EQ(t4.to_string(), "C");
}

TEST(ThirteenTest, Arithmetic) {
    Thirteen a("A5");
    Thirteen b("7C");
    Thirteen sum = a + b;
    EXPECT_EQ(sum.to_string(), "154");

    Thirteen diff = a - Thirteen("5");
    EXPECT_EQ(diff.to_string(), "A0");
}

TEST(ThirteenTest, Comparison) {
    Thirteen a("A5");
    Thirteen b("7C");
    EXPECT_TRUE(a > b);
    EXPECT_FALSE(a < b);
    EXPECT_FALSE(a == b);
}

TEST(ThirteenTest, ExceptionOnNegativeResult) {
    Thirteen t1("5");
    Thirteen t2("A5");
    EXPECT_THROW(t1 - t2, std::invalid_argument);
}