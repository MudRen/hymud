 //TIE@FY3
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void smart_fight();  
void create()
{
    set_name("����", ({ "master li", "master","li" }) );
    set("gender", "����" );
    set("nickname", HIG"ӵ��ɽׯ����"NOR);
    set("age", 25);
    set("int", 30);
    set("per", 30);
    set("cor", 50);
    set("reward_npc", 1);
    set("difficulty", 30);
    set("ill_boss",5);
    set("apprentice_available", 50);
    create_family("��ɽ��", 3, "����");
    set("rank_nogen",1);
    set("ranks",({"����","С��","����","����","����","����","Ԫ��","������"}));
    
    set("long",
        "���������µ�һ���������֮�ӣ�����ӵ��ɽׯ����������Ϊ������Ϊ��ɽ������\n"
        );
     set("pubmaster",1);
    set("force_factor", 120);
    set("max_neili", 2000);
    set("neili", 2000);
    set("resistance/sen",80); 
    set("combat_exp", 6000000);
    set("score", 90000);
            set("max_neili", 95000);
        set("neili", 95000);
        set("force_factor", 30);
	set("max_qi",99999);
        set("max_jing",99999);
	set("eff_qi",99999);
	set("qi",99999);
	set("eff_jing",99999);
	set("jing",99999);
  
        set("combat_exp", 59999999);
        set("score", 90000);
        set_skill("unarmed", 100);
        set_skill("blade", 150);
        set_skill("force", 100);
        set_skill("literate", 100);
	set_skill("dodge", 100);

	set_skill("yunwu-strike", 500);
	set_skill("qiusheng-blade", 530);
	set_skill("xianjing", 550);
	set_skill("liuquan-steps", 500);

	map_skill("unarmed", "yunwu-strike");
        map_skill("blade", "qiusheng-blade");
        map_skill("force", "xianjing");
        map_skill("dodge", "liuquan-steps");
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.liushuichanchan" :),
                (: perform_action, "unarmed.miwu" :),
                (: perform_action, "blade.jingsheng" :),
        }) );  
            

    
    setup();
    //carry_object(__DIR__"obj/cq");
    carry_object(__DIR__"obj/greencloth")->wear();
    carry_object(__DIR__"obj/yuhuan")->wield();
    if (!random(6000000)) carry_object(__DIR__"obj/cq2");
}
void reset()
{
        delete_temp("learned");
        set("apprentice_available", 2);
}

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
void init()
{
        add_action("do_get","get");
} 
int do_get(string arg)
{
    string what,where;
    object the_wall;
    if(!arg) return 0;
    if(sscanf(arg,"%s from %s",what, where) !=2) return 0;
    the_wall = present(where,environment(this_object())) ;
    if (the_wall)
    if(the_wall->query("name") == "��ǽ")       
    {
        message_vision("$N��$n���һ�����󵨣����Ҵ��ȸ���������⣡\n",
                       this_object(),this_player());
        this_object()->kill_ob(this_player());
        this_player()->start_busy(2);
        return 1;
    }
    return 0;
}  
smart_fight()
{
        int i,j,count;
        object *enemy, who;
        who = this_object();
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        if (who->query("qi")<6000) {
                count=0;
                for (j=0;j<sizeof(enemy);j++) {
                        if (enemy[j]->is_zombie()) count++;
                }
                if (count>=3)
                        command("perform zombie-wp1");
        }
        if (!random(3)&& who->query("qi")>8000) who->perform_action("blade.jingsheng");
        return;
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
	
        if(!who->query("marks/��ɽ����") || who->query("class")!="legend") return 0; 
        if( ob->query("name")!="��ѩ�ż�" ) return 0;
                message_vision(CYN"$N΢΢Ц�������ղ�������ʦ������ô��\n"NOR,this_object());
                message_vision(CYN"$N˵:һ·�������ˣ��ں���ЪϢ����ɣ������и�ͽ�ܣ��п����ǿ����д�һ�¡�\n"NOR,this_object());
                tell_object(who,HIW"�����а�ϲ���û��ᣡ���Գ˻�ѧ�����ˣ���\n"NOR);
                who->set("marks/��ɽѧ��",1);
                who->delete("marks/��ɽ����",1);
        return 1;
} 


int recognize_apprentice(object ob)
{
	if( ob->query_temp("learn_timeb") <= 0) return 0;
else         
ob->add_temp("learn_timeb",-1);
return 1;
}