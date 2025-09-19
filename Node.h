#pragma once
#include <iostream>
#include <functional>
#include <stack>
#include <vector>

/// <summary>
/// Перечисление для различных способов обхода бинарного дерева
/// </summary>
enum class PATHS { nlr, nrl, lnr, rnl, lrn, rln, iter };

using enum PATHS; // Использование перечисления PATHS для упрощения доступа к его значениям

using namespace std; // Использование стандартного пространства имен для упрощения кода

/// <summary>
/// Класс узла бинарного дерева
/// </summary>
/// <typeparam name="T">Тип данных, хранимых в узле</typeparam>
template <typename T>
class BinTreeNode
{
public:
	BinTreeNode* left; // Указатель на левый дочерний узел
	BinTreeNode* right; // Указатель на правый дочерний узел
	T data; // Данные, хранимые в узле

	/// <summary>
	/// Конструктор по умолчанию
	/// </summary>
	BinTreeNode()
	{
		data = NULL; // Инициализация данных значением nullptr
		left = nullptr; // Инициализация левого дочернего узла значением nullptr
		right = nullptr; // Инициализация правого дочернего узла значением nullptr
	}

	/// <summary>
	/// Конструктор с параметром данных
	/// </summary>
	/// <param name="data">Значение, которое будет храниться в узле</param>
	BinTreeNode(T data)
	{
		this->data = data; // Присваивание переданного значения данным узла
		left = nullptr; // Инициализация левого дочернего узла значением nullptr
		right = nullptr; // Инициализация правого дочернего узла значением nullptr
	}
};

/// <summary>
/// Обход дерева в прямом порядке (NLR: узел, левое поддерево, правое поддерево)
/// </summary>
/// <typeparam name="T">Тип данных узла</typeparam>
/// <param name="curr">Указатель на текущий узел</param>
template <typename T>
void NLR(const BinTreeNode<T>* curr)
{
	if (curr) // Проверка, существует ли текущий узел
	{
		cout << curr->data << " "; // Вывод данных текущего узла
		NLR(curr->left); // Рекурсивный вызов для левого поддерева
		NLR(curr->right); // Рекурсивный вызов для правого поддерева
	}
}

/// <summary>
/// Обход дерева в прямом порядке с сохранением данных в вектор
/// </summary>
/// <typeparam name="T">Тип данных узла</typeparam>
/// <param name="curr">Указатель на текущий узел</param>
/// <param name="vec">Вектор для хранения данных</param>
template <typename T>
void NLR(const BinTreeNode<T>* curr, vector<T>& vec)
{
	if (curr) // Проверка, существует ли текущий узел
	{
		vec.push_back(curr->data); // Добавление данных текущего узла в вектор
		NLR(curr->left, vec); // Рекурсивный вызов для левого поддерева
		NLR(curr->right, vec); // Рекурсивный вызов для правого поддерева
	}
}

/// <summary>
/// Обход дерева в обратном прямом порядке (NRL: узел, правое поддерево, левое поддерево)
/// </summary>
/// <typeparam name="T">Тип данных узла</typeparam>
/// <param name="curr">Указатель на текущий узел</param>
template <typename T>
void NRL(const BinTreeNode<T>* curr)
{
	if (curr) // Проверка, существует ли текущий узел
	{
		cout << curr->data << " "; // Вывод данных текущего узла
		NRL(curr->right); // Рекурсивный вызов для правого поддерева
		NRL(curr->left); // Рекурсивный вызов для левого поддерева
	}
}

/// <summary>
/// Обход дерева в обратном прямом порядке с сохранением данных в вектор
/// </summary>
/// <typeparam name="T">Тип данных узла</typeparam>
/// <param name="curr">Указатель на текущий узел</param>
/// <param name="vec">Вектор для хранения данных</param>
template <typename T>
void NRL(const BinTreeNode<T>* curr, vector<T>& vec)
{
	if (curr) // Проверка, существует ли текущий узел
	{
		vec.push_back(curr->data); // Добавление данных текущего узла в вектор
		NRL(curr->right, vec); // Рекурсивный вызов для правого поддерева
		NRL(curr->left, vec); // Рекурсивный вызов для левого поддерева
	}
}

