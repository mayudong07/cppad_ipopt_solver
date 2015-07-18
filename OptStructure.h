/* 
 * File:   OptStructure.h
 * Author: yudong
 *
 * Created on June 23, 2015, 4:49 PM
 */

#ifndef OPTSTRUCTURE_H
#define	OPTSTRUCTURE_H
#include <memory>
#include <vector>
#include <unordered_set>
#include <cstring>

#include "TempNode.h"
#include "ActiveNode.h"
#include "PassiveNode.h"

#include "Addition.h"
#include "Division.h"
#include "Exponential.h"
#include "Logarithm.h"
#include "Multiplication.h"
#include "Power.h"
#include "Subtraction.h"
//mad_var.first indicates the type of variable 1=defined_variable, 2=temp variable, 0=null
//mad_var.second indicates the index of the variable in the entire problem.
// if mad_var.first is null, means this variable is undefined.

//static AbsOperaterSptr decode_operator(int o) {
//    AbsOperaterSptr op = nullptr;
//    switch(o){
//        case 0: op = Addition::get_instance(); break;
//        case 1: op = Subtraction::get_instance(); break;
//        case 2: op = Multiplication::get_instance(); break;
//        case 3: op = Division::get_instance(); break;
//        case 5: op = Power::get_instance(); break;
//        case 43: op = Logarithm::get_instance(); break;
//        case 44: op = Exponential::get_instance(); break;
//        default: break;
//    }
//    return op;
//}
//static std::string encode_operator(AbsOperaterSptr o) {}
//
//struct MadVar{
//public:
//    int type; //the type of variable
//    int index; // the index of variable
//    MadVar();
//    MadVar(int t, int i);
//    MadVar(AbsExpNodeSptr);
//    ~MadVar(){};
//    AbsExpNodeSptr decode_mad_var(const std::vector<AbsExpNodeSptr> &active, const std::vector<AbsExpNodeSptr> &temp);
//};
//
//
//class MadExpNode{
//public:
//    MadVar l_operand;
//    int operator_code; // the operator code following the document http://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.60.9659&rep=rep1&type=pdf
//    MadVar r_operand;
//    MadVar result;
//    MadExpNode();
//    MadExpNode(AbsExpNodeSptr);
//    ~MadExpNode();
//    // give the mad exp node info, create a expression node
//    AbsExpNodeSptr decode_mad_exp_node(std::vector<AbsExpNodeSptr> &active, std::vector<AbsExpNodeSptr> &temp);
//};
//
//class MadExpression{
//public:
//    std::vector<MadExpNode> tape;
//    MadExpression();
//    MadExpression(AbsExpNodeSptr);
//    ~MadExpression();
//    AbsExpNodeSptr decode_mad_exp_tape(std::vector<AbsExpNodeSptr> &active, std::vector<AbsExpNodeSptr> &temp);
//};
//
//
//class ProblemFormulation{
//public:
//    int n; // number of defined variables;
//    int m; // number of constraints;
//    int t; // number of temp variables;
//    MadExpression cost;
//    std::vector<MadExpression> constraints; 
//};
//
//
//class OptStructure: public std::enable_shared_from_this<OptStructure> {
//public:
//    OptStructure();
//    OptStructure(const OptStructure& orig);
//    virtual ~OptStructure();
//    
//    void set_cost_variable(const AbsExpNodeSptr n); // set n as the cost variable;
//    void set_constraint_variable(const AbsExpNodeSptr n); // set n as the constraint variable and add to the problem structure;
//    void get_cost_grad(); // get the cost grad structure
//    void get_cost_hess(); // get the cost hess structure
//    void get_constraints_grad(); // get the constraints jacobian structure
//    void get_constraints_hess(); // get the constraints hessian structure
//    void load(ProblemFormulation &prob); // import data from other program to initialize the opt problem structure
//    ProblemFormulation &dump(); // import data from other program to initialize the opt problem structure
//    void create_expression_nodes(const int n, const int m, const int t);
//    
//    std::vector<AbsExpNodeSptr>& temp_nodes(){return temp_nodes_;};
//    std::vector<AbsExpNodeSptr>& active_nodes(){return active_nodes_;};
//    
//private:
//    
//    std::unordered_set<Coordinate> hessian_structure;
//    std::unordered_set<Coordinate> jacobian_structure;
//    AbsExpNodeSptr f; // cost
//    std::vector<AbsExpNodeSptr> f_grad; // cost gradient
//    SparseOptMat f_hess; // cost hessian
//    std::vector<AbsExpNodeSptr> g; // constraints
//    SparseOptMat g_grad; // constraint jacobian
//    std::vector<SparseOptMatSptr> g_hess; // constraint hessian
//    std::vector<AbsExpNodeSptr> temp_nodes_;
//    std::vector<AbsExpNodeSptr> active_nodes_;
//    
//    std::shared_ptr<OptStructure> _self_shared_ptr() { return shared_from_this();};
//    std::weak_ptr<OptStructure> _self_weak_ptr() { return std::weak_ptr<OptStructure>(_self_shared_ptr());};
//    
//    
//    
//    
//
//};

#endif	/* OPTSTRUCTURE_H */

