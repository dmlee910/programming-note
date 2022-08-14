#include <vector>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    while (progresses.size()) {
        for (int i = 0; i < progresses.size(); i++) {
            progresses[i] +=  speeds[i];
        }

        int count = 0;
        while (progresses.size()) {
            if (progresses[0] < 100) {
                break;
            }
            count++;
            progresses.erase(progresses.begin());
            speeds.erase(speeds.begin());
        }
        if (count != 0) {
            answer.push_back(count);
        }
    }

    return answer;
}

TEST(sjpark_Lessons_42586, test1)
{
    vector<int> progresses = {93, 30, 55};
    vector<int> speeds = {1, 30, 5};
    vector<int> answer = {2, 1};
    vector<int> result = solution(progresses, speeds);

    EXPECT_EQ(answer, result);
}

TEST(sjpark_Lessons_42586, test2)
{
    vector<int> progresses = {95, 90, 99, 99, 80, 99};
    vector<int> speeds = {1, 1, 1, 1, 1, 1};
    vector<int> answer = {1, 3, 2};
    vector<int> result = solution(progresses, speeds);

    EXPECT_EQ(answer, result);
}

