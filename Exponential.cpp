/* 
 * File:   Exponential.cpp
 * Author: yudong
 * 
 * Created on June 12, 2015, 1:54 PM
 */

#include "Exponential.h"
#include <cassert>
#include <cmath>

bool Exponential::instance_created = false;
boost::shared_ptr<AbstractOperator> Exponential::instance;

Exponential::Exponential() {
}


Exponential::~Exponential() {
    instance_created = false;
    instance.reset();
}

boost::shared_ptr<AbstractOperator> Exponential::get_instance(){
    
    if (!instance_created){
        instance = boost::shared_ptr<AbstractOperator>(boost::make_shared<Exponential>());
        instance_created=true;
    }
    return instance;
   
}

std::string Exponential::get_operator_token() const{
    return std::string("o44");
}
double Exponential::eval(double l) const{
    return exp(l);
}

double Exponential::eval(double l, double r) const{
    assert(false);
}


AbsExpNodeSptr Exponential::get_jacobian_element(AbsExpNodeSptr l, AbsExpNodeSptr r, int i){
    
}
AbsExpNodeSptr Exponential::get_hessian_element(AbsExpNodeSptr l, AbsExpNodeSptr r, int i, int j){
    
}