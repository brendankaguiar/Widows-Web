#include <iostream>
#include <cstdlib> 
#include <ctime>
using namespace std;
const int x = 6;
const int y = 11;

class board
{
private: //Board properties not seen by user, but needed to interact with functions. Private is implicitly applied if type is left out
	char unchanged_board[x][y];//Referenced for updates
	char changing_board[x][y];
	int index; //WHAT IS THIS INDEX FOR?
	int r;
	int c;
	char piece;
	int score1;
	int score2;


public: //public contains functions and must be explicitely typed
	//LABEL PURPOSE OF EACH FUNCTION
	void set_board();//Setup new board from layout
	void get_board();//display unchanged board
	void set_x(int);  // assign's x position
	void set_y(int); // assign's y position
	void set_pieces(int); //sets board and displays changed board
	void move_piece(int, int); //selfexp
	void update_board(); //display changing board
	void spawn(int); //Loads piece to board
	void get_piece(int);//determines piece type
	int spawn_test(int);//
	void tally_score();
	//void determiner(); determines piece typ as well like get piece?


};
void board::set_board()//Setup new board from layout
{
	char layout[x][y] =
	{
	{' ',49,50,51,52,53,54,55,56,57,58},
	{49,' ','|',' ','|',' ',' ','|',' ','|','O'},
	{50,'-','+','-','+','-','-','+','-','+','-'},
	{51,' ','|',' ','|',' ',' ','|',' ','|',' '},
	{52,'-','+','-','+','-','-','+','-','+','-'},
	{53,'O','|',' ','|',' ',' ','|',' ','|',' '}
	};
	for (int i1 = 0; i1 < 6; i1++)
	{
		for (int i2 = 0; i2 < 11; i2++)
			unchanged_board[i1][i2] = layout[i1][i2];
	}
}
void board::get_board() //Display board
{
	for (int i1 = 0; i1 < 6; i1++)
	{
		for (int i2 = 0; i2 < 11; i2++)
		{
			cout << unchanged_board[i1][i2];
		}
		cout << endl;
	}
}

