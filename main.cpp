#include <windows.h>
#include <iostream>
#include <string>


using namespace std;

// VARIABLES
string inventory[10];
int money = 10;
int playerhealth = 100;
bool Boss = false;

// Function declarations
void BattleSim();
void BossSim();

int main() {
    system("color 1f");
    cout << "If it's all caps, then it's a path you can type." << endl;
    cout << "You are in a small village." << endl;
    cout << "People have been asking for help." << endl;
    cout << "They ask you if you can go to the cave to defeat the giant spider." << endl;
    cout << "You offer to help." << endl;
    cout << "Go defeat the ogre, you got this." << endl << endl;

    srand(time(NULL));

    int room = 1;
    string input;

    while (playerhealth > 0) { // Game loop
        cout << "Health: " << playerhealth << endl;
        cout << endl;

        switch (room) {
        case 1:
            cout << "You are in a small village. Go North to make your way into the dungeon." << endl;
            getline(cin, input);
            if (input == "north" || input == "n")
                room = 2;
            break;

        case 2:
            cout << "You have made it into the forest. You can go South to go back or West to continue the mission." << endl;
            getline(cin, input);
            if (input == "south" || input == "s")
                room = 1;
            else if (input == "west" || input == "w")
                room = 3;
            break;

        case 3:
            cout << "You are at the entrance of the dungeon. Go East to go back or North to go inside." << endl;
            getline(cin, input);
            if (input == "north" || input == "n")
                room = 4;
            else if (input == "east" || input == "e")
                room = 2;
            break;

        case 4:
            cout << "You find a chest. Do you want to open it or go north, south?" << endl;
            getline(cin, input);
            if (input == "open") {
                cout << "You found a sword and some armor." << endl;
                inventory[1] = "sword";
                inventory[2] = "armor";
            }
            if (input == "south" || input == "s")
                room = 3;
            else if (input == "north" || input == "n")
                room = 5;
            break;

        case 5:
            cout << "You walk into the room and find an ogre blocking your pathway." << endl;
            cout << "Ogre: Fight me if you want to pass." << endl;
            getline(cin, input);
            if (input == "south" || input == "s")
                room = 4;
            else if (input == "fight")
                BattleSim(), room = 6;
            break;

        case 6:
            cout << "You are now in a dark room. You see a bright door to the east." << endl;
            getline(cin, input);
            if (input == "east" || input == "e")
                room = 7;
            break;

        case 7:
            system("color f0");
            cout << "You are now in a bright room go south" << endl;
            getline(cin, input);
            if (input == "west" || input == "w")
                room = 5;
            else if (input == "south" || input == "s")
                room = 8;
            break;

        case 8:
            system("color 1f");
            cout << "You are now in a creepy room. There is a chest. Open it or go north/south?" << endl;
            getline(cin, input);
            if (input == "open") {
                cout << "You found a health potion." << endl;
                inventory[3] = "potion";
            }
            if (input == "north" || input == "n")
                room = 7;
            else if (input == "south" || input == "s")
                room = 9;
            break;

        case 9:
            cout << "Go North, East." << endl;
            getline(cin, input);
            if (input == "north" || input == "n")
                room = 9;
            else if (input == "east" || input == "e")
                room = 10;
            break;

        case 10:
            cout << "You are in a creepy room full of webs." << endl;
            cout << "As you start to explore, you find a giant spider." << endl;
            cout << "Fight the giant spider." << endl;
            getline(cin, input);
            if (input == "west" || input == "w")
                room = 9;
            else if (input == "fight")
                BossSim(), room = 11;
            break;

        case 11:
            if (Boss) {
                cout << "YOU WIN!" << endl;
                return 0; // Exit the game
            }
            break;
        }
    } // end of game loop

    if (playerhealth <= 0)
        cout << "GAME OVER" << endl;
    else
        cout << "YOU WIN!" << endl;
}

void BattleSim() {
    int MonsterHealth = 50;
    int hit;
    int choice;
    cout << endl << "---------BATTLE----------" << endl;
    while (playerhealth > 0 && MonsterHealth > 0) {
       
        hit = rand() % 8 + 5;
        cout << "The monster hits you and you take " << hit << " dmg" << endl;
        playerhealth -= hit;

        cout << "Press 1 to attack." << endl;
        cin >> choice;

        switch (choice) {
        case 1:
        
            if (inventory[1] == "sword") {
                hit = rand() % 26 + 10; // Hit for 10-35 dmg
                cout << "You slash the monster for " << hit << " dmg" << endl;
                MonsterHealth -= hit;
            }
            else {
                hit = rand() % 11 + 5; // 5-15 dmg
                cout << "You punch the monster for " << hit << " dmg" << endl;
                MonsterHealth -= hit;
            }
            break;
        }

        cout << "HP: " << playerhealth << endl;
        cout << "Monster HP: " << MonsterHealth << endl;
        cout << "-----------------------------------------------------------------------------" << endl;
    }
    system("color 07");
}

void BossSim() {
    int BossHealth = 120;
    int hit;
    int choice;
    system("color 40");
    cout << endl << endl << "---------------------BOSS BATTLE----------------------------" << endl;
    cout << "The boss looks at you..." << endl;
    while (playerhealth > 0 && BossHealth > 0) {
        // Player DMG
      
        hit = rand() % 8 + 5;
        cout << "The monster hits you and you take " << hit << " dmg" << endl;
        playerhealth -= hit;

        cout << "Press 1 to attack." << endl;
        cin >> choice;

        switch (choice) {
        case 1:

            if (inventory[1] == "sword") {
                hit = rand() % 26 + 10; // Hit for 10-35 dmg
                cout << "You slash the monster for " << hit << " dmg" << endl;
                BossHealth -= hit;
            }
            else {
                hit = rand() % 11 + 5; // 5-15 dmg
                cout << "You punch the monster for " << hit << " dmg" << endl;
                BossHealth -= hit;
            }
            break;
        }
        if (playerhealth <= 0) {
            cout << "You died!" << endl;
            break;
        }

        if (BossHealth <= 0) {
            cout << "You defeated the boss!" << endl;
            Boss = true; // Set to true when the boss is defeated
            break;
        }

        cout << "Health: " << playerhealth << endl;
        cout << "Boss Health: " << BossHealth << endl;
        cout << endl;
        system("color 1f");
    }
    cout << endl << "---------------------BATTLE FINISHED----------------------------" << endl;
}
