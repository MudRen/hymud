#include <ansi.h>
#include <combat.h>
inherit NPC;
inherit F_MASTER;
int direct();
void consider(); 
void create()
{
    set_name("楚留香", ({"master chu", "chu","master" }));
    set("nickname", HIY "妙绝天下"NOR );
    set("gender", "男性");
    set("age", 32);
    set("long",
        "
他双眉被面长，充满粗犷的男性魅力，但那双清澈的眼晴，却又是那麽秀逸。他鼻子
挺直，象征坚强、决断的铁石心肠，他那薄薄的，嘴角上翘的嘴，看来也有些冷酷，但
只要他一笑起来，坚强就变作温柔，冷酷也变作同情，就像是温暖的春风吹过了大地。
");
    set("attitude","friendly");
    create_family("楚香帅", 1, "门主");
    set("student_title","传人");
    set("title","盗帅");
    set("reward_npc", 1);
    set("difficulty", 10);
    set("int", 40);
    set("pubmaster",1);
    set("con", 26);
    set("agi", 50);
    set("skill_public",1);
    set("per", 40);
    set("chat_chance_combat", 30);
    set("chat_msg_combat", ({
        (: perform_action, "unarmed.luori" :),
            }) );       
    
    set("chat_chance", 1);
    set("chat_msg", ({
"楚留香道：四年前见过枯梅大师一次，那次我是陪蓉儿她们去游华山时远远瞧过她一眼。 \n",
    }));
    set("inquiry", ([
        "蝙蝠岛"   :  (: direct :),
        "bat island" : (: direct :),
        "batisland" : (: direct :),
        "bian fu dao" : (: direct :),
        "bianfudao" : (: direct :),
        ]));  
    set("neili", 37000);
    set("max_neili", 37000);
    set("force_factor", 50); 
    set("combat_exp", 4000000);
    set("score", 50000); 
    set_skill("force", 120);
    set_skill("bibo-force", 100);
    set_skill("blade", 220);
    set_skill("wind-blade", 520);
    set_skill("unarmed", 150);
    set_skill("dodge", 150);
    set_skill("luoriquan", 220);
    set_skill("dodge", 320);
    set_skill("fengyu-piaoxiang", 320);
    set_skill("parry", 120);
    set_skill("literate",180);
    set_skill("stealing",320);
    
    map_skill("blade"  , "wind-blade");
    map_skill("force"  , "bibo-force");
    map_skill("unarmed", "luoriquan");
    map_skill("dodge"  , "fengyu-piaoxiang");
    map_skill("dodge"  , "fengyu-piaoxiang");
    set_skill("force", 150);
        set_skill("unarmed", 120);
        set_skill("parry", 150);
        set_skill("dodge", 320);
        set_skill("dodge", 320);
        set_skill("literate", 150);

        set_skill("bibo-force", 550);
        set_skill("luoriquan", 500);
        set_skill("fengyu-piaoxiang", 520);
        set_skill("stealing",500);

        map_skill("force", "bibo-force");
        map_skill("unarmed", "luoriquan");
        map_skill("dodge", "fengyu-piaoxiang");
        map_skill("dodge", "fengyu-piaoxiang");
    setup();
    carry_object(__DIR__"obj/cloth_whitesilk")->wear();
}  
void attempt_apprentice(object ob)
{
    if(!ob->query_temp("marks/murderhu"))
    {
        say("楚留香说道：为人师傅是不敢当的，这样好了，\n");
        say("我们来砌磋(qiecuo)一下，看看你三招内是否可以伤到我！\n");
    } else {
        say("楚留香喝道：你杀了我最好的朋友后还敢来见我！\n");
        kill_ob(ob);
        ob->kill_ob(this_object());
    }
}  
int direct()
{
    object me;
    object room;
    
    me = this_player();
    
    if (this_object()->is_fighting(me)) {
        tell_object(me,"楚流香说：蝙蝠岛？恐怕你是没法活着见到了！\n");
        return 1;
    }
    
    if (this_object()->is_fighting(me)) {
        tell_object(me,"楚流香说：蝙蝠岛？你还是先把这里的敌人打发了吧。\n");
        return 1;
    }
    
    message_vision("楚留香突然眼中放出异样的光芒，喃喃道：
蝙蝠岛，哦！我想起来了，胡铁花曾跟我提起他要去那办一件很要紧的事情，
阁下如果也感兴趣，可以去东海之滨等着。\n\n",this_object(),me);
    message_vision(
"$N听了心中一动，顿时起了极大的兴趣，赶紧往海滨赶去.....\n",me);
    room = load_object("/d/tieflag/bat/bfd1");
    me->move(room);
    return 1;
} 
void die()
{
    object killer;
    if(objectp(killer = query_temp("last_damage_from")))
        killer->set("marks/杀楚留香", 1);
    ::die();
} 
void init()
{
        ::init();       
    add_action("do_look", "look");
    add_action("do_qiecuo","qiecuo");
    add_action("do_killing", "kill");
} 
int do_look(string arg)
{
    object me;
    me = this_player();
    
    if( (string)me->query("gender") == "女性" && 
        ( arg == "master" || arg == "master chu" || arg == "chu"))
    {
        message_vision("$N一颗芳心砰砰的跳的飞快．．．．\n"NOR, me);
        me->unconcious();
        return 1;
    }
    else return 0;
} 
int do_killing(string arg)
{
    object player, victim;
    string id;
    int sen; 
    player = this_player();
    if(!arg || arg == "") return 0;
    victim = present(arg, environment(player));
    if(!objectp(victim))
                return notify_fail("这里没有这个人。\n");
    if(living(victim))
    {
        id= victim->query("id");
        if( id == "li hongxiu")
        {
            message_vision(
"$N道：在我心爱的船上杀我心爱的女人，这，这也太过份了吧！\n", this_object());
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            return 0;
        }
    }
    return 0;
} 
int heal_up()
{
    int mgin,mkee,msen;
    mgin=(int)query("max_jing");
    mkee=(int)query("max_qi");
    msen=(int)query("max_jing");
    set("eff_qi",mkee);
    set("eff_gin",mgin);
    set("eff_sen",msen);
    set("jing",mgin);
    set("qi",mkee);
    set("jing",msen);
    ::heal_up();
    return 1;
} 
int recognize_apprentice(object ob)
{
	if (ob->query_temp("learn_timeb"))
{
   	if( ob->query_temp("learn_timeb") <= 0) return 0;
else         
ob->add_temp("learn_timeb",-1);
return 1;
}
        if (ob->query("marks/master_chu_food")+ 1800 < time() && (int)ob->query("marks/master_chu")+ 600  < time()) 
        {
        if (ob->query("marks/master_chu_food")+ 1800 < time()) 
        {
        message_vision("楚留香摸摸鼻子，对$N苦笑道：楚某过会儿还得赶去蝙蝠岛，如果以后有缘的话
你我再互相切磋切磋吧。\n",ob);
        command("grin "+ob->query("id"));
        return 0;
        }  
        if( (int)ob->query("marks/master_chu")+ 1800  < time())
        {
        say("楚留香说道：你从我这学了不少了，我们来再砌磋(qiecuo)一下吧！\n");
        return 0;
        }
   }    
    return 1;
} 
int do_qiecuo(string arg)
{
    object me;
    int sen;
    me = this_player();
    if (this_object()->is_fighting() || this_object()->is_busy())
        return notify_fail("楚留香正在忙着呢，没空和你砌磋！\n"); 
    if((int)me->query("marks/failed_chu") + 86400 > time())
    {
        say("\楚留香说道：你不久前才输给我！过两天再比吧！\n");
        return 1;
    }
    delete_temp("last_damage_from");
    heal_up();
    sen = (int) me->query("jing")/10;
    me->set("jing", sen);
    COMBAT_D->do_attack(me,this_object(),me->query_temp("weapon"),
                        TYPE_REGULAR);
    if(query_temp("last_damage_from") == me)
    {
        say("\n楚留香说道：你的功夫真不错，从今以后我们就相互学习吧！\n");
        me->set("marks/master_chu",time());
        return 1;
    }
    say("\n楚留香笑嘻嘻道：一招．．．．\n");
    COMBAT_D->do_attack(me,this_object(),me->query_temp("weapon"),
                        TYPE_REGULAR);
    if(query_temp("last_damage_from") == me)
    {
        say("\n楚留香说道：你的功夫真不错，从今以后我们就相互学习吧！\n");
        me->set("marks/master_chu",time());
        return 1;
    }
    say("\n楚留香笑嘻嘻道：两招．．．．\n");
    COMBAT_D->do_attack(me,this_object(),me->query_temp("weapon"),
                        TYPE_REGULAR);
    if(query_temp("last_damage_from") == me)
    {
        say("\n楚留香说道：你的功夫真不错，从今以后我们就相互学习吧！\n");
        me->set("marks/master_chu",time());
        return 1;
    }
    say("\n楚留香笑嘻嘻道：三招已过，等你练好些再来吧！\n");
    me->set("marks/failed_chu",time());
    return 1;
} 
int accept_object(object me, object ob)
{
        object food,who;
        	int i;
who=me;
	if (!(int)who->query_temp("learn_timeb"))      
		who->set_temp("learn_timeb", 0);

	

if (ob->query("money_id") )
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
        if(ob->query("id")!="bamboo basket") return 0;
        food=present("food",ob);
        if(!food) return 0;
        if(food->query("name")!= RED"斜阳倚翠红袖招"NOR) return 0;
        if(!me->query_temp("song_food_carrier"))
        {
                message_vision("楚留香说道：“谢谢你的好意，但我只想吃甜儿托人带给我的‘斜阳倚翠红袖招’。”\n", me);
                return 0;
        }
        if (me->query("combat_exp")<2500000)    
        {message_vision("楚留香说道：“谢谢你的好意，本可切磋两手，可惜阁下根基尚不扎实，还不适合学我的武功。“\n",me);
        message_vision("楚留香说道：“无功不敢受禄，可惜了这道美味。“\n",me);
        return 0;
        }
        else {
        message_vision("楚留香一看，朗声笑道：甜儿那丫头。。好，好，阁下武学上有何疑问不妨 
与我切磋一二！\n\n",me);
        me->set("marks/master_chu_food",time());
        return 1;
        }
}
        


