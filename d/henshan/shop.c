//Room: /d/henshan/shop.c
// Modified By Java Feb.14.1998

inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
�����Ǻ����سǵ�һ��С�꣬��Щ�򵥵���ʳ��ר��׬��Щ�ο�
��Ǯ��
LONG );
	set("exits", ([
		"north" : __DIR__"hengyang1",
		"up"    : __DIR__"huiyan",
	]));
	set("objects", ([
	      "/d/jinyong/book8/henshan/npc/xiaoer2" : 1,
	]));
//        set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
