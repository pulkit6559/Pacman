#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
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

struct Window{
	int TOP;
	int BOTTOM;
	int LEFT;
	int RIGHT;
	Window(int t, int b, int l, int r);
};

Window::Window(int t, int b, int l, int r){
	TOP = t;
	BOTTOM = b;
	LEFT = l;
	RIGHT = r;
}


class Pacman
{       static const int UP,DOWN,LEFT,RIGHT;
	int x,y;
	const static Face rightface;
	const static Face topface;
	const static Face leftface;
	const static Face bottomface;
	const static Window PACWIN;
	//UP 1 - DOWN 2 - LEFT 3 - RIGHT 4

	void checkinput(char ch){
		switch(ch){
			case UP:  moveUp();
				  break;
			case DOWN: moveDown();
				   break;
			case LEFT: moveLeft();
				   break;
			case RIGHT: moveRight();
				    break;
			case 'x': exit(0);
		}
	}


	void moveUp(){

		if(this->y<=PACWIN.TOP){
			return;
		}
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
			start = start - 4*pow(-1,n);
			end = end + 4*pow(-1,n);
			x = x;
			y = y - 1;
			pieslice(x,y,start,360,10);
			pieslice(x,y,0,end,10);
			ch = getch();
			if(ch!=UP){
				cleardevice();
				checkinput(ch);
			}
			cleardevice();
		}
	}
	void moveLeft(){
		int end = leftface.e_angle;
		int start = leftface.s_angle;
		int n = 0;
		char ch;
		for(int i=0;i<300;i++){
			buildmap();
			if(end<leftface.e_angle)
				n++;
			if(end>180)
				n++;
			start = start + 4*pow(-1,n);
			end = end - 4*pow(-1,n);
			x = x-1;
			y = y;
			pieslice(x,y,start,359,10);
			pieslice(x,y,0,end,10);
			ch = getch();
			if(ch!=LEFT){
				cleardevice();
				checkinput(ch);
			}
			cleardevice();
		}
	}

	void moveRight(){

		int end = rightface.e_angle;
		int start = rightface.s_angle;
		int n = 0;
		char ch;
		for(int i=0;i<300;i++){
			buildmap();
			if(end>rightface.e_angle)
				n++;
			if(end<359)
				n++;
			start = start + 4*pow(-1,n);
			end = end - 4*pow(-1,n);
			x = x+1;
			y = y;
			pieslice(x,y,start,end,10);
			//pieslice(x,y+i,b,360,10);
			ch = getch();
			if(ch!=RIGHT){
				cleardevice();
				checkinput(ch);
			}
			cleardevice();
		}
	}

	void moveDown(){

		int end = bottomface.e_angle;
		int start = bottomface.s_angle;
		int n = 0;
		char ch;
		for(int i=0;i<300;i++){
			buildmap();
			if(start>bottomface.s_angle)
				n++;
			if(start<270)
				n++;
			start = start - 4*pow(-1,n);
			end = end + 4*pow(-1,n);
			x = x;
			y = y+1;
			pieslice(x,y,0,end,10);
			pieslice(x,y,start,360,10);

			ch = getch();
			if(ch!=DOWN){
				cleardevice();
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
const Window Pacman::PACWIN = Window(0,0,390,440);
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