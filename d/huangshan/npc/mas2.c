 inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void smart_fight(); 
void create()
{
    set_name("����ü", ({ "master liu", "master","liu" }) );
    set("gender", "Ů��" );
    set("nickname", HIG"ӵ��ɽׯ�ٷ���"NOR);
    set("apprentice_available", 50);
    create_family("��ɽ��", 3, "����");
    set("long",
        "����ü��ɽ�����ŷ���\n"
        );
    set("age", 26);
    set("int", 30);
    set("per", 30);
    set("cor",  50);
    set("reward_npc", 1);
    set("difficulty", 30);  
       set("ill_boss",5);
    set("chat_chance", 1);
    set("chat_msg", ({
        name()+"�ֹ������森���ҵ�������ô�����ˣ�\n",
            }) );
   set("max_neili", 99000);
        set("neili", 99000);

        set("combat_exp", 99999999);
        set_skill("unarmed", 100);
        set_skill("sword", 150);
        set_skill("force", 100);
        set_skill("literate", 100);
	set_skill("dodge", 100);
        set("max_neili", 95000);
        set("neili", 95000);
        set("force_factor", 30);
	set("max_qi",99999);
        set("max_jing",99999);
	set("eff_qi",99999);
	set("qi",99999);
	set("eff_jing",99999);
	set("jing",99999);
        set_skill("yunwu-strike", 500);
        set_skill("siqi-sword", 520);
        set_skill("xianjing", 550);
        set_skill("liuquan-steps", 500);

        map_skill("unarmed", "yunwu-strike");
        map_skill("sword", "siqi-sword");
        map_skill("force", "xianjing");
        map_skill("dodge", "liuquan-steps");
        set("chat_chance", 5);
        set("chat_msg", ({
                (: random_move :),
        }) );
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.liushuichanchan" :),
                (: perform_action, "unarmed.miwu" :),
                (: perform_action, "sword.siqi" :),
        }) );
        set("pubmaster",1);
    
    set("ranks",({"����","С��","����","����","����","����","Ԫ��","������"}));
    setup();
    carry_object(__DIR__"obj/yellowcloth")->wear();
    carry_object(__DIR__"obj/yusword")->wield();
}
void reset()
{
        delete_temp("learned");
        set("apprentice_available", 20);
} 
void init()
{ 
        object ob;
        ::init();
        if( interactive(ob = this_player()) ) {
                remove_call_out("punish_betray");
                call_out("punish_betray",2 , ob);
        }
}
/*void punish_betray(object ob)
{
        if( ( ob->query("once_huangshan")) && ( (ob->query("class"))!= "huangshan"))
          {      
                tell_object(ob, YEL"\n����ü������Ц���������Ȼ�г����ţ��Ͳ������б��ŵ��书����\n"NOR);              
                message("vision", "����ü��"+ ob->name() +"��Ц������"+ ob->name() + "�� ���Ȼ�г����ţ��Ͳ������б��ŵ��书��\n", environment(ob), ob);
           tell_object(ob, HIW"����ü��һ�һ֧ţë��ϸС�ķ����������ֱۣ�\n"NOR);              
                message("vision", HIW"����ü����"+ ob->name() +"��һ����һ֧ţë��ϸС�ķ��룡\n"NOR, environment(ob), ob);
                
                if (ob->query_skill("liuquan-steps",1)) ob->delete_skill("liuquan-steps",0);
                if (ob->query_skill("qiusheng-blade",1)) ob->delete_skill("qiusheng-blade",0);
                if (ob->query_skill("yunwu-strike",1)) ob->delete_skill("yunwu-strike",0);
                if (ob->query_skill("siqi-sword",1)) ob->delete_skill("siqi-sword",0);
                tell_object(ob, HIR"��ֻ��Ѫ��һ���������书ȫʧ����\n"NOR);
                ob->delete("once_huangshan");
          }
} */ 

int recruit_apprentice(object ob)
{
    if( ::recruit_apprentice(ob) )
        ob->set("class", "huangshan");
    add("apprentice_availavble", -1);
}
int accept_fight(object me)
{
                return 0;
} 
int accept_object(object who, object ob)
{
	int i;

	if (!(int)who->query_temp("learn_timeb"))      
		who->set_temp("learn_timeb", 0);

	if( ob->query("money_id") )
{
	if(who->query_skill("unarmed",1)<30)
		i=ob->value() / 50;
	else
	{
		if(who->query_skill("unarmed",1)<60)
			i=ob->value() / 100;
		else
		{
			if(who->query_skill("unarmed",1)<100)
				i=ob->value() / 100;
			else
				i=ob->value() / 100;
		}
	}
	who->add_temp("learn_timeb",i);
command("say ��Ȼ�������ѧ�ҵ��书���Ҿͳ�ȫ��ȫ��ɡ�");
	return 1;
}	
	
        if(ob->query("id") == "old jade")
        {
        command("smile");
        command("thank "+who->query("id"));
        if((int)ob->query("max_cure") < 5)
        call_out("give_pena",3,who);
        else
        call_out("give_reward",3,who);
        return 1;
        } 
}
int give_reward(object who)
{
if(environment() != environment(who)) return 1;
if(!who->query("m_success/����ʯ"))
        {
                who->set("m_success/����ʯ",1);
                who->add("score",700); 
        }
return 1;
} 
int give_pena(object who)
{
if(environment() != environment(who)) return 1;
command("say �㾹Ȼ��͵�ñ����˵���ʯ������\n");
kill_ob(who);
who->kill_ob(this_object());
return 1;
}  
smart_fight()
{
        int i;
        object *enemy, who,count,j;
        who = this_object();
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        if (who->query("qi")<8000) {
                count=0;
                for (j=0;j<sizeof(enemy);j++) {
                        if (enemy[j]->is_zombie()) count++;
                }
                if (count>=3)
                        command("perform zombie-wp1");
        }
        if (!random(3)) who->perform_action("sword.siqi");
        return;
}       


int recognize_apprentice(object ob)
{
	if( ob->query_temp("learn_timeb") <= 0) return 0;
else         
ob->add_temp("learn_timeb",-1);
return 1;
}