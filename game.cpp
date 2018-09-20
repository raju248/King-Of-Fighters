#include "iGraphics.h"
#include "bitmap_loader.h"
#include "Player.h"


int sLength = 830, sWidth = 500;
int bg = 0, bgimage, k;



char BackGround1[40][100] = { "Charac\\bg\\1\\0.bmp", "Charac\\bg\\1\\1.bmp", "Charac\\bg\\1\\2.bmp", "Charac\\bg\\1\\3.bmp", "Charac\\bg\\1\\4.bmp", "Charac\\bg\\1\\5.bmp", "Charac\\bg\\1\\6.bmp", "Charac\\bg\\1\\7.bmp", "Charac\\bg\\1\\8.bmp", "Charac\\bg\\1\\9.bmp", "Charac\\bg\\1\\10.bmp", "Charac\\bg\\1\\11.bmp", "Charac\\bg\\1\\12.bmp", "Charac\\bg\\1\\13.bmp", "Charac\\bg\\1\\14.bmp", "Charac\\bg\\1\\15.bmp", "Charac\\bg\\1\\16.bmp", "Charac\\bg\\1\\17.bmp", "Charac\\bg\\1\\18.bmp", "Charac\\bg\\1\\19.bmp", "Charac\\bg\\1\\20.bmp" };
char MenuBackground[2][100] = { "Charac\\bg\\menubg2.bmp", "Charac\\bg\\logo2.bmp" };
char menuUI[6][100] = { "Charac\\bg\\UI\\1y.bmp", "Charac\\bg\\UI\\2y.bmp", "Charac\\bg\\UI\\3y.bmp", "Charac\\bg\\UI\\4y.bmp", "Charac\\bg\\UI\\5y.bmp", "Charac\\bg\\UI\\6y.bmp" };
char MenuUIWhite[8][100] = { "Charac\\bg\\UI\\1w.bmp", "Charac\\bg\\UI\\2w.bmp", "Charac\\bg\\UI\\3w.bmp", "Charac\\bg\\UI\\4w.bmp", "Charac\\bg\\UI\\5w.bmp", "Charac\\bg\\UI\\6w.bmp", "Charac\\bg\\UI\\exit.bmp", "Charac\\bg\\UI\\score.bmp" };
char StartScreens[4][100] = { "Charac\\bg\\menubg3.bmp", "Charac\\bg\\menubg4.bmp", "Charac\\bg\\menubg5.bmp", "Charac\\bg\\menubg6.bmp" };



int menu, level, timers[10], introImage = 0;

int AshRunImage , AshkickImage, AshPunchImage , AshGoBackImage, AshLostImage;
int IoriRunImage, IoriKickImage, IoriPunchImage, IoriGoBackImage, IoriLostImage;

bool showMenu, continu = true, showPrmp = true, musicOn = true, mainMenu = false, showStartScreen = true, showSinglePlayerLevel, play = true, pause, ShowPauseMenus, jumpUp;
bool isPlay;
bool OpponentSelectRandomMove;
bool isGameOver;

int RandomMove;


char HealthTextPlayer[100] = "Health : 100";
char HealthTextOpponet[100] = "Health : 100";

int PlayerScore = 0;
int OpponentScore = 0;

char PlayerHealthtoChar[10];
char OpponentHealthtoChar[10];

character Ash1(200, 50);
character Iori(450, 50);

int PlayerHealthBarWidth;
int PlayerHealthBarLength;

int OpponentHealthBarWidth;
int OpponentHealthBarLength;

void HealthCheck();


