#include <cassert>
#include "Node.h"

using namespace std;

/// <summary>
/// Тестовая функция для проверки работы узла дерева
/// </summary>
void test()
{
	// проверка конструктора с параметрами, функции insert
	BinTreeNode<int>* tree1 = new BinTreeNode<int>(5);
	assert(tree1->data == 5);
	insert(6, tree1);
	assert(tree1->left->data = 6);
	insert(9, tree1);
	assert(tree1->right->data = 9);
	deletetree(tree1);

	// проверки копирования из вектора в бдп, сохранения в вектор проходами
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

	assert(count(tree2) == 7); // проверка количества узлов и глубина дерева
	assert(depth(tree2) == 3);

	// проверка поиска в бдп
	assert(find(15, tree2) == 15); // элемент есть
	try // нет элемента
	{
		find(100, tree2);
		assert(false);
	}
	catch (out_of_range)
	{

	}

	// удаление из дерева
	removeNode(tree2, 15); // удаление с одним потомком
	vector<int> vect6{ 4, 5, 6, 9, 10, 13 };
	path(tree2, lnr, t1);
	assert(t1 == vect6);
	t1.clear();

	removeNode(tree2, 5); // удаление с двумя потомками
	vector<int> vect7{ 4, 6, 9, 10, 13 };
	path(tree2, lnr, t1);
	assert(t1 == vect7);
	t1.clear();

	removeNode(tree2, 13); // удаление без потомком
	vector<int> vect8{4, 6, 9, 10};
	path(tree2, lnr, t1);
	assert(t1 == vect8);
	t1.clear();

	removeNode(tree2, 100); // удаление несущ. элемента
	path(tree2, lnr, t1);
	assert(t1 == vect8);
	t1.clear();

	BinTreeNode<int>* ctree = copyNodes(tree2); // проверка копирования дерева
	path(ctree, lnr, t1);
	assert(t1 == vect8);
	t1.clear();

	deletetree(ctree);
	deletetree(tree2);

	BinTreeNode<int>* tree3 = new BinTreeNode<int>(1);
	assert(count(tree3) == 1); // проверка количества узлов и глубина дерева
	assert(depth(tree3) == 0);
	assert(in(tree3) == 1); // проверка получения доступа к данным в узле
	deletetree(tree3);

	BinTreeNode<int>* tree4 = nullptr;
	assert(count(tree4) == 0); // проверка количества узлов и глубина дерева
	assert(depth(tree4) == -1);

	try // проверка получения доступа к данным в пустом узле
	{
		int i = in(tree4);
		assert(false);
	}
	catch (out_of_range)
	{

	}

}