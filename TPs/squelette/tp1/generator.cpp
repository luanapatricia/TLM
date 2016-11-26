/********************************************************************
 * TP1 - CUNHA CARNEIRO Luana Patrícia                                 *
 ********************************************************************/

#include "generator.h"

using namespace std;

void generator::thread(void) { 
	for (int i = 0; i < 10; i++){
		long adress = 0x10000000;
		long last_adress = i*4 + adress;
		socket.write(last_adress, i);
		//cout << "Adresse write " << i + 1 << " = " << last_adress << endl;
	}

	for (int i = 0; i < 10; i++){
		ensitlm::data_t data;
		socket.read(i*4 + 0x10000000, data);
		//cout << "Adresse read" << i +1 << " = " << data << endl;
	}


}

generator::generator(sc_core::sc_module_name name) // constructeur
	: sc_core::sc_module(name) {
	SC_THREAD(thread);
}
