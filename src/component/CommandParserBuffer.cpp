/*******************************************
*  @file  CommandParserBuffer.cpp          * 
*  @brief    Brief file description        *
*                                          *
*  @author   Chong Gao                     *
*  @version  1.0                           *
*  @date     2018-12-3                     *
*                                          *
*******************************************/

#include "component/CommandParserBuffer.h"

CommandParserBuffer::CommandParserBuffer(z3::context& z3_ctx, Z3Buffer& z3_buffer) {
    m_buffer["SetLogicParser"] = new SetLogicParser(z3_ctx, z3_buffer);
    m_buffer["SetInfoParser"] = new SetInfoParser(z3_ctx, z3_buffer);
    m_buffer["CommandParser"] = new CommandParser(z3_ctx, z3_buffer); 
    m_buffer["DeclareSortParser"] = new DeclareSortParser(z3_ctx, z3_buffer); 
    m_buffer["DeclareDatatypesParser"] = new DeclareDatatypesParser(z3_ctx, z3_buffer);
    m_buffer["DeclareHeapParser"] = new DeclareHeapParser(z3_ctx, z3_buffer); 
    m_buffer["DefineFunParser"] = new DefineFunParser(z3_ctx, z3_buffer); 
    m_buffer["DefineFunRecParser"] = new DefineFunRecParser(z3_ctx, z3_buffer); 
    m_buffer["DeclareareConstParser"] = new DeclareConstParser(z3_ctx, z3_buffer); 
    m_buffer["AssertParser"] = new AssertParser(z3_ctx, z3_buffer); 
    m_buffer["CheckSatParser"] = new CheckSatParser(z3_ctx, z3_buffer); 

}

CheckSatParser* CommandParserBuffer::getCheckSatParser() {
    return dynamic_cast<CheckSatParser*>(m_buffer["CheckSatParser"]);
}

DeclareConstParser* CommandParserBuffer::getDeclareConstParser() {
    return dynamic_cast<DeclareConstParser*>(m_buffer["DeclareareConstParser"]);
}

AssertParser* CommandParserBuffer::getAssertParser() {
    return dynamic_cast<AssertParser*>(m_buffer["AssertParser"]);
}

DefineFunParser* CommandParserBuffer::getDefineFunParser() {
    return dynamic_cast<DefineFunParser*>(m_buffer["DefineFunParser"]);
}

DefineFunRecParser* CommandParserBuffer::getDefineFunRecParser() {
    return dynamic_cast<DefineFunRecParser*>(m_buffer["DefineFunRecParser"]);
}

DeclareHeapParser* CommandParserBuffer::getDeclareHeapParser() {
    return dynamic_cast<DeclareHeapParser*>(m_buffer["DeclareHeapParser"]);
}

DeclareDatatypesParser* CommandParserBuffer::getDeclareDatatypesParser() {
    return dynamic_cast<DeclareDatatypesParser*>(m_buffer["DeclareDatatypesParser"]);
}

DeclareSortParser* CommandParserBuffer::getDeclareSortParser() {
    return dynamic_cast<DeclareSortParser*>(m_buffer["DeclareSortParser"]);
}

CommandParser* CommandParserBuffer::getCommandParser() {
    return m_buffer["CommandParser"];
}

SetLogicParser* CommandParserBuffer::getSetLogicParser() {
    return dynamic_cast<SetLogicParser*>(m_buffer["SetLogicParser"]);
}

SetInfoParser* CommandParserBuffer::getSetInfoParser() {
	return dynamic_cast<SetInfoParser*>(m_buffer["SetInfoParser"]);
}

CommandParserBuffer::~CommandParserBuffer() {
    for (auto item : m_buffer) {
        if (item.second != nullptr)
            delete item.second;
    }
}
