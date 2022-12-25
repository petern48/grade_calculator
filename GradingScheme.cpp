#include "Course.h"
#include "GradingScheme.h"
#include "Category.h"
#include "Assignment.h"


GradingScheme::GradingScheme(Course* c, int num)
{
	m_gcNumber = num;
	m_Course = c;
	m_nCategories = 0;
};

GradingScheme::~GradingScheme() {
	for (int i = 0; i < m_nCategories; m_nCategories--)
	{
		if (m_Categories[i] != nullptr)
			delete m_Categories[i];
	}
}

bool GradingScheme::addCategory(Course* course, Category* category, double percent)
{
	m_Categories[m_nCategories] = category;
	m_percentages[m_nCategories] = percent;
	m_nCategories++;
	if (percent == 0)
	{
		cout << "Category " << category->getName() << " NOT added. " << endl;
		return false;
	}
	else
	{
		cout << "Category " << category->getName() << " added. " << endl;
		return true;
	}
}

double GradingScheme::calcGrade(double percentsEarned[])  // DOESN'T correspond with proper values in array TODO
{
	double totalEarned = 0;
	// Calculates total grade for each category
	for (int i = 0; i < m_nCategories; i++)
	{
		if (m_percentages[i] != 0)
		{
			double grade = m_percentages[i] * percentsEarned[i] / MAXPERCENT;
			totalEarned += grade;
		}
	}
	return totalEarned;
}

double GradingScheme::checkTotal()
{
	double total = 0;
	for (int i = 0; i < m_nCategories; i++)
	{
		total += m_percentages[i];
	}
	return total;
}