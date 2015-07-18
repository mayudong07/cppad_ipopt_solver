/* 
 * File:   AbstractExpNode.h
 * Author: yudong
 *
 * Created on June 22, 2015, 5:37 PM
 */

#ifndef ABSTRACTEXPNODE_H
#define	ABSTRACTEXPNODE_H

#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/make_shared.hpp>
#include <vector>

class OptProblem;

class AbstractExpNode {
public:
    AbstractExpNode();
    AbstractExpNode(boost::shared_ptr<OptProblem> a):opt_problem_(a){};
    AbstractExpNode(const AbstractExpNode& orig);
    virtual ~AbstractExpNode();
    
    virtual bool is_constant_zero() {return false;};
    virtual bool is_temp_exp_node() {return false;};
    virtual bool is_active_exp_node() {return false;};
    virtual bool is_passive_exp_node() {return false;};
    
    virtual double get_value(const std::vector<double> &double_vector) {return 0.0;};
    
    //
    boost::shared_ptr<OptProblem> opt_problem() {return opt_problem_.lock();};
    void set_prob_problem(boost::weak_ptr<OptProblem> a) {opt_problem_ = a;};
    void set_prob_problem(boost::shared_ptr<OptProblem> a) {opt_problem_ = boost::weak_ptr<OptProblem>(a);};
    
private:
    boost::weak_ptr<OptProblem> opt_problem_;
   
};

typedef boost::shared_ptr<AbstractExpNode> AbsExpNodeSptr;


#endif	/* ABSTRACTEXPNODE_H */

