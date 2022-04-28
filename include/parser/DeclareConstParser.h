#if !defined(DECLCONSTPARSER_H)
#define DECLCONSTPARSER_H
/*******************************************
*  @file  DeclareConstParser.h                *
*  @brief  Brief file description          *
*                                          *
*  @author   Chong Gao                     *
*  @version  1.0                           *
*  @date     2018-12-3                     *
*                                          *
*******************************************/

#include "CommandParser.h"

class DeclareConstParser: public CommandParser
{
public:
    DeclareConstParser(z3::context& ctx, Z3Buffer& buffer): CommandParser(ctx, buffer) { }
    virtual ~DeclareConstParser() { }

    virtual void parse(Table* table);
};

#endif
