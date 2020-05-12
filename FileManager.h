#include "BST.cpp"
#include <unistd.h>


//used to save to and load from files
class FileManager
{
    private:
        string studDataFile;
        string facDataFile;

    public:
        FileManager(); //default constructor
        FileManager(string studData, string facData);   //overloaded constructor

    //saving to a file
        void saveStudFile(DoublyLinkedList<Person*> treeToSave);
        void saveFacFile(DoublyLinkedList<Person*> treeToSave);

    //getting data from file
        BST<Person*> getStudData();
        BST<Person*> getFacData();

    //destructor
      ~FileManager();
};