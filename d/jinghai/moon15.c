// Room: /d/jinghai/moon15.c

inherit ROOM;

void create()
{
	set("short", "�����ֿ�");
	set("long", @LONG
����һ��ܴ��ľ�ݣ���ˮկ�ı����ֿ�����ڡ�������
���������ֻ�п���ͬ����������ſ�����ȡ������Ҫ������
����ɲ�Ҫ̫̰�İ��������˱����ĺ���ɲ��Ǻ���ģ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"moon11",
]));
        set("objects", ([
            __DIR__"obj/changmao"       : 2,
            __DIR__"obj/blade"       : 2,
            __DIR__"obj/sword"       : 2,
        ]));


	setup();
	replace_program(ROOM);
}
