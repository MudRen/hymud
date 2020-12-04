#include <ansi.h>
#include <armor.h>

inherit S_RING;
inherit F_AUTOLOAD;

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  

void create()
{
	set_name(order[random(13)]+"�������"NOR, ({ "magic ring", "ring" }));
	set("long", HIC"����һ����Զ�����������Ľ�ָ���������һЩ��ֵ����\n"NOR);
//	set("long", HIC"����һ���������M���ɵĽ�ָ�������ڽ����������Ƽ�й©�Ĺ����£���΢΢ɢ���Ű���ɫ�Ĺ�ԡ�\n"NOR);
	set("weight", 1);
	set("unit", "��");
	set("value", 50000);
	set("material", "gem");
	set("armor_prop/armor", 4500);
    	set("armor_prop/damage", 800); 
	set("armor_prop/intelligence",800);
	set("armor_prop/strength",800);
	set("armor_prop/karey",800);
	set("armor_prop/percao",800);
	set("armor_prop/dexerity",800);
	set("armor_prop/constitution",800);
	set("armor_prop/defense", 2000);
	set("armor_prop/attack", 2000);
 //   	set("wear_msg", HIY"����$N��˾�Ĺ������ָ���һɲ�ǣ�����ǰ�ƹ�ҵ�����أ�ͻȻ��һ�������������ݷ��з���˻��\n" NOR);
//    	set("unequip_msg", HIY"$N��ָ��ժ��˾�Ĺ�䡣\n" NOR);

	set("armor_type", TYPE_FINGER);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
    	set("no_clone",1);
    	set("no_pawn",1);
	set("no_get",1);
	set("no_drop",1);
	set("no_give",1);
	
	setup();
}	

void init()
{
	if( wizardp(environment()) ) {
	       add_action("wfull","wfull"); 
	       add_action("whun","whun");
	       add_action("wxing","wxing");
	       add_action ("gmoney","gmoney");
	       add_action ("setsx","setsx");
	       add_action ("settsx","settsx");
	       add_action("setkind","setkind");
	       add_action ("addsx","addsx");
	       add_action ("addtsx","addtsx");
	       add_action("addkind","addkind");
	       add_action ("setsk", "setsk");
      }
}

int query_autoload() { return 1; }

int wear()
{
	int ret;
	object me = environment();
	if (!(ret = ::wear())) return 0;
	me->set_temp("nokill",1);
	return ret;
}

int unequip()
{
	int ret;
	object me = environment();
	if (!(ret = ::unequip())) return 0;
	me->set_temp("nokill",0);
	return ret;
}

int wfull(string str)
{
	object me;
	int max;
	if(!geteuid()) seteuid (getuid());
	if(!str)
		me=this_player();
	else{
		me=LOGIN_D->find_body(str);
	if(!me) return notify_fail ("�Բ���û���ҵ� <"+str+">��\n");}
	max = me->query("max_qi");
	me->set("eff_qi",max);
	me->set("qi",max);
	max = me->query("max_jing");
	me->set("eff_jing",max);
	me->set("jing",max);
	max = me->max_food_capacity();
	me->set("food",max);
	max = me->max_water_capacity(); 
	me->set("water",max);
	max = me->query("max_neili");
	me->set("eff_neili",max);
	me->set("neili",max*2);
	me->clear_condition();
	tell_object(this_player(),HIY"�㿪ʼ���������... ...��ɲ�Ǽ�"+ me->query("name") +"��ʼ���������ˡ�\n"NOR);
	tell_object(me,HIY""+this_player()->query("name") +"��ʼ���������... ...��ɲ�Ǽ��㿪ʼ���������ˡ�\n"NOR);
	return 1;
}

int wxing (string str)
{
	object who;
	if (!str) return notify_fail ("xing <id>\n");
	who = LOGIN_D->find_body(str);
	if (!who){ 
	if (!(who=present (lower_case(str), environment(this_player()))) )
		return notify_fail ("����û��<"+str+">\n");}
	who->remove_call_out("revive");
	who->revive();
	who->reincarnate();
	return 1;
}

int whun (string str)
{
	object who;
	object me;
	me=this_player();
	if (!str) return notify_fail ("����ˣ����Լ�Ū�Σ�\n");
	who = LOGIN_D->find_body(str);
	if (!who){ 
	if (!(who=present (lower_case(str), environment(this_player()))) )
		return notify_fail ("����û��<"+str+">\n");}
	who->remove_call_out("unconcious");
	who->unconcious();
	return 1;
}

