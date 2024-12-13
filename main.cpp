
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

	system("color 1f");
	cout << "is all capitals then its an path you can type." << endl;
	cout << "you are in a small village" << endl;
	cout << "people have been asking for help" << endl;
	cout << "they ask you if you can go the the cave to defeat the giant spider" << endl;
	cout << "you offer to help" << endl;
	cout << "go defeat the ogre you got this." << endl << endl;
	srand(time(NULL)); //seeds your number GEN
	int room = 1;
	string input;
	while (playerhealth > 0) { //game loop
		cout << "Health: " << playerhealth << endl;
		
		cout << endl;
		switch (room) {
		case 1:
			cout << "you are in a small village go North to make your way into the dungeon" << endl;
			getline(cin, input);
			if (input == "north")
				room = 2;
			else if (input == "n")
				room = 2;
			break;
			break;
		case 2:
			cout << "you have made it into the forest, you can go South to go back or West to continue the mission" << endl;
			getline(cin, input);
			if (input == "south")
				room = 1;
			else if (input == "s")
				room = 1;

			else if (input == "west")
				room = 3;
			else if (input == "w")
				room = 3;
			break;
		case 3:
			cout << "you are on the entrance of the dungeon go East to go back or North to go inside" << endl;
			getline(cin, input);
			if (input == "north")
				room = 4;
			else if (input == "n")
				room = 4;
			else if (input == "east")
				room = 2;
			else if (input == "e")
				room = 2;
			break;
		case 4:
			cout << "you find a chest do you want to open it or go north, south" << endl;
			if (input == "open")
				cout << "you found a sword and some armor" << endl;
			if (input == "open")
				cout << "   ////////////|---------------------------------," << endl;
			if (input == "open")
			cout << "   `^^^^^^^^^^^|---------------------------------" << endl;
			inventory[1] = "sword";
			inventory[2] = "armor";

			getline(cin, input);
			if (input == "south")

				room = 3;
			else if (input == "s")
				room = 3;
			else if (input == "north")
				room = 5;
			else if (input == "n")
				room = 5;
			break;
		case 5:
			cout << "you walk in the room and find a ogre blocking your pathway" << endl;
			cout << "Ogre: Fight me if you want to pass" << endl;

			getline(cin, input);
			if (input == "south")
				room = 4;
			
			else if (input == "s")
				room = 4;

			else if (input == "fight")
				BattleSim(), room = 6;
			break;

		case 6:
			cout << "you are now in a dark room you see a bright door east " << endl;
			getline(cin, input);


			if (input == "east")
				room = 7;
			else if (input == "e")
				room = 7;
			break;
		case 7:
			cout << "you are now in a bright room with a chest would you like to open it or go south" << endl;
			getline(cin, input);
			if (input == "west")
				room = 5;
			else if (input == "w")
				room = 5;
			else if (input == "south")
				room = 8;
			else if (input == "s")
				room = 8;
			break;
		case 8:
			cout << "you are now in a creepy room there is a chest open it or go north south" << endl;
			getline(cin, input);
			 if (input == "open")
				cout << "you found a health potion" << endl;
			inventory[3] = "potion";
			 if (input == "north")
				room = 7;
			else if (input == "n")
				room = 7;
			else if (input == "south")
				room = 9;
			else if (input == "s")
				room = 9;
			break;
		case 9:
			cout << "go North, East" << endl;
			getline(cin, input);
			if (input == "north")
				room = 9;
			else if (input == "n")
				room = 9;
			else if (input == "east")
				room = 10;
			else if (input == "e")
				room = 10;

			break;
		case 10:
			cout << "you are in a creepy room full of webs" << endl;
			cout << "As you start to explore the place you find a giant spider" << endl;
			cout << "Fight the giant spider" << endl;
			getline(cin, input);

			if (input == "west")
				room = 9;
			else if (input == "w")
				room = 9;
			else if (input == "fight")
				BossSim();
			break;



		}// end of game loop

	}if (playerhealth <= 0)
		cout << "GAME OVER" << endl;
	else
		cout << "YOU WIN!" << endl;

}

void BattleSim() {
	system("color 40");
	int MonsterHealth = 20; //LOCAL variable: can only be seen and used in this function
	int damage;
	char dummy;
	cout << endl << endl << "---------------------FIGHT ----------------------------" << endl;
	cout << "a Ogre attacked!" << endl;
	while (playerhealth > 0 && MonsterHealth > 0) {
		//player DMG
		damage = rand() % 13 + 5; //number between 0-12
		cout << "You hit the monster for" << " " << damage << " " << "damage" << endl;
		MonsterHealth -= damage;
		cout << "Press any key to continue" << endl;
		cin >> dummy;

		//monster DMG
		damage = rand() % 14 + 3; //number between 0-20
		cout << "The monster hits you for" << " " << damage << " " << "damage" << endl;
		playerhealth -= damage;
		cout << "Press any key to continue" << endl;
		cin >> dummy;

		//value print for health
		if (playerhealth > 0)
			cout << "HP: " << playerhealth << endl;
		else
			cout << "You died" << endl;
		if (MonsterHealth > 0)
			cout << "Monster HP:" << MonsterHealth << endl;
		else
			cout << "You survived" << endl;
		cout << endl;

	} // end of mini loop

	cout << endl << endl << "---------------------BATTLE-FINISH----------------------------" << endl;
	system("color 1f");
}

void BossSim() {
	int BossHealth = 150; //LOCAL variable: can only be seen and used in this function
	int damage;
	char dummy;
	system("color 40");
	system("pause");
	cout << endl << endl << "---------------------FIGHT----------------------------" << endl;
	cout << "The boss looks at you..." << endl;
	while (playerhealth > 0 && BossHealth > 0) {
		//player DMG
		damage = rand() % 11 + 5; //number between 0-10
		cout << "You hit the monster for" << " " << damage << " " << "damage" << endl;
		BossHealth -= damage;
		cout << "Press any key to continue" << endl;
		cin >> dummy;
			//monster DMG
		damage = rand() % 19 + 3; //number between 0-20
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
		system("color 1f");
	} // end of mini loop

	cout << endl << endl << "---------------------BATTLE-FINISH----------------------------" << endl;
}
