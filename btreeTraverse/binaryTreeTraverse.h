/*
 * =====================================================================================
 *
 *       Filename:  morris.h
 *
 *    Description:  morris traversal
 *
 *        Version:  1.0
 *        Created:  08/11/2014 11:25:59 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Deng Yong (dy), scdeng@163.com
 *        Company:  IIE,CAS
 *
 * =====================================================================================
 */
#include <queue>
#include <stack>
#include <iostream>
using namespace std;
struct Node{
	int data;
	Node *left;
	Node *right;
	Node(int n):data(n),left(NULL),right(NULL){}
};

/*	@brief trivial traverse node p
 */
void traverse(Node *p);


/*	@brief recursively traverse binary tree
 */
void rec_in(Node *root);

/*	@brief recursively traverse binary tree
 */
void rec_post(Node *root);


/*	@brief level order traversal
 */
void levelOrder(Node *root);


/*	@brief traverse binary tree in non-recursive with no stack
 *		morris inorder traversal
 */
void morris_in(Node *root);

/*	@brief morris pre-order traversal binary tree
 */
void morris_pre(Node *root);

/*	@brief traverse a binary tree in inorder without recursion
 */
void in_order_stack_left(Node *root);

/*	@brief traverse a binary tree in pre-order without recursion
 *		left subtree traversed first
 */
void pre_order_stack_left(Node *root);

/*	@brief traverse a binary tree in pre-order without recursion
 *		right subtree traversed first
 *	@return return reverse post order of left check first
 */
stack<Node*> pre_order_stack_right(Node *root);

/*	@brief traverse binary tree (post-order) using two stacks
 */
void post_order_stack_left(Node *root);

/*	@brief post-order traverse binary tree using only one stack
 */
void post_order_stack1_left(Node *root);


