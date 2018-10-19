#include "acceptance_tests.h"

/*----------------------------------
 JOHN SPRAY'S TEST CASES FOLLOW
----------------------------------*/
TEST(JohnSprayScore, OneBall) {
    Game g;
    g.Bowl(2);
    ASSERT_EQ(2, g.GetOverallScore());
}

TEST(JohnSprayScore, TwoBalls) {
    Game g;
    g.Bowl(2);
    g.Bowl(3);

    EXPECT_EQ(2, g.GetBallScore(0,0));
    EXPECT_EQ(3, g.GetBallScore(0,1));
    EXPECT_EQ(5, g.GetFrameScore(0));
    ASSERT_EQ(5, g.GetOverallScore());
}

TEST(JohnSprayScore, Spares) {
    Game g;
    for (int i=0; i<21; i++)
    {
      g.Bowl(5);
    }

    //Test number of balls bowled in each frame and the total number of frames bowled.
    EXPECT_EQ(2, g.GetBallsBowledInFrame(0));
    EXPECT_EQ(2, g.GetBallsBowledInFrame(1));
    ASSERT_EQ(3, g.GetBallsBowledInFrame(9));
    ASSERT_EQ(10, g.GetFramesBowled());

    //Test individual ball scores. First argument is the frame, second argument is the ball.
    EXPECT_EQ(5, g.GetBallScore(0,0));
    EXPECT_EQ(5, g.GetBallScore(0,1));
    EXPECT_EQ(5, g.GetBallScore(1,0));
    EXPECT_EQ(5, g.GetBallScore(1,1));
    EXPECT_EQ(5, g.GetBallScore(9,0));
    EXPECT_EQ(5, g.GetBallScore(9,1));
    ASSERT_EQ(5, g.GetBallScore(9,2));

    //Test frame scores
    EXPECT_EQ(15, g.GetFrameScore(0));
    EXPECT_EQ(30, g.GetFrameScore(1));
    ASSERT_EQ(150, g.GetFrameScore(9));

    //Test total score
    ASSERT_EQ(150, g.GetOverallScore());
}

TEST(JohnSprayScore, Strikes) {
    Game g;
    for (int i=0; i<12; i++)
    {
      g.Bowl(10);
    }

    //Test number of balls bowled in each frame and the total number of frames bowled.
    EXPECT_EQ(1, g.GetBallsBowledInFrame(0));
    EXPECT_EQ(1, g.GetBallsBowledInFrame(1));
    ASSERT_EQ(3, g.GetBallsBowledInFrame(9));
    ASSERT_EQ(10, g.GetFramesBowled());

    //Test individual ball scores. First argument is the frame, second argument is the ball.
    EXPECT_EQ(10, g.GetBallScore(0,0));
    EXPECT_EQ(10, g.GetBallScore(1,0));
    EXPECT_EQ(10, g.GetBallScore(9,1));
    EXPECT_EQ(10, g.GetBallScore(9,0));
    ASSERT_EQ(10, g.GetBallScore(9,2));

    //Test frame scores
    EXPECT_EQ(30, g.GetFrameScore(0));
    ASSERT_EQ(60, g.GetFrameScore(1));

    //Test total score
    ASSERT_EQ(300, g.GetOverallScore());
}

/*----------------------------------
 ROBERT MARTIN'S TEST CASES FOLLOW
----------------------------------*/
TEST(RobertMartinScore, OneBall) {
    Game g;
    g.Bowl(5);
    g.Bowl(4);
    ASSERT_EQ(9, g.GetOverallScore());
}

TEST(RobertMartinScore, TwoBalls) {
    Game g;
    g.Bowl(5);
    g.Bowl(4);
    g.Bowl(7);
    g.Bowl(2);

    EXPECT_EQ(9, g.GetFrameScore(0));
    EXPECT_EQ(18, g.GetFrameScore(1));
    ASSERT_EQ(18, g.GetOverallScore());
}

TEST(RobertMartinScore, SimpleSpare) {
    Game g;
    g.Bowl(3);
    g.Bowl(7);
    g.Bowl(3);

    EXPECT_EQ(13, g.GetFrameScore(0));
    ASSERT_EQ(16, g.GetOverallScore());
}

TEST(RobertMartinScore, SimpleFrameAfterSpare) {
    Game g;
    g.Bowl(3);
    g.Bowl(7);
    g.Bowl(3);
    g.Bowl(2);

    EXPECT_EQ(13, g.GetFrameScore(0));
    ASSERT_EQ(18, g.GetOverallScore());
}

TEST(RobertMartinScore, SimpleStrike) {
    Game g;
    g.Bowl(10);
    g.Bowl(3);
    g.Bowl(6);

    EXPECT_EQ(19, g.GetFrameScore(0));
    ASSERT_EQ(28, g.GetOverallScore());
}

TEST(RobertMartinScore, PerfectGame) {
    Game g;
    for (int i=0; i<12; i++)
    {
      g.Bowl(10);
    }
    ASSERT_EQ(300, g.GetOverallScore());
}

