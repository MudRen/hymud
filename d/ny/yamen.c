
// Room: /d/snow/yamen.c

inherit ROOM;

void create()
{
	set("coor",({-75,4870,10}));
	set("short", "��Զ������");
	set("long",
"������Զ�����ô��ã�����һ��˶�󰸼��ĺ����������Զ�����������ɽ��ͷ���߹��Ҷ�\n"
"�����顰����������ĸ����֡�������������......����Ĳ����飿\n"
);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"yamen_yard",
]));
	set("objects", ([ /* sizeof() == 3 */
//  __DIR__"npc/judge_guard" : 4,
  __DIR__"npc/judgeman" : 1,
]));

	setup();
	replace_program(ROOM);
}
