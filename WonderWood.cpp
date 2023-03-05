#include <iostream>
#include "Entity.h"
#include <time.h>
using namespace std;

int main()
{    
    char Start;

    srand(time(NULL));

    cout << "Welcome to WonderWood! Press [S]tart to play!" << endl;

    cin >> Start;

    while (Start != 'S') {
        cin >> Start;
    }

    int playerhp = rand() % 15 + 1;
    int playerInt = rand() % 8 + 1;
    int playerDefence = rand() % 3 + 1;
    int playerAttack = rand() % 6 + 1;

    Entity Player(playerhp, playerAttack, 0, playerInt, playerhp);

    int lv = 0;

    while(Player.isAlive()) {

        lv++;
        Player.setLevel(lv);        

        if (Player.getLevel() > 1) {

            Player.setHp(Player.getMaxhp() + Player.getLevel());       
            Player.setIntelligence(Player.getIntelligence() + Player.getLevel());
            Player.setDefence(Player.getDefence() + Player.getLevel());
            Player.setAttack(Player.getAttack() + Player.getLevel());
        }
                
        cout << "\n\n\t\tSTATS:" << endl;
        cout << "Player's LV: " << Player.getLevel() << endl;
        cout << "Player's Attack: " << Player.getAttack() << endl;
        cout << "Player's Defence: " << Player.getDefence() << endl;
        cout << "Player's Intelligence: " << Player.getIntelligence() << endl;
        cout << "Player's HP: " << Player.getMaxhp() << endl;

        int enemyhp = rand() % 20 + 1 + Player.getLevel();
        int enemyInt = rand() % 10 + 1 + Player.getLevel();
        int enemyDefence = rand() % 6 + 1 + Player.getLevel();
        int enemyAttack = rand() % 10 + 1 + Player.getLevel();
        
        Entity Enemy(enemyhp, enemyDefence, enemyDefence, 0, enemyhp);

        int dmgDone = 0;
        bool isPlayerTurn = true;

        cout << "\n\nWhile you were walking in the woods you find a strange goblin... He attacks you!" << endl;

        while (Player.isAlive() && Enemy.isAlive() == true) {
            if (isPlayerTurn) {
                cout << "\nPlayer's turn. Chose an action:\n(| [M]elee attack\t| [S]pell attack|\t| [C]harged attack)\n\n|" << endl;
                char choice;
                cin >> choice;

                while ((choice != 'M' && choice != 'S') && (choice != 'C')) {
                    cin >> choice;
                }

                switch (choice) {

                case 'M':
                    cout << "\nPlayer swings its sword!\n" << endl;
                    dmgDone = Player.meleeAttack(Player.getAttack(), Enemy.getDefence());
                    Enemy.setHp(Enemy.getHp() - dmgDone);
                    cout << "Enemy took " << dmgDone << " DMG " << endl;
                    break;

                case 'S':
                    cout << "\nPlayer casts a fireball! It burns!\n" << endl;
                    dmgDone = Player.spellAttack(Player.getAttack(), Enemy.getDefence(), Player.getIntelligence());
                    Enemy.setHp(Enemy.getHp() - dmgDone);
                    cout << "Enemy took " << dmgDone << " DMG " << endl;
                    break;

                case 'C':
                    cout << "\nPlayer charges ahead and smashes into the enemy!\n" << endl;
                    dmgDone = Player.chargedAttack(Player.getAttack(), Enemy.getDefence());
                    Enemy.setHp(Enemy.getHp() - dmgDone);
                    cout << "Enemy took " << dmgDone << " DMG " << endl;
                    break;
                }

                cout << "\nPlayer HP: " << Player.getHp() << " On " << Player.getMaxhp() << endl;
                cout << "\nEnemy HP: " << Enemy.getHp() << " On " << Enemy.getMaxhp() << endl;

                isPlayerTurn = false;

                if (isPlayerTurn == false) {
                    cout << "\n\n\nEnemy's turn..." << endl;
                    int choice = rand() % 3 + 1;

                    switch (choice) {

                    case 1:
                        cout << "\nEnemy swings its sword!\n" << endl;
                        dmgDone = Enemy.meleeAttack(Player.getAttack(), Enemy.getDefence());
                        Player.setHp(Player.getHp() - dmgDone);
                        cout << "Player took " << dmgDone << " DMG " << endl;
                        break;

                    case 2:
                        cout << "\nEnemy casts a fireball! It burns!\n" << endl;
                        dmgDone = Enemy.spellAttack(Enemy.getAttack(), Player.getDefence(), Enemy.getIntelligence());
                        Player.setHp(Player.getHp() - dmgDone);
                        cout << "Player took " << dmgDone << " DMG " << endl;
                        break;

                    case 3:
                        cout << "\nEnemy charges ahead and smashes into the enemy!\n" << endl;
                        dmgDone = Enemy.chargedAttack(Enemy.getAttack(), Player.getDefence());
                        Player.setHp(Player.getHp() - dmgDone);
                        cout << "Player took " << dmgDone << " DMG " << endl;
                        break;
                    }

                    cout << "\nPlayer HP: " << Player.getHp() << " On " << Player.getMaxhp() << endl;
                    cout << "\nEnemy HP: " << Enemy.getHp() << " On " << Enemy.getMaxhp() << endl;
                }

                isPlayerTurn = true;
            }

            if(Enemy.isAlive() == false) {
                cout << "\n\nPlayer Wins! Nice!\n\n";
                cout << "\tLEVEL UP ! \n" << endl;
            }
            if(Player.isAlive() == false) {
                cout << "\n\nEnemy Wins! Better luck next time.\n\n";
            }
            if(Player.isAlive() == false && Enemy.isAlive() == false) {
                cout << "\n\nIt's a draw! (That means you die too, fella :()\n\n";
            }           
        }      
    }
}

