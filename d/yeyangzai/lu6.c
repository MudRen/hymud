// Room: /open/stst/sazai/lu6.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
        ����ͨ�����������ȣ��ǳ����������߾��Ǵ����ˡ�

LONG

        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"qianting",
  "north" : __DIR__"dating",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

