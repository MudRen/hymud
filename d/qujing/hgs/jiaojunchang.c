//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "����ɽ�̾���");
set("long", @LONG
    
һƬ�����Ĳݵأ��������ǵ������ǵĽ̾�
����ֻ������һ�������ͨ��Գָ����һ��
�У�һ�����߹����ĺ��ӱ���
LONG );


set("exits", ([
"east"   : __DIR__"shanya",
]));


set("objects", ([
__DIR__"npc/beng" : 3,
]));



set("outdoors", "xy19");
setup();
}
