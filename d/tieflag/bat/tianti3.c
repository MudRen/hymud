 inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
����һ����խ����,�����������ݡ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
        "up"   : __DIR__"tianti",
            "down" : __DIR__"tianti2",
        ]));
        set("objects", ([
        __DIR__"npc/bianfu2": 1,
        ]) );
      set("coor/x",3310);
        set("coor/y",20);
        set("coor/z",10);
        setup();
      replace_program(ROOM);
}  