void ShowCharacterInSinglePlayer()
{
	HealthCheck();

	if (Ash1.health <= 0)
	{
		iSetColor(255, 255, 255);
		iFilledRectangle(300, 400, 120, 70);
		iSetColor(255, 0, 0);
		iText(300, 400, "You Lost", GLUT_BITMAP_TIMES_ROMAN_24);
		isPlay = false;
		Ash1.lost = true;
		isGameOver = true;
		/*iPauseTimer(0);
		iPauseTimer(1);
		iPauseTimer(2);
		iPauseTimer(3);
		iPauseTimer(4);*/
	}

	if (Iori.health <= 0)
	{
		iSetColor(255, 255, 255);
		iFilledRectangle(300, 400, 120, 70);
		iSetColor(255, 0, 0);
		iText(300, 400, "You Won", GLUT_BITMAP_TIMES_ROMAN_24);
		isPlay = false;
		Iori.lost = true;
		isGameOver = true;
		OpponentSelectRandomMove = false;
		/*iPauseTimer(0);
		iPauseTimer(1);
		iPauseTimer(2);
		iPauseTimer(3);
		iPauseTimer(4);*/
	}

	iText(50, 450, "Player : Ash Crimson", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(500, 450, "Opponent : Iori Yagami", GLUT_BITMAP_TIMES_ROMAN_24);

	iSetColor(255, 255, 255);
	iFilledRectangle(49, 399.5, 252, 17);
	iFilledRectangle(499, 399.5, 252, 17);

	iSetColor(255, 0, 0);
	iFilledRectangle(50, 400, Ash1.health, 15);
	iFilledRectangle(750, 400, -Iori.health, 15);

	/*================================= Ash Images ============================================*/

	//jump image 
	if (Ash1.jump)
	{
		if (Ash1.jumpUp)
		{
			if (Ash1.jumpY == 0)
			{
				iShowBMP2(Ash1.posX, Ash1.posY + Ash1.jumpY, AshJump[1], 0x215218);
			}

			else
				iShowBMP2(Ash1.posX, Ash1.posY + Ash1.jumpY, AshJump[2], 0x215218);
		}

		else
		{
			iShowBMP2(Ash1.posX, Ash1.posY + Ash1.jumpY, AshJump[3], 0x215218);
		}
	}
	// run image
	else if (Ash1.run)
	{
		iShowBMP2(Ash1.posX, Ash1.posY, AshRunForward[AshRunImage], 0x215218);
	}
	//kick image
	else if (Ash1.kick)
	{
		iShowBMP2(Ash1.posX, Ash1.posY, AshKick[AshkickImage], 0x215218);
	}

	else if (Ash1.punch)
	{
		iShowBMP2(Ash1.posX, Ash1.posY, AshPunch[AshPunchImage], 0x215218);
	}

	else if (Ash1.back)
	{
		iShowBMP2(Ash1.posX, Ash1.posY, AshGoBackward[AshGoBackImage], 0x215218);
	}
	//stand image
	else
	{
		if (Ash1.lost)
		{
			iShowBMP2(Ash1.posX, Ash1.posY, AshLost[AshLostImage], 0x215218);
		}

		else	
			iShowBMP2(Ash1.posX, Ash1.posY, AshStand[k], 0x215218);
	}

	/*================================= Iori Images ============================================*/

	if (Iori.jump)
	{
		if (Iori.jumpUp)
		{
			if (Iori.jumpY == 0)
			{
				iShowBMP2(Iori.posX, Iori.posY + Iori.jumpY, IoriJump[1], 0x8CBD7B);
			}

			else
				iShowBMP2(Iori.posX, Iori.posY + Iori.jumpY, IoriJump[2], 0x8CBD7B);
		}

		else
		{

			iShowBMP2(Iori.posX, Iori.posY + Iori.jumpY, IoriJump[3], 0x8CBD7B);
		}
	}
	// run image
	else if (Iori.run)
	{
		iShowBMP2(Iori.posX, Iori.posY, IoriRunForward[IoriRunImage], 0x8CBD7B);
	}
	//kick image
	else if (Iori.kick)
	{
		iShowBMP2(Iori.posX, Iori.posY, IoriKick[IoriKickImage], 0x8CBD7B);
	}

	else if (Iori.punch)
	{
		iShowBMP2(Iori.posX, Iori.posY, IoriPunch[IoriPunchImage], 0x8CBD7B);
	}

	else if (Iori.back)
	{
		iShowBMP2(Iori.posX, Iori.posY, IoriGoBackward[AshGoBackImage], 0x8CBD7B);
	}
	//stand image
	else
	{
		if (Iori.lost)
		{
			iShowBMP2(Iori.posX, Iori.posY, IoriLost[IoriLostImage], 0x8CBD7B);
		}

		else
		  iShowBMP2(Iori.posX, Iori.posY, IoriStand[k], 0x8CBD7B);
	}


	if (isGameOver)
		iShowBMP2(250, 400, "Charac//bg//UI//gameover.bmp", 0x101010);

}


//shows background in game
void ShowBackground()
{
	iShowBMP2(0, 0, BackGround1[bg], -1);
}


//shows single player levels
// case 1 : easy , case 2 : medium , case 3 : hard

void SinglePlayerLevel()
{
	switch (level)
	{
	case 1:ShowBackground();
		ShowCharacterInSinglePlayer();

		break;

	case 2: ShowBackground();
		ShowCharacterInSinglePlayer();
		break;

	case 3: ShowBackground();
		ShowCharacterInSinglePlayer();
		break;

	default:
		break;
	}
}


void Multiplayer()
{

}
//start screen
void StartScreen()
{
	//iShowBMP(15, 100, intro[introImage]);
	//iShowBMP2(250, 250, MenuBackground[1], 0xffffff);
}

//sub menus 
//case 1 : single player , case 2 : multiplayer , case 4 : controls , case 5 : credits , case 6 : score

void SubMenu()
{
	switch (menu)
	{
	case 1: iShowBMP2(0, 0, MenuBackground[0], -1);
		iShowBMP2(380, 0, MenuBackground[1], 0xffffff);
		iShowBMP2(70, 220, "Charac//bg//UI//easy.bmp", -1);
		iShowBMP2(70, 160, "Charac//bg//UI//medium.bmp", -1);
		iShowBMP2(70, 100, "Charac//bg//UI//hard.bmp", -1);
		iShowBMP2(70, 50, "Charac//bg//UI//back.bmp", -1);
		break;

	case 2: iShowBMP2(0, 0, MenuBackground[0], -1);
		iShowBMP2(380, 0, MenuBackground[1], 0xffffff);
		iShowBMP2(70, 50, "Charac//bg//UI//back.bmp", -1);
		break;

	case 3: break;

	case 4: iShowBMP2(0, 0, MenuBackground[0], -1);
		iShowBMP2(380, 0, MenuBackground[1], 0xffffff);
		iShowBMP2(70, 50, "Charac//bg//UI//back.bmp", -1);
		iShowBMP2(70, 180, "Charac//bg//UI//controls1.bmp", -1);
		iShowBMP2(224, 180, "Charac//bg//UI//controls2.bmp", -1);
		break;

	case 5: iShowBMP2(0, 0, MenuBackground[0], -1);
		iShowBMP2(380, 0, MenuBackground[1], 0xffffff);
		iShowBMP2(70, 50, "Charac//bg//UI//back.bmp", -1);
		iShowBMP2(70, 120, "Charac//bg//UI//about.bmp", -1);
		break;

	case 6: iShowBMP2(0, 0, MenuBackground[0], -1);
		iShowBMP2(380, 0, MenuBackground[1], 0xffffff);
		iSetColor(255, 255, 255);
		iFilledRectangle(70, 100, 300, 300);
		iSetColor(0, 32, 96);
		iShowBMP2(70, 50, "Charac//bg//UI//back.bmp", -1);
		break;

	default: 
		break;
	}
}

//shows main menus
void MainMenu()
{
	iShowBMP(70, 390, MenuUIWhite[0]);
	iShowBMP(70, 330, MenuUIWhite[1]);

	if (musicOn)
		iShowBMP(70, 270, MenuUIWhite[2]);
	else
		iShowBMP(70, 270, MenuUIWhite[3]);

	iShowBMP(70, 210, MenuUIWhite[4]);
	iShowBMP(70, 150, MenuUIWhite[5]);
	iShowBMP(70, 30, MenuUIWhite[6]);
	iShowBMP(70, 90, MenuUIWhite[7]);
}

//shows pause menus when game is paused
void pauseMenu()
{
	iShowBMP2(240, 300, "Charac//bg//UI//paused.bmp", 0x215218);
	iShowBMP(280, 230, "Charac//bg//UI//restart.bmp");
	iShowBMP(280, 170, "Charac//bg//UI//quittomain.bmp");
}


void iDraw()
{
	//place your drawing codes here

	iClear();


	if (showStartScreen)
	{
		StartScreen();
	}

	if (continu)
	{
		iShowBMPAlternativeSkipWhite(20, 50, "Charac//bg//UI//main.bmp");
	}


	if (showMenu)
	{
		iShowBMP2(0, 0, MenuBackground[0], -1);
		iShowBMP2(380, 0, MenuBackground[1], 0xffffff);
		MainMenu();
	}

	if (menu)
		SubMenu();

	if (play)
	{
		SinglePlayerLevel();
		iFilledRectangle(50, 500, 800, 50);
	}

	if (ShowPauseMenus)
		pauseMenu();


	
	
}

/*
function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{

}



/*
function iMouse() is called when the user presses/releases the mouse.
(mx, my) is the position where the mouse pointer is.
*/

void iMouse(int button, int state, int mx, int my)
{
	//works when game is in main menu screen
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && showMenu)
	{
		if (mx > 70 && mx < 280)
		{
			if (my > 390 && my < 440)
			{
				menu = 1;
				showSinglePlayerLevel = true;
				showMenu = false;
			}

			if (my > 330 && my < 370)
			{
				menu = 2;
				showMenu = false;
			}

			if (my > 270 && my < 320)
			{
				menu = 3;

				if (musicOn)
					musicOn = false;
				else
					musicOn = true;
			}

			if (my > 210 && my < 260)
			{
				menu = 4;
				showMenu = false;
			}

			if (my > 150 && my < 200)
			{
				menu = 5;
				showMenu = false;
			}

			if (my > 150 && my < 200)
			{
				menu = 5;
				showMenu = false;
			}

			if (my > 90 && my < 140)
			{
				menu = 6;
				showMenu = false;
			}

			if (my > 30 && my < 80)
			{
				exit(0);
			}
		}


	}

	//works for back button 
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && showMenu == false)
	{
		if (mx > 70 && mx < 170 && my>50 && my < 80 && menu)
		{
			menu = 0;
			showMenu = true;
			showSinglePlayerLevel = false;
		}
	}


	//single player level selection
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && showSinglePlayerLevel == true)
	{
		if (mx > 70 && mx < 270 && my>220 && my < 270)
		{

			Ash1 = character(200, 50);
			Ash1.initialState();

			RandomMove = 0;
			Iori = character(450, 50);
			Iori.initialState();


			OpponentSelectRandomMove = true;
			level = 1;
			play = true;
			isPlay = true;
			pause = true;
			showSinglePlayerLevel = false;
			isGameOver = false;
		}

		if (mx > 70 && mx < 270 && my>160 && my < 210)
		{
			Ash1 = character(200, 50);
			Ash1.initialState();

			RandomMove = 0;
			Iori = character(450, 50);
			Iori.initialState();

			OpponentSelectRandomMove = true;
			level = 2;
			play = true;
			isPlay = true;
			//	pause = true;
			showSinglePlayerLevel = false;
			isGameOver = false;
		}

		if (mx > 70 && mx < 270 && my>100 && my < 150)
		{
			Ash1 = character(200, 50);
			Ash1.initialState();

			RandomMove = 0;
			Iori = character(450, 50);
			Iori.initialState();

			OpponentSelectRandomMove = true;
			level = 3;
			play = true;
			isPlay = true;
			pause = true;
			showSinglePlayerLevel = false;
			isGameOver = false;
		}

	}
	//works when game is paused 
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && ShowPauseMenus == true && play)
	{
		if (mx > 280 && mx < 480 && my>230 && my < 280 && level)
		{
			play = true;
			pause = true;
			ShowPauseMenus = false;

			Ash1 = character(200, 50);
			Ash1.initialState();

			Iori = character(450, 50);
			Iori.initialState();
			
			RandomMove = 0;
			iResumeTimer(1);
			iResumeTimer(2);
			iResumeTimer(3);
			iResumeTimer(4);
			iResumeTimer(0);
		}

		if (mx > 280 && mx < 480 && my>170 && my < 220 && level)
		{
			showMenu = true;
			ShowPauseMenus = false;
			play = false;
			menu = 0;
			showSinglePlayerLevel = false;
			iResumeTimer(1);
			iResumeTimer(2);
			iResumeTimer(3);
			iResumeTimer(4);
			iResumeTimer(0);
		}
	}


	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{

	}

}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if (key == 'p')
	{
		//do something with 'q'
		iPauseTimer(0);
		iPauseTimer(1);
		iPauseTimer(2);
		iPauseTimer(3);
		iPauseTimer(4);

	}
	if (key == 'r')
	{
		iResumeTimer(0);
		iResumeTimer(1);
		iResumeTimer(2);
		iResumeTimer(3);
		iResumeTimer(4);
	}

	if (key == ' ' &&  mainMenu == false)
	{
		continu = false;
		showMenu = true;
		showPrmp = false;
		mainMenu = true;
		showStartScreen = false;
	}


		if (play && key == 'p')
		{
			ShowPauseMenus = true;
		}

		if (play && key == 'r')
		{
			ShowPauseMenus = false;
		}
		
		
		if (isPlay)
		{
			if (!Ash1.kick && play && key == 'd' || key == 'D')
			{
				Ash1.DoKick();
			}

			else if (!Ash1.punch && play && key == 's' || key == 'S')
			{
				Ash1.DoPunch();
			}
		}
}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_END)
	{
		exit(0);
	}

	if (isPlay)
	{
		if (!Ash1.back && key == GLUT_KEY_LEFT)
		{
			Ash1.DoGoBackWard();
		}

		if (!Ash1.run && key == GLUT_KEY_RIGHT)
		{
			Ash1.DoGoForward();
		}


		if (key == GLUT_KEY_UP && Ash1.jumpY == 0)
		{
			if (!Ash1.jumpUp)
			{
				Ash1.DoJump();
			}
		}
	}

}

