/* 
 * File:   Exponential.h
 * Author: yudong
 *
 * Created on June 12, 2015, 1:54 PM
 */

#ifndef EXPONENTIAL_H
#define	EXPONENTIAL_H
#include "AbstractOperator.h"

class Exponential: public AbstractOperator {
public:
    Exponential();
    virtual ~Exponential();
    static boost::shared_ptr<AbstractOperator> get_instance();
    std::string get_operator_token() const;
    double eval(double l) const; 
    double eval(double l, double r) const; 
    
    ADNumber eval(ADNumber &&l) const{return exp(l);};  // for unary operator
    ADNumber eval(ADNumber &&l, ADNumber &&r) const {assert(false);};  // for binary operator
    
    AbsExpNodeSptr get_jacobian_element(AbsExpNodeSptr l, AbsExpNodeSptr r, int i);
    AbsExpNodeSptr get_hessian_element(AbsExpNodeSptr l, AbsExpNodeSptr r, int i, int j);
    
    bool is_unary_operator() {return true;}
private:
    static bool instance_created;
    static boost::shared_ptr<AbstractOperator> instance;

};

#endif	/* EXPONENTIAL_H */