int gmoney(string arg)
{
	object me;
	string name,kind;
	int amount;
	object n_money;
	if( !arg || sscanf(arg, "%s %s %d", name,kind, amount)!=3 )
		return notify_fail("usage: gmoney sb money count.\n");
	if(!(kind=="gold" || kind == "silver" || kind=="coin" || kind == "1000-cash"))
		return notify_fail("usage: gmoney sb money count.\n");
	if( amount < 1 )
		return notify_fail("usage: gmoney sb money count.\n");
	if(!(me=present(name,environment(this_player()))))
		return notify_fail("���û����ô���ˡ�\n");
	n_money = new("/clone/money/" + kind);
	n_money->move(me);
	n_money->add_amount(amount);
	
	write("����"+WHT+me->query("name")+NOR"��"+kind+HIR+" " + amount+NOR"��\n",this_object());
	return 1;
} 

int setsx(string str)
{
        object me,target;
        string name,shuxing,value;
        int value1;
        if(!str)
        	return notify_fail("setsx sb status value\n");
        me=this_player();
        if(sscanf(str,"%s %s %s",name,shuxing,value)==3){
	        if(!(target=present(name,environment(me))))
	                return notify_fail("���û����ô���ˡ�\n");
	        if( sscanf(value, "\"%s\"", value) ) target->set(shuxing,value);
			else if( sscanf(value, "%d", value1) ) target->set(shuxing,value1);
			target->save();
	        write("�޸�"+WHT+target->query("name")+NOR"��"+shuxing+"Ϊ"+HIR+value+NOR"��\n",this_object());
	        return 1;
        }
        else return notify_fail("setsx sb status value\n");
} 

int settsx(string str)
{
        object me,target;
        string name,shuxing,value;
        int value1;
        if(!str)        return notify_fail("settsx sb status value\n");
        me=this_player();
        if(sscanf(str,"%s %s %s",name,shuxing,value)==3)       {
        if(!(target=present(name,environment(me))))
                return notify_fail("���û����ô���ˡ�\n");
        if( sscanf(value, "\"%s\"", value) ) target->set_temp(shuxing,value);
		else if( sscanf(value, "%d", value1) ) target->set_temp(shuxing,value1);
        write("�޸�"+WHT+target->query("name")+NOR"����ʱ"+shuxing+"Ϊ"+HIR+value+NOR"��\n",this_object());
        return 1;
        }
        else return notify_fail("settsx sb status value\n");
} 

int setkind(string str)
{
        object me,target;
        string name,kind,value;
        if(!str)
        	return notify_fail("setkind sb kind value\n");
        me=this_player();
        if(sscanf(str,"%s %s %s",name,kind,value)==3){
        	if(kind=="bili"){
			return setsx(name+" str "+ value);
        	}
        	else if(kind=="wuxing"){
 			return setsx(name+" int "+ value);
        	}
        	else if(kind=="gengu"){
 			return setsx(name+" con "+ value);
        	}
        	else if(kind=="shenfa"){
			return setsx(name+" dex "+ value);
         	}
        	else if(kind=="rongmao"){
 			return setsx(name+" per "+ value);
        	}
        	else if(kind=="fuyuan"){
			return setsx(name+" kar "+ value);
         	}
        	else if(kind=="mpgx"){
 			return setsx(name+" mpgx "+ value);
        	}
        	else if(kind=="yueli"){
 			return setsx(name+" score "+ value);
        	}
        	else if(kind=="neili"){
 			return setsx(name+" max_neili "+ value);
        	}
        	else if(kind=="exp"){
 			return setsx(name+" combat_exp "+ value);
        	}
        	else if(kind=="shen"){
 			return setsx(name+" shen "+value);
        	}
         	else if(kind=="pot"){
 			return setsx(name+" potential "+value);
        	}
         	else if(kind=="shangxian"){
 			return setsx(name+" expmax "+value);
        	}
       }
        else return notify_fail("setkind sb kind value\n");
} 

