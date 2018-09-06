#pragma once
#include"Stream.h"

using namespace std;
template<class T>
struct Flow
{
	Flow * next;
	Stream<T> excute(Stream<T> s) { return next->excute(calc(s)); };
	Stream<T> calc(Stream<T> s) { return s; };
};

template<class T>
struct map : Flow<T>
{
	function<T(T)> func;
	map(function<T(T)> f) {
		func = f;
	}
	Flow<T> * flow() {
		return dynamic_cast<Flow<T>*>(this);
	}

	Stream<T> calc(Stream<T> s) { return s; };
};

template<class T>
struct fillter : Flow<T>
{
	function<bool(T)> func;
	fillter(function<bool(T)> f) {
		func = f;
	}
	Flow<T> * flow() {
		return dynamic_cast<Flow<T>*>(this);
	}
	Stream<T> calc(Stream<T> s) { return s; };
};