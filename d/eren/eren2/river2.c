#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
���������������ǰȥ����������������ˮ������Ư�����Һ�ˮλ
���ߣ������Ż���̽��ͷ����������֪���˶�ã�ˮ�ƻ�����������ǿ��
��վ�ȡ��ߴ��ƺ���Щ����ζ�����ϡ�ճ�ǰ���м���Ų���ĺ�Ӱ��
LONG
        );
        set("exits", ([ 
                "west" : __DIR__"river1",
                "east" : __DIR__"river2",
        ]));
        set("objects", ([
                __DIR__"npc/cor" : 2,
                __DIR__"npc/kingcor" : 1,
        ]) );
        set("indoors", "eren2");
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
        object obj;
        object me, room;
        me= this_player();
        if(!arg || arg=="")
        {
                write("��Ҫ��ʲô��\n");
                return 1;
        }
        if( arg == "up")
        {
        message_vision(YEL"$N˫�ֲ���������ȥ��\n"NOR,me);
        call_out("climb_up",6,me);
        me->start_busy(4);
        return 1;
        }
        else
        {
                write("�㲻������ô����");
                return 1;
        }
}  
int climb_up (object me)        {
        object room;
        if(!objectp(me)) return 1;
        if (me->is_ghost()) return 1;
        room=find_object(__DIR__"yongdao7");
        if(!objectp(room)) 
                room = load_object(__DIR__"yongdao7"); 
        me->move(room);
        message_vision(HIG"$Nʪ���ܵشӰ��������ϰ�����\n"NOR,me);
        return 1;
}    
