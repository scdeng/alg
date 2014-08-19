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
void traverse(Node *p){
	cout << p->data << " ";
}


/*	@brief recursively traverse binary tree
 */
void rec_in(Node *root){
	if( !root ){
		return ;
	}
	rec_in(root->left);
	cout << root->data << " ";
	rec_in(root->right);
}

/*	@brief recursively traverse binary tree
 */
void rec_post(Node *root){
	if( !root ){
		return ;
	}
	rec_post(root->left);
	rec_post(root->right);
	cout << root->data << " ";
}

/*	@brief level order traversal
 */
void levelOrder(Node *root){
	//1. initialize an empty queue
	queue<Node*> Q;
	//2. enqueue root
	Q.push(root);
	//3.while queue is not empty
	while( !Q.empty() ){
		//	3.1 dequeue from queue
		Node *p = Q.front();
		Q.pop();
		//	3.2 traverse popped item
		traverse(p);
		//	3.3 enqueue popped item's both children (if not null)
		if( p->left ){
			Q.push(p->left);
		}
		if( p->right ){
			Q.push(p->right);
		}
	}
}


/*	@brief traverse binary tree in non-recursive with no stack
 *		morris inorder traversal
 */
void morris_in(Node *root){
	Node *cur = root;
	Node *pre;
	while( cur != NULL ){
		if( cur->left == NULL ){
			cout << cur->data << " ";
			cur = cur->right;
		}else{
			//find cur's pre in inorder
			pre = cur->left;
			while( pre->right != NULL && pre->right != cur ){
				pre = pre->right;
			}

			//first time to get cur's previous node
			//if pre has not linked to cur
			//link it which means that 
			//cur's left subtree has not been traversed
			if( pre->right == NULL ){
				pre->right = cur;
				cur = cur->left;
			}else{
				//cur->left subtree has been traversed
				//inorder traversal
				//traversal left subtree and then traverse myself
				cout << cur->data << " ";
				//recover pre's right to be NULL
				pre->right = NULL;
				//traverse cur's right subtree
				cur = cur->right;
			}
		}
	}
}

/*	@brief morris pre-order traversal binary tree
 */
void morris_pre(Node *root){
	Node *cur = root;
	Node *pre;
	while( cur != NULL ){
		if( cur->left == NULL ){
			cout << cur->data << " ";
			cur = cur->right;
		}else{

			//find cur's previous node (in-order)
			pre = cur->left;
			while( pre->right != NULL && pre->right != cur ){
				pre = pre->right;
			}
			//first time to get cur's previous node
			//which means two facts:
			//	1. pre has not linked to cur
			//	2. cur's left subtree has not been traversed
			if( pre->right == NULL ){
				//traverse myself before traverse left subtree
				cout << cur->data << " ";
				pre->right = cur;
				cur = cur->left;
			}else{
				//cur->left subtree has been traversed
				//recover pre's right to be NULL
				pre->right = NULL;
				cur = cur->right;
			}
		}
	}
}

/*	@brief traverse a binary tree in inorder without recursion
 */
void in_order_stack_left(Node *root){

	//1. initialize am empty stack
	stack<Node*> st;
	//2. initialize current as root
	Node *cur = root;
	
	//3. push current to stack until current is not NULL
	while( cur != NULL ){
		st.push(cur);
		cur = cur->left;
	}
	while( !st.empty() ){	
		//	3.1 pop stack as node p
		Node *p = st.top();
		st.pop();
		//	3.2 traverse p
		traverse(p);
		//	3.3 set current to be p->right and go step 3
		cur = p->right;
		//this is step 3
		//push 
		while( cur != NULL ){
			st.push(cur);
			cur = cur->left;
		}
	}	
}




/*	@brief traverse a binary tree in pre-order without recursion
 *		left subtree traversed first
 */
void pre_order_stack_left(Node *root){

	//1. initialize am empty stack
	stack<Node*> st;
	//2. initialize current as root
	Node *cur = root;
	
	//3. push current to stack until current is not NULL
	while( cur != NULL ){
		st.push(cur);
		traverse(cur);
		cur = cur->left;
	}
	while( !st.empty() ){	
		//	3.1 pop stack as node p
		Node *p = st.top();
		st.pop();
		//	3.2 traverse p
		//traverse(p);
		//	3.3 set current to be p->right and go step 3
		cur = p->right;
		//this is step 3
		//push 
		while( cur != NULL ){
			st.push(cur);
			traverse(cur);
			cur = cur->left;
		}
	}	
}


/*	@brief traverse a binary tree in pre-order without recursion
 *		right subtree traversed first
 *	@return return reverse post order of left check first
 */
stack<Node*> pre_order_stack_right(Node *root){

	stack<Node*> postOrder;
	//1. initialize am empty stack
	stack<Node*> st;
	//2. initialize current as root
	Node *cur = root;
	
	//3. push current to stack until current is not NULL
	while( cur != NULL ){
		st.push(cur);
		traverse(cur);
		postOrder.push(cur);
		cur = cur->right;
	}
	while( !st.empty() ){	
		//	3.1 pop stack as node p
		Node *p = st.top();
		st.pop();
		//	3.2 traverse p
		//traverse(p);
		//	3.3 set current to be p->right and go step 3
		cur = p->left;
		//this is step 3
		//push 
		while( cur != NULL ){
			st.push(cur);
			traverse(cur);
			postOrder.push(cur);
			cur = cur->right;
		}
	}
	return postOrder;
}

/*	@brief traverse binary tree (post-order) using two stacks
 */
void post_order_stack_left(Node *root){
	stack<Node*> postOrder = pre_order_stack_right(root);
	cout << endl;
	while( !postOrder.empty() ){
		cout << postOrder.top()->data << " ";
		postOrder.pop();
	}
}

/*	@brief post-order traverse binary tree using only one stack
 */
void post_order_stack1_left(Node *root){
	//1. initialize an empty stack
	stack<Node*> st;
	//2. set cur as root
	Node *cur = root;
	//3. while cur is not null do:
	//	3.1 push cur's right to stack
	//	3.2 push cur to stack
	//4.while stack is not empty do:
	//	4.1 pop stack, Node *p is popped item
	//	4.2 if p has right child and the right child is on top of stack
	//		a) then:
	//			pop stack, push cur to stack
	//			set cur as cur's right
	//			push like step 3
	//		b) else:
	//			traverse cur
	//			set cur as NULL
	do{
		//step 3
		while( cur != NULL ){
			if( cur->right ){
				st.push(cur->right);
			}
			st.push(cur);
			cur = cur->left;
		}
		
		//step 4.1
		Node *p = st.top();
		st.pop();
		//4.2 a)
		if( p->right && !st.empty() && p->right == st.top()){
			cur = st.top();
			st.pop();
			st.push(p);
		}else{
			//4.2 b)
			traverse(p);
			cur = NULL;
		}
	}while( !st.empty() );
}


