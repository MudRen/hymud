
//Writen by lnwm on 97/07/11

//maowu.c

#include <ansi.h>

inherit ROOM;

void do_refuse( object who);

void create()
{
        set("short", "Сé��");
        set("long", @LONG
é�ݵ���ߺ����һ�������࣬����򵥡�һ�Ŵ��̵���齰ڷ������ӵ�
һ�ǡ��ıڿտգ�ֻ��������ǽ�Ϲ���һ��ˮīɽˮ����ֽ��΢΢���ƣ���Ȼ
��ͷ���̡��ݽŵ�ˮ����ʢ����ˮ��ˮ�峺���ף�Ӧ�Ǵ�����СϪ�й����ġ�
LONG
        );
       set("exits", ([
            "out" 		:		__DIR__ "shanpo",
		]));
        set("objects", ([		
		 __DIR__ "npc/shenren": 1,
		]) );
        setup();
}

void init()
{
    object who;
    who = this_player();
    if( !userp( who ) ) return;
    do_refuse( who );
}

void do_refuse( object who )
{
	if( who->query_temp("lnwm/���ɽ�",1))
	{
		tell_object(who,CYN"\n�������������һ�����������Լ�������\n"NOR);
		tell_object(who,RED"\n��ֻ������ǰ��Ӱһ������ֻ����ɤ����һ���𣬾�ʲôҲ��֪���ˡ�\n"NOR);
		who->die();
		return;
	}	
	else
	{
		tell_object(who,CYN"\n�������˼��㴳�˽�����ͻȻԲ��˫�ۣ�����ô�Ҵ����ҵ����ӣ���\n"NOR);
		tell_object(who,CYN"\n��ֻ������ǰ��Ӱһ����һ�ɴ��������Ƴ������ӡ�\n"NOR);
		who->set_temp("lnwm/���ɽ�",1);
		who->move( __DIR__"shanpo");
		tell_object(who,RED"\n\nֻ�����˵����������д������´��ٸҴ����ҵ����ӣ��͵�����������\n\n"NOR);
		who->unconcious();
		return;
	}
}
    