/// <summary>
/// Обход дерева в симметричном порядке (LNR: левое поддерево, узел, правое поддерево)
/// </summary>
/// <typeparam name="T">Тип данных узла</typeparam>
/// <param name="curr">Указатель на текущий узел</param>
template <typename T>
void LNR(const BinTreeNode<T>* curr)
{
	if (curr) // Проверка, существует ли текущий узел
	{
		LNR(curr->left); // Рекурсивный вызов для левого поддерева
		cout << curr->data << " "; // Вывод данных текущего узла
		LNR(curr->right); // Рекурсивный вызов для правого поддерева
	}
}

/// <summary>
/// Обход дерева в симметричном порядке с сохранением данных в вектор
/// </summary>
/// <typeparam name="T">Тип данных узла</typeparam>
/// <param name="curr">Указатель на текущий узел</param>
/// <param name="vec">Вектор для хранения данных</param>
template <typename T>
void LNR(const BinTreeNode<T>* curr, vector<T>& vec)
{
	if (curr) // Проверка, существует ли текущий узел
	{
		LNR(curr->left, vec); // Рекурсивный вызов для левого поддерева
		vec.push_back(curr->data); // Добавление данных текущего узла в вектор
		LNR(curr->right, vec); // Рекурсивный вызов для правого поддерева
	}
}

/// <summary>
/// Обход дерева в обратном симметричном порядке (RNL: правое поддерево, узел, левое поддерево)
/// </summary>
/// <typeparam name="T">Тип данных узла</typeparam>
/// <param name="curr">Указатель на текущий узел</param>
template <typename T>
void RNL(const BinTreeNode<T>* curr)
{
	if (curr) // Проверка, существует ли текущий узел
	{
		RNL(curr->right); // Рекурсивный вызов для правого поддерева
		cout << curr->data << " "; // Вывод данных текущего узла
		RNL(curr->left); // Рекурсивный вызов для левого поддерева
	}
}

/// <summary>
/// Обход дерева в обратном симметричном порядке с сохранением данных в вектор
/// </summary>
/// <typeparam name="T">Тип данных узла</typeparam>
/// <param name="curr">Указатель на текущий узел</param>
/// <param name="vec">Вектор для хранения данных</param>
template <typename T>
void RNL(const BinTreeNode<T>* curr, vector<T>& vec)
{
	if (curr) // Проверка, существует ли текущий узел
	{
		RNL(curr->right, vec); // Рекурсивный вызов для правого поддерева
		vec.push_back(curr->data); // Добавление данных текущего узла в вектор
		RNL(curr->left, vec); // Рекурсивный вызов для левого поддерева
	}
}

/// <summary>
/// Обход дерева в обратном порядке (LRN: левое поддерево, правое поддерево, узел)
/// </summary>
/// <typeparam name="T">Тип данных узла</typeparam>
/// <param name="curr">Указатель на текущий узел</param>
template <typename T>
void LRN(const BinTreeNode<T>* curr)
{
	if (curr) // Проверка, существует ли текущий узел
	{
		LRN(curr->left); // Рекурсивный вызов для левого поддерева
		LRN(curr->right); // Рекурсивный вызов для правого поддерева
		cout << curr->data << " "; // Вывод данных текущего узла
	}
}

/// <summary>
/// Обход дерева в обратном порядке с сохранением данных в вектор
/// </summary>
/// <typeparam name="T">Тип данных узла</typeparam>
/// <param name="curr">Указатель на текущий узел</param>
/// <param name="vec">Вектор для хранения данных</param>
template <typename T>
void LRN(const BinTreeNode<T>* curr, vector<T>& vec)
{
	if (curr) // Проверка, существует ли текущий узел
	{
		LRN(curr->left, vec); // Рекурсивный вызов для левого поддерева
		LRN(curr->right, vec); // Рекурсивный вызов для правого поддерева
		vec.push_back(curr->data); // Добавление данных текущего узла в вектор
	}
}

