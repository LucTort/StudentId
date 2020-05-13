//uses code from assignment 4
//https://stackoverflow.com/questions/17032970/clear-data-inside-text-file-in-c
//Uses code from assignment 1
//https://stackoverflow.com/questions/7663709/how-can-i-convert-a-stdstring-to-int
//https://www.cplusplus.com/forum/general/1796/
//https://stackoverflow.com/questions/18100391/check-if-a-file-exists-without-opening-it
//https://stackoverflow.com/questions/230062/whats-the-best-way-to-check-if-a-file-exists-in-c
//https://www.ibm.com/support/knowledgecenter/en/SSLTBW_2.3.0/com.ibm.zos.v2r3.bpxbd00/rtacc.htm
#include "FileManager.h"

//    _____              __               __
//   / ___/__  ___  ___ / /_______ ______/ /____  _______
//  / /__/ _ \/ _ \(_-</ __/ __/ // / __/ __/ _ \/ __(_-<
//  \___/\___/_//_/___/\__/_/  \_,_/\__/\__/\___/_/ /___/
//   Constructors

//default constructor
FileManager::FileManager()
{
    studDataFile = "studentTable.txt";
    facDataFile = "facultyTable.txt";

    const char *facDataFileTest = "facultyTable.txt";
    const char *studDataFileTest = "studentTable.txt";


    //makes sure that there is some data in the file if there wasn't any previously. Otherwise program would crash
    if( access( facDataFileTest, F_OK ) != -1 ) //https://stackoverflow.com/questions/230062/whats-the-best-way-to-check-if-a-file-exists-in-c
        {                                       //https://www.ibm.com/support/knowledgecenter/en/SSLTBW_2.3.0/com.ibm.zos.v2r3.bpxbd00/rtacc.htm
        // file exists
        } else 
        {
            ofstream myFile;
            myFile.open(facDataFile, std::ofstream::out | std::ofstream::trunc);
            myFile << "0" << endl;
            myFile.close();
        }
            

        if( access( studDataFileTest, F_OK ) != -1 ) 
        {
        // file exists
        } else 
        {
            ofstream myFile;
            myFile.open(studDataFile, std::ofstream::out | std::ofstream::trunc);
            myFile << "0" << endl;
            myFile.close();
        }
}

//overloaded constructor for using different file names
//If going to use this need to add code to create a file if there aren't any
FileManager::FileManager(string studData, string facData)
{
    studDataFile = studData;
    facDataFile = facData;
}

//     ____                ____              __  _
//    / __/__ __  _____   / __/_ _____  ____/ /_(_)__  ___  ___
//   _\ \/ _ `/ |/ / -_) / _// // / _ \/ __/ __/ / _ \/ _ \(_-<
//  /___/\_,_/|___/\__/ /_/  \_,_/_//_/\__/\__/_/\___/_//_/___/
//  Save Functions

//saves a DoublyLinkedList of students to a specified file
void FileManager::saveStudFile(DoublyLinkedList<Person*> studNodes)
{
    ofstream myFile;
    myFile.open(studDataFile, std::ofstream::out | std::ofstream::trunc);

    Person *currentStud = new Person();

    myFile << studNodes.getSize() << endl;  //puts number of students at top of file

    while (studNodes.getSize() > 0)
    {

        currentStud = studNodes.removeFront();

        myFile << currentStud->getId() << endl;
        myFile << currentStud->getName() << endl;
        myFile << currentStud->getStanding() << endl;
        myFile << currentStud->getGPA() << endl;
        myFile << currentStud->getMajor() << endl;
        myFile << currentStud->getAdvisor() << endl;

        myFile << endl;
    }

    myFile.close();

}

