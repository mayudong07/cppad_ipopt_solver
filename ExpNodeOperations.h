/* 
 * File:   ExpNodeOperations.h
 * Author: yudong
 *
 * Created on July 14, 2015, 4:18 PM
 */

#ifndef EXPNODEOPERATIONS_H
#define	EXPNODEOPERATIONS_H

#include "ActiveNode.h"
#include "TempNode.h"
#include "PassiveNode.h"
#include "Addition.h"
#include "Division.h"
#include "Exponential.h"
#include "Logarithm.h"
#include "Multiplication.h"
#include "Power.h"
#include "Subtraction.h"
#include "OptProblem.h"

inline AbsExpNodeSptr exp_node_operations(AbsExpNodeSptr left, AbsOperaterSptr op, AbsExpNodeSptr right){
    OptProblemSptr opt = right->opt_problem();
    if (opt){
        return opt->create_temp_variable(left, op, right);
    }else{
        return boost::make_shared<TempNode>(left, Subtraction::get_instance(), right);
    }
}
// arithematic binary operators

AbsExpNodeSptr operator + (AbsExpNodeSptr left, AbsExpNodeSptr right) {
    return exp_node_operations(left, Addition::get_instance(), right);
};
AbsExpNodeSptr operator - (AbsExpNodeSptr left, AbsExpNodeSptr right) {
    return exp_node_operations(left, Subtraction::get_instance(), right);
};
AbsExpNodeSptr operator * (AbsExpNodeSptr left, AbsExpNodeSptr right) {
    return exp_node_operations(left, Multiplication::get_instance(), right);
};
AbsExpNodeSptr operator / (AbsExpNodeSptr left, AbsExpNodeSptr right) {
    return exp_node_operations(left, Division::get_instance(), right);
};

AbsExpNodeSptr power(AbsExpNodeSptr left, AbsExpNodeSptr right) {
    return exp_node_operations(left, Power::get_instance(), right);
};

AbsExpNodeSptr operator + (AbsExpNodeSptr left, double right) {return left+boost::make_shared<PassiveNode>(left->opt_problem(),right);};
AbsExpNodeSptr operator + (double left, AbsExpNodeSptr right) {return right+left;};

AbsExpNodeSptr operator - (AbsExpNodeSptr left, double right) {return left-boost::make_shared<PassiveNode>(left->opt_problem(),right);};
AbsExpNodeSptr operator - (double left, AbsExpNodeSptr right) {return boost::make_shared<PassiveNode>(right->opt_problem(),left)-right;};

AbsExpNodeSptr operator * (AbsExpNodeSptr left, double right) {return left*boost::make_shared<PassiveNode>(left->opt_problem(),right);};
AbsExpNodeSptr operator * (double left, AbsExpNodeSptr right) {return right*left;};

AbsExpNodeSptr operator / (AbsExpNodeSptr left, double right) {return left/boost::make_shared<PassiveNode>(left->opt_problem(),right);};
AbsExpNodeSptr operator / (double left, AbsExpNodeSptr right) {return boost::make_shared<PassiveNode>(right->opt_problem(),left)/right;};

AbsExpNodeSptr power(AbsExpNodeSptr left, double right) {return power(left, boost::make_shared<PassiveNode>(left->opt_problem(),right));};
AbsExpNodeSptr power(double left, AbsExpNodeSptr right) {return power(boost::make_shared<PassiveNode>(right->opt_problem(),left), right);};

inline AbsExpNodeSptr operator - (AbsExpNodeSptr left) {return 0.0-left;};
inline AbsExpNodeSptr operator + (AbsExpNodeSptr left) {return left;};
inline AbsExpNodeSptr exp(AbsExpNodeSptr left) {return exp_node_operations(AbsExpNodeSptr(), Exponential::get_instance(), left);};
inline AbsExpNodeSptr log(AbsExpNodeSptr left) {return exp_node_operations(AbsExpNodeSptr(), Logarithm::get_instance(), left);};



#endif	/* EXPNODEOPERATIONS_H */

