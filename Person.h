//References Stud class from assignment 4

using namespace std;
#include <cstdlib>
#include <stdexcept>
#include <iostream>


class Person
{
    private:
        int id;
        string name;

        //for students
        string standing;
        string major;
        double GPA;
        int advisor;

        //for faculty
        string level;
        string department;
        // SOMETYPE OF LINKED LISST advisees;

    public:
        Person(); //default constructor
        Person(int id, string name, string standing, string major, double GPA, int advisor);  //constructor for students
        // Person(int id, string name, string standing, string level, string department, SOMETYPE OF LINKED LISST advisees;);  //constructor for students

        //all person functions

        void setId(int id);
        void setName(int name);

        int getId();
        string getName();

        //for students

        void setStanding(int standing);
        void setMajor(int major);
        void setGPA(double GPA);
        void setGPA(int advisor);

        int getStanding();
        int getMajor();
        double getGPA();

      ~Person();
};