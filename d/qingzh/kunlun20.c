// kunlun20.c 昆仑山
// west to jiayuguan,est to lanzhou
// Ver 0.1 08/15/1998 by Freeze

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIG "昆仑山小径"NOR);
	set("long", @LONG
这路狭窄崎岖，又凹凸不平，走的煞是累人。由于这路弯弯曲曲，绕了一
会儿，你只感头晕。
LONG
	);	
        set("outdoors", "qingzh");

	set("exits", ([
		"south" : __DIR__"kunlun19",
		"north" : "/d/jyguan/huangmo6",
	]));
	
//	set("objects", ([
//		__DIR__"npc/guest" : 1]));
	
	setup();
	replace_program(ROOM);
}

/*	
void init()
{
	object ob;
	int ioqi;
	
	ob = this_player();
	ioqi = 300 / (int)ob->query("int") + 3;
        if((int)ob->query("qi") < 50) 
                 message("vinson",HIR"你忽然感到呼吸吃力，身体发软，象是高原反应，歇息一会儿再走吧！\n"NOR, ob);
	ob->improve_skill("dodge", 0.1 * (int)ob->query_skill("dodge", 1));
        ob->receive_damage("qi", ioqi );
}
*/		

