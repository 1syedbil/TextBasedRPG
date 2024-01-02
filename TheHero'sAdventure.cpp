#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctime> //included this so that srand(time(NULL)) would work

#pragma warning(disable: 4996)

//prototypes
int clearWithEnter(void);
int getNum(void);
int gameOver(void);
void characterCreator(struct character* player); 
void randEncounter(struct enemy* monster, struct character* player, struct weapon* weapon);   
void battle(struct enemy monster, struct character player, struct weapon weapon);  

const int stringArraySize = 50;

const int counter = 0;

const int quitProg = -1; 

const int returnVal = 1; 

const int MAXhp = 100;

const int T1spd = 30;

const int T2spd = 60;

const int T3spd = 45; 

const int T1strn = 30;

const int T2strn = 60;

const int T3strn = 45;

const int T1agl = 30;

const int T2agl = 60;

const int T3agl = 45; 

const int t1ProbRange = 250;

const int t2ProbRange = 500;

const int t3ProbRange = 750;

const int t4ProbRange = 999; 

struct character 
{
	char name[stringArraySize];
	int health;
	int strength;
	int speed;
	int agility;
};

struct consumableItem 
{
	int regen;
	int posion;
	int strnUp;
	int spdUp;
	int aglUp;
};

struct attack
{
	char name[stringArraySize];
	int dmg;
	int strnReq;
	int spdReq;
};

struct enemy
{
	char name[stringArraySize];
	int health;
	int strength;
	int speed;
	struct attack attack1;
	struct attack attack2;
};

typedef struct enemy Enemy;

struct weapon
{
	char name[stringArraySize];
	int defense;
	struct attack attack1;
	struct attack attack2;
	struct attack attack3;
};

typedef struct weapon Weapon; 

const Enemy t1 = { "Troll", MAXhp, 70, 25, {"Strong Kick", 30, 10, 5}, {"Strong Punch", 30, 10, 5}}; 

const Enemy t2 = { "Ogre", MAXhp, 60, 25, {"Regular Kick", 20, 10, 5}, {"Regular Punch", 20, 10, 5}}; 

const Enemy t3 = { "Goblin", MAXhp, 30, 40, {"Regular Shove", 10, 5, 10}, {"Regular Stab", 12, 5, 10}}; 

const Enemy t4 = { "Witch", MAXhp, 20, 35, {"Regular Spell", 12, 1, 7}, {"Weak Spell", 5, 1, 7}};

const Weapon strtSwrd = { "Reg Sword", 10, {"Reg Slash", 10, 5, 3}, {"Strg Slash", 20, 7, 2}, {"Wk Slas", 5, 3, 4} }; 

const Weapon strtSpr = { "Reg Spear", 10, {"Reg Pierce", 10, 3, 5}, {"Strg Pierce", 20, 2, 7}, {"Wk Pierce", 5, 4, 3} };

const Weapon strtShld = { "Reg Shield", 20, {"Reg Charge", 7, 2, 2}, {"Strg Charge", 14, 4, 4}, {"Wk Charge", 3, 1, 1} };

