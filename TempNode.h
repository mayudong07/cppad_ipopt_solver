/* 
 * File:   TempNode.h
 * Author: yudong
 *
 * Created on June 23, 2015, 3:14 PM
 */

#ifndef TEMPNODE_H
#define	TEMPNODE_H

#include "AbstractExpNode.h"
#include "AbstractOperator.h"

class TempNode: public AbstractExpNode {
public:
    TempNode();
    TempNode(int i):index_(i){};
    TempNode(AbsExpNodeSptr l, AbsOperaterSptr o, AbsExpNodeSptr r);
    TempNode(const TempNode& orig);
    virtual ~TempNode();
    // check if this temp node is computed by a unary operator
    bool is_unary_operator();
    
    double get_value(const std::vector<double> &double_vector);
    
    
    bool is_temp_exp_node() {return true;};
    
    int index(){return index_;};
    void set_index(int idx) {index_=idx;};
    void set_left_operand(AbsExpNodeSptr o) {l_operand_=o;};
    void set_operator(AbsOperaterSptr o) {operator_=o;};
    void set_right_operand(AbsExpNodeSptr o) {r_operand_=o;};
    
    AbsExpNodeSptr left_operand(){return l_operand_;};
    AbsExpNodeSptr right_operand(){return r_operand_;};
    AbsOperaterSptr get_operator(){return operator_;};
    
private:
    int index_;
    AbsExpNodeSptr l_operand_;
    AbsExpNodeSptr r_operand_;
    AbsOperaterSptr operator_;

};
typedef boost::shared_ptr<TempNode> TempNodeSptr;

#endif	/* TEMPNODE_H */

