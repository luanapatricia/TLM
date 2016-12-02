#include "cpu.h"


using namespace std;


void cpu::thread(void) {




}


cpu::cpu(sc_core::sc_module_name name) // constructeur
    : sc_core::sc_module(name) {
    SC_THREAD(thread);
}
