// Room: /d/linzhi/by01.c

inherit ROOM;

void create()
{
	set("short", "��б��");
	set("long", @LONG
�����ǰ�һ����б�֣��ڽֱ�����ʷ���һ�Ұ�һ���̣���
���ʷ���һ��ˮ���ꡣ���������˲��ֻ࣬�м���С������һ��
��ˣ��
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"bye",
  "west" : __DIR__"by02",
  "south" : __DIR__"fruitshop",
  "north" : __DIR__"silkshop",
]));
  set("objects", ([ /* sizeof() == 4 */
__DIR__"npc/girl" : 2,  	
]));

        set("outdoors", "linzhi");
//        set("cannot_build_home", 1);
//        set("altitude", 2600);
	setup();
	replace_program(ROOM);
}
