#include <glpk.h>
#include <chrono>
#include "../makeOutput.h"
#include "../algorithms.h"

void integer_linear_programming(
    std::vector<int> &values,
    std::vector<int> &weights,
    int &n_pallets,
    int &capacity,
    std::vector<bool> &usedItems
)
{
    std::chrono::time_point start = std::chrono::high_resolution_clock::now();

    glp_prob *problem = glp_create_prob();
    glp_set_obj_dir(problem, GLP_MAX);


    glp_add_cols(problem, n_pallets); //one variable for each pallet

    for (int i = 1; i <= n_pallets; i++){
        glp_set_col_bnds(problem, i, GLP_DB, 0.0, 1.0);
        glp_set_col_kind(problem, i, GLP_BV);
    }

    double sizePenalty = 0.1;
    double indexPenalty = 0.000005;

    for (int i = 1; i <= n_pallets; i++){
        double adjusted_coef = values[i - 1] - sizePenalty - i * indexPenalty;
        glp_set_obj_coef(problem, i, adjusted_coef);
    }


    glp_add_rows(problem, 1); //there is going to be one constraint for the total weight <= capacity

    glp_set_row_bnds(problem, 1, GLP_UP, 0.0, capacity); //add constraint for max weight


    //have to initialize all with 0 (glp does not deal with indexes 0)
    std::vector<int> constraints_index = {0}; //what constraint we are referring to
    std::vector<int> variables_index = {0}; //what variable we are referring to
    std::vector<double> var_coeficient = {0}; //what is the coeficient of that variable in that constraint

    for (int i = 1; i <= n_pallets; i++){ //iterate through the variables in the last constraint (max weight)
        constraints_index.push_back(1); //it's always this constraint we are working with
        variables_index.push_back(i);
        var_coeficient.push_back(weights[i-1]); //the coeficient of each variable is its weight
    }

    glp_load_matrix(problem, n_pallets, constraints_index.data(), variables_index.data(), var_coeficient.data());


    glp_iocp param;
    glp_init_iocp(&param);
    param.presolve = GLP_ON;
    param.msg_lev = GLP_OFF;
    param.tm_lim = 10000;

    int ret = glp_intopt(problem, &param);

    if(glp_intopt(problem, &param)){
        std::cerr << "The program was terminated as it took longer than 10 seconds.\n";
        glp_delete_prob(problem);
        return;
    }

    for (int i = 1; i <= n_pallets; i++){
        usedItems[i-1] = (glp_mip_col_val(problem, i) == 1);
    }

    glp_delete_prob(problem);

    std::chrono::time_point stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    output(capacity, n_pallets, weights, values, usedItems, duration.count());
}