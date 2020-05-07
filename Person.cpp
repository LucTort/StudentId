//References Stud class from assignment 4

#include "Person.h"

Person::Person()
{

}

Person::Person(int idIn, string nameIn, string standingIn, string majorIn, double GPAIn, string advisorIn)
{
    id = idIn;
    name = nameIn;
    standing = standingIn;
    major = majorIn;
    GPA = GPAIn;
    advisor = advisorIn;
}
Person::Person(int idIn, string nameIn, string departmentIn, string levelIn,  DoublyLinkedList *adviseeIn)
{
    id = idIn;
    name = nameIn;
    department = departmentIn;
    level = levelIn;
    advisee = adviseeIn;
}

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

        void Person::setAdvisor(string advisorIn)
        {
            advisor = advisorIn;
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

        string Person::getAdvisor()
        {
            return advisor;
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





        Person::~Person()
        {

        }