//rendering functions

void CharacterRender()
{
	if (Ash1.stand)
	{
		k++;

		if (k == 8)
			k = 0;
	}



	//changes the value of Y co ordinate if the character jumps

	if (Ash1.jump)
	{
		if (Ash1.jumpUp)
		{
			Ash1.jumpY += 70;

			if (Ash1.jumpY >= 200)
			{
				Ash1.jumpUp = false;
			}
		}

		else
		{
			Ash1.jumpY -= 70;

			if (Ash1.jumpY < 0)
			{
				Ash1.jump = false;
				Ash1.jumpY = 0;
			}
		}
	}



	if (Ash1.run)
	{
		AshRunImage++;

		if (AshRunImage >= 5)
		{
			AshRunImage = 0;
		}

		Ash1.standCounter++;

		if (Ash1.posX <= 720)
			Ash1.posX += 10;

		if (Ash1.standCounter >= 8)
		{
			Ash1.standCounter = 0;
			Ash1.run = false;
		}
	}

	if (Ash1.kick)
	{
		AshkickImage++;

		if (AshkickImage == 9)
		{
			AshkickImage = 0;
		}

		Ash1.standCounter++;

		if (Ash1.standCounter >= 8)
		{
			Ash1.standCounter = 0;

			Ash1.kick = false;
		}
	}

	if (Ash1.punch)
	{
		AshPunchImage++;

		if (AshPunchImage == 15)
		{
			AshPunchImage = 0;
		}

		Ash1.standCounter++;

		if (Ash1.standCounter >= 16)
		{
			Ash1.standCounter = 0;
			Ash1.punch = false;
		}


	}

	if (Ash1.back)
	{
		AshGoBackImage++;

		if (AshGoBackImage == 7)
		{
			AshGoBackImage = 0;
		}

		Ash1.standCounter++;

		if (Ash1.posX >= 8)
			Ash1.posX -= 10;

		if (Ash1.standCounter == 10)
		{
			Ash1.standCounter = 0;
			Ash1.back = false;
		}
	}

	if (Ash1.lost)
	{
		AshLostImage++;

		if (AshLostImage >= 8)
		{
			AshLostImage = 0;
			isPlay = false;
		}
	}
}


