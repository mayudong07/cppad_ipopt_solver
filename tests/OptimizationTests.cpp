/*
 * File:   OptimizationTests.cpp
 * Author: yudong
 *
 * Created on Jul 14, 2015, 6:46:46 PM
 */

#include "OptimizationTests.h"


CPPUNIT_TEST_SUITE_REGISTRATION(OptimizationTests);

OptimizationTests::OptimizationTests() {
    opt_prob_sptr = boost::make_shared<OptProblem>();
    // set up optimization data
}

OptimizationTests::~OptimizationTests() {
}

void OptimizationTests::setUp() {
}

void OptimizationTests::tearDown() {
}

void OptimizationTests::testMethod() {
    ActiveNodeSptr x_1 = opt_prob_sptr->create_active_variable();
    ActiveNodeSptr x_2 = opt_prob_sptr->create_active_variable();
    ActiveNodeSptr x_3 = opt_prob_sptr->create_active_variable();
    ActiveNodeSptr x_4 = opt_prob_sptr->create_active_variable();
    opt_prob_sptr->cost_var() = x_1 * x_4 * (x_1 + x_2 + x_3) + x_3;
    opt_prob_sptr->add_constraint(x_1 * x_2 * x_3 * x_4);
    opt_prob_sptr->add_constraint(power(x_1,2) + power(x_2,2) + power(x_3,2) + power(x_4,2));
    int j;
    CPPUNIT_ASSERT(opt_prob_sptr);
    OptProblemData opt_data;
    opt_data.resize(4,2);
    opt_data.x_i[0] = 1.0;
    opt_data.x_i[1] = 5.0;
    opt_data.x_i[2] = 5.0;
    opt_data.x_i[3] = 1.0;
    
    for(j = 0; j < 4; j++)
    {	opt_data.x_l[j] = 1.0;
        opt_data.x_u[j] = 5.0;
    }
    opt_data.g_l[0] = 25.0;     opt_data.g_u[0] = 1.0e19;
    opt_data.g_l[1] = 40.0;     opt_data.g_u[1] = 40.0;

    CppADSolver solver(opt_prob_sptr);
    IpoptSolution solution = solver.solve(opt_data);
    /*
    Check some of the solution values
    */
    bool ok;
    ok &= solution.status == 0;
    //
    double check_x[]   = { 1.000000, 4.743000, 3.82115, 1.379408 };
    double check_z_l[] = { 1.087871, 0.,       0.,      0.       };
    double check_z_u[] = { 0.,       0.,       0.,      0.       };
    double rel_tol     = 1e-6;  // relative tolerance
    double abs_tol     = 1e-6;  // absolute tolerance
    for(j = 0; j < 4; j++)
    {	ok &= CppAD::NearEqual(
            check_x[j],   solution.x[j],   rel_tol, abs_tol
            );
            ok &= CppAD::NearEqual(
            check_z_l[j], solution.z_l[j], rel_tol, abs_tol
            );
            ok &= CppAD::NearEqual(
            check_z_u[j], solution.z_u[j], rel_tol, abs_tol
            );
    }
    
    
}

void OptimizationTests::tesths017() {
    ActiveNodeSptr x_1 = opt_prob_sptr->create_active_variable();
    ActiveNodeSptr x_2 = opt_prob_sptr->create_active_variable();
    ActiveNodeSptr x_3 = opt_prob_sptr->create_active_variable();
    ActiveNodeSptr x_4 = opt_prob_sptr->create_active_variable();
    opt_prob_sptr->cost_var() = 1 + x_1 + x_2 + x_3 + x_4;
    opt_prob_sptr->add_constraint(0.0401-4.0/x_1-2.25/x_2-1.0/x_3-0.25/x_4);
    opt_prob_sptr->add_constraint(0.010085-0.16/x_1-0.36/x_2-0.64/x_3-0.64/x_4);
    int j;
    CPPUNIT_ASSERT(opt_prob_sptr);
    OptProblemData opt_data;
    opt_data.resize(4,2);
    opt_data.x_i[0] = 1.0;
    opt_data.x_i[1] = 1.0;
    opt_data.x_i[2] = 1.0;
    opt_data.x_i[3] = 1.0;
    
    
    for(j = 0; j < 4; j++)
    {	opt_data.x_l[j] = 0.001;
        opt_data.x_u[j] = 40000.0-10000.0*j;
    }
    opt_data.g_l[0] = 0;     opt_data.g_u[0] = 1.0e19;
    opt_data.g_l[1] = 0;     opt_data.g_u[1] = 1.0e19;

    CppADSolver solver(opt_prob_sptr);
    IpoptSolution solution = solver.solve(opt_data);
    /*
    Check some of the solution values
    */
    bool ok;
    ok &= solution.status == 0;
    //
    double check_x[]   = { 193.407460592, 179.546994601, 185.01785939, 168.706548614 };
    double rel_tol     = 1e-6;  // relative tolerance
    double abs_tol     = 1e-6;  // absolute tolerance
    for(j = 0; j < 4; j++)
    {	ok &= CppAD::NearEqual(
            check_x[j],   solution.x[j],   rel_tol, abs_tol
            );
    }
}

