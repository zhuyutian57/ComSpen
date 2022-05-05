#if !defined(PROBLEM_SLAH_)
#define PROBLEM_SLAH_
/*******************************************
*  @file  Problem.h                        *
*  @brief  Brief file description          *
*                                          *
*  @author   Chong Gao                     *
*  @version  1.0                           *
*  @date     2019-2-18                     *
*                                          *
*******************************************/

#include "component/Problem.h"
#include "component/SortType.h"
#include "Predicate_SLAH.h"
#include "HeapChunk.h"
#include "Types.h"
#include "z3++.h"

using HeapType = pair<SortType*, SortType*>;

class Problem_SLAH : public Problem {
public:
    Problem_SLAH(z3::context& ctx);
    virtual ~Problem_SLAH();
    
    void setHeapChunk(HeapChunk* hck) { m_hck = hck; }
    HeapChunk* getHeapChunk(){ return m_hck; }

    void show();
    
protected:
    HeapChunk* m_hck;
};


#endif
