// Michelle A. Santiago
// Lab 8: Breadth-First Traversal of Binary Trees

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "BinarySearchTree.hpp"
#include "doctest.h"
#include <sstream>
#include <stdexcept>
#include <queue>

using namespace std;

TEST_CASE("BinarySearchTree basic operations") {
  BinarySearchTree<int> B;
  B.insert(10);

  B.insert(4);
  B.insert(2);
  B.insert(15);
  B.insert(31);
  B.insert(1);
  B.insert(56);
  CHECK(B.toInorderStr() == "1,2,4,10,15,31,56");
  CHECK(B.BFT() == "[[10],[4,15],[2,31],[1,56]]");
  BinarySearchTree<int> C;
  for (auto e :
       {16, 8, 24, 28, 20, 12, 4, 2, 6, 10, 14, 18, 22, 26, 30, 15, 7, 3}) {
    C.insert(e);
  }

  CHECK(C.toInorderStr() == "2,3,4,6,7,8,10,12,14,15,16,18,20,22,24,26,28,30");
  CHECK(C.BFT() ==
        "[[16],[8,24],[4,12,20,28],[2,6,10,14,18,22,26,30],[3,7,15]]");
}

// my own test cases 

TEST_CASE("Basic operations of Binary Search Trees") {
  BinarySearchTree<int> W;

  W.insert(90);
  W.insert(89);
  W.insert(88);
  W.insert(87);
  W.insert(65);
  W.insert(34);
  W.insert(22);
  W.insert(10);

  CHECK(W.toInorderStr() == "10,22,34,65,87,88,89,90");
  
  W.remove(65);
  W.remove(87);

  CHECK(W.toInorderStr() == "10,22,34,88,89,90");

  CHECK(W.contains(90) == true);
  CHECK(W.contains(65) == false);
}