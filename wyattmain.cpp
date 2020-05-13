//https://www.tutorialspoint.com/cplusplus/cpp_switch_statement.htm
//https://stackoverflow.com/questions/5655142/how-to-check-if-input-is-numeric-in-c

#include "CatInHat.cpp"


//printing out all of the options
void printOptions(){

  cout << "\nWhat would you like to do?\n"<<endl;
  cout << "1) Print all students and their information (sorted by ascending id #)" << endl;
  cout << "2) Print all faculty and their information (sorted by ascending id #)" << endl;
  cout << "3) Find and display student information given the students id " << endl;
  cout << "4) Find and display faculty information given the faculty id " << endl;
  cout << "5) Given a student’s id, print the name and info of their faculty advisor " << endl;
  cout << "6) Given a faculty id, print ALL the names and info of his/her advisees. " << endl;
  cout << "7) Add a new student " << endl;
  cout << "8) Delete a student given the id " << endl;
  cout << "9) Add a new faculty member " << endl;
  cout << "10) Delete a faculty member given the id. " << endl;
  cout << "11) Change a student’s advisor given the student id and the new faculty id. " << endl;
  cout << "12) Remove an advisee from a faculty member given the ids " << endl;
  cout << "13) Rollback " << endl;
  cout << "14) Exit" << endl;
  cout << "---Extras---" << endl;
  cout << "15) Cat in the Hat " << endl;
  cout << "16) Given a student id, change their GPA" << endl;
  cout << "17) Given a student id, change their major" << endl;
  cout << "18) Given a student id, change their standing" << endl;
  cout << "19) Given a faculty id, change their level" << endl;
  cout << "20) Given a faculty id, change their department" << endl;
  cout << "21) Given a student id, change their name" << endl;
  cout << "22) Given a faculty id, change their name" << endl;
}

