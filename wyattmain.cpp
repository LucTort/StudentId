#include "BST.cpp"
int main(){
  BST *w = new BST();
  // TreeNode *node = new TreeNode();

  w->insert(5);
  w->insert(10);
  w->insert(3);
  w->insert(12);
  w->insert(5);
  w->insert(8);
  w->insert(4);
  w->insert(2);

  w-> printTree(w->getMax());
  w-> printTree(w->getMin());

  // w->deleteNode(2);

  cout << w->search(2)<< endl;

  w->deleteNode(2);

  cout << w->search(2)<< endl;

  // w-> printTree(w->getMin());

  // w->printTree(w->search(5));

  return 0;
}
