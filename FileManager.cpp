//uses code from assignment 4
//https://stackoverflow.com/questions/17032970/clear-data-inside-text-file-in-c
//Uses code from assignment 1
//https://stackoverflow.com/questions/7663709/how-can-i-convert-a-stdstring-to-int
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

void FileManager::saveStudFile(DoublyLinkedList<Person> studNodes)
{
    ofstream myFile;
    myFile.open(studDataFile, std::ofstream::out | std::ofstream::trunc);

     Person *currentStud = new Person();

    myFile << studNodes.getSize() << endl;

    while (studNodes.getSize() > 0)
    {

        *currentStud = studNodes.removeFront();

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

void FileManager::saveFacFile(DoublyLinkedList<Person> facNodes)
{
    ofstream myFile;
    myFile.open(facDataFile, std::ofstream::out | std::ofstream::trunc);

     Person *currentFac = new Person();

    while (facNodes.getSize() > 0)
    {

        *currentFac = facNodes.removeFront();

        myFile << currentFac->getId() << endl;
        myFile << currentFac->getName() << endl;
        myFile << currentFac->getLevel() << endl;
        myFile << "Test" << endl;
        myFile << currentFac->getDepartment() << endl;

        DoublyLinkedList<int> *advisees = new DoublyLinkedList<int>();
        advisees = currentFac->getAdvisees();
        int currentAdvisee = 0;
        bool needEndl = false;

        myFile << facNodes.getSize() << endl;

        while(advisees->getSize() > 0)
        {
            currentAdvisee = advisees->removeFront();
            myFile << currentAdvisee << ",";
            needEndl = true;
        }
        
        if (needEndl) {myFile << endl;}
        myFile << endl;
    }

    myFile.close();
}

//     __                __  ____              __  _             
//    / /  ___  ___ ____/ / / __/_ _____  ____/ /_(_)__  ___  ___
//   / /__/ _ \/ _ `/ _  / / _// // / _ \/ __/ __/ / _ \/ _ \(_-<
//  /____/\___/\_,_/\_,_/ /_/  \_,_/_//_/\__/\__/_/\___/_//_/___/
//  Load Functions
BST<Person> FileManager::getStudData()
{
    ifstream myFile;
    myFile.open(studDataFile);
    if (!myFile.is_open()) //makes sure file opens correctly
    {
        cout << "File didn't open properly" << endl;
    }

    BST<Person> *treeFromFile = new BST<Person>();

    string stringDataPoints;
    getline(myFile, stringDataPoints);
    // int numDataPoints = (int) stringDataPoints;
    int numDataPoints = stoi(stringDataPoints);
    

    for(int x = 0; x < numDataPoints; x++)
    {
        string fileData;

        getline(myFile, fileData);
        cout << fileData << endl;
        int ID = stoi(fileData);

        getline(myFile, fileData);
        cout << fileData << endl;
        string name = fileData;

        getline(myFile, fileData);
        cout << fileData << endl;
        string standing = fileData;

        getline(myFile, fileData);
        cout << fileData << endl;
        double GPA = stod(fileData);

        getline(myFile, fileData);
        cout << fileData << endl;
        string major = fileData;

        getline(myFile, fileData);
        cout << fileData << endl;
        int advisor = stoi(fileData);

        getline(myFile, fileData);//space between data
        cout << fileData << endl;

        Person *newStud = new Person(ID, name, standing, major, GPA, advisor);

        treeFromFile->insert(newStud->getId(), *newStud);

    }

    treeFromFile->printTree(treeFromFile->getRoot());
    

    myFile.close();

}//end getStudData

//     ___          __               __          
//    / _ \___ ___ / /_______ ______/ /____  ____
//   / // / -_|_-</ __/ __/ // / __/ __/ _ \/ __/
//  /____/\__/___/\__/_/  \_,_/\__/\__/\___/_/   
//   Destructor

FileManager::~FileManager()
{
    
}