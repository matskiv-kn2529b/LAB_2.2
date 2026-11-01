#include "pch.h"
#include "CppUnitTest.h"

#include "C:\\Users\\Mackiv\\source\\repos\\LAB_2.2\\LAB_2.2\\Integer.h"
#include "C:\\Users\\Mackiv\\source\\repos\\LAB_2.2\\LAB_2.2\\Integer.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace IntegerTests
{
    TEST_CLASS(IntegerTests)
    {
    public:

        TEST_METHOD(Power_PositiveExponent)
        {
            Integer result = Integer(2) ^ Integer(10);

            Assert::AreEqual(1024, result.GetX());
        }

        TEST_METHOD(Power_ZeroExponent)
        {
            Integer result = Integer(5) ^ Integer(0);

            Assert::AreEqual(1, result.GetX());
        }

        TEST_METHOD(Power_NegativeBase)
        {
            Integer result = Integer(-3) ^ Integer(3);

            Assert::AreEqual(-27, result.GetX());
        }

        TEST_METHOD(Power_NegativeExponent)
        {
            Integer result = Integer(2) ^ Integer(-3);

            Assert::AreEqual(0, result.GetX());
        }

        TEST_METHOD(PrimeNumber_ReturnsTrue)
        {
            Integer value(17);

            Assert::IsTrue(~value);
        }

        TEST_METHOD(CompositeNumber_ReturnsFalse)
        {
            Integer value(15);

            Assert::IsFalse(~value);
        }

        TEST_METHOD(DivisibilityOperator)
        {
            Integer value(24);

            Assert::IsTrue(value[2]);
            Assert::IsTrue(value[3]);
            Assert::IsFalse(value[5]);
        }
    };
}