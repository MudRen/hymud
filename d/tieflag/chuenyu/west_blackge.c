#include <room.h>
inherit ROOM; 
void create()
{
        set("short", "���ɸ�����");
        set("long", @LONG
���Ǻ��ɱ������ڻ�̫ӭ���������������������õ�Ӻ�ٵ��š�
���Ǻ��ɸ���������������򱱶��Ǿ����޼����Ļ�԰��¥������
���ھ޴��˯����������һ��СС�Ĵ����ҡ�
LONG
        );
        set("exits", ([ /* sizeof() == 5 */
  "eastup" : __DIR__"bedroom",
  "east" : __DIR__"center",
  "west" : __DIR__"west_garden",
  "south" : __DIR__"storage",
  "north" : __DIR__"north_garden",
]));
        set("objects", ([
                __DIR__"npc/guard" : 2,
        ]) ); 
        create_door("south", "ľ��", "north", DOOR_CLOSED); 
        set("coor/x",110);
        set("coor/y",190);
        set("coor/z",40);
        setup();
}        
