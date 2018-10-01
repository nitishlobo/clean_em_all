class Game {
private:
    int score;
    vector<Frame> frames;

public:
    void Bowl(int pins_knocked);
    int GetOverallScore();
    int GetFrameScore(int frame);
    int GetBallScore(int frame, int ball);
    int GetFramesBowled();
    int GetBallsBowledInFrame(int frame);
    bool IsGameOver();
}
