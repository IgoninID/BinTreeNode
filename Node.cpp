#include <cassert>
#include "Node.h"

using namespace std;

/// <summary>
/// �������� ������� ��� �������� ������ ���� ������
/// </summary>
void test_rand()
{
	// �������� ������������ � �����������, ������� insert
	BinTreeNode<int>* tree1 = new BinTreeNode<int>(5);
	assert(tree1->data == 5);
	insert(6, tree1);
	assert(tree1->left->data = 6);
	insert(9, tree1);
	assert(tree1->right->data = 9);
	deletetree(tree1);

	// �������� ����������� �� ������� � ���, ���������� � ������ ���������
	vector<int> vect{ 4, 5, 6, 9, 10, 13, 15 };

	vector<int> vect1{ 9, 5, 4, 6, 10, 15, 13 };
	vector<int> vect2{ 9, 10, 15, 13, 5, 6, 4 };
	vector<int> vect3{ 15, 13, 10, 9, 6, 5, 4 };
	vector<int> vect4{ 13, 15, 10, 6, 4, 5, 9 };
	vector<int> vect5{ 4, 6, 5, 13, 15, 10, 9 };

	vector<int> test{ 9, 5, 10, 15, 13, 4, 6 };
	vector<int> t1;

	BinTreeNode<int>* tree2 = treefromvector(test);
	/*							9
	*					5				10
	*				4		6					15
	*										13
	*/
	path(tree2, lnr, t1);
	assert(vect == t1);
	t1.clear();	

	path(tree2, nlr, t1);
	assert(vect1 == t1);
	t1.clear();

	path(tree2, nrl, t1);
	assert(vect2 == t1);
	t1.clear();

	path(tree2, rnl, t1);
	assert(vect3 == t1);
	t1.clear();

	path(tree2, rln, t1);
	assert(vect4 == t1);
	t1.clear();

	path(tree2, lrn, t1);
	assert(vect5 == t1);
	t1.clear();

	path(tree2, iter, t1);
	assert(vect1 == t1);
	t1.clear();

	assert(count(tree2) == 7); // �������� ���������� ����� � ������� ������
	assert(depth(tree2) == 3);

	// �������� ������ � ���
	assert(find(15, tree2) == 15); // ������� ����
	try // ��� ��������
	{
		find(100, tree2);
		assert(false);
	}
	catch (out_of_range)
	{

	}

	// �������� �� ������
	removeNode(tree2, 15); // �������� � ����� ��������
	vector<int> vect6{ 4, 5, 6, 9, 10, 13 };
	path(tree2, lnr, t1);
	assert(t1 == vect6);
	t1.clear();

	removeNode(tree2, 5); // �������� � ����� ���������
	vector<int> vect7{ 4, 6, 9, 10, 13 };
	path(tree2, lnr, t1);
	assert(t1 == vect7);
	t1.clear();

	removeNode(tree2, 13); // �������� ��� ��������
	vector<int> vect8{4, 6, 9, 10};
	path(tree2, lnr, t1);
	assert(t1 == vect8);
	t1.clear();

	removeNode(tree2, 100); // �������� �����. ��������
	path(tree2, lnr, t1);
	assert(t1 == vect8);
	t1.clear();

	BinTreeNode<int>* ctree = copyNodes(tree2); // �������� ����������� ������
	path(ctree, lnr, t1);
	assert(t1 == vect8);
	t1.clear();

	deletetree(ctree);
	deletetree(tree2);

	BinTreeNode<int>* tree3 = new BinTreeNode<int>(1);
	assert(count(tree3) == 1); // �������� ���������� ����� � ������� ������
	assert(depth(tree3) == 0);
	assert(in(tree3) == 1); // �������� ��������� ������� � ������ � ����
	deletetree(tree3);

	BinTreeNode<int>* tree4 = nullptr;
	assert(count(tree4) == 0); // �������� ���������� ����� � ������� ������
	assert(depth(tree4) == -1);

	try // �������� ��������� ������� � ������ � ������ ����
	{
		int i = in(tree4);
		assert(false);
	}
	catch (out_of_range)
	{

	}

}