int main(void)
{
	printf("Welcome to... The Hero's Adventure!\n");

	clearWithEnter();

	printf("Would you like to start a new game?\n\t1. Start New Game\n\t2. Quit\nEnter the number corresponding with your decision.\n");

	int decision = getNum();

	if (decision == 1)
	{
		system("cls");
	}
	else
	{
		return quitProg;   
	}

	printf("This is story that takes place in a kingdom from a time long forgotten and a land far far away...\n");

	clearWithEnter();

	printf("You suddenly awake in a room resembling a large monestary or a chapel...\nThe sun shines down on you from a tall stained glass window.\n");

	clearWithEnter();

	printf("A member of this monestary walks up to you and speaks to you in a soft and kind voice...\n\n\"Welcome great hero. May I know thy name?...\"\n"); 

	clearWithEnter();

	printf("Create your character...\n\nEnter your character name: ");

	struct character player = {};

	characterCreator(&player);   

	decision = 0;

	while (decision != 1)
	{
		printf("Are you satisified with your character?\n\t1. Yes\n\t2. No\nType the number corresponding with your decision and hit enter.\n");

		decision = getNum();

		if (decision == 1)
		{
			clearWithEnter();  
			break;
		}

		clearWithEnter();

		printf("Enter a new character name: ");

		characterCreator(&player); 
	}

	printf("\"I see... then from here on you will be known as the Great Hero %s!\"\n", player.name);  

	clearWithEnter();

	printf("\"Oh Great Hero %s! Our kingdom is in grave danger from the threat of monsters!\"\n\n\"Our forces are not strong enough to defeat them as they are being controlled by the powerful Dark King!\"\n\n\"You are the only one with the potential to be able to defeat him... please... you must help us.\"\n", player.name); 

	clearWithEnter();

	printf("Will you accept your mission?\n\t1. Yes\n\t2. No\nType the number corresponding with your decision and hit enter.\n");

	decision = getNum();

	if (decision == 1)
	{
		clearWithEnter();

		printf("\"Wonderful! We are forever indebted you!\"\n\n\"Guards bring the hero his weapon of choice...\"\n");

		clearWithEnter();
	}
	else if (decision == 2)
	{
		clearWithEnter();  

		return gameOver(); 
	}

	printf("Three guards walk up you. Each one kneels to you and offers up an item they are holding...\n\t1. Sword - Name: %s, Defense: %d, Attacks: %s, %s, %s\n\t2. Spear - Name: %s, Defense: %d, Attacks: %s, %s, %s\n\t3. Shield - Name: %s, Defense: %d, Ataacks: %s, %s, %s\nWhat will you choose?\n\n", strtSwrd.name, strtSwrd.defense, strtSwrd.attack1.name, strtSwrd.attack2.name, strtSwrd.attack3.name, strtSpr.name, strtSpr.defense, strtSpr.attack1.name, strtSpr.attack2.name, strtSpr.attack3.name, strtShld.name, strtShld.defense, strtShld.attack1.name, strtShld.attack2.name, strtShld.attack3.name);

	printf("Type the number corresponding with your decision and hit enter.\n");

	Weapon currentWeapon = {};

	decision = getNum();

	if (decision == 1)
	{
		currentWeapon = strtSwrd;

		printf("\nYou selected the %s. Here are its attack stats:\n\tName - %s, Damage - %d, StrengthReq - %d, SpeedReq - %d\n\tName - %s, Damage - %d, StrengthReq - %d, SpeedReq - %d\n\tName - %s, Damage - %d, StrengthReq - %d, SpeedReq - %d\n", currentWeapon.name, currentWeapon.attack1.name, currentWeapon.attack1.dmg, currentWeapon.attack1.strnReq, currentWeapon.attack1.spdReq, currentWeapon.attack2.name, currentWeapon.attack2.dmg, currentWeapon.attack2.strnReq, currentWeapon.attack2.spdReq, currentWeapon.attack3.name, currentWeapon.attack3.dmg, currentWeapon.attack3.strnReq, currentWeapon.attack3.spdReq);    

		clearWithEnter();
	} 
	else if (decision == 2) 
	{
		currentWeapon = strtSpr;

		printf("\nYou selected the %s. Here are its attack stats:\n\tName - %s, Damage - %d, StrengthReq - %d, SpeedReq - %d\n\tName - %s, Damage - %d, StrengthReq - %d, SpeedReq - %d\n\tName - %s, Damage - %d, StrengthReq - %d, SpeedReq - %d\n", currentWeapon.name, currentWeapon.attack1.name, currentWeapon.attack1.dmg, currentWeapon.attack1.strnReq, currentWeapon.attack1.spdReq, currentWeapon.attack2.name, currentWeapon.attack2.dmg, currentWeapon.attack2.strnReq, currentWeapon.attack2.spdReq, currentWeapon.attack3.name, currentWeapon.attack3.dmg, currentWeapon.attack3.strnReq, currentWeapon.attack3.spdReq); 

		clearWithEnter();  
	}
	else if (decision == 3)
	{
		currentWeapon = strtShld;

		printf("\nYou selected the %s. Here are its attack stats:\n\tName - %s, Damage - %d, StrengthReq - %d, SpeedReq - %d\n\tName - %s, Damage - %d, StrengthReq - %d, SpeedReq - %d\n\tName - %s, Damage - %d, StrengthReq - %d, SpeedReq - %d\n", currentWeapon.name, currentWeapon.attack1.name, currentWeapon.attack1.dmg, currentWeapon.attack1.strnReq, currentWeapon.attack1.spdReq, currentWeapon.attack2.name, currentWeapon.attack2.dmg, currentWeapon.attack2.strnReq, currentWeapon.attack2.spdReq, currentWeapon.attack3.name, currentWeapon.attack3.dmg, currentWeapon.attack3.strnReq, currentWeapon.attack3.spdReq); 

		clearWithEnter();  
	}

	printf("The monestary member bids you farewell with a kind smile as you embark on the path through the forest towards the Dark King's castle...\n");

	clearWithEnter();

	printf("You continue to walk through the forest.\n");

	clearWithEnter(); 

	Enemy currentEnemy = {};

	randEncounter(&currentEnemy, &player, &currentWeapon);  


	return 0;
}

