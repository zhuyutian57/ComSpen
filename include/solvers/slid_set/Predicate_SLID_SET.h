#if !defined(PREDICATE_SLID_SET_)
#define PREDICATE_SLID_SET_
/******************************************
*  @file  Predicate_SLID_SET.h             *
*  @brief  Brief file description          *
*                                          *
*  @author   Chong Gao                     *
*  @version  1.0                           *
*  @date     2019-2-18                     *
*                                          *
*******************************************/

#include "z3++.h"
#include "Types.h"
#include "component/Z3Buffer.h"
#include "component/Predicate.h"

namespace ComSpen {

class Predicate_SLID_SET:public Predicate {
public:
    Z3Buffer& z3_buffer;
    Predicate_SLID_SET(
        z3::context& ctx,
        Z3Buffer& buffer,
        std::string name,
        z3::expr_vector pars, z3::expr base, z3::expr rec);
    virtual ~Predicate_SLID_SET();

    void getABC(z3::expr_vector& alpha, z3::expr_vector& beta, z3::expr_vector& gamma);
    void getAlpha(z3::expr_vector& alpha);
    void getBeta(z3::expr_vector& beta);
    void getGamma(z3::expr_vector& gamma);
    void getX(z3::expr_vector& x);
    z3::expr_vector& getPars() {return m_pars;}
    z3::expr getFreeItem() {return m_free_item;}

    z3::expr getPhip() {return m_deltap;}

    z3::expr getUnfold1();
    z3::expr getUnfold2(z3::expr_vector& new_vars);

    z3::expr subPhiR2(z3::expr e1, z3::expr e2);
    z3::expr getDataItem(z3::expr e1);
    int getCase() {return m_case_i;}

    int getEinGamma();
    bool getStrt();
    z3::expr getTr();

    z3::expr apply(z3::expr_vector& args);
    z3::expr unfoldPredicate(z3::expr_vector& args);

    virtual void show();

private:
    z3::expr getDeltaP();

    z3::expr getTrPossiblelyEmpty();
    z3::expr getTrSurelyNonempty();
    z3::expr getUnfoldDeltap2();
    z3::expr getUnfoldDeltap3();

    void initSucc();
    void initStrtPars();
    int getCard(z3::expr& var, z3::expr_vector& svars);
    void setMatrix(int (&matrix)[4][4], int i, int j, int val);
    bool floyd(int (&matrix)[4][4]);
    z3::expr getIJExpr(int (&matrix)[4][4], int i, int j, z3::expr_vector& svars);
    z3::expr getIExpr(int i, z3::expr_vector& svars);

    string newName(string name, int i);

private:
    z3::expr m_data;
    z3::expr m_pto;
    z3::expr m_rec_app;
    z3::expr m_deltap;

    z3::expr m_succ;
    z3::expr_vector m_succ_pars;

    int m_case_i;
    z3::expr_vector m_svars;
    z3::expr_vector m_strt_items;
    z3::expr_vector m_strt_pars;

    z3::expr m_tr;
    z3::expr m_free_item;
};

}

#endif
