/*************************************************
*   Programmer:  Sofia Lizotte
*   Class:       CptS 122 - Lab 9
*   Programming Assignment # 4
*   File:  main.cpp  (driver program)
*   Description:   load, store, edit and save diet + exercise plans to .txt files with an array of objects.  
*
*/

#include "pa4header.h"
#include "FitnessAppWrapper.h"

int main(void) {

	system("Color 0C");
	cout<< " Initializing Full Body Composition Scan.... \n";
	cout << "Your Personalized Fitness Plan is Complete! \n";
	system("cls");
	system("07");
	FitnessAppWrapper appWrapper; // have to create an instance of FitnessAppWrapper (this was causing errors)
	appWrapper.runApp();  // call runApp fn  

	return 0; 
}