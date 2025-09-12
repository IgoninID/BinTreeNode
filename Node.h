#pragma once
#include <iostream>
#include <stack>
#include <vector>

/// <summary>
/// 
/// </summary>
enum class PATHS { nlr, nrl, lnr, rnl, lrn, rln, iter };

using enum PATHS; //

using namespace std; //

/// <summary>
/// 
/// </summary>
/// <typeparam name="T - "></typeparam>
template <typename T>
class BinTreeNode
{
public:
	BinTreeNode* left; //
	BinTreeNode* right; //
	T data; //

	/// <summary>
	/// 
	/// </summary>
	BinTreeNode()
	{
		data = nullptr; //
		left = nullptr; //
		right = nullptr; //
	}

	/// <summary>
	/// 
	/// </summary>
	/// <param name="data - "></param>
	BinTreeNode(T data)
	{
		this->data = data; //
		left = nullptr; //
		right = nullptr; //
	}
};

/// <summary>
/// 
/// </summary>
/// <typeparam name="T - "></typeparam>
/// <param name="curr - "></param>
template <typename T>
void NLR(const BinTreeNode<T>* curr)
{
	if (curr) //
	{
		cout << curr->data << " "; //
		NLR(curr->left); //
		NLR(curr->right); //
	}
}

/// <summary>
/// 
/// </summary>
/// <typeparam name="T - "></typeparam>
/// <param name="curr - "></param>
/// <param name="vec - "></param>
template <typename T>
void NLR(const BinTreeNode<T>* curr, vector<T>& vec)
{
	if (curr) //
	{
		vec.push_back(curr->data); //
		NLR(curr->left, vec); //
		NLR(curr->right, vec); //
	}
}

/// <summary>
/// 
/// </summary>
/// <typeparam name="T - "></typeparam>
/// <param name="curr - "></param>
template <typename T>
void NRL(const BinTreeNode<T>* curr)
{
	if (curr) //
	{
		cout << curr->data << " "; //
		NRL(curr->right); //
		NRL(curr->left); //
	}
}

/// <summary>
/// 
/// </summary>
/// <typeparam name="T - "></typeparam>
/// <param name="curr - "></param>
/// <param name="vec - "></param>
template <typename T>
void NRL(const BinTreeNode<T>* curr, vector<T>& vec)
{
	if (curr) //
	{
		vec.push_back(curr->data); //
		NRL(curr->right, vec); //
		NRL(curr->left, vec); //
	}
}

/// <summary>
/// 
/// </summary>
/// <typeparam name="T - "></typeparam>
/// <param name="curr - "></param>
template <typename T>
void LNR(const BinTreeNode<T>* curr)
{
	if (curr) //
	{
		LNR(curr->left); //
		cout << curr->data << " "; //
		LNR(curr->right); //
	}
}

/// <summary>
/// 
/// </summary>
/// <typeparam name="T - "></typeparam>
/// <param name="curr - "></param>
/// <param name="vec - "></param>
template <typename T>
void LNR(const BinTreeNode<T>* curr, vector<T>& vec)
{
	if (curr) //
	{
		LNR(curr->left, vec); //
		vec.push_back(curr->data); //
		LNR(curr->right, vec); //
	}
}

/// <summary>
/// 
/// </summary>
/// <typeparam name="T - "></typeparam>
/// <param name="curr - "></param>
template <typename T>
void RNL(const BinTreeNode<T>* curr)
{
	if (curr) //
	{
		RNL(curr->right); //
		cout << curr->data << " "; //
		RNL(curr->left); //
	}
}

/// <summary>
/// 
/// </summary>
/// <typeparam name="T - "></typeparam>
/// <param name="curr - "></param>
/// <param name="vec - "></param>
template <typename T>
void RNL(const BinTreeNode<T>* curr, vector<T>& vec)
{
	if (curr) //
	{
		RNL(curr->right, vec); //
		vec.push_back(curr->data); //
		RNL(curr->left, vec); //
	}
}

/// <summary>
/// 
/// </summary>
/// <typeparam name="T - "></typeparam>
/// <param name="curr - "></param>
template <typename T>
void LRN(const BinTreeNode<T>* curr)
{
	if (curr) //
	{
		LRN(curr->left); //
		LRN(curr->right); //
		cout << curr->data << " "; //
	}
}

/// <summary>
/// 
/// </summary>
/// <typeparam name="T - "></typeparam>
/// <param name="curr - "></param>
/// <param name="vec - "></param>
template <typename T>
void LRN(const BinTreeNode<T>* curr, vector<T>& vec)
{
	if (curr)
	{
		LRN(curr->left, vec); //
		LRN(curr->right, vec); //
		vec.push_back(curr->data); //
	}
}

