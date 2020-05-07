//References Stud class from assignment 4

#include "Person.h"

Person::Person()
{

}

Person::Person(int idIn, string nameIn, string standingIn, string majorIn, double GPAIn, int advisorIn)  //for the students
{
    id = idIn;
    name = nameIn;
    standing = standingIn;
    major = majorIn;
    GPA = GPAIn;
    advisor = advisorIn;
}

// Person::Person(int idIn, string nameIn, string departmentIn, string levelIn,  DoublyLinkedList<int>* adviseesIn)  //for the faculty
// {
//     id = idIn;
//     name = nameIn;
//     department = departmentIn;
//     level = levelIn;
//     advisees = adviseesIn;
// }

        void Person::setId(int IDIn)
        {
            id = IDIn;
        }

        void Person::setName(string nameIn)
        {
            name = nameIn;
        }

        void Person::setStanding(string standingIn)
        {
            standing = standingIn;
        }

        void Person::setMajor(string majorIn)
        {
            major = majorIn;
        }

        void Person::setGPA(double GPAIn)
        {
            GPA = GPAIn;
        }

        void Person::setAdvisor(int advisorIn)
        {
            advisor = advisorIn;
        }

        void Person::setLevel(string levelIn)
        {
            level = levelIn;
        }

        void Person::setDepartment(string departmentIn)
        {
            department = departmentIn;
        }

        void Person::setAdvisees(DoublyLinkedList<int> *adviseesIn)
        {
            advisees = adviseesIn;
        }






        int Person::getId()
        {
            return id;
        }

        string Person::getName()
        {
            return name;
        }


        string Person::getStanding()
        {
            return standing;
        }

        string Person::getMajor()
        {
            return major;
        }

        double Person::getGPA()
        {
            return GPA;
        }

        int Person::getAdvisor()
        {
            return advisor;
        }

        string Person::getLevel()
        {
            return level;
        }

        string Person::getDepartment()
        {
            return department;
        }

        DoublyLinkedList<int>* Person::getAdvisees()
        {
            return advisees;
        }


        void Person::printStudData()
        {
            cout << "ID: " << id << endl;
            cout << "Name: " << name << endl;
            cout << "Major: " << major << endl;
            cout << "Standing: " << standing << endl;
            cout << "GPA: " << GPA << endl;
            cout << "Advisor: " << advisor << endl;
        }

        void Person::printFacData()
        {
            cout << "ID: " << id << endl;
            cout << "Name: " << name << endl;
            cout << "Level: " << level << endl;
            cout << "Department: " << department << endl;
            cout << "Advisees: ";
            advisees->printList();
            cout << endl;
        }





        Person::~Person()
        {

        }
