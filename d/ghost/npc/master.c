inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void smart_fight(); 
void create()
{
    set_name("�ϵ�����", ({ "master lao dao", "master"}) );
    set("gender", "����" );
    set("class","wudang");
    set("age", 45);
    set("int", 30);
    set("per", 30);
    set("str",50);
    set("apprentice_available", 50);
    set("reward_npc", 1);
    set("difficulty", 15);
    set("fly_target",1);
    create_family("����ɽׯ", 1, "ׯ��");
    set("rank_nogen",1);
    set("ranks",({ "����","���","С�ܼ�","�ܼ�","��ܼ�",
                        "�ܹ�","���ܹ�","������" }));
    
    set("long", "�������ۣ�ͷ�����ң�������������ʵĹ�ꡣ\n" );
    
    set("inquiry", ([
        "�����ķ�": 
        "�����ķ�������ʮ��չ��������ã���[����Ʊ�]������һ����\n",
        "����Ʊ�": 
        "�˾�������������ǿ��ֻ�ִ�У��������ú����书��������ʹ�á�\n",
        ]) ); 
         
    set("max_atman", 1000);
    set("atman", 1000);
    set("max_force", 1000);
    set("force", 1000);
    set("force_factor", 90);
    set("max_mana", 2000);
    set("mana", 2000);
    
    set("resistance/kee",30);
    set("resistance/sen",50);
    set("resistance/gin",30);
    
    set("combat_exp", 9999999);
    set("score", random(90000));
   set("max_neili", 3500);
        set("neili", 3500);
        set("force_factor", 30);
	set("max_qi",2999);
        set("max_jing",2999);
	set("eff_qi",2999);
	set("qi",2999);
	set("eff_jing",2999);
	set("jing",2999);
        set("chat_chance", 1);
        set("combat_exp", 39999999);
        set("score", 90000);
        set("skill_public", 1);
        set_skill("unarmed", 350);
        set_skill("sword", 350);
        set_skill("force", 200);
        set_skill("parry", 150);
        set_skill("literate", 100);
	set_skill("dodge", 100);

	set_skill("three-sword", 500);
	set_skill("taiji-quan", 500);

  	 map_skill("unarmed", "taiji-quan");
        map_skill("sword", "three-sword");
        map_skill("parry", "three-sword");


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
       set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "sword.nianzijue" :),
        }) );
	set_temp("apply/attack", 200);set_temp("apply/defense", 200);set_temp("apply/armor", 500);set_temp("apply/damage", 600);setup();


    setup();
    carry_object(__DIR__"obj/cloth3")->wear();
    carry_object(__DIR__"obj/hat")->wear();
    carry_object(__DIR__"obj/swordd")->wield();
} 
/*void reset()
{
    delete_temp("learned");
    set("apprentice_available", 20);
}
*/ 


/*int recruit_apprentice(object ob)
{
    if( ::recruit_apprentice(ob) )
        ob->set("class", "ghost")&& ob->set("wudang/zhen", 1));
    add("apprentice_availavble", -1);
}*/

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
	
    if((string)ob->name() != "���ǽ�") return 0;
    if(!who->query("marks/�����Ǳ���")) return 0;
    if(ob->query("real") && (object)ob->query_temp("marks/owner") == who &&
       who->query_temp("killed_master_shi"))
    {
        who->delete("marks/�����Ǳ���");
        command("spank " + who->query("id"));
        command("say ����Ҫ�书�ؼ�����������ѧ�䣿(accept book/teach?)");
        who->set_temp("marks/�õ����Ǳ���", 1);
        add_action("do_accept", "accept");
    }
    else
    {
        say("�ϵ����ӽӹ����ǽ�����ϸ�ؿ��˿���\n");
        command("sigh");
        command("say ��һ�����Ǽٵģ�");
    }
    return 1;
} 
int do_accept(string arg)
{
    object me, book;
    
    if(!arg || (arg != "book" && arg != "teach")) 
        return notify_fail("����Ҫʲô��\n");
    me = this_player();
    if(!me->query_temp("marks/�õ����Ǳ���")) return 0;
    me->set_temp("marks/�õ����Ǳ���", 0);
    if(arg == "book")
    {
        book = new(__DIR__"obj/book");
        book->move(this_object());
        command("give book to " + me->query("id"));
        command("say �㹦�Ͳ�С�������㻹��������ѧ�䡣");
    }
    else 
        command("say �ӽ��쿪ʼ�������ͬ��ѧ���ˡ�");
    me->set("marks/�ϵ�����", 1);
    return 1;
}  
smart_fight()
{
   int i;
        object *enemy, who;
        who = this_object();
        enemy = this_object()->query_enemy();
        for(i=0; i<sizeof(enemy); i++) {
        if (!enemy[i]->is_zombie() && enemy[i]->query("id")!="guard") 
                who->perform_action("sword.nianzijue"); 
        }
        return;
}      




int recognize_apprentice(object ob)
{
	if( ob->query_temp("learn_timeb") <= 0) return 0;
else         
ob->add_temp("learn_timeb",-1);
return 1;
}
