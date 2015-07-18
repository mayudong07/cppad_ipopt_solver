
// this is a function to overload the operators for ExpNodes


# include "ExpNodeADNumber.h"
/// get ADNumber from activenode
using namespace cppad_ipopt;

ADNumber get_ad_number(const ActiveNodeSptr n,  const ADVector& x){
    return x[n->index()];
}



ADNumber get_ad_number(const PassiveNodeSptr n,  const ADVector& x){
    return ADNumber(n->value());
}


ADNumber get_ad_number(const TempNodeSptr n,  const ADVector& x){
    if (n->is_unary_operator()){
        return n->get_operator()->eval(get_ad_number(n->right_operand(),x));
    }else{
        return n->get_operator()->eval(get_ad_number(n->left_operand(),x), get_ad_number(n->right_operand(),x));
    }
}

ADNumber get_ad_number(const AbsExpNodeSptr n,  const ADVector& x){
    if (n->is_active_exp_node()){
        return get_ad_number(boost::dynamic_pointer_cast<ActiveNode>(n), x);
    }else if (n->is_temp_exp_node()){
        return get_ad_number(boost::dynamic_pointer_cast<TempNode>(n), x);
    }else if (n->is_passive_exp_node()){
        return get_ad_number(boost::dynamic_pointer_cast<PassiveNode>(n), x);
    }else{
        assert(false);
    }
}


ADVector OptProbFGinfo::eval_r(size_t k, const ADVector&  x){
    // nm is the number of constraints + 1
    int m = opt_prob_ptr()->num_of_constraints();
    ADVector fg(m+1);
    
    // f(x)
    fg[0] = get_ad_number(opt_prob_ptr()->cost_var(), x);
    // g_1 (x)
    for (int i=0;i<m;i++){
        fg[i+1] = get_ad_number(opt_prob_ptr()->constraints_vec()[i], x);
    }
    return fg;
}