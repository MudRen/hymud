// Room: /d/fengtian/ll3.c

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
  "south" : __DIR__"ll4",
  "west" : __DIR__"xiaochi",
  "east" : __DIR__"bingqi",
  "north" : __DIR__"ll2",
]));
        set("outdoors", "fengtian");
	setup();
	replace_program(ROOM);
}
