

class FileManager
{
    private:
        string studDataFile;
        string facDataFile;

    public:
        FileManager(); //default constructor
        FileManager(string studData, string facData);
        void updateStudFile(BST treeToSave);
        void updateFacFile(BST treeToSave);

      ~FileManager();
};