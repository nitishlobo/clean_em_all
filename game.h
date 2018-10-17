/**************************************************************************
This file declares the top-most level abstraction in the ten pin bowling game.
The Game class contains the frames of the game and the score information.
***************************************************************************/
#include <vector>

#include "frame.h"

/*	Record the full game history by the use of the Game class.
	Need only one instantiation of this class per player per game.

	Example: Game player_nitish;
			player_nitish.Bowl(3);
*/
class Game {
/* Class members:
	frames_ - the frame into which the player will bowl the balls into. Vector of the class Frame.
	score_ - total score of the game
*/
private:
    std::vector<Frame> frames_;
    int score_;

public:
/* Main class methods:
	Game - class initialisation
	Bowl - call this method (from the main application) everytime a ball is bowled
*/
    Game();
    void Bowl(int pins_knocked);

/* Public APIs:
	GetOverallScore - request the overall game score to date
	GetFrameScore - request the score since the beginning of the game to the end of a specified frame
	GetBallScore - request how many pins were knocked over on a specific roll in a specific frame
	GetFramesBowled - request the number of frames played in the game to date (including unfinished frames)
	GetBallsBowledInFrame - request the number of balls bowled in a specific frame of the game
	IsGameOver - request to see if the player has completed all 10 frames
*/
    int GetOverallScore();
    int GetFrameScore(int frame);
    int GetBallScore(int frame, int ball);
    int GetFramesBowled();
    int GetBallsBowledInFrame(int frame);
    bool IsGameOver();
};
