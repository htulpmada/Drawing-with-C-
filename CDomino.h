#include <cmath>
using namespace System::Drawing;

public ref class CDomino {
public:
	CDomino(int type, int x, int y, int w, int h, Color c) {
		Type=type;
		X=x;
		Y=y;
		Width=w;
		Height=h;
		color=c;
		rot=0;
		tempx=0;
		tempy=0;
	}
	CDomino(CDomino^ src) {	// copy constructor
		Type=src->Type;
		X=src->X;
		Y=src->Y;
		Width=src->Width;
		Height=src->Height;
		color=src->color;
		rot=0;
		tempx=src->tempx;
		tempy=src->tempy;

	}
	void rotate(){
		int theta;
		int temp;
		
		rot++;
		if (rot%4==0){theta=0;}
		else if (rot%4==1){theta=90;temp=Width;Width=Height;Height=temp;}
		else if (rot%4==2){theta=180;}
		else if (rot%4==3){theta=270;temp=Width;Width=Height;Height=temp;}
	}
	int getX() { return X; }
	void setX(int x) { X=x; }
	int getY() { return Y; }
	void setY(int y) { Y=y; }
	int getWidth(){return Width;}
	int getHeight(){return Height;}
	int getTX() { return tempx; }
	int getTY() { return tempy; }
	void setTX(int x) { tempx=x; }
	void setTY(int y) { tempy=y; }
	
	//void checkEdge(){};

	void draw(Graphics^ g) {
		int x0=X+Width/2,x1=X,x2;
		int y0=Y+Height/2,y1=Y,y2;
		int theta=0;
		int temp;
		//X=x0+(x1-x0)*cos(theta)-(y1-y0)*sin(theta);
		//Y=y0+(x1-x0)*sin(theta)+(y1-y0)*cos(theta);

		g->FillRectangle(gcnew SolidBrush(Color::Blue),0,120,900,2);
		g->FillRectangle(gcnew SolidBrush(Color::Blue),0,415,900,2);

		switch (Type) {
			case 0://:0/0''
				//if(rot%4==0){
				g->FillRectangle(gcnew SolidBrush(color), X, Y, Width, Height);
				g->FillRectangle(gcnew SolidBrush(Color::OrangeRed),X,Y+Height/2,Width,2);
		
				/*}
				else if(rot%4==1){
					Width*=2;
					Height/=2;
					X=X-(Width/4);
					Y=Y+(Height/2);
					//temp=Width;Width=Height;Height=temp;
				g->FillRectangle(gcnew SolidBrush(color), X, Y, Width, Height);
				g->FillRectangle(gcnew SolidBrush(Color::OrangeRed),(X+Width),Y,2,Height/2);}
				else if(rot%4==2){
					X=X+(Width/4);
					Y=Y-(Height/2);
					
				g->FillRectangle(gcnew SolidBrush(color), X, Y, Width, Height);
				g->FillRectangle(gcnew SolidBrush(Color::OrangeRed),X,Y+Height/2,Width,2);}
				else if(rot%4==3){
					X=X-(Width/4);
					Y=Y+(Height/2);
					//temp=Width;Width=Height;Height=temp;
				g->FillRectangle(gcnew SolidBrush(color), X, Y, Width, Height);
				g->FillRectangle(gcnew SolidBrush(Color::OrangeRed),(X+Width),Y,2,Height/2);
				X=X+(Width/4);
				Y=Y-(Height/2);
				}
				*/	
				break;
			case 1://:0/1''
				g->FillRectangle(gcnew SolidBrush(color), X, Y, Width, Height);
				g->FillRectangle(gcnew SolidBrush(Color::OrangeRed),X,Y+Height/2,Width,2);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(Width/3), Y+Height-(Height/4), Width/4, Height/(8));
				break;
			case 2://:1/1''
				g->FillRectangle(gcnew SolidBrush(color), X, Y, Width, Height);
				g->FillRectangle(gcnew SolidBrush(Color::OrangeRed),X,Y+Height/2,Width,2);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(Width/3)-2, Y+Height-(Height/4), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(Width/3)-2, Y+(Height/4), Width/4, Height/8);
				break;
			case 3://:0/2''
				g->FillRectangle(gcnew SolidBrush(color), X, Y, Width, Height);
				g->FillRectangle(gcnew SolidBrush(Color::OrangeRed),X,Y+Height/2,Width,2);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(Width/4), Y+((Height/8)*6), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/3)*2), Y+((Height/8)*6), Width/4, Height/8);
				break;
			case 4://:1/2''
				g->FillRectangle(gcnew SolidBrush(color), X, Y, Width, Height);
				g->FillRectangle(gcnew SolidBrush(Color::OrangeRed),X,Y+Height/2,Width,2);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(Width/4), Y+((Height/8)*6), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(Width/3)-2, Y+(Height/4), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/3)*2), Y+((Height/8)*6), Width/4, Height/8);
				break;
			case 5://:2/2''
				g->FillRectangle(gcnew SolidBrush(color), X, Y, Width, Height);
				g->FillRectangle(gcnew SolidBrush(Color::OrangeRed),X,Y+Height/2,Width,2);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(Width/4), Y+((Height/8)*6), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(Width/3)*2, Y+(Height/4), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(Width/3)-2, Y+(Height/4), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/3)*2), Y+((Height/8)*6), Width/4, Height/8);
				break;
			case 6://:0/3''
				g->FillRectangle(gcnew SolidBrush(color), X, Y, Width, Height);
				g->FillRectangle(gcnew SolidBrush(Color::OrangeRed),X,Y+Height/2,Width,2);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/6)*4), Y+((Height/8)*5), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/6)*2), Y+((Height/8)*6), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+1, Y+((Height/8)*7), Width/4, Height/8);
				break;
			case 7://:1/3''
				g->FillRectangle(gcnew SolidBrush(color), X, Y, Width, Height);
				g->FillRectangle(gcnew SolidBrush(Color::OrangeRed),X,Y+Height/2,Width,2);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(Width/3)-2, Y+(Height/4), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/6)*4), Y+((Height/8)*5), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/6)*2), Y+((Height/8)*6), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+1, Y+((Height/8)*7), Width/4, Height/8);
				break;
			case 8://:2/3''
				g->FillRectangle(gcnew SolidBrush(color), X, Y, Width, Height);
				g->FillRectangle(gcnew SolidBrush(Color::OrangeRed),X,Y+Height/2,Width,2);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(Width/3)*2, Y+(Height/4), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(Width/3)-2, Y+(Height/4), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/6)*4), Y+((Height/8)*5), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/6)*2), Y+((Height/8)*6), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+1, Y+((Height/8)*7), Width/4, Height/8);
				break;
			case 9://:3/3''
				g->FillRectangle(gcnew SolidBrush(color), X, Y, Width, Height);
				g->FillRectangle(gcnew SolidBrush(Color::OrangeRed),X,Y+Height/2,Width,2);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/6)*4), Y+((Height/8)*1), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/6)*2), Y+((Height/8)*2), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+1, Y+((Height/8)*3), Width/4, Height/8);
				
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/6)*4), Y+((Height/8)*5), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/6)*2), Y+((Height/8)*6), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+1, Y+((Height/8)*7), Width/4, Height/8);
				break;
			case 10://:0/4''
				g->FillRectangle(gcnew SolidBrush(color), X, Y, Width, Height);
				g->FillRectangle(gcnew SolidBrush(Color::OrangeRed),X,Y+Height/2,Width,2);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(2), Y+((Height/8)*5), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/4)*2), Y+((Height/8)*5), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(2), Y+((Height/8)*7), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/4)*2), Y+((Height/8)*7), Width/4, Height/8);
				break;
			case 11://:1/4''
				g->FillRectangle(gcnew SolidBrush(color), X, Y, Width, Height);
				g->FillRectangle(gcnew SolidBrush(Color::OrangeRed),X,Y+Height/2,Width,2);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(Width/3)-2, Y+(Height/4), Width/4, Height/8);
				
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(2), Y+((Height/8)*5), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/4)*2), Y+((Height/8)*5), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(2), Y+((Height/8)*7), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/4)*2), Y+((Height/8)*7), Width/4, Height/8);
				break;
			case 12://:2/4''
				g->FillRectangle(gcnew SolidBrush(color), X, Y, Width, Height);
				g->FillRectangle(gcnew SolidBrush(Color::OrangeRed),X,Y+Height/2,Width,2);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(Width/3)*2, Y+(Height/4), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(Width/3)-2, Y+(Height/4), Width/4, Height/8);
				
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(2), Y+((Height/8)*5), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/4)*2), Y+((Height/8)*5), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(2), Y+((Height/8)*7), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/4)*2), Y+((Height/8)*7), Width/4, Height/8);
				break;
			case 13://:3/4''
				g->FillRectangle(gcnew SolidBrush(color), X, Y, Width, Height);
				g->FillRectangle(gcnew SolidBrush(Color::OrangeRed),X,Y+Height/2,Width,2);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/6)*4), Y+((Height/8)*1), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/6)*2), Y+((Height/8)*2), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+1, Y+((Height/8)*3), Width/4, Height/8);
				
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(2), Y+((Height/8)*5), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/4)*2), Y+((Height/8)*5), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(2), Y+((Height/8)*7), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/4)*2), Y+((Height/8)*7), Width/4, Height/8);
				break;
			case 14://:4/4''
				g->FillRectangle(gcnew SolidBrush(color), X, Y, Width, Height);
				g->FillRectangle(gcnew SolidBrush(Color::OrangeRed),X,Y+Height/2,Width,2);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(2), Y+2, Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/4)*2), Y+2, Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(2), Y+((Height/8)*2), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/4)*2), Y+((Height/8)*2), Width/4, Height/8);
				
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(2), Y+((Height/8)*5), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/4)*2), Y+((Height/8)*5), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(2), Y+((Height/8)*7), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/4)*2), Y+((Height/8)*7), Width/4, Height/8);
				break;
			case 15://:0/5''
				g->FillRectangle(gcnew SolidBrush(color), X, Y, Width, Height);
				g->FillRectangle(gcnew SolidBrush(Color::OrangeRed),X,Y+Height/2,Width,2);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(3), Y+((Height/8)*5), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/4)*3), Y+((Height/8)*5), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(3), Y+((Height/8)*7), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/4)*3), Y+((Height/8)*7), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(Width/3)+4, Y+Height-(Height/4), Width/4, Height/8);
				break;
			case 16://:1/5''
				g->FillRectangle(gcnew SolidBrush(color), X, Y, Width, Height);
				g->FillRectangle(gcnew SolidBrush(Color::OrangeRed),X,Y+Height/2,Width,2);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(Width/3)+4, Y+(Height/8)*2, Width/4, Height/8);
				
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(3), Y+((Height/8)*5), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/4)*3), Y+((Height/8)*5), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(3), Y+((Height/8)*7), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/4)*3), Y+((Height/8)*7), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(Width/3)+4, Y+Height-(Height/4), Width/4, Height/8);
				break;
			case 17://:2/5''
				g->FillRectangle(gcnew SolidBrush(color), X, Y, Width, Height);
				g->FillRectangle(gcnew SolidBrush(Color::OrangeRed),X,Y+Height/2,Width,2);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(Width/3)*2, Y+(Height/4), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(Width/3)-2, Y+(Height/4), Width/4, Height/8);
				
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(3), Y+((Height/8)*5), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/4)*3), Y+((Height/8)*5), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(3), Y+((Height/8)*7), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/4)*3), Y+((Height/8)*7), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(Width/3)+4, Y+Height-(Height/4), Width/4, Height/8);
				break;
			case 18://:3/5''
				g->FillRectangle(gcnew SolidBrush(color), X, Y, Width, Height);
				g->FillRectangle(gcnew SolidBrush(Color::OrangeRed),X,Y+Height/2,Width,2);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/6)*4), Y+((Height/8)*1), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/6)*2), Y+((Height/8)*2), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+1, Y+((Height/8)*3), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(3), Y+((Height/8)*5), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/4)*3), Y+((Height/8)*5), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(3), Y+((Height/8)*7), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/4)*3), Y+((Height/8)*7), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(Width/3)+4, Y+Height-(Height/4), Width/4, Height/8);
				break;
			case 19://:4/5''
				g->FillRectangle(gcnew SolidBrush(color), X, Y, Width, Height);
				g->FillRectangle(gcnew SolidBrush(Color::OrangeRed),X,Y+Height/2,Width,2);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(3), Y+(3), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/4)*3), Y+(3), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(3), Y+((Height/8)*3), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/4)*3), Y+((Height/8)*3), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(3), Y+((Height/8)*5), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/4)*3), Y+((Height/8)*5), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(3), Y+((Height/8)*7), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/4)*3), Y+((Height/8)*7), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(Width/3)+4, Y+Height-(Height/4), Width/4, Height/8);
				break;
			case 20://:5/5''
				g->FillRectangle(gcnew SolidBrush(color), X, Y, Width, Height);
				g->FillRectangle(gcnew SolidBrush(Color::OrangeRed),X,Y+Height/2,Width,2);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(3), Y+(3), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/4)*3), Y+(3), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(3), Y+((Height/8)*3), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/4)*3), Y+((Height/8)*3), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(Width/3)+4, Y+(Height/8)*2, Width/4, Height/8);
				

				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(3), Y+((Height/8)*5), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/4)*3), Y+((Height/8)*5), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(3), Y+((Height/8)*7), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/4)*3), Y+((Height/8)*7), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(Width/3)+4, Y+Height-(Height/4), Width/4, Height/8);
				break;
			case 21://:0/6''
				g->FillRectangle(gcnew SolidBrush(color), X, Y, Width, Height);
				g->FillRectangle(gcnew SolidBrush(Color::OrangeRed),X,Y+Height/2,Width,2);
				
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(3), Y+((Height/8)*4)+4, Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/4)*3), Y+((Height/8)*4)+4, Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(3), Y+((Height/8)*6)-2, Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/4)*3), Y+((Height/8)*6)-2, Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(3), Y+((Height/8)*7)+1, Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/4)*3), Y+((Height/8)*7)+1, Width/4, Height/8);
				
				break;
			case 22://:1/6''
				g->FillRectangle(gcnew SolidBrush(color), X, Y, Width, Height);
				g->FillRectangle(gcnew SolidBrush(Color::OrangeRed),X,Y+Height/2,Width,2);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(Width/3)+4, Y+(Height/8)*2, Width/4, Height/8);
				
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(3), Y+((Height/8)*4)+4, Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/4)*3), Y+((Height/8)*4)+4, Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(3), Y+((Height/8)*6)-2, Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/4)*3), Y+((Height/8)*6)-2, Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(3), Y+((Height/8)*7)+1, Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/4)*3), Y+((Height/8)*7)+1, Width/4, Height/8);
				break;
			case 23://:2/6''
				g->FillRectangle(gcnew SolidBrush(color), X, Y, Width, Height);
				g->FillRectangle(gcnew SolidBrush(Color::OrangeRed),X,Y+Height/2,Width,2);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(Width/3)*2, Y+(Height/4), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(Width/3)-2, Y+(Height/4), Width/4, Height/8);

				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(3), Y+((Height/8)*4)+4, Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/4)*3), Y+((Height/8)*4)+4, Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(3), Y+((Height/8)*6)-2, Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/4)*3), Y+((Height/8)*6)-2, Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(3), Y+((Height/8)*7)+1, Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/4)*3), Y+((Height/8)*7)+1, Width/4, Height/8);
				break;
			case 24://:3/6''
				g->FillRectangle(gcnew SolidBrush(color), X, Y, Width, Height);
				g->FillRectangle(gcnew SolidBrush(Color::OrangeRed),X,Y+Height/2,Width,2);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/6)*4), Y+((Height/8)*1), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/6)*2), Y+((Height/8)*2), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+1, Y+((Height/8)*3), Width/4, Height/8);

				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(3), Y+((Height/8)*4)+4, Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/4)*3), Y+((Height/8)*4)+4, Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(3), Y+((Height/8)*6)-2, Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/4)*3), Y+((Height/8)*6)-2, Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(3), Y+((Height/8)*7)+1, Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/4)*3), Y+((Height/8)*7)+1, Width/4, Height/8);
				break;
			case 25://:4/6''
				g->FillRectangle(gcnew SolidBrush(color), X, Y, Width, Height);
				g->FillRectangle(gcnew SolidBrush(Color::OrangeRed),X,Y+Height/2,Width,2);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(3), Y+(3), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/4)*3), Y+(3), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(3), Y+((Height/8)*3), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/4)*3), Y+((Height/8)*3), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(3), Y+((Height/8)*4)+4, Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/4)*3), Y+((Height/8)*4)+4, Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(3), Y+((Height/8)*6)-2, Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/4)*3), Y+((Height/8)*6)-2, Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(3), Y+((Height/8)*7)+1, Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/4)*3), Y+((Height/8)*7)+1, Width/4, Height/8);
				break;
			case 26://:5/6''
				g->FillRectangle(gcnew SolidBrush(color), X, Y, Width, Height);
				g->FillRectangle(gcnew SolidBrush(Color::OrangeRed),X,Y+Height/2,Width,2);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(3), Y+(3), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/4)*3), Y+(3), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(3), Y+((Height/8)*3), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/4)*3), Y+((Height/8)*3), Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(Width/3)+4, Y+(Height/8)*2, Width/4, Height/8);

				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(3), Y+((Height/8)*4)+4, Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/4)*3), Y+((Height/8)*4)+4, Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(3), Y+((Height/8)*6)-2, Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/4)*3), Y+((Height/8)*6)-2, Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(3), Y+((Height/8)*7)+1, Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/4)*3), Y+((Height/8)*7)+1, Width/4, Height/8);
				break;
			case 27://:6/6''
				g->FillRectangle(gcnew SolidBrush(color), X, Y, Width, Height);
				g->FillRectangle(gcnew SolidBrush(Color::OrangeRed),X,Y+Height/2,Width,2);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(3), Y+3, Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/4)*3), Y+3, Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(3), Y+((Height/8)*2)-3, Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/4)*3), Y+((Height/8)*2)-3, Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(3), Y+((Height/8)*3)+1, Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/4)*3), Y+((Height/8)*3)+1, Width/4, Height/8);
				
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(3), Y+((Height/8)*4)+4, Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/4)*3), Y+((Height/8)*4)+4, Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(3), Y+((Height/8)*6)-2, Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/4)*3), Y+((Height/8)*6)-2, Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+(3), Y+((Height/8)*7)+1, Width/4, Height/8);
				g->FillEllipse(gcnew SolidBrush(Color::MediumVioletRed), X+((Width/4)*3), Y+((Height/8)*7)+1, Width/4, Height/8);
				break;
			case 28:
				g->FillRectangle(gcnew SolidBrush(color), X, Y, Width, Height);
				g->FillRectangle(gcnew SolidBrush(Color::OrangeRed),X,Y+Height/2,Width,2);
				break;
		}
	}
	int GetType(){return Type;}

	bool containPoint(int x, int y) {
		if(Type>=0){return (x>=X && y>=Y && x<X+Width && y<Y+Height);}
		else{return false;}
	}

private:
	int rot;
	int Type;	// tells suit number
	int X;		//tells left bonudary
	int Y;		//top edge
	int Width;
	int Height;
	int tempx;
	int tempy;
	Color color;
};
