#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdio>
using namespace std;

const int N=11;
char Map[N][N] = {
				 '0','0','0','0','0','0','0','0','0','0','0',
				 '0','*','*','*','*','*','*','*','*','*','*',
				 '0','*',' ','E',' ',' ',' ',' ',' ',' ','*',
				 '0','*',' ',' ',' ','*','*','*',' ',' ','*',
				 '0','*',' ',' ',' ','*','*','*',' ',' ','*',
				 '0','*',' ',' ','*','*',' ',' ',' ',' ','*',
				 '0','*',' ',' ','*','*',' ',' ',' ',' ','*',
				 '0','*',' ',' ','*','*',' ',' ',' ',' ','*',
				 '0','*',' ',' ','*','*',' ',' ','#',' ','*',
				 '0','*','H',' ',' ',' ',' ',' ',' ',' ','*',
				 '0','*','*','*','*','*','*','*','*','*','*',
				};

struct ZB
{
	int x,y;
};
ZB H,E;

bool flag;
int Zou[4][2] = {-1,0,1,0,0,-1,0,1};
//上下左右 

void init ()
{
	H.x=9,H.y=2;
	E.x=2,E.y=3;
}

void out ()
{
	system ("cls");
	if (flag)
	{
		printf ("Invalid input!");
		Sleep (500);
		system ("cls");
	}
	
	for (int i=1;i<=10;i++)
	{
		for (int j=1;j<=10;j++)
			cout<<Map[i][j];
		cout<<endl;
	}
}

int PD (int x,int y)//判断是否有输入错误情况 
{
	if ( x<1 || x>10) return 1;
	if ( y<1 || y>10) return 1;
	if ( Map[x][y] == '*') return 1;
	return 0;
}

void Start (int x,int y,int d)//进行移动 
{
	if ( Map[x][y] == '#' && Map[x+Zou[d][0]][y+Zou[d][1]] != '*')
	{
		Map[H.x][H.y] = ' ';
		H.x=x,H.y=y;
		Map[H.x][H.y] = 'H';
		Map[x+Zou[d][0]][y+Zou[d][1]] = '#';
		return ;
	}
	
	if ( Map[x][y] == '#') return ;
	
	Map[H.x][H.y] = ' ';
	H.x=x,H.y=y;
	Map[H.x][H.y] = 'H';
}

void work ()//进行移动前的初始化 
{
	char c = getch ();
	int d;
	switch (c)
	{
		case 'w': d=0;
				  break;
		case 's': d=1;
				  break;
		case 'a': d=2;
				  break;
		case 'd': d=3;
				  break;
	}
	int x = Zou[d][0]+H.x;
	int y = Zou[d][1]+H.y;
	flag = 0;
	
	if (PD (x,y)) flag =1;
	else Start (x,y,d);
	if ( x+Zou[d][0] == E.x && y+Zou[d][1] == E.y)
	{
		system ("cls");
		printf ("You Win !");
	}
	else {
			out ();
			work ();
	}
}

int main ()
{
	init ();
	flag = 0;
	out ();
	work ();
}
