#include <vector>
#include <iostream>
#include <cmath>
#include <gtest/gtest.h>

using namespace std;

string solution(int n) {
    string answer = "";

    long long result = 0;
    int rest = 0;
    int val = 0;
    int decade = 0;
    while (n > 0) {
        rest = ((n-1)%3);
        switch (rest) {
            case 0 : val = 1; break;
            case 1 : val = 2; break;
            case 2 : val = 4; break;
        }
        result += (val * pow(10, decade));
        ++decade;
        n = ((n-1)/3);
    }

    answer = to_string(result);

    return answer;
}

TEST(sjpark_Lessons_12899, test1)
{
    EXPECT_EQ(solution(1), string("1"));
    EXPECT_EQ(solution(2), string("2"));
    EXPECT_EQ(solution(3), string("4"));
    EXPECT_EQ(solution(4), string("11"));
    EXPECT_EQ(solution(5), string("12"));
    EXPECT_EQ(solution(6), string("14"));
    EXPECT_EQ(solution(7), string("21"));
    EXPECT_EQ(solution(8), string("22"));
    EXPECT_EQ(solution(9), string("24"));
    EXPECT_EQ(solution(10), string("41"));
    EXPECT_EQ(solution(11), string("42"));
    EXPECT_EQ(solution(12), string("44"));
}

