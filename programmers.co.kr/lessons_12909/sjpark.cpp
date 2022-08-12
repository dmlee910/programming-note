#include <vector>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

static bool solution(string s)
{
    bool answer = true;

    vector<char> v;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            v.push_back(s[i]);
            continue;
        }

        // ')'
        if (v.size() == 0) {
            answer = false;
            break;
        }
        else {
            v.pop_back();
        }
    }

    if (v.size() != 0) {
        answer = false;
    }

    return answer;
}

TEST(sjpark_Lessons_12909, test1)
{
    string s = "()()";
    EXPECT_EQ(solution(s), true);
    s = "(())()";
    EXPECT_EQ(solution(s), true);
    s = ")()(";
    EXPECT_EQ(solution(s), false);
    s = "(()(";
    EXPECT_EQ(solution(s), false);
}

