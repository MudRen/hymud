#include <room.h>
inherit ROOM; 
void create()
{
        set("short", "ɽ��");
        set("long", @LONG
С���а˽ǣ������ͤ��ֻ�������Ŵ����ա��񻨴����䣬���е���ɫ
���ɴ���˽Ƿ����£����лƽ�����壬���������������Ȫ���������ݡ�
���ɡ����١����ܼ䣬���������������磬�ƽ�Ϊ��������Ϊ�׵�СС¥��
��֮�����������ϡ�
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"sriver",
  "south" : __DIR__"dating",
]));
        set("objects", ([
        __DIR__"npc/feiyu" : 1,
        __DIR__"npc/s_wushi" : 2,
                        ]) ); 
        set("outdoors","palace");
        create_door("south", "�ƽ���", "north", DOOR_CLOSED);
        set("coor/x",250);
        set("coor/y",-70);
        set("coor/z",10);
        setup();
}        
