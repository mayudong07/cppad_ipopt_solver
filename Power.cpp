/* 
 * File:   Power.cpp
 * Author: yudong
 * 
 * Created on June 11, 2015, 2:59 PM
 */

#include "Power.h"
#include <cassert>
#include <cmath>

bool Power::instance_created = false;
boost::shared_ptr<AbstractOperator> Power::instance;


Power::Power() {
    
}


Power::~Power() {
    instance_created = false;
    instance.reset();
    
}

boost::shared_ptr<AbstractOperator> Power::get_instance(){
    
    if (!instance_created){
        instance = boost::shared_ptr<Power>(boost::make_shared<Power>());
        instance_created=true;
    }
    return instance;
   
}

std::string Power::get_operator_token() const{
    return std::string("o5");
}
double Power::eval(double l) const{
    assert(false);
}

double Power::eval(double l, double r) const{
    return pow(l, r);
}


AbsExpNodeSptr Power::get_jacobian_element(AbsExpNodeSptr l, AbsExpNodeSptr r, int i){
    
}
AbsExpNodeSptr Power::get_hessian_element(AbsExpNodeSptr l, AbsExpNodeSptr r, int i, int j){
    
}