/* 
 * File:   PyVariableTests.cpp
 * Author: yudong
 * 
 * Created on July 9, 2015, 3:08 PM
 */

#include <iostream>
#include <math.h>       /* exp */
#include "PyVariableTests.h"



CPPUNIT_TEST_SUITE_REGISTRATION(PyVariableTests);

PyVariableTests::PyVariableTests() {
    active_node_vec.push_back(boost::make_shared<ActiveNode>(0));
    active_node_vec.push_back(boost::make_shared<ActiveNode>(1));
    active_node_vec.push_back(boost::make_shared<ActiveNode>(2));
    active_node_vec.push_back(boost::make_shared<ActiveNode>(3));
    temp_node_vec.push_back(boost::make_shared<TempNode>(0));
    temp_node_vec.push_back(boost::make_shared<TempNode>(1));
    temp_node_vec.push_back(boost::make_shared<TempNode>(2));
    temp_node_vec.push_back(boost::make_shared<TempNode>(3));
}

PyVariableTests::~PyVariableTests() {
}

void PyVariableTests::setUp() {
}

void PyVariableTests::tearDown() {
}

void PyVariableTests::testPyVar() {
    AbsExpNodeSptr n;
    PyVar v1(0,0);
    n = v1.decode(active_node_vec, temp_node_vec);
    CPPUNIT_ASSERT(!n);
    
    PyVar v2(1,0);
    n = v2.decode(active_node_vec, temp_node_vec);
    CPPUNIT_ASSERT(n);
    CPPUNIT_ASSERT(n->is_active_exp_node());
    CPPUNIT_ASSERT(boost::dynamic_pointer_cast<ActiveNode>(n)->index()==0);
    
    PyVar v3(2,1);
    n = v3.decode(active_node_vec, temp_node_vec);
    CPPUNIT_ASSERT(n);
    CPPUNIT_ASSERT(n->is_temp_exp_node());
    CPPUNIT_ASSERT(boost::dynamic_pointer_cast<TempNode>(n)->index()==1);
    
    PyVar v4(3,0, 10.0);
    n = v4.decode(active_node_vec, temp_node_vec);
    CPPUNIT_ASSERT(n);
    CPPUNIT_ASSERT(n->is_passive_exp_node());
    CPPUNIT_ASSERT(boost::dynamic_pointer_cast<PassiveNode>(n)->value()==10.0);
    
}

void PyVariableTests::testPyExpNode() {
    AbsExpNodeSptr n;
    PyExpNode n1(1,0,0,2,0,2,1); // this means t1=d0+t0
    n = n1.decode(active_node_vec, temp_node_vec);
    CPPUNIT_ASSERT(n);
    CPPUNIT_ASSERT(n->is_temp_exp_node());
    TempNodeSptr n_tmp=boost::dynamic_pointer_cast<TempNode>(n);
    CPPUNIT_ASSERT(n_tmp->get_operator() == Addition::get_instance());
    CPPUNIT_ASSERT(n_tmp->index() == 1);
    CPPUNIT_ASSERT(n_tmp->left_operand()->is_active_exp_node());
    CPPUNIT_ASSERT(n_tmp->right_operand()->is_temp_exp_node());
    
    PyExpNode n2(1,0,0,1,1,2,1); // this means t1=d0+d1
    n = n2.decode(active_node_vec, temp_node_vec);
    std::vector<double> dvec{16,2,77,29, 30};
    CPPUNIT_ASSERT(n->get_value(dvec)==(16+2));
    
}

void PyVariableTests::testPyTape(){
    AbsExpNodeSptr n;
    PyTape t;
    PyExpNode n1(1,0,0,1,1,2,1); // this means t1=d0+d1
    PyExpNode n2(1,0,2,2,1,2,2); // this means t2=d0*t1
    PyExpNode n3(0,0,43,2,2,2,3); // this means t3=log(t2)
    t.push_back_node(n1);
    t.push_back_node(n2);
    t.push_back_node(n3);
    n = t.decode(active_node_vec, temp_node_vec);
    std::vector<double> dvec{16,2,77,29, 30};
    CPPUNIT_ASSERT(n->get_value(dvec)==log(288.0));
    
}

void PyVariableTests::testPyTape_non_temp(){
    AbsExpNodeSptr n;
    PyTape t;
    PyExpNode n1(0,0,-999,0,0,1,1); // this means t1=d0+d1
    t.push_back_node(n1);
    n = t.decode(active_node_vec, temp_node_vec);
    std::vector<double> dvec{16,2,77,29, 30};
    CPPUNIT_ASSERT(n->get_value(dvec)==2.0);
    
}