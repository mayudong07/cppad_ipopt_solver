/* 
 * File:   ActiveNode.h
 * Author: yudong
 *
 * Created on June 23, 2015, 1:53 PM
 */

#ifndef ACTIVENODE_H
#define	ACTIVENODE_H
#include <vector>

#include "AbstractExpNode.h"
#include "PassiveNode.h"


class ActiveNode: public AbstractExpNode {
public:
    ActiveNode();
    ActiveNode(int i):index_(i){};
    ActiveNode(const ActiveNode& orig);
    virtual ~ActiveNode();
    // attributes getter and setter;
    int index() const {return index_;};
    int set_index(const int idx) {index_=idx;};
    // abstractor exp node
    virtual double get_value(const std::vector<double> &double_vector) {return double_vector[index()];};
    
    bool is_active_exp_node() {return true;};
    
private:
    int index_;
    

};
typedef boost::shared_ptr<ActiveNode> ActiveNodeSptr;

#endif	/* ACTIVENODE_H */

