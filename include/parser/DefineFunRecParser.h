#if !defined(DEFINE_FUN_REC_PARSER_)
#define DEFINE_FUN_REC_PARSER_
/*******************************************
*  @file  DefineFunRecParser.h        * 
*  @brief    Brief file description        *
*                                          *
*  @author   Chong Gao                     *
*  @version  1.0                           *
*  @date     2018-11-7                     *
*                                          *
*******************************************/

#include "CommandParser.h"

namespace ComSpen {

/*! @class DefineFunRecParser
 *  @brief Brief class description
 *
 *  Detailed description
 */
class DefineFunRecParser: public CommandParser
{
public:
    DefineFunRecParser(z3::context& ctx, Z3Buffer& buffer): CommandParser(ctx, buffer) {}
    virtual ~DefineFunRecParser() {}

    virtual void parse(Table* table);
    void checkSLAHRecRule(Table* table, z3::expr rec, string fname);
};

}

#endif
