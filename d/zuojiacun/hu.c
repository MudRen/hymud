// Room: /d/zuojiacun/hu.c

inherit ROOM;

void create()
{
	set("short", "�Ϻ���");
	set("long", @LONG
�Ϻ��Ǹ��οͣ���Ȼ40��������ˣ���������ʮ��Ӳ�ʡ���
�����ڳ���ɽ�вɲΣ���˵������������Ʒ�֡���Ҫ�ǿϳ�Ǯ��
Ҳ�������������Щ�Ϻ��˲Ρ�
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"lu10",
]));

	setup();
	replace_program(ROOM);
}
