// Room: /d/zuojiacun/liyuan.c

inherit ROOM;

void create()
{
	set("short", "��ʿԪ��");
	set("long", @LONG
��ʿԪ�й���ʿ���Ǵ����Ļ���ߵ��ˣ�Ҳ������Ǯ���ˡ�
�����������ܣ���һЩС�������������ٵط���������һ�Ű���
����ǽ�Ϲ���һ���ֻ���
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"lu12",
]));
  	set("objects",([
	"/clone/npc/npc1" : 1,
]));
	setup();
	replace_program(ROOM);
}
