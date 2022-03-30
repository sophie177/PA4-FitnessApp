/*************************************************
*   Programmer:  Sofia Lizotte
*   Class:       CptS 122 - Lab 9
*   Programming Assignment # 4
*   File:  diet.cpp
*   Note: Overloaded stream operators are directly copied from class code
*/

#include "pa4header.h"
#include "diet.h"

DietPlan::DietPlan() { // default constructor
	goalCalories = 0;  // goal member
	planName = "";     // name member
	planDate = "";     // date member
}

// DietPlan Default Destructor
DietPlan::~DietPlan() {
	//implicit destructor, destructs when object leaves scope
}

DietPlan::DietPlan(int goal, std::string name, std::string date) {
	// explicit constructor with parameters
	goalCalories = goal;
	planName = name;
	planDate = date;
}

DietPlan::DietPlan(DietPlan& old) { // copy constructor, param = reference to old object
	goalCalories = old.getGoalCalories();
	planName = old.getPlanName();
	planDate = old.getPlanDate();
}

void DietPlan::setGoalCalories(int goal) { // setter (mutator)
	(goal > 100) ? goalCalories = goal : goalCalories = 100;
}

int DietPlan::getGoalCalories() {
	return goalCalories; // setter for goal calories in DietPlan
}

void DietPlan::setPlanName(std::string plan) {
	planName = plan;  // getter fn
}

std::string DietPlan::getPlanName() {
	return planName;  // can get name of DietPlan (Accessor)
}

void DietPlan::setPlanDate(std::string date) {
	planDate = date;  // set date of DietPlan (mutator)
}

std::string DietPlan::getPlanDate() {
	return planDate;   // can access date of member DietPlan
}

void DietPlan::editGoal(void) {
	system("cls");
	int newGoal = 0;
	std::cout << "How many calories is your new goal?: ";
	std::cin >> newGoal;
	setGoalCalories(newGoal); // member setter fn call
}

std::string DietPlan::toString(void) {
	// concatenated string of DietPlan for the specific case
	return "Diet Plan " + planName + " for " + planDate + ": Goal: " + std::to_string(goalCalories) + " calories";
}


std::fstream& operator >> (std::fstream& lhs, DietPlan& rhs) {
	// extraction operator is overloaded for diet/exercise filestreams
	std::string name;
	std::getline(lhs, name);
	std::string strCalories; // lhs = fstream
	std::getline(lhs, strCalories);
	int calories = stoi(strCalories);
	std::string date;
	std::getline(lhs, date);
	std::string newline;  // rhs = dietPlan
	std::getline(lhs, newline);
	rhs.setPlanName(name);
	rhs.setGoalCalories(calories);
	rhs.setPlanDate(date);
	return lhs;
}


std::ostream& operator << (std::ostream& lhs, DietPlan& rhs) {
	// overloaded stream insertion operator : 
	lhs << "Diet Plan " << rhs.getPlanName() << " for " << rhs.getPlanDate() << ": Goal: " << rhs.getGoalCalories() << " calories";
	return lhs;
}


std::fstream& operator << (std::fstream& lhs, DietPlan& rhs) {
	// write DietPlan to dietPlans.txt : 
	lhs << rhs.getPlanName() << std::endl; // lhs = fstream, rhs = DietPlan
	lhs << rhs.getGoalCalories() << std::endl;
	lhs << rhs.getPlanDate() << std::endl;
	lhs << "\n";
	return lhs;
}