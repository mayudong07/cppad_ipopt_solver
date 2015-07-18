/* 
 * File:   PassiveNode.h
 * Author: yudong
 *
 * Created on June 23, 2015, 2:50 PM
 */

#ifndef PASSIVENODE_H
#define	PASSIVENODE_H
#include <vector>

#include "AbstractExpNode.h"

class PassiveNode: public AbstractExpNode {
public:
    PassiveNode();
    PassiveNode(double);
    PassiveNode(boost::shared_ptr<OptProblem>, double);
    PassiveNode(const PassiveNode& orig);
    virtual ~PassiveNode();
    double get_value(const std::vector<double> &double_vector) {return value_;};
    
    bool is_constant_zero();
    
    bool is_passive_exp_node() {return true;};
    double value(){return value_;};
private:
    double value_;

};
typedef boost::shared_ptr<PassiveNode> PassiveNodeSptr;

extern boost::shared_ptr<PassiveNode> const_one;
extern boost::shared_ptr<PassiveNode> const_zero;
extern boost::shared_ptr<PassiveNode> const_two;

#endif	/* PASSIVENODE_H */

