// Room: /d/snow/fireplace.c
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
������������������һ������֮��, ͷ���Ϸ������ɿ����̴�
�ĳ���, ������Ȼû�а취���̴�����ȥ�������ǽ����Ϊ������
�������ں�, �����ϻ���һ����Ĳ�ҡ�
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
                "out" : __DIR__"inn_kitchen",
]));
        set("objects", ([
                __DIR__"obj/woodsword": 1
        ]));
        setup();
        replace_program(ROOM);
}
