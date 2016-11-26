/********************************************************************
 * TP1 - CUNHA CARNEIRO Luana Patrícia				    *
 ********************************************************************/

#include "ensitlm.h"
#include "bus.h"

SC_MODULE(generator){
	ensitlm::initiator_socket<generator> socket;
	void thread(void);

	SC_CTOR(generator);

};
