#include <vector>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

static vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    auto iter = arr.begin();
    answer.push_back(*iter);

    for(auto iter = arr.begin(); iter != arr.end(); iter++) {
        if (answer[answer.size()-1] == *iter) {
            continue;
        }
        answer.push_back(*iter);
    }

    return answer;
}

TEST(sjpark_Lessons_12906, test1)
{
    vector<int> arr = {1,1,3,3,0,1,1};
    vector<int> answer = {1,3,0,1};
    vector<int> result = solution(arr);

    bool b = true;
    if (answer.size() == result.size()) {
        for (int i = 0; i < answer.size(); i++) {
            if (answer[i] != result[i]) {
                b = false;
                break;
            }
        }
    }
    else {
        b = false;
    }

    EXPECT_TRUE(b);
}

TEST(sjpark_Lessons_12906, test2)
{
    vector<int> arr = {4,4,4,3,3};
    vector<int> answer = {4,3};
    vector<int> result = solution(arr);

    bool b = true;
    if (answer.size() == result.size()) {
        for (int i = 0; i < answer.size(); i++) {
            if (answer[i] != result[i]) {
                b = false;
                break;
            }
        }
    }
    else {
        b = false;
    }

    EXPECT_TRUE(b);
}
