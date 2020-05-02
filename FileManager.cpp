//uses code from assignment 4
#include "FileManager.h"

FileManager::FileManager()
{
    studDataFile = "studData";
    facDataFile = "facData";
}

FileManager::FileManager(string studData, string facData)
{
    studDataFile = studData;
    facDataFile = facData;
}

void FileManager::saveStudFile(LinkedList studNodes)
{
    ofstream saveFile;  //https://www.cplusplus.com/reference/fstream/fstream/open/

    saveFile.open(studDataFile, std::trunc);   //opens file, truncating current data in file

    if (!saveFile.is_open()) //makes sure file opens correctly
        {
            cout << "Error: Couldn't create save file" << endl;
            return 1;
        }

    TreeNode studTreeNode = studNodes->removeFront();

    Person currentStud = studTreeNode->getData();

    string str = "";

    str << currentStud.getId() << "+" << currentStud.getName() << "+" << currentStud.getGPA() << "+" << currentStud.getStanding();

    saveFile << str << "\n";

    saveFile.close();
}

void FileManager::saveFacFile(LinkedList facNodes)
{
    //put stuff here
}

FileManager::~FileManager()
{
    
}