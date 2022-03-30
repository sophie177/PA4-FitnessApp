/*************************************************
*   Programmer:   Sofia Lizotte
*   Class:        CptS 122 - Lab 9
*   Programming Assignment # 4
*   File:         exercise.h
*   Description:  this file contains function documentation for Exercise.cpp
*/

#pragma once
#include "pa4header.h"

class ExercisePlan {
public:
	ExercisePlan(); // default constructor

	// ExercisePlan Constructor 
	ExercisePlan(int steps, std::string name, std::string date);

	// ExercisePlan Copy Constructor: PBR to old object
	ExercisePlan(ExercisePlan& old);

	~ExercisePlan(); // default destructor

/*    Function:   setGoalSteps()
*     Returns:    nothing
*     Parameters: goal integer
*     Note:       public, setter for goal steps in EP
*/	void setGoalSteps(int steps);

/*    Function:   getGoalSteps()
*     Returns:    int goal-steps
*     Parameters: none
*     Note:       public, getter for goal steps in EP
*/	int getGoalSteps();

/*    Function:    setPlanName()
*     Returns:     nothing
*     Parameters:  string plan
*     Note:        Public, setter for plan in EP
*/	void setPlanName(std::string plan);

/*    Function:    getPlanName()
*     Returns:     string plan-name
*     Parameters:  none
*     Note:  	   public, getter for plan name of EP
*/	std::string getPlanName();

/*    Function:    setPlanDate()
*     Returns:     nothing
*     Parameters:  string date
*     Note:        public, setter for plan date in EP
*/	void setPlanDate(std::string date);

/*    Function:    getPlanDate()
*     Returns:     plan-date
*     Parameters:  none
*     Note:        public, getter for date in EP
*/	std::string getPlanDate();

/*    Function:   editGoal()
*     Returns:    nothing
*     Parameters: none
*     Note:       Requests the number of steps to be edited into current object
*                  then uses member setter (mutator) to set goal steps
*/	void editGoal(void);

/*    Function:   toString()
*     Returns:    concatenated string of the instance of the ExercisePlan
*     Parameters: none
*     Note:       combines new inputs and old string components into new string
*/	std::string toString(void);

private:
	// Data members
	int goalSteps;
	std::string planName;
	std::string planDate;
};


/*  Function:   overloaded stream extraction operator 
*   Parameters: lhs = fstream, rhs = EP
*   Returns :   modified fstream after reading EP from fstream             */
std::fstream& operator >> (std::fstream& lhs, ExercisePlan& rhs);


	/*  Function:   overloaded stream insertion operator
	*   Parameters: PBR to lhs = ostream, rhs = EP
	*   Returns :   modified ostream after writing EP to screen            */
std::ostream& operator << (std::ostream& lhs, ExercisePlan& rhs);


	/*  Function:   overloaded stream insertion operator
	*   Parameters: PBR to lhs = fstream, rhs = EP
	*   Returns :   modified fstream after writing EP to exercisePlans.txt         */
std::fstream& operator << (std::fstream& lhs, ExercisePlan& rhs);
