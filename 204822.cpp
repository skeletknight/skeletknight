#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

int score = 0;


struct player{

	string name;
	int score;
};





void upmove(int a[4][4]);

void downmove(int a[4][4]);

void leftmove(int a[4][4]);

void rightmove(int a[4][4]);

void game();

//this part need to get completed

void leaderboard(string name){
	player player;
	player.score = score;

	
}






void randomnumber(int a[4][4])
{
	int li,ri;
	srand(time(0));
	while(1)
	{
		li=rand()%4;
		ri=rand()%4;
		if(a[li][ri]==0)
		{
			a[li][ri]=pow(2,li%2 + 1);
			break;
		}
	}

}

void print(int a[4][4])
{	

	cout<<"\n\t\tPress ESC to quit the game";
	
	cout<<"\n\n\n\n\n your score is : "<<score<<"\n\n\n\n";

	int i,j;

	for(i=0;i<4;i++)
	{
		cout<<"\t\t\t\t-----------------\n\t\t\t\t";
		for(j=0;j<4;j++)
		{
			if(a[i][j]==0) cout<<"|   ";
			else
				cout<<"| "<<a[i][j]<<" ";
		}
		cout<<"|"<<endl;
	}
	cout<<"\t\t\t\t-----------------\n";
	
}

int check(int tmp[4][4],int a[4][4])
{
	int fl=1,i,j;
	for(i=0;i<4;i++)
    	for(j=0;j<4;j++)
    		if(tmp[i][j]!=a[i][j])
    		{
    			fl=0;
    			break;
			}
	return fl;
}

bool checkover(int a[4][4])
{
	int fl=0,gl=0,i,j;
	for(i=0;i<4;i++)
    	for(j=0;j<4;j++)
    		if(a[i][j]==0)
    		{
    			fl=1;
				break;
			}

	for(i=0;i<3;i++)
    	for(j=0;j<3;j++)
    		if(a[i+1][j]==a[i][j] || a[i][j+1]==a[i][j])
    		{
    			gl=1;
    			break;
			}

	if(fl || gl) return true;
	else return false;
}

int main()
{	
	int color;
	cout<<"CHOOSE THE COLOR YOU LIKE TO 1.BLUE 2.AQUA 3.GREEN 4.RED 5.YELLOW 6.GRAY 7.LIGHT PURPLE 8.LIGHT RED 9.LIGHT AQUA ";
	cin>>color;
	switch (color)
	{
	case 1:
		system("Color 01");
		break;
	case 2:
		system("Color 03");
		break;
	case 3:
		system("Color 02");
		break;
	case 4:
		system("Color 04");
		break;
	case 5:
		system("Color 06");
		break;
	case 6:
		system("Color 08");
		break;
	case 7:
		system("Color 0D");
		break;
	case 8:
		system("Color 0C");
		break;
	case 9:
		system("Color 0B");
		break;
	}
	system("CLS");

	cout<<"CHOOSE 1 TO PLAY THE GAME"<<"\n\n CHOOSE 2 FOR SEEING THE LEADER BOARD "<<"\n\n CHOOSE 3 FOR EXIT";
	
	char user_input;
	user_input = _getch();
	
	switch (user_input)
	{
	case '1':
		game();
		break;
	case '2':
		//leaderboardfunction
		break;
	case '3':
		exit(1);
		break;
	default:

		break;
	}
	

	
}


void upmove(int a[4][4])
{
  for (int j = 0; j < 4; j++) {
        for (int i = 0; i < 3; i++) {
            if (a[i][j] == a[i + 1][j]) {
                a[i][j] *= 2;
				score += a[i][j];
                a[i + 1][j] = 0;
            }
        }
        for (int i = 0; i < 3; i++) {
            if (a[i][j] == 0) {
                for (int k = i + 1; k < 4; k++) {
                    if (a[k][j] != 0) {
                        a[i][j] = a[k][j];
                        a[k][j] = 0;
                        break;
                    }
                }
            }
        }
    }
	
}


