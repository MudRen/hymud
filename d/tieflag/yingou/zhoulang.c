 inherit ROOM;
#include <room.h>
void create()
{
        set("short", "ʯ����");
        set("long", @LONG
���ź���ʮ����ʯ�ף��������������������ȼ�ŵƣ��ƻ�������һ���š�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"secret",
  "east" : __DIR__"pianting",
]));
        set("coor/x",-30);
        set("coor/y",-20);
        set("coor/z",-10);
        setup();
//door here
        create_door("north", "������", "south", DOOR_CLOSED); 
}       