void board::set_pieces(int index) //Changed functionality to set pieces. If I need this to update, later I will add that functionality
{
	if (index == 1) //Might not need
	{
		for (int i1 = 0; i1 < 6; i1++)
		{
			for (int i2 = 0; i2 < 11; i2++)
				changing_board[i1][i2] = unchanged_board[i1][i2];
		}
		changing_board[1][10] = '#';
		changing_board[5][1] = '*';
	}
	else
	{
		cout << "This is the most recent move.\n";
		for (int i1 = 0; i1 < 6; i1++)
		{
			for (int i2 = 0; i2 < 11; i2++)
			{
				cout << changing_board[i1][i2];
			}
			cout << endl;
		};
	}
}
void board::set_x(int row) // assign's x position
{
	r = row;
}
void board::set_y(int col) // assign's y position
{
	c = col;
}
void board::move_piece(int dir, int turn)
{
	if (dir == 8)//Move up
	{
		if (changing_board[r][c] == '#' || changing_board[r][c] == '*') //moves if queen
		{
			int new_r = (r - 1);//Changes to desired position
			changing_board[r][c] = unchanged_board[r][c]; //Replaces location with the board's initial value
			if (turn == 1)
				changing_board[new_r][c] = '#'; // set new queen piece position
			else
				changing_board[new_r][c] = '*'; // set new queen piece position
		}
		else if (changing_board[r][c] == 'x' || changing_board[r][c] == 'y')
		{
			int new_r = (r - 1);
			changing_board[r][c] = unchanged_board[r][c]; //Replaces subscripts with initial value
			if (turn == 1)
				changing_board[new_r][c] = 'x'; // set new queen piece position
			else
				changing_board[new_r][c] = 'y'; // set new queen piece position 
		}
	}
	else if (dir == 4) //Move Left
	{
		if (changing_board[r][c] == '#' || changing_board[r][c] == '*') //moves if queen
		{
			int new_c = (c - 1);//Changes to desired position
			changing_board[r][c] = unchanged_board[r][c]; //Replaces subscripts with initial value
			if (turn == 1)
				changing_board[r][new_c] = '#'; // set new queen piece position
			else
				changing_board[r][new_c] = '*'; // set new queen piece position
		}
		else if (changing_board[r][c] == 'x' || changing_board[r][c] == 'y')
		{
			int new_c = (c - 1);
			changing_board[r][c] = unchanged_board[r][c]; //Replaces subscripts with initial value
			if (turn == 1)
				changing_board[r][new_c] = 'x'; // set new queen piece position
			else
				changing_board[r][new_c] = 'y'; // set new queen piece position 
		}
	}
	else if (dir == 2) //Move Down
	{
		if (changing_board[r][c] == '#') //moves if queen
		{
			int new_r = (r + 1);//Changes to desired position
			changing_board[r][c] = unchanged_board[r][c]; //Replaces subscripts with initial value
			if (turn == 1)
				changing_board[new_r][c] = '#'; // set new queen piece position
			else
				changing_board[new_r][c] = '*'; // set new queen piece position
		}
		else if (changing_board[r][c] == 'x' || changing_board[r][c] == 'y')
		{
			int new_r = (r + 1);
			changing_board[r][c] = unchanged_board[r][c]; //Replaces subscripts with initial value
			if (turn == 1)
				changing_board[new_r][c] = 'x'; // set new queen piece position
			else
				changing_board[new_r][c] = 'y'; // set new queen piece position 
		}
	}
	else if (dir == 6) //Move Right
	{
		if (changing_board[r][c] == '#' || changing_board[r][c] == '*') //moves if queen
		{
			int new_c = (c + 1);//Changes to desired position
			changing_board[r][c] = unchanged_board[r][c]; //Replaces subscripts with initial value
			if (turn == 1)
				changing_board[r][new_c] = '#'; // set new queen piece position
			else
				changing_board[r][new_c] = '*'; // set new queen piece position
		}
		else if (changing_board[r][c] == 'x' || changing_board[r][c] == 'y')
		{
			int new_c = (c + 1);
			changing_board[r][c] = unchanged_board[r][c]; //Replaces subscripts with initial value
			if (turn == 1)
				changing_board[r][new_c] = 'x'; // set new queen piece position
			else
				changing_board[r][new_c] = 'y'; // set new queen piece position 
		}
	}
}
void board::update_board() //might not need if paired with 
{
	for (int i1 = 0; i1 < 6; i1++)
	{
		for (int i2 = 0; i2 < 11; i2++)
			cout << changing_board[i1][i2];
		cout << endl;
	}
}
void board::spawn(int turn)
{
	if (turn == 1)
		changing_board[1][10] = piece;
	else
		changing_board[5][1] = piece;
}
void board::get_piece(int turn)
{
	int coin;
	srand(time(0));
	if (turn == 1)
	{
		coin = rand() % 2 + 1;
		cout << "Tossing the coin\n";
		if (coin == 1)
			piece = '#';
		else
			piece = 'x';
		if (coin == 1)
			cout << "The coin landed on heads. You get a Queen!\n";
		else
			cout << "The coin landed on tails. You get a King.\n";
	}
	else
	{
		coin = rand() % 2 + 1;
		cout << "Tossing the coin!\n";
		if (coin == 1)
			piece = '*';
		else
			piece = 'y';
		if (coin == 1)
			cout << "The coin landed on heads. You get a Queen!\n";
		else
			cout << "The coin landed on tails. You get a King.\n";
	}
}

int board::spawn_test(int turn)
{
	int determiner;
	if (turn == 1)
	{
		if (changing_board[1][10] == '#' || changing_board[1][10] == '*' || changing_board[1][10] == 'y' || changing_board[1][10] == 'x')
			determiner = 0;
		else
			determiner = 1;
	}
	else
	{
		if (changing_board[5][1] == '#' || changing_board[5][1] == '*' || changing_board[5][1] == 'y' || changing_board[5][1] == 'x')
			determiner = 0;
		else
			determiner = 1;
	}
	return determiner;
}

