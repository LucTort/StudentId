#include "BST.cpp"

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
}

int main(){

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
  DoublyLinkedList<int> *adv1 = new DoublyLinkedList<int>();
  DoublyLinkedList<int> *adv2 = new DoublyLinkedList<int>();
  DoublyLinkedList<int> *adv3 = new DoublyLinkedList<int>();

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

//for every faculty memeber a doubly linked list must be created
  Person *lucas = new Person();
  lucas->setId(50);
  lucas->setName("Lucas Torti");
  lucas->setLevel("Lecturer");//Lecturer, assistant professor, associate professor
  lucas->setDepartment("Keck Center");
  adv1->insertBack(40);
  lucas->setAdvisees(adv1);//starting to delimeter and then create a new doubly linked list and add everything in between, pass in doubly linked list to set advisee

  Person *wyatt = new Person();
  wyatt->setId(20);
  wyatt->setName("wyatt miller");
  wyatt->setLevel("professor");//Lecturer, assistant professor, associate professor
  wyatt->setDepartment("Argyros");
  // adv2->insertBack(30);
  wyatt->setAdvisees(adv2);

  Person *chris = new Person();
  chris->setId(70);
  chris->setName("chris change");
  chris->setLevel("assistant professor");//Lecturer, assistant professor, associate professor
  chris->setDepartment("dance school");
  adv3->insertBack(35);
  adv3->insertBack(30);
  chris->setAdvisees(adv3);


  w->insert(frank->getId(), frank);

  w->insert(rosie->getId(), rosie);

  w->insert(bob->getId(), bob);

  fac->insert(lucas->getId(), lucas);

  fac->insert(wyatt->getId(), wyatt);

  fac->insert(chris->getId(), chris);



  // WORKNG PRINT STUDENT ASCENDING
  // w->printTree(w->getRoot());
  // w->printStudent();




  int option = 0;

  printOptions();

  cin >> option;

  if (option == 1){
    // WORKNG PRINT STUDENT ASCENDING
    w->printTree(w->getRoot());
    w->printStudent();
  }

  if (option ==2){
    //PRINT FACULTY ASCENDING
    fac->printTree(fac->getRoot());
    fac->printFac();
  }


  if (option == 3){
    cout << "Enter the ID that you would like to print the information "<< endl;
    cin >> idInput;

    trueCheck = w->search(idInput);
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
  if (option == 4){
    cout << "Enter the ID that you would like to print the information "<< endl;
    cin >> facIdInput;
    //checking if id exists
    trueCheck = fac->search(facIdInput);

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

  if (option == 5){
    cout << "Enter the ID of the students "<< endl;
    cin >> studInput1;

    trueCheck = w->search(studInput1);

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
if (option == 6){
  cout << "well get back to this"<< endl;
}
if (option == 7){
  string name1 = "";
  double gpa1 = 0;
  int id1 = 0;
  string major1= "";
  string standing1 = "";
  int advisor1 = 0;

  cout<< "Please enter information for the following fields "<< endl;
  cout<< "Name? "<< endl;
  std::getline(std::cin >> std::ws, name1);
  cout<< "ID? "<< endl;
  cin>>id1;
  cout<< "GPA? "<< endl;
  cin>>gpa1;
  cout<< "Major? "<< endl;
  std::getline(std::cin >> std::ws, major);
  cout<< "Standing? "<< endl;
  cin>>standing1;
  cout<< "Advisor? "<< endl;
  cin>> advisor1;

  int trueCheck1= 0;
  trueCheck1 = fac->search(advisor1);

  //CHECKING FOR THE CORRECT DATA TYPES

  // while (trueCheck1 == 0){
  //   cout << "That advisor does not exist, please enter one that does"<< endl;
  //   cout<< "Advisor? "<<endl;
  //   cin>> advisor1;
  //   trueCheck1 = fac->search(advisor1);
  // }
  Person *renee = new Person();
  renee->setId(id1);
  renee->setGPA(gpa1);
  renee->setMajor(major1);
  renee->setStanding(standing1);
  renee->setName(name1);
  renee->setAdvisor(advisor1);

  w->insert(renee->getId(), renee);

  cout << "You added this new student"<< endl;

  int trueCheck2 = 0;
  trueCheck2 = w->search(id1);
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








  return 0;
}
