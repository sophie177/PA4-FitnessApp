/*************************************************
*   Programmer:  Sofia Lizotte
*   Class:       CptS 122 - Lab 9
*   Programming Assignment # 4
*   File:  FitnessAppWrapper.cpp
*   Description: this file contains the 'wrapper' that takes two arrays and stores the instances of class ExercisePlan 
*                 and DietPlan by day (one day = one array element). It assigns two filestreams to each in order to 
*                 fill the array elements and change file contents if the user wants to edit data. 
*
*/

#include "pa4header.h"
#include "FitnessAppWrapper.h"

using std::cout;
using std::cin;
using std::endl;
using std::fstream;

FitnessAppWrapper::FitnessAppWrapper() { }  // default Constructor (compiler - generated)

FitnessAppWrapper::~FitnessAppWrapper() { } // default Destructor (compiler - generated)

void FitnessAppWrapper::runApp(void) {  // wrapper fn 

	// ClassName ObjectName[number of objects]; 
	DietPlan dietPlanList[7] = {};   
	ExercisePlan exercisePlanList[7] = {};   
	bool appLoop = true;

	bool dietLoaded = false, exerciseLoaded = false;

	fstream fsDiet;
	fstream fsExercise;

	do{
		system("cls");
		int choice = displayMenu();
		

		switch (choice) {
		case 1:
			fsDiet.open("dietPlans.txt");  
			if (fsDiet.is_open()) {
				loadWeeklyPlan(fsDiet, dietPlanList); // store each instance of dietPlans in one array element
					dietLoaded = true;
					cout << "Weekly diet plan loaded!" << endl;
					fsDiet.close();
			}else{
				cout << "Cannot open dietPlans.txt!" << endl;  //  -    error checking! 
			}
			system("pause");

			break;
		case 2:
			fsExercise.open("exercisePlans.txt");
			if (fsExercise.is_open()) {
				loadWeeklyPlan(fsExercise, exercisePlanList); // store each instance of exercisePlans in one array element
				exerciseLoaded = true;
				cout << "Weekly exercise plan loaded!" << endl;
				fsExercise.close();
			}
			else
			{
				cout << "Cannot open exercisePlans.txt!" << endl;
			}
			system("pause"); 


			break;
		case 3:
			//Store weekly diet plan to file.
			fsDiet.open("dietPlans.txt");
			if (fsDiet.is_open()) {
				writeWeeklyPlanToFile(fsDiet, dietPlanList);
				cout << "Plan written to dietPlans.txt!" << endl;
				fsDiet.close();
			}
			else
			{
				cout << "Cannot open dietPlans.txt!" << endl;
			}
			system("pause"); 
			break;
		case 4:
			//Store weekly exercise plan to file.
			fsExercise.open("exercisePlans.txt");
			if (fsExercise.is_open()) {
				writeWeeklyPlanToFile(fsExercise, exercisePlanList);
				cout << "Plan written to exercisePlans.txt!" << endl;
				fsExercise.close();
			}
			else
			{
				cout << "Cannot open exercisePlans.txt!" << endl;
			}
			system("pause"); 
			break;
		case 5:
			if (dietLoaded) {
				displayWeeklyPlan(dietPlanList); // display weekly diet plan
			}
			else
			{
				cout << "Error: diet plan not loaded !" << endl;
			}
			system("pause"); 
			break;
		case 6:
			if (exerciseLoaded) {
				displayWeeklyPlan(exercisePlanList); // display weekly exercise plan
			}
			else
			{
				cout << "Error: exercise plan not loaded!" << endl;
			}
			system("pause"); 
			break;
		case 7:
			//Edit daily diet plan.
			if (dietLoaded) {  
				int planNumber = chooseDailyPlanFromWeekly(dietPlanList);
				dietPlanList[planNumber].editGoal();
				displayDailyPlan(dietPlanList[planNumber]);
			}
			else
			{
				cout << "Error: no diet plan loaded!" << endl;
			}
			system("pause"); 
			break;
		case 8:
			//Edit daily exercise plan.
			if (exerciseLoaded) {
				int planNumber = chooseDailyPlanFromWeekly(exercisePlanList);
				exercisePlanList[planNumber].editGoal();
				displayDailyPlan(exercisePlanList[planNumber]);
			}
			else
			{
				cout << "Error: no exercise plan loaded!" << endl;
			}
			system("pause");
			break;
		case 9:
			//Exit
			if (dietLoaded) {
				fsDiet.open("dietPlans.txt");
				writeWeeklyPlanToFile(fsDiet, dietPlanList);
				fsExercise.close();
			}

			if (exerciseLoaded) {
				fsExercise.open("exercisePlans.txt");
				writeWeeklyPlanToFile(fsExercise, exercisePlanList);
				fsExercise.close();
			}
			//  check to ensure files were closed
			int a = 1;  // this is just an excuse to practice ternary operators :)
			(fsExercise.is_open()) ? fsExercise.close() : file_closed(a);// (condition) ? T : F ; 
			(fsDiet.is_open()) ? fsDiet.close() : file_closed(a); 

			//Set main program loop to false to break execution
			appLoop = false;
			break;

		}//below me is the big program loop end bracket!!
	}while (appLoop);  
}



