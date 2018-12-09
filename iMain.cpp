/*
	author: S. M. Shahriar Nirjon
	last modified: August 8, 2008
*/
# include "iGraphics.h"
int x=50,y=400;
int gx=151,gy=50;
int dir=1;
int diry=3;
int fox=200,foy=200;
int flag=1;
int cx[100], cy[100];
//int cx=250,cy=270;
int t;
int totalcol=0;
char str[100];
int collisionflag=0;
int score=0;
int dirflag=0;//0 for left,1 for right,2 for up,3 for down
int fivescore=0;
int menu=1;
int i;
int food[] = { 50, 100, 150, 200 };
int naiflag=0;
int apelx=50;
int apely=250;
int apelflag=0;
int apelnai=0;
int ghostdhora=0;
int gameoverflag=0;
int life=0;
/* 
	function iDraw() is called again and again by the system.
*/
void iDraw()
{
	//place your drawing codes here	
	iClear();

	if(menu==1){
		iShowBMP(0,0,"blue1.bmp");
		iSetColor(255,255,0);
		iText(150,110,"<CLICK TO START THE GAME>");
		
		iFilledRectangle(150,250,200,50);
		iFilledRectangle(150,150,200,50);
		iSetColor(0,0,0);
		iText(210,270,"START",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(210,170,"QUIT",GLUT_BITMAP_TIMES_ROMAN_24);
		



	}
	if(menu==2){
	
	//iShowBMP(0,100,"maza.bmp");
		iSetColor(255,0,0);

		iRectangle(2,83,505,510);

		iSetColor(91, 207, 217);

		iFilledRectangle(53, 141, 80, 80);//123
		iFilledRectangle(206, 141, 80, 80);
		iFilledRectangle(359, 141, 80, 80);

		iFilledRectangle(53, 294, 80, 80);//456
		iFilledRectangle(206, 294, 80, 80);
		iFilledRectangle(359, 294, 80, 80);

		iFilledRectangle(53, 447, 80, 80);//789
		iFilledRectangle(206, 447, 80, 80);
		iFilledRectangle(359, 447, 80, 80);

	iText(50,30,"SCORE: 000",GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(0,255,0);
	//for (i = 0; i < 4; i++){
		
	//}
	//for(i=0;i<4;i++){
		
	//for(cx=50;cx<=350;cx=cx+50){
		cx[0] = 50;	cy[0] = 260;
		cx[1] = 100; cy[1] = 260;
		cx[2] = 150; cy[2] = 260;
		cx[3] = 200; cy[3] = 260;
		for (i = 0; i < 4; i++)
		{
			iFilledCircle(cx[i], cy[i], 10);
			//if (collisionflag == 1){	//FOOD
				//cx[0] = -10;
				//cy[0] = -10;
				//iFilledCircle(cx[0], cy[0], 10);
				//iFilledCircle(-10, -10, 10);
			//}
			if(naiflag==1){
				cx[i]=-10;
				cy[i]=-10;
		}

			
		}

		//////////////////////////////APPLE///////////////////////////////////
	/*		iShowBMP(apelx,apely,"apple.bmp");
			if(apelflag==1)
			{
				apelx=-20;
				apely=-20;


			}
			*/
	//}
	iShowBMP(gx,gy,"gho.bmp");//GHOST
	
	if(dirflag==0)			//PACMAN
	iShowBMP(x,y,"cl.bmp");
	if(dirflag==1)
	iShowBMP(x,y,"cr.bmp");
	if(dirflag==2)
	iShowBMP(x,y,"cu.bmp");
	if(dirflag==3)
	iShowBMP(x,y,"cd.bmp");
	
	//iShowBMP(fox,foy,"food1.bmp");
	if(collisionflag==1)
	{
		
		//printf("Collision: %d\n",++totalcol);
		//printf("SCORE: %d\n",++score);
		iText(150,50,"COLLIDED WITH FOOD!",GLUT_BITMAP_TIMES_ROMAN_24);
		//how to increment score using itext???
		
	}
	if(gameoverflag==1){
		x=50;
		y=400;


	}


	}
	if(menu==3){

		iShowBMP(0,0,"gameover.bmp");
		iSetColor(0,255,255);
		iFilledRectangle(160,270,200,50);
		iSetColor(0,0,0);
		iText(180,290,"RESTART",GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(255,255,255);
		iText(50,430,"FINAL SCORE: ",GLUT_BITMAP_TIMES_ROMAN_24);

	}
	if(menu==4){

		iText(180,290,"-HIGH SCORE-",GLUT_BITMAP_TIMES_ROMAN_24);



	}
	
}//IDRAW SESH

//void specialfoodcollision(){

	


//}

void foodcollision(){
	for (i = 0; i<4; i++){

		
		if ((cx[i] - 10)>=x && ((cx[i] - 10) <=x + 32) && (cy[i] + 10) >= y && ((cy[i] + 10) <= y + 32))
		{	
			naiflag==1;
		 	collisionflag = 1;
			//cx[i] = -10;
			//cy[i] = -10;
		//if(x==50 && x==100 && x==150 && x==200)
			//if(naiflag==1){
			printf("Times collided: %d\n", ++totalcol); //ekbar o hoitese na
			fivescore = fivescore + 4;
			printf("SCORE: %d\n", ++fivescore);///barbar hoitese	
			//}
			

			//printf("Collided with food!\n");
		

		

	}
		
	}
	/*
	if((apelx)>x && ((apely)<x+32) && (apely)>y && ((apely)<y+32)){
		apelflag=1;
		printf("hoise\n");
		
			
	}
	*/
}

///////////////////////////////////GHOST////////////////////////////////////////

void ghostmove(){
	/*if(dir==1){
		gx=gx+3;
		if(gx>=300)
			dir=2;
	
	}
	else{
		gx=gx-3;
		if(gx<=30)
			dir=1;
	}
	*/
	/*if(diry==3){
		gy=gy+5;
		if(gy<=300)
			diry=4;
	}
	else{
		gy=gy-3;
		 if(gy>=30)
			diry=3;
	}
	*/

if(diry==1){
	gy=gy+2.5;
	if(gy>=550)
		diry=2;
}
else{
	gy=gy-2.5;
	if(gy<=100)
		diry=1;
}
if((gx)>=x && (gx)<=(x+32) && (gy)>=y && (gy)<=(y+32)){/////GHOST COLLISION
		ghostdhora=1;
		printf("GAME OVER \n");
		x=-50;
		y=-50;
		//life++;
		//if(life==3)
		gameoverflag++;
		if(gameoverflag==1)
		menu=3;
		


	

	

	
}

}
//void ghost1collision(){
	




	//}

//void food(){
	//flag=1;
	//if(flag==2)
		//iShowBMP(fox,foy,"kala.bmp");



//}


/* 
	function iMouseMove() is called when the user presses and drags the mouse.oka
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/* 
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{

		
			 if( mx>=150 && mx<=350 && my>=250 && my<=300)
				menu=2;
			 if( gameoverflag==1 && mx>=160 && mx<=370 && my>=270 && my<=320)
				menu=1;
			 if( mx>=150 && mx<=350 && my>=150 && my<=200)
				exit(0);
			
			 //if( mx>=150 && mx<=350 && my>=250 && my<=300)
				//menu=1;
			
			 
	}

		//place your codes here	
	
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
	}
}
/*iPassiveMouseMove is called to detect and use 
the mouse point without pressing any button */

void iPassiveMouseMove(int mx,int my)
{
	//place your code here
	
 if(mx== 2){}        /*Something to do with mx*/
 else if(my== 2){}   /*Something to do with my*/
 
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed. 
*/
void iKeyboard(unsigned char key)
{
	if(key == 'q')
	{
		//do something with 'q'
	}
	if(key == 'p')
		iPauseTimer(t);
	if(key == 'r')
		iResumeTimer(t);
	//place your codes for other keys here
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
	flag=1;

	if(key == GLUT_KEY_END)
	{
		exit(0);	
	}
	if(key == GLUT_KEY_RIGHT){
		
		dirflag=1;
		
		if(x>=480)    /////CORNER
			x=x-20;
		else if(x>=20 && x<=133 && y>=105 && y<=231) //1
			x=x-2;
		else if(x>=20 && x<=133 && y>=260 && y<=384) //4
			x=x-2;
		else if(x>=20 && x<=133 && y>=412 && y<=537) //7
			x=x-2;
		else if(x>=170 && x<=286 && y>=105 && y<=231)//2
			x=x-2;
		else if(x>=170 && x<=286 && y>=260 && y<=384)//5
			x=x-2;
		else if (x>=170 && x<=286 && y>=412 && y<=537)//8
			x=x-2;
		else if(x>=323 && x<=436 && y>=105 && y<=231)//3
			x=x-2;
		else if(x>=323 && x<=436 && y>=260 && y<=384)//6
			x=x-2;
		else if(x>=323 && x<=436 && y>=412 && y<=537)//9
			x=x-2;
		else
			x=x+3;
		
		
		
		
		
	}
	if(key ==GLUT_KEY_LEFT ) {
	dirflag=0;
	if(x<=4)           /////CORNER
		x=x+20;
	else if(x>=20 && x<=133 && y>=105 && y<=221) //1
		x=x+2;
		else if(x>=20 && x<=133 && y>=260 && y<=384) //4
			x=x+2;
	else if(x>=20 && x<=133 && y>=412 && y<=537) //7
			x=x+1;
		else if(x>=170 && x<=286 && y>=105 && y<=231)//2
			x=x+2;
		else if(x>=170 && x<=286 && y>=260 && y<=384)//5
			x=x+2;
		else if (x>=170 && x<=286 && y>=412 && y<=537)//8
			x=x+2;
		else if(x>=323 && x<=436 && y>=105 && y<=231)//3
			x=x+2;
		else if(x>=323 && x<=436 && y>=260 && y<=384)//6
			x=x+2;
		else if(x>=323 && x<=436 && y>=412 && y<=537)//9
			x=x+2;
		else
			x=x-3;
		
	
	}
	if(key ==GLUT_KEY_DOWN ){
		dirflag=3;
					//////CORNER
		if(y<=90)
			y=y+20;
			else if(x>=20 && x<=133 && y>=105 && y<=231) //1
		y=y+2;
			else if(x>=20 && x<=133 && y>=260 && y<=384) //4
			y=y+2;
	else if(x>=20 && x<=133 && y>=412 && y<=537) //7
			y=y+2;
		else if(x>=170 && x<=286 && y>=105 && y<=231)//2
			y=y+2;
		else if(x>=170 && x<=286 && y>=260 && y<=384)//5
			y=y+2;
		else if (x>=170 && x<=286 && y>=412 && y<=537)//8
			y=y+2;
		else if(x>=323 && x<=436 && y>=105 && y<=231)//3
			y=y+2;
		else if(x>=323 && x<=436 && y>=260 && y<=384)//6
			y=y+2;
		else if(x>=323 && x<=436 && y>=412 && y<=537)//9
			y=y+2;
		else 
			y=y-3;


	}
	if(key ==GLUT_KEY_UP ){
		dirflag=2;

		if(y>=560)   /////CORNER
			y=y-20;
		else if(x>=20 && x<=133 && y>=105 && y<=231) //1
		y=y-2;
		else if(x>=20 && x<=133 && y>=260 && y<=384) //4
			y=y-2;
		else if(x>=20 && x<=133 && y>=412 && y<=537) //7
			y=y-2;
		else if(x>=170 && x<=286 && y>=105 && y<=231)//2
			y=y-2;
		else if(x>=170 && x<=286 && y>=260 && y<=384)//5
			y=y-2;
		else if (x>=170 && x<=286 && y>=412 && y<=537)//8
			y=y-2;
		else if(x>=323 && x<=436 && y>=105 && y<=231)//3
			y=y-2;
		else if(x>=323 && x<=436 && y>=260 && y<=384)//6
			y=y-2;
		else if(x>=323 && x<=436 && y>=412 && y<=537)//9
			y=y-2;
		else
			y=y+3;
	}
	//place your codes for other keys here
}
//
int main()
{

int t =iSetTimer(20,ghostmove);
int t1=iSetTimer(1000,foodcollision);
//int t2=iSetTimer(100,specialfoodcollision);
//int t3=iSetTimer(100,ghost1collision);



	//place your own initialization codes here. 
	iInitialize(512,600, "PACMAN");
	return 0;
}	