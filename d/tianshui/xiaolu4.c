// Room: /d/tianshui/xiaolu4.c

inherit ROOM;

void create()
{
	set("short", "��ݵ�");
	set("long", @LONG
����һƬ����Ĳݵأ����⸽���Ǻ��ѵõģ�������Χ����
�˶�����������������߾��ǹ���С����ˮ���ˣ�������һ���޼�
�Ļ���·��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"xiaolu3",
        "east" : "/d/mayi/huangtu2",
]));
	set("no_clean_up", 0);
	set("outdoors", "tianshui");
	set("objects",([
	__DIR__"npc/moggy" : 3,
	__DIR__"npc/yak" : 1,
	__DIR__"npc/cowboy" : 1,
]));
	setup();
	replace_program(ROOM);
}
