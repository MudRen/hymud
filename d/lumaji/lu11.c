// Room: /d/lumaji/lu11.c

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
�����ڻ���С·�ϣ�·�ı�����ũ�һЩũ����������æ
µ�š�·�汻������ˮ������û��ʲô������
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"nongju2",
  "west" : __DIR__"lu10",
  "northeast" : __DIR__"lu12",
]));
	set("outdoors", "lumaji");
	setup();
	replace_program(ROOM);
}
