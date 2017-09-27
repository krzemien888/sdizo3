#include "stdafx.h"

#include "gtest\gtest.h"

#include "alghoritms\BackpackBruteforce\BackpackBruteforce.h"
#include "alghoritms\BackpackBruteforce\BackpackBruteforce.cpp"

#include "alghoritms\BackpackDynamic\BackpackDynamic.h"
#include "alghoritms\BackpackDynamic\BackpackDynamic.cpp"

#include "alghoritms\BackpackGreedy\BackpackGreedy.h"
#include "alghoritms\BackpackGreedy\BackpackGreedy.cpp"

template<typename T>
::testing::AssertionResult VectorsMatch(const std::vector<T> &expected,
										const std::vector<T> &actual) {
	
	if (expected.size() != actual.size())
		return ::testing::AssertionFailure() << "Size of expected: " << expected.size() << "\n Size of actual: " << actual.size();

	for (size_t i(0); i < expected.size(); ++i) {
		if (expected[i] != actual[i]) {
			return ::testing::AssertionFailure() << "array[" << i
				<< "] (" << actual[i] << ") != expected[" << i
				<< "] (" << expected[i] << ")";
		}
	}

	return ::testing::AssertionSuccess();
}

TEST(BruteForceTest, Sack1DataTest)
{
	BackpackBruteforce algh;

	int size = 10;
	int amount = 6;
	std::vector<int> weights = { 7, 8, 6, 4, 3, 9 };
	std::vector<int> values = { 75, 150, 250, 35, 10, 100 };

	algh.apply(weights, values, size);

	auto result = algh.getSolution();

	int takenSize = 0, sumValue = 0;
	for (Item item : result)
	{
		takenSize += item.weight;
		sumValue += item.value;
	}

	EXPECT_EQ(10, takenSize);
	EXPECT_EQ(285, sumValue);
}

TEST(BruteForceTest, Sack2DataTest)
{
	BackpackBruteforce algh;

	int size = 30;
	int amount = 10;
	std::vector<int> weights = { 9, 13, 3, 5, 7, 8, 10, 3, 9, 6 };
	std::vector<int> values = { 116, 103, 84, 83, 54, 72, 89, 103, 43, 115 };

	algh.apply(weights, values, size);

	auto result = algh.getSolution();

	int takenSize = 0, sumValue = 0;
	for (Item item : result)
	{
		takenSize += item.weight;
		sumValue += item.value;
	}

	EXPECT_EQ(26, takenSize);
	EXPECT_EQ(501, sumValue);
}

TEST(DynamicProgramming, Sack1DataTest)
{
	BackpackDynamic algh;

	int size = 10;
	int amount = 6;
	std::vector<int> weights = { 7, 8, 6, 4, 3, 9 };
	std::vector<int> values = { 75, 150, 250, 35, 10, 100 };

	algh.apply(weights, values, size);

	auto result = algh.getSolution();

	int takenSize = 0, sumValue = 0;
	for (Item item : result)
	{
		takenSize += item.weight;
		sumValue += item.value;
	}

	EXPECT_EQ(10, takenSize);
	EXPECT_EQ(285, sumValue);
}

TEST(DynamicProgramming, Sack1DataMatrixTest)
{
	BackpackDynamic algh;

	int size = 10;
	int amount = 6;
	std::vector<int> weights = { 7, 8, 6, 4, 3, 9 };
	std::vector<int> values = { 75, 150, 250, 35, 10, 100 };

	algh.prepareSolutionMatrix(weights, values, size);

	auto result = algh.getSolutionMatrix();

	std::vector<std::vector<int>> expected = {
		{ 0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,75,75,75,75},
		{ 0,0,0,0,0,0,0,75,150,150,150},
		{ 0,0,0,0,0,0,250,250,250,250,250},
		{ 0,0,0,0,35,35,250,250,250,250,285 },
		{ 0,0,0,10,35,35,250,250,250,260,285},
		{ 0,0,0,10,35,35,250,250,250,260,285}
	};

	EXPECT_EQ(result, expected);
}

TEST(DynamicProgramming, Sack2DataTest)
{
	BackpackDynamic algh;

	int size = 30;
	int amount = 10;
	std::vector<int> weights = { 9, 13, 3, 5, 7, 8, 10, 3, 9, 6 };
	std::vector<int> values = { 116, 103, 84, 83, 54, 72, 89, 103, 43, 115 };

	algh.apply(weights, values, size);

	auto result = algh.getSolution();

	int takenSize = 0, sumValue = 0;
	for (Item item : result)
	{
		takenSize += item.weight;
		sumValue += item.value;
	}

	EXPECT_EQ(26, takenSize);
	EXPECT_EQ(501, sumValue);
}

TEST(DynamicProgramming, Sack3DataTest)
{
	BackpackDynamic algh;

	int size = 90;
	int amount = 32;
	std::vector<int> weights = { 9, 13, 3, 5, 7, 8, 10, 3, 9, 6, 11, 7, 15, 5, 9, 12, 17, 13, 4, 7, 12, 8, 9, 17, 18, 2, 3, 11, 28, 15, 12, 16 };
	std::vector<int> values = { 116, 103, 84, 83, 54, 72, 89, 103, 43, 115, 121, 90, 133, 60, 70, 122, 155, 75, 44, 56, 78, 78, 145, 51, 100, 13, 30, 66, 120, 125, 90, 150 };

	algh.apply(weights, values, size);

	auto result = algh.getSolution();

	int takenSize = 0, sumValue = 0;
	for (Item item : result)
	{
		takenSize += item.weight;
		sumValue += item.value;
	}

	EXPECT_EQ(90, takenSize);
	EXPECT_EQ(1233, sumValue);
}