void board::tally_score()
{
	int p1score = 0;
	int p2score = 0;
	int turn = 1;
	if (turn == 1)
	{
		for (int i1 = 0; i1 < 6; i1++)
		{
			for (int i2 = 0; i2 < 11; i2++)
			{
				if (changing_board[i1][i2] == '#')
					p1score += 1;
				else if (changing_board[i1][i2] == 'x')
					p1score += 1;
			}
		};
		turn++;
	}
	if (turn > 1)
	{
		for (int i1 = 0; i1 < 6; i1++)
		{
			for (int i2 = 0; i2 < 11; i2++)
			{
				if (changing_board[i1][i2] == '*')
					p2score += 1;
				else if (changing_board[i1][i2] == 'y')
					p2score += 1;
			}
		};
	}
	cout << "\nPlayer 1 score: " << p1score << "\nPlayer 2 score: " << p2score << endl;
	if (p1score > p2score)
	{
		cout << "Player 1 wins!";
	}
	else if (p2score == p1score)
		cout << "It's a tie.";
	else
		cout << "Player 2 wins!";
}
int main()
{
	board player;
	player.set_board();
	player.get_board();
	int public_index = 1;
	int max_turns; //For 20 turns add 2 to make 22 etc.
	int row;
	int col;
	int dir;
	int turn;
	int reset;
	do
	{
	cout << "\n\t\tDirections\n1.Set up: Each player starts with one queen on opposite corners. Per turn you will either flip a coin or move one space alternatingly.\n";
	cout << "2. Flipping turn: If you flip heads, you get a queen(p1[#] or p2[*]). Tails you get a king(p1[x] or p2[y]) to your den marked by [O]. \nIf your den is occupied, your turn is skipped.\n";
	cout << "3. Moving turn: You can move any one of your pieces up, down, left or right where there is either an adjacent [+],[-], [O], \nor [|] space available per turn. Empty spaces are boundrays.\n";
	cout << "4. The Grid: First select the x coor., hit enter then y coor., hit enter. ':' represents '10'. Use the arrow keys to indicate the direction of the moving piece.\n";
	cout << "5. Attacking: You may attack once per turn, by moving your queen to a space occupied by a king only. Attacks earn you a flipping turn if the den is available.\n";
	cout << "6. Objective: This is a battle and a racing game. Fill up more of the web than your opponent to win. Game is over when the web is full.\nPlayer 1 is # and gets to go first.\n";
	cout << endl << endl << endl << "STARTING NOW!\n";
	cout << "How many turns would you like?";
	cin >> max_turns;
	max_turns += 3;
		do
		{
			if (public_index == 1)
			{
				for (int i = 0; i < 2; i++) //Alternates between player 1 and 2
				{
					turn = (i + 1);//Indicates which player is going through the loop
					player.set_pieces(public_index); //Sets board pieces
					player.update_board();
					cout << "\n\nPlayer " << turn << " select the starting coordinates for the widow you want to move separated by spaces.\n";
					cin >> row >> col;
					player.set_x(row);
					player.set_y(col);
					cout << "\nPlayer " << turn << ", type 4 to move left, 8 for up, 6 for right, 2 for down\n";
					cin >> dir;
					player.move_piece(dir, turn);
					player.update_board();
					public_index++;
				}
			}
			else if (public_index > 1)
			{
				for (int i = 0; i < 2; i++) //Alternates between player 1 and 2
				{
					int choice;
					cout << "Would you like to \n1. Move\n2. Spawn\n3. Attack\n";
					cin >> choice;
					switch (choice) //Classes should eliminate need for this. Further research please
					{
					case 1:
					{
						turn = (i + 1);//Indicates which player is going through the loop
						cout << "\n\nPlayer " << turn << " select coordinates for the widow you want to move.\n";
						cin >> row >> col;
						player.set_x(row);
						player.set_y(col);
						cout << "\nType 4 to move left, 8 for up, 6 for right, 2 for down then type the enter key.\n";
						cin >> dir;
						player.move_piece(dir, turn);
						player.update_board();
						break;
					}
					case 2:
					{
						int determiner;
						turn = (i + 1);
						determiner = player.spawn_test(turn);
						if (determiner == 1)
						{
							player.get_piece(turn);
							player.spawn(turn);
							player.update_board();
						}
						else
							cout << "\nThe den is occupied. Lose a turn.\n";
						break;
					}
					case 3:
					{
						turn = (i + 1);
						cout << "\n\n\t\tPlayer " << (i + 1) << " select your attacking widow's coordinates separated by spaces.\n";
						cin >> row >> col;
						player.set_x(row);
						player.set_y(col);
						cout << "\nFor attacking direction, type 4 for left, 8 for up, 6 for right, 2 for down\n";
						cin >> dir;
						player.move_piece(dir, turn);
						int determiner;
						determiner = player.spawn_test(turn);
						if (determiner == 1)
						{
							player.get_piece(turn);
							player.spawn(turn);
							player.update_board();
						}
						else
							cout << "\nThe den is occupied. You cannot spawn a widow.\n";
						break;
					}
					}
				}
			}
			public_index++;
		} while (public_index < max_turns);
		cout << "\nThe game is now over. Tallying up pieces now.\n";
		player.tally_score();
		cout << "\nWould you like to play again? Type 1 for yes and press the enter key.\n";
		cin >> reset;
		if (reset == 1)
			public_index = 1;
	} while (reset == 1);
	system("PAUSE");
	return 0;
}