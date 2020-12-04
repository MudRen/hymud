// Npc : fangzhang.c
// hydra

#include <ansi.h>
inherit NPC;

void create()
{
    seteuid(getuid());
    set_name( "����", ({ "fang zhang", "monk" }) );
    set("title","�����·���");
    set( "attribute", "friendly" );
    set( "gender", "����" );
    set( "age", 50 );
    set( "long", @LONG
��λ�Ǵ����µķ��ɣ���һ����ü���������ӡ�
LONG
    );
    
    set( "str", 20 );
    set( "dex", 20 );
    set( "combat_exp", 3000 );
    set( "social_exp", 2000 );
    


        
    setup();
    carry_object( "/clone/misc/cloth" )->wear();
}

void init()
{
    object me;
    me = this_player();
    call_out( "greeting",3,me );
    add_action( "do_nod","nod");
}

void greeting( object me )
{
    if( random(3)==0 )
    {
        if(!me->query_temp("����/wait_nod"))
        {
            if ( environment(me) != environment() )  return;
            tell_object( me,CYN"�Ϸ��ɼ��㵽�������ĵظ���˵��������λ��ʦ���ܷ��ƶɮһ��æ����\n"NOR);
            tell_object( me,CYN"���Ը��Ļ����͵��ͷ��\n"NOR);
            me -> set_temp("����/wait_nod",1);
        }
    }
    else
    {
        if( userp(me) )
            command( "say �����ӷ𡣡�����");
    }
}
    
int do_nod( string arg )
{
    object me;
    string msg;
    me = this_player();
    if(!me->query_temp("����/wait_nod") || me->query_temp("����/have_noded") ) return 0;
    if( arg ) return 0;
    msg = "�Ϸ��ɡ�������������һһ����̾��һ����������ǰ���첻֪����ʲô�ط����˼���\n";
    msg += "���ˣ����������ݣ�ƾ������һ���ֽţ������ݳ��������Ϊ���۸����ա�����\n";
    msg += "ǰ�죬�ֿ����˸����żҵ�С�㣬˵Ҫ����������������\n";
    msg += "�ż���ʩ��֪�һ�һ�㹦��������ȥ��æ�����Ǹ��ߣ����ǡ�������������ƶɮ��\n";
    msg += "�����ǽ����֣�ʵ�ڲ������ǵĶ��֡�\n";
    msg += "�ҿ���ʦ�����գ��Ƿ�Ը���ƶɮ���æ��������ݰ�����ˮ��ƶɮ���������ˡ�\n";
    msg += "����Ÿ�����˵�ǡ������췽�ɽ������ġ������ǻ�������ġ�\n";
    tell_object( me,msg );
    me -> set_temp("����/have_noded",1);
    return 0;
}
