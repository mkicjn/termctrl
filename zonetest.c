#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "src/input.h"
#include "src/room.h"
#include "src/zone.h"
struct creature player={
	.name="Player",
	.sym='@',
	.color=LIGHT_BLUE,
};
struct entity player_ent={
	.type=CREATURE,
	.ptr={.c=&player},
	.next_entity=NULL,
};
int main()//(int argc,char **argv)
{
	srand(time(NULL));
	struct tile *z=new_zone();
	clear_screen();
	random_room(z);
	place_doors(z);
	int pc=spawn(z,&player_ent);
	scroll_zone(pc);
	draw_zone(z);
	set_canon(false);
	set_cursor_visible(false);
	while (!exit_req) {
		char c=key();
		int o=input_offset(c,ZONE_WIDTH);
		pc=move_entity(z,pc,pc+o);
		scroll_zone(pc);
		draw_zone(z);
	}
	set_canon(true);
	set_cursor_visible(true);
	sgr(RESET);
	putchar('\n');
	free(z);
	return 0;
}