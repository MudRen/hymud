// Room: /d/fengtian/xm2.c

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

	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"xm1",
  "east" : __DIR__"ftf1",
  "north" : __DIR__"xm3",
  "west" : __DIR__"business",
]));
        set("outdoors", "fengtian");
	setup();
	replace_program(ROOM);
}
