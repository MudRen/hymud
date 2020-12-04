#include <ansi.h>
inherit ROOM; 
void create()
{
        object me;
        me = this_player();
        set("short", "�ݿ�");
        set("long", @LONG
����һ������ĺ�«�͵��ݿӣ��ıڳ�ʪ���ֹ⻬���ӵ���Ϊ����
�ű��������Ѿ����õ�ʬ�壬�Ա��ƺ����м�ֻ���������ںڰ��п�
�����㣬�·��ڵ��Ž�����Ϊ��һ�����͡�
LONG);
        set("indoors", "eren2");
        set("no_magic",1);
        set("objects", ([
                __DIR__"npc/rat" : 1,
        ]) );
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
} 
void init()
{       
        add_action("do_climb", "climb");
}  
int do_climb(string arg)
{
    object obj, me;
    int kar;
    
    if(!arg || arg=="") return notify_fail("��Ҫ����������\n");
    me = this_player();
    if( arg == "wall" || arg == "����" || arg == "up")
    {
        if( me->is_busy() )
            return notify_fail("��Ķ�����û����ɣ������ƶ���\n");
        message_vision("$Nʹ�����̵�������˳�Ŷ���������ȥ��\n", me);
        me->start_busy(1);
        call_out("climb_wall", 2, me);
        return 1;
    }
    return notify_fail("�㲻������"+arg+"��\n");
}        
int climb_wall(object me)
{
    int kar;
    
    if (me->is_ghost()) return 0;
    kar = (int)me->query("kar");
    if( kar > 60 ) kar = 60;
    if( random(60 - kar) < 15 )
    {
        me->move(__DIR__"yongdao2a.c");
        message_vision("$N�������м��ѵ����˳�����\n", me);
    }
    else message_vision("$N����һ��ûץ�ȣ��ֵ���������\n", me);
    return 1;
}   
