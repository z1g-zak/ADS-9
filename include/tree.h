// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <algorithm>
#include <cstdint>
#include <numeric>
#include <string>
#include <vector>

struct Node {
  char n;
  std::vector<Node*> children;

  explicit Node(char val);
  ~Node();

  Node(const Node&) = delete;
  Node& operator=(const Node&) = delete;
  Node(Node&&) = delete;
  Node& operator=(Node&&) = delete;
};

class PMTree {
 private:
  std::vector<Node*> rt_child;
  int size;

  void buildSubtree(Node* par, std::vector<char> avail_ch);

 public:
  explicit PMTree(std::vector<char> in);
  ~PMTree();

  PMTree(const PMTree&) = delete;
  PMTree& operator=(const PMTree&) = delete;
  PMTree(PMTree&&) = delete;
  PMTree& operator=(PMTree&&) = delete;

  const std::vector<Node*>& getRootChild() const { return rt_child; }
  int getSize() const { return size; }
};

std::vector<std::vector<char>> getAllPerms(PMTree& tree);
std::vector<char> getPerm1(PMTree& tree, int n);
std::vector<char> getPerm2(PMTree& tree, int n);

#endif  // INCLUDE_TREE_H_
