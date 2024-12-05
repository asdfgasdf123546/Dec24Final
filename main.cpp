#include<iostream>
using namespace std;
string inventory[10];
int PlayerHealth = 100;


int main() {
	int room = 1;
	string   input;
	while (input != "quit") {

		cout << "your inventory: ";
		for (int i = 0; i < 10; i++)
			cout << inventory[i] << " ";
		cout << endl << endl;


		cout << " your health: " << PlayerHealth << endl << endl;
		switch (room) {
		case 1:

			cout << "make sure to use all lower capitals, and if the word" << endl;
			cout << "is all capitals then its an path you can type." << endl;	
			cout << "you are in a small village" << endl;
			cout << "people have been asking for help" << endl;
			cout << "they ask you if you can go the the dungeon to defeat the ogre" << endl;
			cout << "you offer to help" << endl;
			cout << "go defeat the ogre youvgot this" << endl;
			cin >> input;
			cout << "" << endl;
			inventory[0] = "";
			cout << "you are in teh small village go North to make your way into the dungeon" << endl;
			cin >> input;
			if (input == "north")
				room = 2;
			break;
		case 2:
			cout << "you have made it into the forest, you can go west to go back or, north to continue the mission" << endl;
			cin >> input;
			if (input == "west")
				room = 1;
			if (input == "north")
				room = 3;
			break;
		case 3:
			cout << ", you can go North, East" << endl;
			cin >> input;
			if (input == "North")
				room = 4;
			else if (input == "East")
				room = 2;
			break;
		case 4:
			cout << "you picked up a sword" << endl;
			inventory[1] = "sword";
			cout << "you're in room 4, you can go south, North" << endl;
			cin >> input;
			if (input == "south")
				room = 3;
			else if (input == "North")
				room = 5;
			break;
		case 5:	
			cout << "you're in room 5, you can go south, East" << endl;
			cin >> input;
			if (input == "south")
				room = 3;
			else if (input == "East")
				room = 6;
			break;
		case 6:
			cout << "you're in room 6, you can go West, East" << endl;
			cin >> input;
			if (input == "West")
				room = 5;
			else if (input == "East")
				room = 7;
			break;
		case 7:
			cout << "you're in room 7, you can go West, South" << endl;
			cin >> input;
			if (input == "West")
				room = 5;
			else if (input == "South")
				room = 8;
			break;
		case 8:
				cout << "you're in room 8, you can go North, South" << endl;
				cin >> input;
				if (input == "North")
					room = 7;
				else if (input == "South")
					room = 9;
				break;
		case 9:
			cout << "you're in room 9, you can go North, East" << endl;
			cin >> input;
			if (input == "North")
				room = 5;
			else if (input == "East")
				room = 10;
			break;
		case 10:
			cout << "you're in room 10, you can" << endl;
			cin >> input;
			
		 if (input == "west")
				room = 10;
			break;





		}

	}





}


