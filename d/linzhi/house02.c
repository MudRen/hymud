// Room: /d/linzhi/house02.c

inherit ROOM;

void create()
{
	set("short", "�����ʷ�");
	set("long", @LONG
����һ����ͨ�Ĳ����ʷ����������ܼ򵥣�����������ë
֯�ɵĵ�̺�����������ұ߰���һ��ľ����̨���������һ����
Ƥ���ͣ������Ϸ���һ����ˮ����Ҫ�ǿ��ˣ������������ˮ�ȡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"by06",
]));
  set("objects", ([ /* sizeof() == 4 */
__DIR__"npc/man" : 1,  	
]));

	setup();
	replace_program(ROOM);
}
