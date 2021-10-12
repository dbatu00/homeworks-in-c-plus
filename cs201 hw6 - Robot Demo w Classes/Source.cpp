#include <string>
#include "Robots_Modified.h"
#include "miniFW_Modified.h"
#include "strutils.h"
#include "randgen.h"
using namespace std;

int monsterTurn = 0;
int playerDeathCount = 0;


void macar(Robot &monster1, Robot& monster2, Robot &monster3)// Monster Alive Check and Resurrect
{
		
		if( !monster1.IsAlive())
			monster1.Resurrect();
		else if( !monster2.IsAlive())
			monster2.Resurrect();
		else if( !monster3.IsAlive())
			monster3.Resurrect();

}

int monsterMove(Robot &m1, Robot& m2, Robot& m3)
{
	RandGen rand;
	int x;
	
	if(monsterTurn % 3 == 0)
	{
		x = rand.RandInt(4);
		if(x == 0)
		{
			m1.TurnFace(east);
			m1.Move();
		}
		else if(x == 1)
		{
			m1.TurnFace(west);
			m1.Move();
		}
		else if(x == 2)
		{		
			m1.TurnFace(north);
			m1.Move();

		}
		else if (x == 3)
		{
			m1.TurnFace(south);
			m1.Move();
		}
		monsterTurn++;
		return 1;
	}
	
	else if(monsterTurn % 3 == 1)
	{
		x = rand.RandInt(4);
		if(x == 0)
		{
			m2.TurnFace(east);
			m2.Move();
		}
		else if(x == 1)
		{
			m2.TurnFace(west);
			m2.Move();
		}
		else if(x == 2)
		{		
			m2.TurnFace(north);
			m2.Move();

		}
		else if (x == 3)
		{
			m2.TurnFace(south);
			m2.Move();
		}
		
		monsterTurn++;
		return 2;
	}

	else if(monsterTurn % 3 == 2)
	{
		x = rand.RandInt(4);
		if(x == 0)
		{
			m3.TurnFace(east);
			m3.Move();
		}
		else if(x == 1)
		{
			m3.TurnFace(west);
			m3.Move();
		}
		else if(x == 2)
		{		
			m3.TurnFace(north);
			m3.Move();

		}
		else if (x == 3)
		{
			m3.TurnFace(south);
			m3.Move();
		}
		
		monsterTurn++;
		return 3;

	}
	
	

}


void playerMove(Robot &r)
{
	if (r.IsAlive()== true )
	{	
		if (IsPressed(keyRightArrow))
		{				
			r.TurnFace(east);
			r.Move();
		}
		else if (IsPressed(keyLeftArrow))
		{
			r.TurnFace(west);
			r.Move();
		}
		else if (IsPressed(keyUpArrow))
		{
			r.TurnFace(north);
			r.Move();
		}
		else if (IsPressed(keyDownArrow))
		{
			r.TurnFace(south);		
			r.Move();
		}
	}
}


int main(){

	RandGen rand;
	int thingNumber = rand.RandInt(20,64);
	int thingCount = 0;
	int thingPosX, thingPosY;
	int thingAmount;
	bool thingPut = false;

	while(thingCount < thingNumber)
	{
		thingPut = false;
		
		while(!thingPut)
			{
				thingPosX = rand.RandInt(0,7);
				thingPosY = rand.RandInt(0,7);
				if (GetCellCount(thingPosX, thingPosY) == 0)
				{
					thingAmount = rand.RandInt(1,10);
					PutThings(thingPosX, thingPosY, thingAmount);
					thingCount++;
					thingPut = true;
				}
		}
			
	
	}

	string playerName, monster1Name, monster2Name, monster3Name;
	int whichMonster, things;

	ShowMessage("Please enter the name of the player. ");
	cin >> playerName;
	ShowMessage("Please enter the name of the monster1. ");
	cin >> monster1Name;
	ShowMessage("Please enter the name of the monster2. ") ;
	cin >> monster2Name;
	ShowMessage("Please enter the name of the monster3. ");
	cin >> monster3Name;

	Robot player(5,2,east,0);
	Robot monster1(0,0,east,0);
	Robot monster2(0,7,east,0);
	Robot monster3(7,7,east,0);
	
	player.SetColor(blue);
	monster1.SetColor(red);
	monster2.SetColor(red);
	monster3.SetColor(red);

	player.SetName(playerName);
	monster1.SetName(monster1Name);
	monster2.SetName(monster2Name);
	monster3.SetName(monster3Name);

	//FLOW
	
	do
	{
		whichMonster = monsterMove(monster1,monster2,monster3);
	
		if(whichMonster == 1 && (monster1.IsAlive()))
			monster1.PickAllThings();
		else if (whichMonster == 2 && (monster2.IsAlive()))
			monster2.PickAllThings();
		else if (whichMonster == 3 && (monster3.IsAlive()))
			monster3.PickAllThings();

		if(!player.IsAlive())
		{
			playerDeathCount++;
			player.Resurrect();
			
		}		
		
		macar(monster1,monster2,monster3);

		playerMove(player);
		if(player.IsAlive())
			player.PickAllThings();
		else
		{
			playerDeathCount++;
			player.Resurrect();
			macar(monster1,monster2,monster3);
		}
		
	things = GetThingCount(0,0,7,7);
	
	if(playerDeathCount == 3)
		{
			things = 0;
			ShowMessage("Player Lost");
			cin.get();
			cin.ignore();
			return 0;
		}
	}
	while(things != 0);

	if ( player.GetBagCount() > monster1.GetBagCount() && player.GetBagCount() > monster2.GetBagCount() 
													   && player.GetBagCount() > monster3.GetBagCount() )
		ShowMessage("Player Won");

	cin.get();
	cin.ignore();
	return 0;
	










}
