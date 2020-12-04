
// herbalist.c
#include <ansi.h>
inherit NPC;

mixed heal_me(mixed what);
void goodbye(object);
void remove_waiter(object);

void create()
{
	set_name("���ƹ�", ({ "herbalist" }) );
	set("title", "ɣ��ҩ��");
	set("gender", "����" );
	set("age", 54);
	set("long",
		"���ƹ����⸽���൱�����Ĵ����ˣ�����ʩ���ҩ��������ҩǮ������\n"
		"����������ҽ��Ҳ��������ʱ��������ɽ���µ����Ǻ���ѧҽ��һ��\n"
		"���˺�С��ֱ��������ҩ�Ա�ҽ�����顣\n" );
	set("combat_exp", 1300);
	set("attitude", "friendly");
	set("inquiry", ([
			"����": (: heal_me :),
			"��ҩ": (: heal_me :),
	        "�β�": (: heal_me :),
        	"����": (: heal_me :),
	        "����": (: heal_me :),
        	"�ָ�": (: heal_me :),
        	"�ⶾ": 
"��Ӵ���㲻˵�ҵ����ˣ���������һ��ȥ�����Ǵ�ʦ���......\n",
	]) );

	set_skill("literate", 70);
	set_skill("dodge", 60);
	set_skill("unarmed", 60);
	set("score",-200000);
	setup();
	add_money("silver", 10);
}

mixed heal_me(mixed what)
{
int damage_type=0;
int dec1,dec2,dec3;
object me;
me=this_player();
if (dec1=me->query("max_gin")-me->query("eff_gin"))
                damage_type=1;
if (dec2=me->query("max_kee")-me->query("eff_kee"))
                damage_type=2;
if (dec3=me->query("max_sen")-me->query("eff_sen"))
                damage_type=4;
if (!objectp(what))
	{
	switch (what)
        	{
	        case 1: return dec1;
        	case 2: return dec2;
	        case 3: return dec3;
        	default:
		}
	}
if (is_fighting())
	return notify_fail("û��������Ҫɱ����?!\n");
if (query("healing")) 
	return notify_fail("�Բ�������æ���أ����Ժ�\n");
if (damage_type)
        {
        message_vision("$N��$n˵��:"+
                       "��λ"+RANK_D->query_respect(me)+", ��ɫ��̫����! \n",
                       this_object(),me);
        me->set_temp("pending/recover",1);
	remove_call_out("remove_wait");
	set_temp("waiting",1);
call_out("remove_wait",5,me);
        add_action("do_agree","agree");
        return (RANK_D->query_respect(me)+"Ҫ�Ҹ��㿴����(agree)? �����ɱ���ϧǮ��.\n");
        }
return (RANK_D->query_respect(me)+", �����ӹǶ��ܽ�ʵ, ûɶ���ε�.\n");
}

void remove_wait(object me)
	{
	me->delete_temp("pending/recover");
	tell_room(environment(),this_object()->query("name")+"˵��: "+
		"��!"+me->query("name")+
		"���β���Ǯ������û�! ����..........@#@!$%^&*!\n");
	command("scowl");
	this_object()->delete_temp("waiting");
	return;
	}

int do_agree(string arg)
{
object me,*ob;
int i,money,tmp,cure;
me=this_player();
set("healing",1);
if (!me->query_temp("pending/recover")) return 0;
remove_call_out("remove_wait");
money=(heal_me(2)+heal_me(2)+heal_me(1))*300; //coin
ob=all_inventory(me);
i=sizeof(ob);
while(i--)
	if (ob[i]->query("id")=="account book")
			break;
if (i<0)
	return notify_fail("��Ӧ��ȥ����һ���ʲ�!\n");
cure=ob[i]->query("rich");
if (cure<money)
      {
	  write(HIR "��ѽ,"+RANK_D->query_respect(me)+
     		"Ǯ���󲻹�Ү!\n"+"��ֻ�ܾ�����Ϊ��, ���ǶԲ���.\n");
ob[i]->set("rich",0);
ob[i]->save();
      cure/=300;
tmp=cure;
      cure-=heal_me(1);
      if (cure<0)  me->receive_curing("gin",tmp);
      else  
      	{
      	me->receive_curing("gin",heal_me(1));
tmp=cure;
      	cure-=heal_me(2);
      	if (cure<0)  me->receive_curing("kee",tmp);
	    else
	    	{
	    	me->receive_curing("kee",heal_me(2));
tmp=cure;
    	    cure-=heal_me(3);
	        if (cure<0)  me->receive_curing("sen",tmp); 
      		else  
      			me->receive_curing("sen",heal_me(3)); 
      		}
      	}
      }
else    {
        me->receive_curing("gin",heal_me(1));
        me->add("eff_kee",heal_me(2));
        me->add("eff_sen",heal_me(3));
	ob[i]->add("rich",-money);
	ob[i]->save();
        }
me->delete_temp("pending/recover");
call_out("goodbye",2,me);
return 1;
}

void goodbye(object patient)
{
say("��ӭ�����������Ժ��ڽ��������߿�Ҫ����Ŷ��\n");
if (query("healing")) delete("healing");
command("smile");
}
