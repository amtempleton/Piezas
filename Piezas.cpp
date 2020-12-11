#include "Piezas.h"
#include <vector>
/** CLASS Piezas
 * Class for representing a Piezas vertical board, which is roughly based
 * on the game "Connect Four" where pieces are placed in a column and
 * fall to the bottom of the column, or on top of other pieces already in
 * that column. For an illustration of the board, see:
 *  https://en.wikipedia.org/wiki/Connect_Four
 *
 * Board coordinates [row,col] should match with:
 * [2,0][2,1][2,2][2,3]
 * [1,0][1,1][1,2][1,3]
 * [0,0][0,1][0,2][0,3]
 * So that a piece dropped in column 2 should take [0,2] and the next one
 * dropped in column 2 should take [1,2].
**/


/**
 * Constructor sets an empty board (default 3 rows, 4 columns) and
 * specifies it is X's turn first
**/
Piezas::Piezas()
{
    for(int i =0; i< BOARD_ROWS; i++)
    {
        for(int j = 0; j < BOARD_COLS; j++)
        {
          board[i][j] = Blank;
        }
    }

    turn = X;
}

/**
 * Resets each board location to the Blank Piece value, with a board of the
 * same size as previously specified
**/
void Piezas::reset()
{
  for(int i =0; i< BOARD_ROWS; i++)
  {
      for(int j = 0; j < BOARD_COLS; j++)
      {
        board[i][j] = Blank;
      }
  }
}

/**
 * Places a piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. dropPiece does
 * NOT allow to place a piece in a location where a column is full.
 * In that case, placePiece returns Piece Blank value
 * Out of bounds coordinates return the Piece Invalid value
 * Trying to drop a piece where it cannot be placed loses the player's turn
**/
Piece Piezas::dropPiece(int column)
{

      if(column > 3)
        return Invalid;

      for(int i = 0; i < BOARD_ROWS; i++)
      {
        //drop piece
        if(board[i][column] == Blank)
        {
            board[i][column] = turn;

            //toggle turn
            if(turn == X)
              turn = O;
            else
              turn  = X;

            return board[i][colum];
        }//if
      }//for

      return Blank;
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece Piezas::pieceAt(int row, int column)
{

    if(row > BOARD_ROWS || column > BOARD_COLS)
    {
      return Invalid;
    }
    else
    {
        return board[row][colum];
    }
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won ("tie").
 * For a game to be over, all locations on the board must be filled with X's
 * and O's (i.e. no remaining Blank spaces). The winner is which player has
 * the most adjacent pieces in a single line. Lines can go either vertically
 * or horizontally. If both X's and O's have the same max number of pieces in a
 * line, it is a tie.
**/
Piece Piezas::gameState()
{
    int xcount = 0;
    int ocount = 0;
    int xrowcount = 0;
    int orowcount = 0;
    vector<int> xtotal;
    vector<int> ototal;
    vector<int> xrowtotal;
    vector<int> orowtotal;

    //game not over
    for(int a = 0; a < BOARD_ROWS; a++)
    {
      for(inr b = 0; b < BOARD_COLS; b++)
      {
        if(board[a][b] == Blank)
          return Invalid;
      }
    }

    for(int i = 0; i < BOARD_ROWS; i++)
    {
      //reset
      xcount = 0;
      ocount = 0;

      if(board[i][1] == X){
        xcount++;
        if(board[i][1] == board[i][0])
        {
          xcount++;
        }
        if(board[i][1] == board[i][2])
        {
          xcount++;
        }
        if(board[i][1] == board[i][3])
        {
          xcount++;
        }
      }
      else if(board[i][1] == O){
        ocount++;
        if(board[i][1] == board[i][0])
        {
          ocount++;
        }
        if(board[i][1] == board[i][2])
        {
          ocount++;
        }
        if(board[i][1] == board[i][3])
        {
          ocount++;
        }
      }
      //row counts
      xtotal[i] = xcount;
      ototal[i] = ocount;
    }//for

    for(int k = 0; k < BOARD_COLS; k++)
    {
      xrowcount = 0;
      orowcount = 0;

      if(board[1][k] == X)
      {
        xrowcount++;
        if(board[1][k] == board[0][k]){
          xrowcount++;
        }
        if(board[1][k] == board[2][k])
        {
          xrowcount++;
        }
      }//if
      else if(board[1][k] == O)
      {
        orowcount++;
        if(board[1][k] == board[0][k]){
          orowcount++;
        }
        if(board[1][k] == board[2][k])
        {
          orowcount++;
        }
      }//if
      xrowtotal[k] = xrowcount;
      orowtotal[k] = orowcount;
    }//for

    int total = 0;
    for(int rt = 0; rt < 4; rt++){
      
    }

}
