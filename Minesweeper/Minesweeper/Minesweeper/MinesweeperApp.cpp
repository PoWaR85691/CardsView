#include "MinesweeperApp.h"
#include <stdexcept>
#include <sstream>

MinesweeperApp::MinesweeperApp(int height, int width, int mines)
{
	reset(height, width, mines);
}

bool MinesweeperApp::reset(int height, int width, int mines)
{
	fieldHeight = height;
	fieldWidth = width;
	this->mines = mines;

	turn = 0;

	if ((height < 0) || (width < 0) || 
		(mines < 0) || !(mines < height*width)) 
	{
		gameState = S_ERROR;
		return false;
	}

	mineField.resize(height*width, false);
	gameField.resize(height*width, GF_CLOSED);

	return true;
}

MinesweeperApp::operator bool() const
{
	return isPlaying();
}

bool MinesweeperApp::isError() const
{
	return (gameState == S_ERROR);
}

bool MinesweeperApp::isPlaying() const
{
	return (gameState == S_PLAYING);
}

bool MinesweeperApp::isGameOver() const
{
	return !isPlaying();
}

bool MinesweeperApp::isWin() const
{
	return (gameState == S_WIN);
}

bool MinesweeperApp::isFail() const
{
	return (gameState == S_FAIL);
}


bool MinesweeperApp::isMine(int i, int j) const
{
	if ((i < 0) || (i >= fieldHeight) ||
		(j < 0) || (j >= fieldWidth))
	{
		std::ostringstream str;
		str << "Tile [" << i << ", " << j << "] is out of field [" << fieldHeight << ", " << fieldWidth << "]";
		throw std::out_of_range(str.str());
	}
	return mineField[i*fieldWidth + j];
}

int MinesweeperApp::getFieldTile(int i, int j) const
{
	if ((i < 0) || (i >= fieldHeight) ||
		(j < 0) || (j >= fieldWidth))
	{
		std::ostringstream str;
		str << "Tile [" << i << ", " << j << "] is out of field [" << fieldHeight << ", " << fieldWidth << "]";
		throw std::out_of_range(str.str());
	}
	return gameField[i*fieldWidth + j];
}

void MinesweeperApp::getFieldSize(int& height, int& width) const
{
	height = fieldHeight;
	width = fieldWidth;
}


int MinesweeperApp::getTurn() const
{
	return turn;
}


bool MinesweeperApp::makeTurn(int i, int j)
{

}

bool MinesweeperApp::setFlag(int i, int j)
{
	
}
