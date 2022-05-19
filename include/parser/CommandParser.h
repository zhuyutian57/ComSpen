#if !defined(COMMAND_PARSER_)
#define COMMAND_PARSER_
/*******************************************
*  @file  CommandParser.h                  * 
*  @brief    Brief file description        *
*                                          *
*  @author   Chong Gao                     *
*  @version  1.0                           *
*  @date     2018-11-7                     *
*                                          *
*******************************************/

#include "Parser.h"

namespace ComSpen {

using SortTypeList = vector<SortType*>;
using SelectorDec = pair<string, SortType*>;
using SelectorDecList = vector<SelectorDec>;
using ConstructorDec = pair<string, SelectorDecList>;
using ConstructorDecList = vector<ConstructorDec>;

/*! @class CommandParser
 *  @brief Brief class description
 *
 *  Detailed description
 */
class CommandParser : public Parser
{
public:
    CommandParser(z3::context& ctx, Z3Buffer& buffer)
        : Parser(ctx, buffer), m_paren_counter(0) {}
    virtual ~CommandParser() {}

    virtual void parse(Table* table);
    void setScanner(Scanner* scanner);
    void setFile(string file);

protected:
    int m_paren_counter;

    SortType* parseSortDecl(Table* table);
    void parseSortDeclList(Table* table, SortTypeList& st_list);
    void parseSelectorDecl(Table* table, SelectorDec& sel_dec);
    void parseSelectorDeclList(Table* table, SelectorDecList& sd_list);
    void parseConstructorDecl(Table* table, ConstructorDec& con_dec);
    void parseConstructorDeclList(Table* table, ConstructorDecList& cd_list);

    void parseParameters(Table* table);
    z3::expr parseExpr(Table* table);
    z3::expr parseExists(Table* table);
    SortType* parseSort(Table* table);

private:
    z3::expr mk_app(FuncType* pf, z3::expr_vector args, SortList& args_types, Table* table);
};

}

#endif
