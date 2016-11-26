/********************************************************************
 * TP1 - CUNHA CARNEIRO Luana Patrícia				    *
 ********************************************************************/

#include "ensitlm.h"
#include "bus.h"

SC_MODULE(memory){

	ensitlm::target_socket<memory> socket;
	ensitlm::data_t *storage;
	unsigned int mem_size;
	
	tlm::tlm_response_status write(const ensitlm::addr_t &a,
				     		const ensitlm::data_t &d);

	tlm::tlm_response_status read (const ensitlm::addr_t &a,
				       /* */ ensitlm::data_t &d);

	memory(sc_core::sc_module_name name, unsigned int size); //construtor
	SC_HAS_PROCESS(memory); //pour specifier que ce module a un processus
	~memory(); // destrutor

};
