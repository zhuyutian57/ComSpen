#if !defined(LOGIC_PARSER_)
#define LOGIC_PARSER_
/*******************************************
*  @file  LogicParser.h                    * 
*  @brief    Brief file description        *
*                                          *
*  @author   Chong Gao                     *
*  @version  1.0                           *
*  @date     2018-12-3                     *
*                                          *
*******************************************/

#include "Parser.h"

namespace ComSpen {

/*! @class LogicParser
 *  @brief Brief class description
 *
 *  Detailed description
 */
class LogicParser : public Parser
{
public:
    LogicParser(z3::context& ctx, Z3Buffer& buffer)
        : Parser(ctx, buffer) {}
    virtual ~LogicParser() {}
    
    void parse(Table* table);
    void setLogic(string logic);

private:
    const string prefix="../config/Logics/";
    std::string logic;
};

}

#endif
