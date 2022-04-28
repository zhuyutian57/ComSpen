#if !defined(COMMAND_PARSER_BUFFER_)
#define COMMAND_PARSER_BUFFER_
/*******************************************
*  @file  CommandParserBuffer.h            * 
*  @brief    Brief file description        *
*                                          *
*  @author   Chong Gao                     *
*  @version  1.0                           *
*  @date     2018-12-3                     *
*                                          *
*******************************************/

#include <map>

#include "parser/CommandParser.h"
#include "parser/SetLogicParser.h"
#include "parser/SetInfoParser.h"
#include "parser/DeclareSortParser.h"
#include "parser/DeclareDatatypesParser.h"
#include "parser/DeclareHeapParser.h"
#include "parser/DefineFunParser.h"
#include "parser/DefineFunRecParser.h"
#include "parser/DeclareConstParser.h"
#include "parser/AssertParser.h"
#include "parser/CheckSatParser.h"

using std::map;
using std::string;

class CommandParser;

/*! @class CommandParserBuffer
 *  @brief Brief class description
 *
 *  Detailed description
 */
class CommandParserBuffer
{
public:
    CommandParserBuffer(z3::context& z3_ctx, Z3Buffer& z3_buffer); 
    virtual ~CommandParserBuffer(); 

    CommandParser* getCommandParser();

    DeclareHeapParser* getDeclareHeapParser();

    DeclareSortParser* getDeclareSortParser();

    DeclareDatatypesParser* getDeclareDatatypesParser();

    SetLogicParser* getSetLogicParser();
    
    SetInfoParser* getSetInfoParser();
    
    DefineFunParser* getDefineFunParser();

    DefineFunRecParser* getDefineFunRecParser();

    DeclareConstParser* getDeclareConstParser();

    AssertParser* getAssertParser();

    CheckSatParser* getCheckSatParser();

protected:
    map<string, CommandParser*> m_buffer; ///< Member description
};


#endif
