// wear.c

#include <ansi.h>

inherit F_CLEAN_UP;

int do_wear(object me, object ob);

int main(object me, string arg)
{
	object ob, *inv;
	int i, count;

	if( !arg ) return notify_fail("��Ҫ����ʲô��\n");
   if (me->is_busy()) return notify_fail("����æ����!\n");
	if(arg=="all") {
		inv = all_inventory(me);
		for(count=0, i=0; i<sizeof(inv); i++) {
			if( inv[i]->query("equipped") ) continue;
			if((int)me->query_str() < (int)inv[i]->query("wear_str")) continue;
			if((int)me->query_con() < (int)inv[i]->query("wear_con")) continue;
			if((int)me->query("max_neili") < (int)inv[i]->query("wear_maxneili")) continue;
			if(do_wear(me, inv[i]) ) count ++;
		}
		write("Ok.\n");
		return 1;
	}

	if( !objectp(ob = present(arg, me)) )
		return notify_fail("������û������������\n");

	if( ob->query("equipped") )
		return notify_fail("���Ѿ�װ�����ˡ�\n");

	if (userp(me) && me->query("max_neili") < ob->query("wear_maxneili"))
		return notify_fail("��о�ȫ����Ϣ���ڣ�ԭ������������������װ��"+ob->name()+"��\n");
	if (userp(me) && me->query_con() < ob->query("wear_con"))
		return notify_fail("����װ��"+ob->name()+"���������岻��ǿ׳��ֻ�����ա�\n");
	if (userp(me) && me->query_str() < ob->query("wear_str"))
		return notify_fail("����װ��"+ob->name()+"����������������ֻ�����ա�\n");

	return do_wear(me, ob);
}

int do_wear(object me, object ob)
{
	string str;

	if( ob->query("id") == "jinsi jia" && me->query("age") >= 20)
		return notify_fail("�㳤���ˣ������Ͻ�˿���ˡ�\n");

	if( ob->query("female_only")
	&&      (string)me->query("gender") =="����")
		return notify_fail("����Ů�˵���������һ��������Ҳ�봩����Ҳ���ߣ�\n");

	if( ob->wear() ) {
		if( !stringp(str = ob->query("wear_msg")) )
			switch( ob->query("armor_type") ) {
				case "cloth":
				case "armor":
				case "boots":
					str = YEL "$N����һ" + ob->query("unit") + "$n��\n" NOR;
					break;
				case "head":
				case "neck":
				case "wrists":
				case "finger":
				case "hands":
					str = YEL "$N����һ" + ob->query("unit") + "$n��\n" NOR;
					break;
				case "waist":
					str = YEL "$N����һ" + ob->query("unit") + "$n��\n" NOR;
					break;
				case "wrists":
					str = YEL "$N����һ" + ob->query("unit") + "$n��\n" NOR;
					break;
				case "surcoat":
					str = YEL "$N����һ" + ob->query("unit") + "$n��\n" NOR;
					break;
				case "shield":
					str = YEL "$N����һ" + ob->query("unit") + "$n��\n" NOR;
					break;

				default:
					str = YEL "$Nװ��$n��\n" NOR;
			}
		message_vision(str, me, ob);

if (!me->query_temp("item/wielda") && (ob->query("makeritem")||ob->query("systemmake")))
{	
    if (ob->query("armor_prop/neili"))
{
    	me->add("neili",ob->query("armor_prop/neili")*500);
message_vision(HIB + ob->query("name") + HIB"���һ����͵����⣬$N��������ԡ�¸е������쳣�ĳ��棡\n"NOR, me);
me->set_temp("item/wielda",1);
}    
    if (ob->query("armor_prop/qi"))
{
    	me->add("max_qi",ob->query("armor_prop/qi")*300);
    	me->add("eff_qi",ob->query("armor_prop/qi")*300);
      me->add("qi",ob->query("armor_prop/qi")*300);
message_vision(HIR + ob->query("name") + HIR"���һ��ҫ�۵ĺ�⣬$N��������ԡ�¸е������쳣�ĳ��棡\n"NOR, me);
me->set_temp("item/wielda",1);
}    
    if (ob->query("armor_prop/jing"))
{
    	me->add("max_jing",ob->query("armor_prop/jing")*300);
    	me->add("eff_jing",ob->query("armor_prop/jing")*300);
      me->add("jing",ob->query("armor_prop/jing")*300);
message_vision(HIY + ob->query("name") + HIY"���һ����Ŀ�Ļƹ⣬$N��������ԡ�¸е������쳣�ĳ��棡\n"NOR, me);
me->set_temp("item/wielda",1);
}   
    
    if (ob->query("armor_prop/jingli"))
{
      me->add("max_jingli",ob->query("armor_prop/jingli")*300);
      me->add("eff_jingli",ob->query("armor_prop/jingli")*300);
      me->add("jingli",ob->query("armor_prop/jingli")*300);
message_vision(HIC + ob->query("name") + HIC"���һ����Ŀ���̹⣬$N��������ԡ�¸е������쳣�ĳ��棡\n"NOR, me);
me->set_temp("item/wielda",1);
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
ָ���ʽ��wear <װ������>
 
���ָ������װ��ĳ�����ߡ�
 
HELP
    );
    return 1;
}
