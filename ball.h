/**************************************************************************
This file declares the lowest main abstraction in the ten pin bowling game.
The Ball class is an object that represents a ball that is used to knock the pins over.
***************************************************************************/

/*	Record a ball being bowled down the aisle.
	Need one instantiation of this class per ball bowled in the game.

	Example: //TODO - complete this;
*/
class Ball {
private:
    int pins_knocked;

public:
    Ball();
    void Bowl(int score);
    int GetPinsKnocked();
};
