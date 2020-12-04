 inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int leave(); 
void create()
{
    set_name("ѩ���", ({ "master xuerui", "master","xuerui" }) );
    set("class","legend");      
    set("gender", "Ů��" );
    set("nickname", HIG "���齣��"NOR);
    set("reward_npc", 1);
    set("difficulty", 35);
    set("age", 26);
    set("int", 30);
    set("per", 30);
    set("cor",40);
    set("str",100);
   set("ill_boss",5);
    
    set("apprentice_available", 50);
    create_family("��ѩɽׯ", 1, "ׯ������");
    set("rank_nogen",1);
    set("ranks",({"��ͯ","С��","����","����","����",WHT"����"NOR,WHT"��ʥ"NOR,HIW"����"NOR}));
    set("long",
        "ѩ�����ʮ���꿪ʼ�ͺͰ��������������������˵����ϱڣ�\n"
        "�����޵С���������������ʢ֮ʱ���ֺ�Ȼ�˳������������ڴˡ�\n");
    set("inquiry", ([
        "leave" : (: leave :),
                ]));    
    set("fly_target",1);
     set("max_neili", 93500);
        set("neili", 93500);
        set("force_factor", 30);
	set("max_qi",92999);
        set("max_jing",92999);
	set("eff_qi",92999);
	set("qi",92999);
	set("eff_jing",92999);
	set("jing",92999);

        set("combat_exp", 59999999);
        set("score", 90000);
        set_skill("unarmed", 100);
        set_skill("sword", 350);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("literate", 100);
	set_skill("dodge", 100);
        set_skill("throwing", 100);


	set_skill("meihua-shou", 500);
	set_skill("deisword", 550);
	set_skill("qidaoforce", 550);
	set_skill("fall-steps", 500);

	map_skill("unarmed", "meihua-shou");
        map_skill("sword", "deisword");
        map_skill("force", "qidaoforce");
        map_skill("parry", "deisword");
        map_skill("dodge", "fall-steps");


        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.luoyeqiufeng" :),
                (: perform_action, "sword.caideikuangwu" :),
        }) );
set("pubmaster",1);

    setup();
    carry_object(__DIR__"obj/yellowcloth")->wear();
    carry_object(__DIR__"obj/msword")->wield();
}

int accept_fight(object me)
{
    object xiaocui;
    if( objectp(xiaocui = present("cui", environment(this_object()))) && living(xiaocui))
    {
        command("smile");
        command("say ������С�����ɡ�");
        return 0;
    }
    else
        command("sigh");
    command("ѩ��������ĴӴ������վ���������������е���ɰ����");
    command("wield wangsword");
    command("say �룡");
    remove_call_out("do_unwie");
    call_out("do_unwie", 3);
    return 1;
} 
int do_unwie()
{
    if( !this_object()->is_fighting()) 
    {   
//      command("unwield wangsword");
        message_vision("$N����豭ǳ�һ�ڣ�������������������һ�ۣ�����������ϡ�\n", this_object());
        command("smile");
        return 1;
    }
    else
        call_out("do_unwie", 3);
}  
int do_killing(string arg)
{
    object player, victim, weapon;
    string name, id, id_class;
    if(!arg) return 0;
    player = this_player();
    if( objectp(victim = present(arg, environment(this_object()))) && living(victim))
    {
        name = victim->name();
        if( name == "����")
        {
            message_vision("$N����üͷ��\n", this_object());
            weapon = present("wangsword", this_object());
            if(weapon)
            {
                message_vision("$N�ӳ�Ƥ�����г��һ��ֻ����ָ����ݼ����������С�\n", this_object());
                weapon->wield();
            }
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            remove_call_out("do_unwie");
            call_out("do_unwie", 3);
            return 0;
        }
        if( name == "ѩ���")
        {
            message_vision("$N����üͷ��\n", this_object());
            weapon = present("wangsword", this_object());
            if(weapon)
            {
                message_vision("$N�ӳ�Ƥ�����г��һ��ֻ����ָ����ݼ����������С�\n", this_object());
                weapon->wield();
            }
            remove_call_out("do_unwie");
            call_out("do_unwie", 3);
            return 0;
        }
        id_class=victim->query("class");
        id=victim->query("id");
        if(id_class == "legend"&& userp(victim)&&player!=victim)
        {
            message_vision("$N����üͷ��\n", this_object());
            weapon = present("wangsword", this_object());
            if(weapon)
            {
                message_vision("$N�ӳ�Ƥ�����г��һ��ֻ����ָ����ݼ����������С�\n", this_object());
                weapon->wield();
            }
            remove_call_out("do_unwie");
            call_out("do_unwie", 3);
            message_vision("$N����$n�ȵ���" + RANK_D->query_rude(player) 
                                                + "����ɱ" + RANK_D->query_self_rude(this_object()) 
                                                + "��ͽ�ܣ�ȥ���ɡ�\n", this_object(), player);
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            if (!player->is_busy()) player->start_busy(2);
            return 0;
        } 
        
        return 0;
    }
    return 0;
} 
void init()
{       
        ::init();
        add_action("do_killing", "kill"); 
} 
int leave() {
        if (this_player()->query("class")!="legend") return 0;
        message_vision(CYN"$N�����˸���־���Ҳ���ǿ�����¡�\n"NOR, this_object(),this_player());
        message_vision(CYN"$N˵��ֻ�Ǿ����ķ��ǵ��Ӳ���ʹ�ã������������ľ�������Ҳ��᲻���ˡ�\n"NOR,this_object(),this_player());
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
