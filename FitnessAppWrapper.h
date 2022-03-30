/*************************************************
*   Programmer:  Sofia Lizotte
*   Class:       CptS 122 - Lab 9
*   Programming Assignment # 4
*   File:  FitnessAppWrapper.h
*   Description:  this file contains function documentation for FitnessAppWrapper.cpp
*
*/


#pragma once

#include "diet.h"
#include "exercise.h"

#include <iostream>
#include <string>
#include <fstream>

class FitnessAppWrapper {
public:
 
	FitnessAppWrapper();   // default constructor  *  do I need to declare if we never use it???

	~FitnessAppWrapper(); // default destructor * 

	/*   Function :  runApp() 
	*    Parameters: 
	*    Returns:  
	*    Note: wrapper fn handles main execution. Includes instantiation of object lists. */
	void runApp(void);

	/*   Function :  file_closed()
*    Parameters:     integer as confirmation
*    Returns:        nothing
*    Note: this function was just an excuse to practice ternary operators, could have been done more efficiently */
	void file_closed(int a);


	/*   Function :  loadDailyPlan()
*    Parameters:     filestream reference, DietPlan reference
*    Returns:        nothing (void)
*    Note:           uses overloaded operator to take single plan from filestream and load it into referenced object	*/
	void loadDailyPlan(std::fstream& fileStream, DietPlan& plan);

	/*   Function :  loadDailyPlan()
*    Parameters:     ref to filestream, ref to EP
*    Returns:        nothing (void)
*    Note:           overloaded operator used to load a plan from filestream into ref'd object	*/
	void loadDailyPlan(std::fstream& fileStream, ExercisePlan& plan);

	/*   Function :  loadWeeklyPlan()
*    Parameters:     array DietPlans, reference to filestream
*    Returns:        void
*    Note:           calls loadDailyPlan() 7 times	*/
	void loadWeeklyPlan(std::fstream& fileStream, DietPlan weeklyPlan[]);

	/*   Function :  loadWeeklyPlan()
*    Parameters:     reference to filestream and array ExercisePlans
*    Returns:        nothing
*    Note:           overloaded for ExercisePlans, same as above	*/
	void loadWeeklyPlan(std::fstream& fileStream, ExercisePlan weeklyPlan[]);

	/*    Function:      displayDailyPlan()
	*     Parameters:    reference to DietPlan (PBR)
	*     Returns:       void
	*     Note:          uses overloaded operators to output a single DietPlan	*/
		void displayDailyPlan(DietPlan& plan);

/*    Function:    displayDailyPlan()
*     Parameters:  reference to ExercisePlan (PBR) 
*     Returns:     nothing
*     Note:        overloaded operators used to display single ExercisePlan entry 
*/
	void displayDailyPlan(ExercisePlan& plan);

/*    Function:    displayWeeklyPlan()
*     Parameters:  reference array of DietPlans
*     Returns:     nothing
*     Note:        calls displayPlan() 7 times
*/
	void displayWeeklyPlan(DietPlan weeklyPlan[]);

/*    Function:    displayWeeklyPlan()
*     Parameters:  reference array of ExercisePlans
*     Returns:     nothing
*     Note:        calls displayDailyPlan() 7 times
*/ void displayWeeklyPlan(ExercisePlan weeklyPlan[]);

/*    Function:     writeDailyPlanToFile()
*     Parameters:   reference to filestram and DietPlan object
*     Returns:      nothing
*     Note:
*/	void writeDailyPlanToFile(std::fstream& outfile, DietPlan& plan);

/*    Function:     writeDailyPlanToFile()
*     Parameters:   reference to filestream and ExercisePlan object
*     Returns:      nothing
*     Note:         overloaded operator used to write a single exercise plan to file
*/	void writeDailyPlanToFile(std::fstream& outfile, ExercisePlan& plan);

/*    Function:      writeWeeklyPlanToFile()
*     Parameters:    reference to filestream, ref to array of DietPlans
*     Returns:       nothing
*     Note:          calls writeDailyPlanToFile() 7 times
*/	void writeWeeklyPlanToFile(std::fstream& outfile, DietPlan weeklyPlan[]);

/*    Function:      writeWeeklyPlanToFile()
*     Parameters:    ref to filestream, ref to array of ExercisePlans
*     Returns:       nothing
*     Note:          calls writeDailyPlan 7 times, uses overloaded operators
*/	void writeWeeklyPlanToFile(std::fstream& outfile, ExercisePlan weeklyPlan[]);

/*    Function:      chooseDailyPlanFromWeekly()
*     Parameters:    array of DietPlans
*     Returns:       integer indicating user choice of plan to edit
*     Note:          helper fn for editing
*/	int chooseDailyPlanFromWeekly(DietPlan weeklyPlan[]);

/*    Function:      chooseDailyPlanFromWeekly()
*     Parameters:    array of ExercisePlans
*     Returns:       integer (user choice of plan to edit)
*     Note:
*/	int chooseDailyPlanFromWeekly(ExercisePlan weeklyPlan[]);

/*    Function:      displayMenu()
*     No Parameters, nothing Returned
*     Note:          displays menu for navigating, changes menu colors based on number of times refreshed
*/	int displayMenu(void);

private:
	// No private data members.  
};