TEST(RobertMartinScore, EndOfArray) {
    Game g;
    for (int i=0; i<9; i++)
    {
    g.Bowl(0);
    g.Bowl(0);
    }
    g.Bowl(2);
    g.Bowl(8);  //10th frame makes a spare in the first 2 bowls.
    g.Bowl(10); //Last bowl produces a strike.

    ASSERT_EQ(20, g.GetOverallScore());
}

TEST(RobertMartinScore, SampleGame) {
    Game g;
    g.Bowl(1);
    g.Bowl(4);
    g.Bowl(4);
    g.Bowl(5);
    g.Bowl(6);
    g.Bowl(4);
    g.Bowl(5);
    g.Bowl(5);
    g.Bowl(10);
    g.Bowl(0);
    g.Bowl(1);
    g.Bowl(7);
    g.Bowl(3);
    g.Bowl(6);
    g.Bowl(4);
    g.Bowl(10);
    g.Bowl(2);
    g.Bowl(8);
    g.Bowl(6);

    //Test number of balls bowled in each frame and the total number of frames bowled.
    EXPECT_EQ(2, g.GetBallsBowledInFrame(0));
    EXPECT_EQ(2, g.GetBallsBowledInFrame(1));
    EXPECT_EQ(2, g.GetBallsBowledInFrame(2));
    EXPECT_EQ(1, g.GetBallsBowledInFrame(4));
    EXPECT_EQ(2, g.GetBallsBowledInFrame(5));
    EXPECT_EQ(1, g.GetBallsBowledInFrame(8));
    ASSERT_EQ(3, g.GetBallsBowledInFrame(9));

    ASSERT_EQ(10, g.GetFramesBowled());

    //Test individual ball scores. First argument is the frame, second argument is the ball.
    EXPECT_EQ(1, g.GetBallScore(0, 0));
    EXPECT_EQ(4, g.GetBallScore(0, 1));
    EXPECT_EQ(6, g.GetBallScore(2, 0));
    EXPECT_EQ(4, g.GetBallScore(2, 1));
    EXPECT_EQ(10, g.GetBallScore(4, 0));
    EXPECT_EQ(2, g.GetBallScore(9, 0));
    EXPECT_EQ(8, g.GetBallScore(9, 1));
    ASSERT_EQ(6, g.GetBallScore(9, 2));

    //Test frame scores
    EXPECT_EQ(5, g.GetFrameScore(0));
    EXPECT_EQ(29, g.GetFrameScore(2));
    EXPECT_EQ(60, g.GetFrameScore(4));
    ASSERT_EQ(117, g.GetFrameScore(8));

    ASSERT_EQ(133, g.GetOverallScore());
}

TEST(RobertMartinScore, HeartBreak) {
    Game g;
    for (int i=0; i<11; i++)
    {
      g.Bowl(10);
    }
    g.Bowl(9);

    ASSERT_EQ(299, g.GetOverallScore());
}

TEST(RobertMartinScore, TenthFrameSpare) {
    Game g;
    for (int i=0; i<9; i++)
    {
        g.Bowl(10);
    }
    g.Bowl(9);
    g.Bowl(1);
    g.Bowl(1);

    ASSERT_EQ(270, g.GetOverallScore());
}

TEST(RobertMartinScore, FullGame01) {
    TestFullGame(std::vector<int> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 0);
}

TEST(RobertMartinScore, FullGame02) {
    TestFullGame(std::vector<int> {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 20);
}

TEST(RobertMartinScore, FullGame03) {
    TestFullGame(std::vector<int> {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10}, 300);
}

TEST(RobertMartinScore, FullGame04) {
    TestFullGame(std::vector<int> {5,5,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, 16);
}

TEST(RobertMartinScore, FullGame05) {
    TestFullGame(std::vector<int> {10,3,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}, 24);
}

TEST(RobertMartinScore, FullGame06) {
    TestFullGame(std::vector<int> { 10, 3, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 24);
}

TEST(RobertMartinScore, FullGame07) {
    //Tenth frame spare
    TestFullGame(std::vector<int> {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,1 }, 11);
}

TEST(RobertMartinScore, FullGame08) {
  //Tenth frame strike
  TestFullGame(std::vector<int> { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 1, 1 }, 12);
}

TEST(RobertMartinScore, FullGame09) {
    //Example game from katas
    TestFullGame(std::vector<int> { 1, 4, 4, 5, 6, 4, 5, 5, 10, 0, 1, 7, 3, 6, 4, 10, 2, 8, 6 }, 133);
}

void TestFullGame(std::vector<int> balls, int correct_score) {
    Game g;
    std::vector<int> v = balls;

    for (auto b:balls) {
    g.Bowl(b);
    }
    ASSERT_EQ(g.GetOverallScore(), correct_score);
    ASSERT_TRUE(g.IsGameOver());
}
