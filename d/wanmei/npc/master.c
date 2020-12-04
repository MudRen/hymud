 inherit NPC;
#include <ansi.h>
inherit F_MASTER;
void smart_fight(); 
int your_score = 0;
void create()
{
        set_name("���Ŵ�ѩ", ({ "master ximen", "ximen", "master" }) );
        set("title", "��÷ׯ��");
        set("gender", "����");
        set("nickname", RED "����" NOR );
        set("age", 34);
        set("reward_npc", 1);
        set("difficulty", 30);
    
        set("long",
                "���Ŵ�ѩ���ǵ�����������֮һ�������Ѿ������ˣ��޽����ľ��磮��\n"
                ); 
    
        set("resistance/kee",50);
        set("attitude", "peaceful");
        set("combat_exp", 20000000);
        set("agi",25);
        set("int",40);
        set("str", 100);
        set("int", 30);
        set("cor", 300);
        set("cps", 30);
        set("con", 30); 
        set("force", 2500);
        set("max_neili", 2500);
        set("force_factor", 30); 
        

        
        set("chat_chance", 1);
        set("chat_msg", ({
           "���Ŵ�ѩŭ�����½С�������ӵ�����ɽׯ����ҲҪɱ���㣡��\n",
            }) ); 
        set("inquiry", ([
                "��ʦ": "�������и���أ����������Ϊʦ�ģ��ý������в�����
��������(accept test)��\n",
                "apprentice": "�������и���أ����������Ϊʦ�ģ��ý������в�����
��������(accept test)��\n" 
        ]) ); 
        create_family("��÷ɽׯ", 1, "ׯ��");
        set("ranks",({ "����","���","С�ܼ�","�ܼ�","��ܼ�", "�ܹ�","���ܹ�","��ׯ��" }));
        set("rank_nogen",1); 
     set("pubmaster",1);
        set("max_neili", 95000);
        set("neili", 95000);
        set("force_factor", 30);
	set("max_qi",99999);
        set("max_jing",99999);
	set("eff_qi",99999);
	set("qi",99999);
	set("eff_jing",99999);
	set("jing",99999);

                set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.hunranyijian" :),
                (: perform_action, "dodge.feitiantui" :),

		"���Ŵ�ѩ��Ц������˷������ɱ�ң�\n"
        }) );


        set_skill("force", 100);
        set_skill("unarmed", 100);
        set_skill("sword", 350);
        set_skill("parry", 100);
        set_skill("dodge", 80);
        set_skill("throwing", 50);
	
        set_skill("doomforce", 500);
        set_skill("doomstrike", 500);
        set_skill("doomsteps", 590);
	set_skill("doomsword",520);

        map_skill("force", "doomforce");
        map_skill("unarmed", "doomstrike");
        map_skill("sword", "doomsword");
        map_skill("dodge", "doomsteps");


       


        set_temp("apply/defense", 200);
        set_temp("apply/armor", 2500);
        set_temp("apply/damage", 2200);
        set_temp("apply/attack", 200);
        setup(); 
        carry_object(__DIR__"obj/xuejian")->wield();
        carry_object(__DIR__"obj/cloth")->wear();
} 
void init()
{
        ::init();
        add_action("do_accept", "accept");
        if (this_player()->query_skill("lingxi-zhi",1)){
                message_vision(HIY"\n$N�ȵ�:��!½С�������,��һ��ɱһ��!!\n"NOR,this_object());
                this_object()->kill_ob(this_player());
        }
} 
int do_accept(string arg)
{
        mapping guild;
        int extra;      
        int mgin,mkee,msen;
    
        if( arg== "test" )    {
                if(this_player()->query("family/master_id") == this_object()->query("id")){
                        say("\n���Ŵ�ѩ�������ͷ�������Ѿ�֤������һ������֮���ˣ�\n");
                        return 1;
                }
                if (this_object()->is_fighting()||this_object()->query_busy()) {
                        command("say ��������ʰ��������ְ��ŵļһ");
                        return 1;
                }
                mgin=(int)query("max_jing");
                mkee=(int)query("max_qi");
                msen=(int)query("max_jing");
                set("eff_qi",mkee);
                set("eff_jing",mgin);
                set("eff_jing",msen);
                set("jing",mgin);
                set("qi",mkee);
                set("jing",msen);
                extra=100;
                
                say("\n���Ŵ�ѩ���˵�ͷ��˵�����ܺã����ǵ�һ��....\n\n");
                this_object()->add_temp("apply/attack", extra*5);       
                this_object()->add_temp("apply/damage",extra*2);
                COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon"));
                this_object()->add_temp("apply/attack", -extra*5);      
                this_object()->add_temp("apply/damage",-extra*2);                    
                if( (int)this_player()->query("qi") < 0 || !present(this_player(), environment())) {
                        say("���Ŵ�ѩ̾�˿�����˵��������һ�ж��Ų����������Բ�����....\n");
                        return 1;
                }
                
                say("\n���Ŵ�ѩ˵�������ǵڶ���....\n\n");
                this_object()->add_temp("apply/attack", extra*5);       
                this_object()->add_temp("apply/damage",extra*4);
           COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon"));
                this_object()->add_temp("apply/attack", -extra*5);      
                this_object()->add_temp("apply/damage",-extra*4);                      
                if( (int)this_player()->query("qi") < 0  || !present(this_player(), environment())) {
                        say("���Ŵ�ѩ���ߡ���һ����˵��������������಻�����ļһ�....\n");
                        return 1;
                }
                
                say("\n���Ŵ�ѩ˵��������������....\n\n");
                this_object()->add_temp("apply/attack", extra*5);       
                this_object()->add_temp("apply/damage",extra*4);
                COMBAT_D->do_attack(this_object(), this_player(), query_temp("weapon"));
                this_object()->add_temp("apply/attack", -extra*5);      
                this_object()->add_temp("apply/damage",-extra*4);                      
                if( (int)this_player()->query("qi") < 0 || !present(this_player(), environment())) {
                        say("���Ŵ�ѩ̾������ϧ���ѵ���һ���书���޴���....\n");
                        return 1;
                }
        
                if (this_player()->query_skill("lingxi-zhi",1)){
                        say("\n���Ŵ�ѩ������Ц��˵����½С���ͽ�ܣ���Ȼ����Щ�ֶΣ������ҿɲ�������Ϊͽ��\n\n");
                        command("grin");
                        return 1;
                }
                                
                say("\n���Ŵ�ѩ������Ц��˵������������ٵ�һ������֮�ţ�\n\n");
                your_score = this_player()->query("score");
                command("recruit " + this_player()->query("id") );
                return 1;
    }
    return 0;
} 

void killed_enemy(object who)
{
        command("say ����֮ͽ��������ϧ��\n");
} 
void die()
{
        object killer;
        if(objectp(killer = query_temp("last_damage_from"))){
                if (killer->query("marks/won_lu")) killer->set("marks/kill_ximen", 1);
        }
        ::die();
} 
smart_fight()
{
        int i;
        object *enemy, who;
        who = this_object();
        enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        if (i>2 && enemy[1]->is_zombie()&& random(3)>0) {
                who->perform_action("sword.zombie-wp1");
                return;
        }
        who->perform_action("sword.hunranyijian"); 
        return;
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
