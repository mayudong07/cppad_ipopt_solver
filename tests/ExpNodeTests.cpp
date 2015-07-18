/*
 * File:   PackageTests.cpp
 * Author: yudong
 *
 * Created on Jul 8, 2015, 4:36:01 PM
 */

#include <iostream>
#include <math.h>       /* exp */
#include "ExpNodeTests.h"


CPPUNIT_TEST_SUITE_REGISTRATION(ExpNodeTests);

ExpNodeTests::ExpNodeTests() {
    opt_prob_sptr = boost::make_shared<OptProblem>();
}

ExpNodeTests::~ExpNodeTests() {
}

void ExpNodeTests::setUp() {
}

void ExpNodeTests::tearDown() {
}

void ExpNodeTests::testMethod() {
    CPPUNIT_ASSERT(true);
}

void ExpNodeTests::testFailedMethod() {
    CPPUNIT_ASSERT(true);
}


void ExpNodeTests::testActiveNode(){
    ActiveNodeSptr n = boost::make_shared<ActiveNode>();
    CPPUNIT_ASSERT(n->index()==0);
    n->set_index(3);
    CPPUNIT_ASSERT(n->index()==3);
    std::vector<double> dvec{16,2,77,29, 30};
//    std::cout<< "/nthe index of n is "<< n->index() <<"\n";
    double tmp = n->get_value(dvec);
    CPPUNIT_ASSERT(tmp==29.0);
    CPPUNIT_ASSERT(!(tmp==77.0));
}

void ExpNodeTests::testPassiveNode(){
    std::vector<double> dvec{16,2,77,29};
    PassiveNodeSptr n = boost::make_shared<PassiveNode>(10);
    CPPUNIT_ASSERT(n->get_value(dvec)==10.0);
    
}

void ExpNodeTests::testTempNode(){
    std::vector<double> dvec{16,2,77,29};
    ActiveNodeSptr an = boost::make_shared<ActiveNode>();
    an->set_index(1);
    PassiveNodeSptr pn = boost::make_shared<PassiveNode>(10);
    AbsOperaterSptr op = Addition::get_instance();
    
    TempNodeSptr tn = boost::make_shared<TempNode>(an, op, pn);
    CPPUNIT_ASSERT(tn->get_value(dvec)==(2+10.0));
    
    TempNodeSptr tn1 = boost::make_shared<TempNode>(an, Subtraction::get_instance(), pn);
    CPPUNIT_ASSERT(tn1->get_value(dvec)==(2-10.0));
    
    
    TempNodeSptr tn2 = boost::make_shared<TempNode>(an, Division::get_instance(), pn);
    CPPUNIT_ASSERT(tn2->get_value(dvec)==(2/10.0));
    
    // test unary operators
    TempNodeSptr tn3 = boost::make_shared<TempNode>(AbsExpNodeSptr(), Exponential::get_instance(), pn);
    CPPUNIT_ASSERT(tn3->get_value(dvec)==exp(10.0));
    
    TempNodeSptr tn4 = boost::make_shared<TempNode>(AbsExpNodeSptr(), Logarithm::get_instance(), pn);
    CPPUNIT_ASSERT(tn4->get_value(dvec)==log(10.0));
    // test nested temp vars
    TempNodeSptr tn5 = boost::make_shared<TempNode>(AbsExpNodeSptr(), Logarithm::get_instance(), tn);
    CPPUNIT_ASSERT(tn5->get_value(dvec)==log(2+10.0));
}


