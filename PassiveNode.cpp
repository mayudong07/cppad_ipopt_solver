/* 
 * File:   PassiveNode.cpp
 * Author: yudong
 * 
 * Created on June 23, 2015, 2:50 PM
 */

#include "PassiveNode.h"

boost::shared_ptr<PassiveNode> const_one = boost::make_shared<PassiveNode>(1);
boost::shared_ptr<PassiveNode> const_zero = boost::make_shared<PassiveNode>();
boost::shared_ptr<PassiveNode> const_two = boost::make_shared<PassiveNode>(2);


PassiveNode::PassiveNode():value_(0.0) {
}

PassiveNode::PassiveNode(double v):value_(v) {
}

PassiveNode::PassiveNode(boost::shared_ptr<OptProblem> a, double v):AbstractExpNode(a), value_(v)  {
}

PassiveNode::PassiveNode(const PassiveNode& orig) {
}

PassiveNode::~PassiveNode() {
}


bool PassiveNode::is_constant_zero(){
    return value_ == 0.0 ;
}