/// <summary>
/// Обход дерева в обратном порядке (RLN: правое поддерево, левое поддерево, узел)
/// </summary>
/// <typeparam name="T">Тип данных узла</typeparam>
/// <param name="curr">Указатель на текущий узел</param>
template <typename T>
void RLN(const BinTreeNode<T>* curr)
{
	if (curr) // Проверка, существует ли текущий узел
	{
		RLN(curr->right); // Рекурсивный вызов для правого поддерева
		RLN(curr->left); // Рекурсивный вызов для левого поддерева
		cout << curr->data << " "; // Вывод данных текущего узла
	}
}

/// <summary>
/// Обход дерева в обратном порядке с сохранением данных в вектор
/// </summary>
/// <typeparam name="T">Тип данных узла</typeparam>
/// <param name="curr">Указатель на текущий узел</param>
/// <param name="vec">Вектор для хранения данных</param>
template <typename T>
void RLN(const BinTreeNode<T>* curr, vector<T>& vec)
{
	if (curr) // Проверка, существует ли текущий узел
	{
		RLN(curr->right, vec); // Рекурсивный вызов для правого поддерева
		RLN(curr->left, vec); // Рекурсивный вызов для левого поддерева
		vec.push_back(curr->data); // Добавление данных текущего узла в вектор
	}
}

/// <summary>
/// Итеративный обход дерева в прямом порядке с использованием стека
/// </summary>
/// <typeparam name="T">Тип данных узла</typeparam>
/// <param name="curr">Указатель на текущий узел</param>
template <typename T>
void iterPath(const BinTreeNode<T>* curr)
{
	if (curr) // Проверка, существует ли текущий узел
	{
		const BinTreeNode<T>* temp; // Временный указатель на узел
		stack<const BinTreeNode<T>* > s; // Стек для хранения узлов
		s.push(curr); // Добавление текущего узла в стек
		while (!s.empty()) // Пока стек не пуст
		{
			temp = s.top(); // Получение верхнего узла из стека
			s.pop(); // Удаление верхнего узла из стека
			cout << temp->data << " "; // Вывод данных текущего узла
			if (temp->right) // Если существует правое поддерево
				s.push(temp->right); // Добавление правого узла в стек
			if (temp->left) // Если существует левое поддерево
				s.push(temp->left); // Добавление левого узла в стек
		}
	}
}

/// <summary>
/// Итеративный обход дерева в прямом порядке с сохранением данных в вектор
/// </summary>
/// <typeparam name="T">Тип данных узла</typeparam>
/// <param name="curr">Указатель на текущий узел</param>
/// <param name="vec">Вектор для хранения данных</param>
template <typename T>
void iterPath(const BinTreeNode<T>* curr, vector<T>& vec)
{
	if (curr) // Проверка, существует ли текущий узел
	{
		const BinTreeNode<T>* temp; // Временный указатель на узел
		stack<const BinTreeNode<T>* > s; // Стек для хранения узлов
		s.push(curr); // Добавление текущего узла в стек
		while (!s.empty()) // Пока стек не пуст
		{
			temp = s.top(); // Получение верхнего узла из стека
			s.pop(); // Удаление верхнего узла из стека
			vec.push_back(temp->data); // Добавление данных текущего узла в вектор
			if (temp->right) // Если существует правое поддерево
				s.push(temp->right); // Добавление правого узла в стек
			if (temp->left) // Если существует левое поддерево
				s.push(temp->left); // Добавление левого узла в стек
		}
	}
}

