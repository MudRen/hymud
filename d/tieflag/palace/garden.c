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
  "east" : __DIR__"garden3",
  "north" : __DIR__"garden1",
  "south" : __DIR__"garden2",
  "west" : __DIR__"secretpath2",
]));
        set("objects", ([
        __DIR__"npc/dagu" : 1,
                        ]) ); 
        set("outdoors","palace");
        create_door("west", "ͭ��", "east", DOOR_CLOSED);
        set("coor/x",260);
        set("coor/y",-40);
        set("coor/z",10);
        setup();
}       
