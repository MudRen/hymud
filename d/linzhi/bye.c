// Room: /d/linzhi/bye.c

inherit ROOM;

void create()
{
	set("short", "��һ�򶫿�");
	set("long", @LONG
�����ǰ�һ�򶫿ڣ������ͽ���һ���ˡ���һ������֥����
����Ĵ����ˣ��˿���Ȼ���࣬�������Ĳ�����һ�㶼������
��һЩ��Ҫ��������Ʒ����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "eastup" : __DIR__"lin10",
  "west" : __DIR__"by01",
]));

  set("objects", ([ /* sizeof() == 4 */
__DIR__"npc/cityguard" : 3,  	
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
//        set("altitude", 2600);
	setup();
	replace_program(ROOM);
}