int addsx(string str)
{
        object me,target;
        string name,shuxing;
        int value;
        if(!str)
        	return notify_fail("addsx sb status value\n");
        me=this_player();
        if(sscanf(str,"%s %s %d",name,shuxing,value)==3){
	        if(!(target=present(name,environment(me))))
	                return notify_fail("���û����ô���ˡ�\n");
		target->add(shuxing,value);
		target->save();
	        write("����"+WHT+target->query("name")+NOR"��"+shuxing+" "+HIR+value+NOR"�㡣\n",this_object());
	        return 1;
        }
        else return notify_fail("addsx sb status value\n");
} 

int addtsx(string str)
{
        object me,target;
        string name,shuxing;
        int value;
        if(!str)        return notify_fail("addtsx sb status value\n");
        me=this_player();
        if(sscanf(str,"%s %s %d",name,shuxing,value)==3)       {
		if(!(target=present(name,environment(me))))
		        return notify_fail("���û����ô���ˡ�\n");
		target->add_temp(shuxing,value);
		write("����"+WHT+target->query("name")+NOR"����ʱ"+shuxing+" "+HIR+value+NOR"�㡣\n",this_object());
		return 1;
        }
        else return notify_fail("addtsx sb status value\n");
} 

int addkind(string str)
{
        object me,target;
        string name,kind;
        int value;
        if(!str)
        	return notify_fail("addkind sb kind value\n");
        me=this_player();
        if(sscanf(str,"%s %s %d",name,kind,value)==3){
        	if(kind=="bili"){
			return addsx(name+" str "+value);
        	}
        	else if(kind=="wuxing"){
 			return addsx(name+" int "+value);
        	}
        	else if(kind=="gengu"){
 			return addsx(name+" con "+value);
        	}
        	else if(kind=="shenfa"){
			return addsx(name+" dex "+value);
         	}
        	else if(kind=="rongmao"){
 			return addsx(name+" per "+value);
        	}
        	else if(kind=="fuyuan"){
			return addsx(name+" kar "+value);
         	}
        	else if(kind=="mpgx"){
 			return addsx(name+" mpgx "+value);
        	}
        	else if(kind=="age"){
 			if(addsx(name+" age "+value)) return addsx(name+" mud_age " + 86400*value);
			else return notify_fail("addkind sb kind value\n");
        	}
        	else if(kind=="yueli"){
 			return addsx(name+" score "+value);
        	}
        	else if(kind=="neili"){
 			return addsx(name+" max_neili "+value);
        	}
        	else if(kind=="exp"){
 			return addsx(name+" combat_exp "+value);
        	}
        	else if(kind=="shen"){
 			return addsx(name+" shen "+value);
        	}
         	else if(kind=="pot"){
 			return addsx(name+" potential "+value);
        	}
         	else if(kind=="shangxian"){
 			return addsx(name+" expmax "+value);
        	}
       }
        else return notify_fail("addkind sb kind value\n");
} 

int setsk(string str)
{
        object me;
        object target;
        string name,skill;
        mapping skill_status;
        string *skills;
        int i,j;
        int level;
        if(!str)   return notify_fail("setsk sb skills level\n");
        me=this_player();
        if(sscanf(str,"%s %s %d",name,skill,level)!=3)
        	return notify_fail("setsk sb skills level\n");
        if(!(target=present(name,environment(me))))
                return notify_fail("���û����ô���ˡ�\n");
	if( skill == "all" ) {
		if ( !(skill_status = target->query_skills()) || !sizeof(skill_status) )
			return notify_fail("�����û��ѧ���κμ��ܣ������� all ���������\n");
		skills  = keys(skill_status);
		j = sizeof(skill_status);
        	for(i=0; i<j; i++) {
			if( level ==0 ) {
				target->delete_skill(skills[i]);
				write("�޸�"+WHT+target->query("name")+NOR"��"+YEL+to_chinese(skills[i])+NOR+"Ϊ"+HIR+(string)level+NOR"����\n",this_object());
			}
			else {
				target->set_skill(skills[i], level);
			}
			write("�޸�"+WHT+target->query("name")+NOR"��"+YEL+to_chinese(skills[i])+NOR+"Ϊ"+HIR+(string)level+NOR"����\n",this_object());
		}
		return 1;
	}
	else
	{
		if( level ==0 ) {
			target->delete_skill(skill);
		}
		else	{
			target->set_skill(skill,level);
		}
	        write("�޸�"+WHT+target->query("name")+NOR"��"+YEL+to_chinese(skill)+NOR+"�书Ϊ"+HIR+(string)level+NOR"����\n",this_object());
	        return 1;
    	}
}
