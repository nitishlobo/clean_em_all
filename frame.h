class Frame {
private:
    vector<Ball> balls;
    int frame;
    int score;

public:
    void Bowl(int pins_knocked);
    int GetScore();
    int GetFrame();
}