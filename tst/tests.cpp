#include <gtest/gtest.h>
#include "LinkedList.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <utility>

using namespace std;

template <typename T>
vector<T> To_vector(const LinkedList<T>& list) {
	vector<T> result;
	for (auto node = list.get_head(); node; node = node->next) {
		result.push_back(node->value);
	}
	return result;
}

TEST(Test_reverse, Empty_list) {
	vector<int> vect = {};
	LinkedList<int> list;
	list.reverse();
	EXPECT_EQ(vect, To_vector(list));
}

TEST(Test_reverse, Full_list) {
	vector<int> vect = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	LinkedList<int> list;
	for (int i = 0; i < 10; ++i) {
		list.push_front(i);
	}
	list.reverse();
	EXPECT_EQ(vect, To_vector(list));
}

TEST(Test_reverse, Lists_in_a_list) {
	vector<vector<int>> vect = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
	LinkedList<LinkedList<int>> list;
	LinkedList<int> list_1, list_2, list_3;
	for (int i = 3; i > 0; --i) {
		list_1.push_front(i);
	}
	for (int i = 6; i > 3; --i) {
		list_2.push_front(i);
	}
	for (int i = 9; i > 6; --i) {
		list_3.push_front(i);
	}
	list.push_front(move(list_1));
	list.push_front(move(list_2));
	list.push_front(move(list_3));
	list.reverse();
	EXPECT_EQ(vect[0], To_vector(list.get_head()->value));
	EXPECT_EQ(vect[1], To_vector(list.get_head()->next->value));
	EXPECT_EQ(vect[2], To_vector(list.get_head()->next->next->value));
}

TEST(Test_recursion_reverse, Empty_list) {
	vector<int> vect = {};
	LinkedList<int> list;
	list.recursion_reverse();
	EXPECT_EQ(vect, To_vector(list));
}

TEST(Test_recursion_reverse, Full_list) {
	vector<int> vect = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	LinkedList<int> list;
	for (int i = 0; i < 10; ++i) {
		list.push_front(i);
	}
	list.recursion_reverse();
	EXPECT_EQ(vect, To_vector(list));
}

TEST(Test_recursion_reverse, Lists_in_a_list) {
	vector<vector<int>> vect = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
	LinkedList<LinkedList<int>> list;
	LinkedList<int> list_1, list_2, list_3;
	for (int i = 3; i > 0; --i) {
		list_1.push_front(i);
	}
	for (int i = 6; i > 3; --i) {
		list_2.push_front(i);
	}
	for (int i = 9; i > 6; --i) {
		list_3.push_front(i);
	}
	list.push_front(move(list_1));
	list.push_front(move(list_2));
	list.push_front(move(list_3));
	list.recursion_reverse();
	EXPECT_EQ(vect[0], To_vector(list.get_head()->value));
	EXPECT_EQ(vect[1], To_vector(list.get_head()->next->value));
	EXPECT_EQ(vect[2], To_vector(list.get_head()->next->next->value));
}

TEST(Test_push_and_pop_front, Test_1) {
	vector<int> vect = {};
	LinkedList<int> list;
	EXPECT_EQ(vect, To_vector(list));

	vect.insert(vect.begin(), 1);
	list.push_front(1);
	EXPECT_EQ(vect, To_vector(list));

	vect.insert(vect.begin(), 2);
	list.push_front(2);
	EXPECT_EQ(vect, To_vector(list));

	vect.erase(vect.begin());
	list.pop_front();
	EXPECT_EQ(vect, To_vector(list));

	vect.erase(vect.begin());
	list.pop_front();
	EXPECT_EQ(vect, To_vector(list));

	list.pop_front();
	EXPECT_EQ(vect, To_vector(list));
}

TEST(Container_Iteration_Test, Test_1) {
	LinkedList<int> list;
	vector<int> vect = {};
	stringstream ss_vect, ss_list;
	for (auto& now : vect) {
		ss_vect << (++now);
	}

	for (auto& now : list) {
		ss_list << (++now);
	}
	EXPECT_EQ(ss_list.str(), ss_vect.str());
}

TEST(Container_Iteration_Test, Test_2) {
	LinkedList<int> list;
	for (int i = 1; i < 6; ++i) {
		list.push_front(i);
	}
	list.reverse();
	vector<int> vect = { 1, 2, 3, 4, 5 };
	stringstream ss_vect, ss_list;
	for (auto& now : vect) {
		ss_vect << (++now);
	}
	for (auto& now : list) {
		ss_list << (++now);
	}
	EXPECT_EQ(ss_list.str(), ss_vect.str());

	for (auto& now : vect) {
		ss_vect << (now);
	}
	for (auto& now : list) {
		ss_list << (now);
	}
	EXPECT_EQ(ss_list.str(), ss_vect.str());
}
