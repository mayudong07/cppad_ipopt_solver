/* 
 * File:   PyVariable.cpp
 * Author: yudong
 * 
 * Created on July 9, 2015, 12:59 PM
 */

#include "PyVariable.h"

AbsExpNodeSptr PyVar::decode(const std::vector<ActiveNodeSptr> &active, const std::vector<TempNodeSptr> &temp){
    AbsExpNodeSptr n;
    switch(type){
        case 0: break;
        case 1: n = AbsExpNodeSptr (active[index]); break;
        case 2: n = AbsExpNodeSptr (temp[index]);break;
        case 3: n = AbsExpNodeSptr (boost::make_shared<PassiveNode>(value));break;
        default: break;
    }
    return n;
}

AbsExpNodeSptr PyExpNode::decode(std::vector<ActiveNodeSptr> &active, std::vector<TempNodeSptr> &temp){
    AbsExpNodeSptr res_var = result.decode(active, temp);
    AbsExpNodeSptr lvar = l_operand.decode(active, temp);
    AbsExpNodeSptr rvar = r_operand.decode(active, temp);
    AbsOperaterSptr op = decode_operator(operator_code);
    if (res_var->is_temp_exp_node()){
        // there is a temp expression node
        boost::shared_ptr<TempNode> res_tmp_ptr = boost::dynamic_pointer_cast<TempNode>(res_var);
        assert(res_tmp_ptr);
        res_tmp_ptr->set_left_operand(lvar);
        res_tmp_ptr->set_right_operand(rvar);
        res_tmp_ptr->set_operator(op);
    } else{
        // this is not a temp expression. then all the rest should be null
        assert(!lvar);
        assert(!rvar);
        assert(!op);
    }
    
    return res_var;
}


AbsExpNodeSptr PyTape::decode(std::vector<ActiveNodeSptr> &active, std::vector<TempNodeSptr> &temp){
    AbsExpNodeSptr result;
    for (std::vector<PyExpNode>::iterator it = tape.begin() ; it != tape.end(); ++it){
        result=(*it).decode(active, temp);
    }
    return result;
}





inline AbsExpNodeSptr decode_pyvar(const PyVariableObject &v, const std::vector<ActiveNodeSptr> &active, const std::vector<TempNodeSptr> &temp){
    AbsExpNodeSptr n;
    switch(v.first.first){
        case 0: break;
        case 1: n = AbsExpNodeSptr (active[v.first.second]); break;
        case 2: n = AbsExpNodeSptr (temp[v.first.second]);break;
        case 3: n = AbsExpNodeSptr (boost::make_shared<PassiveNode>(v.second));break;
        default: break;
    }
    return n;
}
AbsExpNodeSptr decode_pynode(const PyExpNodeObject &n, const std::vector<ActiveNodeSptr> &active, const std::vector<TempNodeSptr> &temp){
    AbsExpNodeSptr res_var = decode_pyvar(n.first[2], active, temp);
    AbsExpNodeSptr lvar = decode_pyvar(n.first[0], active, temp);
    AbsExpNodeSptr rvar = decode_pyvar(n.first[1], active, temp);
    AbsOperaterSptr op = decode_operator(n.second);
    if (res_var->is_temp_exp_node()){
        // there is a temp expression node
        boost::shared_ptr<TempNode> res_tmp_ptr = boost::dynamic_pointer_cast<TempNode>(res_var);
        assert(res_tmp_ptr);
        res_tmp_ptr->set_left_operand(lvar);
        res_tmp_ptr->set_right_operand(rvar);
        res_tmp_ptr->set_operator(op);
    } else{
        // this is not a temp expression. then all the rest should be null
        assert(!lvar);
        assert(!rvar);
        assert(!op);
    }
    
    return res_var;
}
AbsExpNodeSptr decode_pytape(const PyTapeObject &t, const std::vector<ActiveNodeSptr> &active, const std::vector<TempNodeSptr> &temp){
    AbsExpNodeSptr result;
    for (PyTapeObject::const_iterator it = t.begin() ; it != t.end(); ++it){
        result=decode_pynode((*it), active, temp);
    }
    return result;
}



std::string print_pyvar(const PyVariableObject &v){
    std::string s;
    s+="(";
    s+=std::to_string(v.first.first);
    s+=",";
    s+=std::to_string(v.first.second);
    s+=")";
    return s;
}


std::string print_pynode(const PyExpNodeObject &n){
    std::string s;
    s+="{";
    s+=print_pyvar(n.first[0]);
    s+=print_pyvar(n.first[1]);
    s+=print_pyvar(n.first[2]);
    s+="}";
    return s;
            
}


std::string print_pytape(const PyTapeObject &t){
    std::string s;
    s+="[";
    for (PyTapeObject::const_iterator it = t.begin() ; it != t.end(); ++it){
        s+=print_pynode((*it));
    }
    s+="]";
    return s;
}