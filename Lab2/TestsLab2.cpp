#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB2/Source.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace TestsLab2
{
	TEST_CLASS(TestsLab2)
	{
	public:
		//Тесты для всех веток, числа обозначают номер строки из кода
		TEST_METHOD(Main_test_TEST1)
		{
			Logger::WriteMessage(L"TEST1 (0, 0, 0, 0, 0, 0)");
			Assert::IsTrue(Method(0, 0, 0, 0, 0, 0) == "5", L"Assert");
			Logger::WriteMessage(L"13 passed!");
		}

		TEST_METHOD(Main_test_TEST2)
		{
			Logger::WriteMessage(L"TEST2 (1, 0, 0, 1, 0, 1)");
			Assert::IsTrue(Method(1, 0, 0, 1, 0, 1) == "2 " + to_string(0.0) + " " + to_string(1.0), L"Assert");
			Logger::WriteMessage(L"19 passed!");
		}

		TEST_METHOD(Main_test_TEST3)
		{
			Logger::WriteMessage(L"TEST3 (0, 0, 0, 1, 0, 1)");
			Assert::IsTrue(Method(0, 0, 0, 1, 0, 1) == "4 " + to_string(1.0), L"Assert");
			Logger::WriteMessage(L"31 passed!");
		}

		TEST_METHOD(Main_test_TEST4)
		{
			Logger::WriteMessage(L"TEST4 (0, 1, 0, 0, 1, 0)");
			Assert::IsTrue(Method(0, 1, 0, 0, 1, 0) == "4 " + to_string(1.0), L"Assert");
			Logger::WriteMessage(L"33 passed!");
		}

		TEST_METHOD(Main_test_TEST5)
		{
			Logger::WriteMessage(L"TEST5 (0, 0, 0, 1, 0, 0)");
			Assert::IsTrue(Method(0, 0, 0, 1, 0, 0) == "4 " + to_string(0.0), L"Assert");
			Logger::WriteMessage(L"35 passed!");
		}

		TEST_METHOD(Main_test_TEST6)
		{
			Logger::WriteMessage(L"TEST6 (0, 0, 1, 0, 0, 0)");
			Assert::IsTrue(Method(0, 0, 1, 0, 0, 0) == "3 " + to_string(0.0), L"Assert");
			Logger::WriteMessage(L"43 passed!");
		}

		TEST_METHOD(Main_test_TEST7)
		{
			Logger::WriteMessage(L"TEST7 (1, 0, 0, 0, 5, 0)");
			Assert::IsTrue(Method(1, 0, 0, 0, 5, 0) == "3 " + to_string(5.0), L"Assert");
			Logger::WriteMessage(L"45 passed!");
		}

		TEST_METHOD(Main_test_TEST8)
		{
			Logger::WriteMessage(L"TEST8 (1, 0, 1, 0, 0, 0)");
			Assert::IsTrue(Method(1, 0, 1, 0, 0, 0) == "3 " + to_string(0.0), L"Assert");
			Logger::WriteMessage(L"47 passed!");
		}

		TEST_METHOD(Main_test_TEST9)
		{
			Logger::WriteMessage(L"TEST9 (0, 0, 0, 0, 1, 1)");
			Assert::IsTrue(Method(0, 0, 0, 0, 1, 1) == "0", L"Assert");
			Logger::WriteMessage(L"51 passed!");
		}

		TEST_METHOD(Main_test_TEST10)
		{
			Logger::WriteMessage(L"TEST10 (0, 0, 0, 1, 0, 1)");
			Assert::IsTrue(Method(0, 0, 0, 1, 0, 1) == "4 " + to_string(1.0), L"Assert");
			Logger::WriteMessage(L"57 passed!");
		}

		TEST_METHOD(Main_test_TEST11)
		{
			Logger::WriteMessage(L"TEST11 (0, 1, 0, 0, 3, 0)");
			Assert::IsTrue(Method(0, 1, 0, 0, 3, 0) == "4 " + to_string(3.0), L"Assert");
			Logger::WriteMessage(L"59 passed!");
		}

		TEST_METHOD(Main_test_TEST12)
		{
			Logger::WriteMessage(L"TEST12 (0, 1, 0, 1, 3, 3)");
			Assert::IsTrue(Method(0, 1, 0, 1, 3, 3) == "4 " + to_string(3.0), L"Assert");
			Logger::WriteMessage(L"61 passed!");
		}

		TEST_METHOD(Main_test_TEST13)
		{
			Logger::WriteMessage(L"TEST13 (0, 0, 1, 0, 0, 11)");
			Assert::IsTrue(Method(0, 0, 1, 0, 0, 11) == "3 " + to_string(11.0), L"Assert");
			Logger::WriteMessage(L"68 passed!");
		}

		TEST_METHOD(Main_test_TEST14)
		{
			Logger::WriteMessage(L"TEST14 (11, 0, 0, 0, 121, 0)");
			Assert::IsTrue(Method(11, 0, 0, 0, 121, 0) == "3 " + to_string(11.0) , L"Assert");
			Logger::WriteMessage(L"70 passed!");
		}

		TEST_METHOD(Main_test_TEST15)
		{
			Logger::WriteMessage(L"TEST15 (8, 0, 4, 0, 4, 2)");
			Assert::IsTrue(Method(8, 0, 4, 0, 4, 2) == "3 " + to_string(0.5), L"Assert");
			Logger::WriteMessage(L"72 passed!");
		}

		TEST_METHOD(Main_test_TEST16)
		{
			Logger::WriteMessage(L"TEST16 (1, 0, 1, 1, 0, 0)");
			Assert::IsTrue(Method(1, 0, 1, 1, 0, 0) == "1 " + to_string(-1.0) + " " + to_string(0.0), L"Assert");
			Logger::WriteMessage(L"80 passed!");
		}

		TEST_METHOD(Main_test_TEST17)
		{
			Logger::WriteMessage(L"TEST17 (1, 1, 1, 0, 0 ,0)");
			Assert::IsTrue(Method(1, 1, 1, 0, 0 ,0) == "1 " + to_string( -1.0) + " " + to_string(0.0), L"Assert");
			Logger::WriteMessage(L"87 passed!");
		}
		TEST_METHOD(Main_test_TEST18)
		{
			Logger::WriteMessage(L"TEST18 (0, 2, 20, 1, 0, 0)");
			Assert::IsTrue(Method(0, 2, 20, 1, 0, 0) == "1 " + to_string(-0.05) + " " + to_string(0.0), L"Assert");
			Logger::WriteMessage(L"94 passed!");
		}

		TEST_METHOD(Main_test_TEST19)
		{
			Logger::WriteMessage(L"TEST19 (10, 10, 0, 2, 0, 0)");
			Assert::IsTrue(Method(10, 10, 0, 2, 0, 0) == "1 " + to_string(-1.0) + " " + to_string(0.0), L"Assert");
			Logger::WriteMessage(L"101 passed!");
		}

		TEST_METHOD(Main_test_TEST20)
		{
			Logger::WriteMessage(L"TEST20 (20, 20, 10, 10, 0, 0)");
			Assert::IsTrue(Method(20, 20, 10, 10, 0, 0) == "1 " + to_string(-1.0) + " " + to_string(0.0), L"Assert");
			Logger::WriteMessage(L"108 passed!");
		}

		TEST_METHOD(Main_test_TEST21)
		{
			Logger::WriteMessage(L"TEST21 (20, 20, 10, 9, 0, 0)");
			Assert::IsTrue(Method(20, 20, 10, 9, 0, 0) == "Are you kidding me?");
			Logger::WriteMessage(L"final passed!");
		}
		
		//ложные тесты

		TEST_METHOD(Additional_test_TEST1)
		{
			Logger::WriteMessage(L"A_TEST1 (20, 20, 10, 10, 0, 0)");
			Assert::IsTrue(Method(0, 0, 0, 0, 0, 0) != "1 ", L"Assert");
			Logger::WriteMessage(L"A_TEST1 passed!");
		}

		TEST_METHOD(Additional_test_TEST2)
		{
			Logger::WriteMessage(L"A_TEST2 (20, 20, 10, 10, 0, 0)");
			Assert::IsTrue(Method(5, 6, 1, 3, 0, 1) != "2 " + to_string(-1.0) + " " + to_string(2.0), L"Assert");
			Logger::WriteMessage(L"A_TEST2 passed!");
		}

		TEST_METHOD(Additional_test_TEST3)
		{
			Logger::WriteMessage(L"A_TEST3 (20, 20, 10, 10, 0, 0)");
			Assert::IsTrue(Method(1, 2, 3, 4, 5, 6) != "0 " + to_string(0.0) + " " + to_string(0.35), L"Assert");
			Logger::WriteMessage(L"A_TEST3 passed!");
		}

		TEST_METHOD(Additional_test_TEST4)
		{
			Logger::WriteMessage(L"A_TEST4 (20, 20, 10, 10, 0, 0)");
			Assert::IsTrue(Method(1, 0, 1, 0, 3, 0) != "3 " + to_string(-5.0) + " " + to_string(0.0), L"Assert");
			Logger::WriteMessage(L"A_TEST4 passed!");
		}

		TEST_METHOD(Additional_test_TEST5)
		{
			Logger::WriteMessage(L"A_TEST5 (20, 20, 10, 10, 0, 0)");
			Assert::IsTrue(Method(15, 15, 15, 15, 15, 15) != "2 " + to_string(-4.0) + " " + to_string(1.0), L"Assert");
			Logger::WriteMessage(L"A_TEST5 passed!");
		}
	};
}
