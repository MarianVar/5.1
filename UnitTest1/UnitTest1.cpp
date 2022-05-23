#include "pch.h"
#include "CppUnitTest.h"
#include "../5.1/5.1.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int v = 0;
			Assert::AreEqual(Process("f.dat", "t.dat"), v);
		}
	};
}
