// make by take for cs system. edit 1-31-02 13:20
inherit ITEM;

#include <ansi.h>

void create()
{
	set_name(HIR"�����"NOR, ({"huo lingfu","fu"}));
	set("unit", "��" );
	set_weight(10);
        set("long",@long
���ǷŻ�ר�õĻ�����������Է������κεط���ָ��(fire),�����;���жϿ���(halt) .
long );
	set("no_sell","�ƹ��ҡҡͷ˵���ⱦ��С�겻���ա�\n");
	set("no_put",1);
	set("bomb",1);
	setup();

}

void init()
{
	add_action("do_fire","fire");
	add_action("do_halt","halt");
}

int do_fire()
{
	object room,ob,me,fire;
	string answer ;
	me = this_player();
	ob = this_object();
	room = environment(me);
	if (room->query("no_fight") || room->query("no_magic"))
	return notify_fail("���ﲻ�ܷ��û�������㻹�ǻ����ط��ɣ�\n");
	if (me->is_busy())
	return notify_fail("�㻹�ǵ��пյ�ʱ�������Ż�ɡ�\n");
	if (me->query_temp("firewait"))
	return notify_fail("�㲻�����ڷŻ���\n");
	message_vision (HIR"\n$NС������Ľ�һ����������ڵ��ϣ����ĬĬ��������������\n"NOR, me );
	me->set_temp("firewait",1);
	me->start_busy(9);
        call_out("wait_fire",10,me,ob,room,answer);
        return 1;
}

int do_halt()
{
	object me;
	me = this_player();
	if (!me->query_temp("firewait")) return 0;
	remove_call_out("wait_fire");
	me->start_busy(1);
	me->delete_temp("firewait");
    	message_vision (HIW"\n$NͻȻ�����������ָ���ս��״̬��\n"NOR, me );
    	return 1;
}

void wait_fire(object me,object ob,object room,string answer)
{
   	object fire ;
   	if (!me || !room) return;
          message( "chat", HIY"\n\n��̫ƽʢ����ǧ����(Qianli yan)��"+answer+HIY"������������һƬ����д���������ֻ���е����⡣\n\n"NOR, users() );
        fire = new(__DIR__"fire");
        fire -> set_temp("fire_id",me);
        fire->move(room);
     	me->delete_temp("firewait");
     	message_vision (HIR"\n�����������߶�������$N��������ĺڰ�����ȼ��������\n"NOR, me );
        destruct (ob);
}
