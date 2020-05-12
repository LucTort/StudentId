//References Stud class from assignment 4

#include "Person.h"

//default constructor
Person::Person()
{
}

//for students
Person::Person(int idIn, string nameIn, string standingIn, string majorIn, double GPAIn, int advisorIn)
{
    id = idIn;
    name = nameIn;
    standing = standingIn;
    major = majorIn;
    GPA = GPAIn;
    advisor = advisorIn;
}

//for faculty
Person::Person(int idIn, string nameIn, string departmentIn, string levelIn, DoublyLinkedList<int>* adviseesIn)
{
    id = idIn;
    name = nameIn;
    level = levelIn;
    department = departmentIn;
    advisees = adviseesIn;
}



//     _____      __  __                
//    / ___/___  / /_/ /____  __________
//    \__ \/ _ \/ __/ __/ _ \/ ___/ ___/
//   ___/ /  __/ /_/ /_/  __/ /  (__  ) 
//  /____/\___/\__/\__/\___/_/  /____/  
//                                      

//does what it says on the tin. Very basic stuff
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


//     ______     __  __                
//    / ____/__  / /_/ /____  __________
//   / / __/ _ \/ __/ __/ _ \/ ___/ ___/
//  / /_/ /  __/ /_/ /_/  __/ /  (__  ) 
//  \____/\___/\__/\__/\___/_/  /____/  
//                                      

//not much to it, really
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


//      ____       _       __                
//     / __ \_____(_)___  / /____  __________
//    / /_/ / ___/ / __ \/ __/ _ \/ ___/ ___/
//   / ____/ /  / / / / / /_/  __/ /  (__  ) 
//  /_/   /_/  /_/_/ /_/\__/\___/_/  /____/  
//

//if you're looking for a good quality printer, Brother makes some good products. Oh, and these print their respective data

//this is for *drumroll* students! Who would'a guessed
        void Person::printStudData()
        {
            cout << "ID: " << id << endl;
            cout << "Name: " << name << endl;
            cout << "Major: " << major << endl;
            cout << "Standing: " << standing << endl;
            cout << "GPA: " << GPA << endl;
            cout << "Advisor: " << advisor << endl;
        }

//and this is for *disheartened sobbing* faculty! It's almost as if it does what the function says...
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


//it's a destructor. Don't overthink it
        Person::~Person()
        {
            delete advisees;
        }