/// <summary>
/// Выбор способа обхода дерева
/// </summary>
/// <typeparam name="T">Тип данных узла</typeparam>
/// <param name="curr">Указатель на текущий узел</param>
/// <param name="choice">Тип обхода (из перечисления PATHS)</param>
template <typename T>
void path(const BinTreeNode<T>* curr, PATHS choice)
{
	switch (choice) // Выбор способа обхода
	{
	case (PATHS)0: // NLR
		NLR<T>(curr); // Вызов прямого обхода
		break;
	case (PATHS)1: // NRL
		NRL<T>(curr); // Вызов обратного прямого обхода
		break;
	case (PATHS)2: // LNR
		LNR<T>(curr); // Вызов симметричного обхода
		break;
	case (PATHS)3: // RNL
		RNL<T>(curr); // Вызов обратного симметричного обхода
		break;
	case (PATHS)4: // LRN
		LRN<T>(curr); // Вызов обратного обхода
		break;
	case (PATHS)5: // RLN
		RLN<T>(curr); // Вызов обратного обхода (RLN)
		break;
	case (PATHS)6: // iter
		iterPath(curr); // Вызов итеративного обхода
		break;
	}
}


/// <summary>
/// Выбор способа обхода дерева с сохранением данных в вектор
/// </summary>
/// <typeparam name="T">Тип данных узла</typeparam>
/// <param name="curr">Указатель на текущий узел</param>
/// <param name="choice">Тип обхода (из перечисления PATHS)</param>
/// <param name="vec">Вектор для хранения данных</param>
template <typename T>
void path(const BinTreeNode<T>* curr, PATHS choice, vector<T>& vec)
{
	switch (choice) // Выбор способа обхода
	{
	case (PATHS)0: // NLR
		NLR<T>(curr, vec); // Вызов прямого обхода с сохранением в вектор
		break;
	case (PATHS)1: // NRL
		NRL<T>(curr, vec); // Вызов обратного прямого обхода с сохранением в вектор
		break;
	case (PATHS)2: // LNR
		LNR<T>(curr, vec); // Вызов симметричного обхода с сохранением в вектор
		break;
	case (PATHS)3: // RNL
		RNL<T>(curr, vec); // Вызов обратного симметричного обхода с сохранением в вектор
		break;
	case (PATHS)4: // LRN
		LRN<T>(curr, vec); // Вызов обратного обхода с сохранением в вектор
		break;
	case (PATHS)5: // RLN
		RLN<T>(curr, vec); // Вызов обратного обхода (RLN) с сохранением в вектор
		break;
	case (PATHS)6: // iter
		iterPath(curr, vec); // Вызов итеративного обхода с сохранением в вектор
		break;
	}
}

/// <summary>
/// Вставка нового узла в дерево
/// </summary>
/// <typeparam name="T">Тип данных узла</typeparam>
/// <param name="data">Данные для вставки</param>
/// <param name="tree">Указатель на корень дерева</param>
template <typename T>
void insert(T data, BinTreeNode<T>* tree)
{
	if (tree == nullptr) // Если дерево пустое
	{
		tree = new BinTreeNode<T>(data); // Создание нового узла с данными
		return; // Завершение функции
	}
	if (tree->left == nullptr) // Если левый дочерний узел отсутствует
	{
		tree->left = new BinTreeNode<T>(data); // Создание левого узла
		return; // Завершение функции
	}
	else // Если левый узел занят
	{
		tree->right = new BinTreeNode<T>(data); // Создание правого узла
		return; // Завершение функции
	}
}

/// <summary>
/// Вставка нового узла в бинарное дерево поиска
/// </summary>
/// <typeparam name="T">Тип данных узла</typeparam>
/// <param name="data">Данные для вставки</param>
/// <param name="curr">Указатель на текущий узел</param>
/// <returns>Указатель на корень поддерева</returns>
template <typename T>
BinTreeNode<T>* insertintree(T data, BinTreeNode<T>* curr)
{
	if (curr == nullptr) // Если текущий узел пустой
	{
		return new BinTreeNode<T>(data); // Создание нового узла
	}
	if (data < curr->data) // Если данные меньше текущего узла
	{
		curr->left = insertintree<T>(data, curr->left); // Рекурсивная вставка в левое поддерево
	}
	if (data > curr->data) // Если данные больше текущего узла
	{
		curr->right = insertintree<T>(data, curr->right); // Рекурсивная вставка в правое поддерево
	}
	return curr; // Возврат указателя на текущий узел
}

