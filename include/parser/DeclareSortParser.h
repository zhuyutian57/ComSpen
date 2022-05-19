#if !defined(DECL_SORT_PARSER_)
#define DECL_SORT_PARSER_
/*******************************************
*  @file  DeclareSortParser.h                 * 
*  @brief    Brief file description        *
*                                          *
*  @author   Chong Gao                     *
*  @version  1.0                           *
*  @date     2018-11-7                     *
*                                          *
*******************************************/

#include "CommandParser.h"

namespace ComSpen {

/*! @class DeclareSortParser
 *  @brief Brief class description
 *
 *  Detailed description
 */
class DeclareSortParser: public CommandParser
{
public:
    DeclareSortParser(z3::context& ctx, Z3Buffer& buffer): CommandParser(ctx, buffer) {}
    virtual ~DeclareSortParser() {}

    virtual void parse(Table* table);
};

}

#endif
