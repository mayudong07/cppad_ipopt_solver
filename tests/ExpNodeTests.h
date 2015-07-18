/*
 * File:   PackageTests.h
 * Author: yudong
 *
 * Created on Jul 8, 2015, 4:36:00 PM
 */

#ifndef PACKAGETESTS_H
#define	PACKAGETESTS_H

#include <cppunit/extensions/HelperMacros.h>

#include "../ActiveNode.h"
#include "../TempNode.h"
#include "../PassiveNode.h"
#include "../ExpNodeOperations.h"

#include "../Addition.h"
#include "../Division.h"
#include "../Exponential.h"
#include "../Logarithm.h"
#include "../Multiplication.h"
#include "../Power.h"
#include "../Subtraction.h"

class ExpNodeTests : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(ExpNodeTests);

    CPPUNIT_TEST(testMethod);
    CPPUNIT_TEST(testFailedMethod);
    CPPUNIT_TEST(testActiveNode);
    CPPUNIT_TEST(testPassiveNode);
    CPPUNIT_TEST(testTempNode);
    CPPUNIT_TEST(testOverloadedAddition);
    CPPUNIT_TEST(testOverloadedSub);
    CPPUNIT_TEST(testOverloadedMul);
    CPPUNIT_TEST(testOverloadedDiv);
    CPPUNIT_TEST(testOverloadedExp);
    CPPUNIT_TEST(testOverloadedLog);
    CPPUNIT_TEST(testOverloadedPower);

    CPPUNIT_TEST_SUITE_END();

public:
    ExpNodeTests();
    virtual ~ExpNodeTests();
    void setUp();
    void tearDown();

private:
    boost::shared_ptr<OptProblem> opt_prob_sptr;
    void testMethod();
    void testFailedMethod();
    void testActiveNode();
    void testPassiveNode();
    void testTempNode();
    void testOverloadedAddition();
    void testOverloadedSub();
    void testOverloadedMul();
    void testOverloadedDiv();
    void testOverloadedExp();
    void testOverloadedLog();
    void testOverloadedPower();
};

#endif	/* PACKAGETESTS_H */

