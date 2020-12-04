 inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int leave(); 
void create()
{
    set_name("雪蕊儿", ({ "master xuerui", "master","xuerui" }) );
    set("class","legend");      
    set("gender", "女性" );
    set("nickname", HIG "多情剑客"NOR);
    set("reward_npc", 1);
    set("difficulty", 35);
    set("age", 26);
    set("int", 30);
    set("per", 30);
    set("cor",40);
    set("str",100);
   set("ill_boss",5);
    
    set("apprentice_available", 50);
    create_family("铁雪山庄", 1, "庄主夫人");
    set("rank_nogen",1);
    set("ranks",({"棋童","小侠","少侠","大侠","奇侠",WHT"狂侠"NOR,WHT"侠圣"NOR,HIW"隐侠"NOR}));
    set("long",
        "雪蕊儿从十五岁开始就和爱夫铁少行侠江湖，俩人刀剑合壁，\n"
        "天下无敌。正当俩人名声顶盛之时，又忽然退出江湖，隐居于此。\n");
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
        command("say 还是让小翠来吧。");
        return 0;
    }
    else
        command("sigh");
    command("雪蕊儿慢慢的从翠竹凳上站起来，放下了手中的紫砂杯。");
    command("wield wangsword");
    command("say 请！");
    remove_call_out("do_unwie");
    call_out("do_unwie", 3);
    return 1;
} 
int do_unwie()
{
    if( !this_object()->is_fighting()) 
    {   
//      command("unwield wangsword");
        message_vision("$N拿起茶杯浅啖一口，含情脉脉的望了铁少一眼，又坐在竹凳上。\n", this_object());
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
        if( name == "铁少")
        {
            message_vision("$N皱皱眉头。\n", this_object());
            weapon = present("wangsword", this_object());
            if(weapon)
            {
                message_vision("$N从赤皮剑鞘中抽出一把只有两指宽的虞姬剑握在手中。\n", this_object());
                weapon->wield();
            }
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            remove_call_out("do_unwie");
            call_out("do_unwie", 3);
            return 0;
        }
        if( name == "雪蕊儿")
        {
            message_vision("$N皱皱眉头。\n", this_object());
            weapon = present("wangsword", this_object());
            if(weapon)
            {
                message_vision("$N从赤皮剑鞘中抽出一把只有两指宽的虞姬剑握在手中。\n", this_object());
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
            message_vision("$N皱皱眉头。\n", this_object());
            weapon = present("wangsword", this_object());
            if(weapon)
            {
                message_vision("$N从赤皮剑鞘中抽出一把只有两指宽的虞姬剑握在手中。\n", this_object());
                weapon->wield();
            }
            remove_call_out("do_unwie");
            call_out("do_unwie", 3);
            message_vision("$N对著$n喝道：" + RANK_D->query_rude(player) 
                                                + "竟敢杀" + RANK_D->query_self_rude(this_object()) 
                                                + "的徒弟，去死吧。\n", this_object(), player);
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
        message_vision(CYN"$N道：人各有志，我不勉强你留下。\n"NOR, this_object(),this_player());
        message_vision(CYN"$N说：只是聚气心法非弟子不能使用，蝶恋花剑法的精髓你大概也体会不到了。\n"NOR,this_object(),this_player());
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
command("say 既然你诚心想学我的武功，我就成全成全你吧。");
	return 1;
}

int recognize_apprentice(object ob)
{
	if( ob->query_temp("learn_timeb") <= 0) return 0;
else         
ob->add_temp("learn_timeb",-1);
return 1;
}
