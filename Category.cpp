#include "Category.h"
#include "Course.h"
#include "GradingScheme.h"
#include "Assignment.h"

Category::Category(Course* c, string name)
{
	m_name = name;
	Course* m_Course = c;
	m_nAssignments = 0;
}

Category::~Category()
{
	for (int i = 0; i < m_nAssignments; m_nAssignments--)
	{
		if (m_Assignments[i] != nullptr)
			delete m_Assignments[i];
	}
}

bool Category::addAssignment(string s, double d)
{
	m_Assignments[m_nAssignments] = new Assignment(this, s, d);
	m_nAssignments++;
	return true;
}