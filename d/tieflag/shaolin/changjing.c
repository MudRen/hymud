 // TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "�ؾ���");
        set("long", @LONG
�ؾ������������á�����ŷ𾭺͸�ɮ˵��������������������
�����ڴ˴���һ¥ͨ��������˵���ĳ�����Խ���Ϸ𾭱�Խ���أ�����
����ÿ������¶����ڴ˽���˵�����ն�������
����ľ��,�ź�¥��ͨ��¥�ϡ�
LONG
        );
        set("exits", ([ 
  "northdown" : __DIR__"fangnan",
  "up"  : __DIR__"changjing2",
  "southdown" : __DIR__"yonglu2",
  "eastdown": __DIR__"least",
  "westdown": __DIR__"lwest",
]));
        set("coor/x",-210);
        set("coor/y",230);
        set("coor/z",50);
        setup();
        create_door("up", "ľ��", "down", DOOR_CLOSED);
}  
