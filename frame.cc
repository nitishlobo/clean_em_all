/**************************************************************************
This file declares the mid-level abstraction in the ten pin bowling game.
***************************************************************************/
#include "frame.h"

/* Class initialisation */
Frame::Frame() {
    score_ = 0;
    strikeAchieved_ = false;
    spareAchieved_ = false;
}

/* Record the ball bowled into a ball class vector and record any spares or strikes. */
void Frame::Bowl(int pins_knocked) {
    //Bowl the ball
    Ball b;
    b.Bowl(pins_knocked);
    balls_.push_back(b);

    //Record a spare
    if (balls_.size() > 1) {
        if (balls_[balls_.size()].GetPinsKnocked() + pins_knocked == 10) {
            spareAchieved_ = true;
        }
    }

    //Record a strike
    if (pins_knocked == 10) {
        strikeAchieved_ = true;
    }
    return;
}

/* Set the score for the frame.
    Typically this is the sum of the game score plus the pins knocked in this frame.
*/
void Frame::SetScore(int score_value) {
    score_ = score_value;
}

/* Return boolean indicating whether frame consists of a spare. */
bool Frame::isSpareAchieved() {
    return spareAchieved_;
}

/* Return boolean indicating whether frame consists of a strike. */
bool Frame::isStrikeAchieved() {
    return strikeAchieved_;
}

/* Return number of balls bowled in a frame. */
int Frame::GetBallsBowled() {
    return balls_.size();
}

/* Return number of pins knocked for an individual ball inside the frame. */
int Frame::GetPinsKnockedOnRoll(int roll) {
    return balls_[roll-1].GetPinsKnocked();
}

/* Return the score since the beginning of the game to this frame (inclusive) */
int Frame::GetScore() {
    return score_;
}
