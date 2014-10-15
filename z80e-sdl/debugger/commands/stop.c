#include <z80e/ti/asic.h>
#include <z80e/debugger/debugger.h>

int command_stop(struct debugger_state *state, int argc, char **argv) {
	state->asic->stopped = 1;
	return 0;
}
