 // TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
��������ɽ������Ա����ϣ����϶����̳�Ӫ�죬������ΰ��
��ɫ׳�ۡ����ǡ�����ӳ�գ��ܸ����ơ����������а�����ʯ��
���٣����С������Ը�����֮��������ɽ����ϵ�ʯ���ˡ�����
��ʥ������Ľǣ��ĸ�����������ڱ�����䣬���ո��ӣ�����
���š�
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"luya", 
  "south" : __DIR__"taishi",
  "northwest" : __DIR__"shuyuan",
  "southeast" : __DIR__"shizong",
]));
        set("outdoors", "songshanfy");
        set("objects", ([
                __DIR__"obj/bei1" : 1,
       ]) );
        
        
        set("coor/x",-180);
        set("coor/y",110);
        set("coor/z",0);
        setup();
        create_door("north", "Сľ��", "south", DOOR_CLOSED);
} 
