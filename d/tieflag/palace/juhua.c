 inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "�ջ�԰");
        set("long", @LONG
һ�����Ȼ�������ĶС԰��С԰�ж������ջ����ջ�԰���ˮ�رߣ�
�м������ص���������������һ�����飬��ǰ�滪�����µĽ�������ơ�
�����⣬��ӳ��ǧ�ʹ�����������һֻСС�Ľ��壬��緢�����Ķ���
���������һ�У��ƺ�����쳾�������Ե���������Ȼ���ס�
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"bookhouse",
  "south" : __DIR__"tang",
]));
        set("objects", ([
        __DIR__"obj/bell" : 1,
        __DIR__"npc/killerbee" : 1,
                        ]) );
        set("outdoors", "palace"); 
        set("coor/x",310);
        set("coor/y",-60);
        set("coor/z",10);
        setup();
}
void reset()
{
        object *inv;
        object con, item;
        ::reset();
        con = present("bell", this_object());
        inv = all_inventory(con);
        if( !sizeof(inv) && !random(5)) {
        item = new(__DIR__"obj/guo");
        item->move(con);
        }
}     
