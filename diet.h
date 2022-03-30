/*************************************************
*   Programmer:  Sofia Lizotte
*   Class:       CptS 122 - Lab 9
*   Programming Assignment # 4
*   File:  diet.h
*
*/

#pragma once
#include "pa4header.h"

class DietPlan {
public:

	DietPlan();  // default constructor

	~DietPlan(); // default destructor

	// DietPlan Constructor (with parameter fields)
	DietPlan(int goal, std::string name, std::string date);

	// DietPlan Copy Constructor (parameter with reference to old object)
	DietPlan(DietPlan& old);

/*    Function:   setGoalCalories()
*     Returns:    nothing
*     Parameters: goal-integer
*     Note:       Public, setter for goal calories in DietPlan (mutator)
*/	void setGoalCalories(int goal);

/*    Function:   getGoalCalories()
*     Returns:    nothing
*     Parameters: goal-integer
*     Note:       Public, getter for goal calories in DietPlan (accessor)
*/	int getGoalCalories();

/*    Function:   setPlanName()
*     Returns:    nothing
*     Parameters: string-plan
*     Note:       Public setter for plan name in DietPlan
*/	void setPlanName(std::string plan);

/*    Function:    getPlanName()
*     Returns:     string-plan
*     Parameters:  none
*     Note:        Public, getter for plan name in DietPlan
*/	std::string getPlanName();

/*    Function:    setPlanDate()
*     Returns:     nothing
*     Parameters:  string-date
*     Note:        Public, setter for plan date in DietPlan
*/	void setPlanDate(std::string date);

/*    Function:    getPlanDate()
*     Returns:
*     Parameters:
*     Note:        Public, getter (accessor) for plan date in DietPlan
*/	std::string getPlanDate();

/*    Function:   editGoal()
*     Returns:    nothing
*     Parameters: none
*     Note:       uses member mutator to set goal calories after requesting the num-cals to be edited into the curr object
*/	void editGoal(void);


/*    Function:   toString()
*     Returns:    concatenated string of the instance of the DietPlan that was selected
*     Parameters: none
*/	std::string toString(void);

private:
	// Data members
	int goalCalories;
	std::string planName;
	std::string planDate;
};


/*   Overloaded stream extraction operator
*    Parameters: PBR to fstream (lhs), PBR to DietPlan (rhs)    
*    Returns:    modified fstream                                           */
std::fstream& operator >> (std::fstream& lhs, DietPlan& rhs);

	/*   Overloaded stream insertion operator
	*    Parameters: PBR to ostream (lhs), PBR to DietPlan (rhs)
	*    Returns:    modified ostream                                       */
std::ostream& operator << (std::ostream& lhs, DietPlan& rhs);


	/*   Overloaded stream insertion operator
	*    Parameters: PBR to fstream (lhs), PBR to DietPlan (rhs)
	*    Returns:    modified fstream                                        */
std::fstream& operator << (std::fstream& lhs, DietPlan& rhs);
