// Room: /d/fengtian/xm1.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
�������ʢ���ٸ����ڵأ���������Ƚ��ྲ������û��̫
��ĵ��̣��Ƚϴ�ĵ��̾���ʢ�������ھ֡���Զ�ھ֡�����
��һЩʢ���ĸ���Ҳס�����
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"biao",
  "south" : __DIR__"lukou",
  "east" : __DIR__"jiuguan",
  "north" : __DIR__"xm2",
]));
        set("outdoors", "fengtian");
	setup();
	replace_program(ROOM);
}
