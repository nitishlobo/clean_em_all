#include <vector>

#include "ball.h"

class Frame {
private:
    bool strikeAchieved, spareAchieved;
    int score;
    std::vector<Ball> balls;

public:
    Frame();
    void Bowl(int pins_knocked);
    void SetScore(int score_value);

    int GetBallsBowled();
    bool isStrikeAchieved();
    bool isSpareAchieved();
    int GetScore();
    //Get pins knocked on a certain roll in the frame
    //In a typical game roll will be 1 or 2; in the last frame roll will be 1 or 2 or 3.
    int GetPinsKnockedOnRoll(int roll);
};
