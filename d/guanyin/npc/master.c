 inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int kill_him();
void create()
{
    set_name("石观音", ({ "shi guanyin","guanyin" }) );
    set("nickname", HIG"芳华永驻"NOR );
    set("gender", "女性" );
    set("age", 25);
    set("int", 30);
    set("str",60);
    set("per", 30);
    set("agi",100);
    set("apprentice_available", 50);
    set("ranks",({"弟子","小魔","少魔","大魔","奇魔","长老","元老","副掌门"}));
    set("rank_nogen",1);
    set("fly_target",1);
    set("long",
        "石观音的美丽，竟已是今人不能想象的，因为她的美丽已全部占据了
人们的想象力。有很多人都常用“星眸”来形容女子的美丽，但星光又怎
及她这双眼睛的明亮与温柔。有很多人都常用“春山”来形容美女的眉，
但纵是雾里朦胧的春山也不及她秀眉的婉约。
"
        );
    set("force_factor", 400);
    set("chat_chance", 1);
    set("chat_msg", ({
        "石观音道：“你......你不觉我老？”\n",
            "石观音笑了笑，又道：“你可知道这里是什么地方？”\n",
            "石观音眼光突然朦胧，柔声道：“你既知道，为何还不过来？”\n",
               }) );
       set("max_neili", 95000);
        set("neili", 95000);
        set("force_factor", 30);
	set("max_qi",99999);
        set("max_jing",99999);
	set("eff_qi",99999);
	set("qi",99999);
	set("eff_jing",99999);
	set("jing",99999);
	set("agi",25);
        set("int",30);
        set("combat_exp", 99999999);
        set_skill("unarmed", 100);
        set_skill("blade", 350);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("literate", 100);
	set_skill("dodge", 100);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.taixubaihuan" :),
                (: perform_action, "unarmed.yaozhan" :),
        }) );
        set("pubmaster",1);
	set_skill("kongshoudao", 500);
	set_skill("bat-blade", 530);
	set_skill("ghosty-force", 500);
	set_skill("ghosty-steps", 500);

	map_skill("unarmed", "kongshoudao");
        map_skill("blade", "bat-blade");
        map_skill("force", "ghosty-force");
        map_skill("parry", "bat-blade");
        map_skill("dodge", "ghosty-steps");
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 600);
    set("combat_exp", 99999999);
    set("inquiry", ([
        "无花" : (: kill_him :),
        "李姑娘" : (: kill_him :),
        "李菊" : (: kill_him :),
        "天枫十四郎" : (: kill_him :),
        "南宫灵" : (: kill_him :), 
        ]));
    
    setup();
    carry_object(__DIR__"obj/whitecloth")->wear();
}
void reset()
{
        delete_temp("learned");
        set("apprentice_available", 20);
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "bandit");
        add("apprentice_availavble", -1);
}  
int kill_him()
{
        object me;
        me = this_player();
        command("say 看来你已经知道我的来历了！！ \n");
        this_object()->kill_ob(me);
        me->kill_ob(this_object());
        return 1;
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
command("say 既然你诚心想学我的武功，我就成全成全你吧。");
	return 1;
}
        if(ob->query("name")!="乌鞘长刀") return 0;
        if(!who->query("天枫_quest3"))
        {
                message_vision("石观音皱了皱眉：你这把刀是哪里来的。。。？\n",who);
                return 0;
        }
        message_vision("石观音抽出长刀，凝神伫立半晌，脸色变幻不停，似乎苍老了许多。。。\n",who);
        call_out("give_saki",5,who);
        return 1;
} 
int give_saki(object who)
{
        object saki;
                
        if(environment(who)!=environment()) return 0;
    message_vision(HIY"石观音突然嫣然一笑道：一夜夫妻百日恩，唉，就劳烦这位"+ RANK_D->query_respect(who) +"把这瓶清酒
送于他，就算奴家报答当日情了。\n"NOR,who);
        saki=new(__DIR__"obj/saki");
        saki->move(who);
        who->set("天枫_quest4","成功");
        
        return 1;
}     
int recognize_apprentice(object ob)
{
	if( ob->query_temp("learn_timeb") <= 0) return 0;
else         
ob->add_temp("learn_timeb",-1);
return 1;
}