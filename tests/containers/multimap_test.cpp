#include "gtest/gtest.h"
#include "containers/MultiMap.h"

#include <map>

cuhksz::MultiMap<int, char> testMultimap {
    {1, 'A'},
    {2, 'B'},
    {2, 'C'},
    {2, 'D'},
    {4, 'E'},
    {3, 'F'}
};

std::multimap<int, char> stlMultimap {
    {1, 'A'},
    {2, 'B'},
    {2, 'C'},
    {2, 'D'},
    {4, 'E'},
    {3, 'F'}
};


TEST(multimapTest, initialize) {
    cuhksz::MultiMap<int, char> initMultimap1;
    EXPECT_EQ(initMultimap1.size(), 0);
    cuhksz::MultiMap<int, char> initMultimap2( stlMultimap );
    EXPECT_EQ(initMultimap2.size(), 6);
}

TEST(multimapTest, typeConvert) {
    auto multimap1 = testMultimap.toStlMultimap();
    std::multimap<int, char> multimap2 = testMultimap;
    EXPECT_EQ(multimap1, multimap2);
}

TEST(multimapTest, eqOperator) {
    cuhksz::MultiMap<int, char> initMultimap2( stlMultimap );
    testMultimap = initMultimap2;
    EXPECT_EQ(testMultimap.size(), 6);
}

TEST(multimapTest, find) {
    auto valueFound = testMultimap.find(2);
    EXPECT_EQ(valueFound.size(), 3);
}

TEST(multimapTest, erase) {
    testMultimap.erase(2);
    EXPECT_EQ(testMultimap.size(), 3);
}

TEST(multimapTest, count) {
    EXPECT_EQ(testMultimap.count(3), 1);
    EXPECT_EQ(testMultimap.count(5), 0);
}

TEST(multimapTest, clear) {
    testMultimap.clear();
    EXPECT_TRUE(testMultimap.isEmpty());
}
