// Room: /d/fengtian/ll1.c

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
  "west" : __DIR__"du",
  "south" : __DIR__"ll2",
  "east" : __DIR__"dangpu",
  "north" : __DIR__"wy6",
]));
        set("outdoors", "fengtian");
	setup();
	replace_program(ROOM);
}
