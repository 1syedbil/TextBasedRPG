#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable: 4996)

//prototypes
int clearWithEnter(void);
int getNum(void);
void characterCreator(struct character* player); 

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

struct character 
{
	char name[stringArraySize];
	int health;
	int strength;
	int speed;
	int agility;
};

struct enemy
{
	char name[stringArraySize];
	int health;
	int strength;
	int speed;
	int agility;
};

struct consumable
{
	int regen;
	int posion;
	int strnUp;
	int spdUp;
	int aglUp;
};

struct weapon
{
	int dmg;
	int defense;
	int numOfUses;
};


int main(void)
{
	printf("Welcome to... The Hero's Adventure!\n");

	clearWithEnter();

	printf("Would you like to start a new game?\n");

	printf("\t1. Start New Game\n");
	
	printf("\t2. Quit\n");

	printf("Enter the number corresponding with your decision.\n");

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

	printf("You suddenly awake in a room resembling a large monestary or a chapel...\n");

	printf("The sun shines down on you from a tall stained glass window.\n");

	clearWithEnter();

	printf("A member of this monestary walks up to you and speaks to you in a soft and kind voice...\n\n");

	printf("\"Welcome great hero. May I know thy name?...\"\n"); 

	clearWithEnter();

	
	printf("Create your character...\n\n");

	printf("Enter your character name: ");

	struct character player = {};

	characterCreator(&player);   

	decision = 0;

	while (decision != 1)
	{
		printf("Are you satisified with your character?\n\n");

		printf("\t1. Yes\n");

		printf("\t2. No\n");

		printf("Type the number corresponding with your decision and hit enter.\n");

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

	printf("\"I see... then from here on you will be known as the great hero %s!\"\n", player.name);  


	return 0;
}

void characterCreator(struct character* player)
{
	fgets(player->name, stringArraySize, stdin);  
	   
	if (player->name[strlen(player->name) - 1] == '\n') 
	{
		player->name[strlen(player->name) - 1] = '\0'; 
	} 

	printf("\n"); 

	printf("Select what type of build you would like your character to have.\n\n"); 

	printf("1. Strength type - sacrifices speed and agility for a greater strength stat\n"); 

	printf("2. Speed type - sacrifices strength and agility for a greater speed stat\n"); 

	printf("3. Agility type - sacrifices strength and speed for a greater agility stat\n"); 

	printf("4. All-rounder type - does not sacrifice any stats but is not exceptional in any specific stat\n\n"); 

	printf("Type the number corresponding with your decision and hit enter.\n"); 

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

	printf("Here are your stats:\n\n"); 

	printf("Name - %s\n", player->name); 

	printf("Health - %d\n", player->health);

	printf("Strength - %d\n", player->strength);

	printf("Speed - %d\n", player->speed);

	printf("Agility - %d\n", player->agility);

	clearWithEnter();
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