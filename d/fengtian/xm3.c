// Room: /d/fengtian/xm3.c

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
  "west" : __DIR__"fu",
  "south" : __DIR__"xm2",
  "north" : __DIR__"xm4",
]));
        set("outdoors", "fengtian");
	setup();
	replace_program(ROOM);
}
