#include "Course.h"
#include "GradingScheme.h"
#include "Category.h"
#include "Assignment.h"

Course::Course(string name)
{
	m_name = name;
	m_nGradingSchemes = 0;
	m_nCategories = 0;
}
Course::~Course()
{
	for (int i = 0; i < m_nGradingSchemes; m_nGradingSchemes--)
	{
		if (m_GradingSchemes[i] != nullptr)
		{
			delete m_GradingSchemes[i];
		}
		if (m_Categories[i] != nullptr)
			delete m_Categories[i];
	}
}

bool Course::addGradingScheme(int num)
{
	if (m_nGradingSchemes >= MAXGRADINGSCHEMES)
		return false;
	else
	{
		m_GradingSchemes[m_nGradingSchemes] = new GradingScheme(this, num);
		m_nGradingSchemes++;
		return true;
	}
}
void Course::assignGradingBasis(string GB)
{
	if (GB == "LETTER")
		m_gradingBasis = LETTERGRADE;
	else
		m_gradingBasis = PASSNOPASS;

}

bool Course::addCategory(string name)
{
	if (m_nCategories >= MAXCATEGORIES)
	{
		cout << "Max number of categories has been reached";
		return false;
	}
	else
	{
		m_Categories[m_nCategories] = new Category(this, name);
		m_nCategories++;
		return true;
	}
}

bool Course::assignPercentage(int courseNum, double percent)
{
	this->m_percentages[courseNum] = percent;
	return true;
}

double Course::calcGradingSchemes()
{
	GradingScheme* bestGC = nullptr;
	double bestGrade = 0;
	// For each Grading Scheme
	for (int i = 0; i < m_nGradingSchemes; i++)
	{
		GradingScheme* thisGC = this->getGC(i);
		double grade = thisGC->calcGrade(this->m_percentages);
		if (grade > bestGrade)
		{
			bestGrade = grade;
			bestGC = thisGC;
		}
		//else if (grade == bestGrade)

		cout << "Grading Scheme #" << thisGC->getNumber() + 1 << ": " << grade << "%" << endl;
	}
	cout << endl << "Best Grading Scheme is number " << bestGC->getNumber() + 1 << ": " << bestGrade << "%" << endl;

	return bestGrade;
}
