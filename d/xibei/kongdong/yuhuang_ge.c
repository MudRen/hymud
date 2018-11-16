//1997-3-10 by qyz
#include <room.h>

inherit ROOM;


void create()
{
	set("short","玉皇阁");
	set("long",@LONG
玉皇阁矗立在山颠，是崆峒山最高的建筑，称为“观顶”，基础用巨石砌起
异常牢固，在靠近山颠的地方有一大黑石块，表面平坦，上有石桌石墩，周围环
以石栏，相传昔时常有仙人羽客栖集于此，路旁有一巨石，踞另一垣石之上，令
人有飞来之感。阁内一座金碧辉煌的钟楼，屹立在郁葱的密林中，或于晨霏中隐
现，若飘渺之天上宫阙，堪为大观。
LONG);
	set("exits",
	([
	"east" : __DIR__"xuanyuan_gong",
          	]));
        set("outdoors","kongdong");
	set("objects", ([
		__DIR__"npc/kdizi1" : 2,
		]) );
        setup();
        //place_program(ROOM);
}
