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
  "north" : __DIR__"garden",
]));
        set("objects", ([
        __DIR__"npc/girls" : 5,
                        ]) ); 
        set("outdoors","palace");
        set("coor/x",260);
        set("coor/y",-50);
        set("coor/z",10);
        setup();
        replace_program(ROOM); 
}     
