// Room: /d/linzhi/byw.c

inherit ROOM;

void create()
{
	set("short", "��һ������");
	set("long", @LONG
�����ǰ�һ�����ڣ��򶫾ͽ���һ���ˡ���һ������֥����
����Ĵ����ˣ��˿���Ȼ���࣬�������Ĳ�����һ�㶼������
��һЩ��Ҫ��������Ʒ����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"by17",
  "west" : __DIR__"lin48",
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
