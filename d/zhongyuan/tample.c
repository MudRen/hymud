// Room: /u/lin/d/guanzhong/tample.c

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
������ɽ���Թ�������ɽ�µ��ϰ���
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"xiaolu1",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

