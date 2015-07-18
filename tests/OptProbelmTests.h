/*
 * File:   OptProbelmTests.h
 * Author: yudong
 *
 * Created on Jul 10, 2015, 4:53:08 PM
 */

#ifndef OPTPROBELMTESTS_H
#define	OPTPROBELMTESTS_H

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
#include "../PyVariable.h"

class OptProbelmTests : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(OptProbelmTests);

    CPPUNIT_TEST(testCreateOptProblem);
    CPPUNIT_TEST(testCreateActiveVariable);
    CPPUNIT_TEST(testCreateTempVariable);
    CPPUNIT_TEST(testCreateFromPython);

    CPPUNIT_TEST_SUITE_END();

public:
    OptProbelmTests();
    virtual ~OptProbelmTests();
    void setUp();
    void tearDown();

private:
    boost::shared_ptr<OptProblem> opt_prob_sptr;
    
    void testCreateOptProblem();
    void testCreateActiveVariable();
    void testCreateTempVariable();
    void testCreateFromPython();
};

#endif	/* OPTPROBELMTESTS_H */

