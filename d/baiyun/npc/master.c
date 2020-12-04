 // master.c
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("Ҷ�³�", ({ "master ye", "master" }) );
        set("nickname", HIC"һ������"NOR+HIR" �������"NOR);
        set("gender", "����" );
        set("age", 44);
        set("str", 100);
        set("cor", 30);
        set("cps", 30);
        set("int", 30);
       set("per", 20);
        set("agi",25);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.tianwaifeixian" :),
                (: perform_action, "sword.feixian" :),
        }) );
        set("pubmaster",1);
        set("attitude","friendly");
        set("neili", 35000);
        set("max_neili", 35000);
        //set("force", 15000);
        //set("force_factor", 100);
        set("max_qi",99999);
        set("max_jing",99999);
        set("max_jing",99999);
        set("eff_qi",9999);
        set("qi",99999);
        set("chat_chance", 1);
        set("chat_msg", ({
                "Ҷ�³Ǵӵ��Ѫ�ߵİ���˺��һ��������\nҶ�³��ôӵ��Ѫ�ߵİ���˺�µĲ������Լ����ˡ�\n",
        }) ); 
        set("long",
"
һ������΢�룬������ѩ�׳��۵��ˡ��������ܰף��Ȳ��ǲ԰ף�Ҳ���ǲҰף�
����һ�ְ���㾧Ө�������ɫ�������۾���������ڵģ���ȴ���ÿ��£���
�������ź��ǡ�����ڵ�ͷ���ϣ�������̴��ľ������ڣ����ϵ��·�Ҳ���
��ѩ���·������ϵ�����һ�㡣
\n"
        );
        create_family("���Ƴ�",1, "����");
        set("rank_nogen",1);
        set("ranks",({"��ͯ","С��ʿ","��ʿ","С����","����",
                      "С����","����","��ʦ",CYN"��ʦ"NOR,
                      CYN"����"NOR,CYN"����"NOR,HIC"��ʥ"NOR}));
        set("rank_levels",({ 32000,64000,128000,256000,512000,
                             1024000,1536000,2304000,3456000,
                             5187000,26244000 }));
        set("combat_exp", 8000000);
        set("score", 200000);
        set("reward_npc", 1);
        set("difficulty", 10);
        
        set_skill("parry", 120);
        set_skill("dodge", 120);
        set_skill("force", 100);
        set_skill("literate", 100);
	set_skill("sword", 100);
	set_skill("unarmed",80);
	set_skill("changquan",500);
	set_skill("feixian-steps",500);
	set_skill("feixian-sword",550);
	set_skill("jingyiforce",500);
        map_skill("dodge", "feixian-steps");
	map_skill("sword", "feixian-sword");
	map_skill("force", "jingyiforce");
	map_skill("parry", "feixian-sword");
	map_skill("unarmed", "changquan");
        setup();
        carry_object(__DIR__"obj/whitecloth")->wear();
        carry_object(__DIR__"obj/bsword")->wield();
   carry_object(__DIR__"obj/bcloth")->wear(); 
} 

void init()
{       
        ::init();
        add_action("do_killing", "kill");
    
} 
int do_killing(string arg)
{
    object player, victim;
    string id,id_class;
    player = this_player();
    if(!arg || arg == "") return 0;
    victim = present(arg, environment(player));
    if(!objectp(victim))
                return notify_fail("����û������ˡ�\n");
    if(living(victim))
    {
        id_class=victim->query("class");
        id=victim->query("id");
        if(id_class == "baiyun"&& userp(victim)&& player!=victim)
        {
            message_vision(HIW
"$N�����������¥�������������\n"NOR, this_object());
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            if (!player->is_busy()) player->start_busy(2);
            return 0;
        } 
    }
    return 0;
}  
int leave() {
        if (this_player()->query("class")!="assassin") return 0;
        message_vision(WHT"$N����һ������������Ƶ����������Ĳ����������������ģ����ǳ����߰ɣ�\n"NOR, this_object());
        message_vision(CYN"$N��Ȼ�������Ƶ��������黭������ͽ֮����������\n"NOR,this_object());
        return 1;
}        
int accept_object(object who, object ob)
{
	int i;

	if (!(int)who->query_temp("learn_timeb"))      
		who->set_temp("learn_timeb", 0);

	if( !ob->query("money_id") )
		return 0;		


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

int recognize_apprentice(object ob)
{
	if( ob->query_temp("learn_timeb") <= 0) return 0;
else         
ob->add_temp("learn_timeb",-1);
return 1;
}
