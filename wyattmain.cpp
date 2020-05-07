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
  BST<Person*> *w = new BST<Person*>();

  Person *rosie = new Person();
  rosie->setId(35);
  rosie->setGPA(3.8);
  rosie->setMajor("Accounting");
  rosie->setStanding("Senior");
  rosie->setName("Rosie O Donald");

  Person *frank = new Person();
  frank->setId(30);
  frank->setGPA(1.2);
  frank->setMajor("CompSci");
  frank->setStanding("Junior");
  frank->setName("Frank Azark");

  Person *bob = new Person();
  bob->setId(40);
  bob->setGPA(3.29);
  bob->setMajor("Finance");
  bob->setStanding("Senior");
  bob->setName("Bob Miller");

  // Person *lucas = new Person();
  // lucas->setId(50);
  // lucas->setGPA(3.9);
  // lucas->setMajor("Finance");
  // lucas->setStanding("Senior");
  // lucas->setName("Bob Miller");




  w->insert(frank->getId(), frank);

  w->insert(rosie->getId(), rosie);

  w->insert(bob->getId(), bob);



  w->printTree(w->getRoot());


  w->printStudent();




  int option = 0;

  printOptions();

  cin >> option;







  return 0;
}
