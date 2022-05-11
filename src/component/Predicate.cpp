#include "component/Predicate.h"

Predicate::Predicate(
    z3::context& ctx,
    std::string name,
    z3::expr_vector pars,
    z3::expr base,
    z3::expr rec)
	:z3_ctx(ctx), name(name), m_pars(pars), m_base_rule(base), m_rec_rule(rec) {}

std::string Predicate::getName() { return name; }

void Predicate::show() {
    cout << "pars: \n";
    for (unsigned int i=0; i<m_pars.size(); i++) {
        cout << m_pars[i] << " ";
    }
    cout << endl;

    cout << "base: " << m_base_rule << endl;
    cout << "rec: " << m_rec_rule << endl;
}
