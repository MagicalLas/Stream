#include "stdafx.h"
#include "CppUnitTest.h"
#include<vector>
#include"../Stream/Stream.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SparkStream
{
	using namespace LaStream;
	TEST_CLASS(TestStream)
	{
		Stream<int> stream;
	public:
		TEST_METHOD(StreamMakeVoidConstructor)
		{
			Stream<int> AStream;
			Assert::IsNotNull(&AStream);
		}

		TEST_METHOD(StramCanJoinVector) {
			std::vector<int> vec = {0,1,2,3,4};
			stream = Stream<int>(vec);
			Assert::IsNotNull(&stream);
		}


	}; 
	TEST_CLASS(TestNYPC)
	{
	public:
		TEST_METHOD(forFirst)
		{
			auto a = 9; auto b = 7;
			auto n = 55;
			int count = 0;
			for (size_t i = 0; i < n/a+1; i++)
			{
				if ((n - a * i) %b == 0) {
					count = i;
					break;
				}
			}
			Assert::AreEqual(count,3);
		}

		TEST_METHOD(StramCanJoinVector) {
		}


	};
}