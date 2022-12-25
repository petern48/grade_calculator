# C++ Grade Calculator
### Video Demo: https://youtu.be/ZYZvnMvoUw0
### Description:

Grade Calculator is a program compute overall class grades for a wide variety of college classes.
It offers the user the ability to create a **weighted** calculator specific to their classes.

### **Overview**
The calculator is implemented by 4 classes: Course, Category, Assignment, and GradingScheme. All of which are dynamically allocated, depending on the user's input.

As the user runs the program, the user is prompted to do the following:
1. Design a course calculator for their course
    - Create their `Course`
    - Assign their Course a grading basis `LETTERGRADE` or `PASSNOPASS`
    - Create the Course's `Category`s inside the Course object
    - Create `Assignment`s inside of each Category object
    - Create one or more `GradingSceme`s for their course, with some or all of its Categories
    - Assign percentages to each category to indicate how much of the total grade it weighs
2. Run the course calculator
    - Input how many points they received for each assignment

Once the program receives the user's input, it does the following:
- Calculate the percentage earned on each assignment
- Output the overall percentage for each category
- Output the overall percentage for the course for each grading scheme
- Ouput which grading scheme results in the highest grade along with the percentage it would earn
- Output the resulting letter grade or pass/no pass grade, depending on course's selected grading basis

#### **Classes:**

#### Course (`Course.h` and `Course.cpp`)
`Course` is the only independent class. The object saves a name, grading basis, categories, grading schemes, and the percentage of each category the user earned

#### Category (`Category.h` and `Category.cpp`)
`Category`s are dynamically allocated and saved to the respective course object. The object saves a name and the assignments it contains

#### Assignment (`Assignment.h` and `Assignment.cpp`)
`Assignment`s are dynamically allocated and saved to the respective Category object. The object stores its name, which category it belongs to, and the total number of points the assignment is out of.

#### GradingScheme (`GradingScheme.h` and `GradingScheme.cpp`)
`GradingScheme`s are dynamically allocated and saved to a Course object. The object saves which number grading scheme it is, and the course it belongs to. It also saves which categories from the Course object to include in the grading scheme along with the percentage each of the categories contibute to the final grade. Each grading scheme must have at least one category, the program will prompt the user to input categories again. Additionally, the `checkTotal` member function checks for whether the grading scheme adds up to 100 percent.

#### **Purpose**
Implementing each of these as separate classes allows for greater flexibility. The user, may create grading schemes that include different number of categories with different weights, according to their course's policy. For example, some classes have a grading scheme that drops one of two midterms, in case they did very poorly or could not attend one of them. This calculator would accomodate that and calculate which grading scheme is better.

**YOUTUBE DESCRIPTION**
This is my C++ project that implements classes to allow the user to create a custom course calculator for their class. It accommodates different numbers or categories, assignments, and even grading schemes. Ultimately, it will output which grading scheme is best to use and the final grade and percentage it results in.
GitHub: https://github.com/petern48
