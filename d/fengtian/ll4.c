// Room: /d/fengtian/ll4.c

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
  "south" : __DIR__"kd1",
  "west" : __DIR__"jiulou",
  "east" : __DIR__"caifeng",
  "north" : __DIR__"ll3",
]));
        set("outdoors", "fengtian");
	setup();
	replace_program(ROOM);
}