void randEncounter(struct enemy* monster, struct character* player, struct weapon* weapon)  
{
	//needed to add this so that rand() would generate a new random number every single time the program was run
	srand(time(NULL));  

	int i = rand() % 1000;  

	if (i >= counter && i <= t1ProbRange)    
	{
		*monster = t1; 
	}
	else if (i > t1ProbRange && i <= t2ProbRange) 
	{
		*monster = t2;
	}
	else if (i > t2ProbRange && i <= t3ProbRange) 
	{
		*monster = t3; 
	}
	else if (i > t3ProbRange && i <= t4ProbRange)  
	{
		*monster = t4; 
	}

	printf("Oh no! You've run into an enemy %s! Would you like to Fight or Run Away?\n\t1. Fight\n\t2. Run Away\nType the number corresponding with your decision and hit enter.\n", monster->name); 

	int decision = getNum();

	clearWithEnter(); 

	if (decision == 1)
	{
		printf("You have entered a battle with an enemy %s!\n", monster->name);  

		clearWithEnter();

		battle(*monster, *player, *weapon);    
	}
	else if (decision == 2) 
	{
		i = rand() % 1000;

		if (i <= 501 || player->speed > monster->speed + 5)      
		{
			printf("You have successfully escaped the enemy %s!\n", monster->name); 

			clearWithEnter();
		}
		else
		{
			printf("You weren't fast enough to escape the enemy %s. You are now entering a battle!\n", monster->name); 

			clearWithEnter(); 

			battle(*monster, *player, *weapon);   
		}
	}
}

