/*************************************************
*   Programmer:  Sofia Lizotte
*   Class:       CptS 122 - Lab 9
*   Programming Assignment # 4
*   File:  exercise.cpp
*   Note: overloaded stream operators are copied from class code
*/

#include "pa4header.h"
#include "exercise.h"

ExercisePlan::ExercisePlan() {  // default constructor (compiler - generated)
	goalSteps = 0;      // goal member
	planName = "";      // name member
	planDate = "";      // date member
}

ExercisePlan::ExercisePlan(int steps, std::string name, std::string date) {  
	// explicit constructor with parameters
	goalSteps = steps;      
	planName = name;
	planDate = date;
}

ExercisePlan::ExercisePlan(ExercisePlan& old) {  // explicit copy constructor  (param = reference to old object)
	goalSteps = old.getGoalSteps();
	planName = old.getPlanName();
	planDate = old.getPlanDate();
}

ExercisePlan::~ExercisePlan() { 
	// default destructor, invoked when object leaves scope (implicit)
}

void ExercisePlan::setGoalSteps(int steps) {
	(steps < 100) ? goalSteps = 100 : goalSteps = steps;
}

int ExercisePlan::getGoalSteps() {
	return goalSteps;
}

void ExercisePlan::setPlanName(std::string plan) {
	planName = plan;
}

std::string ExercisePlan::getPlanName() {
	return planName;
}

void ExercisePlan::setPlanDate(std::string date) {
	planDate = date;
}

std::string ExercisePlan::getPlanDate() {
	return planDate;
}

void ExercisePlan::editGoal(void) {
	system("cls");
	int newGoal = 0;
	std::cout << "Enter your new goal # of steps: \n";
	std::cin >> newGoal;
	setGoalSteps(newGoal);
}

std::string ExercisePlan::toString(void) {
	// here is the concatenated string : 
	return "Exercise Plan " + planName + " for " + planDate + ": Goal: " + std::to_string(goalSteps) + " steps";
	// simply becomes a std string
}

std::fstream& operator >> (std::fstream& lhs, ExercisePlan& rhs) {// overloaded extraction operator
	std::string name;
	std::getline(lhs, name);
	std::string strSteps;
	std::getline(lhs, strSteps);
	int steps = stoi(strSteps);
	std::string date;
	std::getline(lhs, date);
	std::string newline;
	std::getline(lhs, newline);
	rhs.setPlanName(name);
	rhs.setGoalSteps(steps);
	rhs.setPlanDate(date);
	return lhs;
}

std::ostream& operator << (std::ostream& lhs, ExercisePlan& rhs) { 
	// overloaded stream insertion operator
	lhs << "Exercise Plan " << rhs.getPlanName() << " for " << rhs.getPlanDate() << ": Goal: " << rhs.getGoalSteps() << " steps";
	return lhs;
}

std::fstream& operator << (std::fstream& lhs, ExercisePlan& rhs) {
	// overloaded stream insertion operator
	lhs << rhs.getPlanName() << std::endl;
	lhs << rhs.getGoalSteps() << std::endl;
	lhs << rhs.getPlanDate() << std::endl;
	lhs << "\n";
	return lhs;
}