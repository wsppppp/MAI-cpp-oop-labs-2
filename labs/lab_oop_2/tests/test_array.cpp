#include <gtest/gtest.h>
#include "array.h"

TEST(ArrayTest, Constructors) {
    Array a;
    EXPECT_EQ(a.size(), 0);

    Array b(5, 7);
    EXPECT_EQ(b.size(), 5);
    EXPECT_EQ(b[0], 7);

    Array c{1,2,3};
    EXPECT_EQ(c.size(), 3);
    EXPECT_EQ(c[2], 3);
}

TEST(ArrayTest, Arithmetic) {
    Array a{1,2,3};
    Array b{4,5};
    Array c = a + b;
    EXPECT_EQ(c.size(), 3);
    EXPECT_EQ(c[0], 5);
    EXPECT_EQ(c[1], 7);
    EXPECT_EQ(c[2], 3);
}

TEST(ArrayTest, AccessAndModify) {
    Array a{1,2,3};
    a.set(1, 9);
    EXPECT_EQ(a[1], 9);
    a.push_back(4);
    EXPECT_EQ(a.size(), 4);
    a.pop_back();
    EXPECT_EQ(a.size(), 3);
    EXPECT_EQ(a.back(), 3);
}