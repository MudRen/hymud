// Room: /d/zuojiacun/yuju.c

inherit ROOM;

void create()
{
	set("short", "��ߵ�");
	set("long", @LONG
����һ����ߵ꣬���������һЩ�㹳����ˡ�˿��һ���
��ߡ�����ϰ������ڹ�̨�����������ţ������������æվ��
��������������
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"lu3",
]));
  	set("objects",([
	"/clone/npc/npc" : 1,
]));
	setup();
	replace_program(ROOM);
}
