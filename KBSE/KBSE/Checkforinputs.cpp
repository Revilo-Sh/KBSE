#include "Checkforinputs.h"
#include <iostream>
#include <windows.h>


using namespace std;

Checkforinputs::Checkforinputs()
{
	cout << "Loaded Keyboard Keys" << endl;
}

Checkforinputs::~Checkforinputs()
{
	cout << "DeLoaded Keyboard Keys" << endl;
}

void Checkforinputs::AddToList()
{
}

void Checkforinputs::pressDown()
{
	if (!keyPressed) {
		for (Index = 0; Index < 190; Index++)
		{
			if (GetAsyncKeyState(Index) < 0 && keyPressed == false) {
				if (GetKeyState(Index) & 0x8000) {
					std::cout << VaildKeys[Index] << std::endl;
					keyPressed = true;
					inputindex = 1;
					break;
				}
				else
				{
					cout << "cant Find Key" << endl;
				}
			}
			
		}
	}

	if (GetAsyncKeyState(Index) == 0 && isDown == true) {
		isDown = false;
		keyPressed = false;
		inputindex = 0;
		SoundPlayRate = true;
		
		
	}

	if (GetAsyncKeyState(Index) < 0 && isDown == false) {
		isDown = true;
	}

}






