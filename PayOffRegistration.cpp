/**
   @author Pei Wang
 */

#include "PayOffHelper.hpp"

namespace {
    PayOffHelper<PayOffCall> RegisterCall("call");
    PayOffHelper<PayOffPut> RegisterPut("put");
}
