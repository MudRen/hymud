#include <room.h>
inherit ROOM; 
void create()
{
        set("short", "����");
        set("long", @LONG
һ���ɺ�ĵ�̺�����ſڱ�ֱ������Զ�����䳤����ֹʮ�ɡ���ͷ��
����ʮ����ʯ�ף���������һ���Ż���ԭ��С��¥������ɽ���������С��
����ȴ�ǿ��ݲ������ڼ�ƹ�Ի͡�
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"gate",
  "south" : __DIR__"datang",
]));
        create_door("north", "�ƽ���", "south", DOOR_CLOSED);
        set("coor/x",250);
        set("coor/y",-80);
        set("coor/z",10);
        set("objects", ([
        __DIR__"npc/g_wushi" : 2,
                        ]) ); 
        setup();
}
void init()
{
        object me;
        me = this_player();
        if(interactive(me))
        me->set_temp("intime", time()); 
} 
int valid_leave(object me, string dir)
{
        int in_time;
        
        if (dir == "south")
        {
        in_time = me->query_temp("intime");
        me->set_temp("wait_time", time()-in_time);      
        }
   return 1;
}   
