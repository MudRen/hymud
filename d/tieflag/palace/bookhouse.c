 inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "�鷿");
        set("long", @LONG
�鷿С�ɾ��£���ɨ���˳���Ȼ����ǽ������ϰ����˸����鼮��һ��
��ľ�������ڵ񻨴�ǰ���Ա߷��˸���������������������������ϣ�����
����һյˮ���ƣ��Ա���һ���������ε���仨ƿ������ϡ��ز��˼�ֻ��
ɫ��ɽ�軨��
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"jinghouse",
  "south" : __DIR__"juhua",
]));
        set("objects", ([
        __DIR__"obj/desk" : 1,
        __DIR__"npc/manfeng" : 1,
                        ]) ); 
        set("outdoors", "palace"); 
        set("coor/x",310);
        set("coor/y",-50);
        set("coor/z",10);
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
        if( !sizeof(inv)) {
        item = new(__DIR__"obj/book");
        item->move(con);
        }
}    
