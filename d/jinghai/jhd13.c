// Room: /d/jinghai/jhd13.c

inherit ROOM;

void create()
{
	set("short", "������Ϣ��");
	set("long", @LONG
����һ����Ĵ󷿼䣬������˼��Ŵ�ʲôҲû�У���
���ĵ�������������֮�඼��������Ϣ��
LONG
);

	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"jhd10",
]));

	
	set("sleep_room", 1);

	setup();
	replace_program(ROOM);
}
