#if !defined(FUNC_TYPE_)
#define FUNC_TYPE_
/*******************************************
*  @file  FuncType.h                       * 
*  @brief    Brief file description        *
*                                          *
*  @author   Chong Gao                     *
*  @version  1.0                           *
*  @date     2018-11-7                     *
*                                          *
*******************************************/

#include "component/SortType.h"
#include "component/Z3Buffer.h"
#include "parser/Table.h"
#include "Types.h"
#include "z3++.h"


using SortList = vector<SortType*>;


/*! @class FuncType
 *  @brief Brief class description
 *
 *  Detailed description
 */
class FuncType
{
public:
	z3::context& z3_ctx;
	Z3Buffer& z3_buffer;
    FuncType(z3::context& ctx, Z3Buffer& buffer, string name, string attr="", bool determine=true)
        :z3_ctx(ctx), z3_buffer(buffer), m_name(name), m_attr(attr), m_determine(determine){}
    virtual void addArg(SortType* arg) {m_arg_sort_list.push_back(arg);}
    virtual void addPar(SortType* par) {}
    void setName(string name) { m_name = name; }
    void setAttr(string attr) { m_attr = attr; }
    virtual ~FuncType() {}

    virtual string getName() {return m_name;}
    virtual string getRange() {return m_arg_sort_list.back()->getSort();}
    virtual bool isDetermine() {return m_determine;}

    virtual z3::func_decl determine(SortList& arg_type_list, Table* table);

    SortList& getArgList() { return m_arg_sort_list; }

    virtual void show(); 

protected:
    string m_name; ///< Member description
    SortList m_arg_sort_list; ///< parameter list
    string m_attr; ///< associate type
    bool m_determine; ///< arg_list whether determine
};



/*! @class ParFuncType
 *  @brief Brief class description
 *
 *  Detailed description
 */
class ParFuncType :public FuncType
{
public:
    ParFuncType(z3::context& ctx, Z3Buffer& buffer, string name)
        : FuncType(ctx, buffer, name, "", false) {}
    virtual ~ParFuncType() {}
    virtual void addPar(SortType* par) { m_par_list.push_back(par); }
    virtual z3::func_decl determine(SortList& arg_type_list, Table* table);
    virtual void show(); 

protected:
    SortList m_par_list; ///< Member description

private:
    bool isPar(std::string s);
    bool checkEqual(
        std::string label,
        std::string type,
        std::map<std::string, std::string>& mp);
};

#endif
