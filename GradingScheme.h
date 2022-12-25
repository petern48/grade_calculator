#pragma once
#ifndef GRADINGSCHEME_H
#define GRADINGSCHEME_H
#include "grade_calculator.h"

class GradingScheme {
public:
	GradingScheme(Course* c, int num);
	~GradingScheme();
	bool addCategory(Course* course, Category* category, double percent);
	int CategoryCount() { return m_nCategories; };
	Category* getCategory(int n) { return m_Categories[n]; };
	int getNumber() { return m_gcNumber; };
	double calcGrade(double percentsEarned[]);
	double checkTotal();
	void resetCategories() { m_nCategories = 0; };

private:
	Course* m_Course;
	Category* m_Categories[MAXCATEGORIES];
	double m_percentages[MAXCATEGORIES];
	int m_nCategories;
	int m_gcNumber;
};

#endif