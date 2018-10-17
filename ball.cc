/**************************************************************************
This file declares the lowest-level abstraction in the ten pin bowling game.
***************************************************************************/
#include "ball.h"

/* Class initialisation */
Ball::Ball() {
    pins_knocked_ = 0;
}

/* Record the number of pins knocked over by the bowled ball. */
void Ball::Bowl(int score) {
    pins_knocked_ = score;
    return;
}

/* Request number of pins knocked by the ball. */
int Ball::GetPinsKnocked() {
    return pins_knocked_;
}
