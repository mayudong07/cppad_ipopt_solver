/*
 * File:   OperatorTests.h
 * Author: yudong
 *
 * Created on Jul 14, 2015, 12:54:07 PM
 */

#ifndef OPERATORTESTS_H
#define	OPERATORTESTS_H

#include <cppunit/extensions/HelperMacros.h>
#include "../OptProblem.h"
#include "../Addition.h"
#include "../Division.h"
#include "../Exponential.h"
#include "../Logarithm.h"
#include "../Multiplication.h"
#include "../Power.h"
#include "../Subtraction.h"
#include "../ExpNodeADNumber.h"


class OperatorTests : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(OperatorTests);

    CPPUNIT_TEST(testCreateADNumber);
    CPPUNIT_TEST(testCreateTempADNumber);

    CPPUNIT_TEST_SUITE_END();

public:
    OperatorTests();
    virtual ~OperatorTests();
    void setUp();
    void tearDown();

private:
    void testCreateADNumber();
    void testCreateTempADNumber();
};

#endif	/* OPERATORTESTS_H */

