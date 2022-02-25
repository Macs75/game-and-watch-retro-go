
#if !defined (COVERFLOW)
  #define COVERFLOW 0
#endif /* COVERFLOW */
#if !defined (BIG_BANK)
#define BIG_BANK 1
#endif
#if BIG_BANK == 1
#define EMU_DATA 
#else
#define EMU_DATA __attribute__((section(".extflash_emu_data")))
#endif
extern const rom_system_t snes_system;
extern const uint8_t _binary_roms_snes_Super_Turrican__U__smc_start[];
uint8_t SAVE_SNES_0[0]  __attribute__((section (".saveflash"))) __attribute__((aligned(4096)));

const retro_emulator_file_t snes_roms[] EMU_DATA = {
	{
		.name = "Super Turrican (U)",
		.ext = "smc",
		.address = _binary_roms_snes_Super_Turrican__U__smc_start,
		.size = 524288,
		#if COVERFLOW != 0
		.img_address = NULL,
		.img_size = 0,
		#endif
		.save_address = SAVE_SNES_0,
		.save_size = sizeof(SAVE_SNES_0),
		.system = &snes_system,
		.region = REGION_NTSC,
	},

};
const uint32_t snes_roms_count = 1;

const rom_system_t snes_system EMU_DATA = {
	.system_name = "Super Nintendo Entertainment System",
	.roms = snes_roms,
	.extension = "snes",
	#if COVERFLOW != 0
	.cover_width = 128,
	.cover_height = 96,
	#endif 
	.roms_count = 1,
};
