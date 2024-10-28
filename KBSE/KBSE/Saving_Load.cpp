#include "Saving_Load.h"
#include <iostream>
#include <fstream>


using namespace std;
ofstream SaveFile("SaveData");

Saving_Load::Saving_Load()
{
	cout << "Loaded All Save To KBSE" << endl;

	
}

Saving_Load::~Saving_Load()
{
	cout << "Saved All Data" << endl;
	//SaveFile << DarkMode;
}

void Saving_Load::SaveDarkMode(int State)
{
	DarkMode = State;
}
