//door.c
//Hydra 

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short","����լ��");
        set("long", @LONG
������һ�����ҵĴ��š�������������������һ�����ĸ��ˡ�������ɺ�ɫ��
�ŵ����Ϸ�д������������--���Ÿ����������������ɴִ��ľͷ���ɵģ���
�ڵ����߶�����ͷʨ�ӣ��������ݡ������Ҷ�վ���ſڣ�ϸ���ػ��ţ�һ������
���ý�լ�ġ�
LONG
        );
        set("outdoors","liangzhou");
        set("exits", ([ 
                "south"         :       __DIR__ "lroad2",
                "north"         :       __DIR__"fuzhai1",
                ])
        );
        set("objects",([
                __DIR__"npc/jiading":2,
        ]) );
        setup();
}

void init()
{
    add_action( "do_say","say" );
}

int valid_leave( object ppl,string dir )
{
    object ob;
    if ( dir == "north" && !ppl->query_temp("����/allow_enter")
        && objectp( ob = present ( "jia ding", environment( ppl )  ) )
        && living(ob) )
    {
        message_vision("�Ҷ���$N˵����δ����ү���룬�㲻�ܽ�ȥ��\n",ppl);
        return notify_fail("�㱻�Ҷ���ס��ȥ·��\n");
    }
    return ::valid_leave(ppl, dir);
}

int do_say( string arg )
{
    object me = this_player();
    if( arg != "�������췽�ɽ�������" ) return 0;
    if( !present("jia ding",environment(me)) )
    {
        write("��׼��˵��˭������\n");
        return 1;
    }
    
    if( me -> query_temp("����/have_noded") )
    {
        me->set_temp("����/allow_enter",1);
        tell_object( me,CYN"�Ҷ�����ԭ����ʦ�Ǵ������Ϸ��ɽ������ġ�"
            "��������\n"NOR);
        tell_object( me,CYN"���Ҽ�����˵���ɣ���Ӧ�û�������ġ�\n"NOR);
        return 1;        
    }
    else
    {
        tell_object( me,CYN"�Ҷ����������ͷ��Ŀ��������ˣ������ʦ��ô�������"
            "�������أ�\nȥȥȥ��\n"NOR);
        return 1;
    }
}
