#include "BST.cpp"


class FileManager
{
    private:
        string studDataFile;
        string facDataFile;

    public:
        FileManager(); //default constructor
        FileManager(string studData, string facData);


        void saveStudFile(DoublyLinkedList<Person> treeToSave);
        void saveFacFile(DoublyLinkedList<Person> treeToSave);

        BST<Person> getStudData();
        BST<Person> getFacData();

      ~FileManager();
};