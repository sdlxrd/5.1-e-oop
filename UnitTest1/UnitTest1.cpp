#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\Misha\source\repos\5.1 e oop\5.1 e oop\Money.cpp"
#include "C:\Users\Misha\source\repos\5.1 e oop\5.1 e oop\Object.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Money a(15, 50), b(14, 90);
			double x = Object::Count();
			Assert::AreEqual(x, 2.);
		}
	};
}
