#include<iostream>
#include<string>

using namespace std;

//VARIABLE IS GLOBAL
//inventory using array
string inventory[10];
int money = 10;
int playerhealth = 100;
//function declaration
void BattleSim();
void BossSim();

int main() {
	cout << "is all capitals then its an path you can type." << endl;
	cout << "you are in a small village" << endl;
	cout << "people have been asking for help" << endl;
	cout << "they ask you if you can go the the cave to defeat the dragon" << endl;
	cout << "you offer to help" << endl;
	cout << "go defeat the ogre you got this." << endl << endl;
	srand(time(NULL)); //seeds your number GEN
	int room = 1;
	string input;
	while (playerhealth > 0) { //game loop

		switch (room) {
		case 1:
			cout << "you are in a small village go North to make your way into the dungeon" << endl;
			getline(cin, input);
			if (input == "north")
				room = 2;

			break;
			break;
		case 2:
			cout << "you have made it into the forest, you can go South to go back or West to continue the mission" << endl;
			getline(cin, input);
			if (input == "south")
				room = 1;
			if (input == "west")
				room = 3;
			break;
		case 3:
			cout << ", you are on the entrance of the dungeon go East to go back or North to go inside" << endl;
			getline(cin, input);
			if (input == "north")
				room = 4;
			else if (input == "east")
				room = 2;
			break;
		case 4:
			cout << "you find a chest you open it and find a sword you picked up a sword" << endl;
			cout << "         /| ________________" << endl;
			cout << "O |= ==|* > ________________ >" << endl;
			cout << "           | " << endl;
			inventory[1] = "sword";
			cout << "you're in room 4, you can go south, North" << endl;
			getline(cin, input);
			if (input == "south")
				room = 3;
			else if (input == "North")
				room = 5;
			break;
		case 5:
			cout << "you're in room 5, you can go south, East" << endl;
			getline(cin, input);
			if (input == "south")
				room = 3;
			else if (input == "east")
				room = 6;
			break;
		case 6:
			cout << "you're in room 6, you can go West, East" << endl;
			getline(cin, input);
			if (input == "west")
				room = 5;
			else if (input == "east")
				room = 7;
			break;
		case 7:
			cout << "you're in room 7, you can go West, South" << endl;
			getline(cin, input);
			if (input == "west")
				room = 5;
			else if (input == "south")
				room = 8;
			break;
		case 8:
			cout << "you're in room 8, you can go North, South" << endl;
			getline(cin, input);
			if (input == "north")
				room = 7;
			else if (input == "south")
				room = 9;
			break;
		case 9:
			cout << "you're in room 9, you can go North, East" << endl;
			getline(cin, input);
			if (input == "north")
				room = 9;
			else if (input == "east")
				room = 10;
			break;
		case 10:
			cout << "you're in room 10, you can" << endl;
			getline(cin, input);

			if (input == "west")
				room = 9;
			break;



		}// end of game loop

	}if (playerhealth <= 0)
		cout << "GAME OVER" << endl;
	else
		cout << "YOU WIN!" << endl;

}

void BattleSim() {

	int monsterhealth = 20;
	int hit;
	int choice;
	cout << endl << " -----------battle--------------" << endl;
	while (playerhealth > 0 && monsterhealth > 0) {
		cout << "press 1 to attack, 2 to use health potion, 3 to try to escape!" << endl;
		cin >> choice;
		switch (choice) {
		case 1:
			if (inventory[1] == "armor") {
				hit = rand() % 5 + 2;
				cout << "the armor protects you and the monster bites you for only" << hit << " dmg" << endl;
				playerhealth -= hit;
			}
			else {
				hit = rand() % 15 + 12;
				cout << "the monster bite into your bare skin" << hit << " dmg" << endl;
				playerhealth -= hit;

				if (inventory[0] == "sword") {
					hit = rand() % 11 + 10;
					cout << "you slash the monster for" << hit << " dmg" << endl;
					monsterhealth -= hit;
				}
				else {
					hit = rand() % 5 + 2;
					cout << "you punch the monster for" << hit << " dmg" << endl;
					monsterhealth -= hit;


				}
				break;
		case 2:
			if (inventory[2] == "potion") {
				if (playerhealth < 50)
					cout << "glug glug" << endl;
				inventory[2] = " ";
				playerhealth += 30;
			}
			else cout << "sorry you dont have a health potion!" << endl;

			break;
		case 3:
			hit + rand() % 100;
			if (hit > 50) {
				cout << "you successfully escape!" << endl;
				monsterhealth = 0;


			}
			else cout << "you where unable to escape" << endl;
			break;
			}

			cout << "playerhealth is now " << playerhealth << endl;
			cout << "monster health is now " << monsterhealth << endl;


		}

		cout << "-----------------------------------" << endl;
	}
}
void BossSim() {
	int BossHealth = 100; //LOCAL variable: can only be seen and used in this function
	int damage;
	char dummy;
	system("color FF");
	system("pause");
	cout << endl << endl << "---------------------ENCOUNTER----------------------------" << endl;
	cout << "The boss looks at you..." << endl;
	while (playerhealth > 0 && BossHealth > 0) {
		//player DMG
		damage = rand() % 11 + 5; //number between 0-10
		cout << "You hit the monster for" << " " << damage << " " << "damage" << endl;
		BossHealth -= damage;
		cout << "Press any key to continue" << endl;
		cin >> dummy;

		//monster DMG
		damage = rand() % 21 + 3; //number between 0-20
		cout << "The monster hits you for" << " " << damage << " " << "damage" << endl;
		playerhealth -= damage;
		cout << "Press any key to continue" << endl;
		cin >> dummy;


		//value print for health
		if (playerhealth > 0)
			cout << "HP: " << playerhealth << endl;
		else
			cout << "You died" << endl;
		if (BossHealth > 0)
			cout << "Boss HP:" << BossHealth << endl;
		else
			cout << "You survived" << endl;
		cout << endl;

	} // end of mini loop

	cout << endl << endl << "---------------------BATTLE-FINISH----------------------------" << endl;

}


