
// Room: /d/snow/nroad1.c

inherit ROOM;

void create()
{
	set("short", "��Զ�ǽֵ�");
	set("long",
"��������������Զ�ǵĽֵ��ϣ��ϱ߲�Զ����һ��ߴ��Ժ�ӣ������ϣ��ܿ���ˮ�̸��һ\n"
"�ǣ�������һƬ���֣����������Ƕ��������ľƵ꣬�����涼��ʯ��·��������Զ������\n"
"���������������ǳ����֡�\n"
);
	set("outdoors", "ny");
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"nroad2",
  "south" : __DIR__"txgate",
  "west" : __DIR__"nroad3",
  "east" : __DIR__"nroad0",
]));
	set("no_clean_up", 0);

	set("objects", ([__DIR__"npc/playboy":1,]));
	setup();
	replace_program(ROOM);
}
