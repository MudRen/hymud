 inherit ROOM;
#include <room.h>
void create()
{
        set("short", "�ص���");
        set("long", @LONG
��������ת�˼���������ƺ������΢����Щ�����Ե�ͭ��������
ɫ�Ĺ⣬����ӰͶӡ��ʯ���ϡ�ӭ��һ��΢�紵���������ƺ����������㣬
�����Ŀ����ơ�����ǰ����������ͷ��һ��ͭ�Ű뿪��
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"garden",
  "west" : __DIR__"secretpath1",
]));
        set("outdoors","palace");
        create_door("east", "ͭ��", "west", DOOR_CLOSED);
        set("coor/x",250);
        set("coor/y",-40);
        set("coor/z",10);
        setup();
}        
