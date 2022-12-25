#pragma once
#ifndef CATEGORY_H
#define CATEGORY_H
#include "grade_calculator.h"

class Category {
public:
	Category(Course* c, string name);
	~Category();
	bool addAssignment(string s, double d);
	string getName() { return m_name; };
	Assignment* getAssignment(int n) { return m_Assignments[n]; };
	int AssignmentCount() { return m_nAssignments; };

private:
	string m_name;
	Assignment* m_Assignments[MAXASSIGNMENTS];
	int m_nAssignments;
};



#endif

