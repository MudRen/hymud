#include <room.h>
inherit ROOM; 
void create()
{
        set("short", "��԰");
        set("long", @LONG
����һ������Ļ�԰������ȺɽΧ�ƣ�԰���򻨾��ޡ�ĵ����ҩ���ƾ�
��õ���ļ��㻨������ؾ�ͬʱ���ţ�̧����ȥ����������һƬ���λ���֮
�С���ʯС����������ʼ䣬���ҵ�վ��ʮ���������Ů�����ڼ��ݹ໨��
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"garden",
  "east" : __DIR__"valley",
]));
        set("objects", ([
        __DIR__"npc/whitewoman" : 1,
                        ]) ); 
        set("outdoors","palace");
        set("coor/x",270);
        set("coor/y",-40);
        set("coor/z",10);
        setup();
        replace_program(ROOM); 
}     
