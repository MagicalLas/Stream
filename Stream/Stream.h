// Stream.h : 표준 시스템 포함 파일,
// 또는 프로젝트 특정 포함 파일에 대한 파일을 포함합니다.

#pragma once

#include <iostream>
#include <vector>
#include <functional>

#include "/Stream/Build/Stream/FlowGraph.h"

namespace LaStream {
	template<class T>
	class Stream {
	private:

	public:
		Stream(std::vector<T> vector) {}
		Stream() {}
		Stream<T>& map(std::function<T(T)> f);

	};
}
// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.
