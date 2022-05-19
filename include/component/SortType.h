#if !defined(SORT_TYPE_)
#define SORT_TYPE_
/*******************************************
*  @file  SortType.h                       * 
*  @brief    Brief file description        *
*                                          *
*  @author   Chong Gao                     *
*  @version  1.0                           *
*  @date     2018-11-7                     *
*                                          *
*******************************************/

#include "Types.h"
#include "z3++.h"

namespace ComSpen {

/*! @class SortType
 *  @brief Brief class description
 *
 *  Detailed description
 */
class SortType
{
public:
	z3::context& z3_ctx;
    SortType(z3::context& ctx, string sort_name, int sort_size)
        : z3_ctx(ctx), m_sort_name(sort_name), m_sort_size(sort_size) {}
    SortType(SortType* st)
        : z3_ctx(st->z3_ctx), m_sort_name(st->m_sort_name), m_sort_size(st->m_sort_size) {
        if (!st->subTypes.empty())
            subTypes = st->subTypes;
    }
    virtual ~SortType() {}

    void addSubType(std::string subType);

    int getArity();
    string getName();
    std::string getSubType(int idx);
    std::string getSort();

    operator z3::sort();

protected:
    string m_sort_name; ///< Member description
    int m_sort_size; ///< sort size
    vector<std::string> subTypes;
};

}

#endif
