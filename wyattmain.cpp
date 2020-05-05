//Add in to a doubly linked list all the ids, then grab the ids in order, see if they match a get id from a student, and if it does, print all the student's information
//If we make a function which prints all the student ids to a doubley linked list similar to how the printTree function prints all the student ids to the console, then we will be able to search every student id using that list

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

  Person *bob = new Person();
  bob->setId(80);
  bob->setGPA(3.29);

  Person *frank = new Person();
  frank->setId(30);
  frank->setGPA(1.2);

  Person *rosie = new Person();
  rosie->setId(35);
  rosie->setGPA(16);



  w->insert(bob->getId(), bob);

  w->insert(frank->getId(), frank);
  w->insert(rosie->getId(), rosie);

  w->printTree(w->getRoot());
  cout<< "Delete" << endl;
  cout << "Derp" << endl;
//      _______             __     __     __  _                      __                      __ 
//     / ____(_)  __   ____/ /__  / /__  / /_(_)___  ____ _   ____ _/ /_   _________  ____  / /_
//    / /_  / / |/_/  / __  / _ \/ / _ \/ __/ / __ \/ __ `/  / __ `/ __/  / ___/ __ \/ __ \/ __/
//   / __/ / />  <   / /_/ /  __/ /  __/ /_/ / / / / /_/ /  / /_/ / /_   / /  / /_/ / /_/ / /_  
//  /_/   /_/_/|_|   \__,_/\___/_/\___/\__/_/_/ /_/\__, /   \__,_/\__/  /_/   \____/\____/\__/  
//                                                /____/                                        
  w->deleteNode(bob->getId());
    cout<< "Reprint tree" << endl;

  w->printTree(w->getRoot());

  w->returnNode(w->getRoot());



  int option = 0;

//    ______          __     _____ __            __   ______                                 __
//   /_  __/__  _____/ /_   / ___// /___  ______/ /  /_  __/_______  ___     ___  ____  ____/ /
//    / / / _ \/ ___/ __/   \__ \/ __/ / / / __  /    / / / ___/ _ \/ _ \   / _ \/ __ \/ __  / 
//   / / /  __(__  ) /_    ___/ / /_/ /_/ / /_/ /    / / / /  /  __/  __/  /  __/ / / / /_/ /  
//  /_/  \___/____/\__/   /____/\__/\__,_/\__,_/    /_/ /_/   \___/\___/   \___/_/ /_/\__,_/   
//                                                                                             

  printOptions();

  cin >> option;
  if (option == 1){

  }







  return 0;
}
