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

Window GLOBWIN = Window(25,445,25,395);

const int stepV =-1* int((GLOBWIN.TOP-GLOBWIN.BOTTOM)/20)-1;
const int stepH =-1* int((GLOBWIN.LEFT-GLOBWIN.RIGHT)/20)-1;

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
		//Points pts;
		if(this->y==PACWIN.TOP){
			return;
		}
		int end = topface.e_angle;
		int start = topface.s_angle;
		int n = 0,a,b;
		char ch;
		while(1){

			pts.draw();
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
			a = (x - 25)/stepH - 1;
			b = (y- 25)/stepV - 1;
			if(Points::point[b][a]==1){
				//printf("Touch");
				Points::point[b][a] = 0;
				//pts.draw();
			}
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
		int n = 0,a,b;
		//Points pts;
		char ch;
		for(int i=0;i<300;i++){
			pts.draw();
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
			a = (x - 25)/stepH - 1;
			b = (y- 25)/stepV - 1;
			if(Points::point[b][a]==1){
				//printf("Touch");
				Points::point[b][a] = 0;
				//pts.draw();
			}
			ch = getch();
			if(ch!=LEFT){
				cleardevice();
				checkinput(ch);
			}
			cleardevice();
		}
	}

	void moveRight(){
		//Points pts;
		int end = rightface.e_angle;
		int start = rightface.s_angle;
		int n = 0,a,b;
		char ch;
		for(int i=0;i<300;i++){
			pts.draw();
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
			a = (x - 25)/stepH - 1;
			b = (y- 25)/stepV - 1;
			if(Points::point[b][a]==1){
				//printf("Touch");
				Points::point[b][a] = 0;
				//pts.draw();
			}
			ch = getch();
			if(ch!=RIGHT){
				cleardevice();
				checkinput(ch);
			}
			cleardevice();
		}
	}

	void moveDown(){
		//xPoints pts;
		int end = bottomface.e_angle;
		int start = bottomface.s_angle;
		int n = 0,a,b;
		char ch;
		for(int i=0;i<300;i++){
			buildmap();
			pts.draw();
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

			a = (x - 25)/stepH - 1;
			b = (y- 25)/stepV - 1;
			if(Points::point[b][a]==1){
				//printf("Touch");
				Points::point[b][a] = 0;
				//pts.draw();
			}

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


class Points{
	//static int point[20][20];
	const static int N;
	public:
	static int point[20][20];

	static void init_points();

	void draw(){
		//printf("TEST");

		//printf("%d %d",stepV,stepH);
		int x = 0, y = 0;
		for(int i = 0; i<20;i++){
			for(int j= 0; j<20;j++){
				//printf("TEST");
				y = 25 + (i+1)*stepV;
				x = 25 + (j+1)*stepH;
				if(Points::point[i][j]==1){
					//printf("TEST");
					circle(x,y,3);
					floodfill(x,y,WHITE);
					setfillstyle(SOLID_FILL,YELLOW);
				}
			}
		}
	}



};
Points pts;

const int Points::N = 1;
int Points::point[20][20];
void Points::init_points(){
	int i,j,r;
	randomize();
	for(i = 0; i<20; i++){
		for(j=0; j<Points::N; j++){

			r = random(20);
			//printf("%d",r);
			Points::point[i][r] = 1;

		}
	}
//		for(i = 0; i<20; i++){
//		for(j=0;j<20;j++){
//			printf("%d ", Points::point[i][j]);
//		}
//		printf("\n") ;
//	}
}


class Shooter{
	static int x,y;

	public:
	Shooter(int a, int b){
		this->x = a+5;
		this->y = b+10;
	}
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
	Points pts;
	Points::init_points();
	pts.draw();
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
