#pragma once
#include<functional>
using namespace std;
template <class T>
struct flow
{
	function<T(T)> map;
	function<bool(T)> fillter;

	flow * next;
};