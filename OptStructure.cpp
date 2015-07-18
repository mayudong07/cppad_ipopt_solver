/* 
 * File:   OptStructure.cpp
 * Author: yudong
 * 
 * Created on June 23, 2015, 4:49 PM
 */

//#include "OptStructure.h"
//// MadVar class
//MadVar::MadVar():type(0), index(0){
//}
//MadVar::MadVar(int t, int i):type(t), index(i){
//}
//MadVar::MadVar(AbsExpNodeSptr){
//    
//}
//
//AbsExpNodeSptr MadVar::decode_mad_var(const std::vector<AbsExpNodeSptr> &active, const std::vector<AbsExpNodeSptr> &temp){
//    if (type == 0){
//        return (AbsExpNodeSptr)nullptr;
//    }
//    if (type == 1){
//        return active[index];
//    }
//    if (type == 2){
//        return temp[index];
//    }
//    
//}
//// MadExpNode class
//MadExpNode::MadExpNode(){
//}
//MadExpNode::MadExpNode(AbsExpNodeSptr){
//}
//MadExpNode::~MadExpNode(){
//}
//
//AbsExpNodeSptr MadExpNode::decode_mad_exp_node(std::vector<AbsExpNodeSptr> &active, std::vector<AbsExpNodeSptr> &temp){
//    AbsExpNodeSptr res_var = result.decode_mad_var(active, temp);
//    AbsExpNodeSptr lvar = l_operand.decode_mad_var(active, temp);
//    AbsExpNodeSptr rvar = r_operand.decode_mad_var(active, temp);
//    AbsOperaterSptr op = decode_operator(operator_code);
//    if (res_var->is_temp_exp_node()){
//        // there is a temp expression node
//        std::shared_ptr<TempNode> res_tmp_ptr = std::dynamic_pointer_cast<TempNode>(res_var);
//        assert(res_tmp_ptr);
//        res_tmp_ptr->set_left_operand(lvar);
//        res_tmp_ptr->set_right_operand(rvar);
//        res_tmp_ptr->set_operator(op);
//    } else{
//        // this is not a temp expression. then all the rest should be null
//        assert(!lvar);
//        assert(!rvar);
//    }
//    
//    return res_var;
//    
//}
//// MadExpression class
//MadExpression::MadExpression(){
//}
//MadExpression::MadExpression(AbsExpNodeSptr){
//}
//
//AbsExpNodeSptr MadExpression::decode_mad_exp_tape(std::vector<AbsExpNodeSptr> &active, std::vector<AbsExpNodeSptr> &temp){
//    AbsExpNodeSptr result=nullptr;
//    for (std::vector<MadExpNode>::iterator it = tape.begin() ; it != tape.end(); ++it){
//        result=(*it).decode_mad_exp_node(active, temp);
//    }
//    return result;
//}
//
////// opt structure problem class
//OptStructure::OptStructure() {
//}
//
//
//OptStructure::OptStructure(const OptStructure& orig) {
//}
//
//OptStructure::~OptStructure() {
//}
//
//void OptStructure::set_cost_variable(const AbsExpNodeSptr n){
//    
//}
//void OptStructure::set_constraint_variable(const AbsExpNodeSptr n){
//    
//}
//void OptStructure::get_cost_grad(){
//    
//}
//void OptStructure::get_cost_hess(){
//    
//}
//void OptStructure::get_constraints_grad(){
//    
//}
//void OptStructure::get_constraints_hess(){
//    
//}
//void OptStructure::load(ProblemFormulation &prob){
//    // first resize container size, and create expression nodes.
//    
//    
//    
//}
//ProblemFormulation & OptStructure::dump(){
//}



// private methods

//void OptStructure::create_expression_nodes(const int n, const int m, const int t){
//    f_grad.resize(n); // cost gradient
//    g.resize(m); // constraints
//    g_hess.resize(m); // constraint hessian
//    int i;
//    temp_nodes_.resize(t);
//    std::shared_ptr<TempNode> node=nullptr;
//    for (i=0;i<t;i++){
//        node = std::make_shared<TempNode>();
//        node->set_index(i);
//        node->set_prob_structure(_self_weak_ptr());
//        temp_nodes_[i] = AbsExpNodeSptr(node);
//    }
//    active_nodes_.resize(n);
//    std::shared_ptr<ActiveNode> a_node=nullptr;
//    for (i=0;i<n;i++){
//        a_node = std::make_shared<ActiveNode>();
//        a_node->set_index(i);
//        a_node->set_prob_structure(_self_weak_ptr());
//        active_nodes_[i] = AbsExpNodeSptr(a_node);
//    }
//}
