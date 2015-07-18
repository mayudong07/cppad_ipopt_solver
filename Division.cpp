/* 
 * File:   Division.cpp
 * Author: yudong
 * 
 * Created on June 11, 2015, 2:49 PM
 */

#include <cmath>
#include <cassert>
#include "Division.h"

bool Division::instance_created = false;
boost::shared_ptr<AbstractOperator> Division::instance;


Division::Division() {
}


Division::~Division() {
    instance_created = false;
    instance.reset();
}

boost::shared_ptr<AbstractOperator> Division::get_instance(){
    
    if (!instance_created){
        instance = boost::shared_ptr<AbstractOperator>(boost::make_shared<Division>());
        instance_created=true;
    }
    
    return instance;
   
}

std::string Division::get_operator_token() const{
    return std::string("o3");
}
double Division::eval(double l) const{
    assert(false); //division is a strict binary operator
}

double Division::eval(double l, double r) const{
    assert(fabs(r)>1e-19);
    return l/r;
}


AbsExpNodeSptr Division::get_jacobian_element(AbsExpNodeSptr l, AbsExpNodeSptr r, int i){
    
}
AbsExpNodeSptr Division::get_hessian_element(AbsExpNodeSptr l, AbsExpNodeSptr r, int i, int j){
    
}