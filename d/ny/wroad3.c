
// Room: /d/snow/eroad1.c

inherit ROOM;

void create()
{
	set("short", "�ּ�С·");
	set("long",
"����һ��ɽ��С·��·�߹�ʯ��ᾣ���ľ���죬�Ӳݴ�����������������ʱ����Գ���Ǻ�֮\n"
"�����㲻��ë����Ȼ��\n"
);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"wroad1",
]));
	set("no_clean_up",0);
	set("outdoors", "ny");
	set("objects",([ /* sizeof() == 1 */
__DIR__"npc/tcorpse":1,
	]));
	setup();
	replace_program(ROOM);
}
