#include "Course.h"
#include "GradingScheme.h"
#include "Category.h"
#include "Assignment.h"

int main()
{
    cout << "Let's make a new course!" << endl;

    // Create new Course object and assign it a grading basis
    Course* thisCourse = createCourse();
    cout << "Course created." << endl;
    cout << "Create categories:" << endl;

    // Repeatedly create Categories and Assignments for this course until user says no more
    createCategoriesAndAssignments(thisCourse);

    GradingScheme* thisGC;
    int gcNumber = thisCourse->GradingSchemeCount();

    while (gcNumber == 0 || get_bool("Create another grading scheme (Y/N)? ") == true)
    {
        // Create Grading Scheme
        if (thisCourse->addGradingScheme(gcNumber) == false)
        {
            cout << "Max number of gradings schemes has already been reached" << endl;
            break;
        }

        thisGC = thisCourse->getGC(gcNumber);
        gcNumber = thisCourse->GradingSchemeCount();

        cout << "Grading scheme number " << gcNumber << " successfully created!" << endl;

        bool included = false;
        // Select categories to include
        for (int i = 0; i < thisCourse->CategoryCount() || included == false; i++)
        {
            // If no category, was included, reset loop
            if (i == thisCourse->CategoryCount())
            {
                i = 0;
                thisGC->resetCategories();
                cout << "Must include at least one category" << endl;
            }
            Category* thisCat = thisCourse->getCategory(i);
            string s = "Include category [" + thisCat->getName() + "] (Y/N)? ";
            double percent;

            if (get_bool(s) == true)
                percent = get_double("Enter category's percentage for total grade: ");
            else
                percent = 0;

            // At least one category must be included
            if (thisGC->addCategory(thisCourse, thisCat, percent))
                included = true;
        }

        // Check if Grade Scheme adds up to MAXPERCENT
        if (thisGC->checkTotal() != MAXPERCENT)
            cout << "NOTE: this Grading Scheme adds up to " << thisGC->checkTotal() << "%" << endl;

        cout << "Grade Scheme completed." << endl;
    }

    if (!get_bool("Course calculator complete. \nWould you like to use a course calculator (Y/N)? "))
    {
        // End program
        cout << "Goodbye." << endl;
        return 0;
    }

    // Runs Calculator, outputs results and whether their PASS/NOPASS or LETTERGRADE result
    runCourseCalculator();
}