#include "iGraphics.h"
#include "bitmap_loader.h"
#include "Player.h"
#include "Scores.h"
#include "AllImages.h"

int sLength = 830, sWidth = 500;
int bg = 0, bgimage, k;
int bg1 = 0, bg2 = 0, bg3 = 0;
int len;
int mode;
int mposx, mposy;
int RandomMove;
int ComboBar1;
int ComboBar2;

char str[1000], str2[1000], str3[1000];

char PlayerName[20];
char ShowScoreText1[500] = "0";
char ShowScoreText2[500] = "0";

char YourScore[100] = "Your Score : ";

int menu, level, timers[10], introImage = 0;

int AshRunImage, AshkickImage, AshPunchImage, AshGoBackImage, AshLostImage, AshWinImage, AshComboImage;
int IoriRunImage, IoriKickImage, IoriPunchImage, IoriGoBackImage, IoriLostImage, IoriStandImage, IoriWinImage = 1,IoriComboImage;
int KyoRunImage, KyokickImage, KyoPunchImage, KyoGoBackImage, KyoLostImage, KyoWinImage, KyoComboImage;
int TerryRunImage, TerrykickImage, TerryPunchImage, TerryGoBackImage, TerryLostImage, TerryStandImage, TerryWinImage = 1, TerryComboImage;


bool isAshCombo = false;
bool isEnterName;
bool showPassiveMarks;
bool readScoreOnce = true;
bool PressSpaceToContinue = true;
bool musicOn = true;
bool mainMenu = false;
bool showPrmp = true;
bool ShowPauseMenus;
bool showMenu;
bool showStartScreen = true;
bool showSinglePlayerLevel;
bool OpponentSelectRandomMove;

bool jumpUp;
bool pause;
bool play;

bool isPlay;
bool isGameOver;
bool isMultiPlayer;
bool isMultiPlayerPlay;

character Ash1(200, 50);
character Iori(450, 50);
character Kyo(200, 50);
character Terry(450, 50);

int AshComboX = 0, AshComboY = 20;
int IoriComboX = Iori.posX-50, IoriComboY = 0;
int KyoComboX = 0,KyoComboY;
int TerryComboX = Terry.posX - 50, TerryComboY = Terry.posY;



void HealthCheck();
void HealthCheckMultiplayer();
void bgRender();
void CharacterAshRender();
void CharacterKyoRender();
void CharacterTerryRender();
void MainMenu();
void MoveSelect();
void MultiPlayer();
void OpponentMovementAI();
void pauseMenu();
void ShowBackground(char *BackGround);
void ShowCharacterAsh();
void ShowCharacterInSinglePlayer();
void ShowCharacterIori();
void ShowCharacterKyo();
void ShowCharacterTerry();
void ShowStartScreenText();
void SinglePlayerLevel();
void StartScreen();
void StartScreenChange();
void SubMenu();

/*
   ShowCharacterX fucntion shows character images
*/

void ShowCharacterAsh()
{
	/*================================= Ash Images =========================================*/
	iShowBMP2(70, 445, "Charac//bg//AshName.bmp", 0x215218);
	iShowBMP2(10, 400, "Charac//bg//AshFace.bmp", 0xFF00FF);
	
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

	else if (Ash1.comboOn && Ash1.combo)
	{
		iShowBMP2(Ash1.posX, Ash1.posY, AshCombo[AshComboImage], 0x215218);
	}

	else if (Ash1.isHit)
	{
		iShowBMP2(Ash1.posX, Ash1.posY, "Charac\\Ash\\891.bmp", 0x215218);
		Ash1.isHit = false;
	}
	//stand image
	else
	{
		if (Ash1.lost)
		{
			iShowBMP2(Ash1.posX, Ash1.posY, AshLost[AshLostImage], 0x215218);
		}

		else if (Ash1.win)
		{
			iShowBMP2(Ash1.posX, Ash1.posY, AshWin[AshWinImage], 0x215218);
		}

		else
			iShowBMP2(Ash1.posX, Ash1.posY, AshStand[k], 0x215218);
	}


	if (Ash1.comboEffect)
	{
		iShowBMP2(AshComboX + 30, AshComboY, AshComboEffect[0], 0x215218);
	}
}

void ShowCharacterIori()
{
	/*================================= Iori Images ==========================================*/
	iShowBMP2(580, 445, "Charac//bg//IoriName.bmp", 0x215218);
	iShowBMP2(750, 400, "Charac//bg//IoriFace.bmp", 0xFF00FF);

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
		iShowBMP2(Iori.posX, Iori.posY, IoriGoBackward[IoriGoBackImage], 0x8CBD7B);
	}

	else if (Iori.isHit)
	{
		iShowBMP2(Iori.posX, Iori.posY, "Charac\\Iori\\635.bmp", 0x0000FF);
		Iori.isHit = false;
	}

	else if (Iori.combo)
	{
		iShowBMP2(Iori.posX, Iori.posY, IoriCombo[bg2], 0x8CBD7B);

		if (IoriComboImage == 7)
		{
			IoriComboImage = 0;
		}
	}

	//stand image
	else
	{
		if (Iori.lost)
		{
			iShowBMP2(Iori.posX, Iori.posY, IoriLost[IoriLostImage], 0x8CBD7B);
		}

		else if (Iori.win)
		{
			iShowBMP2(Iori.posX, Iori.posY, IoriWin[0], 0x8CBD7B);
			iShowBMP2(Iori.posX, Iori.posY + 75, IoriWin[IoriWinImage], 0x0000FF);
		}

		else
			iShowBMP2(Iori.posX, Iori.posY, IoriStand[IoriStandImage], 0x8CBD7B);
	}


	if (Iori.comboEffect)
	{
		iShowBMP2(IoriComboX, Iori.posY, IoriComboEffect[0], 0x0000FF);
	}
}

