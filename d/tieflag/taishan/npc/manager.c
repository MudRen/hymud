//by xiaolang
inherit NPC;
#include <ansi.h> 
int test_dart();
void create_level(object who,string name, int exp); 
void create()
{
    set_name("霍休", ({ "huo xiu" }) );
    set("gender", "男性" );
    set("age", 32);
    set("neili",500);
    set("title","天宗");
    set("force_factor",20);
    set("max_neili",500);    
    set("inquiry",      ([
        "mission" : (: test_dart :),
        ]) );
    set("int", 30);
    set("long",
        "他一身穿着洗的发白的蓝布衣裳，赤脚穿着双破草鞋，正坐在地上用只\n破锡壶在红泥小火炉上温酒。\n"
        );
	set("neili", 22400);
	set("max_neili", 22400);
	set("max_qi", 22000);
	set("max_jing", 21200);
	set("combat_exp", 8000000);
	set("shen_type", 1);

	set_skill("strike", 150);
	set_skill("kuaihuo-strike", 310);
	set_skill("sword", 350);
	set_skill("taishan-sword", 320);
	set_skill("shiba-pan", 320);
	set_skill("force", 150);
	set_skill("panshi-shengong", 350);
	set_skill("parry", 150);
	set_skill("dodge", 150);
	set_skill("fengshenjue", 310);
	set_skill("dramaturgy", 380);
	set_skill("horticulture", 380);
	map_skill("sword", "taishan-sword");
	map_skill("parry", "taishan-sword");
	map_skill("dodge", "fengshenjue");
	map_skill("force", "panshi-shengong");
	map_skill("strike", "kuaihuo-strike");
	prepare_skill("strike", "kuaihuo-strike");
	set("no_get",1);
	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({
		(: perform_action, "sword.heru" :),
		(: perform_action, "sword.ruhe" :),
		(: perform_action, "sword.wuyue" :),
		(: perform_action, "sword.18pan" :),
		(: perform_action, "strike.zhouyu" :),
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );    
    set("combat_exp", 35000000);
    setup();
    carry_object(__DIR__"obj/hxcloth")->wear();
    carry_object(__DIR__"obj/hxshoes")->wear();
} 
void init()
{
        ::init();
//        add_action("do_accept", "accept");
} 
int test_dart()
{
    object me;
        
    me=this_player();
    if(me->query("organization/性质") != "邪")
    {
    	command("say 你不是我们组织的，我怎么相信你？\n");
    	return 1;
    }

    if(me->query("护送失败/timer")+180>time())
    {
    	command("say 你刚护送失败不久。\n");
    	return 1;
    }
    if(me->query("improbity")>= 100)
    {
    	command("say 你已经做的很不错了，干点别的事去吧。\n");
    	return 1;
    }
    	
    if (query("护送任务/gived") )
    {
        set("护送任务/gived",1);
        command("say 我们这里还没有你要的护送任务。");
        return 1;
    }
    command("say 现在有一个重要的人物要去目的地，你是否愿意？(accept mission)");
//    add_action("do_accept","accept");
    return 1;
} 
int do_accept(string arg)
{    
    object ob,cart,biaotou;
    object me,*team;
    string location,msg;
    int i, exp,n; 
    
    msg="";
    if (arg != "mission") return 0;
    me=this_player();
    team=me->query_team();
    if (sizeof(team)==0) team=({me}); 
   if (sizeof(team) != 0 && (team[0]!=me)) 
        return notify_fail("say 只有队伍首领才能提出护送任务。\n");
    for (i=0;i<sizeof(team);i++)
    {
    	if(team[i]->query("护送失败/timer")+180>time())
    		return notify_fail("你队伍当中有人刚护送失败不久。\n");
    	}
    	
    for (i=0;i<sizeof(team);i++)
    {
//    	team[i]->set_temp("护送任务/难度",1);
        if (team[i]->query("combat_exp")<15000000)
        {
            command("say 护送路途危险，我看这位"+RANK_D->query_respect(team[i])+"似乎不宜！");
            return 1;
        }
/*        if (!intp(team[i]->query("deposit")) || team[i]->query("deposit")<1000000)
        {
            command("say 护镖是危险的事，我看"+RANK_D->query_respect(team[i])+"没有赔偿能力。");
            return 1;
        }  */
        if(team[i]->query("organization/性质") != "邪"){
        	command("heng");
        	command("say 难道你队伍里的人要当间谍，监守自盗不成？\n");
        	return 1;        	
        }
        if(team[i]->query("improbity") >= 100){
        	command("smile");
        	command("say 你队伍中已经有人做的很不错了，不需要保护别人了，让他干点别的去吧。\n");
        	return 1;
        }
        
        if (team[i]->query("combat_exp")>exp)
                exp= team[i]->query("combat_exp");
    } 
    

        if (query("护送任务/gived"))
                {
                 command("say 你来晚了，已经有人接下这个任务了。");
                 return 1;
                }

    set("护送任务/gived",1);
    command("say 一路小心。");
    location = environment(me)->query("short");        
    biaotou=new("/obj/npc/importman");
    biaotou->move(environment());
    n=random(3);
    switch( n ) {
    	case 0:
    		biaotou->get_quest("/d/taishan/way/way1_ts_to_lyz");
    		msg = "前往老云寨";
    		break;
    	case 1:
    		biaotou->get_quest("/d/taishan/way/way2_ts_to_qp");
    		msg = "前往清平山庄";
    		break;
    	case 2:
    		biaotou->get_quest("/d/taishan/way/way3_ts_to_fy");
    		msg = "前往风云城金钱帮";
    		break;
    }
    for (i=0;i<sizeof(team);i++)
    {
    	team[i]->set_temp("护送任务/难度",n+1);
    }		
    biaotou->set_protector(team);
    biaotou->set("combat_exp",exp*3/5);
    create_level(biaotou,"importman",exp*3/5);
    
    CHANNEL_D->do_sys_channel(
                "info",sprintf("%s，%s保护一名重要人物从%s出发%s！", NATURE_D->game_time(),
                me->query("name"),location,msg) );     

    me->set_leader(biaotou);
    me->set_temp("护送任务/accepted",1);
    biaotou->go_now();
    return 1;   
} 
void reset()
{
    delete("护送任务/gived");
}  
void create_level(object who,string name, int exp)
{
        int level;
        level=100+130*(exp-1000000)/6500000;
        if (exp<1000000) level=100;
        if (exp>7500000) level=200;
        level=level*level/100;
        if (name=="importman") {
                
                who->command("say 我就是那个联络人员，路上多多照顾。");
                who->set("str",10+random(level/15));
                who->set("agi",10+random(level/8));
           	who->set("cor",20+random(15));
//                who->set("max_qi",1000+random(level*level/20));
//                who->set("eff_qi",who->query("max_qi"));
//                who->set("qi",who->query("max_qi"));
                who->set_skill("blade", 100 + random(level*2/3));
                who->set_skill("parry", 100 + random(level*2/3));
                who->set_skill("dodge", 100 + random(level*2/3));
                who->set_skill("demon-steps",100+random(level*2/3));
                who->set_skill("move", 100 + random(level*2/3));
                who->set_skill("moon-blade",100+random(level*2/3));
                who->set_skill("unarmed",100 + random(level*2/3));
        }
        if (name=="killer") {
                who->set("str",10+random(level/12));
                who->set("agi",10+random(level/8));
                who->set("cor",20+random(15));
                who->set("max_qi",2500+random(level*level/40));
                who->set("eff_qi",who->query("max_qi"));
                who->set("qi",who->query("max_qi"));
                who->set("max_sen",who->query("max_qi")/2);
                who->set("max_jing",who->query("max_qi")/2);
                who->set("eff_sen",who->query("max_sen"));
                who->set("sen",who->query("max_sen"));
                who->set("eff_jing",who->query("max_jing"));
                who->set("jing",who->query("max_jing"));
                who->set_skill("parry", 70 + random(level/2));
                who->set_skill("dodge", 70 + random(level/2));
                who->set_skill("move", 70 + random(level/2));
                who->set_skill("blade",70+random(level/2));
                who->set_skill("fall-steps",70+random(level/2));
                who->set_skill("unarmed",70+ random(level/2));
                who->set_skill("yue-strike",50+random(level/8));
                who->set_skill("shortsong-blade",50+random(level/8));
        } 
}   
