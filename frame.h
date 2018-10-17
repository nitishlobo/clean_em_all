/**************************************************************************
This file declares the mid-level abstraction in the ten pin bowling game.
Frame is an object representing one of the several frames in a typical game.
The Frame class is used by the Game class and it uses the Ball class.
***************************************************************************/
#include <vector>

#include "ball.h"

/*	Record scoring information relating to a frame in the game.
	A typical game involves 10 frames and each frame has 2 balls each,
    except the last frame which can have 2 or 3 balls.

	Example: std::vector<Frame> frames;
			 frames.Bowl(7);
*/
class Frame {
/* Class members:
    spareAchieved_ - boolean indicating whether spare is present in the frame
	strikeAchieved_ - boolean indicating whether strike is present in the frame
	score_ - score from the beginning of the game to the current frame (inclusive).
    balls_ - record of how many pins the player has knocked over. Vector of the class Ball.
*/
private:
    bool  spareAchieved_, strikeAchieved_;
    int score_;
    std::vector<Ball> balls_;

public:
/* Main class methods:
	Frame - class initialisation
	Bowl - call this method everytime a ball is bowled
    SetScore - set the score for the frame. This needs to be a method because of the way
                spares and strikes work.
*/
    Frame();
    void Bowl(int pins_knocked);
    void SetScore(int score_value);

/* Public APIs:
    isSpareAchieved - return boolean indicating whether frame consists of a spare
    isStrikeAchieved - return boolean indicating whether frame consists of a strike
    GetBallsBowled - request number of balls bowled in a frame
    GetPinsKnockedOnRoll - request number of pins knocked for an individual ball inside the frame
                            roll is the number of the roll inside the frame (starting from 1).
                            Valid roll values for a typical game are 1, 2 or 3.
    GetScore - request the score since the beginning of the game to this frame (inclusive)
*/
    bool isSpareAchieved();
    bool isStrikeAchieved();
    int GetBallsBowled();
    int GetPinsKnockedOnRoll(int roll);
    int GetScore();
};
