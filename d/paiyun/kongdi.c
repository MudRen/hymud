// Room: /d/paiyun/kongdi.c

inherit ROOM;

void create()
{
	set("short", "�ּ�յ�");
	set("long", @LONG
һƬ�ּ�յ��������к�����ж��죬�յ�����һ�ھ�����
�����в�����̦�������Ӻܾ�û���������ˮ�ˡ�
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"lin2",
  "east" : __DIR__"lin1",
]));
        set("objects",([
        __DIR__"npc/cleaner" : 1,
]));


	set("outdoors", "paiyun");

	setup();
	replace_program(ROOM);
}
