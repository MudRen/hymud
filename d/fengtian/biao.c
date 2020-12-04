// Room: /d/fengtian/biao.c

inherit ROOM;

void create()
{
	set("short", "��Զ�ھ�");
	set("long", @LONG
������Ʈ����һ���ӻ����ڷ����������죬���ϴ�������
�֡���Զ�����ſ���һ�ų��ʼ����ھֵ������������������죬
�ھ��ڲ�ʱ���˽���������
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"xm1",
]));
	set("cannot_build_home",1);

	set("outdoors", "fengtian");

	set("objects",([
	__DIR__"npc/tangzi" : 4,
	__DIR__"npc/biaoshi" : 2,
]));

	setup();
	replace_program(ROOM);
}
