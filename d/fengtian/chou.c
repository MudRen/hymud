// Room: /d/fengtian/chou.c

inherit ROOM;

void create()
{
	set("short", "���ׯ");
	set("long", @LONG
�����ׯ�����ʢ������һ���ˣ��ϰ��ɽ��ϲɹ�һЩ
�õ�˿�У���ʢ������׬����Ǯ��
LONG
	);

	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"wy4",
]));

	setup();
	replace_program(ROOM);
}
