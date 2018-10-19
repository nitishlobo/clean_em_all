/**************************************************************************
This file implements the top-most level abstraction in the ten pin bowling game.
***************************************************************************/
#include "game.h"

/* Class initialisation */
Game::Game() {
    score_ = 0;
}

/* Record game history and handle game logic for score keeping - spares, strikes, etc. */
void Game::Bowl(int pins_knocked) {
    //Get the frame number which the last ball was bowled in (i.e. 0 to 9 in a typical game).
    int currentFrameNumber = frames_.size()-1;

    //Bowl in new frame if no frames have been bowled in
    //or a strike is rolled
    //or balls in the current frame equal to or more than the allowed limit
    //and its not the last frame of the game
    if (currentFrameNumber == -1
        || ((frames_[currentFrameNumber].isStrikeAchieved() == true || frames_[currentFrameNumber].GetBallsBowled() >= 2)
        && currentFrameNumber < 9)) {
            Frame f;
            f.Bowl(pins_knocked);
            frames_.push_back(f);
            currentFrameNumber++;
    } else {
        //Otherwise bowl into the current frame
        frames_[currentFrameNumber].Bowl(pins_knocked);
    }

    //Score for spare
    if (currentFrameNumber > 0) {
        if (frames_[currentFrameNumber-1].isSpareAchieved() && (frames_[currentFrameNumber].GetBallsBowled() == 1)) {
            //Recalculate score in previous frame and add this change to the game score
            frames_[currentFrameNumber-1].SetScore(score_ + pins_knocked);
            score_ = score_ + pins_knocked;
        }
    }

    //Score for strike
    if (currentFrameNumber > 0) {
        //Add the two ball scores in the current frame if previous frame has a strike
        if (frames_[currentFrameNumber-1].isStrikeAchieved() && (frames_[currentFrameNumber].GetBallsBowled() == 2)) {
            int originalFrameScore = frames_[currentFrameNumber-1].GetScore();
            int previousBallScore = frames_[currentFrameNumber].GetPinsKnockedOnRoll(1);
            frames_[currentFrameNumber-1].SetScore(originalFrameScore + previousBallScore + pins_knocked);
            score_ = score_ + previousBallScore + pins_knocked;
        }
    }
    //Score for 2 consecutive strikes
    if (currentFrameNumber > 1) {
        //Add previous ball from previous frame and current ball to the original score in the frame.
        if (frames_[currentFrameNumber-2].isStrikeAchieved()
            && (frames_[currentFrameNumber-1].GetBallsBowled() == 1)
            && (frames_[currentFrameNumber].GetBallsBowled() == 1)) {
                int originalFrameScore = frames_[currentFrameNumber-2].GetScore();
                int previousBallScore = frames_[currentFrameNumber-1].GetPinsKnockedOnRoll(1);
                frames_[currentFrameNumber-2].SetScore(originalFrameScore + previousBallScore + pins_knocked);
                score_ = score_ + previousBallScore + pins_knocked;
        }
    }

    //Normal scoring
    score_ = score_ + pins_knocked;
    frames_[currentFrameNumber].SetScore(score_);
    return;
}

/* Return the overall game score, regardless of whether the game is finished or still in progress. */
int Game::GetOverallScore() {
    return score_;
}

/* Return the cumulative score from the the start of the game to a particular frame. */
int Game::GetFrameScore(int frame) {
    return frames_[frame].GetScore();
}

/* Return the number of pins knocked over for a particular ball. */
int Game::GetBallScore(int frame, int ball) {
    return frames_[frame].GetPinsKnockedOnRoll(ball);
}

/* Return the number of frames completed (including the one currently being completed) in the game. */
int Game::GetFramesBowled() {
    return frames_.size();
}

/* Return the number of balls bowled for a particular frame.
	Example: a strike means only 1 ball is bowled for the frame.
			Anything else means 2 balls are bowled in the frame,
			unless it is the last frame or a frame is not completed.
*/
int Game::GetBallsBowledInFrame(int frame) {
    return frames_[frame].GetBallsBowled();
}

/* Return boolean indicating whether the game has been completed. */
bool Game::IsGameOver() {
    //Get the frame number which the last ball was bowled in (i.e. 0 to 9 in a typical game).
    int currentFrameNumber = frames_.size()-1;

    //Game is over only if:
    //its the last frame
    //  and 3 balls are bowled in the last frame
    //  or there's 2 balls with no spares and no strikes.
    if (currentFrameNumber == 9) {
        if (frames_[currentFrameNumber].GetBallsBowled() == 3
            || (frames_[currentFrameNumber].GetBallsBowled() == 2
            && !frames_[currentFrameNumber].isSpareAchieved()
            && !frames_[currentFrameNumber].isStrikeAchieved())) {
                return true;
        }
    }
    return false;
}
