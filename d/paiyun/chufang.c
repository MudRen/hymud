// Room: /d/paiyun/chufang.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����ﵽ������Ұζ�����㣬����������կ�ĳ��ӿ϶���һ
���ģ�������̨�Ϻ͹���Ĳ���Ŀ�ˮ���������ˣ����̲�ס��
������ɽ������ȥ��
LONG
	);
set("objects", ([
	"/clone/food/jitui":1,
        "/clone/food/baozi":1,
       "/clone/food/jiudai":1,
       //"/p/obj/table":1,
       ]) );
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"dayuan",
]));
	setup();
	replace_program(ROOM);
}