/// <summary>
/// Создание бинарного дерева поиска из вектора
/// </summary>
/// <typeparam name="T">Тип данных узла</typeparam>
/// <param name="vec">Вектор с данными</param>
/// <returns>Указатель на корень созданного дерева</returns>
template <typename T>
BinTreeNode<T>* treefromvector(vector<T>& vec)
{
	BinTreeNode<T>* curr = nullptr; // Инициализация пустого дерева
	for (T data : vec) // Для каждого элемента вектора
	{
		curr = insertintree(data, curr); // Вставка данных в дерево
	}
	return curr; // Возврат указателя на корень дерева
}


/// <summary>
/// Удаление дерева и освобождение памяти
/// </summary>
/// <typeparam name="T">Тип данных узла</typeparam>
/// <param name="curr">Указатель на текущий узел</param>
template <typename T>
void deletetree(BinTreeNode<T>* curr)
{
	if (curr) // Проверка, существует ли текущий узел
	{
		deletetree(curr->left); // Рекурсивное удаление левого поддерева
		deletetree(curr->right); // Рекурсивное удаление правого поддерева
		delete curr; // Освобождение памяти текущего узла
	}
}

/// <summary>
/// Получение данных текущего узла
/// </summary>
/// <typeparam name="T">Тип данных узла</typeparam>
/// <param name="curr">Указатель на текущий узел</param>
/// <returns>Данные узла</returns>
template <typename T>
T in(const BinTreeNode<T>* curr)
{
	if (curr) // Проверка, существует ли текущий узел
	{
		return curr->data; // Возврат данных узла
	}
	throw out_of_range("Пустое дерево"); // Выброс исключения, если узел пустой
}

/// <summary>
/// Подсчет количества узлов в дереве
/// </summary>
/// <typeparam name="T">Тип данных узла</typeparam>
/// <param name="curr">Указатель на текущий узел</param>
/// <returns>Количество узлов</returns>
template <typename T>
size_t count(BinTreeNode<T>* curr)
{
	if (curr == nullptr) // Если узел пустой
	{
		return 0; // Возврат 0
	}
	return 1 + count<T>(curr->left) + count<T>(curr->right); // Подсчет узлов в текущем узле и поддеревьях
}

/// <summary>
/// Вычисление глубины дерева
/// </summary>
/// <typeparam name="T">Тип данных узла</typeparam>
/// <param name="curr">Указатель на текущий узел</param>
/// <returns>Глубина дерева</returns>
template <typename T>
int depth(BinTreeNode<T>* curr)
{
	if (curr == nullptr) // Если узел пустой
	{
		return -1; // Возврат -1 (пустое дерево)
	}
	int left = depth<T>(curr->left); // Вычисление глубины левого поддерева
	int right = depth<T>(curr->right); // Вычисление глубины правого поддерева
	return max(left, right) + 1; // Возврат максимальной глубины + 1
}

/// <summary>
/// Поиск узла с заданными данными
/// </summary>
/// <typeparam name="T">Тип данных узла</typeparam>
/// <param name="data">Искомые данные</param>
/// <param name="curr">Указатель на текущий узел</param>
/// <returns>Данные найденного узла</returns>
template <typename T>
T find(T data, BinTreeNode<T>* curr)
{
	if (curr == nullptr) // Если узел пустой
	{
		throw out_of_range("Нет такого элемента"); // Выброс исключения
	}
	if (data == curr->data) // Если данные найдены
	{
		return curr->data; // Возврат данных узла
	}
	if (data < curr->data) // Если данные меньше текущего узла
	{
		return find<T>(data, curr->left); // Рекурсивный поиск в левом поддереве
	}
	if (data > curr->data) // Если данные больше текущего узла
	{
		return find<T>(data, curr->right); // Рекурсивный поиск в правом поддереве
	}
}

