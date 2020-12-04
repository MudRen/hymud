// wield.c
#include <ansi.h>
inherit F_CLEAN_UP;

int do_wield(object me, object ob);

int main(object me, string arg)
{
	object ob, *inv;
	int i, count;
	if (me->is_busy())
		return notify_fail("����æ���ء�\n");
    if (me->is_exert()) return notify_fail("������ʹ��"+me->query_exert()+"��\n");
    if (me->is_perform()) return notify_fail("������ʹ��"+me->query_perform()+"��\n");

	if( !arg ) return notify_fail("��Ҫװ��ʲô������\n");

	if(arg=="all") {
		inv = all_inventory(me);
		for(count=0, i=0; i<sizeof(inv); i++) {
			if( inv[i]->query("equipped") ) continue;
			if((int)me->query("max_neili") < (int)inv[i]->query("wield_maxneili")) continue;
			if((int)me->query("neili") < (int)inv[i]->query("wield_neili")) continue;
			if((int)me->query_str() < (int)inv[i]->query("wield_str")) continue;
			if(do_wield(me, inv[i]) ) count ++;
		}
		write("Ok.\n");
		return 1;
	}

	if( !objectp(ob = present(arg, me)) )
		return notify_fail("������û������������\n");

	if( ob->query("equipped") )
		return notify_fail("���Ѿ�װ�����ˡ�\n");

	if((int)me->query("max_neili") < (int)ob->query("wield_maxneili"))
		return notify_fail("��о�ȫ����Ϣ���ڣ�ԭ������������������װ��"+ob->name()+"��\n");
	if((int)me->query("neili") < (int)ob->query("wield_neili"))
		return notify_fail("��о�ȫ����Ϣ���ڣ�ԭ������������������װ��"+ob->name()+"��\n");
	if((int)me->query_str() < (int)ob->query("wield_str"))
		return notify_fail("�������"+ob->name()+"����������������ֻ�����ա�\n");

	return do_wield(me, ob);
}

int do_wield(object me, object ob)
{
	string str;

	if( ob->wield() ) {
		if( !stringp(str = ob->query("wield_msg")) )
			str = "$Nװ��$n��������\n";
		message_vision(str, me, ob);

if (!me->query_temp("item/wield") && (ob->query("makeritem")||ob->query("systemmake")))
{	
    if (ob->query("weapon_prop/neili"))
{
    	me->add("neili",ob->query("weapon_prop/neili")*500);
message_vision(HIB + ob->query("name") + HIB"���һ����͵����⣬$N��������ԡ�¸е������쳣�ĳ��棡\n"NOR, me);
me->set_temp("item/wield",1);
}    
    if (ob->query("weapon_prop/qi"))
{
    	me->add("max_qi",ob->query("weapon_prop/qi")*300);
    	me->add("eff_qi",ob->query("weapon_prop/qi")*300);
      me->add("qi",ob->query("weapon_prop/qi")*300);
message_vision(HIR + ob->query("name") + HIR"���һ��ҫ�۵ĺ�⣬$N��������ԡ�¸е������쳣�ĳ��棡\n"NOR, me);
me->set_temp("item/wield",1);
}    
    if (ob->query("weapon_prop/jing"))
{
    	me->add("max_jing",ob->query("weapon_prop/jing")*300);
    	me->add("eff_jing",ob->query("weapon_prop/jing")*300);
      me->add("jing",ob->query("weapon_prop/jing")*300);
message_vision(HIY + ob->query("name") + HIY"���һ����Ŀ�Ļƹ⣬$N��������ԡ�¸е������쳣�ĳ��棡\n"NOR, me);
me->set_temp("item/wield",1);
}   
    
    if (ob->query("weapon_prop/jingli"))
{
      me->add("max_jingli",ob->query("weapon_prop/jingli")*300);
      me->add("eff_jingli",ob->query("weapon_prop/jingli")*300);
      me->add("jingli",ob->query("weapon_prop/jingli")*300);
message_vision(HIC + ob->query("name") + HIC"���һ����Ŀ���̹⣬$N��������ԡ�¸е������쳣�ĳ��棡\n"NOR, me);
me->set_temp("item/wield",1);
}
}

if (userp(me) && me->query_temp("xmud")) 
{
	seteuid(getuid());
	me->force_me("xnventory");
}
		return 1;
	} else
		return 0;
}

int help(object me)
{
	write(@HELP
ָ���ʽ��wield <װ������>
 
���ָ������װ��ĳ����Ʒ������, �����Ҫӵ��������Ʒ.
 
HELP
    );
    return 1;
}
