#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable: 4996)

//prototypes
int clearWithEnter(void);
int getNum(void);

const int stringArraySize = 50;

const int counter = 0;

const int quitProg = -1; 

const int returnVal = 1; 

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

	fgets(player.name, stringArraySize, stdin);

	if (player.name[strlen(player.name) - 1] == '\n')
	{
		player.name[strlen(player.name) - 1] = '\0';
	}

	printf("\n"); 

	printf("Select what type of build you would like your character to have.\n\n");

	printf("1. Strength type - sacrifices speed and agility for a greater strength stat\n");

	printf("2. Speed type - sacrifices strength and agility for a greater speed stat\n");

	printf("3. Agility type - sacrifices strength and speed for a greater agility stat\n");

	printf("4. All-rounder type - does not sacrifice any stats but is not exceptional in any specific stat\n\n");

	printf("Enter the number corresponding with your decision.\n");

	decision = getNum();

	if (decision == 1)
	{
		player.speed = 30;
		player.agility = 30;
		player.strength = 60; 
		player.health = 100;
	}

	else if (decision == 2)
	{
		player.speed = 60;
		player.agility = 30; 
		player.strength = 30;
		player.health = 100; 
	}

	else if (decision == 3)
	{
		player.speed = 30;
		player.agility = 60;
		player.strength = 30; 
		player.health = 100;
	}

	else if (decision == 4)
	{
		player.speed = 45;
		player.agility = 45;
		player.strength = 45; 
		player.health = 100;  
	}

	clearWithEnter(); 

	printf("Here are your stats:\n\n");

	printf("Name - %s\n", player.name);
	
	printf("Health - %d\n", player.health);

	printf("Strength - %d\n", player.strength);

	printf("Speed - %d\n", player.speed);

	printf("Agility - %d\n", player.agility);

	clearWithEnter(); 

	decision = 0;

	while (decision != 1)
	{
		printf("Are you satisified with your character?\n\n");

		printf("\t1. Yes\n");

		printf("\t2. No\n");

		printf("Enter a number corresponding with your decision.\n");

		decision = getNum();

		if (decision == 1)
		{
			clearWithEnter();  
			break;
		}

		clearWithEnter();

		printf("Enter a new character name: ");

		fgets(player.name, stringArraySize, stdin);

		if (player.name[strlen(player.name) - 1] == '\n') 
		{
			player.name[strlen(player.name) - 1] = '\0';  
		}

		clearWithEnter();

		printf("Select a new character build.\n\n");

		printf("1. Strength type - sacrifices speed and agility for a greater strength stat\n");

		printf("2. Speed type - sacrifices strength and agility for a greater speed stat\n");

		printf("3. Agility type - sacrifices strength and speed for a greater agility stat\n");

		printf("4. All-rounder type - does not sacrifice any stats but is not exceptional in any specific stat\n\n");

		printf("Enter the number corresponding with your decision.\n");

		int newDecision = getNum(); 

		if (newDecision == 1)
		{
			player.speed = 30;
			player.agility = 30;
			player.strength = 60;
			player.health = 100;
		}

		else if (newDecision == 2)
		{
			player.speed = 60;
			player.agility = 30;
			player.strength = 30;
			player.health = 100;
		}

		else if (newDecision == 3) 
		{
			player.speed = 30;  
			player.agility = 60;  
			player.strength = 30;  
			player.health = 100;  
		}

		else if (newDecision == 4) 
		{
			player.speed = 45;  
			player.agility = 45;  
			player.strength = 45;   
			player.health = 100;  
		}

		clearWithEnter();  

		printf("Here are your stats:\n\n");

		printf("Name - %s\n", player.name);  
		   
		printf("Health - %d\n", player.health);  

		printf("Strength - %d\n", player.strength);  

		printf("Speed - %d\n", player.speed);  

		printf("Agility - %d\n", player.agility);  

		clearWithEnter(); 
	}

	printf("\"I see... then from here on you will be known as the great hero %s!\"\n", player.name);  


	return 0;
}

int clearWithEnter(void)
{
	printf("\n\tPress Enter to continue");

	char enter[stringArraySize] = "";

	fgets(enter, stringArraySize, stdin);
	if (enter[0] == '\n')
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