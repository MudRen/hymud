// Room: /d/fengtian/ll2.c

inherit ROOM;

void create()
{
	set("short", "���ֽ�");
	set("long", @LONG
���ֽ���ʢ����һ�������ֵ����������ų����Ĳ�������
�Լ�������İ�������Ҳ�𽥷����������𽥳�Ϊʢ����һ����
Ҫ��ҵ���ˡ�
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"ll3",
  "east" : __DIR__"mu",
  "north" : __DIR__"ll1",
]));
        set("outdoors", "fengtian");

	set("objects",([
"/clone/npc/man" : 1,
]));

	setup();
	replace_program(ROOM);
}
