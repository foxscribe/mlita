#include <gtest/gtest.h>
#include <numeric>
#include "solution.hpp"

TEST(Calculate, Example1)
{
	auto R = Calculate(8);
  EXPECT_EQ(R, (std::vector<unsigned long>{ 3, 5 }));
}

TEST(Calculate, Example2)
{
	auto R = Calculate(100);
  EXPECT_EQ(R, (std::vector<unsigned long>{ 2, 3, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 }));
}

TEST(CalculateTest, Value4) {
	auto result = Calculate(4);
	EXPECT_EQ(result, (std::vector<unsigned long>{ 4 }));
}

TEST(CalculateTest, Value5) {
	auto result = Calculate(5);
	EXPECT_EQ(result, (std::vector<unsigned long>{ 2, 3 }));
}

TEST(CalculateTest, Value10) {
	auto result = Calculate(10);
	EXPECT_EQ(result, (std::vector<unsigned long>{ 2, 3, 5 }));
}

TEST(CalculateTest, Value15) {
	auto result = Calculate(15);
	EXPECT_EQ(result, (std::vector<unsigned long>{2, 3, 4, 6}));
}

TEST(CalculateTest, SortedOrder) {
	for (unsigned long n = 1; n <= 100; ++n) {
		auto result = Calculate(n);
		EXPECT_TRUE(std::is_sorted(result.begin(), result.end()));
	}
}

TEST(CalculateTest, MaxValue) {
	auto result = Calculate(10000);
	
	std::set<unsigned long> unique_elements(result.begin(), result.end());
	EXPECT_EQ(unique_elements.size(), result.size());
  
	unsigned long sum = std::accumulate(result.begin(), result.end(), 0UL);
	EXPECT_EQ(sum, 10000UL);
}
