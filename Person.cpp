//References Stud class from assignment 4

#include "Person.h"

Person::Person()
{

}

Person::Person(int idIn, string nameIn, string standingIn, string majorIn, double GPAIn, int advisorIn)
{
    id = idIn;
    name = nameIn;
    standing = standingIn;

}

        void Person::setId(int IDIn)
        {
            id = IDIn;
        }

        void Person::setName(string nameIn)
        {
            name = nameIn;
        }

        void Person::setStanding(int standingIn)
        {
            standing = standingIn;
        }

        void Person::setMajor(int majorIn)
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



        int Person::getId()
        {
            return id;
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

        Person::~Person()
        {
            
        }