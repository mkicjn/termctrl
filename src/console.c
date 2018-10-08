#include "console.h"
extern int player_coords;
void command(struct tile *z,int pos)
{
	char cmd[128];
	next_report();
	fputs("Enter command: ",stdout);
	set_cursor_visible(true);
	set_canon(true);
	fgets(cmd,128,stdin);
	set_cursor_visible(false);
	set_canon(false);
	if (!strcmp(cmd,"think\n")) {
		report("s c","Thought:",think(z,target(z,pos)));
	} else if (!strcmp(cmd,"swap\n")) {
		int p=target(z,pos);
		if (z[p].e)
			player_coords=p;
	} else if (!strcmp(cmd,"kill\n")) {
		int p=target(z,pos);
		if (z[p].e)
			kill(z,p);
		draw_pos(z,p);
	} else if (!strcmp(cmd,"resurrect\n")) {
		int p=target(z,pos);
		if (z[p].c&&!z[p].e) {
			z[p].e=z[p].c;
			z[p].c=NULL;
			z[p].c->hp=z[p].c->maxhp;
		}
		draw_pos(z,p);
	}
}
