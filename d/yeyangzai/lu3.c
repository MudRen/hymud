// Room: /open/stst/sazai/lu3.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
        ����ͨ��ǰ�������ȣ��ǳ����������߾���ǰ���ˡ�

LONG

        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"lianwu",
  "north" : __DIR__"qianting",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
