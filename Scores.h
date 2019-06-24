char ShowOnScreen[100];
int numberArray[100];
int arrayIndex = 0, stringIndex = 0;
char st[100][100];
int numberIndex = 0;
int rank = 0;
char rankText[10];
bool isClicked = false;

void AppendHighScore(char name[], int n) //adds new score record in txt file 
{
	FILE *fp = fopen("HighScore.txt", "a");

	if (fp != NULL)
	{
		fprintf(fp, "%s %d\n", name,n);	
	}

	fclose(fp);
}

//reads the saved highscore from HighScore.txt file and stores in array (st and numberarray) for sorting 
// st - stores the player names
// numberArray - stores scores
void readHighScore() 
{
	FILE *fp = fopen("HighScore.txt", "r");
	char str[100];
	int score;
	arrayIndex = 0, stringIndex = 0;

	if (fp != NULL)
	{
		while (fscanf(fp, "%s%d\n", str, &score) != EOF)
		{
			strcpy(st[stringIndex++], str);
			numberArray[arrayIndex++] = score;
		}
	}

	fclose(fp);
}


void SortingHighScore()//Sorts the highScores using bubblesort algorithm and gets called from highScoreShow()
{
	int temp;
	char t[100];

	for (int i = 0; i < arrayIndex - 1; i++)
	{
		for (int j = 0; j < arrayIndex - 1; j++)
		{
			if (numberArray[j] < numberArray[j + 1])
			{
				temp = numberArray[j];
				numberArray[j] = numberArray[j + 1];
				numberArray[j + 1] = temp;
				strcpy(t, st[j]);
				strcpy(st[j], st[j + 1]);
				strcpy(st[j + 1], t);
			}
		}
	}

}


void highScoreShow()//show the highScore
{
	//calls the sorting function to sort the score in ascending before showing on the screen
	SortingHighScore();
	rank = 0;
	for (int k = 0, y = 320; k < 6; k++, y -= 35)
	{
		char str[100];
		if (numberArray[k]>0)
		{
			rank++;
			sprintf(rankText, "%d", rank);
			itoa(numberArray[k], str, 10);
			iSetColor(0, 0, 255);

			iText(80, 360, "Rank", GLUT_BITMAP_HELVETICA_18);
			iText(80, y, rankText, GLUT_BITMAP_HELVETICA_18);

			iText(180, 360, "Score", GLUT_BITMAP_HELVETICA_18);
			iText(180, y, str, GLUT_BITMAP_HELVETICA_18);

			iText(280, 360, "Name", GLUT_BITMAP_HELVETICA_18);
			iText(280, y, st[k], GLUT_BITMAP_HELVETICA_18);
		}
	}
}


//when the game is over then Shows Game Over page And Shows Enter Your Name 
//And When a button is pressed after clicking on the text box,
//the correspoing character is showed on the screen along with the remaining character
void showName()
{
	srand(time(0));
	iSetColor(rand() % 256, rand() % 256, rand() % 256);
	iText(200, 300, "Enter Your Name & Press ENTER ", GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(255, 0, 0);
	iFilledRectangle(249, 249, 252, 32);

	if (!isClicked)
		iSetColor(0, 0, 0);
	else
		iSetColor(255, 255, 255);

	iFilledRectangle(250, 250, 250, 30);
	iSetColor(255, 0, 0);
	iText(255, 258, ShowOnScreen, GLUT_BITMAP_TIMES_ROMAN_24);
}