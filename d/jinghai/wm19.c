// Room: /d/jinghai/wm19.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����Ǿ����ɵı������������̵��ǲü������ľ�飬����
����֨֨���졣���ӵ��Ҳ���һ�������ܡ���������ʮ�˰����
������ȫ�������Թ�����ʮ����������Ŀ��ף���������սѥ��
��ϱ���һ��С·����֪ͨ���η���
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"wm10",
]));
        set("objects", ([
            __DIR__"obj/changmao"       : 2,
            __DIR__"obj/blade"       : 2,
            __DIR__"obj/sword"       : 2,
        ]));


	setup();
	replace_program(ROOM);
}
