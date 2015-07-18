/*
 * File:   OptProbelmTests.cpp
 * Author: yudong
 *
 * Created on Jul 10, 2015, 4:53:09 PM
 */

#include "OptProbelmTests.h"
#include <iostream>


CPPUNIT_TEST_SUITE_REGISTRATION(OptProbelmTests);

OptProbelmTests::OptProbelmTests() {
    opt_prob_sptr = boost::make_shared<OptProblem>();
}

OptProbelmTests::~OptProbelmTests() {
}

void OptProbelmTests::setUp() {
}

void OptProbelmTests::tearDown() {
}

void OptProbelmTests::testCreateOptProblem() {
    CPPUNIT_ASSERT(opt_prob_sptr);
    ActiveNodeSptr x_1 = opt_prob_sptr->create_active_variable();
    ActiveNodeSptr x_2 = opt_prob_sptr->create_active_variable();
    ActiveNodeSptr x_3 = opt_prob_sptr->create_active_variable();
    ActiveNodeSptr x_4 = opt_prob_sptr->create_active_variable();
    opt_prob_sptr->cost_var() = x_1 * x_4 * (x_1 + x_2 + x_3) + x_3;
    opt_prob_sptr->add_constraint(x_1 * x_2 * x_3 * x_4);
    opt_prob_sptr->add_constraint(power(x_1,2) + power(x_2,2) + power(x_3,2) + power(x_4,2));
    CPPUNIT_ASSERT(opt_prob_sptr->num_of_constraints()==2);
    CPPUNIT_ASSERT(opt_prob_sptr->num_of_variables()==4);
    CPPUNIT_ASSERT(opt_prob_sptr->temp_var_vec().size()==15);
}

void OptProbelmTests::testCreateActiveVariable() {
    ActiveNodeSptr var;
    var = opt_prob_sptr->create_active_variable();
    CPPUNIT_ASSERT(var);
    CPPUNIT_ASSERT(var->index()==0);
    CPPUNIT_ASSERT(var->opt_problem()==opt_prob_sptr);
    CPPUNIT_ASSERT(var==opt_prob_sptr->active_var_vec()[0]);
    var = opt_prob_sptr->create_active_variable();
    CPPUNIT_ASSERT(var);
    CPPUNIT_ASSERT(var->index()==1);
    CPPUNIT_ASSERT(var->opt_problem()==opt_prob_sptr);
    CPPUNIT_ASSERT(var==opt_prob_sptr->active_var_vec()[1]);
}

void OptProbelmTests::testCreateTempVariable(){
    ActiveNodeSptr var1, var2;
    var1 = opt_prob_sptr->create_active_variable();
    var2 = opt_prob_sptr->create_active_variable();
    TempNodeSptr var;
    var = opt_prob_sptr->create_temp_variable(var1, Addition::get_instance(), var2);
    CPPUNIT_ASSERT(var);
    CPPUNIT_ASSERT(var->index()==0);
    CPPUNIT_ASSERT(var->opt_problem()==opt_prob_sptr);
    CPPUNIT_ASSERT(var==opt_prob_sptr->temp_var_vec()[0]);
    
    var = opt_prob_sptr->create_temp_variable(var1, Subtraction::get_instance(), var2);
    CPPUNIT_ASSERT(var);
    CPPUNIT_ASSERT(var->index()==1);
    CPPUNIT_ASSERT(var->opt_problem()==opt_prob_sptr);
    CPPUNIT_ASSERT(var==opt_prob_sptr->temp_var_vec()[1]);
}


void OptProbelmTests::testCreateFromPython(){
    PyVariableObject v1 = PyVariableObject(Loc(1,0), 0);
    PyVariableObject v2 = PyVariableObject(Loc(1,1), 0);
    PyVariableObject t1 = PyVariableObject(Loc(2,0), 0);
    PyVarObjectVec exp_node_vars;
    exp_node_vars.push_back(v1);exp_node_vars.push_back(v2);exp_node_vars.push_back(t1);
    PyExpNodeObject exp_node = PyExpNodeObject(exp_node_vars,0);
    PyTapeObject tape;
    tape.push_back(exp_node);
    
    PyOptProbObject pyopt;
    pyopt.n = 2;
    pyopt.t = 1;
    pyopt.constraints.push_back(tape);
    pyopt.constraints.push_back(tape);
    pyopt.constraints.push_back(tape);
    pyopt.cost = tape;
    
    opt_prob_sptr->create_this_from_python(pyopt);
    std::cout<<std::endl<< print_pynode(exp_node) << std::endl;

    
}