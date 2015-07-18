/* 
 * File:   OptProblem.cpp
 * Author: yudong
 * 
 * Created on July 8, 2015, 2:12 PM
 */

#include "OptProblem.h"

OptProblem::OptProblem() {
}

OptProblem::OptProblem(const OptProblem& orig) {
}


void OptProblem::create_this_from_python(const PyOptProbObject& pyopt){
    // instantiate opt problem from PyoptProbObject
    int i;
    ActiveNodeSptr var;
    TempNodeSptr tvar;
    active_var_vec().resize(pyopt.n);
    for (i=0;i<pyopt.n;i++){
        var = boost::make_shared<ActiveNode>(i);
        var->set_prob_problem(shared_from_this());
        active_var_vec()[i] = var;
    }
    temp_var_vec().resize(pyopt.t);
    for (i=0;i<pyopt.t;i++){
        tvar = boost::make_shared<TempNode>(i);
        tvar->set_prob_problem(shared_from_this());
        temp_var_vec()[i] = tvar;
    }
    
    cost_var() = decode_pytape(pyopt.cost, active_var_vec(), temp_var_vec());
    
    AbsExpNodeSptrVec con = constraints_vec();
    int m = pyopt.num_of_constraints();
    con.resize(m);
    for (i=0;i<m;i++){
        con[i]=decode_pytape(pyopt.constraints[i], active_var_vec(), temp_var_vec());
    }
}

OptProblem::~OptProblem() {
}


ActiveNodeSptr OptProblem::create_active_variable(){
    int index = active_var_vec().size();
    ActiveNodeSptr var = boost::make_shared<ActiveNode>(index);
    var->set_prob_problem(shared_from_this());
    active_var_vec().push_back(var);
    return var;
}
TempNodeSptr OptProblem::create_temp_variable(AbsExpNodeSptr l, AbsOperaterSptr o, AbsExpNodeSptr r){
    int index = temp_var_vec().size();
    TempNodeSptr var = boost::make_shared<TempNode>(l, o, r);
    var->set_index(index);
    var->set_prob_problem(shared_from_this());
    temp_var_vec().push_back(var);
    return var;
}
PassiveNodeSptr OptProblem::create_passive_variable(double value){
    PassiveNodeSptr var;
    var = boost::make_shared<PassiveNode>(value);
    var->set_prob_problem(shared_from_this());
    return var;
    
}