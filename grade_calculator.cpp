#include "Course.h"
#include "GradingScheme.h"
#include "Category.h"
#include "Assignment.h"

Course* Courses[MAXCOURSES];
int nCourses = 0;

// Create Course and assign it a grading basis
Course* createCourse()
{
    // CourseName can't be empty string
    string CourseName;
    do {
        CourseName = get_string("Name of Course: ");
    } while(CourseName == "");

    Courses[nCourses] = new Course(CourseName);
    Course* thisCourse = Courses[nCourses];
    nCourses++;

    string gradingBasis;
    do {
        gradingBasis = get_string("Grading Basis (LETTER or PASSNOPASS): ");

    } while (gradingBasis != "LETTER" && gradingBasis != "PASSNOPASS");
    thisCourse->assignGradingBasis(gradingBasis);
    return thisCourse;
}

// Create categories and their respective assignments
int createCategoriesAndAssignments(Course* course)
{
    while (true)
    {
        string CategoryName = get_string("Type nothing but Enter once done. Input name for the category (e.g homework, midterms, final, projects, essays): ");
        if (CategoryName != "")
        {
            course->addCategory(CategoryName);
            cout << "Category " << CategoryName << " added!" << endl;
        }
        else
            break;
    }

    // For each Category
    for (int i = 0; i < course->CategoryCount(); i++)
    {

        Category* c = course->getCategory(i);
        string cname = c->getName();

        cout << "Let's input assignments to this category: " << cname << endl;

        // Repeatedly create Assignments
        while (true)
        {
            string s = "Type nothing but Enter once done. Type a name or number to label this: " + cname + " ";
            string AssignmentName = get_string(s);
            if (AssignmentName != "")
            {
                s = "How many possible points is this " + cname + " out of? ";
                double points = get_double(s);

                c->addAssignment(AssignmentName, points);
                cout << cname << " " << AssignmentName << " created. Out of " << points << " points." << endl;
            }
            else
                break;
        }
    }
    return course->CategoryCount();
}

double runCourseCalculator()
{
    // Choose course
    Course* thisCourse = getCourse(Courses, nCourses);

    // Store grades
    double pointsScored[MAXCATEGORIES][MAXASSIGNMENTS];

    for (int i = 0; i < thisCourse->CategoryCount(); i++)
    {
        Category* thisCategory = thisCourse->getCategory(i);

        for (int j = 0; j < thisCategory->AssignmentCount(); j++)
        {
            Assignment* thisAssignment = thisCategory->getAssignment(j);
            string s = "Points earned for " + thisCategory->getName() + " " + thisAssignment->getName() + ": ";
            double points = get_double(s);

            // Save points and calculate
            pointsScored[i][j] = points;
        }
    }

    // Calculates, saves, and outputs grade
    calcGrades(pointsScored, thisCourse);

    // Calculates which grading scheme results in best grade, and outputs which one it is and its grade
    double bestGrade = thisCourse->calcGradingSchemes();
    gradeResult(thisCourse, bestGrade);
    return bestGrade;
}

void gradeResult(Course* thisCourse, double percent)
{
    if (thisCourse->getGradingBasis() == PASSNOPASS)
    {
        if (percent >= PASSSCORE)
            cout << "PASS!" << endl;
        else
            cout << "FAILED!" << endl;
    }
    else
    {
        if (percent >= AGRADE)
            cout << "You earned an A!" << endl;
        else if (percent >= BGRADE)
            cout << "You earned a B!" << endl;
        else if (percent >= CGRADE)
            cout << "You earned a C!" << endl;
        else if (percent >= DGRADE)
            cout << "You earned a D!" << endl;
        else
            cout << "You earned an F!" << endl;
    }
}



string uppercase(string text)
{
    string upper = "";
    for (int i = 0; i < text.length(); i++)
    {
        upper += toupper(text[i]);
    }
    return upper;
}

// Gets a string and saves it to variable in all caps
string get_string(string text)
{
    cout << text;
    string input;

    getline(cin, input);
    return uppercase(input);
}

bool get_bool(string text)
{
    string input;
    do {
        cout << text;
        getline(cin, input);
        input = uppercase(input);

    } while (input != "Y" && input != "N");
    if (input == "Y")
        return true;
    else
        return false;
}

// Must be positive
double get_double(string text)
{
    double input = 0;
    do
    {
        cout << text;
        cin >> input;
    } while ( input < 0);
    cin.ignore(10000, '\n');
    return input;
}

void displayCourses(Course* courses[], int n)
{
    for (int i = 0; i < n; i++)
        cout << "[" << courses[i]->getName() << "] ";
    cout << endl;
}

Course* getCourse(Course* courses[], int n)
{
    while (true)
    {
        cout << "Which course would you like to use? " << endl;
        displayCourses(courses, n);
        string name = get_string("");
        for (int i = 0; i < n; i++)
        {
            if (name == courses[i]->getName())
            {
                cout << courses[i]->getName() << " selected." << endl;
                return courses[i];
            }
        }
    }
}

void calcGrades(double pointsScored[][MAXASSIGNMENTS], Course* course)
{
    // For each Category
    for (int i = 0; i < course->CategoryCount(); i ++)
    {
        double totalEarned = 0;
        double totalPossible = 0;
        Category* category =  course->getCategory(i);
        cout << category->getName() << ":";

        // For each assignment
        for (int j = 0; j <= category->AssignmentCount(); j++)
        {
            if (j != category->AssignmentCount())
            {
                cout << " " << pointsScored[i][j] << " |";
                totalEarned += pointsScored[i][j];
                totalPossible += category->getAssignment(j)->getPointsPossible();
            }
            // Once done, calculate grade for Category
            else
            {
                double grade = totalEarned / totalPossible * MAXPERCENT;

                // Save grade for corresponding category
                course->assignPercentage(i, grade);

                cout << "| Overall: " << grade << "%" << endl;
            }
        }
    }
}