void ShowCharacterKyo()
{
	iShowBMP2(70, 445, "Charac//bg//KyoName.bmp", 0x215218);
	iShowBMP2(10, 400, "Charac//bg//KyoFace.bmp", 0xFF00FF);
	//jump image 
	if (Kyo.jump)
	{
		if (Kyo.jumpUp)
		{
			if (Kyo.jumpY == 0)
			{
				iShowBMP2(Kyo.posX, Kyo.posY + Kyo.jumpY, KyoJump[0], 0x848484);
			}

			else
				iShowBMP2(Kyo.posX, Kyo.posY + Kyo.jumpY, KyoJump[1], 0x848484);
		}

		else
		{
			iShowBMP2(Kyo.posX, Kyo.posY + Kyo.jumpY, KyoJump[2], 0x848484);
		}
	}
	// run image
	else if (Kyo.run)
	{
		iShowBMP2(Kyo.posX, Kyo.posY, KyoRunForward[KyoRunImage], 0x848484);
	}
	//kick image
	else if (Kyo.kick)
	{
		iShowBMP2(Kyo.posX, Kyo.posY, KyoKick[KyokickImage], 0x848484);
	}
	else if (Kyo.isHit)
	{
		iShowBMP2(Kyo.posX, Kyo.posY, "Charac//Kyo//735.bmp", 0x848484);
		Kyo.isHit = false;
	}
	else if (Kyo.punch)
	{
		iShowBMP2(Kyo.posX, Kyo.posY, KyoPunch[KyoPunchImage], 0x848484);
	}

	else if (Kyo.back)
	{
		iShowBMP2(Kyo.posX, Kyo.posY, KyoGoBackward[KyoGoBackImage], 0x848484);
	}

	else if (Kyo.combo)
	{
		iShowBMP2(KyoComboX, Kyo.posY, KyoCombo[KyoComboImage], 0x848484);
	}

	//stand image
	else
	{
		if (Kyo.lost)
		{
			iShowBMP2(Kyo.posX, Kyo.posY, KyoLost[KyoLostImage], 0x848484);
		}

		else if (Kyo.win)
		{
			iShowBMP2(Kyo.posX, Kyo.posY, KyoWin[KyoWinImage], 0x848484);
		}

		else
			iShowBMP2(Kyo.posX, Kyo.posY, KyoStand[k], 0x848484);
	}

}



void ShowCharacterTerry()
{
	iShowBMP2(580, 445, "Charac//bg//TerryName.bmp", 0x215218);
	iShowBMP2(750, 400, "Charac//bg//TerryFace.bmp", 0xFF00FF);
	//jump image 
	if (Terry.jump)
	{
		if (Terry.jumpUp)
		{
			if (Terry.jumpY == 0)
			{
				iShowBMP2(Terry.posX, Terry.posY + Terry.jumpY, TerryJump[0], 0x000000);
			}

			else
				iShowBMP2(Terry.posX, Terry.posY + Terry.jumpY, TerryJump[1], 0x000000);
		}

		else
		{
			iShowBMP2(Terry.posX, Terry.posY + Terry.jumpY, TerryJump[2], 0x000000);
		}
	}
	// run image
	else if (Terry.run)
	{
		iShowBMP2(Terry.posX, Terry.posY, TerryRunForward[TerryRunImage], 0x000000);
	}
	//kick image
	else if (Terry.kick)
	{
		iShowBMP2(Terry.posX, Terry.posY, TerryKick[TerrykickImage], 0x000000);
	}

	else if (Terry.isHit)
	{
		iShowBMP2(Terry.posX, Terry.posY, "Charac\\Terry\\515.bmp", 0x000000);
		Terry.isHit = false;
	}

	else if (Terry.punch)
	{
		iShowBMP2(Terry.posX, Terry.posY, TerryPunch[TerryPunchImage], 0x000000);
	}

	else if (Terry.back)
	{
		iShowBMP2(Terry.posX, Terry.posY, TerryGoBackward[TerryGoBackImage], 0x000000);
	}

	else if (Terry.combo)
	{
	iShowBMP2(Terry.posX, Terry.posY, TerryCombo[TerryComboImage], 0x000000);
	}

	//stand image
	else
	{
		if (Terry.lost)
		{
			iShowBMP2(Terry.posX, Terry.posY, TerryLost[TerryLostImage], 0x000000);
		}

		else if (Terry.win)
		{
			iShowBMP2(Terry.posX, Terry.posY, TerryWin[TerryWinImage], 0x000000);
		}

		else
			iShowBMP2(Terry.posX, Terry.posY, TerryStand[TerryStandImage], 0x000000);
	}

	if (Terry.comboEffect)
	{
	 iShowBMP2(TerryComboX + 30, TerryComboY, "Charac\\Terry\\204.bmp", 0x000000);
	}
}

//shows background in game
void ShowBackground(char *BackGround)
{
	iShowBMP2(0, 0, BackGround, -1);
}


//shows character in single player mode
void ShowCharacterInSinglePlayer()
{
	HealthCheck();


	//Health Bars
	iSetColor(255, 255, 255);
	iFilledRectangle(86, 430.5, 252, 17);
	iFilledRectangle(492, 430.5, 252, 17);

	iSetColor(255, 0, 0);
	iFilledRectangle(87, 431, Ash1.health/2, 15);
	iFilledRectangle(743, 431.5, -Iori.health/2, 15);

	iSetColor(255, 0, 0);
	iFilledRectangle(87, 400, Ash1.hitCounter, 10);
	iFilledRectangle(743, 400.5, -Iori.hitCounter, 10);

	iText(260, 400, ShowScoreText1, GLUT_BITMAP_HELVETICA_18);
	iText(500, 400, ShowScoreText2, GLUT_BITMAP_HELVETICA_18);

	ShowCharacterAsh();
	ShowCharacterIori();

	//shows the game over image

}

//show character in multiplayer mode
void Multiplayer()
{
	ShowBackground(BackGround3[bg2]);
	HealthCheckMultiplayer();

	//Health Bars
	iSetColor(255, 255, 255);
	iFilledRectangle(86, 430.5, 252, 17);
	iFilledRectangle(492, 430.5, 252, 17);

	iSetColor(255, 0, 0);
	iFilledRectangle(87, 431, Kyo.health / 2, 15);
	iFilledRectangle(743, 431.5, -Terry.health / 2, 15);

	iSetColor(255, 0, 0);
	iFilledRectangle(87, 400, Kyo.hitCounter, 10);
	iFilledRectangle(743, 400.5, -Terry.hitCounter, 10);

	iText(260, 400, ShowScoreText1, GLUT_BITMAP_HELVETICA_18);
	iText(500, 400, ShowScoreText2, GLUT_BITMAP_HELVETICA_18);


	ShowCharacterKyo();
	ShowCharacterTerry();


	//on screeen buttons
	iShowBMP2(530, 5, "Charac\\bg\\Button\\red.bmp", 0x000000);
	iShowBMP2(575, 5, "Charac\\bg\\Button\\blue.bmp", 0x000000);
	iShowBMP2(620, 5, "Charac\\bg\\Button\\green.bmp", 0x000000);

	iShowBMP2(665, 5, "Charac\\bg\\Button\\left.bmp", 0x000000);
	iShowBMP2(710, 5, "Charac\\bg\\Button\\up.bmp", 0x000000);
	iShowBMP2(755, 5, "Charac\\bg\\Button\\right.bmp", 0x000000);
}





//shows single player levels
// case 1 : easy , case 2 : medium , case 3 : hard

void SinglePlayerLevel()
{
	switch (level)
	{
	case 1: ShowBackground(BackGround1[bg]);
		ShowCharacterInSinglePlayer();

		break;

	case 2: ShowBackground(BackGround2[bg1]);
		ShowCharacterInSinglePlayer();
		break;

	case 3: ShowBackground(BackGround3[bg2]);
		ShowCharacterInSinglePlayer();
		break;

	default:
		break;
	}
}



//start screen images and Intro
void StartScreen()
{
	iShowBMP(15, 100, intro[introImage]);
	iShowBMP2(450, 0, MenuBackground[1], 0xffffff);
}

