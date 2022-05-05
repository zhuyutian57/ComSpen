#if !defined(THEORY_PARSER_)
#define THEORY_PARSER_
/*******************************************
*  @file  TheoryParser.h                   * 
*  @brief    Brief file description        *
*                                          *
*  @author   Chong Gao                     *
*  @version  1.0                           *
*  @date     2018-12-3                     *
*                                          *
*******************************************/

#include "CommandParser.h"
#include "component/Z3Buffer.h"
#include "Parser.h"
#include "Types.h"

/*! @class TheoryParser
 *  @brief Brief class description
 *
 *  Detailed description
 */
class TheoryParser : public Parser
{
public:
    TheoryParser(z3::context& ctx, Z3Buffer& buffer)
        : Parser(ctx, buffer) {}
    virtual ~TheoryParser() {}

    void parse(Table* table);
    void setTheory(string theory);

private:
    const std::string prefix = "../config/Theories/";
    std::string theory;
    
    SortType* parseSort();
    void parseSorts(Table* table);
    vector<SortType*> parseSortsList(Table* table);
    FuncType* parseFun(Table* table);
    void parseFuns(Table* table);
};

#endif
