//---------------------------------------------------------------------------------------------------------------------------------------------------------------
// Paul Moesher                                                  Lab 8                                                  Due: 3/28/18
//---------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
using namespace std;


	void displayHeading() // This function dispalys the game heading
	{
		cout << setw(40) << "Space Race" << endl << setw(42) << "Paul Moesher" << endl << setw(43) << "CS2010 10:30 MWF" << endl;
		cout << "" << endl; // line for space
		cout << " Move #      Current Position    Card       New Position    Space Bonus" << endl;
	}

	int drawCard() // This function draws a random number (card)
	{
		return rand() % 5 + 1;
	}

	string moveShip(int&current_position, int new_position) // This function calulates the square that the ship moves to.
	{
		if ((current_position + new_position) <= 80) // if the new position is greater then 80 then do not update the position
			current_position += new_position; //New position
			
		string Space_bonus = ""; //Returns nothing unless there is a bonus
		switch (current_position) // Using a switch to change the position and what is displayed if their is a bonus
		{
		case 6: Space_bonus = "Mars Trail";
			current_position = 20;
			break;
		case 10: Space_bonus = "Einstein's WormHole";
			current_position = 24;
			break;
		case 35: Space_bonus = "Leavitt Pass";
			current_position = 40;
			break;
		case 42: Space_bonus = "Milky Way Gap";
			current_position = 52;
			break;
		case 64: Space_bonus = "Tyson Black Hole";
			current_position = 75;
			break;
		}
		return Space_bonus;
		}

	void displayMove(int&current_position, int&counter) // This function displays everything the move number, current position, card number, new position, and space bonus

	{
		cout << right <<setw(5) << counter << setw(17)  << current_position << "\t";
		int moveSquares = drawCard();
		cout << setw(11) << moveSquares << "\t";
		string space_bonus = moveShip(current_position, moveSquares);
		cout << setw(10) << current_position << setw(22) << space_bonus << endl;
		cout << "-----------------------------------------------------------------------------" << endl;
		counter++;
	}



	int main()
	{
		srand(time(NULL));
		int current_position = 1, counter = 1;

		displayHeading();

		while (current_position < 80)
		displayMove(current_position, counter);

		cout << endl;
		system("pause");
		return 0;

	}

	

