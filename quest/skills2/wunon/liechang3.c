// Room: /d/sandboy/daotian1.c

inherit ROOM;

void create()
{
	set("short", "���Գ�");
	set("long", @LONG
������һ���Ĳ�ԭ,����Ұζ��Ⱥ,��Ӱ����...
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "jiangnan");
	set("roomif","$botten#����:bulie$#");        
        set("exits", ([
                "east" : __DIR__"daotian3",
        ]));
//        set("no_fight",1);
//        set("no_beg",1);
//        set("no_steal",1);
	set("objects", ([
		__DIR__"dalie/dalie" : 3,
	])); 


	setup();
	replace_program(ROOM);
}
