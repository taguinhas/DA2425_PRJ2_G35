#include <glpk.h>
#include <chrono>
#include "../makeOutput.h"

void integer_linear_programming(
    std::vector<int> &values,
    std::vector<int> &weights,
    int &n_pallets,
    int &capacity,
    std::vector<bool> &usedItems
){
    std::chrono::time_point start = std::chrono::high_resolution_clock::now();

    double sizePenalty = 1e-3;
    double indexPenalty = 1e-6;

    glp_prob *problem = glp_create_prob();
    glp_set_obj_dir(problem, GLP_MAX);


    glp_add_cols(problem, n_pallets); //one variable for each pallet

    for (int i = 1; i <= n_pallets; i++){
        glp_set_col_bnds(problem, i, GLP_LO, 0.0, 0.0); //each variable has a lower bound of 0
    }

    for (int i = 1; i <= n_pallets; i++){
        double adjusted_coef = values[i - 1] - sizePenalty - i * indexPenalty;
        glp_set_obj_coef(problem, i, adjusted_coef);
        glp_set_col_kind(problem, i, GLP_IV); //we want all our variables to be integers (either 1 or 0)
    }


    glp_add_rows(problem, n_pallets + 1); //there is going to be one constraint for each pallet (<=1) and one for the total weight <= capacity

    for (int i = 1; i <= n_pallets; i++){
        glp_set_row_bnds(problem, i, GLP_UP, 0.0, 1.0); //for each pallet, the quantity can be maximum 1
    }

    glp_set_row_bnds(problem, n_pallets + 1, GLP_UP, 0.0, capacity); //add constraint for max weight


    //have to initialize all with 0 (glp does not deal with indexes 0)
    std::vector<int> constraints_index = {0}; //what constraint we are referring to
    std::vector<int> variables_index = {0}; //what variable we are referring to
    std::vector<double> var_coeficient = {0}; //what is the coeficient of that variable in that constraint

    for (int i = 1; i <= n_pallets; i++){ //for each constraint
        for (int j = 1; j <= n_pallets; j++){ //for each variable
            constraints_index.push_back(i); //add the index of the constraint we are working with
            variables_index.push_back(j); //add the index of the variable we are working with
            var_coeficient.push_back(i == j ? 1 : 0); //if the index of the var is equal to the constraint, it's the constraint of this var
        }
    }

    for (int i = 1; i <= n_pallets; i++){ //iterate through the variables in the last constraint (max weight)
        constraints_index.push_back(n_pallets + 1); //it's always this constraint we are working with
        variables_index.push_back(i);
        var_coeficient.push_back(weights[i-1]); //the coeficient of each variable is its weight
    }

    //load our data into the matrix
    glp_load_matrix(problem, n_pallets * (n_pallets + 1), constraints_index.data(), variables_index.data(), var_coeficient.data());


    //solve with the integer optimizer
    glp_iocp param;
    glp_init_iocp(&param);
    param.presolve = GLP_ON;
    param.msg_lev = GLP_MSG_ERR;

    if(glp_intopt(problem, &param)){ //if it returns different than 0 there is a problem
        std::cerr << "Error solving the integer linear programming problem." << std::endl;
        return;
    }

    for (int i = 1; i <= n_pallets; i++){
        usedItems[i-1] = (glp_mip_col_val(problem, i) == 1);
    }

    glp_delete_prob(problem);

    std::chrono::time_point stop = std::chrono::high_resolution_clock::now();

    output(capacity, n_pallets, weights, values, usedItems, std::chrono::duration_cast<std::chrono::microseconds>(stop-start).count());
}