/* 
 * File:   Multiplication.cpp
 * Author: yudong
 * 
 * Created on June 11, 2015, 2:33 PM
 */

#include "Multiplication.h"
bool Multiplication::instance_created = false;
boost::shared_ptr<AbstractOperator> Multiplication::instance;

Multiplication::Multiplication() {
}


Multiplication::~Multiplication() {
    instance_created = false;
    instance.reset();
}


boost::shared_ptr<AbstractOperator> Multiplication::get_instance(){
    
    if (!instance_created){
        instance = boost::shared_ptr<Multiplication>(boost::make_shared<Multiplication>());
        instance_created=true;
    }
    return instance;
   
}


std::string Multiplication::get_operator_token() const{
    return std::string("o2");
}

double Multiplication::eval(double l) const{
    return l;
}

double Multiplication::eval(double l, double r) const{
    return l*r;
}

AbsExpNodeSptr Multiplication::get_jacobian_element(AbsExpNodeSptr l, AbsExpNodeSptr r, int i){
    
}
AbsExpNodeSptr Multiplication::get_hessian_element(AbsExpNodeSptr l, AbsExpNodeSptr r, int i, int j){
    
}