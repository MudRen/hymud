 inherit ROOM;
void create()
{
        set("short", "��¥");
        set("long", @LONG
����¥��, �����㿴��һ������ʦ�Ļ�����ڶ����ǽ��, ����
���·�����һ�Ÿ����첼������, ��������ط���éɽ������ؼ���
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"book_room1",
]));
        set("objects", ([
        __DIR__"npc/taolord" : 1,
        __DIR__"npc/up_taoist" : 2,
        __DIR__"obj/desk" : 1,

 ]) ); 
        set("coor/x",-40);
        set("coor/y",2140);
        set("coor/z",90);
        setup();
        replace_program(ROOM);
} 
void reset()
{
        object *inv;
        object con, item;
        ::reset();
        con = present("desk", this_object());
        inv = all_inventory(con);
        if( !sizeof(inv) ) {
        item = new(__DIR__"obj/specialbook");
        item->move(con);

        }
}       