//sub menus 
//case 1 : single player , case 2 : multiplayer , case 4 : controls , case 5 : credits , case 6 : score
void SubMenu()
{
	switch (menu)
	{
	case 1: iShowBMP2(0, 0, GameBackground[1], -1);
		iShowBMP2(70, 220, "Charac//bg//UI//easy.bmp", -1);
		iShowBMP2(70, 160, "Charac//bg//UI//medium.bmp", -1);
		iShowBMP2(70, 100, "Charac//bg//UI//hard.bmp", -1);
		iShowBMP2(70, 50, "Charac//bg//UI//back.bmp", -1);
		break;

	case 2: iShowBMP2(0, 0, GameBackground[0], -1);
		iShowBMP2(70, 100, "Charac//bg//UI//play.bmp", -1);
		iShowBMP2(70, 50, "Charac//bg//UI//back.bmp", -1);
		break;

	case 3: break;

	case 4: iShowBMP2(0, 0, GameBackground[2], -1);
		iShowBMP2(70, 50, "Charac//bg//UI//back.bmp", -1);
		iShowBMP2(70, 90, "Charac//bg//UI//controls1.bmp", -1);
		iShowBMP2(400, 90, "Charac//bg//UI//controls2.bmp", 0x000000);
		break;

	case 5: iShowBMP2(0, 0, "Charac//bg//Credits.bmp", -1);
		iShowBMP2(70, 50, "Charac//bg//UI//back.bmp", -1);
		
		break;

	case 6: //iShowBMP2(0, 0, GameBackground[4], -1);
		iShowBMP2(0, 0, "Charac//bg//HScore.bmp", -1);
	    iSetColor(255, 255, 255);
		iFilledRectangle(70, 100, 300, 300);
		highScoreShow();
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
	iShowBMP(70, 90, MenuUIWhite[7]);
	iShowBMP(70, 30, MenuUIWhite[6]);
	

	if (showPassiveMarks)
	{

		if (mposy >= 390 && mposy <= 440)
			iShowBMP(70, 390, menuUI[0]);

		if (mposy >= 330 && mposy <= 380)
			iShowBMP(70, 330, menuUI[1]);

		if (mposy >= 270 && mposy <= 320)
		{
			if (musicOn)
			        iShowBMP(70, 270, menuUI[2]);
			else
				iShowBMP(70, 270, menuUI[3]);
		}
		if (mposy >= 210 && mposy <= 250)
				iShowBMP(70, 210, menuUI[4]); 

		if (mposy >= 150 && mposy <= 200)
			iShowBMP(70, 150, menuUI[5]);

		if (mposy >= 30 && mposy <= 80)
			iShowBMP(70, 30, menuUI[6]);

		if (mposy >= 90 && mposy <= 130)
			iShowBMP(70, 90, menuUI[7]);
	}
}

//shows pause menus when game is paused
void pauseMenu()
{
	iShowBMP2(240, 300, "Charac//bg//UI//paused.bmp", 0x215218);
	iShowBMP(280, 230, "Charac//bg//UI//restart.bmp");
	iShowBMP(280, 170, "Charac//bg//UI//quittomain.bmp");
}

//Game Over screen of single player and multiplayer mode 
void GameOverScreen()
{

	iShowBMP2(250, 400, "Charac//bg//UI//gameover.bmp", 0x101010);

	//single player
	if (play){
		if (Ash1.win)
		{
			iSetColor(255, 0, 0);
			iFilledRectangle(330, 350, 110, 30);
			iSetColor(255, 255, 255);
			iText(338, 355, "You Won", GLUT_BITMAP_TIMES_ROMAN_24);
			showName();

			sprintf(YourScore, "Your Score : %d", Ash1.Score);
			iSetColor(255, 0, 0);
			iFilledRectangle(250, 150, 250, 30);
			iSetColor(255, 255, 255);
			iText(252, 157, YourScore, GLUT_BITMAP_TIMES_ROMAN_24);
		}

		else if (Ash1.lost)
		{
			iSetColor(255, 0, 0);
			iFilledRectangle(330, 350, 118, 30);
			iSetColor(255, 255, 255);
			iText(338, 355, "You lost", GLUT_BITMAP_TIMES_ROMAN_24);
			showName();
			sprintf(YourScore, "Your Score : %d", Ash1.Score);
			iSetColor(255, 0, 0);
			iFilledRectangle(250, 150, 250, 30);
			iSetColor(255, 255, 255);
			iText(252, 157, YourScore, GLUT_BITMAP_TIMES_ROMAN_24);
		}
	}

	//multipalyer
	if (isMultiPlayer){
		if (Kyo.win)
		{

			if (!ShowPauseMenus){
				iSetColor(255, 0, 0);
				iFilledRectangle(330, 350, 150, 30);
				iSetColor(255, 255, 255);
				iText(338, 355, "Player 1 Won", GLUT_BITMAP_TIMES_ROMAN_24);
				iShowBMP2(240, 255, "Charac//bg//PressP.bmp", 0x215218);
			}
		}
		else if (Terry.win)
		{

			if (!ShowPauseMenus){
				iSetColor(255, 0, 0);
				iFilledRectangle(330, 350, 150, 30);
				iSetColor(255, 255, 255);
				iText(338, 355, "Player 2 Won", GLUT_BITMAP_TIMES_ROMAN_24);
				iSetColor(255, 0, 0);
				iShowBMP2(240, 255, "Charac//bg//PressP.bmp", 0x215218);
			}
		}
	}

}

void iDraw()
{
	//place your drawing codes here

	iClear();


	if (showStartScreen) //shows intro
	{
		StartScreen();
	}

	if (PressSpaceToContinue) //shows press space to continue text at intro
	{
		iShowBMPAlternativeSkipWhite(20, 50, "Charac//bg//UI//main.bmp");
	}


	if (showMenu) // shows main menu
	{
		iShowBMP2(0, 0, MenuBackground[0], -1);
		iShowBMP2(380, 0, MenuBackground[1], 0xffffff);
		MainMenu();
	}

	if (menu) //shows submenu 
		SubMenu();

	if (play) //shows single player game play screen
	{
		showMenu = false;
		SinglePlayerLevel();
	}

	if (isMultiPlayer) //show multiplayer game play screen
	{
		showMenu = false;
		Multiplayer();
	}	

	if (isGameOver) //show game over text and ask kor name to save score
	{
		
		GameOverScreen();
	}

	if (ShowPauseMenus) //shows pause menu
	{
		pauseMenu();
	}
}

/*
function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{

}

void iPassiveMouseMove(int mx, int my)
{
	//shows alternative menu button if mouse pointer is in the button's area

	if (mx > 70 && mx < 280 && showMenu)
	{
		if (my > 390 && my < 440)
		{
			mposx = 70;
			mposy = 390;
			showPassiveMarks = true;
		}

		if (my > 330 && my < 370)
		{
			mposx = 70;
			mposy = 330;
			showPassiveMarks = true;
		}

		if (my > 270 && my < 320)
		{
			mposx = 70;
			mposy = 270;
			showPassiveMarks = true;
		}

		if (my > 210 && my < 260)
		{
			mposx = 70;
			mposy = 210;
			showPassiveMarks = true;
		}

		if (my > 150 && my < 200)
		{
			mposx = 70;
			mposy = 150;
			showPassiveMarks = true;
		}


		if (my > 90 && my < 140)
		{
			mposx = 70;
			mposy = 90;
			showPassiveMarks = true;
		}

		if (my > 30 && my < 80)
		{
			mposx = 70;
			mposy = 30;
			showPassiveMarks = true;
		}

	   if (!(my>30 && my< 440))
			showPassiveMarks = false;
	}

	else if (!(mx > 70 && mx < 280) && showMenu)
		showPassiveMarks = false;



}
/*
function iMouse() is called when the user presses/releases the mouse.
(mx, my) is the position where the mouse pointer is.
*/

void iMouse(int button, int state, int mx, int my)
{


	//activating name input box
	if (isEnterName && isGameOver)
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			if (mx > 250 && mx < 500 && my>250 && my < 280)
			{
				isClicked = true;
			}
		}
	}

	//MultiPlayer Mouse Controls for on screen buttons
	if (isMultiPlayerPlay)
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		{
			//power button red
			if (mx > 530 && mx < 570 && my>5 && my < 43 && Terry.comboOn)
			{
				TerryComboX = Terry.posX - 10;
				TerryComboY = Terry.posY;
				Terry.DoCombo();
				//Terry.combo = true;
				//Terry.comboEffect = false;
				TerryComboImage = 0;
			}

			//punch button blue
			if (mx > 575 && mx < 615 && my>5 && my < 43 && !Terry.punchOn && !Terry.punch && !Terry.isHit)
			{
				TerryPunchImage = 0;
				Terry.DoPunch();
			}


			//kick button green
			if (mx > 620 && mx < 640 && my>5 && my < 43 && !Terry.kickOn && !Terry.kick && !Terry.isHit)
			{
				TerrykickImage = 0;
				Terry.DoKick();
			}

			//go left button
			if (mx > 665 && mx < 705 && my>5 && my < 43 && !Terry.run)
			{
				TerryRunImage = 0;
				Terry.DoGoForward();
			}

			//go right button
			if (mx > 710 && mx < 750 && my>5 && my < 43 && Terry.jumpY==0)
			{
				if (!Terry.jump)
				{
					Terry.DoJump();
				}
			}


			//jump button
			if (mx > 755 && mx < 795 && my>5 && my < 43 && !Terry.back)
			{
				TerryGoBackImage = 0;
				Terry.DoGoBackWard();
			}
		}
	}


	//works when game is in main menu screen
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && showMenu)
	{
		if (mx > 70 && mx < 280)
		{
			if (my > 390 && my < 440) //single player
			{
				menu = 1;
				showSinglePlayerLevel = true;
				showMenu = false;
			}

			if (my > 330 && my < 370) //multiplayer
			{
				menu = 2;
				showMenu = false;
			}

			if (my > 270 && my < 320) //music on/off
			{
				menu = 3;

				if (musicOn){
					PlaySound(0, 0, 0);
					musicOn = false;
				}
				else
				{
						PlaySound("Charac\\menu_sound1.wav", NULL, SND_LOOP | SND_ASYNC);
						musicOn = true;
				}
			}

			if (my > 210 && my < 260) //controls 
			{
				menu = 4;
				showMenu = false;
			}

			if (my > 150 && my < 200) //about 
			{
				menu = 5;
				showMenu = false;
			}


			if (my > 90 && my < 140) //score
			{
				menu = 6;
				showMenu = false;
			}

			if (my > 30 && my < 80) //exit
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


	//multiplayer play button
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && menu == 2)
	{
		if (mx > 70 && mx < 270 && my>100 && my < 150)
		{
			Kyo = character(200, 50);
			Kyo.initialState();

			Terry = character(450, 50);
			Terry.initialState();

			strcpy(ShowScoreText1, "0");
			strcpy(ShowScoreText2, "0");

			menu = -1;

			isMultiPlayer = true;
			isMultiPlayerPlay = true;
			pause = true;
			isGameOver = false;
			iResumeTimer(1);
			iResumeTimer(2);
			iResumeTimer(3);
			iResumeTimer(4);
			iResumeTimer(0);
			iResumeTimer(5);
			iResumeTimer(6);
			iResumeTimer(7);
		}
	}


	//single player level selection
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && showSinglePlayerLevel == true)
	{
		//easy
		if (mx > 70 && mx < 270 && my>220 && my < 270)
		{

			Ash1 = character(200, 50);
			Ash1.initialState();

			RandomMove = 0;
			Iori = character(450, 50);
			Iori.initialState();
			readScoreOnce = true;

			strcpy(ShowScoreText1, "0");
			strcpy(ShowScoreText2, "0");

			OpponentSelectRandomMove = true;
			level = 1;
			play = true;
			isPlay = true;
			pause = true;
			showSinglePlayerLevel = false;
			isGameOver = false;
		}

		//medium
		if (mx > 70 && mx < 270 && my>160 && my < 210)
		{
			Ash1 = character(200, 50);
			Ash1.initialState();

			RandomMove = 0;
			Iori = character(450, 50);
			Iori.initialState();
			
			strcpy(ShowScoreText1, "0");
			strcpy(ShowScoreText2, "0");

			OpponentSelectRandomMove = true;
			level = 2;
			play = true;
			isPlay = true;
			pause = true;
			showSinglePlayerLevel = false;
			isGameOver = false;
		}


		//hard
		if (mx > 70 && mx < 270 && my>100 && my < 150)
		{
			Ash1 = character(200, 50);
			Ash1.initialState();

			RandomMove = 0;
			Iori = character(450, 50);
			Iori.initialState();
			
			strcpy(ShowScoreText1, "0");
			strcpy(ShowScoreText2, "0");

			OpponentSelectRandomMove = true;
			level = 3;
			play = true;
			isPlay = true;
			pause = true;
			showSinglePlayerLevel = false;
			isGameOver = false;
		}

	}

	//pause menus for single player mode
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && ShowPauseMenus == true && play)
	{
		//restart
		if (mx > 280 && mx < 480 && my>230 && my < 280 && level)
		{
			play = true;
			pause = true;
			ShowPauseMenus = false;
			isPlay = true;
			isGameOver = false;

			Ash1 = character(200, 50);
			Ash1.initialState();
			readScoreOnce = true;
			Iori = character(450, 50);
			Iori.initialState();
			OpponentSelectRandomMove = true;
			RandomMove = 0;
			iResumeTimer(1);
			iResumeTimer(2);
			iResumeTimer(3);
			iResumeTimer(4);
			iResumeTimer(0);
		}

		//quit to main menu 
		if (mx > 280 && mx < 480 && my>170 && my < 220 && level)
		{
			showMenu = true;
			ShowPauseMenus = false;
			play = false;
			isPlay = false;
			pause = false;
			menu = 0;
			isGameOver = false;
			showSinglePlayerLevel = false;
			iResumeTimer(1);
			iResumeTimer(2);
			iResumeTimer(3);
			iResumeTimer(4);
			iResumeTimer(0);
		}
	}


	//pause menus for multiplayer mode
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && ShowPauseMenus == true && isMultiPlayer)
	{
		//restart
		if (mx > 280 && mx < 480 && my>230 && my < 280)
		{
			pause = true;
			ShowPauseMenus = false;
			isMultiPlayerPlay = true;
			isGameOver = false;

			strcpy(ShowScoreText1, "0");
			strcpy(ShowScoreText2, "0");

			Kyo = character(200, 50);
			Kyo.initialState();

			Terry = character(450, 50);
			Terry.initialState();
			iResumeTimer(1);
			iResumeTimer(2);
			iResumeTimer(3);
			iResumeTimer(4);
			iResumeTimer(0);
			iResumeTimer(5);
			iResumeTimer(6);
			iResumeTimer(7);
		}

		//quit to main menu
		if (mx > 280 && mx < 480 && my>170 && my < 220)
		{
			showMenu = true;
			ShowPauseMenus = false;
			isMultiPlayer = false;
			isMultiPlayerPlay = false;
			menu = 0;
			isGameOver = false;
			iResumeTimer(1);
			iResumeTimer(2);
			iResumeTimer(3);
			iResumeTimer(4);
			iResumeTimer(0);
			iResumeTimer(5);
			iResumeTimer(6);
			iResumeTimer(7);
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

	//name and score after the game is over
	if (isEnterName && isGameOver && isClicked)
	{
		if (key == '\r' && len > 0)
		{
			AppendHighScore(ShowOnScreen, Ash1.Score);
			readHighScore();
			for (int i = 0; i < len; i++)
			{
				str[i] = 0;
				strcpy(ShowOnScreen, str);
			}

			len = 0;
			isEnterName = false;
			isClicked = false;
			showMenu = true;
			ShowPauseMenus = false;
			play = false;
			isPlay = false;
			pause = false;
			menu = 0;
			isGameOver = false;
			showSinglePlayerLevel = false;
		}
		else if (key == '\b')
		{
			if (len > 0)
			{
				str[--len] = '\0';
				strcpy(ShowOnScreen, str);
			}
		}
		else
		{
			if (len < 20)
			{
				str[len] = key;
				strcpy(ShowOnScreen, str);
				len++;
			}
		}

	}


    //pauses the game
	if (key == 'p' && !isEnterName)
	{
		//do something with 'q'
		iPauseTimer(0);
		iPauseTimer(1);
		iPauseTimer(2);
		iPauseTimer(3);
		iPauseTimer(4);
		iPauseTimer(5);
		iPauseTimer(6);
		iPauseTimer(7);

	}

	//resumes the game
	if (key == 'r' && !isEnterName)
	{
		iResumeTimer(0);
		iResumeTimer(1);
		iResumeTimer(2);
		iResumeTimer(3);
		iResumeTimer(4);
		iResumeTimer(5);
		iResumeTimer(6);
		iResumeTimer(7);
	}

	// Press space to continue at intro
	if (key == ' ' &&  mainMenu == false)
	{
		PressSpaceToContinue = false;
		showMenu = true;
		showPrmp = false;
		mainMenu = true;
		musicOn = true;
		showStartScreen = false;

		PlaySound(0, 0, 0);

		PlaySound("Charac\\menu_sound1.wav", NULL, SND_LOOP | SND_ASYNC);
	}


	//pause and resume in single player
	if (!isEnterName)
	{
		if (play && key == 'p')
		{
			ShowPauseMenus = true;
		}

		if (play && key == 'r')
		{
			ShowPauseMenus = false;
		}

	}

	//pause and resume is multiplayer
	if (isMultiPlayer && key == 'p')
	{
		ShowPauseMenus = true;
	}

	if (isMultiPlayer && key == 'r')
	{
		ShowPauseMenus = false;
	}

	//single player control on until the game is not over 
	if (isPlay)
	{
		if (!Ash1.kick && !Ash1.kickOn && Ash1.punchOn == false /*&& play*/ && key == 'd' || key == 'D' && !Ash1.isHit)
		{
			Ash1.kickOn = true;
			Ash1.DoKick();
			AshkickImage = 0;
			Ash1.standCounter = 0;
		}

		else if (!Ash1.punch && !Ash1.punchOn && Ash1.kickOn == false /*&& play*/ && key == 's' || key == 'S' && !Ash1.isHit)
		{
			Ash1.punchOn = true;
			Ash1.DoPunch();
			AshPunchImage = 0;
			Ash1.standCounter = 0;
		}

		else if (Ash1.comboOn && !isAshCombo &&  key == 'A' || key == 'a')
		{
			//Ash1.hitCounter++;
			//Ash1.comboOn = true;
			isAshCombo = true;
			AshComboX = Ash1.posX;
			AshComboY = Ash1.posY + 20;
			//Ash1.comboOn = false;
			Ash1.DoCombo();
			Ash1.standCounter = 0;
			AshComboImage = 0;
		}


	}


	//player 1 control in Multiplayer mode
	if (isMultiPlayerPlay) 
	{
		if (!Kyo.kick && !Kyo.kickOn && Kyo.punchOn == false && key == 'd' || key == 'D' && !Kyo.isHit)
		{
			Kyo.kickOn = true;
			Kyo.DoKick();
			KyokickImage = 0;
			Kyo.standCounter = 0;
		}

		else if (!Kyo.punch && !Kyo.punchOn && Kyo.kickOn == false && key == 's' || key == 'S' && !Kyo.isHit)
		{
			Kyo.punchOn = true;
			Kyo.DoPunch();
			KyoPunchImage = 0;
			Kyo.standCounter = 0;
		}

		else if (Kyo.comboOn && key == 'a' || key == 'A')
		{
			KyoComboX = Kyo.posX;
			KyoComboY = Kyo.posY;
			Kyo.DoCombo();
			//Kyo.comboOn = false;
			KyoComboImage = 0;
			Kyo.standCounter = 0;
			Kyo.hitCounter = 0;
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

	//single player movement controls
	if (isPlay)
	{
		if (!Ash1.back && key == GLUT_KEY_LEFT)
		{
			Ash1.DoGoBackWard();
			AshGoBackImage = 0;
		}

		if (!Ash1.run && key == GLUT_KEY_RIGHT)
		{
			Ash1.DoGoForward();
			AshRunImage = 0;
		}


		if (key == GLUT_KEY_UP && Ash1.jumpY == 0)
		{
			if (!Ash1.jumpUp)
			{
				Ash1.DoJump();
			}
		}
	}

	//multiplayer player 1 controls
	if (isMultiPlayerPlay)
	{
		if (!Kyo.back && key == GLUT_KEY_LEFT)
		{
			Kyo.DoGoBackWard();
			KyoGoBackImage = 0;
			Kyo.standCounter = 0;
		}

		if (!Kyo.run && key == GLUT_KEY_RIGHT)
		{
			Kyo.DoGoForward();
			KyoRunImage = 0;
			Kyo.standCounter = 0;
		}


		if (key == GLUT_KEY_UP && Kyo.jumpY == 0)
		{
			if (!Kyo.jumpUp)
			{
				Kyo.DoJump();
			}
		}
	}

}


//checks collision between player 1 and player 2 in multiplayer mode
void HealthCheckMultiplayer()
{
	if (!ShowPauseMenus)
	{
		if (Terry.posX > Kyo.posX && Terry.posX < Kyo.posX + 80 && Terry.posY + 50>Kyo.posY && Terry.posY + 50 < Kyo.posY + 100 && (Terry.punch || Terry.kick) && isMultiPlayerPlay)
		{
			//Kyo.isHit = true;
			if (Terry.hitCounter < 100)
			{
				Terry.hitCounter++;
				if (Terry.hitCounter >= 100)
				{
					Terry.comboOn = true;
					Terry.hitCounter = 100;
				}
			}


			Kyo.health -= 1;


			if (Terry.punch)
				Terry.Score += 10;

			if (Terry.kick)
				Terry.Score += 30;

			sprintf(ShowScoreText2, "%d", Terry.Score);

			if (Kyo.health <= 0)
			{
				iSetColor(255, 255, 255);
				iFilledRectangle(300, 400, 120, 70);
				iSetColor(255, 0, 0);
	
				isMultiPlayerPlay = false;
				Kyo.lost = true;
				Terry.win = true;
				isGameOver = true;
			}
		}

		else if (TerryComboX >= Kyo.posX && TerryComboX <= Kyo.posX + 10 && Terry.comboEffect /*&& TerryComboY >= Kyo.posY && TerryComboY <= Kyo.posY + 110 /*&& Terry.comboOn/*&& AshComboX <= Terry.posX + 80*/)
		{
			Terry.Score += 50;
			sprintf(ShowScoreText2, "%d", Terry.Score);
			//Kyo.isHit = true;
			Kyo.health -= 10;
			Terry.combo = false;
			Terry.comboEffect = false;
			TerryComboX = 0;
			Terry.comboOn = false;
			Terry.hitCounter = 0;

			if (Kyo.health <= 0)
			{
				Kyo.health = 0;
				iSetColor(255, 255, 255);
				iFilledRectangle(300, 400, 120, 70);
				iSetColor(255, 0, 0);
		
				isMultiPlayerPlay = false;
				Kyo.lost = true;
				Terry.win = true;
				isGameOver = true;
			}
		}



		//checks the collision between kyo and terry when kyo does punch or kick
		if (Kyo.posX + 80 >= Terry.posX && Kyo.posX + 80 <= Terry.posX + 80 && Kyo.posY >= Terry.posY && Kyo.posY <= Terry.posY + 120 && (Kyo.punch || Kyo.kick || Kyo.combo) && isMultiPlayerPlay)
		{
			

			//Terry.isHit = true;


			if (Kyo.hitCounter <= 100)
			{
				Kyo.hitCounter++;
				if (Kyo.hitCounter >= 100)
				{
					Kyo.comboOn = true;
					Kyo.hitCounter = 100;
				}
			}





			Terry.health -= 1;

			if (Kyo.punch)
				Kyo.Score += 10;

			if (Kyo.kick)
				Kyo.Score += 30;

			if (Kyo.combo)
			{
				Kyo.Score += 50;
			}

			sprintf(ShowScoreText1, "%d", Kyo.Score);

			if (Terry.health <= 0)
			{
				iSetColor(255, 255, 255);
				iFilledRectangle(300, 400, 120, 70);
				iSetColor(255, 0, 0);
				
				isMultiPlayerPlay = false;
				Kyo.win = true;
				Terry.lost = true;
				isGameOver = true;
			}
		}

		else if (Kyo.posX + 80 >= Terry.posX && Kyo.posX + 80 <= Terry.posX + 80 && Kyo.posY >= Terry.posY && Kyo.posY <= Terry.posY + 120 && Kyo.comboOn /*&& AshComboX+50 <= Terry.posX+80 */ /*&& Kyo.combo*/)
		{
			Kyo.Score += 50;
			sprintf(ShowScoreText1, "%d", Kyo.Score);
			Terry.health -= 20;
			//Kyo.combo = false;
			Kyo.comboEffect = false;
			KyoComboX = Kyo.posX;
			Kyo.comboOn = false;

			if (Terry.health <= 0)
			{
				Terry.health = 0;
				iSetColor(255, 255, 255);
				iFilledRectangle(300, 400, 120, 70);
				iSetColor(255, 0, 0);
				
				isMultiPlayerPlay = false;
				Kyo.win = true;
				Terry.lost = true;
				isGameOver = true;
			}
		}
	}
}


//checks the collision between player and oppnent in single player mode 
void HealthCheck()
{
	if (!ShowPauseMenus)
	{
		if (Iori.posX > Ash1.posX && Iori.posX < Ash1.posX + 80 && Iori.posY + 50>Ash1.posY && Iori.posY + 50 < Ash1.posY + 100 && (Iori.punch || Iori.kick) && isPlay)
		{
			Ash1.isHit = true;
			if (Iori.hitCounter < 100)
			{
				Iori.hitCounter++;
				if (Iori.hitCounter >= 100)
				{
					Iori.comboOn = true;
					Iori.hitCounter = 100;
				}
			}

			if (level == 1)
				Ash1.health -= 1;

			else if (level == 2)
				Ash1.health -= 5;

			else
				Ash1.health -= 8;


			if (Iori.punch)
				Iori.Score += 10;

			if (Iori.kick)
				Iori.Score += 30;

			sprintf(ShowScoreText2, "%d", Iori.Score);

			if (Ash1.health <= 0)
			{
				isPlay = false;
				Ash1.lost = true;
				Iori.win = true;
				isGameOver = true;
				isEnterName = true;
				OpponentSelectRandomMove = false;
				RandomMove = 0;
			}
		}

		else if (IoriComboX > Ash1.posX && IoriComboX < Ash1.posX + 1000 && IoriComboY >= Ash1.posY && IoriComboY <= Ash1.posY + 110 && Iori.comboOn/*&& AshComboX <= Iori.posX + 80*/)
		{
			Ash1.isHit = true;
			Ash1.health -= 20;
			Iori.combo = false;
			Iori.comboEffect = false;
			IoriComboX = 0;
			Iori.comboOn = false;
			Iori.Score += 50;

			sprintf(ShowScoreText2, "%d", Iori.Score);
			if (Ash1.health <= 0)
			{
				Ash1.health = 0;

				isPlay = false;
				Ash1.lost = true;
				Iori.win = true;
				isGameOver = true;
				isEnterName = true;
				OpponentSelectRandomMove = false;
				RandomMove = 0;
			}
		}



		//checks collision between ash and iori when ash does punch or kick
		if (Ash1.posX + 80 >= Iori.posX && Ash1.posX + 80 <= Iori.posX + 80 && Ash1.posY >= Iori.posY && Ash1.posY <= Iori.posY + 120 && (Ash1.punch || Ash1.kick) && isPlay)
		{
			//iFilledRectangle(Ash1.posX, Ash1.posY, 100, 100);
			Iori.isHit = true;
			if (Ash1.hitCounter < 100)
			{
				Ash1.hitCounter++;

				if (Ash1.hitCounter >= 100)
				{
					Ash1.comboOn = true;
					isAshCombo = false;
					Ash1.hitCounter = 100;
				}
			}

			Iori.health -= 1;

			if (Ash1.punch)
				Ash1.Score += 10;

			if (Ash1.kick)
				Ash1.Score += 30;

			sprintf(ShowScoreText1, "%d", Ash1.Score);

			if (Iori.health <= 0)
			{
				isPlay = false;
				Ash1.win = true;
				Iori.lost = true;
				isGameOver = true;
				isEnterName = true;
				OpponentSelectRandomMove = false;
				RandomMove = 0;
			}
		}

		else if (AshComboX > Iori.posX - 50 && AshComboY >= Iori.posY && AshComboY <= Iori.posY + 110 && AshComboX < Iori.posX && Ash1.comboOn/*&& AshComboX+50 <= Iori.posX+80 */ /*&& Ash1.combo*/)
		{
			Iori.hit = true;
			iFilledRectangle(10, 10, 10, 50);
			Iori.health -= 20;
			Ash1.combo = false;
			Ash1.comboEffect = false;
			AshComboX = Ash1.posX;
			Ash1.comboOn = false;
			isAshCombo = false;

			Ash1.hitCounter = 0;
			Ash1.Score += 50;
			sprintf(ShowScoreText1, "%d", Ash1.Score);
			if (Iori.health <= 0)
			{
				Iori.health = 0;

				isPlay = false;
				Ash1.win = true;
				Iori.lost = true;
				isGameOver = true;
				isEnterName = true;
				OpponentSelectRandomMove = false;
				RandomMove = 0;
			}
		}
	}
}

//generates random movement for opponet in single player mode
void MoveSelect()
{
	srand(time(0));

    if (OpponentSelectRandomMove)
	{
		if (Iori.posX - Ash1.posX < 40)
		{
			RandomMove = rand() % 3;
		}

		else if (RandomMove != 1 || RandomMove != 2 || RandomMove != 3 || RandomMove != 4 || RandomMove != 5 || RandomMove!=6)
			RandomMove = rand() % 7;
	}


}

/*
  rendering functions : 
  changes the value of index of character image arrays 

  character. run = renders run images
             back = renders going back images
			 punch = renders punch images
			 kick = renders kick images
			 jump = renders jump images
			 combo = renders character power action images
			 comboEffect = renders power images
			 lost = render lost images
			 win = renders winning celebration images
*/

//does movement of opponent(Iori) according to the move which has been generated by MoveSelect() 
void OpponentMovementAI()
{
	switch (RandomMove)
	{
	case 6:  if (!Iori.jump && Iori.jumpY == 0)
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

	case 5: if (Iori.comboOn)
	{
		IoriComboX = Iori.posX - 50;
		IoriComboY = Iori.posY;
		Iori.combo = true;
		Iori.comboEffect = true;
		//	Iori.DoCombo();
		IoriComboImage = 0;
		Iori.hitCounter = 0;
		RandomMove = 0;
	}
			break;
	}


	if (Iori.stand)
	{
		IoriStandImage++;

		if (IoriStandImage >= 9)
		{
			IoriStandImage = 0;
			//MoveSelect();
		}
	}

	if (Iori.jump)
	{

		if (Iori.jumpUp)
		{
			Iori.jumpY += 70;

			if (Iori.jumpY >= 200)
			{
				Iori.jumpUp = false;
				//RandomMove = 0;
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
				//MoveSelect();
			}
		}
	}

	if (Iori.back)
	{
		IoriGoBackImage++;

		if (IoriGoBackImage >= 7)
		{
			IoriGoBackImage = 0;
		}

		Iori.standCounter++;

		if (Iori.posX <= 740)
			Iori.posX += 10;

		if (Iori.standCounter >= 8)
		{
			Iori.standCounter = 0;
			RandomMove = 0;
			Iori.back = false;
			//MoveSelect();
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
			//MoveSelect();
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
			//MoveSelect();
		}
	}

	if (Iori.run)
	{
		IoriRunImage++;


		if (IoriRunImage >= 8)
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
			//MoveSelect();
		}
	}

	if (Iori.lost)
	{
		IoriLostImage++;

		if (IoriLostImage >= 8)
		{
			IoriLostImage = 8;
		}
	}

	if (Iori.win)
	{
		IoriWinImage++;

		if (IoriWinImage >= 7)
		{
			IoriWinImage = 1;
		}
	}

	if (Iori.combo)
	{
		IoriComboImage++;

		if (IoriComboImage == 8)
		{
			IoriComboImage = 0;
		}


		if (IoriComboImage == 4)
		{
			Iori.comboEffect = true;
		}

		if (Iori.comboEffect)
		{
			IoriComboX -= 20;
		}

		Iori.standCounter++;

		if (Iori.standCounter == 8)
		{
			Iori.combo = false;
			Iori.standCounter = 0;
			//MoveSelect();
		}

	}


}


//renders the character terry
void CharacterTerryRender()
{
	if (Terry.stand)
	{
		TerryStandImage++;

		if (TerryStandImage == 8)
			TerryStandImage = 0;
	}



	//changes the value of Y co ordinate if the character jumps

	if (Terry.jump)
	{
		if (Terry.jumpUp)
		{
			Terry.jumpY += 70;

			if (Terry.jumpY >= 200)
			{
				Terry.jumpUp = false;
			}
		}

		else
		{
			Terry.jumpY -= 70;

			if (Terry.jumpY < 0)
			{
				Terry.jump = false;
				Terry.jumpY = 0;
			}
		}
	}



	if (Terry.run)
	{
		TerryRunImage++;

		if (TerryRunImage >= 10)
		{
			TerryRunImage = 0;
		}

		Terry.standCounter++;

		if (Terry.posX >= 0)
			Terry.posX -= 10;

		if (Terry.standCounter >= 10)
		{
			Terry.standCounter = 0;
			Terry.run = false;
		}
	}




	if (Terry.kick)
	{
		TerrykickImage++;

		if (TerrykickImage == 5)
		{
			TerrykickImage = 0;
		}

		Terry.standCounter++;

		if (Terry.standCounter >= 5)
		{
			Terry.standCounter = 0;
			Terry.kick = false;
			Terry.kickOn = false;
		}
	}

	if (Terry.punch)
	{
		TerryPunchImage++;

		if (TerryPunchImage == 8)
		{
			TerryPunchImage = 0;
		}

		Terry.standCounter++;

		if (Terry.standCounter >= 8)
		{
			Terry.standCounter = 0;
			Terry.punch = false;
			Terry.punchOn = false;
		}

	}

	if (Terry.back)
	{
		TerryGoBackImage++;

		if (TerryGoBackImage == 12)
		{
			TerryGoBackImage = 0;
		}

		Terry.standCounter++;

		if (Terry.posX <= 740)
			Terry.posX += 10;

		if (Terry.standCounter == 12)
		{
			Terry.standCounter = 0;
			Terry.back = false;
		}
	}

	if (Terry.lost)
	{
		TerryLostImage++;

		if (TerryLostImage >= 5)
		{
			TerryLostImage = 5;
			isMultiPlayerPlay = false;
		}
	}

	if (Terry.win)
	{
		TerryWinImage++;

		if (TerryWinImage >= 10)
		{
			TerryWinImage = 10;
			isMultiPlayerPlay = false;
		}
	}

	if (Terry.combo)
	{
		TerryComboImage++;

		if (TerryComboImage >= 12)
		{
			TerryComboImage = 0;
		}

		if (TerryComboImage >= 5)
		{
			Terry.comboEffect = true;
		}

		Terry.standCounter++;

		if (Terry.standCounter >= 17)
		{
			Terry.combo = false;
			Terry.standCounter = 0;
		}
	}

	if (Terry.comboEffect)
	{
		TerryComboX -= 20;
	}
}

//renders the character kyo
void CharacterKyoRender()
{
	if (Kyo.stand)
	{
		k++;

		if (k == 8)
			k = 0;
	}



	//changes the value of Y co ordinate if the character jumps

	if (Kyo.jump)
	{
		if (Kyo.jumpUp)
		{
			Kyo.jumpY += 70;

			if (Kyo.jumpY >= 200)
			{
				Kyo.jumpUp = false;
			}
		}

		else
		{
			Kyo.jumpY -= 70;

			if (Kyo.jumpY < 0)
			{
				Kyo.jump = false;
				Kyo.jumpY = 0;
			}
		}
	}



	if (Kyo.run)
	{
		KyoRunImage++;

		if (KyoRunImage >= 5)
		{
			KyoRunImage = 0;
		}

		Kyo.standCounter++;

		if (Kyo.posX <= 720)
			Kyo.posX += 20;

		if (Kyo.standCounter >= 8)
		{
			Kyo.standCounter = 0;
			Kyo.run = false;
		}
	}




if (Kyo.kick)
{
	KyokickImage++;

	if (KyokickImage == 9)
	{
		KyokickImage = 0;
	}

	Kyo.standCounter++;

	if (Kyo.standCounter >= 8)
	{
		Kyo.standCounter = 0;

		Kyo.kick = false;
		Kyo.kickOn = false;
	}
}

	if (Kyo.punch)
	{
		KyoPunchImage++;

		if (KyoPunchImage == 15)
		{
			KyoPunchImage = 0;
		}

		Kyo.standCounter++;

		if (Kyo.standCounter >= 16)
		{
			Kyo.standCounter = 0;
			Kyo.punch = false;
			Kyo.punchOn = false;
		}

	}

	if (Kyo.back)
	{
		KyoGoBackImage++;

		if (KyoGoBackImage == 7)
		{
			KyoGoBackImage = 0;
		}

		Kyo.standCounter++;

		if (Kyo.posX >= 8)
			Kyo.posX -= 10;

		if (Kyo.standCounter == 7)
		{
			Kyo.standCounter = 0;
			Kyo.back = false;
		}
	}

	if (Kyo.lost)
	{
		KyoLostImage++;

		if (KyoLostImage >=5)
		{
			KyoLostImage = 5;
			isMultiPlayerPlay = false;
		}
	}

	if (Kyo.win)
	{
		KyoWinImage++;

		if (KyoWinImage >= 12)
		{
			KyoWinImage = 12;
			
		}
	}

	if (Kyo.combo)
	{
		KyoComboImage++;

		if (KyoComboImage >= 12)
		{
			KyoComboImage = 0;
		}

		/*if (KyoComboImage >= 8)
		{
			Kyo.comboOn = true;
		}*/

		Kyo.standCounter++;

		if (Kyo.standCounter >= 12)
		{
			Kyo.combo = false;
			Kyo.comboOn = false;
			Kyo.standCounter = 0;
		}
	}

	if (Kyo.comboEffect)
	{
		KyoComboX += 20;
	}
}

//renders the character Ash
void CharacterAshRender()
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
			Ash1.posX += 20;

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
			Ash1.kickOn = false;
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
			Ash1.punchOn = false;
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
			AshLostImage = 8;
			isPlay = false;
		}
	}

	if (Ash1.win)
	{
		AshWinImage++;

		if (AshWinImage == 15)
		{
			AshWinImage = 0;
		}
	}

	if (Ash1.combo)
	{
		AshComboImage++;

		if (AshComboImage == 17)
		{
			AshComboImage = 0;
		}

		if (AshComboImage >= 12)
		{
			Ash1.comboEffect = true;
		}

		Ash1.standCounter++;

		if (Ash1.standCounter == 17)
		{
			Ash1.combo = false;
			Ash1.standCounter = 0;
		}
	}

	if (Ash1.comboEffect)
	{
		AshComboX += 20;
	}

}



