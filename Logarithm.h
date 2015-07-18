/* 
 * File:   Logarithm.h
 * Author: yudong
 *
 * Created on June 11, 2015, 3:15 PM
 */

#ifndef LOGARITHM_H
#define	LOGARITHM_H
#include "AbstractOperator.h"

class Logarithm: public AbstractOperator {
public:
    Logarithm();
    virtual ~Logarithm();
    static boost::shared_ptr<AbstractOperator> get_instance();
    std::string get_operator_token() const;
    double eval(double l) const; 
    double eval(double l, double r) const; 
    
    ADNumber eval(ADNumber &&l) const{return log(l);};  // for unary operator
    ADNumber eval(ADNumber &&l, ADNumber &&r) const {assert(false);};  // for binary operator
    
    AbsExpNodeSptr get_jacobian_element(AbsExpNodeSptr l, AbsExpNodeSptr r, int i);
    AbsExpNodeSptr get_hessian_element(AbsExpNodeSptr l, AbsExpNodeSptr r, int i, int j);
    
    bool is_unary_operator() {return true;}
private:
    static bool instance_created;
    static boost::shared_ptr<AbstractOperator> instance;

};

#endif	/* LOGARITHM_H */