TEST(DynamicProgramming, Sack4DataTest)
{
	BackpackDynamic algh;

	int size = 120;
	int amount = 32;
	std::vector<int> weights = { 9, 13, 3, 5, 7, 8, 10, 3, 9, 6, 11, 7, 15, 5, 9, 12, 17, 13, 4, 7, 12, 8, 9, 17, 18, 2, 3, 11, 28, 15, 12, 16 };
	std::vector<int> values = { 116, 103, 84, 83, 54, 72, 89, 103, 43, 115, 121, 90, 133, 60, 70, 122, 155, 75, 44, 56, 78, 78, 145, 51, 100, 13, 30, 66, 120, 125, 90, 150 };

	algh.apply(weights, values, size);

	auto result = algh.getSolution();

	int takenSize = 0, sumValue = 0;
	for (Item item : result)
	{
		takenSize += item.weight;
		sumValue += item.value;
	}

	EXPECT_EQ(120, takenSize);
	EXPECT_EQ(1509, sumValue);
}

TEST(GreedyBackpack, Sack1DataTest)
{
	BackpackGreedy algh;

	int size = 10;
	int amount = 6;
	std::vector<int> weights = { 7, 8, 6, 4, 3, 9 };
	std::vector<int> values = { 75, 150, 250, 35, 10, 100 };

	algh.apply(weights, values, size);

	auto result = algh.getSolution();

	int takenSize = 0, sumValue = 0;
	for (Item item : result)
	{
		takenSize += item.weight;
		sumValue += item.value;
	}

	EXPECT_EQ(10, takenSize);
	EXPECT_EQ(285, sumValue);
}

TEST(GreedyBackpack, Sack2DataTest)
{
	BackpackGreedy algh;

	int size = 30;
	int amount = 10;
	std::vector<int> weights = { 9, 13, 3, 5, 7, 8, 10, 3, 9, 6 };
	std::vector<int> values = { 116, 103, 84, 83, 54, 72, 89, 103, 43, 115 };

	algh.apply(weights, values, size);

	auto result = algh.getSolution();

	int takenSize = 0, sumValue = 0;
	for (Item item : result)
	{
		takenSize += item.weight;
		sumValue += item.value;
	}

	EXPECT_EQ(26, takenSize);
	EXPECT_EQ(501, sumValue);
}

TEST(GreedyBackpack, Sack3DataTest)
{
	BackpackGreedy algh;

	int size = 90;
	int amount = 32;
	std::vector<int> weights = { 9, 13, 3, 5, 7, 8, 10, 3, 9, 6, 11, 7, 15, 5, 9, 12, 17, 13, 4, 7, 12, 8, 9, 17, 18, 2, 3, 11, 28, 15, 12, 16 };
	std::vector<int> values = { 116, 103, 84, 83, 54, 72, 89, 103, 43, 115, 121, 90, 133, 60, 70, 122, 155, 75, 44, 56, 78, 78, 145, 51, 100, 13, 30, 66, 120, 125, 90, 150 };

	algh.apply(weights, values, size);

	auto result = algh.getSolution();

	int takenSize = 0, sumValue = 0;
	for (Item item : result)
	{
		takenSize += item.weight;
		sumValue += item.value;
	}

	EXPECT_EQ(87, takenSize);
	EXPECT_EQ(1204, sumValue);
}

TEST(GreedyBackpack, Sack4DataTest)
{
	BackpackGreedy algh;

	int size = 120;
	int amount = 32;
	std::vector<int> weights = { 9, 13, 3, 5, 7, 8, 10, 3, 9, 6, 11, 7, 15, 5, 9, 12, 17, 13, 4, 7, 12, 8, 9, 17, 18, 2, 3, 11, 28, 15, 12, 16 };
	std::vector<int> values = { 116, 103, 84, 83, 54, 72, 89, 103, 43, 115, 121, 90, 133, 60, 70, 122, 155, 75, 44, 56, 78, 78, 145, 51, 100, 13, 30, 66, 120, 125, 90, 150 };

	algh.apply(weights, values, size);

	auto result = algh.getSolution();

	int takenSize = 0, sumValue = 0;
	for (Item item : result)
	{
		takenSize += item.weight;
		sumValue += item.value;
	}

	EXPECT_EQ(120, takenSize);
	EXPECT_EQ(1509, sumValue);
}

TEST(DynamicProgramming, ResultMatrixTest1)
{
	BackpackDynamic algh;

	int size = 7;
	std::vector<int> weights = { 1, 3, 4, 5 };
	std::vector<int> values = { 1, 4, 5, 7 };

	algh.prepareSolutionMatrix(weights, values, size);
	auto result = algh.getSolutionMatrix();

	std::vector<std::vector<int>> expected = {
		{0,0,0,0,0,0,0,0},
		{0,1,1,1,1,1,1,1},
		{0,1,1,4,5,5,5,5},
		{0,1,1,4,5,6,6,9},
		{0,1,1,4,5,7,8,9}
	};

	EXPECT_EQ(result, expected);
}

TEST(DynamicProgramming, DataTest1)
{
	BackpackDynamic algh;

	int size = 7;
	std::vector<int> weights = { 1, 3, 4, 5 };
	std::vector<int> values = { 1, 4, 5, 7 };

	algh.apply(weights, values, size);
	auto result = algh.getSolution();

	std::vector<Item> expected = {
		{ { 7 },{ 5 } },
		{ { 4 },{ 3 } },
		{ { 5 },{ 4 } }
	};

	
	VectorsMatch(result, expected);
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}