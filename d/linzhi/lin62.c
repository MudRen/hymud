// Room: /d/linzhi/lin62.c

inherit ROOM;

void create()
{
	set("short", "ɽ�ֽ�ʯ��");
	set("long", @LONG
������һƬ������ֻ���м��������������һ��ʯ�ף���ʱ
�����߻���������������������Զ��Ӧ����һ������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"lin55",
  "west" : __DIR__"lin63",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 3600);
	setup();
	replace_program(ROOM);
}