void MoveSelect()
{
	srand(time(0));

	if (OpponentSelectRandomMove)
	{
		if (Iori.posX - Ash1.posX < 40)
		{
			RandomMove = rand() % 3;
		}

		else if (RandomMove != 1 || RandomMove != 2 || RandomMove != 3 || RandomMove != 4 || RandomMove != 5)
			RandomMove = rand() % 6;
	}

	else
		RandomMove = 6;
}



void HealthCheck()
{

	if (Iori.posX > Ash1.posX && Iori.posX < Ash1.posX + 80 && Iori.posY + 50>Ash1.posY && Iori.posY + 50 < Ash1.posY + 100 && (Iori.punch || Iori.kick) && isPlay)
	{
		Ash1.health -= 1;
		strcpy(HealthTextPlayer, "Health : ");
		sprintf(PlayerHealthtoChar, "%d", Ash1.health);
		strcat(HealthTextPlayer, PlayerHealthtoChar);

		if (Iori.punch)
			Iori.Score += 10;

		if (Iori.kick)
			Iori.Score += 30;

	}

	if (Ash1.posX + 80 >= Iori.posX && Ash1.posX + 80 <= Iori.posX + 80 && Ash1.posY >= Iori.posY && Ash1.posY <= Iori.posY + 120 && (Ash1.punch || Ash1.kick) && isPlay)
	{
		//iFilledRectangle(Ash1.posX, Ash1.posY, 100, 100);
		Iori.health -= 1;
		strcpy(HealthTextOpponet, "Health : ");
		sprintf(OpponentHealthtoChar, "%d", Iori.health);
		strcat(HealthTextOpponet, OpponentHealthtoChar);

		if (Ash1.punch)
			Ash1.Score += 10;

		if (Ash1.kick)
			Ash1.Score += 30;
	}
}


