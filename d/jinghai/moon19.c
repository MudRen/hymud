// Room: /d/jinghai/moon19.c

inherit ROOM;

void create()
{
	set("short", "书房");
	set("long", @LONG
明月水寨的书房里放的大部份是兵书，这里不光有很多的长
年在海上讨生活的前辈们所著的海战心得，也有一些陆战手册，
客人们要想在找到其它的书籍就很难了。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"moon8",
]));
        set("objects",([
        __DIR__"npc/guan2" : 1,
        __DIR__"npc/obj/xian-steps_book.c" : 1 ,	
        __DIR__"npc/obj/bibo-sword_book.c" : 1 ,	
        __DIR__"npc/obj/jinghai-force_book.c" : 1 ,		
]));


	setup();
}


int valid_leave(object me,string dir)
{
        if(!me)
                return 0;

        if(dir == "west" || dir == "w")
        {
                if(sizeof(filter_array(deep_inventory(me),(: $1->is_jinghai_book() :))))
                        return notify_fail("管事伸手拦住你说道：“奉寨主之命，本派典籍不可携出书房。”\n");
        }

        return ::valid_leave(me,dir);
}

