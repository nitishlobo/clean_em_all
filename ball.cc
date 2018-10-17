#include "ball.h"

Ball::Ball() {
    pins_knocked = 0;
}

void Ball::Bowl(int score) {
    pins_knocked = score;
    return;
}

int Ball::GetPinsKnocked() {
    return pins_knocked;
}
