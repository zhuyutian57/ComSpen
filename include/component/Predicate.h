#if !defined(PREDICATE_)
#define PREDICATE_
/******************************************
*  @file  Predicate.h                      *
*  @brief  Brief file description          *
*                                          *
*  @author   WanYun Su                     *
*  @version  1.0                           *
*  @date     2021-2-20                     *
*                                          *
*******************************************/

#include "z3++.h"
#include "Types.h"

namespace ComSpen {

class Predicate {
public:
	z3::context& z3_ctx;
    Predicate(
        z3::context& ctx,
        std::string name,
        z3::expr_vector pars,
        z3::expr base,
        z3::expr rec);
    virtual ~Predicate() {}

    std::string getName();

    virtual void show();

protected:
    std::string name;
    z3::expr_vector m_pars;
    z3::expr m_base_rule;
    z3::expr m_rec_rule;
};

}

#endif
