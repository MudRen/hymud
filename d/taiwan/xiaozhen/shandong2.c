// Room: /d/taiwan/shandong2.c

inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
����һ��ͨ��ɽ�е����,���ߵ�ʯ�����������Զ����һ��ҹ����
��������,��������ط���Щ��ɭ�ֲ�.ǰ�治Զ�ƺ���Щʲô����.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/dizi.c" : 2,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"shandong1",
  "northdown" : __DIR__"boss",
]));

	setup();
	replace_program(ROOM);
}
