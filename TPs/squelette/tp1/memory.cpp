/********************************************************************
* TP1 - CUNHA CARNEIRO Luana Patrícia
 ********************************************************************/

#include "memory.h"
#include <new>

using namespace std;

tlm::tlm_response_status memory::write(const ensitlm::addr_t &a, //adress
				       const ensitlm::data_t &d) { // data
	if (a/4 < memory::mem_size){
		memory::storage[a/4] = d;
		cout << memory::name() << " Write adress: " << a << " \n data: " << d << endl;
		return tlm::TLM_OK_RESPONSE;	
	}
	else { 
		SC_REPORT_ERROR("TLM", "Write out of bound");
        abort();
	}

}

tlm::tlm_response_status memory::read (const ensitlm::addr_t &a,
				       		ensitlm::data_t &d) {
	if(a/4 < memory::mem_size){
		d = memory::storage[a/4];
		cout << memory::name() << " Read: " << a << " data: "<< d << endl;
		return tlm::TLM_OK_RESPONSE;
	}
	else { 
		SC_REPORT_ERROR("TLM", "Read out of bound");
        abort();
	}
	
}

	memory::memory(sc_core::sc_module_name name, unsigned int size) 
		: sc_core::sc_module(name),mem_size(size) { 
		// MM: on évite d'utiliser malloc() en C++. Utilise
		// MM: plutôt 'new'. Et attention, tu alloues une
		// MM: mémoire trop grande, la taille est en octets.
		//memory::storage = (ensitlm::data_t*) malloc(size * sizeof(ensitlm::data_t)); }
		memory::storage = (ensitlm::data_t* = new [sizeof(ensitlm::data_t)]); }
	memory::~memory(){ 
		delete(memory::storage);
	}
