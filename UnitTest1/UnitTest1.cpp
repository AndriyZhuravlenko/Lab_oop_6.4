#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\LEGION\source\repos\Lab_oop_6.4\Lab_oop_6.4\Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Matrix<int> m(2);
			m[0] = 1, m[1] = 3;
			int a;
			a = m.getSize();
			Assert::AreEqual(a, 2);
		}
	};
}