void OpponentMovementAI()
{
	switch (RandomMove)
	{
	case 5:  if (!Iori.jump && Iori.jumpY == 0)
	{
		Iori.DoJump();
		RandomMove = 0;
	}
			 break;

	case 4: if (!Iori.back)
	{
		Iori.DoGoBackWard();
		RandomMove = 0;
		IoriGoBackImage = 0;
	}
			break;


	case 3: if (!Iori.run && (Iori.posX - Ash1.posX > 100))
	{
		Iori.DoGoForward();
		IoriRunImage = 0;
		RandomMove = 0;
	}
			break;

	case 1: if (!Iori.punch)
	{
		Iori.DoPunch();
		IoriPunchImage = 0;
		RandomMove = 0;
	}
			break;

	case 2: if (!Iori.kick)
	{
		Iori.DoKick();
		RandomMove = 0;
		IoriKickImage = 0;
	}
			break;
	case 6: Iori.lost = true;
		Iori.kick = false;
		Iori.punch = false;
		Iori.run = false;
		Iori.jump = false;
		break;
	}


	if (Iori.jump)
	{

		if (Iori.jumpUp)
		{
			Iori.jumpY += 70;

			if (Iori.jumpY >= 200)
			{
				Iori.jumpUp = false;
				RandomMove = 0;
			}
		}

		else
		{
			Iori.jumpY -= 70;

			if (Iori.jumpY < 0)
			{
				Iori.jump = false;
				Iori.jumpY = 0;
				RandomMove = 0;
			}
		}
	}

	if (Iori.back)
	{
		Iori.standCounter++;

		if (Iori.posX <= 740)
			Iori.posX += 10;

		if (Iori.standCounter == 10)
		{
			Iori.standCounter = 0;
			RandomMove = 0;
			Iori.back = false;
		}
	}

	if (Iori.kick)
	{
		IoriKickImage++;

		if (IoriKickImage >= 9)
		{
			IoriKickImage = 0;
		}

		Iori.standCounter++;

		if (Iori.standCounter >= 8)
		{
			Iori.standCounter = 0;
			Iori.kick = false;
		}
	}

	if (Iori.punch)
	{
		IoriPunchImage++;

		if (IoriPunchImage >= 6)
		{
			IoriPunchImage = 0;
		}

		Iori.standCounter++;

		if (Iori.standCounter >= 10)
		{
			Iori.standCounter = 0;
			Iori.punch = false;
		}
	}

	if (Iori.run)
	{
		IoriRunImage++;

		if (IoriRunImage >= 9)
		{
			IoriRunImage = 0;
		}

		Iori.standCounter++;

		if (Iori.posX >= 0)
			Iori.posX -= 10;

		if (Iori.standCounter >= 8)
		{
			Iori.standCounter = 0;
			Iori.run = false;
		}
	}

	if (Iori.lost)
	{
		IoriLostImage++;

		if (IoriLostImage >= 7)
		{
			IoriLostImage = 0;
			isPlay = false;
		}
	}
}



void StartScreenChange()
{
	introImage++;

	if (introImage == 833)
		introImage = 0;
}

void bgRender()
{
	bg++;

	if (bg == 15)
		bg = 0;

	if (showPrmp)
	{
		if (!continu)
			continu = true;
		else
			continu = false;
	}

}


int main()
{
	//place your own initialization codes here.


	iInitialize(sLength, sWidth, "Animation with image");

	if (play)
	{
		timers[0] = iSetTimer(500, MoveSelect);
		timers[1] = iSetTimer(80, CharacterRender);
		timers[2] = iSetTimer(80, OpponentMovementAI);
	}

	if (StartScreen)
		timers[3] = iSetTimer(30, StartScreenChange);

	timers[4] = iSetTimer(200, bgRender);

	iStart();

	return 0;
}

