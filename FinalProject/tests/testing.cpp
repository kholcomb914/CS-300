#include <gtest/gtest.h>
#include "hamming.hpp"

// Test fixture for Hamming class
class HammingTest : public ::testing::Test {
protected:
    HammingTest() : hamming("1011001") {}
    Hamming hamming;
};

TEST_F(HammingTest, ConstructorAndGetCodeWord) {
    Eigen::Matrix<int, 7, 1> expectedCodeWord;
    expectedCodeWord << 1, 0, 1, 1, 0, 0, 1;
    EXPECT_EQ(hamming.getCodeWord(), expectedCodeWord);
}

TEST_F(HammingTest, FlipBit) {
    hamming.flipBit(0);
    Eigen::Matrix<int, 7, 1> expectedCodeWord;
    expectedCodeWord << 0, 0, 1, 1, 0, 0, 1;
    EXPECT_EQ(hamming.getCodeWord(), expectedCodeWord);
}

TEST_F(HammingTest, GetSyndrome) {
    Eigen::Matrix<int, 3, 1> expectedSyndrome; 
    expectedSyndrome << 0, 0, 1;
    EXPECT_EQ(hamming.getSyndrome(), expectedSyndrome);
}

TEST_F(HammingTest, Decode) {
    int expectedErrorIndex = 2;
    EXPECT_EQ(hamming.decode(), expectedErrorIndex);
}

TEST_F(HammingTest, ErrorReport) {
    
    std::ostringstream output;
    std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());
    hamming.errorReport();

    std::cout.rdbuf(oldCout);
    std::string expectedOutput = "1011001 (Error found at bit 3.)\n";
    EXPECT_EQ(output.str(), expectedOutput);
}