//changes the images at intro
void StartScreenChange()
{
	introImage++;

	if (introImage == 833)
		introImage = 0;
}


//renders game background
void bgRender()
{
	bg++;

	if (bg == 15)
		bg = 0;

	bg1++;

	if (bg1 == 4)
		bg1 = 0;

	bg2++;

	if (bg2 == 7)
		bg2 = 0;
}

//shows the "Press space to continue text" 
void ShowStartScreenText()
{
	if (showPrmp)
	{
		if (!PressSpaceToContinue)
			PressSpaceToContinue = true;
		else
			PressSpaceToContinue = false;
	}
}

int main()
{
	//place your own initialization codes here.
	readHighScore();
	iInitialize(sLength, sWidth, "King Of Fighters");
	

	if (showPrmp) //intro music
	     PlaySound("Charac\\music.wav", NULL, SND_LOOP | SND_ASYNC);
	
	timers[0] = iSetTimer(800, MoveSelect);
	timers[1] = iSetTimer(100, CharacterAshRender);
	timers[2] = iSetTimer(100, OpponentMovementAI);
	timers[3] = iSetTimer(30, StartScreenChange);
	timers[4] = iSetTimer(500, bgRender);
	timers[5] = iSetTimer(100, ShowStartScreenText);
	timers[6] = iSetTimer(100, CharacterKyoRender);
	timers[7] = iSetTimer(100, CharacterTerryRender);
	

	iStart();

	return 0;
}

