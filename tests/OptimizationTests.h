/*
 * File:   OptimizationTests.h
 * Author: yudong
 *
 * Created on Jul 14, 2015, 6:46:46 PM
 */

#ifndef OPTIMIZATIONTESTS_H
#define	OPTIMIZATIONTESTS_H

#include <cppunit/extensions/HelperMacros.h>

#include "../OptProblem.h"
#include "../Addition.h"
#include "../Division.h"
#include "../Exponential.h"
#include "../Logarithm.h"
#include "../Multiplication.h"
#include "../Power.h"
#include "../Subtraction.h"
#include "../ExpNodeOperations.h"

#include "../CppADSolver.h"

class OptimizationTests : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(OptimizationTests);

    CPPUNIT_TEST(testMethod);
    CPPUNIT_TEST(tesths017);

    CPPUNIT_TEST_SUITE_END();

public:
    boost::shared_ptr<OptProblem> opt_prob_sptr;
    OptimizationTests();
    virtual ~OptimizationTests();
    void setUp();
    void tearDown();

private:
    void testMethod();
    void tesths017();
};

#endif	/* OPTIMIZATIONTESTS_H */

