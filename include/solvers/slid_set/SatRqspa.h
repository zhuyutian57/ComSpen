#ifndef SAT_RQSPA_H
#define SAT_RQSPA_H

#include "FA.h"
#include "z3++.h"
#include "Types.h"
#include "component/Z3Buffer.h"

#include <fstream>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>

namespace ComSpen {

class SatRqspa {
private:
    z3::expr m_phi_count;
    std::string m_file_name;
    std::vector<z3::expr> m_vars;
    FA m_result;
    std::set<int> m_new_ids;
    std::set<z3::expr, exprcomp> m_tpaq_set;
    std::vector<int> m_factors;
public:
	z3::context& z3_ctx;
	Z3Buffer& z3_buffer; 
    SatRqspa(z3::context& ctx, Z3Buffer& buffer, std::string file_name, z3::expr phi_count) 
	: z3_ctx(ctx), z3_buffer(buffer), m_phi_count(phi_count), m_file_name(file_name), m_result(ctx,buffer){}
    void getContent(std::string& str);
    void getTransition(std::string& str, transition& tr);
    void readFile(FA& fa, std::string file_name, std::string prefix);
    void generateNFA(z3::expr var, FA& nfa);
    z3::expr generateFovarExpr(int idx);
    z3::expr generateSovarExpr(int idx);
    void getVars();
    z3::expr generateExpr(FA& pa);
    FA generatePA();
    z3::expr subPhiCount();
    z3::check_result checkSat(std::vector<z3::expr>& vars, std::map<std::string, std::string>& model);
    void displayModel(z3::model& model, std::vector<z3::expr>& vars, std::map<std::string, std::string>& m_model);

};

}

#endif /* SAT_RQSPA_H */
