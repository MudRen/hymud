// Room: /d/jinghai/jhd28.c

inherit ROOM;

void create()
{
	set("short", "С���");
	set("long", @LONG
������ֻ��ʮ�����˼ң����ھ����ɻ�û�г�����ʱ����
���Ѿ���������������˲�֪���ٴ��ˣ���˵������ǰ��ס��ɽ
��ģ�ֻ�Ǻ���������Ҫ����̳����������ǲ�����Ƭƽ����
��̲�ϰ��˼ҡ�������Ϊ�����ɸ�������һ���ĺ��������ǶԾ�
���ɾ�������������һ��Թ��Ҳû�С�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"jhd30",
  "north" : __DIR__"jhd6",
  "east" : __DIR__"jhd29",
]));
        set("outdoors", "jinghai");

	setup();
	replace_program(ROOM);
}