/// <summary>
/// 
/// </summary>
/// <typeparam name="T - "></typeparam>
/// <param name="curr - "></param>
template <typename T>
void RLN(const BinTreeNode<T>* curr)
{
	if (curr) //
	{
		RLN(curr->right); //
		RLN(curr->left); //
		cout << curr->data << " "; //
	}
}

/// <summary>
/// 
/// </summary>
/// <typeparam name="T - "></typeparam>
/// <param name="curr - "></param>
/// <param name="vec - "></param>
template <typename T>
void RLN(const BinTreeNode<T>* curr, vector<T>& vec)
{
	if (curr) //
	{
		RLN(curr->right, vec); //
		RLN(curr->left, vec); //
		vec.push_back(curr->data); //
	}
}

/// <summary>
/// 
/// </summary>
/// <typeparam name="T - "></typeparam>
/// <param name="curr - "></param>
template <typename T>
void iterPath(const BinTreeNode<T>* curr)
{
	if (curr) //
	{
		const BinTreeNode<T>* temp; //
		stack<const BinTreeNode<T>* > s; //
		s.push(curr); //
		while (!s.empty()) //
		{
			temp = s.top(); //
			s.pop(); //
			cout << temp->data << " "; //
			if (temp->right) //
				s.push(temp->right); //
			if (temp->left) //
				s.push(temp->left); //
		}
	}
}

/// <summary>
/// 
/// </summary>
/// <typeparam name="T - "></typeparam>
/// <param name="curr - "></param>
/// <param name="vec - "></param>
template <typename T>
void iterPath(const BinTreeNode<T>* curr, vector<T>& vec)
{
	if (curr) //
	{
		const BinTreeNode<T>* temp; //
		stack<const BinTreeNode<T>* > s; //
		s.push(curr); //
		while (!s.empty()) //
		{
			temp = s.top(); //
			s.pop(); //
			vec.push_back(temp->data); //
			if (temp->right) //
				s.push(temp->right); //
			if (temp->left) //
				s.push(temp->left); //
		}
	}
}

/// <summary>
/// 
/// </summary>
/// <typeparam name="T - "></typeparam>
/// <param name="curr - "></param>
/// <param name="choice - "></param>
template <typename T>
void path(const BinTreeNode<T>* curr, PATHS choice)
{
	switch (choice) //
	{
	case (PATHS)0: //
		NLR<T>(curr); //
		break;
	case (PATHS)1: //
		NRL<T>(curr); //
		break;
	case (PATHS)2: //
		LNR<T>(curr); //
		break;
	case (PATHS)3: //
		RNL<T>(curr); //
		break;
	case (PATHS)4: //
		LRN<T>(curr); //
		break;
	case (PATHS)5: //
		RLN<T>(curr); //
		break;
	case (PATHS)6: //
		iterPath(curr); //
		break;
	}
}

/// <summary>
/// 
/// </summary>
/// <typeparam name="T - "></typeparam>
/// <param name="curr - "></param>
/// <param name="choice - "></param>
/// <param name="vec - "></param>
template <typename T>
void path(const BinTreeNode<T>* curr, PATHS choice, vector<T>& vec)
{
	switch (choice) //
	{
	case (PATHS)0: //
		NLR<T>(curr, vec); //
		break;
	case (PATHS)1: //
		NRL<T>(curr, vec); //
		break;
	case (PATHS)2: //
		LNR<T>(curr, vec); //
		break;
	case (PATHS)3: //
		RNL<T>(curr, vec); //
		break;
	case (PATHS)4: //
		LRN<T>(curr, vec); //
		break;
	case (PATHS)5: //
		RLN<T>(curr, vec); //
		break;
	case (PATHS)6: //
		iterPath(curr, vec); //
		break;
	}
}

/// <summary>
/// 
/// </summary>
/// <typeparam name="T - "></typeparam>
/// <param name="data - "></param>
/// <param name="tree -"></param>
template <typename T>
void insert(T data, BinTreeNode<T>* tree)
{
	if (tree == nullptr) //
	{
		tree = new BinTreeNode<T>(data); //
		return; //
	}
	if (tree->left == nullptr) //
	{
		tree->left = new BinTreeNode<T>(data); //
		return; //
	}
	else //
	{
		tree->right = new BinTreeNode<T>(data); //
		return; //
	}
}

