// Room: /d/linzhi/lin63.c

inherit ROOM;

void create()
{
	set("short", "ɽ�ֽ�ʯ��");
	set("long", @LONG
������һƬ������ֻ���м��������������һ��ʯ�ף���ʱ
�����߻���������������������һ����ΰ������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"lin62",
  "west" : __DIR__"pg_temple",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 3200);
	setup();
	replace_program(ROOM);
}
