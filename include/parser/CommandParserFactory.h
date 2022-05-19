#if !defined(COMMAND_PARSER_FACTORY_)
#define COMMAND_PARSER_FACTORY_

/*******************************************
*  @file  CommandParserFactory.h           * 
*  @brief    Brief file description        *
*                                          *
*  @author   Chong Gao                     *
*  @version  1.0                           *
*  @date     2018-11-7                     *
*                                          *
*******************************************/

#include "CommandParser.h"
#include "AssertParser.h"
#include "CheckSatParser.h"
#include "DeclareConstParser.h"
#include "DeclareConstParser.h"
#include "DeclareDatatypesParser.h"
#include "DeclareFunParser.h"
#include "DeclareHeapParser.h"
#include "DeclareSortParser.h"
#include "DefineFunParser.h"
#include "DefineFunRecParser.h"
#include "SetInfoParser.h"
#include "SetLogicParser.h"
#include "Types.h"

namespace ComSpen {

/*! @class CommandParserFactory
 *  @brief Brief class description
 *
 *  Detailed description
 */

class CommandParserFactory {

public:
    CommandParserFactory(z3::context& z3_ctx, Z3Buffer& z3_buffer);
    virtual ~CommandParserFactory() {}

    CommandParser* getCommandParser(const string& cmd); 

private:
    std::map<std::string, CommandParser*> factory;
};

}

#endif
