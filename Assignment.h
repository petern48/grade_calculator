#pragma once
#ifndef ASSIGNMENT_CLASS_H
#define ASSIGNMENT_CLASS_H
#include "grade_calculator.h"



class Assignment {
public:
	Assignment(Category* c, string s, double d);
	~Assignment() { };
	string getName() { return m_name; };
	double calcGrade(double points);
	double getPointsPossible() { return m_pointsPossible; };
private:
	string m_name;
	Category* m_Category;
	double m_pointsPossible;
};



#endif
