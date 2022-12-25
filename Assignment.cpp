#include "Course.h"
#include "GradingScheme.h"
#include "Category.h"
#include "Assignment.h"

Assignment::Assignment(Category* c, string s, double d)
{
	m_Category = c;
	m_name = s;
	m_pointsPossible = d;
}

double Assignment::calcGrade(double points)
{
	return points / m_pointsPossible;
}