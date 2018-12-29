#include "zone.h"
struct task {
	enum {ATK,DEF,CAP} type;
	struct entity *target;
	int duration;
	struct task *next;
};
struct creature {
	char *name;
	struct task *tasks;
	char sym;
	color_t color;
	//struct faction *faction;
	// TODO: Stats
};
struct item {
	char *name;
	unsigned int value;
	char sym;
	color_t color;
	// TODO: Stats
};
struct entity {
	enum {CREATURE,ITEM} type;
	union {
		struct creature *c;
		struct item *i;
	} ptr;
};
struct tile {
	char fg,bg;
	color_t fg_c,bg_c;
	// TODO: Entity placement
};
struct zone {
	struct entity *player;
	int player_coords;
	struct tile *area;
};