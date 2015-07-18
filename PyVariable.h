/* 
 * File:   PyVariable.h
 * Author: yudong
 *
 * Created on July 9, 2015, 12:59 PM
 */

#ifndef PYVARIABLE_H
#define	PYVARIABLE_H

#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/make_shared.hpp>
#include <vector>
#include <utility>
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
//mad_var.first indicates the type of variable 1=defined_variable, 2=temp variable, 3=const numbers, 0=null
//mad_var.second indicates the index of the variable in the entire problem.
// if mad_var.first is null, means this variable is undefined.
static AbsOperaterSptr decode_operator(int o) {
    AbsOperaterSptr op;
    switch(o){
        case -1: break; // operator with -1 code is a null operator 
        case 0: op = Addition::get_instance(); break;
        case 1: op = Subtraction::get_instance(); break;
        case 2: op = Multiplication::get_instance(); break;
        case 3: op = Division::get_instance(); break;
        case 5: op = Power::get_instance(); break;
        case 43: op = Logarithm::get_instance(); break;
        case 44: op = Exponential::get_instance(); break;
        default: break;
    }
    return op;
}
static std::string encode_operator(AbsOperaterSptr o) {}



struct PyVar{
    int type; //the type of variable
    int index; // the index of variable
    double value; // initial guess
    PyVar():type(0), index(0), value(0){};
    PyVar(int t, int i):type(t), index(i), value(0){};
    PyVar(int t, int i, double v):type(t), index(i), value(v){};
    PyVar(AbsExpNodeSptr);
    ~PyVar(){};
    AbsExpNodeSptr decode(const std::vector<ActiveNodeSptr> &active, const std::vector<TempNodeSptr> &temp);
};

struct PyExpNode{
    PyVar l_operand;
    int operator_code; // the operator code following the document http://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.60.9659&rep=rep1&type=pdf
                       // however if the operator_code is -999, there is no operator required and the result is a defined variable
    PyVar r_operand;
    PyVar result;
    PyExpNode(){};
    PyExpNode(int lt, int li, int op, int rt, int ri, int res_t, int res_i): 
            l_operand(lt, li), operator_code(op), r_operand(rt, ri), result(res_t, res_i){};
    PyExpNode(AbsExpNodeSptr);
    ~PyExpNode(){};
    // give the mad exp node info, create a expression node
    AbsExpNodeSptr decode(std::vector<ActiveNodeSptr> &active, std::vector<TempNodeSptr> &temp);
};

struct PyTape{
    std::vector<PyExpNode> tape;
    
    PyTape(){};
    PyTape(AbsExpNodeSptr){};
    ~PyTape(){};
    void push_back_node(PyExpNode &node){tape.push_back(node);};
    AbsExpNodeSptr decode(std::vector<ActiveNodeSptr> &active, std::vector<TempNodeSptr> &temp);
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////// python representation objects/////////////////////////////////////////////////
/////////// THe following types can automatically converted to cython and python objects
typedef std::pair<int , int > Loc;
typedef std::pair<Loc, double> PyVariableObject;
typedef std::vector<PyVariableObject> PyVarObjectVec;
typedef std::pair<PyVarObjectVec, int> PyExpNodeObject;
typedef std::vector<PyExpNodeObject> PyTapeObject;

class PyOptProbObject{
public:
    int n; // number of defined variables
    int t; // number of temp variables
    std::vector<PyTapeObject> constraints;
    PyTapeObject cost;
    int num_of_constraints() const{return constraints.size();};
};
inline AbsExpNodeSptr decode_pyvar(const PyVariableObject &v, const std::vector<ActiveNodeSptr> &active, const std::vector<TempNodeSptr> &temp);
AbsExpNodeSptr decode_pynode(const PyExpNodeObject &n, const std::vector<ActiveNodeSptr> &active, const std::vector<TempNodeSptr> &temp);
AbsExpNodeSptr decode_pytape(const PyTapeObject &t, const std::vector<ActiveNodeSptr> &active, const std::vector<TempNodeSptr> &temp);


std::string print_pyvar(const PyVariableObject &v);
std::string print_pynode(const PyExpNodeObject &n);
std::string print_pytape(const PyTapeObject &t);

#endif	/* PYVARIABLE_H */

