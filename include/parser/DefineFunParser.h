#if !defined(DEFINE_FUN_PARSER_)
#define DEFINE_FUN_PARSER_
/*******************************************
*  @file  DefineFunParser.h           * 
*  @brief    Brief file description        *
*                                          *
*  @author   Wanyun Su                     *
*  @version  1.0                           *
*  @date     2021-4-8                      *
*                                          *
*******************************************/

#include "CommandParser.h"

namespace ComSpen {

/*! @class DefineFunctionRecParser
 *  @brief Brief class description
 *
 *  Detailed description
 */
class DefineFunParser: public CommandParser
{
public:
    DefineFunParser(z3::context& ctx, Z3Buffer& buffer): CommandParser(ctx, buffer) {}
    virtual ~DefineFunParser() {}

    virtual void parse(Table* table);
};

}

#endif
