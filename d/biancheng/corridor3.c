#include <room.h>
#include <ansi.h>
inherit ROOM;
void create() 
{
        set("short", "¥��");
        set("long", @LONG
�߹�¥����ǰ�������Ⱥ�����ң��������һ��������ʮ���죬һ���ʮ��С
ʱ���˵�ֵ��������������ģ��������Ⱥ�ĵմ����ӣ����Ǹ�����������������
�������������ܹܹ���ϣ�����������������ҲҪͨ���˲�����¥��
LONG
        );
        set("exits", ([ 
        "down": __DIR__"pianting2",
        "north": __DIR__"uproom1",
        "east": __DIR__"uproom2",
        ]));
        set("objects", ([
                __DIR__"npc/vguard4":   1,
        ]) );
        set("coor/x",-1120);
        set("coor/y",320);
        set("coor/z",10);
        setup();
        create_door("north","ľ��","south",DOOR_CLOSED);
}   
