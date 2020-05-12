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

FileManager::FileManager()
{
    studDataFile = "studData.txt";
    facDataFile = "facData.txt";

    const char *facDataFileTest = "facData.txt";
    const char *studDataFileTest = "studData.txt";


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

void FileManager::saveFacFile(DoublyLinkedList<Person*> facNodes)
{
    ofstream myFile;
    myFile.open(facDataFile, std::ofstream::out | std::ofstream::trunc);

    Person *currentFac = new Person();
    // cout << "Its size: "<<facNodes.getSize() << endl;  //puts number of faculty at top of file
    myFile << facNodes.getSize() << endl;  //puts number of students at top of file
    while (facNodes.getSize() > 0)
    {
        // cout <<"YEEEEEEEEEEEEEEEEEEEEEEEEEEE" << endl << endl;
        currentFac = facNodes.removeFront();

        myFile << currentFac->getId() << endl;
        myFile << currentFac->getName() << endl;
        myFile << currentFac->getLevel() << endl;
        myFile << currentFac->getDepartment() << endl;

        DoublyLinkedList<int> *advisees = new DoublyLinkedList<int>();
        advisees = currentFac->getAdvisees();
        int currentAdvisee = 0;
        // bool needEndl = false;

        cout << "Here is the size: " <<advisees->getSize() << endl;

        myFile << advisees->getSize() << endl;

        // cout << advisees->getSize() << endl;

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
    // int numDataPoints = (int) stringDataPoints;
    int numDataPoints = stoi(stringDataPoints);


    for(int x = 0; x < numDataPoints; x++)
    {
        string fileData;

        getline(myFile, fileData);
        // cout << "ID: " <<fileData << endl;
        int ID = stoi(fileData);

        getline(myFile, fileData);
        // cout << "Name: " <<fileData << endl;
        string name = fileData;

        getline(myFile, fileData);
        // cout << "Standing: " <<fileData << endl;
        string standing = fileData;

        getline(myFile, fileData);
        // cout << "GPA: " <<fileData << endl;
        double GPA = stod(fileData);

        getline(myFile, fileData);
        // cout << "Major: " <<fileData << endl;
        string major = fileData;

        getline(myFile, fileData);
        // cout << "Advisor: " <<fileData << endl;
        int advisor = stoi(fileData);

        getline(myFile, fileData);//space between data
        // cout << "No data: " <<fileData << endl;

        Person *newStud = new Person(ID, name, standing, major, GPA, advisor);

        treeFromFile->insert(newStud->getId(), newStud);

    }

    // treeFromFile->printTree(treeFromFile->getRoot());


    myFile.close();

    return *treeFromFile;

}//end getStudData


BST<Person*> FileManager::getFacData()
{
    ifstream myFile;
    myFile.open(facDataFile);
    if (!myFile.is_open()) //makes sure file opens correctly
    {
        cout << "File didn't open properly" << endl;
    }

    // cout<< "Reading from fileeeeeeeeeeeeeeeeeeeeeeeeeeeeeee" << endl;

    BST<Person*> *treeFromFile = new BST<Person*>();

    string stringDataPoints;
    getline(myFile, stringDataPoints);
    // int numDataPoints = (int) stringDataPoints;
    int numDataPoints = stoi(stringDataPoints);

    // cout<< "Reading from fileeeeeeeeeeeeeeeeeeeeeeeeeeeeeee" << stringDataPoints << endl;

    for(int x = 0; x < numDataPoints; ++x)
    {
    // cout<< "Reading from fileeeeeeeeeeeeeeeeeeeeeeeeeeeeeee" << endl;

        string fileData;

        getline(myFile, fileData);
        // cout << "ID: " << fileData << endl;
        int ID = stoi(fileData);

        getline(myFile, fileData);
        // cout << "Name: " << fileData << endl;
        string name = fileData;

        getline(myFile, fileData);
        // cout << "Level: " << fileData << endl;
        string level = fileData;

        getline(myFile, fileData);
        // cout << "Department: " << fileData << endl;
        string department = fileData;


        getline(myFile, fileData);
        // cout << fileData << endl;
        int numAdvisees = stoi(fileData);

        DoublyLinkedList<int> *facAdvisees = new DoublyLinkedList<int>();

        for(int x = 0; x < numAdvisees; ++x)
        {
            getline(myFile, fileData);
            // cout << fileData << endl;
            int advisee = stoi(fileData);
            facAdvisees->insertFront(advisee);
        }


        getline(myFile, fileData);//space between data

        Person *newFac = new Person(ID, name, department, level, facAdvisees);

        treeFromFile->insert(newFac->getId(), newFac);

    }

    // treeFromFile->printTree(treeFromFile->getRoot());


    myFile.close();

    return *treeFromFile;

}//end getStudData

//     ___          __               __
//    / _ \___ ___ / /_______ ______/ /____  ____
//   / // / -_|_-</ __/ __/ // / __/ __/ _ \/ __/
//  /____/\__/___/\__/_/  \_,_/\__/\__/\___/_/
//   Destructor

FileManager::~FileManager()
{

}
