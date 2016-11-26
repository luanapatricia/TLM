/********************************************************************
 * TP1 - CUNHA CARNEIRO Luana Patrícia
 ********************************************************************/

#include "ensitlm.h"
#include "generator.h"
#include "bus.h"
#include "memory.h"

int sc_main (int argc, char ** argv) {
	generator g("Generator1");
	Bus b("Bus");
	memory m("Memory", 10); // 10 c'est la quantité de lignes de memoire. Chaque ligne c'est une mot

	/* connect components to the bus */
	g.socket.bind(b.target);
	m.socket.bind(b.initiator);

	/* Memory is mapped at addresses [0x10000000, 0x100000FF] [inicio,tamanho]*/
	b.map(m.socket, 0x10000000, 0xFF);

	/* and start simulation */
	sc_core::sc_start();
	return 0;
}