/// <summary>
/// Поиск узла с минимальным значением данных
/// </summary>
/// <typeparam name="T">Тип данных узла</typeparam>
/// <param name="curr">Указатель на текущий узел</param>
/// <returns>Указатель на узел с минимальным значением</returns>
template <typename T>
BinTreeNode<T>* minDataNode(BinTreeNode<T>* curr)
{
	BinTreeNode<T>* temp = curr; // Временный указатель на текущий узел
	while (temp && temp->left != nullptr) // Пока существует левый дочерний узел
	{
		temp = temp->left; // Переход к левому узлу
	}
	return temp; // Возврат указателя на узел с минимальным значением
}

/// <summary>
/// Удаление узла с заданными данными
/// </summary>
/// <typeparam name="T">Тип данных узла</typeparam>
/// <param name="curr">Указатель на текущий узел</param>
/// <param name="data">Данные для удаления</param>
/// <returns>Указатель на корень поддерева после удаления</returns>
template <typename T>
BinTreeNode<T>* removeNode(BinTreeNode<T>* curr, T data)
{
	if (curr == nullptr) // Если узел пустой
	{
		return curr; // Возврат nullptr
	}
	if (data < curr->data) // Если данные меньше текущего узла
	{
		curr->left = removeNode<T>(curr->left, data); // Рекурсивное удаление в левом поддереве
	}
	else if (data > curr->data) // Если данные больше текущего узла
	{
		curr->right = removeNode<T>(curr->right, data); // Рекурсивное удаление в правом поддереве
	}
	else // Если найден узел для удаления
	{
		BinTreeNode<T>* temp; // Временный указатель для хранения узла
		if (curr->left == nullptr) // Если нет левого поддерева
		{
			temp = curr->right; // Сохранение правого поддерева
			delete(curr); // Удаление текущего узла
			return temp; // Возврат правого поддерева
		}
		else if (curr->right == nullptr) // Если нет правого поддерева
		{
			temp = curr->left; // Сохранение левого поддерева
			delete(curr); // Удаление текущего узла
			return temp; // Возврат левого поддерева
		}
		// Если есть оба поддерева
		temp = minDataNode<T>(curr->right); // Поиск минимального узла в правом поддереве
		curr->data = temp->data; // Замена данных текущего узла
		curr->right = removeNode<T>(curr->right, temp->data); // Удаление минимального узла из правого поддерева
	}
	return curr; // Возврат указателя на текущий узел
}

/// <summary>
/// Функция применения функции к каждому узлу дерева
/// </summary>
/// <typeparam name="T">Тип данных узла</typeparam>
/// <param name="func">Функция для применения к узлу</param>
/// <param name="curr">Указатель на текущий узел</param>
template <typename T>
void NodeFunc(function<void(BinTreeNode<T>*)> func, BinTreeNode<T>* curr)
{
	if (curr) // если узел не пустой
	{
		func(curr); // примененяем функцию к текущему узлу
		NodeFunc(func, curr->left); // вызов функции к левому поддереву
		NodeFunc(func, curr->right); // вызов функции к правому поддереву
	}
}

/// <summary>
/// Функция копирования дерева из дерева
/// </summary>
/// <typeparam name="T">Тип данных узла</typeparam>
/// <param name="curr">Указатель на текущий узел</param>
/// <returns>Указатель на новое дерево</returns>
template <typename T>
BinTreeNode<T>* copyNodes(BinTreeNode<T>* curr)
{
	if (curr)
	{
		BinTreeNode<T>* temp = new BinTreeNode<T>();
		temp->data = curr->data;
		temp->left = copyNodes(curr->left);
		temp->right = copyNodes(curr->right);
		return temp;
	}
	return nullptr;
}

/// <summary>
/// Тестовая функция для проверки работы узла дерева
/// </summary>
void test();