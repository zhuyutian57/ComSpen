#if !defined(DECLHEAPPARSER_H)
#define DECLHEAPPARSER_H
/*******************************************
*  @file  DeclareHeapParser.h                 *
*  @brief  Brief file description          *
*                                          *
*  @author   Chong Gao                     *
*  @version  1.0                           *
*  @date     2018-12-3                     *
*                                          *
*******************************************/

#include "CommandParser.h"

class DeclareHeapParser: public CommandParser
{
public:
    DeclareHeapParser(z3::context& ctx, Z3Buffer& buffer): CommandParser(ctx, buffer) { }
    virtual ~DeclareHeapParser() { }

    virtual void parse(Table* table);
};

#endif
