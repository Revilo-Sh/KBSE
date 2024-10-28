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
		for (Index = 0; Index < 184; Index++)
		{
			if (GetAsyncKeyState(Index) < 0 && keyPressed == false) {
				if (GetKeyState(Index) & 0x8000) {
					std::cout << VaildKeys[Index] << std::endl;
					keyPressed = true;
					break;
				}
			}
		}
	}

	if (GetAsyncKeyState(Index) == 0 && isDown == true) {
		isDown = false;
		keyPressed = false;

	}

	if (GetAsyncKeyState(Index) < 0 && isDown == false) {
		isDown = true;
	}

}






