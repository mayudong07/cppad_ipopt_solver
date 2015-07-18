/* 
 * File:   Addition.cpp
 * Author: yudong
 * 
 * Created on June 11, 2015, 11:31 AM
 */

#include "Addition.h"
#include <cassert>


bool Addition::instance_created = false;
boost::shared_ptr<AbstractOperator> Addition::instance;



Addition::Addition() {

}

Addition::~Addition() {
    instance_created = false;
    instance.reset();
}

boost::shared_ptr<AbstractOperator> Addition::get_instance(){
    
    if (!instance_created){
        instance = boost::shared_ptr<AbstractOperator>(boost::make_shared<Addition>());
        instance_created=true;
    }
    return instance;
   
}

std::string Addition::get_operator_token() const{
    return std::string("o0");
}

double Addition::eval(double l) const{
    return l;
}

double Addition::eval(double l, double r) const{
    return l+r;
}


AbsExpNodeSptr Addition::get_jacobian_element(AbsExpNodeSptr l, AbsExpNodeSptr r, int i){
    
}
AbsExpNodeSptr Addition::get_hessian_element(AbsExpNodeSptr l, AbsExpNodeSptr r, int i, int j){
    
}