// make by take for cs system. edit 1-31-02 13:20
inherit ITEM;

#include <ansi.h>

void create()
{
	set_name(HIC"��"+HIG"ɫ"+HIY"��"+HIR"��"NOR, ({"ling huo","huo","fire"}));
	set("unit", "��" );
	set_weight(1000000000);
        set("long",@long
���ǻ������а�������߶����ɵ���ɫ���棬Ҫ������(pu fire)��ֻ��Ҫ����ʱ�䡣������жϿ���(halt) ��
long );
	set("no_clean_up", 1);
	set("no_get",1);
	set("no_sell",1);
	set("no_put",1);
	setup();

}

void init()
{
	add_action("do_pu","pu");
	add_action("do_halt","halt");
	call_out("wait_TWin",130+random(30));
}

int do_pu()
{
	object ob,me;
	me = this_player();
	ob = this_object();
	if (me->is_busy())
	return notify_fail("�㻹���ȾȾ��Լ��ɡ�\n");
	if (me->query_temp("pkgame") != "ct")
	return notify_fail("����̫Σ�գ��㻹�ǲ�Ҫ��������ˡ�\n");
	if (me->query("env/invisibility"))
	return notify_fail("������ʱ��������\n");
	me->set_temp("waitwin",1);
	me->start_busy(9);
	message_vision (HIC"\n$N����ų��������Ļ������������۾���Ĭ���������������\n"NOR, me );
	call_out("wait_CtWin",10,me,ob);
	return 1;
}

int do_halt()
{
	object me;
	me = this_player();
	if (!me->query_temp("waitwin")) return 0;
	remove_call_out("wait_CtWin");
	me->start_busy(1);
	me->delete_temp("waitwin");
    	message_vision (HIC"\n$N������������˫�ۣ��ָ���ս��״̬��\n"NOR, me );
    	return 1;
}

void wait_CtWin(object me,object ob)
{
   	if (!me || !ob || !me->query_temp("waitwin")) return;
   	remove_call_out("wait_CtWin");
	remove_call_out("wait_TWin");
     	message_vision (HIC"\n��ɫ����$N����ѹ�ƣ�����ʧȥ����������Ϣ��Ϩ���ˣ�\n"NOR, me );
   	message( "rumor", HIM"\n\n������ҹ����ĳ�ˣ���ɫ����Ȼ��"HIW+me->query("family/family_name")+HIY""+me->query("name")+HIM"ʩ�������ˡ�\n\n"NOR, users() );
     	me->delete_temp("waitwin");
     	me->add_temp("pgwin",2);
	message( "system", BLINK HIR"\n�� CS �������� ���ֽ������˾ֱ���"+HIY"����"+BLINK HIR"���ʤ,���λ׼��5���Ӻ�ʼ��һ�ֱ���������������\n" NOR, users() );
       	"/cmds/usr/pkgame"->over();
     	"/cmds/usr/pkgame"->query_Win("ct");
        destruct (ob);
}

void wait_TWin()
{
	object ob,who;
	ob = this_object();
	if ( !ob ) return;
	remove_call_out("wait_CtWin");
	remove_call_out("wait_TWin");
  message( "chat", HIY"\n\n��̫ƽʢ����ǧ����(Qianli yan)����ɫ���������˼䣬�½�һƬ�𺣣�����Ϳ̿������������\n\n"NOR, users() );
	message( "system", BLINK HIR"\n�� CS �������� ���ֽ������˾ֱ���"+HIY"�ݻ�"+BLINK HIR"���ʤ,���λ׼��5���Ӻ�ʼ��һ�ֱ���������������\n" NOR, users() );
 	if ( ob->query_temp("fire_id") )
 	{
 		who = ob->query_temp("fire_id");
 	  if ( who )
 	  who->add_temp("pgwin",1);
 	}
 	"/cmds/usr/pkgame"->over();
	"/cmds/usr/pkgame"->query_Win("t");
  destruct (ob);
}


	
