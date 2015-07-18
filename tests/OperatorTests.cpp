/*
 * File:   OperatorTests.cpp
 * Author: yudong
 *
 * Created on Jul 14, 2015, 12:54:07 PM
 */

#include "OperatorTests.h"
#include <iostream>

using namespace cppad_ipopt;

CPPUNIT_TEST_SUITE_REGISTRATION(OperatorTests);

OperatorTests::OperatorTests() {
}

OperatorTests::~OperatorTests() {
}

void OperatorTests::setUp() {
}

void OperatorTests::tearDown() {
}

void OperatorTests::testCreateADNumber() {
    ADVector x(3);
    ActiveNodeSptr var; // index =1
    var = boost::make_shared<ActiveNode>(1); // index =1
    CPPUNIT_ASSERT(var->index()==1);
    ADNumber adn = get_ad_number(var, x);
    CPPUNIT_ASSERT(adn==x[1]);
    
    var = boost::make_shared<ActiveNode>(0); // index =1
    CPPUNIT_ASSERT(var->index()==0);
    ADNumber adn0 = get_ad_number(var, x);
    CPPUNIT_ASSERT(adn0==x[0]);
    
    PassiveNodeSptr pv;
    pv = boost::make_shared<PassiveNode>(10.0); // index =1
    CPPUNIT_ASSERT(pv->value()==10.0);
    ADNumber pvd = get_ad_number(pv, x);
    CPPUNIT_ASSERT(pvd==10.0);
}

void OperatorTests::testCreateTempADNumber() {
    ADVector x(3);
    x[0] = 1;
    x[1] = 2;
    x[2] = 3;
    ActiveNodeSptr var1, var2; // index =1
    TempNodeSptr tvar; // index =0
    var1 = boost::make_shared<ActiveNode>(0); // index =0
    var2 = boost::make_shared<ActiveNode>(1); // index =1
    tvar = boost::make_shared<TempNode>(var1, Addition::get_instance(), var2); // index =0
    
    ADNumber adn = get_ad_number(tvar, x);
    CPPUNIT_ASSERT(adn==3.0);
    PassiveNodeSptr pvar = boost::make_shared<PassiveNode>(10);
    TempNodeSptr tvar2 = boost::make_shared<TempNode>(tvar, Multiplication::get_instance(), pvar); // tvar2 = tvar*(10.0))
    ADNumber adn2 = get_ad_number(tvar2, x);
    CPPUNIT_ASSERT(adn2==30);
    
}