void FitnessAppWrapper::file_closed(int a) {
	
	std::string result = (a == 1) ? "file closed!\n" : "Error: couldn't close file!\n";
}

void FitnessAppWrapper::loadDailyPlan(std::fstream& fileStream, DietPlan& plan) {
	fileStream >> plan;
}

void FitnessAppWrapper::loadDailyPlan(std::fstream& fileStream, ExercisePlan& plan) {
	fileStream >> plan;
}

void FitnessAppWrapper::loadWeeklyPlan(std::fstream& fileStream, DietPlan weeklyPlan[]) {
	for (int i = 0; i < 7; i++) {
		loadDailyPlan(fileStream, weeklyPlan[i]);
	}
}

void FitnessAppWrapper::loadWeeklyPlan(std::fstream& fileStream, ExercisePlan weeklyPlan[]) {
	for (int i = 0; i < 7; i++) {
		loadDailyPlan(fileStream, weeklyPlan[i]);
	}
}

void FitnessAppWrapper::displayDailyPlan(DietPlan& plan) {
	cout << plan << endl;
}

void FitnessAppWrapper::displayDailyPlan(ExercisePlan& plan) {
	cout << plan << endl;
}

void FitnessAppWrapper::displayWeeklyPlan(DietPlan weeklyPlan[]) {
	for (int i = 0; i < 7; i++) {
		cout << i + 1 << ": ";
		displayDailyPlan(weeklyPlan[i]);
	}
}

void FitnessAppWrapper::displayWeeklyPlan(ExercisePlan weeklyPlan[]) {
	for (int i = 0; i < 7; i++) {
		cout << i + 1 << ": ";
		displayDailyPlan(weeklyPlan[i]); 
	}
}

void FitnessAppWrapper::writeDailyPlanToFile(std::fstream& outfile, DietPlan& plan) {
	outfile << plan;
}

void FitnessAppWrapper::writeDailyPlanToFile(std::fstream& outfile, ExercisePlan& plan) {
	outfile << plan;
}

void FitnessAppWrapper::writeWeeklyPlanToFile(std::fstream& outfile, DietPlan weeklyPlan[]) {
	for (int i = 0; i < 7; i++) {
		writeDailyPlanToFile(outfile, weeklyPlan[i]);
	}
}

void FitnessAppWrapper::writeWeeklyPlanToFile(std::fstream& outfile, ExercisePlan weeklyPlan[]) {
	for (int i = 0; i < 7; i++) {
		writeDailyPlanToFile(outfile, weeklyPlan[i]);
	}
}

int FitnessAppWrapper::chooseDailyPlanFromWeekly(DietPlan weeklyPlan[]) {
	int choice = 0;
	while (choice < 1 && choice > 7) {
		system("cls");
		displayWeeklyPlan(weeklyPlan);
		cout << "Which plan would you like to modify? Enter the corresponding number: ";
		cin >> choice;
		cout << endl << "you chose:" << choice << endl;
	}
	return choice;
}

int FitnessAppWrapper::chooseDailyPlanFromWeekly(ExercisePlan weeklyPlan[]) {
	int choice = 0;
	while (choice < 1 && choice > 7){
		system("cls");
		displayWeeklyPlan(weeklyPlan);
		cout << "Which plan would you like to modify? Enter the corresponding number: ";
		cin >> choice;
		cout << endl << "you chose:" << choice << endl; 
		}
	return choice;
}

int FitnessAppWrapper::displayMenu(void) {
	static unsigned int call_count = 0; // keeps mem same after fn call
	// change color each time menu is refreshed : )
	// this is just another excuse to practice ternary operators
		(call_count % 2 == 0) ? system("Color 06") : system("Color 09"); // yellow and blue
	cout << "\n      Welcome to your fitness Planner ! \n" << endl;
	cout << "   Please enter the number that corresponds to your choice : \n" << endl;
	system("pause");
	//static unsigned int second = 0;
	//(second % 2 == 0) ? system("Color 03") : system("Color 05");     // aqua and purple
	call_count++;
	//second++;
	cout << "(1)    Load this week's diet plan from file." << endl;
	cout << "(2)    Load this week's exercise plan from file." << endl;
	cout << "(3)    Store this week's diet plan to file." << endl;
	cout << "(4)    Store this week's exercise plan to file." << endl;
	cout << "(5)    Display this week's diet plan to screen." << endl;
	cout << "(6)    Display this week's exercise plan to screen." << endl;
	cout << "(7)    Edit this week's diet plan." << endl;
	cout << "(8)    Edit this week's exercise plan." << endl;
	cout << "(9)    Exit" << endl;
	int num = 0; // for user choice
	cin >> num;
	return num;  

}