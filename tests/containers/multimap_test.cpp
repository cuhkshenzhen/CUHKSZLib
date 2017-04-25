#include "gtest/gtest.h"
#include "containers/Map.h"

#include <string>
using std::string;

cuhksz::MultiMap<int, char> testMultiMap {
    {1, 'A'},
    {2, 'B'},
    {2, 'C'},
    {2, 'D'},
    {4, 'E'},
    {3, 'F'}
};

//
// TEST(multimapTest, init) {
//
// }

TEST(multimapTest, equal_range) {
    auto range = testMultiMap.equal_range(2);
    string ch;
    for (auto i = range.first; i != range.second; ++i)
    {
        std::cout << i->first << ": " << i->second << '\n';
        ch += i->second;
    }
    EXPECT_EQ(ch, "BCD");

}

TEST(multimapTest, size) {
    EXPECT_EQ(testMultiMap.size(), 6);
}

TEST(multimapTest, erase) {
    testMultiMap.erase(2);
    EXPECT_EQ(testMultiMap.size(), 3);
}

TEST(multimapTest, count) {
    EXPECT_EQ(testMultiMap.count(3), 1);
    EXPECT_EQ(testMultiMap.count(5), 0);
}

TEST(multimapTest, find) {
    EXPECT_EQ(testMultiMap.find(4)->second, 'E');
}

TEST(multimapTest, clear) {
    testMultiMap.clear();
    EXPECT_TRUE(testMultiMap.isEmpty());
}
