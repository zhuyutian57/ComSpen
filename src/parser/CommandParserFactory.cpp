/*******************************************
*  @file  CommandParserFactory.cpp         * 
*  @brief    Brief file description        *
*                                          *
*  @author   Chong Gao                     *
*  @version  1.0                           *
*  @date     2018-12-3                     *
*                                          *
*******************************************/

#include "parser/CommandParserFactory.h"

/*! @brief Brief function description here
 *
 *  Detailed description
 *
 * @param sign Parameter description
 * @return Return parameter description
 */

CommandParserFactory::CommandParserFactory(z3::context& z3_ctx, Z3Buffer& z3_buffer) {
    factory["set-logic"] = new SetLogicParser(z3_ctx, z3_buffer);
    factory["set-info"] = new SetInfoParser(z3_ctx, z3_buffer);
    factory["declare-sort"] = new DeclareSortParser(z3_ctx, z3_buffer); 
    factory["declare-datatypes"] = new DeclareDatatypesParser(z3_ctx, z3_buffer);
    factory["declare-heap"] = new DeclareHeapParser(z3_ctx, z3_buffer); 
    factory["define-fun"] = new DefineFunParser(z3_ctx, z3_buffer); 
    factory["define-fun-rec"] = new DefineFunRecParser(z3_ctx, z3_buffer); 
    factory["declare-const"] = new DeclareConstParser(z3_ctx, z3_buffer); 
    factory["assert"] = new AssertParser(z3_ctx, z3_buffer); 
    factory["check-sat"] = new CheckSatParser(z3_ctx, z3_buffer); 
    factory["declare-fun"] = new DeclareFunParser(z3_ctx, z3_buffer);
}

CommandParser* CommandParserFactory::getCommandParser(const string& cmd) {
    return factory[cmd];
}
