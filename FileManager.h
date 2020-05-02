

class FileManager
{
    private:
        string studDataFile;
        string facDataFile;

    public:
        FileManager(); //default constructor
        FileManager(string studData, string facData);
        void saveStudFile(BST treeToSave);
        void saveFacFile(BST treeToSave);

        BST getStudData();
        BST getFacData();

      ~FileManager();
};