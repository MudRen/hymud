 // TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
һ��޴�����ӣ��������ų�����������Ÿ����߲ˣ�ʳƷ��ÿ��
����ĺ��֮��ɮ�˱�������ۼ�������ʳ�һ�㰴�ȼ��ߵ����ν�
ʳ���������Ȳ�ͬ���ɼ��ȼ���֮�ϡ�
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"neiyuan",
  "west" : __DIR__"qianzao",
]));
        set("objects", ([
                __DIR__"npc/monk9" : 1,
       ]) );
        set("coor/x",-220);
        set("coor/y",300);
        set("coor/z",60);
        setup();
        create_door("west", "ľ��", "east", DOOR_CLOSED); 
}       
