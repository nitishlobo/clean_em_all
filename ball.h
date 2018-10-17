/**************************************************************************
This file declares the lowest abstraction in the ten pin bowling game.
The Ball class is an object that represents a ball that is used to knock the pins over.
***************************************************************************/

/*	Record a ball being bowled down the aisle.
	Need one instantiation of this class per ball bowled in the game.

	Example: std::vector<Ball> balls;
             balls.Bowl(3);
*/
class Ball {
/* Class members:
    pins_knocked_ - record of how many pins the player has knocked over.
*/
private:
    int pins_knocked_;

public:
/* Main class methods:
	Ball - class initialisation
	Bowl - call this method from the frame class everytime a ball is bowled
*/
    Ball();
    void Bowl(int score);

/* Public APIs:
    GetPinsKnocked - request number of pins knocked by the ball
*/
    int GetPinsKnocked();
};
