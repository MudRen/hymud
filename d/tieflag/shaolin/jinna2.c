 // TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "�����޵�");
        set("long", @LONG
���۵�������������������Ϊ������Ϊͭ����Ϊ����
���ͽ����档��Ϊ�����µĻ���٤��������𴦷����Ϊ����٤������
��ͬ����ν٤���������������б�����Ժ����˼���������٤����Ĺ�
ģʵ�ڲ�С�������ֳ������Ľ����ޣ��㲻������������
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"jinna",
]));
        set("objects", ([
                __DIR__"obj/jinna" : 1,
                __DIR__"npc/laomonk" : 2,
       ]) );
        set("coor/x",-190);
        set("coor/y",210);
        set("coor/z",40);
        setup();
        create_door("west", "ľ��", "east", DOOR_CLOSED);
}     
