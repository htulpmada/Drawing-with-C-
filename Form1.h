/*CS351
Project #2
Adam Pluth
The game dominoes


*/


#pragma once

#include "CDomino.h"
#include <stdlib.h>
#include <stdio.h>
namespace Dominoes {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			// Initial state, added by Zhang
			Duplicates = gcnew ArrayList();
			Originals = gcnew ArrayList();
			array<int>^ picks = gcnew array<int>(14);
			array<Color>^ colors = {Color::Red, Color::Gray, Color::Blue, Color::Magenta, Color::Cyan, Color::Yellow,Color::DarkOliveGreen};
			int count=colors->Length;
			int dx=5;
			int dy=5;
			int tempx=0,tempy=0;
			int gap=75;
			int length=(ClientSize.Width-2*dx-(count-1)*gap)/count;
			int depth=(ClientSize.Width-2*dy-(count-1)*gap)/count;
			int pick1=rand()%28;
			int pick2=rand()%28;
			for (int i=0; i<count; i++) { 
				picks[0]=rand()%28;
				picks[1]=rand()%28;

				for(int j=0;j < 13;j++){
					
					while(pick1==picks[i]){pick1=rand()%28;}
					picks[i]=pick1;
				}
				for(int j=0;j < 14;j++){
					while(pick2==picks[j]){pick2=rand()%28;}
					picks[i+6]=pick2;
				}
				Originals->Add(gcnew CDomino(/*picks[i]need to change back*/picks[i], dx+i*(length+gap), dy, length, length*2, colors[1]));
				Originals->Add(gcnew CDomino(/*picks[i+6]need to change back*/picks[i+6], dx+i*(length+gap), ClientSize.Height-(length+dx)*2, length, length*2, colors[1]));
			}
			ShapeToBeMoved=nullptr; // no shape selected

			// create the back buffer
			backBuffer = gcnew Bitmap(ClientSize.Width, ClientSize.Height);
			gBackBuffer = Graphics::FromImage(backBuffer);
			this->SetStyle(ControlStyles::Opaque, true);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

		// state representation, added by Zhang
		ArrayList ^Originals;
		ArrayList ^Duplicates;

		CDomino^ ShapeToBeMoved;
		int m_nOffsetX;	// difference between cursor and top-left corner
		int m_nOffsetY;

		// double buffering
		Bitmap^ backBuffer;
		Graphics^ gBackBuffer;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->SuspendLayout();
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(841, 538);
			this->Name = L"Form1";
			this->Text = L"CDomino";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::Form1_Paint);
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseClick);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void Form1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
				// State Presentation, using double buffers
				// First, clear the back buffer
				gBackBuffer->Clear(Color::White);
				// draw the originals to back buffer
				for (int i=0; i<Originals->Count; i++) {
					CDomino^ p=(CDomino^)Originals[i];
					p->draw(gBackBuffer);
				}
				// draw the duplicates to back buffer
				for (int i=0; i<Duplicates->Count; i++) {
					CDomino^ p=(CDomino^)Duplicates[i];
					p->draw(gBackBuffer);
				}
				// copy from back buffer to front
				e->Graphics->DrawImageUnscaled(backBuffer, 0, 0);
			 }
	private: void Exit(){

				 exit(0);
			 }

	private: System::Void Form1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				if (e->Button == System::Windows::Forms::MouseButtons::Left) {
					// First, check the duplicates, from top down (i.e. back to front)
					for (int i=Duplicates->Count-1; i>=0; i--) {
						CDomino^ p=(CDomino^)Duplicates[i];
						if (p->containPoint(e->X, e->Y)) {
							Duplicates->RemoveAt(i);
							Duplicates->Add(p);	// move to the end, i.e. the top
							ShapeToBeMoved=p;
							m_nOffsetX=e->X-ShapeToBeMoved->getX();
							m_nOffsetY=e->Y-ShapeToBeMoved->getY();
							Invalidate();
							return;
						}
					}
					// Second, check the orginals 
					for (int i=Originals->Count-1; i>=0; i--) {
						CDomino^ p=(CDomino^)Originals[i];
						if (p->containPoint(e->X, e->Y)) {
							CDomino^ p2=gcnew CDomino(p); // make a copy of p
							Duplicates->Add(p2);
							ShapeToBeMoved=p2;	// p2 is selected, to be moved
							Originals->RemoveAt(i);	// add to the end
							m_nOffsetX=e->X-ShapeToBeMoved->getX();
							m_nOffsetY=e->Y-ShapeToBeMoved->getY();
							ShapeToBeMoved->setTX(ShapeToBeMoved->getX());
							ShapeToBeMoved->setTY(ShapeToBeMoved->getY());
							Invalidate();
							//if (Originals->Count==0){Exit();}
							return;
						}
					}
				}
			 }
	private: System::Void Form1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				if (e->Button == System::Windows::Forms::MouseButtons::Left) {
					if (ShapeToBeMoved!=nullptr) {
						ShapeToBeMoved->setX(e->X-m_nOffsetX);
						ShapeToBeMoved->setY(e->Y-m_nOffsetY);
						Invalidate();
					}
				}
			 }
	private: System::Void Form1_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
					for (int j=Duplicates->Count-2; j>=0; j--) {
						CDomino^ q=(CDomino^)Duplicates[j];
						if (q->containPoint(ShapeToBeMoved->getX(), ShapeToBeMoved->getY())||q->containPoint(ShapeToBeMoved->getX()+ShapeToBeMoved->getWidth(), ShapeToBeMoved->getY())||q->containPoint(ShapeToBeMoved->getX()+ShapeToBeMoved->getWidth(), ShapeToBeMoved->getY()+ShapeToBeMoved->getHeight())||q->containPoint(ShapeToBeMoved->getX(),ShapeToBeMoved->getY()+ShapeToBeMoved->getHeight())) {
							int xx=ShapeToBeMoved->getTX();
							int yy=ShapeToBeMoved->getTY();
							
							ShapeToBeMoved->setX(xx);
							ShapeToBeMoved->setY(yy);
						}
					}
				 if (Originals->Count==0){Exit();}
				//checkEdge();
				ShapeToBeMoved=nullptr; // no shape selected
				Invalidate();
			 }
	private: System::Void Form1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				if (e->Button == System::Windows::Forms::MouseButtons::Right) {
					for (int i=Duplicates->Count-1; i>=0; i--) {
						CDomino^ p=(CDomino^)Duplicates[i];
						if (p->containPoint(e->X, e->Y)) {
							p->rotate();
							Invalidate();
							break;
						}
					}
				}
			 }
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
};
}

