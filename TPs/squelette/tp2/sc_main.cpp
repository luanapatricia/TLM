#include "ensitlm.h"
#include "cpu.h"
#include "bus.h"
#include "memory.h"
#include "LCDC.h"
#include "ROM.h"


int sc_main (int argc, char ** argv) {
    Bus b("Bus");
    cpu CPU("CPU");
    Memory m("RAM", 10 * 4);
    LCDC lcdc("LCDC",sc_core::sc_time(1.0 / 25, sc_core::SC_SEC));

    /* connect components to the bus */
    CPU.socket.bind(b.target);
    m.target.bind(b.initiator);
    lcdc.initiator_socket.bind(b.target);


    /* Memory is mapped at addresses [0x10000000, 0x100000FF] */
    b.map(m.socket, 0x10000000, 0xFF);
    b.map(.socket, 0x10000000, 0xFF);


    /* and start simulation */
    sc_core::sc_start();
    return 0;
}