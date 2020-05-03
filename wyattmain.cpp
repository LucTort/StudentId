#include "BST.cpp"
int main(){
  BST<int> *w = new BST<int>();
  int option = 0;
  // TreeNode *node = new TreeNode();

  w->insert(5);
  w->insert(10);
  w->insert(3);
  w->insert(12);
  w->insert(8);
  w->insert(4);
  w->insert(2);
  w->insert(13);

  w-> printTree(w->getMax());
  w-> printTree(w->getMin());

  // w->deleteNode(2);

  cout << w->search(2)<< endl;


  // w->deleteNode(10);
  // w->deleteNode(3);
  // w->deleteNode(12);
  // w->deleteNode(8);
  // w->deleteNode(4);
  // w->deleteNode(2);
  // w->deleteNode(13);
    w->deleteNode(5);

  cout << "Test" << endl;

  cout << "Is it in tree:" << w->search(5)<< endl;

  cout << "Entire tree" << endl;

  w-> printTree(w->getRoot());

  // w->printTree(w->search(5));


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

  cin >> option;








  return 0;
}
