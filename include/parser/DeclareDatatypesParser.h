#if !defined(DECLDATATYPESPARSER_H)
#define DECLDATATYPESPARSER_H
/*******************************************
*  @file  DeclareDatatypesParser.h            *
*  @brief  Brief file description          *
*                                          *
*  @author   Chong Gao                     *
*  @version  1.0                           *
*  @date     2018-12-3                     *
*                                          *
*******************************************/

#include "CommandParser.h"

namespace ComSpen {

class DeclareDatatypesParser: public CommandParser
{
public:
    DeclareDatatypesParser(z3::context& ctx, Z3Buffer& buffer): CommandParser(ctx, buffer) { }
    virtual ~DeclareDatatypesParser() { }

    virtual void parse(Table* table);

};

}

#endif


