 // Room: /d/chuenyu/gate_castle.c
#include <ansi.h>
#include <room.h> 
inherit ROOM; 
void create()
{
        set("short", "���ɴ���");
        set("long", @LONG
��վ����һ����ΰ�ĳǱ�֮ǰ������(door)֮�Ϲ���һ����ҡ�������
���ɷ����д���ĸ����֡����ɴ��ڡ����������½Ǹվ�������
�����ڻ�̫������������һ��ʮ���ա���
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"east_castle",
  "west" : __DIR__"west_castle",
  "north" : __DIR__"trap_castle",
  "down" : __DIR__"high_b_mtn2",
]));
        set("outdoors", "chuenyu"); 
        create_door("north", "����", "south", DOOR_CLOSED); 
        set("coor/x",130);
        set("coor/y",140);
        set("coor/z",30);
        setup();
} 
void init()
{       object ob;
        int exp;
        if( interactive( ob = this_player()))
        {
        exp = ob->query("combat_exp");
    if(exp < 2000) {   
        ob->move(__DIR__"high_b_mtn2.c");       
    message_vision(HIW"\n$N�����ɱ�ɢ����ǿ��ɱ�����˻�����\n\n"NOR, ob);
        }
        }
}      
