/* 
 * File:   PyVariableTests.h
 * Author: yudong
 *
 * Created on July 9, 2015, 3:08 PM
 */

#ifndef PYVARIABLETESTS_H
#define	PYVARIABLETESTS_H

#include <cppunit/extensions/HelperMacros.h>

#include "../PyVariable.h"


class PyVariableTests : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(PyVariableTests);

    CPPUNIT_TEST(testPyVar);
    CPPUNIT_TEST(testPyExpNode);
    CPPUNIT_TEST(testPyTape);
    CPPUNIT_TEST(testPyTape_non_temp);

    CPPUNIT_TEST_SUITE_END();

public:
    PyVariableTests();
    virtual ~PyVariableTests();
    void setUp();
    void tearDown();

private:
    std::vector<ActiveNodeSptr> active_node_vec;
    std::vector<TempNodeSptr> temp_node_vec;
    
    void testPyVar();
    void testPyExpNode();
    void testPyTape();
    void testPyTape_non_temp();
};

#endif	/* PYVARIABLETESTS_H */

