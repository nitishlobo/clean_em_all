#include "game.h"

Game::Game() {
    score = 0;
}

void Game::Bowl(int pins_knocked) {
    //Get the frame number which the last ball was bowled in (i.e. 0 to 9 in a typical game).
    int currentFrameNumber = frames.size()-1;

    //Bowl in new frame if no frames have been bowled in
    //or a strike is rolled
    //or balls in the current frame equal to or more than the allowed limit
    //and its not the last frame of the game
    if (currentFrameNumber == -1
        || ((frames[currentFrameNumber].isStrikeAchieved() == true || frames[currentFrameNumber].GetBallsBowled() >= 2)
        && currentFrameNumber < 9)) {
            Frame f;
            f.Bowl(pins_knocked);
            frames.push_back(f);
            currentFrameNumber++;
    } else {
        //Otherwise bowl into the current frame
        frames[currentFrameNumber].Bowl(pins_knocked);
    }

    //Score for first ball bowled in the game
    if ((currentFrameNumber == 0) && (frames[currentFrameNumber].GetBallsBowled() == 1)) {
        score = pins_knocked;
    }

    //Score for spare
    if (currentFrameNumber > 0) {
        if (frames[currentFrameNumber-1].isSpareAchieved() && (frames[currentFrameNumber].GetBallsBowled() == 1)) {
            //Recalculate score in previous frame and add this change to the game score
            frames[currentFrameNumber-1].SetScore(score + pins_knocked);
            score = score + pins_knocked;
        }
    }

    //Score for strike
    if (currentFrameNumber > 0) {
        //Add the two ball scores in the current frame if previous frame has a strike
        if (frames[currentFrameNumber-1].isStrikeAchieved() && (frames[currentFrameNumber].GetBallsBowled() == 2)) {
            int originalFrameScore = frames[currentFrameNumber-1].GetScore();
            int previousBallScore = frames[currentFrameNumber].GetPinsKnockedOnRoll(1);
            frames[currentFrameNumber-1].SetScore(originalFrameScore + previousBallScore + pins_knocked);
            score = score + previousBallScore + pins_knocked;
        }
    }
    //Score for 2 consecutive strikes
    if (currentFrameNumber > 1) {
        //Add previous ball from previous frame and current ball to the original score in the frame.
        if (frames[currentFrameNumber-2].isStrikeAchieved()
            && (frames[currentFrameNumber-1].GetBallsBowled() == 1)
            && (frames[currentFrameNumber].GetBallsBowled() == 1)) {
                int originalFrameScore = frames[currentFrameNumber-2].GetScore();
                int previousBallScore = frames[currentFrameNumber-1].GetPinsKnockedOnRoll(1);
                frames[currentFrameNumber-2].SetScore(originalFrameScore + previousBallScore + pins_knocked);
                score = score + previousBallScore + pins_knocked;
        }
    }

    //Normal scoring
    score = score + pins_knocked;
    frames[currentFrameNumber].SetScore(score);
    return;
}

int Game::GetOverallScore() {
    return score;
}

int Game::GetFrameScore(int frame) {
    return frames[frame].GetScore();
}

int Game::GetBallScore(int frame, int ball) {
    return frames[frame].GetPinsKnockedOnRoll(ball);
}

int Game::GetFramesBowled() {
    return frames.size();
}

int Game::GetBallsBowledInFrame(int frame) {
    return frames[frame].GetBallsBowled();
}

bool Game::IsGameOver() {
    //Get the frame number which the last ball was bowled in (i.e. 0 to 9 in a typical game).
    int currentFrameNumber = frames.size()-1;

    //Game is over only if:
    //its the last frame
    //  and 3 balls are bowled in the last frame
    //  or there's 2 balls with no spares and no strikes.
    if (currentFrameNumber == 9) {
        if (frames[currentFrameNumber].GetBallsBowled() == 3
            || (frames[currentFrameNumber].GetBallsBowled() == 2
            && !frames[currentFrameNumber].isSpareAchieved()
            && !frames[currentFrameNumber].isStrikeAchieved())) {
                return true;
        }
    }
    return false;
}
