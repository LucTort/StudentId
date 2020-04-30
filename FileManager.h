

class FileManager
{
    private:
        int studDataFile;
        int remainingTicksNeeded;
        int tickToArrive;
        int assignedWindow;

    public:
        Stud(); //default constructor
        Stud(int timeGetInLine, int timeNeeded);
        void decreaseRemainingTicksNeeded();
        int getRemainingTicksNeeded();
        int getTickToArrive();
        int getStartingTicksNeeded();
        void assignWindow(int window);
        int getAssignedWindow();

      ~Stud();
};