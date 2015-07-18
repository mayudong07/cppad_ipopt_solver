/* 
 * File:   ExpNodeADNumber.h
 * Author: yudong
 *
 * Created on July 14, 2015, 12:55 PM
 */

#ifndef EXPNODEADNUMBER_H
#define	EXPNODEADNUMBER_H


// this is a function to overload the operators for ExpNodes


# include <cppad_ipopt_nlp.hpp>

#include "ActiveNode.h"
#include "TempNode.h"
#include "PassiveNode.h"
#include "AbstractOperator.h"
#include "OptProblem.h"
/// get ADNumber from activenode
using namespace cppad_ipopt;

ADNumber get_ad_number(const ActiveNodeSptr n,  const ADVector& x);
ADNumber get_ad_number(const PassiveNodeSptr n,  const ADVector& x);
ADNumber get_ad_number(const TempNodeSptr n,  const ADVector& x);

ADNumber get_ad_number(const AbsExpNodeSptr n,  const ADVector& x);


//// a cppad adapter to get the tape evaluating the cost and constraints
class OptProbFGinfo : public cppad_ipopt_fg_info
{
private:
    OptProblemSptr opt_prob_ptr_;
    bool retape_;
public:
        // derived class part of constructor
        OptProbFGinfo()
        : retape_ (false)
        { }
        OptProbFGinfo(OptProblemSptr p)
        : retape_ (false), opt_prob_ptr_(p)
        { }
        // Evaluation of the objective f(x), and constraints g(x)
        // using an Algorithmic Differentiation (AD) class.
        ADVector eval_r(size_t k, const ADVector&  x);
        bool retape(size_t k)
	{	return retape_; }
        // getter and setter
        OptProblemSptr opt_prob_ptr() const {return opt_prob_ptr_;};
        
};




#endif	/* EXPNODEADNUMBER_H */

