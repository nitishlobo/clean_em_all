#include "frame.h"

Frame::Frame() {
    score = 0;
    strikeAchieved = false;
    spareAchieved = false;
}

void Frame::Bowl(int pins_knocked) {
    //Bowl the ball
    Ball b;
    b.Bowl(pins_knocked);
    balls.push_back(b);

    //Record a spare
    if (balls.size() > 1) {
        if (balls[balls.size()].GetPinsKnocked() + pins_knocked == 10) {
            spareAchieved = true;
        }
    }

    //Record a strike
    if (pins_knocked == 10) {
        strikeAchieved = true;
    }
    return;
}

void Frame::SetScore(int score_value) {
    score = score_value;
}

int Frame::GetBallsBowled() {
    return balls.size();
}

bool Frame::isStrikeAchieved() {
    return strikeAchieved;
}

bool Frame::isSpareAchieved() {
    return spareAchieved;
}

int Frame::GetScore() {
    return score;
}

int Frame::GetPinsKnockedOnRoll(int roll) {
    return balls[roll-1].GetPinsKnocked();
}
