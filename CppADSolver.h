/* 
 * File:   CppADSolver.h
 * Author: yudong
 *
 * Created on July 14, 2015, 7:02 PM
 */

#ifndef CPPADSOLVER_H
#define	CPPADSOLVER_H
#include <cstring>
#include <vector>
#include "ExpNodeADNumber.h"
#include "PyVariable.h"
using namespace cppad_ipopt;

typedef std::vector<double> DoubleVec;

inline void copy_dvec_to_cppvec(DoubleVec& dvec, NumberVector& nvec){
    nvec.resize(dvec.size());
    for (int i=0;i<dvec.size();i++){
        nvec[i] = dvec[i];
    }
}

inline void copy_cppvec_to_dvec(NumberVector& nvec, DoubleVec& dvec){
    dvec.resize(nvec.size());
    for (int i=0;i<nvec.size();i++){
        dvec[i] = nvec[i];
    }
}


struct OptProblemData{
    DoubleVec x_i;
    DoubleVec x_l;
    DoubleVec x_u;
    DoubleVec g_l;
    DoubleVec g_u;
    OptProblemData(){};
    OptProblemData(DoubleVec &xi,DoubleVec &xl,DoubleVec &xu,DoubleVec &gl,DoubleVec &gu):
        x_i(xi), x_l(xl), x_u(xu), g_l(gl), g_u(gu){};
    bool resize(size_t n, size_t m){
        x_l.resize(n);
        x_u.resize(n);
        x_i.resize(n);
        g_l.resize(m);
        g_u.resize(m);
    }
    
};

struct IpoptSolution{
    /// possible values for he solution status
    int status;
    /// the approximation solution
    DoubleVec      x;
    /// Lagrange multipliers corresponding to lower bounds on x
    DoubleVec      z_l;
    /// Lagrange multipliers corresponding to upper bounds on x
    DoubleVec      z_u;
    /// value of g(x)
    DoubleVec      g;
    /// Lagrange multipliers correspondiing constraints on g(x)
    DoubleVec      z_g;
    /// value of f(x)
    double     obj_value;
    IpoptSolution(){};
    IpoptSolution(cppad_ipopt_solution& sol){
        copy_cppvec_to_dvec(sol.x, x);
        copy_cppvec_to_dvec(sol.z_l, z_l);
        copy_cppvec_to_dvec(sol.z_u, z_u);
        copy_cppvec_to_dvec(sol.g, g);
        copy_cppvec_to_dvec(sol.lambda, z_g);
        obj_value = sol.obj_value;
        switch(sol.status){
            case cppad_ipopt_solution::not_defined : status=-999;break;
            case cppad_ipopt_solution::success : status=0;break;
            case cppad_ipopt_solution::maxiter_exceeded : status=2;break;
            case cppad_ipopt_solution::stop_at_acceptable_point : status=1;break;
            default: status=-1;break;
        }
    };
    
};


struct CppADOptProblemData{
    NumberVector x_i;
    NumberVector x_l;
    NumberVector x_u;
    NumberVector g_l;
    NumberVector g_u;
    CppADOptProblemData( OptProblemData& data){
        copy_dvec_to_cppvec(data.x_i, x_i);
        copy_dvec_to_cppvec(data.x_l, x_l);
        copy_dvec_to_cppvec(data.x_u, x_u);
        copy_dvec_to_cppvec(data.g_l, g_l);
        copy_dvec_to_cppvec(data.g_u, g_u);
    }
};



class CppADSolver {
public:
    CppADSolver();
    CppADSolver(std::string &){};
    CppADSolver(PyOptProbObject &);
    CppADSolver(OptProblemSptr prob);
    virtual ~CppADSolver();
    IpoptSolution solve(OptProblemData& data);
private:
    OptProblemSptr opt_prob;
    boost::shared_ptr<OptProbFGinfo> fg_info_ptr;
};

#endif	/* CPPADSOLVER_H */

