/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
#include <string>
using namespace std;

class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

//Test for empty board should return Invalid
TEST(PiezasTest, resetBoard)
{
  Piezas board;
  board.reset();
  Piece res = board.gameState();
	ASSERT_EQ(res, Invalid);
}

//Test to see if constructor sets empty board, should return Invalid
TEST(PiezasTest, blankBoard)
{
  Piezas board;
  Piece res = board.gameState();
	ASSERT_EQ(res, Invalid);
}

//Test to dropPiece, column is greater than 3 should return Invalid
TEST(PiezasTest, invalidColumn)
{
  Piezas board;
  Piece res = board.dropPiece(4);
	ASSERT_EQ(res, Invalid);
}

//Test to see if we can drop a piece should return with same input
TEST(PiezasTest, dropPieceTest)
{
  Piezas board;
  Piece res = board.dropPiece(3);
	ASSERT_EQ(res, X);
}

//Test to see if droping a piece in a full column will return blankBoard
TEST(PiezasTest, DontDropPiece)
{
  Piezas board;
  board.dropPiece(3);
  board.dropPiece(3);
  board.dropPiece(3);
  Piece res = board.dropPiece(3);
	ASSERT_EQ(res, Blank);
}

//Test to see if dropPiece is toggling turns, return with O
TEST(PiezasTest, ToggleTurnDropPiece)
{
  Piezas board;
  board.dropPiece(3);
  Piece res = board.dropPiece(3);
	ASSERT_EQ(res, O);
}

//Test pieceAt for out of bound row, should return Invalid
TEST(PiezasTest, outOfBoundRow)
{
  Piezas board;
  Piece res = board.pieceAt(3,3);
	ASSERT_EQ(res, Invalid);
}

//Test pieceAt for out of bound row, should return Invalid
TEST(PiezasTest, outOfBoundRowNeg)
{
  Piezas board;
  Piece res = board.pieceAt(-1,3);
	ASSERT_EQ(res, Invalid);
}

//Test pieceAt for out of bound column, should return Invalid
TEST(PiezasTest, outOfBoundCol)
{
  Piezas board;
  Piece res = board.pieceAt(2,4);
	ASSERT_EQ(res, Invalid);
}

//Test pieceAt for out of bound column, should return Invalid
TEST(PiezasTest, outOfBoundColNeg)
{
  Piezas board;
  Piece res = board.pieceAt(2,-1);
	ASSERT_EQ(res, Invalid);
}

//Test pieceAt for piece, should return X
TEST(PiezasTest, pieceAtX)
{
  Piezas board;
  board.dropPiece(3);
  Piece res = board.pieceAt(0,3);
	ASSERT_EQ(res, X);
}

//Test pieceAt for piece, should return O
TEST(PiezasTest, pieceAtO)
{
  Piezas board;
  board.dropPiece(3);
  board.dropPiece(3);
  Piece res = board.pieceAt(1,3);
	ASSERT_EQ(res, O);
}

//Test pieceAt for empty spot, should return Blank
TEST(PiezasTest, pieceAtEmpty)
{
  Piezas board;
  Piece res = board.pieceAt(1,3);
	ASSERT_EQ(res, Blank);
}

//Test gameState, return tie
TEST(PiezasTest, gameStateInvalid)
{
  Piezas newGame;
            /*{X, O, X, O},
              {X, O, X, O},
              {X, O, X, O}*/

  newGame.dropPiece(0);//X
  newGame.dropPiece(1);//O
  newGame.dropPiece(0);//X
  newGame.dropPiece(1);//O
  newGame.dropPiece(0);//X
  newGame.dropPiece(1);//O
  newGame.dropPiece(2);//X
  newGame.dropPiece(3);//O
  newGame.dropPiece(2);//X
  newGame.dropPiece(3);//O
  newGame.dropPiece(2);//X
  newGame.dropPiece(3);//O

  Piece res = newGame.gameState();
	ASSERT_EQ(res, Invalid);
}

//Test gameState, return X
TEST(PiezasTest, gameStateX)
{
  Piezas newGame;
            /*{O, O, X, O},
              {O, O, X, O},
              {X, X, X, X}*/

  newGame.dropPiece(0);//X
  newGame.dropPiece(0);//O
  newGame.dropPiece(1);//X
  newGame.dropPiece(1);//O
  newGame.dropPiece(2);//X
  newGame.dropPiece(0);//O
  newGame.dropPiece(3);//X
  newGame.dropPiece(1);//O
  newGame.dropPiece(2);//X
  newGame.dropPiece(3);//O
  newGame.dropPiece(2);//X
  newGame.dropPiece(3);//O

  Piece res = newGame.gameState();
	ASSERT_EQ(res, O);
}

//Test gameState, return O
TEST(PiezasTest, gameStateO)
{
  Piezas newGame;

            /*{X, O, X, X},
              {O, X, X, O},
              {X, O, O, O}*/

  newGame.dropPiece(0);//X
  newGame.dropPiece(1);//O
  newGame.dropPiece(1);//X
  newGame.dropPiece(2);//O
  newGame.dropPiece(2);//X
  newGame.dropPiece(3);//O
  newGame.dropPiece(2);//X
  newGame.dropPiece(3);//O
  newGame.dropPiece(3);//X
  newGame.dropPiece(0);//O
  newGame.dropPiece(0);//X
  newGame.dropPiece(1);//O

  Piece res = newGame.gameState();
	ASSERT_EQ(res, O);
}