void ExpNodeTests::testOverloadedAddition(){
    ActiveNodeSptr a1 = opt_prob_sptr->create_active_variable();
    ActiveNodeSptr a2 = opt_prob_sptr->create_active_variable();
    AbsExpNodeSptr tmp;
    tmp = a1+a2;
    CPPUNIT_ASSERT(tmp);
    CPPUNIT_ASSERT(tmp==opt_prob_sptr->temp_var_vec()[0]);
    CPPUNIT_ASSERT(tmp->opt_problem()==opt_prob_sptr);
    CPPUNIT_ASSERT(tmp->is_temp_exp_node());
    tmp = a1+3.0;
    CPPUNIT_ASSERT(tmp);
    CPPUNIT_ASSERT(tmp==opt_prob_sptr->temp_var_vec()[1]);
    CPPUNIT_ASSERT(tmp->opt_problem()==opt_prob_sptr);
    CPPUNIT_ASSERT(tmp->is_temp_exp_node());
    tmp = 3.0+a1;
    CPPUNIT_ASSERT(tmp);
    CPPUNIT_ASSERT(tmp==opt_prob_sptr->temp_var_vec()[2]);
    CPPUNIT_ASSERT(tmp->opt_problem()==opt_prob_sptr);
    CPPUNIT_ASSERT(tmp->is_temp_exp_node());
    tmp = +a1;
    CPPUNIT_ASSERT(tmp);
    CPPUNIT_ASSERT(tmp==opt_prob_sptr->active_var_vec()[0]);
    CPPUNIT_ASSERT(tmp->opt_problem()==opt_prob_sptr);
    CPPUNIT_ASSERT(tmp->is_active_exp_node());
}

void ExpNodeTests::testOverloadedSub(){
    ActiveNodeSptr a1 = opt_prob_sptr->create_active_variable();
    ActiveNodeSptr a2 = opt_prob_sptr->create_active_variable();
    AbsExpNodeSptr tmp;
    tmp = a1-a2;
    CPPUNIT_ASSERT(tmp);
    CPPUNIT_ASSERT(tmp==opt_prob_sptr->temp_var_vec()[0]);
    CPPUNIT_ASSERT(tmp->opt_problem()==opt_prob_sptr);
    CPPUNIT_ASSERT(tmp->is_temp_exp_node());
    tmp = a1-3.0;
    CPPUNIT_ASSERT(tmp);
    CPPUNIT_ASSERT(tmp==opt_prob_sptr->temp_var_vec()[1]);
    CPPUNIT_ASSERT(tmp->opt_problem()==opt_prob_sptr);
    CPPUNIT_ASSERT(tmp->is_temp_exp_node());
    tmp = 3.0-a1;
    CPPUNIT_ASSERT(tmp);
    CPPUNIT_ASSERT(tmp==opt_prob_sptr->temp_var_vec()[2]);
    CPPUNIT_ASSERT(tmp->opt_problem()==opt_prob_sptr);
    CPPUNIT_ASSERT(tmp->is_temp_exp_node());
    tmp = -a1;
    CPPUNIT_ASSERT(tmp);
    CPPUNIT_ASSERT(tmp==opt_prob_sptr->temp_var_vec()[3]);
    CPPUNIT_ASSERT(tmp->opt_problem()==opt_prob_sptr);
    CPPUNIT_ASSERT(tmp->is_temp_exp_node());
}

void ExpNodeTests::testOverloadedMul(){
    ActiveNodeSptr a1 = opt_prob_sptr->create_active_variable();
    ActiveNodeSptr a2 = opt_prob_sptr->create_active_variable();
    AbsExpNodeSptr tmp;
    tmp = a1*a2;
    CPPUNIT_ASSERT(tmp);
    CPPUNIT_ASSERT(tmp==opt_prob_sptr->temp_var_vec()[0]);
    CPPUNIT_ASSERT(tmp->opt_problem()==opt_prob_sptr);
    CPPUNIT_ASSERT(tmp->is_temp_exp_node());
    tmp = a1*3.0;
    CPPUNIT_ASSERT(tmp);
    CPPUNIT_ASSERT(tmp==opt_prob_sptr->temp_var_vec()[1]);
    CPPUNIT_ASSERT(tmp->opt_problem()==opt_prob_sptr);
    CPPUNIT_ASSERT(tmp->is_temp_exp_node());
    tmp = 3.0*a1;
    CPPUNIT_ASSERT(tmp);
    CPPUNIT_ASSERT(tmp==opt_prob_sptr->temp_var_vec()[2]);
    CPPUNIT_ASSERT(tmp->opt_problem()==opt_prob_sptr);
    CPPUNIT_ASSERT(tmp->is_temp_exp_node());
}

