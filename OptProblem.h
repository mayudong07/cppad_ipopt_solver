/* 
 * File:   OptProblem.h
 * Author: yudong
 *
 * Created on July 8, 2015, 2:12 PM
 */

#ifndef OPTPROBLEM_H
#define	OPTPROBLEM_H
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/make_shared.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <vector>

#include "ActiveNode.h"
#include "TempNode.h"
#include "PassiveNode.h"
#include "AbstractOperator.h"
#include "PyVariable.h"

typedef std::vector<AbsExpNodeSptr> AbsExpNodeSptrVec;
typedef std::vector<ActiveNodeSptr> ActiveNodeSptrVec;
typedef std::vector<TempNodeSptr> TempNodeSptrVec;

class OptProblem : public boost::enable_shared_from_this<OptProblem> {
public:
    OptProblem();
    OptProblem(const OptProblem& orig);
    virtual ~OptProblem();
    ActiveNodeSptr create_active_variable();
    TempNodeSptr create_temp_variable(AbsExpNodeSptr l, AbsOperaterSptr o, AbsExpNodeSptr r);
    PassiveNodeSptr create_passive_variable(double value);
    
    AbsExpNodeSptr &cost_var(){return cost_var_;};
    AbsExpNodeSptrVec &constraints_vec(){return constraints_vec_;};
    ActiveNodeSptrVec &active_var_vec(){return active_var_vec_;};
    TempNodeSptrVec &temp_var_vec(){return temp_var_vec_;};
    
    int num_of_constraints() const {return constraints_vec_.size();};
    int num_of_variables() const {return active_var_vec_.size();};
    
    void add_constraint(AbsExpNodeSptr v){constraints_vec().push_back(v);};
    
    // python interface
    void create_this_from_python(const PyOptProbObject& pyopt);
    
private:
    AbsExpNodeSptr cost_var_;
    AbsExpNodeSptrVec constraints_vec_;
    ActiveNodeSptrVec active_var_vec_;
    TempNodeSptrVec temp_var_vec_;

};

typedef boost::shared_ptr<OptProblem> OptProblemSptr;




#endif	/* OPTPROBLEM_H */

