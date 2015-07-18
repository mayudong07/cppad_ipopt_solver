/* 
 * File:   AbstractOperator.h
 * Author: yudong
 * All operators should be defined as singleton
 * Created on June 11, 2015, 11:22 AM
 */

#ifndef ABSTRACTOPERATOR_H
#define	ABSTRACTOPERATOR_H
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/make_shared.hpp>
#include <string>
#include <boost/numeric/interval.hpp>

#include "AbstractExpNode.h"
# include <cppad_ipopt_nlp.hpp>

using namespace boost::numeric;
using namespace interval_lib ;
using namespace cppad_ipopt;

typedef interval<double, policies<save_state<rounded_transc_std<double> >,
                    checking_base<double> > > IntvalDouble;

class AbstractOperator {
public:
    AbstractOperator();
    virtual ~AbstractOperator();
    
    virtual std::string get_operator_token() const = 0;
    virtual double eval(double l) const =0;  // for unary operator
    virtual double eval(double l, double r) const =0;  // for binary operator
    
    virtual ADNumber eval(ADNumber &&l) const =0;  // for unary operator
    virtual ADNumber eval(ADNumber &&l, ADNumber &&r) const =0;  // for binary operator
    
    
    virtual AbsExpNodeSptr get_jacobian_element(AbsExpNodeSptr l, AbsExpNodeSptr r, int i)=0;
    virtual AbsExpNodeSptr get_hessian_element(AbsExpNodeSptr l, AbsExpNodeSptr r, int i, int j)=0;
    
    virtual bool is_unary_operator() {return false;};
    
    
private:
    

};


typedef boost::shared_ptr<AbstractOperator> AbsOperaterSptr; // shared smart pointer

#endif	/* ABSTRACTOPERATOR_H */

