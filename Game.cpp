#include "Game.h"

class vector1 : std::vector<int>
{
	virtual void signal() {};
	
	void change(int index, int value)
	{
		std::vector<int>::at(index) = value;
		signal();
	}

	int& at(int index) {
		signal();
		return std::vector<int>::at(index);
	}
};

class vector2: vector1
{
	void signal() override
	{
		
	}
};

Game::Game()
{
	while(m_game_continues)
	{
		printBoard(false);
		collect();
		sow();
		capture();
		checkGameStatus();
	}
	announceWinner();
}

void Game::printBoard(bool wait) // TODO: add this as onChange m_holes vector handler
{
	system("cls");
	cout << endl;
	printNumbers(Color::blue);
	
	for(auto i = 0; i < 11; i++)
	{
		printPlayerHole(Color::green, i, m_south_score);
		printHoles(i);
		printPlayerHole(Color::blue, i,m_north_score);
		
		cout << endl;
	}
	printNumbers(Color::green);
	if(wait)
		this_thread::sleep_for(chrono::milliseconds(500)); // wait for 0.5sec to recognize changes by eye
	if (!m_error_message.empty())
		printWithColor(m_error_message, Color::red, true);
}

void Game::collect()
{	
	cout << "Player " << ((m_active_player == Player::south) ? "South (green)" : "North (blue)") << " is on a move." << endl;
	cout << "Enter hole number to collect: ";
	cin >> m_hole_index_to_collect;

	if (m_active_player == Player::south)
		m_hole_index_to_collect--;
	else
		m_hole_index_to_collect = 12 - m_hole_index_to_collect;

	if (m_holes.at(m_hole_index_to_collect) != 0) // player is collecting from hole with seeds
	{
		m_seeds_collected = m_holes.at(m_hole_index_to_collect);
		m_holes.at(m_hole_index_to_collect) = 0;
		printBoard();
	}
	else if (m_holes.at(m_hole_index_to_collect) != 0) // player is collecting from hole without seeds
	{
		m_error_message = "You cannot collect seeds from empty hole! Choose another hole.";
		printBoard();
		collect();
	}
	
}

void Game::sow()
{
	int index = m_hole_index_to_collect;
	int sowed_seed_counter = 0;
	
	while(sowed_seed_counter != m_seeds_collected) // while number of sowed seeds is not equal to number of collected seeds
	{
		index = (index + 1) % 12; // modulo 12 because when I am on the end of vector I want to start again
		if (index != m_hole_index_to_collect) // don't show to the same hole that has been collected
		{
			sowed_seed_counter++;
			m_holes.at(index)++;
			printBoard();
		}
	}
}

void Game::capture()
{
	int index = (m_hole_index_to_collect + m_seeds_collected) % 12;
	
	while(
		(m_holes.at(index) == 2 || m_holes.at(index) == 3) &&       // capture seeds only in case there are 2 or 3 of them
		((m_active_player == south && 11 >= index && index >= 6) || // capture seeds just from opponent side
		(m_active_player == north && 5 >= index && index >= 0)))    
		{
		if(m_active_player == south)
			m_south_score += m_holes.at(index);
		else
			m_north_score += m_holes.at(index);
		m_holes.at(index) = 0;

		index--;
	}
}

void Game::checkGameStatus()
{
	if (m_south_score > 24 || m_north_score > 24)
		m_game_continues = false;
	changePlayer();
}

void Game::changePlayer()
{
	if (m_active_player == south)
		m_active_player = north;
	else
		m_active_player = south;
}

void Game::announceWinner()
{
	if (m_south_score > m_north_score)
		cout << "South player won. Congratulation." << endl;
	else if (m_south_score < m_north_score)
		cout << "North player won. Congratulation." << endl;
	else
		cout << "Game ended as a draw. Good game." << endl;
}


void Game::printWithColor(string text, Color color, bool end)
{
	if(text.find_first_not_of(' ') == string::npos)
	{
		switch (color)
		{
		case blue:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 144);
			break;
		case red:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);
			break;
		case green:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 160);
			break;
		default:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		}
	}
	else
	{
		switch (color)
		{
		case blue:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
			break;
		case red:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 41);
			break;
		case green:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
			break;
		default:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
		}
	}

	if (end)
		cout << text << endl;
	else
		cout << text;
}

void Game::printPlayerHole(Color color, int row, int value)
{
	if (row == 0 || row == 10)
	{
		printWithColor("   ");
		printWithColor("      ", color);
		printWithColor("    ");
	}
	else 
	{
		printWithColor(" ");
		printWithColor("  ", color);
		if (row == 5)
		{
			printWithColor("  ");
			printWithColor((value > 9) ? to_string(value) : "0" + to_string(value), color);
			printWithColor("  ");
		}
		else
		{
			printWithColor("      ");
		}
		printWithColor("  ", color);
		printWithColor("  ");
	}
}

void Game::printHoles(int row)
{
	Color color = (row < 5) ? blue : green;
	int index;
	
	for(int j = 0; j < 6; j++)
	{
		index = (row < 5) ? m_holes.size() - j - 1 : j;
		
		if (row == 0 || row == 4 || row == 6 || row == 10)
		{
			printWithColor("  ");
			printWithColor("      ", color);
			printWithColor("  ");
		}
		else if (row == 5)
			printWithColor("          ");
		else
		{
			printWithColor("  ", color);
			printWithColor("  ");
			if(row == 2 || row == 8)
				printWithColor((m_holes.at(index) < 10) ? "0" + to_string(m_holes.at(index)) : to_string(m_holes.at(index)), color);
			else
				printWithColor("  ");
			printWithColor("  ");
			printWithColor("  ", color);
		}
		printWithColor(" ");
	}
}

void Game::printNumbers(Color color)
{
	printWithColor("             ");

	for(int i = 0; i < 6; i++)
	{
		printWithColor("    ");
		printWithColor("#" + to_string(i + 1), color);
		printWithColor("     ");
	}
	cout << endl;
}
