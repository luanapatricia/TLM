#include "ensitlm.h"
#include "bus.h"


SC_MODULE(cpu){
    ensitlm::initiator_socket<cpu> socket;
    void thread(void);


    SC_CTOR(cpu);


};






