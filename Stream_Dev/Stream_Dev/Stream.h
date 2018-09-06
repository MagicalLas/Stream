#pragma once
#include<functional>
#include<vector>
#include<iostream>
using namespace std;
template<class T>
struct Stream {
	vector<T> v;

	vector<function<T(T)>> maps;
	vector<function<bool(T)>> fillters;
	Stream(vector<T> vec) {
		v = vec;
	}
	Stream& map(function<T(T)> f) {
		this->maps.push_back(f);
		return *this;
	}
	Stream& fillter(function<bool(T)> f) {
		this->maps.push_back(f);
		return *this;
	}
	void action() {

		vector<T> v_;
		for (auto i = v.begin(); i != v.end(); i++) {
			T tmp = *i;
			for (size_t j = 0; j < maps.size(); j++)
			{
				tmp = maps[j](tmp);
			}
			v_.push_back(tmp);
		}

		v = v_;

	}
	T reduce(function<T(T, T)> f, T acc) {
		T accumulater = acc;
		action();
		for (auto i = v.begin(); i != v.end(); i++) {
			accumulater = f(accumulater, *i);
		}
		
		return accumulater;
	}
	T reduce(function<T(T, T)> f) {
		T accumulater = T();
		action();
		for (auto i = v.begin(); i != v.end(); i++) {
			accumulater = f(accumulater, *i);
		}

		return accumulater;
	}

};