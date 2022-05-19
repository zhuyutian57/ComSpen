/*******************************************
*  @file  Var.cpp                          *
*  @brief  Brief file description          *
*                                          *
*  @author   Chong Gao                     *
*  @version  1.0                           *
*  @date     2018-12-3                     *
*                                          *
*******************************************/

#include "component/Var.h"

using namespace ComSpen;

Var::operator z3::expr() {
    z3::sort& s = z3_buffer.getSort(m_sort_type);
    return z3_ctx.constant(m_var_name.c_str(), s); 
}
