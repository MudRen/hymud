// Room: /d/linzhi/lin68.c

inherit ROOM;

void create()
{
	set("short", "��ԭ�ӵ�");
	set("long", @LONG
�����Ǹ�ԭ�ӵ������߼�˵ĵ��κ�����·һ����Ҳ��֪
�Ƿ��ߵ�ͨ������ϸ��ע���ţ�ѡ����һ���нŲ�ӡ�ǽ϶�ķ�
��������һ�ᣬ���÷���û���ߴ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"linzhiw",
  "southeast" : __DIR__"lin67",
]));
        set("outdoors", "linzhi");
        set("cannot_build_home", 1);
        set("altitude", 3600);
	setup();
	replace_program(ROOM);
}
