#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<dos.h>
#include<graphics.h>
void buildmap();
struct RightFace{
	const static int s_angle = 45;
	const static int e_angle = 315;
}

struct LeftFace{
	const static int e_angle = 135;
	const static int s_angle = 225;
}

struct TopFace{
	const static int e_angle = 45;
	const static int s_angle = 135;
}

struct BottomFace{
	const static int e_angle = 225;
	const static int s_angle = 315;
}

class Pacman
{       static const int UP,DOWN,LEFT,RIGHT;
	int x,y;
	RightFace right;
	TopFace top;
	LeftFace left;
	BottomFace bottom;
	int Face; //UP 1 - DOWN 2 - LEFT 3 - RIGHT
	void moveUp(){
		int end = top.e_angle;
		int start = top.s_angle;
		int n = 0;
		for(int i=0;i<300;i++){
			buildmap();
			if(start>top.s_angle)
				n++;
			if(start<90)
				n++;
			start = start - 2*pow(-1,n);
			end = end + 2*pow(-1,n);
			x = x;
			y = y - i;
			pieslice(x,y,start,end,10);
			//pieslice(x,y+i,b,360,10);
			getch();
			cleardevice();
		}
	}
	void moveLeft(){
		int end = left.e_angle;
		int start = left.s_angle;
		int n = 0;
		for(int i=0;i<300;i++){
			buildmap();
			if(a>270)
				n++;
			if(a<225)
				n++;
			start = start - 2*pow(-1,n);
			end = end + 2*pow(-1,n);
			x = x;
			y = y - i;
			pieslice(x,y,start,end,10);
			//pieslice(x,y+i,b,360,10);
			getch();
			cleardevice();
		}
	}

	void moveRight(){
	}

	void moveDowm(){
	}
	public:
	Pacman(int x, int y){
		this->x = (x)*20 + 20 + 5 + 10;
		this->y = (y)*20 + 20 + 5 + 10;
	}

	void init(int x, int y){
		int a = 225;
		int b = 315;
		int n = 0;
		for(int i=0;i<400;i++){
			buildmap();
			if(a>270)
				n++;
			if(a<225)
				n++;
			a = a + 2*pow(-1,n);
			b = b - 2*pow(-1,n);
			pieslice(x,y+i,0,a,10);
			pieslice(x,y+i,b,360,10);
			getch();
			cleardevice();
		}
	}
	void move(){
		while(1){
			ch = getch();
			switch(ch){
				case UP:  moveUP();
					  break;
				case DOWN: moveDown();
					   break;
				case LEFT: moveLeft();
					   break;
				case RIGHT: moveRight();
					    break;
				default:
			}

		}
	}
};
int Pacman::UP = int('w');
int Pacman::DOWN = int('s');
int Pacman::LEFT = int('a');
int Pacman::RIGHT = int('d');
class point{


};

class ghost{

};

class map{


};

void main(){
	int i,gd = DETECT, gm;
	clrscr();
	printf("What the fuck");
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	//line(100,100,200,200);
	//delay(100);
	buildmap();
	Pacman p = Pacman(0,0);
	p.init(35,35);
	p.move();
	//addscorecard(250,5);
	getch();
	closegraph();
	getch();

}

void buildmap(){
	rectangle(20,20,400,450);
	rectangle(25,25,395,445);
	rectangle(25,25,25+21,25+21);
	setfillstyle(SOLID_FILL,YELLOW);
	//floodfill(26,26, WHITE);

}