#include <room.h>
inherit ROOM; 
void create()
{
        set("short", "�ŷ�");
        set("long", @LONG
���Ǵ��ڱ��������ŷ�����������Ʈ�����ϵ���Ҷ��ľ����
���˴������εĿ�ɽ������������ƺ�������Ķ����ڡ���������
�Ľ���������
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"bedroom",
]));
        set("objects", ([
                __DIR__"obj/pigmeat" : 3,
                __DIR__"obj/qiwine" : 3,
                __DIR__"npc/cook" : 1,
        ]) );  
        create_door("north", "������", "south", DOOR_CLOSED); 
        set("coor/x",120);
        set("coor/y",180);
        set("coor/z",50);
        setup();
}    
