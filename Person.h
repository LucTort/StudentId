//References Stud class from assignment 4

using namespace std;
#include <cstdlib>
#include <stdexcept>
#include <iostream>
#include "DoublyLinkedList.cpp"


class Person
{
    private:
        int id;
        string name;

        //for students
        string standing;
        string major;
        double GPA;
        string advisor;

        //for faculty
        string level;
        string department;
        //DoublyLinkedList<int> *myDoubly = new DoublyLinkedList<int>();
        DoublyLinkedList<int> *advisees = new DoublyLinkedList<int>();
        // SOMETYPE OF LINKED LISST advisees;

    public:
        Person(); //default constructor
        Person(int id, string name, string standing, string major, double GPA, string advisor);  //constructor for students
        //Person(int id, string name, string department, string level,  DoublyLinkedList<int>* advisees);  //for the faculty
        // Person(int id, string name, string standing, string level, string department, SOMETYPE OF LINKED LISST advisees;);  //constructor for students

        //all person functions

        void setId(int id);
        void setName(string name);

        int getId();
        string getName();

        //for students

        void setStanding(string standing);
        void setMajor(string major);
        void setGPA(double GPA);
        void setAdvisor(string advisor);
        void setLevel(string levelIn);
        void setDepartment(string departmentIn);
        void setAdvisees(DoublyLinkedList<int> *adviseesIn);


        string getStanding();
        string getMajor();
        double getGPA();
        int getAdvisor();
        string getLevel();
        string getDepartment();
        DoublyLinkedList<int> getAdvisees();



        //print functions

        void printStudData();
        void printFacData();

      ~Person();
};