void battle(struct enemy monster, struct character player, struct weapon weapon)  
{
	printf("A hostile %s attacks you!\n", monster.name);

	clearWithEnter(); 

	printf("Current Status:\n\n\tHealth: %d\n\tStrength: %d\n\tSpeed: %d\n\tAgility: %d\n", player.health, player.strength, player.speed, player.agility);

	clearWithEnter(); 

	struct attack currentMonAtk = {};

	while (monster.health >= 0)
	{
		srand(time(NULL)); 

		int i = rand() % 10; 

		if (i >= 0 && i <= 4)
		{
			currentMonAtk = monster.attack1; 
		}
		else if (i >= 5 && i <= 9)
		{
			currentMonAtk = monster.attack2; 
		}

		printf("The %s used %s! What will you do?\n", monster.name, currentMonAtk.name);  

		clearWithEnter(); 

		printf("1. Dodge\t\t2. Defend\nType the number corresponding with your decision and hit enter.\n");

		int decision = getNum();

		clearWithEnter();

		if (decision == 1)
		{
			if (player.agility > monster.speed)
			{
				printf("You successfully dodged the %s and took no damage.\n", currentMonAtk.name); 

				clearWithEnter();   
			}
			else if (player.agility <= monster.speed)
			{
				player.health -= currentMonAtk.dmg; 

				printf("You failed to dodge the %s and took %d damage.\n", currentMonAtk.name, currentMonAtk.dmg); 

				clearWithEnter();
			}
		}
		else if (decision == 2)
		{
			if (weapon.defense >= currentMonAtk.dmg)
			{
				printf("You successfully defended againt the %s and took no damage.", currentMonAtk.name); 

				clearWithEnter(); 
			}
			else if (weapon.defense < currentMonAtk.dmg)
			{
				int totalDmg = currentMonAtk.dmg - weapon.defense; 

				player.health -= totalDmg;  

				printf("You failed to completely defend against the %s and took %d damage.", currentMonAtk.name, totalDmg); 

				clearWithEnter();
			}
		}

		monster.speed -= currentMonAtk.spdReq; 

		monster.strength -= currentMonAtk.strnReq; 

		if (player.health <= 0)
		{
			printf("GAME OVER. You were killed by the %s...\n", monster.name); 

			clearWithEnter();

			exit(0);
		}

		printf("You Current Status:\n\n\tHealth: %d\n\tStrength: %d\n\tSpeed: %d\n\tAgility: %d\n", player.health, player.strength, player.speed, player.agility);  

		clearWithEnter();

		printf("Monster's Current Status:\n\n\tHealth: %d\n\tStrength: %d\n\tSpeed: %d\n", monster.health, monster.strength, monster.speed);  

		clearWithEnter();

		printf("It is now your turn to make a move. What will you do?\n");

		clearWithEnter();

		printf("1. Attack\t\t2. Run Away\t\t3. Use Item\nType the number corresponding with your decision and hit enter.\n"); 

		decision = getNum();

		clearWithEnter(); 

		break; 
	}
}

void characterCreator(struct character* player)
{
	fgets(player->name, stringArraySize, stdin);  
	   
	if (player->name[strlen(player->name) - 1] == '\n') 
	{
		player->name[strlen(player->name) - 1] = '\0'; 
	} 

	printf("\nSelect what type of build you would like your character to have.\n\n1. Strength type - sacrifices speed and agility for a greater strength stat\n2. Speed type - sacrifices strength and agility for a greater speed stat\n3. Agility type - sacrifices strength and speed for a greater agility stat\n4. All-rounder type - does not sacrifice any stats but is not exceptional in any specific stat\n\nType the number corresponding with your decision and hit enter.\n"); 

	int decision = getNum(); 

	if (decision == 1) 
	{
		player->health = MAXhp;
		player->strength = T2strn;
		player->speed = T1spd;
		player->agility = T1agl; 
	}

	else if (decision == 2)
	{
		player->health = MAXhp; 
		player->strength = T1strn; 
		player->speed = T2spd; 
		player->agility = T1agl; 
	}

	else if (decision == 3)
	{
		player->health = MAXhp; 
		player->strength = T1strn;
		player->speed = T1spd; 
		player->agility = T2agl; 
	}

	else if (decision == 4)
	{
		player->health = MAXhp; 
		player->strength = T3strn;
		player->speed = T3spd;
		player->agility = T3agl;
	}

	clearWithEnter(); 

	printf("Here are your stats:\n\nName - %s\nHealth - %d\nStrength - %d\nSpeed - %d\nAgility - %d\n", player->name, player->health, player->strength, player->speed, player->agility);

	clearWithEnter();
}

int gameOver(void)
{
	printf("GAME OVER. Closing game...\n");

	clearWithEnter();

	return quitProg; 
}

int clearWithEnter(void)
{
	printf("\n\tPress Enter to continue");

	char enter[stringArraySize] = "";

	fgets(enter, stringArraySize, stdin);
	if (strchr(enter, '\n') != NULL) 
	{
		system("cls"); 
	}
	else
	{
		return returnVal;   
	}
} 

int getNum(void)
{
	char record[stringArraySize] = { 0 };
	int number = 0;

	fgets(record, stringArraySize, stdin);

	if (sscanf(record, "%d", &number) != 1)
	{

		number = -1;
	}
	return number;
}
