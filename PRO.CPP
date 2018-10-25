#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<dos.h>
#include<graphics.h>
void buildmap();

struct Face{
	int s_angle;
	int e_angle;
	Face(int s, int e);
};

Face::Face(int s, int e){
	s_angle = s;
	e_angle = e;
}

class Pacman
{       static const int UP,DOWN,LEFT,RIGHT;
	int x,y;
	const static Face rightface;
	const static Face topface;
	const static Face leftface;
	const static Face bottomface;
	//UP 1 - DOWN 2 - LEFT 3 - RIGHT 4

	void checkInput(char ch){
		switch(ch){
			case UP:  moveUp();
				  break;
			case DOWN: moveDown();
				   break;
			case LEFT: moveLeft();
				   break;
			case RIGHT: moveRight();
				    break;
		}
	}


	void moveUp(){
		int end = topface.e_angle;
		int start = topface.s_angle;
		int n = 0;
		char ch;
		for(int i=0;i<300;i++){
			buildmap();
			if(start>topface.s_angle)
				n++;
			if(start<90)
				n++;
			start = start - 2*pow(-1,n);
			end = end + 2*pow(-1,n);
			x = x;
			y = y - i;
			pieslice(x,y,start,end,10);
			//pieslice(x,y+i,b,360,10);
			ch = getch();
			if(ch!=UP){
				checkinput(ch);
			}
			cleardevice();
		}
	}
	void moveLeft(){
		int end = leftface.e_angle;
		int start = leftface.s_angle;
		int n = 0;
		for(int i=0;i<300;i++){
			buildmap();
			if(end<leftface.e_angle)
				n++;
			if(end>180)
				n++;
			start = start + 2*pow(-1,n);
			end = end - 2*pow(-1,n);
			x = x-i;
			y = y;
			pieslice(x,y,start,end,10);
			//pieslice(x,y+i,b,360,10);
			ch = getch();
			if(ch!=LEFT){
				checkinput(ch);
			}
			cleardevice();
		}
	}

	void moveRight(){

		int end = rightface.e_angle;
		int start = rightface.s_angle;
		int n = 0;
		for(int i=0;i<300;i++){
			buildmap();
			if(end<rightface.e_angle)
				n++;
			if(end>0)
				n++;
			start = start + 2*pow(-1,n);
			end = end - 2*pow(-1,n);
			x = x-i;
			y = y;
			pieslice(x,y,start,end,10);
			//pieslice(x,y+i,b,360,10);
			ch = getch();
			if(ch!=RIGHT){
				checkinput(ch);
			}
			cleardevice();
		}
	}

	void moveDown(){

		int end = bottomface.e_angle;
		int start = bottomface.s_angle;
		int n = 0;
		for(int i=0;i<300;i++){
			buildmap();
			if(start>270)
				n++;
			if(start<225)
				n++;
			start = start + 2*pow(-1,n);
			end = end - 2*pow(-1,n);
			x = x;
			y = y+i;
			pieslice(x,y,0,start,10);
			pieslice(x,y,end,360,10);

			ch = getch();
			if(ch!=DOWN){
				checkinput(ch);
			}
			cleardevice();
		}
	}

	public:
	Pacman(int x, int y){
		this->x = (x)*20 + 20 + 5 + 10;
		this->y = (y)*20 + 20 + 5 + 10;
	}

//	void init(int x, int y){
//		int a = 225;
//		int b = 315;
//		int n = 0;
//		for(int i=0;i<400;i++){
//			buildmap();
//			if(a>270)
//				n++;
//			if(a<225)
//				n++;
//			a = a + 2*pow(-1,n);
//			b = b - 2*pow(-1,n);
//			pieslice(x,y+i,0,a,10);
//			pieslice(x,y+i,b,360,10);
//			getch();
//			cleardevice();
//		}
//	}

	void move(){
		char ch;
		while(1){
			ch = getch();
			checkinput(ch);
		}
	}
};


const Face Pacman::rightface = Face(45,315);
const Face Pacman::leftface = Face(225,135);
const Face Pacman::topface = Face(135,45);
const Face Pacman::bottomface = Face(315,225);

const int Pacman::UP = int('w');
const int Pacman::DOWN = int('s');
const int Pacman::LEFT = int('a');
const int Pacman::RIGHT = int('d');
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
	//p.init(35,35);
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