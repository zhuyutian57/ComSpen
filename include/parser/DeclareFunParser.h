#if !defined(DECLARE_FUN_PARSER_)
#define DECLARE_FUN_PARSER_

#include "component/Field.h"
#include "CommandParser.h"

/*! @class DeclareFunParser
 *  @brief Brief class description
 *
 *  Detailed description
 */
class DeclareFunParser: public CommandParser
{
public:
    DeclareFunParser(z3::context& ctx, Z3Buffer& buffer)
      : CommandParser(ctx, buffer) {}
    virtual ~DeclareFunParser() {}

    virtual void parse(Table* table);

};

#endif
