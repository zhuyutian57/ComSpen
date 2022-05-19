/*******************************************
*  @file  BufferPool.cpp                   * 
*  @brief    Brief file description        *
*                                          *
*  @author   Chong Gao                     *
*  @version  1.0                           *
*  @date     2018-12-3                     *
*                                          *
*******************************************/

#include "scanner/TokenBuffer.h"
#include "component/Z3Buffer.h"
#include "scanner/TokenScannerFactory.h"
#include "parser/CommandParserFactory.h"
#include "Types.h"

namespace ComSpen {

TokenScannerFactory tokenScannerFactory;
TokenBuffer token_buffer;
TokenScannerBuffer token_scanner_buffer;

}