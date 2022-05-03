/*******************************************
*  @file  SortType.cpp                     *
*  @brief  Brief file description          *
*                                          *
*  @author   Chong Gao                     *
*  @version  1.0                           *
*  @date     2018-12-3                     *
*                                          *
*******************************************/

#include "component/SortType.h"

//extern z3::context z3_ctx;

string SortType::getName() { return m_sort_name; }

int SortType::getArity() { return m_sort_size; }

void SortType::addSubType(string subType) {
    assert(subTypes.size() < m_sort_size);
    subTypes.push_back(subType);
}

std::string SortType::getSubType(int idx) {
    assert(idx < m_sort_size);
    return subTypes[idx];
}

std::string SortType::getSort() {
    std::string sort = m_sort_name;
    for(std::string subType : subTypes)
        sort += "_" + subType;
    return sort;
}


SortType::operator z3::sort() {
    string sort = this->getSort();
    if (sort == "Bool") {
        return z3_ctx.bool_sort();
    } else if (sort == "Int") {
        return z3_ctx.int_sort();
    } else if (sort == "Float") {
        return z3_ctx.real_sort();
    } else {
        return z3_ctx.uninterpreted_sort(sort.c_str());
    }
}