int main(){


    FileManager *myFileManager = new FileManager();


    CatInHat *cat = new CatInHat();


//      ______            __    __        _______ __
//     / ____/___  ____ _/ /_  / /__     / ____(_) /__  _____
//    / __/ / __ \/ __ `/ __ \/ / _ \   / /_  / / / _ \/ ___/
//   / /___/ / / / /_/ / /_/ / /  __/  / __/ / / /  __(__  )
//  /_____/_/ /_/\__,_/_.___/_/\___/  /_/   /_/_/\___/____/
//

int filesEnabled = true;

//    ______          __     _____ __            __   ______
//   /_  __/__  _____/ /_   / ___// /___  ______/ /  /_  __/_______  ___
//    / / / _ \/ ___/ __/   \__ \/ __/ / / / __  /    / / / ___/ _ \/ _ \
//   / / /  __(__  ) /_    ___/ / /_/ /_/ / /_/ /    / / / /  /  __/  __/
//  /_/  \___/____/\__/   /____/\__/\__,_/\__,_/    /_/ /_/   \___/\___/
//

  int idInput = 0;
  int facIdInput = 0;
  int trueCheck = -1;
  int studInput1 = 0;
  int facGetter = 0;

  BST<Person*> *w = new BST<Person*>();
  BST<Person*> *fac = new BST<Person*>();

  DoublyLinkedList<DoublyLinkedList<Person*>> *prevStudTrees = new DoublyLinkedList<DoublyLinkedList<Person*>>();
  DoublyLinkedList<DoublyLinkedList<Person*>> *prevFacTrees = new DoublyLinkedList<DoublyLinkedList<Person*>>();




//     __                __  ____                 _____ __
//    / /  ___  ___ ____/ / / __/______  __ _    / __(_) /__
//   / /__/ _ \/ _ `/ _  / / _// __/ _ \/  ' \  / _// / / -_)
//  /____/\___/\_,_/\_,_/ /_/ /_/  \___/_/_/_/ /_/ /_/_/\__/
//

  if(filesEnabled)
  {
    *w = myFileManager->getStudData();
    *fac = myFileManager->getFacData();
  }

  w->printTree(w->getRoot());
  fac->printTree(fac->getRoot());

  // w->printStudent();

  if(!filesEnabled)
  {
      DoublyLinkedList<int> *adv1 = new DoublyLinkedList<int>();
      DoublyLinkedList<int> *adv2 = new DoublyLinkedList<int>();
      DoublyLinkedList<int> *adv3 = new DoublyLinkedList<int>();



//creating people
      Person *rosie = new Person();
      rosie->setId(35);
      rosie->setGPA(3.8);
      rosie->setMajor("Accounting");
      rosie->setStanding("Senior");
      rosie->setName("Rosie O Donald");
      rosie->setAdvisor(50);

      Person *frank = new Person();
      frank->setId(30);
      frank->setGPA(1.2);
      frank->setMajor("CompSci");
      frank->setStanding("Junior");
      frank->setName("Frank Azark");
      frank->setAdvisor(20);

      Person *bob = new Person();
      bob->setId(40);
      bob->setGPA(3.29);
      bob->setMajor("Finance");
      bob->setStanding("Senior");
      bob->setName("Bob Miller");
      bob->setAdvisor(70);

    // for every faculty memeber a doubly linked list must be created
      Person *lucas = new Person();
      lucas->setId(50);
      lucas->setName("Lucas Torti");
      lucas->setLevel("Lecturer");//Lecturer, assistant professor, associate professor
      lucas->setDepartment("Keck Center");
      adv1->insertBack(35);
      lucas->setAdvisees(adv1);//starting to delimeter and then create a new doubly linked list and add everything in between, pass in doubly linked list to set advisee

      Person *wyatt = new Person();
      wyatt->setId(20);
      wyatt->setName("wyatt miller");
      wyatt->setLevel("professor");//Lecturer, assistant professor, associate professor
      wyatt->setDepartment("Argyros");
      adv2->insertBack(30);
      wyatt->setAdvisees(adv2);

      Person *chris = new Person();
      chris->setId(70);
      chris->setName("chris change");
      chris->setLevel("assistant professor");//Lecturer, assistant professor, associate professor
      chris->setDepartment("dance school");
      adv3->insertBack(40);
      chris->setAdvisees(adv3);

//inserting them into their respective trees
      w->insert(frank->getId(), frank);

      w->insert(rosie->getId(), rosie);

      w->insert(bob->getId(), bob);

      fac->insert(lucas->getId(), lucas);

      fac->insert(wyatt->getId(), wyatt);

      fac->insert(chris->getId(), chris);
  }

  int option = 0;


// the big while loop
  while(option != 14)
  {

    printOptions();

    cin >> option;    //https://stackoverflow.com/questions/5655142/how-to-check-if-input-is-numeric-in-c
    while(!cin) // or if(cin.fail())
    {
        cout << "Invalid input. Please try again" << endl;
        // user didn't input a number
        cin.clear(); // reset failbit
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
        // next, request user reinput
    }
    


//option 1
    if (option == 1){
      // WORKNG PRINT STUDENT ASCENDING
      w->printTree(w->getRoot());
      w->printStudent(w->getRoot());

      // rollbackStud->insertStack(*w);
    }
  //option 2
    if (option == 2){
      //PRINT FACULTY ASCENDING
      fac->printTree(fac->getRoot());
      fac->printFac(fac->getRoot());
    }

//option 3
    if (option == 3){
      //getting the input
      cout << "Enter the ID that you would like to print the information "<< endl;
      cin >> idInput;

// checking to see if the input was actually in the tree
      trueCheck = w->search(idInput);

      //error checking to see if the student exists
      while (trueCheck == 0){
        cout << "That student does not exist, please enter one that does"<< endl;
        cout<< "Enter a student ID "<<endl;
        cin>> idInput;
        trueCheck = w->search(idInput);
      }
      //printing the student data
      if (trueCheck == 1){
        cout << " "<< endl;
        TreeNode<Person*> *person= new TreeNode<Person*>();
        Person *studPrinter = new Person();
        person = w->searchNode(idInput);

        studPrinter = person->getNodeData();

        studPrinter->printStudData();
      }else{
        cout << "That ID does not exist please restart"<< endl;
      }
    }
    //option 4
    if (option == 4){
      cout << "Enter the ID that you would like to print the information "<< endl;
      cin >> facIdInput;
      //checking if id exists
      trueCheck = fac->search(facIdInput);
      //error checking to see if the fac exists
      while (trueCheck == 0){
        cout << "That faculty does not exist, please enter one that does"<< endl;
        cout<< "Enter a faculty ID "<<endl;
        cin>> facIdInput;
        trueCheck = fac->search(facIdInput);
      }
      //printing the fac data
      if (trueCheck == 1){
        cout << " "<< endl;
        TreeNode<Person*> *facPerson= new TreeNode<Person*>();
        Person *facPrinter = new Person();
        facPerson = fac->searchNode(facIdInput);

        facPrinter = facPerson->getNodeData();

        facPrinter->printFacData();
      }else {
        cout << "That ID does not exist please restart"<< endl;
      }
    }
    //option 5
    if (option == 5){
      //getting the input
      cout << "Enter the ID of the students "<< endl;
      cin >> studInput1;
      //searching the tree
      trueCheck = w->search(studInput1);
      //error checking to see if the stud exists
      while (trueCheck == 0){
        cout << "That student does not exist, please enter one that does"<< endl;
        cout<< "Enter a student ID "<<endl;
        cin>> studInput1;
        trueCheck = w->search(studInput1);
      }
      //getting the advisor of the student
      if (trueCheck == 1){
        cout << " "<< endl;
        TreeNode<Person*> *studPerson= new TreeNode<Person*>();
        Person *studGetFac = new Person();
        //putting the node into the tree node
        studPerson = w->searchNode(studInput1);
        //putting the tree node into Person
        studGetFac =studPerson->getNodeData();

        facGetter = studGetFac->getAdvisor();

        int trueCheck1= 0;

        trueCheck1 = fac->search(facGetter);
        //finding the students advisor in the fac tree and printing fac data
        if (trueCheck1 == 1){
          cout << " "<< endl;
          TreeNode<Person*> *facPerson= new TreeNode<Person*>();
          Person *facPrinter = new Person();
          facPerson = fac->searchNode(facGetter);

          facPrinter = facPerson->getNodeData();

          facPrinter->printFacData();

      }else{
        cout << "It has to exist, it better print, something is being modified" <<endl;
      }

    }else{
      cout << "That Id does not exist, please restart"<< endl;
    }
  }
  //option 6
  if (option == 6){
    int trueCheck2 = 0;
    int facIdInput1 = 0;
    int listSize = 0;
    int idRemoved = 0;
    //getting input
    cout << "Enter a faculty ID "<< endl;
    cin >> facIdInput1;
    //checking if id exists
    trueCheck2 = fac->search(facIdInput1);


    //error checking to see if the fac exists
    while (trueCheck2 == 0){
      cout << "That faculty does not exist, please enter one that does"<< endl;
      cout<< "Enter a faculty ID "<<endl;
      cin>> facIdInput1;
      trueCheck2 = fac->search(facIdInput1);
    }
    //getting all the advisees of that fac
    if (trueCheck2 == 1){
      cout << " "<< endl;
      TreeNode<Person*> *facPerson= new TreeNode<Person*>();
      Person *facPrinter = new Person();
      DoublyLinkedList <int> *advisee1 = new DoublyLinkedList<int>();
      facPerson = fac->searchNode(facIdInput1);

      facPrinter = facPerson->getNodeData();

      advisee1 = facPrinter->getAdvisees();

      cout << "\nHere are the advisees for that faculty "<< endl;

      advisee1->printList();

      listSize = advisee1->getSize();
      //iterating through all advisees and print all of them
      for (int i= 1; i<=listSize; ++i){
        //pull of the id from the doubly linked list, then print the information
        idRemoved = advisee1->removeBack();
        advisee1->insertFront(idRemoved);//might not be necessary

        int trueCheck3 = 0;
        trueCheck3 = w->search(idRemoved);
        if (trueCheck3 == 1){
          cout << " "<< endl;
          TreeNode<Person*> *person= new TreeNode<Person*>();
          Person *studPrinter = new Person();
          person = w->searchNode(idRemoved);

          studPrinter = person->getNodeData();

          studPrinter->printStudData();
        }else{
          cout << "This ID must exist, problem if we are in this else statement"<< endl;
        }
      }
    }else {
      cout << "That ID does not exist please restart"<< endl;
    }

  }
  //option 7
  if (option == 7){

    prevStudTrees->insertFront(w->getListOfNodes());
    prevFacTrees->insertFront(fac->getListOfNodes());

    string name1 = "";
    double gpa1 = 0;
    int id1 = 0;
    string major1= "";
    string standing1 = "";
    int advisor1 = 0;
    string gpaType = "";
    string idType = "";

  //getting all the required info
    cout<< "Please enter information for the following fields "<< endl;
    cout<< "Name? "<< endl;
    //https://stackoverflow.com/questions/5838711/stdcin-input-with-spaces
    std::getline(std::cin >> std::ws, name1);
    cout<< "ID? (Must be an integer)"<< endl;
    cin>>id1;
    cout<< "GPA? (Must be integer or float)"<< endl;
    cin>>gpa1;
    cout<< "Major? "<< endl;
    std::getline(std::cin >> std::ws, major1);
    cout<< "Standing? "<< endl;
    cin>>standing1;
    cout<< "Advisor? "<< endl;
    cin>> advisor1;

    //searching to see if the advisor exists

    int trueCheck1= 0;
    string answer1 = "";
    trueCheck1 = fac->search(advisor1);

    // error checking to see if advisor exists and giving the option to continue regardless

    while (trueCheck1 == 0){
      cout << "That advisor does not exist, would you like to continue anyway? (yes/no)"<< endl;
      cin>> answer1;
      if (answer1 == "yes"){
        break;
      }
      cout<< "Advisor? "<<endl;
      cin>> advisor1;
      trueCheck1 = fac->search(advisor1);
    }
    //setting the values
    Person *renee = new Person();
    renee->setId(id1);
    renee->setGPA(gpa1);
    renee->setMajor(major1);
    renee->setStanding(standing1);
    renee->setName(name1);
    renee->setAdvisor(advisor1);
//inserting the values in the tree
    w->insert(renee->getId(), renee);

    cout << "\nYou added this new student"<< endl;
  //printing the new student
    int trueCheck2 = 0;
    trueCheck2 = w->search(id1);
    //searching for this student in the tree and printing their data
    if (trueCheck2 == 1){
      cout << " "<< endl;
      TreeNode<Person*> *person= new TreeNode<Person*>();
      Person *studPrinter = new Person();
      person = w->searchNode(id1);

      studPrinter = person->getNodeData();

      studPrinter->printStudData();
    }else{
      cout << "This ID does not exist"<< endl;
    }
  }
  if (option == 8){
    //rollback functionality
    prevStudTrees->insertFront(w->getListOfNodes());
    prevFacTrees->insertFront(fac->getListOfNodes());

    int trueCheck2 = 0;
    int idInput1 = 0;
    int trueCheck3 = 0;
    int getTheFac =0;
    //getting input
    cout << "Enter the ID of the student that you would like to delete "<< endl;
    cin >> idInput1;

    //search tree
    trueCheck2 = w->search(idInput1);
    //error checking to see if the fac exists
    while (trueCheck2 == 0){
      cout << "That student does not exist, please enter one that does"<< endl;
      cout<< "Enter a Student ID "<<endl;
      cin>> idInput1;
      trueCheck2 = w->search(idInput1);
    }
    //deleting them out of the tree
    if (trueCheck2 == 1){
      cout << " "<< endl;
      TreeNode<Person*> *person= new TreeNode<Person*>();
      Person *studPrinter = new Person();

      cout << "Tree Before Deletion "<< endl;

      w->printTree(w->getRoot());

      person = w->searchNode(idInput1);

      studPrinter =person->getNodeData();

      //getting their fac memeber befroe the deletion so we can delete the student out of advisees

      getTheFac = studPrinter->getAdvisor();

      cout << "Here is their faculty member: "<< getTheFac << endl;

      //deleting the student once I have their advisor

      w->deleteNode(idInput1);

      cout << "Tree After Deletion "<< endl;

      w->printTree(w->getRoot());

      //have the advisor, now going to delete the student out of the advisees

      int trueCheck4 = 0;
      trueCheck4 = fac->search(getTheFac);
      if (trueCheck4 == 1){
        cout << " "<<endl;
        TreeNode<Person*> *facPerson= new TreeNode<Person*>();
        Person *facPrinter = new Person();
        DoublyLinkedList <int> *advisee1 = new DoublyLinkedList<int>();
        int idremoved1= 0;
        int listSize1 = 0;

        facPerson = fac->searchNode(getTheFac);

        facPrinter = facPerson->getNodeData();

        cout << "faculty data before advisee was deleted"<<endl;

        facPrinter->printFacData();

        advisee1 = facPrinter->getAdvisees();

        listSize1 = advisee1->getSize();
        //iterating through all advisees to find the right student to take out
        for (int i = 1; i<=listSize1; ++i){
          cout << "Ye";
          idremoved1=advisee1->removeBack();
          cout << "eh" << endl;
          if (idremoved1 != idInput1){
            advisee1->insertFront(idremoved1);
          }
        }
        facPrinter->setAdvisees(advisee1);

        cout << "faculty data after advisee was deleted"<<endl;

        facPrinter->printFacData();
      }


    }else{
      cout << "That ID does not exist please restart 2 "<< endl;
    }

  }
//option 9
  if (option==9){
//rollback
    prevStudTrees->insertFront(w->getListOfNodes());
    prevFacTrees->insertFront(fac->getListOfNodes());

    string name1 = "";
    string level1 = "";
    int id11 = 0;
    string department1= "";
    int advisee0=0;
    string answer = "";
    DoublyLinkedList<int> *advisee11 = new DoublyLinkedList<int>();

//getting the required fields
    cout<< "Please enter information for the following fields "<< endl;
    cout<< "Name? "<< endl;
    std::getline(std::cin >> std::ws, name1);
    cout<< "ID? (Must be an integer)"<< endl;
    cin>>id11;
    cout<< "Level? "<< endl;
    std::getline(std::cin >> std::ws, level1);
    cout<< "Department? "<< endl;
    std::getline(std::cin >> std::ws, department1);

    //while loop so they can add as many advisees as they would like

    while (answer != "no" || answer != "n" || answer != "No"||answer != "NO"){
      int advisee0=0;
      cout<< "Enter an advisee ID "<< endl;
      cin>> advisee0;


      int trueCheck1= 0;
      string answer1 = "";
      trueCheck1 = w->search(advisee0);

      //error checking to see if advisee exists

      while (trueCheck1 == 0){
        cout << "That student does not exist, would you like to continue anyway?"<< endl;
        cin>> answer1;
        if (answer1 == "yes" || answer1 == "y" || answer1 == "Yes"){
          break;
        }
        cout<< "Enter an advisee ID "<<endl;
        cin>> advisee0;
        trueCheck1 = w->search(advisee0);
      }
      //while loop breaker
      advisee11->insertBack(advisee0);
      cout << "Would you like to enter another advisee? (yes/no)"<< endl;
      cin>> answer;
      if (answer == "no" ||answer == "n"|| answer == "No" || answer == "NO"){
        break;
      }
    }
    advisee11->printList();
//creating new person
    Person *m = new Person();
    m->setId(id11);
    m->setDepartment(department1);
    m->setLevel(level1);
    m->setName(name1);
    m->setAdvisees(advisee11);
//inserting them in the fac
    fac->insert(m->getId(),m);

    cout << "\nYou added this new faculty member"<<endl;

    int trueCheck2 = 0;
    trueCheck2 = fac->search(id11);
    if (trueCheck2 == 1){
      cout << " "<< endl;
      TreeNode<Person*> *facPerson= new TreeNode<Person*>();
      Person *facPrinter = new Person();
      facPerson = fac->searchNode(id11);
      facPrinter = facPerson->getNodeData();
      facPrinter->printFacData();
    }else {
      cout << "That ID does not exist please restart"<< endl;
    }

    //FROM HERE GO INTO STUDENT AND CHANGE WHO THEY ARE BEING ADVISED BY?

  }

  if (option == 10){

//rollback
    prevStudTrees->insertFront(w->getListOfNodes());
    prevFacTrees->insertFront(fac->getListOfNodes());

    int trueCheck2 = 0;
    int idInput1 = 0;
    int trueCheck3 = 0;
    DoublyLinkedList<int> *getTheFac = new DoublyLinkedList<int>();
    //geting input
    cout << "Enter the ID of the faculty that you would like to delete "<< endl;
    cin >> idInput1;

    trueCheck2 = fac->search(idInput1);

    //error checking to see if the fac exists
    while (trueCheck2 == 0){
      cout << "That faculty does not exist, please enter one that does"<< endl;
      cout<< "Enter a faculty ID "<<endl;
      cin>> idInput1;
      trueCheck2 = fac->search(idInput1);
    }
    // finding the fac member and deleting
    if (trueCheck2 == 1){
      cout << " "<< endl;
      TreeNode<Person*> *person= new TreeNode<Person*>();
      Person *studPrinter = new Person();

      cout << "Tree Before Deletion "<< endl;

      fac->printTree(fac->getRoot());

      person = fac->searchNode(idInput1);

      studPrinter =person->getNodeData();

      getTheFac = studPrinter->getAdvisees();

      //here we have all the id's of who the faculties advisees were, so we can delete this fac out of advisor

      //deleting the faculty once I have their advisees

      fac->deleteNode(idInput1);//come back

      cout << "Tree After Deletion "<< endl;

      fac->printTree(fac->getRoot());

      cout << "Here is their students" << endl;
      getTheFac->printList();

      //now that we have the advisees we have to go into the students and delete their faculty advisor
      int doublyPuller = 0;
      int advSize=0;
      advSize=getTheFac->getSize();

      //going through all advisees and changing their advisor

      for (int i=1;i<=advSize;++i){
        int trueCheck4 = 0;
        doublyPuller = getTheFac->removeFront();
        trueCheck4 = w->search(doublyPuller);
        if (trueCheck4 ==1){
          cout << " "<< endl;
          TreeNode<Person*> *person= new TreeNode<Person*>();
          Person *studPrinter = new Person();
          person = w->searchNode(doublyPuller);

          studPrinter = person->getNodeData();

          if (studPrinter->getAdvisor()==idInput1){
            studPrinter->setAdvisor(0);
          }
          studPrinter->printStudData();
        }else{
          cout << "This student wasnt found for some odd reason"<< endl;
        }
      }
    }
  }
//     ______
//    <  <  /
//    / // / 
//   / // /  
//  /_//_/   
//           
//option 11
  if (option == 11){//come back

    prevStudTrees->insertFront(w->getListOfNodes());
    prevFacTrees->insertFront(fac->getListOfNodes());

    int studId0 = 0;
    int facID = 0;
    cout << "Please enter the Students ID that you would like to modify"<< endl;
    cin >> studId0;

    int trueCheck1= 0;
    trueCheck1 = w->search(studId0);
    //error checking to see if the student exists
    while (trueCheck1 == 0){
      cout << "That student does not exist, please enter one that does"<< endl;//gets student id
      cout<< "Enter a student ID "<<endl;
      cin>> studId0;
      trueCheck1 = w->search(studId0);
    }

    cout << "Enter the new faculty ID"<< endl;//gets faculty id
    cin >> facID;

    int trueCheck2= 0;
    trueCheck2 = fac->search(facID);
    //error checking to see if the fac exists
    while (trueCheck2 == 0){
      cout << "That faculty does not exist, please enter one that does"<< endl;
      cout<< "Enter a faculty ID "<<endl;
      cin>> facID;
      trueCheck2 = fac->search(facID);
    }

    //from here I must go into the student and change the advisor

    cout << " "<< endl;
    TreeNode<Person*> *person= new TreeNode<Person*>();//sets up for changing advisee
    Person *studPrinter = new Person();
    person = w->searchNode(studId0);

    studPrinter = person->getNodeData();

    cout << "\nStudents data before the change"<< endl;
    studPrinter->printStudData();
    int oldAdviseeNum = studPrinter->getAdvisor();

    studPrinter->setAdvisor(facID);

    cout << "\nStudents data after the change"<< endl;
    studPrinter->printStudData();

    //and go into the faculty and change the student

    cout << " "<< endl;
    TreeNode<Person*> *facPerson = new TreeNode<Person*>();
    Person *facPrinter = new Person();
    DoublyLinkedList <int> *modAdv = new DoublyLinkedList<int>();
    facPerson = fac->searchNode(facID);

    facPrinter = facPerson->getNodeData();

    cout << "\nFaculty data before the change"<< endl;
    facPrinter->printFacData();

    modAdv = facPrinter->getAdvisees();

    cout << "\nA list of the current advisees of this faculty member"<< endl;

    modAdv->printList();

    modAdv->insertBack(studId0);

    facPrinter->setAdvisees(modAdv);

    cout << "\nFaculty data after the change"<< endl;
    facPrinter->printFacData();

          //go to old advisee and remove the student
    // facPerson = fac->searchNode(oldAdviseeNum);
    // facPrinter = facPerson->getNodeData();
    // DoublyLinkedList <int> *advisees = new DoublyLinkedList<int>();
    // advisees = facPrinter->getAdvisees();
    // advisees->remove(oldAdviseeNum);
    // facPrinter->setAdvisees(advisees);
    // fac->deleteNode(oldAdviseeNum);
    // fac->insert(oldAdviseeNum, facPrinter);

  }
  
  if (option == 12){
    prevStudTrees->insertFront(w->getListOfNodes());
    prevFacTrees->insertFront(fac->getListOfNodes());

    int studId0 = 0;
    int facID = 0;
//input
    cout << "Enter the faculty ID you wish to modify"<< endl;
    cin >> facID;

    int trueCheck2= 0;
    trueCheck2 = fac->search(facID);
    //error checking to see if the fac exists
    while (trueCheck2 == 0){
      cout << "That faculty does not exist, please enter one that does"<< endl;
      cout<< "Enter a faculty ID "<<endl;
      cin>> facID;
      trueCheck2 = fac->search(facID);
    }

    cout << " "<< endl;
    TreeNode<Person*> *facPerson= new TreeNode<Person*>();
    Person *facPrinter = new Person();
    DoublyLinkedList <int> *modAdv = new DoublyLinkedList<int>();
    int sizeOf = 0;
    int idremoved1 =0;
    facPerson = fac->searchNode(facID);

    facPrinter = facPerson->getNodeData();

    modAdv = facPrinter->getAdvisees();

    cout << "\nA list of the current advisees of this faculty member"<< endl;

    modAdv->printList();

    //Student portion, checking if the student the entered is one of their advisees

    cout << "\nEnter the advisees ID that you would like to remove"<< endl;
    cin >> studId0;

    int trueCheck1= 0;
    trueCheck1 = modAdv->search(studId0);
    //error checking to see if the student exists
    while (trueCheck1 == 0 && !(modAdv->isEmpty())){
      cout << "That advisee is not one of this faculties advisees"<< endl;
      cout<< "Enter a valid advisee ID "<<endl;
      cin>> studId0;
      trueCheck1 = modAdv->search(studId0);
    }

    if (modAdv->isEmpty())
    {
      cout << endl <<"Oop, it looks like that faculty doesn't have any advisees." << endl << endl;
    } 
    else{

      cout << "\nFaculty data before the change"<< endl;
      facPrinter->printFacData();

      sizeOf = modAdv->getSize();

      //removing the student if that student equals the input otherwise inserting him back into the doubly, to later renew the doubly link list and reinsert

      for (int i = 1; i<=sizeOf; ++i){
        idremoved1=modAdv->removeBack();
        if (idremoved1 != studId0){
          modAdv->insertFront(idremoved1);
        }
      }

      facPrinter->setAdvisees(modAdv);

      cout << "\nFaculty data after the change"<< endl;
      facPrinter->printFacData();



      //from here I must go into the student and change the advisor

      cout << " "<< endl;
      TreeNode<Person*> *person= new TreeNode<Person*>();
      Person *studPrinter = new Person();
      person = w->searchNode(studId0);

      studPrinter = person->getNodeData();

      cout << "\nStudents data before the change"<< endl;
      studPrinter->printStudData();

      studPrinter->setAdvisor(0);

      cout << "\nStudents data after the change"<< endl;
      studPrinter->printStudData();
    }

  }

  //Roll back functionality
  if (option == 13){
    cout << "You have chosen the Rollback function "<< endl;

    DoublyLinkedList<Person*> *studLoad = new DoublyLinkedList<Person*>;
    DoublyLinkedList<Person*> *facLoad = new DoublyLinkedList<Person*>;

    *studLoad = prevStudTrees->removeFront();
    *facLoad = prevFacTrees->removeFront();

    if(!(prevStudTrees->isEmpty() || prevStudTrees->isEmpty()))
    {
      w->loadFromListOfNodes(studLoad);
      fac->loadFromListOfNodes(facLoad);
      cout << endl <<"Changes rolled back" << endl;
    }else 
    {
      cout << endl <<"No changes to roll back!" << endl;
    }


  }//end of rollback

  if (option == 15){
    cat->printCat();
  }

//     ________
//    <  / ___/
//    / / __ \ 
//   / / /_/ / 
//  /_/\____/  
//             

if (option == 16)
{
    int studId0 = 0;
    cout << "Please enter the ID of the student you would like to modify"<< endl;
    cin >> studId0;

    //error checking to see if the student exists
    while (!(w->search(studId0)))
    {
      cout << "That student does not exist, please enter one that does"<< endl;
      cout<< "Enter a student ID "<<endl;
      cin >> studId0;
    }

    cout << "Enter the new GPA"<< endl;
    double userChange = 0;
    cin >> userChange;

    //sets up objects to change the GPA
    TreeNode<Person*> *person= new TreeNode<Person*>();
    Person *studPrinter = new Person();
    person = w->searchNode(studId0);
    studPrinter = person->getNodeData();

    //prints data before changing it
    cout << "\nStudent's data before the change"<< endl;
    studPrinter->printStudData();

    //changes the data
    studPrinter->setGPA(userChange);

    //prints data after changing it
    cout << "\nStudent's data after the change"<< endl;
    studPrinter->printStudData();

    
}
//     ________
//    <  /__  /
//    / /  / / 
//   / /  / /  
//  /_/  /_/   
//             
if (option == 17)
{
    int studId0 = 0;
    cout << "Please enter the ID of the student you would like to modify"<< endl;
    cin >> studId0;

    //error checking to see if the student exists
    while (!(w->search(studId0)))
    {
      cout << "That student does not exist, please enter one that does"<< endl;
      cout<< "Enter a student ID "<<endl;
      cin >> studId0;
    }

    cout << "Enter the new major"<< endl;
    string userChange = "";
    cin >> userChange;

    //sets up objects to change the major
    TreeNode<Person*> *person= new TreeNode<Person*>();
    Person *studPrinter = new Person();
    person = w->searchNode(studId0);
    studPrinter = person->getNodeData();
    
    //prints data before changing it
    cout << "\nStudents data before the change"<< endl;
    studPrinter->printStudData();

    //actually changes it
    studPrinter->setMajor(userChange);

    //prints data after changing it
    cout << "\nStudents data after the change"<< endl;
    studPrinter->printStudData();

    
}
//     _______ 
//    <  ( __ )
//    / / __  |
//   / / /_/ / 
//  /_/\____/  
//             
if (option == 18)
{
    int studId0 = 0;
    cout << "Please enter the ID of the student you would like to modify"<< endl;
    cin >> studId0;

    //error checking to see if the student exists
    while (!(w->search(studId0)))
    {
      cout << "That student does not exist, please enter one that does"<< endl;
      cout<< "Enter a student ID "<<endl;
      cin >> studId0;
    }

    cout << "Enter the new standing"<< endl;
    string userChange = "";
    cin >> userChange;

    //sets up objects to change the standing
    TreeNode<Person*> *person= new TreeNode<Person*>();
    Person *studPrinter = new Person();
    person = w->searchNode(studId0);
    studPrinter = person->getNodeData();

    //prints data before changing it
    cout << "\nStudents data before the change"<< endl;
    studPrinter->printStudData();

    //actually changes it
    studPrinter->setStanding(userChange);

    //prints data after changing it
    cout << "\nStudents data after the change"<< endl;
    studPrinter->printStudData();

    
}
//     _______ 
//    <  / __ \
//    / / /_/ /
//   / /\__, / 
//  /_//____/  
//             
if (option == 19)
{
    int facId = 0;
    cout << "Please enter the ID of the faculty you would like to modify"<< endl;
    cin >> facId;

    //error checking to see if the student exists
    while (!(fac->search(facId)))
    {
      cout << "That faculty does not exist, please enter one that does"<< endl;
      cout<< "Enter a faculty ID "<<endl;
      cin >> facId;
    }

    cout << "Enter the new level"<< endl;
    string userChange = "";
    cin >> userChange;

    //sets up objects to change the standing
    TreeNode<Person*> *person= new TreeNode<Person*>();
    Person *facPrinter = new Person();
    person = fac->searchNode(facId);
    facPrinter = person->getNodeData();
    
    //prints data before changing it
    cout << "\nFaculty's data before the change"<< endl;
    facPrinter->printFacData();

    //actually changes it
    facPrinter->setLevel(userChange);

    //prints data after changing it
    cout << "\nFaculty's data after the change"<< endl;
    facPrinter->printFacData();

    
}
//     ___   ____ 
//    |__ \ / __ \
//    __/ // / / /
//   / __// /_/ / 
//  /____/\____/  
//                
if (option == 20)
{
    int facId = 0;
    cout << "Please enter the ID of the faculty you would like to modify"<< endl;
    cin >> facId;

    //error checking to see if the student exists
    while (!(fac->search(facId)))
    {
      cout << "That faculty does not exist, please enter one that does"<< endl;
      cout<< "Enter a faculty ID "<<endl;
      cin >> facId;
    }

    cout << "Enter the new department"<< endl;
    string userChange = "";
    cin >> userChange;

    //sets up objects to change the standing
    TreeNode<Person*> *person= new TreeNode<Person*>();
    Person *facPrinter = new Person();
    person = fac->searchNode(facId);
    facPrinter = person->getNodeData();
    
    //prints data before changing it
    cout << "\nFaculty's data before the change"<< endl;
    facPrinter->printFacData();

    //actually changes it
    facPrinter->setDepartment(userChange);

    //prints data after changing it
    cout << "\nFaculty's data after the change"<< endl;
    facPrinter->printFacData();

}//end option 20

if (option == 21)
{
    int studId = 0;
    cout << "Please enter the ID of the student you would like to modify"<< endl;
    cin >> studId;

    //error checking to see if the student exists
    while (!(w->search(studId)))
    {
      cout << "That student does not exist, please enter one that does"<< endl;
      cout<< "Enter a student ID "<<endl;
      cin >> studId;
    }

    cout << "Enter the new name"<< endl;
    string userChange = "";
    std::getline(std::cin >> std::ws, userChange);

    //sets up objects to change the standing
    TreeNode<Person*> *person= new TreeNode<Person*>();
    Person *studPrinter = new Person();
    person = w->searchNode(studId);
    studPrinter = person->getNodeData();
    
    //prints data before changing it
    cout << "\nStudent's data before the change"<< endl;
    studPrinter->printStudData();

    //actually changes it
    studPrinter->setName(userChange);

    //prints data after changing it
    cout << "\nStudent's data after the change"<< endl;
    studPrinter->printStudData();

}//end option 21

if (option == 22)
{
    int facId = 0;
    cout << "Please enter the ID of the faculty you would like to modify"<< endl;
    cin >> facId;

    //error checking to see if the student exists
    while (!(fac->search(facId)))
    {
      cout << "That faculty does not exist, please enter one that does"<< endl;
      cout<< "Enter a faculty ID "<<endl;
      cin >> facId;
    }

    cout << "Enter the new name"<< endl;
    string userChange = "";
    std::getline(std::cin >> std::ws, userChange);

    //sets up objects to change the standing
    TreeNode<Person*> *person= new TreeNode<Person*>();
    Person *facPrinter = new Person();
    person = fac->searchNode(facId);
    facPrinter = person->getNodeData();
    
    //prints data before changing it
    cout << "\nFaculty's data before the change"<< endl;
    facPrinter->printFacData();

    //actually changes it
    facPrinter->setName(userChange);

    //prints data after changing it
    cout << "\nFaculty's data after the change"<< endl;
    facPrinter->printFacData();

}//end option 21


  //saves the data

//     _____                     ____        __
//    / ___/____ __   _____     / __ \____ _/ /_____ _
//    \__ \/ __ `/ | / / _ \   / / / / __ `/ __/ __ `/
//   ___/ / /_/ /| |/ /  __/  / /_/ / /_/ / /_/ /_/ /
//  /____/\__,_/ |___/\___/  /_____/\__,_/\__/\__,_/
//



        cout << endl << endl;
        DoublyLinkedList<int> *studTreeIds = new DoublyLinkedList<int>();
        DoublyLinkedList<int> *facTreeIds = new DoublyLinkedList<int>();
        *studTreeIds = w->getTreeNodeIds();
        *facTreeIds = fac->getTreeNodeIds();

}//end of while

if (filesEnabled)
{
  w->printTree(w->getRoot());
  myFileManager->saveFacFile(fac->getListOfNodes());
  myFileManager->saveStudFile(w->getListOfNodes());
}

  return 0;
}
