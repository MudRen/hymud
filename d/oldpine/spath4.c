 // Room: /d/oldpine/spath4.c
inherit ROOM; 
void create()
{
        set("short", "���µ�");
        set("long", @LONG
һ����ֱ���µ����������Ѿ����˾�ͷ��
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"spath3",
]));
        set("no_clean_up", 0);
        set("outdoors", "oldpine"); 
        set("coor/x",520);
        set("coor/y",2330);
        set("coor/z",100);
        setup();
        replace_program(ROOM);
}   