/// <summary>
/// �������� ������� ��� �������� ������ ���� ������ ��� ������� ������
/// </summary>
void test_void()
{
	BinTreeNode<int>* tree = nullptr;
	vector<int> v;
	vector<int> t;

	// ������
	path(tree, nlr, v);
	assert(v == t);
	v.clear();

	path(tree, nrl, v);
	assert(v == t);
	v.clear();

	path(tree, lnr, v);
	assert(v == t);
	v.clear();

	path(tree, rnl, v);
	assert(v == t);
	v.clear();

	path(tree, lrn, v);
	assert(v == t);
	v.clear();

	path(tree, rln, v);
	assert(v == t);
	v.clear();

	path(tree, iter, v);
	assert(v == t);
	v.clear();

	// ��������� ������
	try
	{
		int i = in(tree);
		assert(false);
	}
	catch (out_of_range)
	{

	}

	//���������� � �������
	assert(count(tree) == 0);
	assert(depth(tree) == -1);

	//�����
	try
	{
		int i = find(5, tree);
		assert(false);
	}
	catch (out_of_range)
	{

	}

	// ��������
	removeNode(tree, 5);
	path(tree, nlr, v);
	assert(v == t);

	// �������� ������
	deletetree(tree);
	path(tree, nlr, v);
	assert(v == t);

	// �������
	tree = insertintree(10, tree);
	path(tree, nlr, v);
	assert(v.size() == 1);
	assert(v[0] == 10);
	v.clear();
	deletetree(tree);
}

/// <summary>
/// �������� ������� ��� �������� ������ ���� ������ ��� ������ �� ������ ��������
/// </summary>
void test_one()
{
	BinTreeNode<int>* tree = new BinTreeNode<int>(10);
	vector<int> v;
	vector<int> t{ 10 };
	vector<int> t2;

	// ������
	path(tree, nlr, v);
	assert(v == t);
	v.clear();

	path(tree, nrl, v);
	assert(v == t);
	v.clear();

	path(tree, lnr, v);
	assert(v == t);
	v.clear();

	path(tree, rnl, v);
	assert(v == t);
	v.clear();

	path(tree, lrn, v);
	assert(v == t);
	v.clear();

	path(tree, rln, v);
	assert(v == t);
	v.clear();

	path(tree, iter, v);
	assert(v == t);
	v.clear();

	//��������� ������
	int i = in(tree);
	assert(i == 10);

	//���������� � �������
	assert(count(tree) == 1);
	assert(depth(tree) == 0);

	//�����
	assert(find(10, tree) == 10);
	//����� �� �������������
	try
	{
		int i = find(5, tree);
		assert(false);
	}
	catch (out_of_range)
	{

	}


	// �������� �� �������������
	removeNode(tree, 5);
	path(tree, nlr, v);
	assert(v == t);
	v.clear();
	// ��������
	removeNode(tree, 10);
	tree = nullptr;
	path(tree, nlr, v);
	assert(v == t2);
	v.clear();

	// �������
	tree = insertintree(10, tree);

	insertintree(15, tree);
	path(tree, nlr, v);
	assert(v.size() == 2);
	assert(v[0] == 10);
	assert(v[1] == 15);
	v.clear();
	removeNode(tree, 15);

	//�������� ������
	deletetree(tree);
	tree = nullptr;
	path(tree, nlr, v);
	assert(v == t2);

}

