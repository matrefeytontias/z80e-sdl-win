#include <z80e/ti/asic.h>
#include <z80e/log/log.h>
#include <z80e/ti/memory.h>
#include <z80e/ti/hardware/flash.h>

#include <stdlib.h>
#include <string.h>

uint8_t read_size_port(void *device) {
	flash_state_t *state = (flash_state_t*)device;
	return state->chip_size;
}

void write_size_port(void *device, uint8_t data) {
	flash_state_t *state = (flash_state_t*)device;
	state->chip_size = data & 0x1F;
}

void init_flash_ports(asic_t *asic) {
	flash_state_t *state = (flash_state_t*)malloc(sizeof(flash_state_t));

	memset(state, 0, sizeof(flash_state_t));
	state->asic = asic;
	state->chip_size = 0x33;

	z80iodevice_t chip_size_port = { state, read_size_port, write_size_port };

	asic->cpu->devices[0x21] = chip_size_port;
}

void free_flash_ports(asic_t *asic) {
	free(asic->cpu->devices[0x22].device);
}
