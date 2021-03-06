// Room: /d/jinghai/wm15.c

inherit ROOM;

void create()
{
	set("short", "书房");
	set("long", @LONG
这里就是靖海派书房，布置的颇为优雅，几张桌椅之外，几
排书架整齐的摆在屋中。书架上摆着无数书籍。仔细看看，书架
上净是关于武功的书。四面墙上有些山水字画，墙上还挂着一个
条幅，写着“学无止境”四个龙飞凤舞的大字。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	"north" : __DIR__"wm9",
	"enter" : __DIR__"mi5",
]));
        set("objects",([
        __DIR__"npc/guan1.c" : 1 ,
        __DIR__"npc/obj/xian-steps_book" : 1 ,	
        __DIR__"npc/obj/bibo-sword_book" : 1 ,	
        __DIR__"npc/obj/jinghai-force_book" : 1 ,			
]));


	setup();
}
int valid_leave(object me,string dir)
{
	object *inv;

        if(!me)
                return 0;

        if(dir == "north" || dir == "n")
        {
                if(sizeof(filter_array(deep_inventory(me),(: $1->is_jinghai_book() :))))
			return notify_fail("管事伸手拦住你说道：“奉寨主之命，本派典籍不可携出书房。”\n");
        }

	if(dir == "enter")
	{
		if( (me->query("class") != "jinghai") && !wizardp(me) )
			return notify_fail("管事拦住你说道：“本帮重地，外人不的入内！”\n");

		inv = filter_array(all_inventory(me), (: $1->is_character() :));
		if(sizeof(inv))
			foreach(object n in inv)
				if(!n->move(this_object()))
					return notify_fail("管事拦住你说道：“本帮重地，外人不的入内！”\n");
	}

        return ::valid_leave(me,dir);
}