/// <summary>
/// 
/// </summary>
/// <typeparam name="T - "></typeparam>
/// <param name="data - "></param>
/// <param name="curr - "></param>
/// <returns>
/// 
/// </returns>
template <typename T>
BinTreeNode<T>* insertintree(T data, BinTreeNode<T>* curr)
{
	if (curr == nullptr) //
	{
		return new BinTreeNode<T>(data); //
	}
	if (data < curr->data) //
	{
		curr->left = insertintree<T>(data, curr->left); //
	}
	if (data > curr->data) //
	{
		curr->right = insertintree<T>(data, curr->right); //
	}
	return curr; //
}

/// <summary>
/// 
/// </summary>
/// <typeparam name="T - "></typeparam>
/// <param name="vec - "></param>
/// <returns>
/// 
/// </returns>
template <typename T>
BinTreeNode<T>* treefromvector(vector<T>& vec)
{
	BinTreeNode<T>* curr = nullptr; //
	for (T data : vec) //
	{
		curr = insertintree(data, curr); //
	}
	return curr; //
}

/// <summary>
/// 
/// </summary>
/// <typeparam name="T - "></typeparam>
/// <param name="curr - "></param>
template <typename T>
void deletetree(BinTreeNode<T>* curr)
{
	if (curr) //
	{
		deletetree(curr->left); //
		deletetree(curr->right); //
		delete curr; //
	}
}

/// <summary>
/// 
/// </summary>
/// <typeparam name="T - "></typeparam>
/// <param name="curr - "></param>
/// <returns>
/// 
/// </returns>
template <typename T>
T in(BinTreeNode<T>* curr)
{
	if (curr) //
	{
		return curr->data; //
	}
	throw 1; //
}

/// <summary>
/// 
/// </summary>
/// <typeparam name="T - "></typeparam>
/// <param name="curr - "></param>
/// <returns>
/// 
/// </returns>
template <typename T>
size_t count(BinTreeNode<T>* curr)
{
	if (curr == nullptr) //
	{
		return 0; //
	}
	return 1 + count<T>(curr->left) + count<T>(curr->right); //
}

/// <summary>
/// 
/// </summary>
/// <typeparam name="T - "></typeparam>
/// <param name="curr - "></param>
/// <returns>
/// 
/// </returns>
template <typename T>
int depth(BinTreeNode<T>* curr)
{
	if (curr == nullptr) //
	{
		return -1; //
	}
	int left = depth<T>(curr->left); //
	int right = depth<T>(curr->right); //
	return max(left, right) + 1; //
}

/// <summary>
/// 
/// </summary>
/// <typeparam name="T - "></typeparam>
/// <param name="data - "></param>
/// <param name="curr - "></param>
/// <returns>
/// 
/// </returns>
template <typename T>
T find(T data, BinTreeNode<T>* curr)
{
	if (curr == nullptr) //
	{
		throw 1; //
	}
	if (data == curr->data) //
	{
		return curr->data; //
	}
	if (data < curr->data)
	{
		return find<T>(data, curr->left); //
	}
	if (data > curr->data)
	{
		return find<T>(data, curr->right); //
	}
}

/// <summary>
/// 
/// </summary>
/// <typeparam name="T - "></typeparam>
/// <param name="curr - "></param>
/// <returns>
/// 
/// </returns>
template <typename T>
BinTreeNode<T>* minDataNode(BinTreeNode<T>* curr)
{
	BinTreeNode<T>* temp = curr; //
	while (temp && temp->left != nullptr) //
	{
		temp = temp->left; //
	}
	return temp; //
}

/// <summary>
/// 
/// </summary>
/// <typeparam name="T - "></typeparam>
/// <param name="curr - "></param>
/// <param name="data - "></param>
/// <returns>
/// 
/// </returns>
template <typename T>
BinTreeNode<T>* removeNode(BinTreeNode<T>* curr, T data)
{
	if (curr == nullptr) //
	{
		return curr; //
	}
	if (data < curr->data) //
	{
		curr->left = removeNode<T>(curr->left, data); //
	}
	else if (data > curr->data) //
	{
		curr->right = removeNode<T>(curr->right, data); //
	}
	else //
	{
		//
		BinTreeNode<T>* temp; //
		if (curr->left == nullptr) //
		{
			temp = curr->right; //
			delete(curr); //
			return temp; //
		}
		else if (curr->right == nullptr) //
		{
			temp = curr->left; //
			delete(curr); //
			return temp; //
		}
		//
		temp = minDataNode<T>(curr->right); //
		curr->data = temp->data; //
		curr->right = removeNode<T>(curr->right, temp->data); //
	}
	return curr; //
}

/// <summary>
/// 
/// </summary>
void test();