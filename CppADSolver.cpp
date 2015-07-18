/* 
 * File:   CppADSolver.cpp
 * Author: yudong
 * 
 * Created on July 14, 2015, 7:02 PM
 */

#include "CppADSolver.h"
#include <iostream>

using Ipopt::IpoptApplication;
using namespace std;

CppADSolver::CppADSolver() { 
}

CppADSolver::CppADSolver(OptProblemSptr prob): opt_prob(prob){
    fg_info_ptr = boost::make_shared<OptProbFGinfo>(opt_prob);
}

CppADSolver::CppADSolver(PyOptProbObject & pyopt){
//    cout<< "number of variables are"<< pyopt.n <<endl;
//    cout<< "number of temp vars are"<< pyopt.t <<endl;
//    cout<< "number of constraints vars are"<< pyopt.num_of_constraints() <<endl;
//    cout<< "cost var are"<< print_pytape(pyopt.cost) <<endl;
//    for (int i=0;i<pyopt.num_of_constraints();i++){
//        cout<< "constraint var is"<< print_pytape(pyopt.constraints[i]) <<endl;
//    }
//    
    opt_prob = boost::make_shared<OptProblem>();
    opt_prob->create_this_from_python(pyopt);
    fg_info_ptr = boost::make_shared<OptProbFGinfo>(opt_prob);
    
}

CppADSolver::~CppADSolver() {
}



IpoptSolution CppADSolver::solve(OptProblemData &data){
    size_t n = opt_prob->num_of_variables();
    size_t m = opt_prob->num_of_constraints();
    // create the Ipopt interface
    cppad_ipopt_solution solution;
    CppADOptProblemData cppad_data(data);
    Ipopt::SmartPtr<Ipopt::TNLP> cppad_nlp = new cppad_ipopt_nlp(
        n, m, cppad_data.x_i, cppad_data.x_l, cppad_data.x_u, cppad_data.g_l, cppad_data.g_u, &(*fg_info_ptr), &solution
        );

    // Create an instance of the IpoptApplication
    Ipopt::SmartPtr<Ipopt::IpoptApplication> app = new IpoptApplication();

    // turn off any printing
    app->Options()->SetIntegerValue("print_level", 4);
    app->Options()->SetStringValue("sb", "yes");

    // maximum number of iterations
    app->Options()->SetIntegerValue("max_iter", 5000);

    // approximate accuracy in first order necessary conditions;
    // see Mathematical Programming, Volume 106, Number 1, 
    // Pages 25-57, Equation (6)
    app->Options()->SetNumericValue("tol", 1e-9);

    // derivative testing
//    app->Options()->
//    SetStringValue("derivative_test", "second-order");
//    app->Options()-> SetNumericValue(
//            "point_perturbation_radius", 0.
//    );

    // Initialize the IpoptApplication and process the options
    Ipopt::ApplicationReturnStatus status = app->Initialize();
    assert(status == Ipopt::Solve_Succeeded);

    // Run the IpoptApplication
    status = app->OptimizeTNLP(cppad_nlp);
    return IpoptSolution(solution);
}

