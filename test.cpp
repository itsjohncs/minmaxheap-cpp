/**
 * @file MinMaxHeap.hpp
 * @author John Sullivan (jsull003 at ucr.edu)
 * @date May 16, 2012
 *
 * @brief google-test tests for @ref MinMaxHeap.
 **/

#include "MinMaxHeap.hpp"

#include "gtest/gtest.h"

#include <vector>
#include <algorithm>
#include <cstdlib>
#include <iostream>

using namespace minmax;

class MinMaxHeapTest: public ::testing::Test
{
protected:
    static std::vector<int> unsortedValues;
    
    /// The values in unsorted values in ascending order.
    static std::vector<int> sortedValues;
    
    static const size_t nvalues = 10000;
    
    static const int seed = 0;
    
    static void SetUpTestCase()
    {
        srand(seed);
        
        unsortedValues.resize(nvalues);
        sortedValues.resize(nvalues);
        
        for (unsigned int i = 0; i < nvalues; ++i)
            unsortedValues[i] = sortedValues[i] = rand();
            
        std::sort(sortedValues.begin(), sortedValues.end());
    }
    
    MinMaxHeap<int> heap;
    
    void SetUp()
    {
        for (unsigned int i = 0; i < nvalues; ++i)
            heap.push(unsortedValues[i]);
    }
};

std::vector<int> MinMaxHeapTest::unsortedValues;
std::vector<int> MinMaxHeapTest::sortedValues;

TEST_F(MinMaxHeapTest, SatisfiesMaxHeap)
{    
    // Get all the values out of the heap and store them in ascending order
    std::vector<int> values(nvalues);
    for (int i = (int)nvalues - 1; i >= 0; --i)
        values[i] = heap.popMax();

    ASSERT_TRUE(
        std::equal(sortedValues.begin(), sortedValues.end(), values.begin()))
        << "Values were not popped in the correct order.";
}

TEST_F(MinMaxHeapTest, SatisfiesMinHeap)
{
    // Get all the values out of the heap and store them in ascending order
    std::vector<int> values(nvalues);
    for (unsigned int i = 0; i < nvalues; ++i)
        values[i] = heap.popMin();

    ASSERT_TRUE(
        std::equal(sortedValues.begin(), sortedValues.end(), values.begin()))
        << "Values were not popped in the correct order.";
}

TEST_F(MinMaxHeapTest, SatisfiesMinMaxHeap_HalfAndHalf)
{
    // Get all the values out of the heap and store them in ascending order
    std::vector<int> values(nvalues);
    for (unsigned int i = 0; i < nvalues / 2; ++i)
        values[i] = heap.popMin();

    for (int i = (int)nvalues - 1; i >= (int)nvalues / 2; --i)
        values[i] = heap.popMax();

    ASSERT_TRUE(
        std::equal(sortedValues.begin(), sortedValues.end(), values.begin()))
        << "Values were not popped in the correct order.";
}

TEST_F(MinMaxHeapTest, SatisfiesMinMaxHeap_Alternating)
{
    // Get all the values out of the heap and store them in ascending order
    std::vector<int> values(nvalues);
    for (unsigned int i = 0; i < nvalues / 2; ++i)
    {
        values[i] = heap.popMin();
        values[nvalues - i - 1] = heap.popMax();
    }
        
    if (nvalues % 2 == 1)
        values[nvalues / 2 + 1] = heap.popMin();
        
    //for (unsigned int i = 0; i < nvalues; ++i)
    //{
    //    std::cout << values[i] << " ?= " << sortedValues[i] << std::endl;
    //}

    ASSERT_TRUE(
        std::equal(sortedValues.begin(), sortedValues.end(), values.begin()))
        << "Values were not popped in the correct order.";
}
