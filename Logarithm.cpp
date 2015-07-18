/* 
 * File:   Logarithm.cpp
 * Author: yudong
 * 
 * Created on June 11, 2015, 3:15 PM
 */

#include "Logarithm.h"
#include <cassert>
#include <cmath>


bool Logarithm::instance_created = false;
boost::shared_ptr<AbstractOperator> Logarithm::instance;

Logarithm::Logarithm() {
}

Logarithm::~Logarithm() {
    instance_created = false;
    instance.reset();
}


boost::shared_ptr<AbstractOperator> Logarithm::get_instance(){
    
    if (!instance_created){
        instance = boost::shared_ptr<AbstractOperator>(boost::make_shared<Logarithm>());
        instance_created=true;
    }
    return instance;
   
}

std::string Logarithm::get_operator_token() const{
    return std::string("o43");
}
double Logarithm::eval(double l) const{
    assert(l>0);
    return log(l);
}

double Logarithm::eval(double l, double r) const{
    assert(false); // logarithm is a strict unary operator
}


AbsExpNodeSptr Logarithm::get_jacobian_element(AbsExpNodeSptr l, AbsExpNodeSptr r, int i){
    
}
AbsExpNodeSptr Logarithm::get_hessian_element(AbsExpNodeSptr l, AbsExpNodeSptr r, int i, int j){
    
}