//saves a DoublyLinkedList of students to a specified file
void FileManager::saveFacFile(DoublyLinkedList<Person*> facNodes)
{
    ofstream myFile;
    myFile.open(facDataFile, std::ofstream::out | std::ofstream::trunc);

    Person *currentFac = new Person();
    myFile << facNodes.getSize() << endl;  //puts number of students at top of file
    while (facNodes.getSize() > 0)
    {
        currentFac = facNodes.removeFront();

        myFile << currentFac->getId() << endl;
        myFile << currentFac->getName() << endl;
        myFile << currentFac->getLevel() << endl;
        myFile << currentFac->getDepartment() << endl;

        DoublyLinkedList<int> *advisees = new DoublyLinkedList<int>();
        advisees = currentFac->getAdvisees();
        int currentAdvisee = 0;
        // bool needEndl = false;

        myFile << advisees->getSize() << endl;


            while(advisees->getSize() > 0)
            {
                currentAdvisee = advisees->removeFront();
                myFile << currentAdvisee << endl;
                // needEndl = true;
            }
        // if (needEndl) {myFile << endl;}
        myFile << endl;
    }

    myFile.close();
}

//     __                __  ____              __  _
//    / /  ___  ___ ____/ / / __/_ _____  ____/ /_(_)__  ___  ___
//   / /__/ _ \/ _ `/ _  / / _// // / _ \/ __/ __/ / _ \/ _ \(_-<
//  /____/\___/\_,_/\_,_/ /_/  \_,_/_//_/\__/\__/_/\___/_//_/___/
//  Load Functions

//takes a file of students and outputs its data as a binary search tree of type person
BST<Person*> FileManager::getStudData()
{
    ifstream myFile;
    myFile.open(studDataFile);
    if (!myFile.is_open()) //makes sure file opens correctly
    {
        cout << "File didn't open properly" << endl;
    }

    BST<Person*> *treeFromFile = new BST<Person*>();

    string stringDataPoints;
    getline(myFile, stringDataPoints);
    int numDataPoints = stoi(stringDataPoints);

    for(int x = 0; x < numDataPoints; x++)
    {
        string fileData;

        getline(myFile, fileData);
        int ID = stoi(fileData);

        getline(myFile, fileData);
        string name = fileData;

        getline(myFile, fileData);
        string standing = fileData;

        getline(myFile, fileData);
        double GPA = stod(fileData);

        getline(myFile, fileData);
        string major = fileData;

        getline(myFile, fileData);
        int advisor = stoi(fileData);

        getline(myFile, fileData);//space between data

        Person *newStud = new Person(ID, name, standing, major, GPA, advisor);

        treeFromFile->insert(newStud->getId(), newStud);

    }

    myFile.close();

    return *treeFromFile;

}//end getStudData


//takes a file of faculty and outputs its data as a binary search tree of type person
BST<Person*> FileManager::getFacData()
{
    ifstream myFile;
    myFile.open(facDataFile);
    if (!myFile.is_open()) //makes sure file opens correctly
    {
        cout << "File didn't open properly" << endl;
    }

    BST<Person*> *treeFromFile = new BST<Person*>();

    string stringDataPoints;
    getline(myFile, stringDataPoints);
    // int numDataPoints = (int) stringDataPoints;
    int numDataPoints = stoi(stringDataPoints);

    for(int x = 0; x < numDataPoints; ++x)
    {

        string fileData;

        getline(myFile, fileData);
        int ID = stoi(fileData);

        getline(myFile, fileData);
        string name = fileData;

        getline(myFile, fileData);
        string level = fileData;

        getline(myFile, fileData);
        string department = fileData;


        getline(myFile, fileData);
        int numAdvisees = stoi(fileData);

        DoublyLinkedList<int> *facAdvisees = new DoublyLinkedList<int>();

        for(int x = 0; x < numAdvisees; ++x)
        {
            getline(myFile, fileData);
            int advisee = stoi(fileData);
            facAdvisees->insertFront(advisee);
        }


        getline(myFile, fileData);//space between data

        Person *newFac = new Person(ID, name, department, level, facAdvisees);

        treeFromFile->insert(newFac->getId(), newFac);

    }

    myFile.close();

    return *treeFromFile;

}//end getStudData

//     ___          __               __
//    / _ \___ ___ / /_______ ______/ /____  ____
//   / // / -_|_-</ __/ __/ // / __/ __/ _ \/ __/
//  /____/\__/___/\__/_/  \_,_/\__/\__/\___/_/
//   Destructor

//destructor
FileManager::~FileManager()
{
    //variables are deleted automatically, so we're good
}
