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

void FileManager::updateStudFile(BST treeToSave)
{
    //put stuff here
}

void FileManager::updateFacFile(BST treeToSave)
{
    //put stuff here
}

FileManager::~FileManager()
{
    
}