/// <summary>
/// �������� ������� ��� �������� ������ ���� ������ ��� ������������ ������
/// </summary>
void test_perf()
{
	BinTreeNode<int>* tree = new BinTreeNode<int>(10);
	vector<int> v;
	vector<int> t1{ 10, 6, 3, 8, 20, 15, 25 };
	vector<int> t2{ 10, 20, 25, 15, 6, 8, 3 };
	vector<int> t3{ 3, 6, 8, 10, 15, 20, 25 };
	vector<int> t4{ 25, 20, 15, 10, 8, 6, 3 };
	vector<int> t5{ 3, 8, 6, 15, 25, 20, 10 };
	vector<int> t6{ 25, 15, 20, 8, 3, 6, 10 };
	/*
	*                   10
	*               6       20
	*             3   8   15   25
	*/
	insert(6, tree);
	insert(20, tree);
	insert(3, tree->left);
	insert(8, tree->left);
	insert(15, tree->right);
	insert(25, tree->right);

	// ������
	path(tree, nlr, v);
	assert(v == t1);
	v.clear();

	path(tree, nrl, v);
	assert(v == t2);
	v.clear();

	path(tree, lnr, v);
	assert(v == t3);
	v.clear();

	path(tree, rnl, v);
	assert(v == t4);
	v.clear();

	path(tree, lrn, v);
	assert(v == t5);
	v.clear();

	path(tree, rln, v);
	assert(v == t6);
	v.clear();

	path(tree, iter, v);
	assert(v == t1);
	v.clear();

	//��������� ������
	int i = in(tree);
	assert(i == 10);

	//���������� � �������
	assert(count(tree) == 7);
	assert(depth(tree) == 2);

	//�����
	assert(find(8, tree) == 8);
	//����� �� �������������
	try
	{
		int i = find(100, tree);
		assert(false);
	}
	catch (out_of_range)
	{

	}


	// �������� �� �������������
	removeNode(tree, 100);
	path(tree, nlr, v);
	assert(v == t1);
	v.clear();

	// �������� ��� ��������
	removeNode(tree, 25);
	path(tree, nlr, v);
	vector<int> t7{ 10, 6, 3, 8, 20, 15 };
	assert(v == t7);
	v.clear();

	// �������� � ����� ��������
	removeNode(tree, 20);
	path(tree, nlr, v);
	vector<int> t8{ 10, 6, 3, 8, 15 };
	assert(v == t8);
	v.clear();

	// �������� � ����� ���������
	removeNode(tree, 6);
	path(tree, nlr, v);
	vector<int> t9{ 10, 8, 3, 15 };
	assert(v == t9);
	v.clear();

	// �������
	insertintree(18, tree);
	path(tree, nlr, v);
	vector<int> t10{ 10, 8, 3, 15, 18 };
	assert(v == t10);
	v.clear();

	//�������� ������
	deletetree(tree);
	tree = nullptr;
	path(tree, nlr, v);
	vector<int> t11;
	assert(v == t11);
}

