#include<iostream>
using namespace std;
//VARIABLE IS GLOBAL
//inventory using array
string inventory[10];
int money = 10;
int playerHealth = 100;
//function declaration
void BattleSim();

int main() {
	cout << "is all capitals then its an path you can type." << endl;
	cout << "you are in a small village" << endl;
	cout << "people have been asking for help" << endl;
	cout << "they ask you if you can go the the dungeon to defeat the ogre" << endl;
	cout << "you offer to help" << endl;
	cout << "go defeat the ogre you got this" << endl;
	srand(time(NULL)); //seeds your number GEN
	int room = 1;
	string input;
	while (playerHealth > 0) { //game loop

		switch (room) {
		case 1:
			cout << "you are in a small village go North to make your way into the dungeon" << endl;
			cin >> input;
			if (input == "north")
				room = 2;

			break;
			break;
		case 2:
			cout << "you have made it into the forest, you can go west to go back or north to continue the mission" << endl;
			cin >> input;
			if (input == "west")
				room = 1;
			if (input == "north")
				room = 3;
			break;
		case 3:
			cout << ", you can go North, East" << endl;
			cin >> input;
			if (input == "north")
				room = 4;
			else if (input == "east")
				room = 2;
			break;
		case 4:
			cout << "you find a chest you open it and find a sword you picked up a sword" << endl;
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
			else if (input == "east")
				room = 6;
			break;
		case 6:
			cout << "you're in room 6, you can go West, East" << endl;
			cin >> input;
			if (input == "west")
				room = 5;
			else if (input == "east")
				room = 7;
			break;
		case 7:
			cout << "you're in room 7, you can go West, South" << endl;
			cin >> input;
			if (input == "west")
				room = 5;
			else if (input == "south")
				room = 8;
			break;
		case 8:
			cout << "you're in room 8, you can go North, South" << endl;
			cin >> input;
			if (input == "north")
				room = 7;
			else if (input == "south")
				room = 9;
			break;
		case 9:
			cout << "you're in room 9, you can go North, East" << endl;
			cin >> input;
			if (input == "north")
				room = 9;
			else if (input == "east")
				room = 10;
			break;
		case 10:
			cout << "you're in room 10, you can" << endl;
			cin >> input;

			if (input == "west")
				room = 10;
			break;



		}// end of game loop

	}if (playerHealth <= 0)
		cout << "GAME OVER" << endl;
	else
		cout << "YOU WIN!" << endl;

}

void BattleSim() {
	int MonsterHealth = 20; //LOCAL variable: can only be seen and used in this function
	int damage;
	char dummy;
	cout << endl << endl << "---------------------ENCOUNTER----------------------------" << endl;
	cout << "an orge attacked!" << endl;
	while (playerHealth > 0 && MonsterHealth > 0) {
		//player DMG
		damage = rand() % 11 + 5; //number between 0-10
		cout << "You hit the monster for" << " " << damage << " " << "damage" << endl;
		MonsterHealth -= damage;
		cout << "Press any key to continue" << endl;
		cin >> dummy;

		//monster DMG
		damage = rand() % 21 + 3; //number between 0-20
		cout << "The monster hits you for" << " " << damage << " " << "damage" << endl;
		playerHealth -= damage;
		cout << "Press any key to continue" << endl;
		cin >> dummy;


		//value print for health
		if (playerHealth > 0)
			cout << "HP: " << playerHealth << endl;
		else
			cout << "You died" << endl;
		if (MonsterHealth > 0)
			cout << "Monster HP:" << MonsterHealth << endl;
		else
			cout << "You survived" << endl;
		cout << endl;

	} // end of mini loop

	cout << endl << endl << "---------------------BATTLE-FINISH----------------------------" << endl;

}

