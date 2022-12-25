#pragma once

#ifndef GRADE_CALCULATOR_H
#define GRADE_CALCULATOR_H
#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
#include <stdlib.h>
using namespace std;

const int MAXCOURSES = 20;
const int MAXCATEGORIES = 10;
const int MAXGRADINGSCHEMES = 10;
const int MAXASSIGNMENTS = 100;
const int MAXPERCENT = 100;
const int LETTERGRADE = true;
const int PASSNOPASS = false;
const int PASSSCORE = 70;
const int AGRADE = 90;
const int BGRADE = 80;
const int CGRADE = 70;
const int DGRADE = 60;

class Course;
class GradingScheme;
class Category;
class Assignment;

// Main Functions
Course* createCourse();
int createCategoriesAndAssignments(Course* course);
double runCourseCalculator();
void gradeResult(Course* thisCourse, double percent);

// Helper Functions
void displayCourses(Course* courses[], int n);
Course* getCourse(Course* courses[], int n);
void calcGrades(double grades[][MAXASSIGNMENTS], Course* course);
void gradeResult(Course* thisCourse, double percent);

string uppercase(string text);
string get_string(string text);
bool get_bool(string text);
double get_double(string text);
#endif