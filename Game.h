#ifndef GAME
#define GAME

#include <chrono>
#include <iostream>
#include <string>
#include <thread>        
#include <vector>
#include <windows.h>

using namespace std;

enum Player { south, north };
enum Color { red, green, blue, black};

class Game
{
private:
	int m_north_score = 0;
	int m_south_score = 0;
	vector<int> m_holes = vector<int>(12, 4);
	// vector<int> m_holes = vector<int>{30,2,2,2,2,2,2,2,2,2,2,2}; // TODO: remove this line, it is just for testing
	bool m_game_continues = true;
	Player m_active_player = south;
	int m_hole_index_to_collect;
	int m_seeds_collected;

	void printBoard(bool wait = true);
	void collect();
	void sow();
	void capture();
	void checkGameStatus();
	void changePlayer();
	void printWithColor(string text, Color color = black, bool end = false);
	void printPlayerHole(Color color, int row, int value);
	void printHoles(int row);
	void printNumbers(Color color);

public:
	Game();
};

#endif
