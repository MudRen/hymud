// Room: /d/linzhi/lin27.c

inherit ROOM;

void create()
{
	set("short", "������ɽ��ƽ��");
	set("long", @LONG
������������ɽ���ϲ�ƽ�£����ﺣ����4200�����ң�����
���ƽ̹��һ������ӭ��������ͷҲ��̧������������������
ǰ���м�����
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "eastup" : __DIR__"lin26",
  "west" : __DIR__"lin28",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 4200);
	setup();
	replace_program(ROOM);
}
