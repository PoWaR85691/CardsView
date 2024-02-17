#pragma once
#include <vector>

class MinesweeperApp
{
private:
	enum GameState
	{
		S_ERROR,
		S_PLAYING,
		S_WIN,
		S_FAIL
	};

	GameState gameState;
	int mines;
	int turn;

	int fieldHeight, fieldWidth;
	std::vector<bool> mineField;
	std::vector<int> gameField;
public:
	const int GF_CLOSED = -1, GF_FLAG = -2;

	MinesweeperApp(int height, int width, int mines);
	bool reset(int height, int width, int mines);

	operator bool() const;
	bool isError() const;
	bool isPlaying() const;
	bool isGameOver() const;
	bool isWin() const;
	bool isFail() const;

	bool isMine(int i, int j) const;
	int getFieldTile(int i, int j) const;
	void getFieldSize(int &height, int &width) const;

	int getTurn() const;

	bool makeTurn(int i, int j);
	bool setFlag(int i, int j);
};

