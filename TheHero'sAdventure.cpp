#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable: 4996)

//prototypes
int clearWithEnter(void);
int getNum(void);

const int arraySize = 50;

const int counter = 0;

struct character 
{
	char name[arraySize];
	int health;
	int strength;
	int speed;
	int agility;
};

struct enemy
{
	char name[arraySize];
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

	printf("\n");

	printf("\tPress Enter to continue\n");

	clearWithEnter();

	return 0;
}

int clearWithEnter(void)
{
	char enter[arraySize] = ""; 

	fgets(enter, arraySize, stdin);  
	if (enter[0] == '\n')
	{
		system("cls");
	}
	else
	{
		return 1;
	}
} 

int getNum(void)
{
	char record[arraySize] = { 0 }; 
	int number = 0;

	fgets(record, arraySize, stdin);  

	if (sscanf(record, "%d", &number) != 1)
	{

		number = -1;
	}
	return number;
}  