void downmove(int a[4][4])
{
	int i,j,li,ri;
	for(j=0;j<4;j++)
	{
		li=3,ri=j;
		for(i=2;i>=0;i--)
		{
			if(a[i][j]!=0)
			{
				if(a[i+1][j]==0 || a[i+1][j]==a[i][j])
				{
					if(a[li][ri]==a[i][j])
					{
						a[li][ri]*=2;
						score += a[li][ri];
						a[i][j]=0;
					}
					else
					{
						if(a[li][ri]==0)
						{
							a[li][ri]=a[i][j];
							a[i][j]=0;
						}
						else
						{
							a[--li][ri]=a[i][j];
							a[i][j]=0;
						}
					}
				}
				else li--;
			}
		}
	}
}

void leftmove(int a[4][4])
{
	int i,j,li,ri;

	for(i=0;i<4;i++)
	{
		li=i,ri=0;
		for(j=1;j<4;j++)
		{
			if(a[i][j]!=0)
			{
				if(a[i][j-1]==0 || a[i][j-1]==a[i][j])
				{
					if(a[li][ri]==a[i][j])
					{
						a[li][ri]*=2;
						score += a[li][ri];
						a[i][j]=0;
					}
					else
					{
						if(a[li][ri]==0)
						{
							a[li][ri]=a[i][j];
							a[i][j]=0;
						}
						else
						{
							a[li][++ri]=a[i][j];
							a[i][j]=0;
						}
					}
				}
				else ri++;
			}
		}
	}
}

void rightmove(int a[4][4])
{
	int i,j,li,ri;
	for(i=0;i<4;i++)
	{
		li=i,ri=3;
		for(j=2;j>=0;j--)
		{
			if(a[i][j]!=0)
			{
				if(a[i][j+1]==0 || a[i][j+1]==a[i][j])
				{
					if(a[li][ri]==a[i][j])
					{
						a[li][ri]*=2;
						score += a[li][ri];
						a[i][j]=0;
					}
					else
					{
						if(a[li][ri]==0)
						{
							a[li][ri]=a[i][j];
							a[i][j]=0;
						}
						else
						{
							a[li][--ri]=a[i][j];
							a[i][j]=0;
						}
					}
				}
				else ri--;
			}
		}
	}
}


void game(){
	system("CLS");
	player player;
	int random1,random2,random3,random4,i,j;
	int a[4][4]={0},tmp[4][4]={0};

	cout<<"PLEASE ENTER YOUR NAME: ";
	cin>>player.name;
	leaderboard(player.name);

	cout<<"\n\n\n\n\t\t\t2048 GAME\n\n\n\t\tPress any key to continue";
	
	getch();
	system("cls");
	
	srand(time(0));
	random1=rand()%4;
	random2=rand()%4;
	
	while(1)
	{
		
		random3=rand()%4;
		random4=rand()%4;
		
		if(random3!=random1 && random4!=random2) break;
	}
	
	a[random1][random2]=2;
	a[random3][random4]=4;
	print(a);

	int ch;
	while (1)
    {
    	for(i=0;i<4;i++)
		{
    		for(j=0;j<4;j++){
    			tmp[i][j]=a[i][j];
			}
		}	
		
    ch = getch();
    system("cls");
    
	switch (ch)
		{
		case 'w':
			upmove(a);
			break;
		case 's':
			downmove(a);
			break;
		case 'a':
			leftmove(a);
			break;
		case 'd':
			rightmove(a);
			break;
		case (27):
			//showing the score and writing somthing interseting
			cout<<"--------------------------------------------------------";
			exit(1);
			break;

		}

		if(!check(tmp,a))
			randomnumber(a);
		print(a);

		if(!checkover(a))
		{
			cout<<"\n\n\t\t\tGAME OVER!!\n\n\n";
			getch();
			break;
		}
	}
	
}
