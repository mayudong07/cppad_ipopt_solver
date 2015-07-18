/* 
 * File:   TempNode.cpp
 * Author: yudong
 * 
 * Created on June 23, 2015, 3:14 PM
 */

#include "TempNode.h"

TempNode::TempNode(){
}

TempNode::TempNode(AbsExpNodeSptr l, AbsOperaterSptr o, AbsExpNodeSptr r):
l_operand_(l), r_operand_(r), operator_(o){
    if (!is_unary_operator()){
        assert(l->opt_problem()==r->opt_problem());
    }
    set_prob_problem(r->opt_problem());
}


TempNode::TempNode(const TempNode& orig) {
}

TempNode::~TempNode() {
}

bool TempNode::is_unary_operator(){
    return (!l_operand_); // if l_operand_ is null, then it is a temp var computed by unary operator
}

double TempNode::get_value(const std::vector<double> &double_vector) {
    if (is_unary_operator()){
        return get_operator()->eval(right_operand()->get_value(double_vector));
    }else{
        return get_operator()->eval(left_operand()->get_value(double_vector), right_operand()->get_value(double_vector));
    }
}