void ExpNodeTests::testOverloadedDiv(){
    ActiveNodeSptr a1 = opt_prob_sptr->create_active_variable();
    ActiveNodeSptr a2 = opt_prob_sptr->create_active_variable();
    AbsExpNodeSptr tmp;
    tmp = a1/a2;
    CPPUNIT_ASSERT(tmp);
    CPPUNIT_ASSERT(tmp==opt_prob_sptr->temp_var_vec()[0]);
    CPPUNIT_ASSERT(tmp->opt_problem()==opt_prob_sptr);
    CPPUNIT_ASSERT(tmp->is_temp_exp_node());
    tmp = a1/3.0;
    CPPUNIT_ASSERT(tmp);
    CPPUNIT_ASSERT(tmp==opt_prob_sptr->temp_var_vec()[1]);
    CPPUNIT_ASSERT(tmp->opt_problem()==opt_prob_sptr);
    CPPUNIT_ASSERT(tmp->is_temp_exp_node());
    tmp = 3.0/a1;
    CPPUNIT_ASSERT(tmp);
    CPPUNIT_ASSERT(tmp==opt_prob_sptr->temp_var_vec()[2]);
    CPPUNIT_ASSERT(tmp->opt_problem()==opt_prob_sptr);
    CPPUNIT_ASSERT(tmp->is_temp_exp_node());
}

void ExpNodeTests::testOverloadedExp(){
    ActiveNodeSptr a1 = opt_prob_sptr->create_active_variable();
    ActiveNodeSptr a2 = opt_prob_sptr->create_active_variable();
    AbsExpNodeSptr tmp;
    tmp = exp(a2);
    CPPUNIT_ASSERT(tmp);
    CPPUNIT_ASSERT(tmp==opt_prob_sptr->temp_var_vec()[0]);
    CPPUNIT_ASSERT(tmp->opt_problem()==opt_prob_sptr);
    CPPUNIT_ASSERT(tmp->is_temp_exp_node());
}

void ExpNodeTests::testOverloadedLog(){
    ActiveNodeSptr a1 = opt_prob_sptr->create_active_variable();
    ActiveNodeSptr a2 = opt_prob_sptr->create_active_variable();
    AbsExpNodeSptr tmp;
    tmp = log(a2);
    CPPUNIT_ASSERT(tmp);
    CPPUNIT_ASSERT(tmp==opt_prob_sptr->temp_var_vec()[0]);
    CPPUNIT_ASSERT(tmp->opt_problem()==opt_prob_sptr);
    CPPUNIT_ASSERT(tmp->is_temp_exp_node());
}


void ExpNodeTests::testOverloadedPower(){
    ActiveNodeSptr a1 = opt_prob_sptr->create_active_variable();
    ActiveNodeSptr a2 = opt_prob_sptr->create_active_variable();
    AbsExpNodeSptr tmp;
    tmp = power(a1,a2);
    CPPUNIT_ASSERT(tmp);
    CPPUNIT_ASSERT(tmp==opt_prob_sptr->temp_var_vec()[0]);
    CPPUNIT_ASSERT(tmp->opt_problem()==opt_prob_sptr);
    CPPUNIT_ASSERT(tmp->is_temp_exp_node());
    tmp = power(a1,3.0);
    CPPUNIT_ASSERT(tmp);
    CPPUNIT_ASSERT(tmp==opt_prob_sptr->temp_var_vec()[1]);
    CPPUNIT_ASSERT(tmp->opt_problem()==opt_prob_sptr);
    CPPUNIT_ASSERT(tmp->is_temp_exp_node());
    tmp = power(3.0,a1);
    CPPUNIT_ASSERT(tmp);
    CPPUNIT_ASSERT(tmp==opt_prob_sptr->temp_var_vec()[2]);
    CPPUNIT_ASSERT(tmp->opt_problem()==opt_prob_sptr);
    CPPUNIT_ASSERT(tmp->is_temp_exp_node());
}