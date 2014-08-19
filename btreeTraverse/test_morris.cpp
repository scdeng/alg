/*
 * =====================================================================================
 *
 *       Filename:  test_morris.cpp
 *
 *    Description:  test morris 
 *
 *        Version:  1.0
 *        Created:  08/11/2014 11:36:38 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Deng Yong (dy), scdeng@163.com
 *        Company:  IIE,CAS
 *
 * =====================================================================================
 */
#include "binaryTreeTraverse.h"
#include <string>
#include <iostream>
using namespace std;

Node * maketree(){
	Node *root = new Node(6);
	root->left = new Node(4);
	root->right = new Node(8);
	root->left->left = new Node(3);
	root->left->right = new Node(5);
	root->right->left = new Node(7);
	root->right->right = new Node(9);
	return root;
}

void test_pre(Node *root){
	cout << "morris pre-order" << endl;
	morris_pre(root);
	cout << endl;
}


void test_in(Node *root){
	cout << "morris in-order" << endl;
	morris_in(root);
	cout << endl;
}

void test_in_stack_left(Node *root){
	cout << "stack: in-order: left first" << endl;
	in_order_stack_left(root);
	cout << endl;
}

void test_pre_stack_left(Node *root){
	cout << "stack: pre-order: left first" << endl;
	pre_order_stack_left(root);
	cout << endl;
}
void test_pre_stack_right(Node *root){
	cout << "stack: pre-order: right first" << endl;
	pre_order_stack_right(root);
	cout << endl;
}

void test_post_stack_left(Node *root){
	cout << "stack: post-order: left first: using two stack" << endl;
	post_order_stack_left(root);
	cout << endl;
}

void test_post_stack1_left(Node *root){
	cout << "stack: post-order: left first: using only one stack" << endl;
	post_order_stack1_left(root);
	cout << endl;
}

void test_level_order(Node *root){
	cout << "Queue: level order" << endl;
	levelOrder(root);
	cout << endl;
}

void test(int argc, char **argv){
	Node *root = maketree();
	test_pre(root);
	test_in(root);
	test_in_stack_left(root);
	test_pre_stack_left(root);
	test_pre_stack_right(root);
	test_post_stack_left(root);
	test_post_stack1_left(root);
	test_level_order(root);
}
