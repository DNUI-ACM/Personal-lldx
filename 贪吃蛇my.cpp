#include<iostream>
#include<time.h>
#include<graphics.h>
#define NUMS 25
using namespace std;
int fx[4]={+0,+0,+1,-1},
	fy[4]={+1,-1,+0,+0}; 
typedef struct Node{
	int x,y,dir;
	time_t t;
	Node(int tx=0,int ty=0,time_t ti=0,int tdir = 0) : x(tx) , y(ty) , t(ti) , dir(tdir){;}
	~Node(){;}
};
class Snake{
public:
	Node head;
	Node body[NUMS*NUMS];
	int size;
};
Node MakeHeadNode(int ** arr){
	int x=rand()%(NUMS-2) + 1;
	int y=rand()%(NUMS-2) + 1;
	arr[y][x]=1;
	time_t ts;time(&ts);
	return Node(x,y,ts,0);
}
void MakeEatNode(int **arr,Snake snake)
{
	int x,y;
	x=rand()%(NUMS-2) + 1;
	y=rand()%(NUMS-2) + 1;
	while(arr[y][x]!=0)
	{
		x=rand()%(NUMS-2) + 1;
		y=rand()%(NUMS-2) + 1;
	}
	arr[y][x] = 3;
}
void PrintfNodeCircle(Node node,int sum)
{
	setcolor(BLACK);
	circle(node.x*20+10,node.y*20+10,10);
	setfillcolor(sum);
	floodfill(node.x*20+10,node.y*20+10,BLACK);
}
bool Move(Snake & snake ,int dir,int **arr)
{
	Node node = snake.head;
	Node & lastnode = snake.body[snake.size-1];
	if(dir == -1)
	{
		dir = node.dir;
	}
	time_t ts;
	time(&ts);
	Node newnode(node.x + fx[dir],node.y + fy[dir],ts,dir);
	if(newnode.y>NUMS-1||newnode.y<1||newnode.x>NUMS-1||newnode.x<1)
	{
		return false;
	}
	int pt = arr[newnode.y][newnode.x];
	arr[newnode.y][newnode.x] = 1;
	arr[node.y][node.x]=2;
	if(pt==0){
		arr[lastnode.y][lastnode.x]=0;
		for(int i=snake.size-1;i>=1;i--)
		{
			snake.body[i]=snake.body[i-1];
		}
	}
	else if(pt == 2)
	{
		return false;
	}
	else if(pt == 3){
		MakeEatNode(arr,snake);
		for(int i=snake.size;i>=1;i--)
		{
			snake.body[i]=snake.body[i-1];
		}
		snake.size++;
	}
	snake.body[0]=snake.head=newnode;
	return true;
}
void PrintfMaps(int zt,int ** arr)
{
	initgraph(640,640);
	setbkcolor(WHITE);
	if(zt==0)
	{
		outtextxy(320,320,"现在，请按下任意键开始贪吃蛇游戏！");
		outtextxy(320,340,"当然，我不介意你输入z或Z退出游戏！");
		outtextxy(320,360,"当然，我也不会告诉你输入p或P能暂停游戏！"); 
		char p = getch();
		if(p=='z'||p=='Z') exit(0);
		return ;
	}
	else if(zt==1)
	{
		for(int i=1;i<NUMS;i++)
		{
			for(int j=1;j<NUMS;j++)
			{
				if(arr[i][j] == 1){PrintfNodeCircle(Node(j,i),LIGHTMAGENTA);}
				else if(arr[i][j]==2){ PrintfNodeCircle(Node(j,i),GREEN);}
				else if(arr[i][j]==0){ PrintfNodeCircle(Node(j,i),WHITE);}
				else if(arr[i][j]==3){ PrintfNodeCircle(Node(j,i),LIGHTRED);}
			}
		}
		return ;
	}
}
int main()
{
	while(1)
	{
		time_t pdpd;
		srand((unsigned) time(&pdpd));
		int ** arr;
		arr = new int * [NUMS];
		for(int i=0;i<NUMS;i++)
		{
			arr[i] = new int [NUMS];
		}
		for(int i=1;i<NUMS;i++)
		{
			for(int j=1;j<=NUMS;j++)
			{
				arr[i][j]=0;
			}
		}
		PrintfMaps(0,arr);
		Snake snake;
		snake.head = MakeHeadNode(arr);
		snake.body[0]=snake.head;
		snake.size=1;
		int tmps =1;
		PrintfMaps(1,arr);
		time_t cur,ts;
		int tmp = 0;
		MakeEatNode(arr,snake);
		while(time(&cur))
		{
			
			if(kbhit())
			{
				char p = getch();
				//printf("%d\n",p);
				if(p==38){tmp = 1;}
				else if(p==37){tmp = 3;}
				else if(p==40){tmp = 0;}
				else if(p==39){tmp = 2;}
				else if(p=='z'||p=='Z'){exit(0);}
				else if(p=='p'||p=='P'){getch();}
				if(!Move(snake,tmp,arr))
				{
					outtextxy(150,150,"你失败了！！");
					getch();
					break;
				}
				PrintfMaps(1,arr);
				continue;
			} 
			if(cur - snake.head.t>=0.2)
			{
				//printf("here\n");
				if(!Move(snake,tmp,arr))
				{
					outtextxy(150,150,"你失败了！！");
					getch();
					break;
				}
				PrintfMaps(1,arr);
			}
		}
	}
	return 0;
 } 
