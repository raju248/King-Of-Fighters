#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

typedef struct character character;

struct character
{
	int posX;
	int posY;
	bool jump, run, punch, punchOn, kick, kickOn, seat, back, stand = true, hit, jumpUp = false, win, lost, combo, comboEffect, comboOn, isHit;
	int standCounter = 0;
	int hitCounter = 0;
	int health;
	int jumpY = 0;
	int Score = 0;

	character()
	{
		;
	}

	character(int x, int y)
	{
		posX = x;
		posY = y;
	}

	void initialState()
	{
		jump = false;
		run = false; 
		punch = false;
		kick = false;
		back = false; 
		stand = true;
		combo = false;
		comboEffect = false;
		comboOn = false;
		punchOn = false;
		kickOn = false;
		hit = false;
		lost = false;
		win = false;
		health = 500;
		Score = 0;
		hitCounter = 0;
		isHit = false;
	}

	void DoPunch()
	{
		punch = true;
		punchOn = true;
		kickOn = false;
		kick = false;
		back = false;
		run = false;
	}

	void DoKick()
	{
		kick = true;
		kickOn = true;
		punchOn = false;
		punch = false;
		back = false;
		run = false;
		combo = false;
	}

	void DoJump()
	{
		jump = true;
		jumpUp = true;
		kickOn = false;
		punchOn = false;
		run = false;
		kick = false;
		back = false;
		punch = false;
		combo = false;
	}

	void DoGoForward()
	{
		run = true;
		kick = false;
		back = false;
		punch = false;
		combo = false;
		punchOn = false;
		kickOn = false;
	}

	void DoGoBackWard()
	{
		back = true;
		run = false;
		kick = false;
		punch = false;
		combo = false;
		punchOn = false;
		kickOn = false;
	}

	void DoCombo()
	{
		combo = true;
		jump = false;
		run = false;
		punch = false;
		punchOn = false;
		kickOn = false;
		kick = false;
		back = false;
	}
};






#endif