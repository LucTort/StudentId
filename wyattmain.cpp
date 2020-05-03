#include "BST.cpp"
int main(){
  BST<int> *w = new BST<int>();
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


  cout << "What would you like to do?\n"<<endl;
  cout << "1) Print all students and their information (sorted by ascending id #)" << endl;
  cout << "2) Print all faculty and their information (sorted by ascending id #)" << endl;


  return 0;
}
