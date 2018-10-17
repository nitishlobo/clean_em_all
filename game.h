#include <vector>

#include "frame.h"

class Game {
private:
    std::vector<Frame> frames;
    int score;

public:
    Game();
    void Bowl(int pins_knocked);

    int GetOverallScore();
    int GetFrameScore(int frame);
    int GetBallScore(int frame, int ball);
    int GetFramesBowled();
    int GetBallsBowledInFrame(int frame);
    bool IsGameOver();
};
