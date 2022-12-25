#pragma once

#ifndef COURSE_H
#define COURSE_H
#include "grade_calculator.h"



class Course {
public:
	Course(string name);
	~Course();
	void assignGradingBasis(string gb);
	bool getGradingBasis() { return m_gradingBasis; };
	Category* getCategory(int n) { return m_Categories[n]; };
	string getName() { return m_name; };
	bool addCategory(string name);
	int CategoryCount() { return m_nCategories; };
	bool addGradingScheme(int num);
	int GradingSchemeCount() { return m_nGradingSchemes; };
	GradingScheme* getGC(int n) { return m_GradingSchemes[n]; }
	bool assignPercentage(int courseNum, double percent);
	double calcGradingSchemes();


private:
	string m_name;
	bool m_gradingBasis;
	GradingScheme* m_GradingSchemes[MAXGRADINGSCHEMES];
	int m_nGradingSchemes;
	Category* m_Categories[MAXCATEGORIES];
	int m_nCategories;
	double m_percentages[MAXCATEGORIES]; // Percentages user earned for each category
};





#endif

