/* 
 * File:   Subtraction.cpp
 * Author: yudong
 * 
 * Created on June 11, 2015, 12:27 PM
 */

#include "Subtraction.h"

bool Subtraction::instance_created = false;
boost::shared_ptr<AbstractOperator> Subtraction::instance;

Subtraction::Subtraction() {
}


Subtraction::~Subtraction() {
    instance_created = false;
    instance.reset();
}


boost::shared_ptr<AbstractOperator> Subtraction::get_instance(){
    
    if (!instance_created){
        instance = boost::shared_ptr<Subtraction>(boost::make_shared<Subtraction>());
        instance_created=true;
    }
    return instance;
   
}


std::string Subtraction::get_operator_token() const{
    return std::string("o1");
}

double Subtraction::eval(double lvar) const{
    return -lvar;
}

double Subtraction::eval(double lvar, double rvar) const{
    return lvar-rvar;
}


AbsExpNodeSptr Subtraction::get_jacobian_element(AbsExpNodeSptr l, AbsExpNodeSptr r, int i){
    
}
AbsExpNodeSptr Subtraction::get_hessian_element(AbsExpNodeSptr l, AbsExpNodeSptr r, int i, int j){
    
}