/// <summary>
/// �������� ������� ��� �������� ������ ���� ������ ��� �������� ������
/// </summary>
void test_comp()
{
	BinTreeNode<int>* tree = new BinTreeNode<int>(10);
	vector<int> v;
	vector<int> t1{ 10, 6, 3, 8, 20 };
	vector<int> t2{ 10, 20, 6, 8, 3 };
	vector<int> t3{ 3, 6, 8, 10, 20 };
	vector<int> t4{ 20, 10, 8, 6, 3 };
	vector<int> t5{ 3, 8, 6, 20, 10 };
	vector<int> t6{ 20, 8, 3, 6, 10 };
	/*
	*                   10
	*               6       20
	*             3   8
	*/
	insert(6, tree);
	insert(20, tree);
	insert(3, tree->left);
	insert(8, tree->left);

	// ������
	path(tree, nlr, v);
	assert(v == t1);
	v.clear();

	path(tree, nrl, v);
	assert(v == t2);
	v.clear();

	path(tree, lnr, v);
	assert(v == t3);
	v.clear();

	path(tree, rnl, v);
	assert(v == t4);
	v.clear();

	path(tree, lrn, v);
	assert(v == t5);
	v.clear();

	path(tree, rln, v);
	assert(v == t6);
	v.clear();

	path(tree, iter, v);
	assert(v == t1);
	v.clear();

	//��������� ������
	int i = in(tree);
	assert(i == 10);

	//���������� � �������
	assert(count(tree) == 5);
	assert(depth(tree) == 2);

	//�����
	assert(find(8, tree) == 8);
	//����� �� �������������
	try
	{
		int i = find(100, tree);
		assert(false);
	}
	catch (out_of_range)
	{

	}


	// �������� �� �������������
	removeNode(tree, 100);
	path(tree, nlr, v);
	assert(v == t1);
	v.clear();

	// �������� ��� ��������
	removeNode(tree, 20);
	path(tree, nlr, v);
	vector<int> t7{ 10, 6, 3, 8};
	assert(v == t7);
	v.clear();

	// �������� � ����� ���������
	removeNode(tree, 6);
	path(tree, nlr, v);
	vector<int> t9{ 10, 8, 3 };
	assert(v == t9);
	v.clear();

	// �������� � ����� ��������
	removeNode(tree, 8);
	path(tree, nlr, v);
	vector<int> t8{ 10, 3 };
	assert(v == t8);
	v.clear();

	// �������
	insertintree(18, tree);
	path(tree, nlr, v);
	vector<int> t10{ 10, 3, 18 };
	assert(v == t10);
	v.clear();

	//�������� ������
	deletetree(tree);
	tree = nullptr;
	path(tree, nlr, v);
	vector<int> t11;
	assert(v == t11);
}

/// <summary>
/// �������� ������� ��� �������� ������ ���� ������ ��� ������������ ������
/// </summary>
void test_deg()
{
	BinTreeNode<int>* tree = new BinTreeNode<int>(10);
	vector<int> v;
	vector<int> t1{ 10, 6, 3 };
	vector<int> t2{ 10, 6, 3 };
	vector<int> t3{ 3, 6, 10 };
	vector<int> t4{ 10, 6, 3 };
	vector<int> t5{ 3, 6, 10 };
	vector<int> t6{ 3, 6, 10 };
	/*
	*                   10
	*               6       
	*             3
	*/
	insert(6, tree);
	insert(3, tree->left);
	
	// ������
	path(tree, nlr, v);
	assert(v == t1);
	v.clear();

	path(tree, nrl, v);
	assert(v == t2);
	v.clear();

	path(tree, lnr, v);
	assert(v == t3);
	v.clear();

	path(tree, rnl, v);
	assert(v == t4);
	v.clear();

	path(tree, lrn, v);
	assert(v == t5);
	v.clear();

	path(tree, rln, v);
	assert(v == t6);
	v.clear();

	path(tree, iter, v);
	assert(v == t1);
	v.clear();

	//��������� ������
	int i = in(tree);
	assert(i == 10);

	//���������� � �������
	assert(count(tree) == 3);
	assert(depth(tree) == 2);

	//�����
	assert(find(3, tree) == 3);
	//����� �� �������������
	try
	{
		int i = find(100, tree);
		assert(false);
	}
	catch (out_of_range)
	{

	}


	// �������� �� �������������
	removeNode(tree, 100);
	path(tree, nlr, v);
	assert(v == t1);
	v.clear();

	// �������� � ����� ��������
	removeNode(tree, 6);
	path(tree, nlr, v);
	vector<int> t8{ 10, 3 };
	assert(v == t8);
	v.clear();

	// �������� ��� ��������
	removeNode(tree, 3);
	path(tree, nlr, v);
	vector<int> t7{ 10 };
	assert(v == t7);
	v.clear();

	// �������
	insertintree(1, tree);
	path(tree, nlr, v);
	vector<int> t10{ 10, 1 };
	assert(v == t10);
	v.clear();

	//�������� ������
	deletetree(tree);
	tree = nullptr;
	path(tree, nlr, v);
	vector<int> t11;
	assert(v == t11);
}