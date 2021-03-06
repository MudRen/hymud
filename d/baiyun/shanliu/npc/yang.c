 // yangfan.c
//inherit F_LEADER;
inherit NPC; 
inherit F_MASTER; 
#include <ansi.h>
void create()
{
        set_name("杨凡", ({ "yang fan", "yang"}) );
        set("gender", "男性" );
        set("age", 28);
        set("title","山流 少主");
        set("nickname",HIY"大头"NOR);
        set("class","shaolin");
        set("reward_npc", 1);
        set("difficulty", 15);
        set("long",
"这是个矮矮胖胖的年轻人，圆圆的脸，一双眼睛却又细又长，嘴很大，头更大，看起来
有点象猪八戒。但他的神情却很从容镇定，甚至可以说很有点潇洒的样子。\n");
        set("chat_chance", 1);
        set("chat_msg", ({
            "杨凡眨了眨眼，乐呵呵哼着小调：大头大头，下雨不愁，别人有伞，我有大头。\n",
    }) );
        set("inquiry",  ([
                "山流" : "山流只是一群很平凡的人，但却是为了一个不平凡的理想而存在。\n",
                "shanliu" : "山流只是一群很平凡的人，但却是为了一个不平凡的理想而存在。\n",
                "血雨檄": "血雨檄中人皆称霸一方的黑道巨枭，不可小视。\n",
                "questnpc": "血雨檄中人皆称霸一方的黑道巨枭，不可小视。\n",
                ])                      ); 
        set("combat_exp", 80000000);
        set("attitude", "friendly");
        set("per",1);
        set("str", 100);
        set("force",50000);
        set("max_neili",50000);
        set("force_factor",150);
        set("org_ranks",({
"义士","义侠","光明使者","平凡的人" })); 
	set_skill("literate", 100);
	set_skill("strike", 200);
	set_skill("hand", 200);
	set_skill("sword", 200);
	set_skill("force", 200);
	set_skill("parry", 200);
	set_skill("dodge", 200);

	set_skill("construction", 380);
	set_skill("painting", 380);


	        set_skill("songshan-sword", 380);
        set_skill("songshan-jian", 380);
        set_skill("songshan-qigong", 380);
        set_skill("dodge", 290);
        set_skill("zhongyuefeng", 380);
        set_skill("strike", 290);
        //set_skill("songyang-zhang", 380);
        set_skill("hanbing-zhenqi", 380);
        set_skill("parry", 290);
        set_skill("sword", 290);
        set_skill("songshan-jian", 380);
        //set_skill("songyang-zhang", 380);
        //set_skill("songyang-shou", 380);
        set_skill("literate", 250);
        set_skill("hanbing-shenzhang", 380);
		  set_temp("apply/armor", 200);
		  set_temp("apply/damage", 200);
	set_temp("apply/attack",200);
	set_temp("apply/defense",200);
	set_skill("songshan-sword", 380);
	set_skill("songyang-strike", 380);
	set_skill("poyun-hand", 380);
	set_skill("hanbing-zhenqi", 380);
	set_skill("fuguanglueying", 380);
	map_skill("strike", "songyang-strike");
	map_skill("hand", "poyun-hand");
	map_skill("sword", "songshan-sword");
	map_skill("parry", "songshan-sword");
	map_skill("dodge", "fuguanglueying");
	map_skill("force", "hanbing-zhenqi");
	prepare_skill("strike", "songyang-strike");
	prepare_skill("hand", "poyun-hand");

	set("no_get",1);
	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({
		(: command("haha") :),
//		(: command("unwield sword") :),
//		(: command("wield sword") :),
		(: perform_action, "sword.feiwu" :),
		(: perform_action, "sword.jianqi" :),
		(: perform_action, "sword.suiyuan" :),
		(: perform_action, "strike.yinyang" :),
		(: perform_action, "strike.junji" :),	
		(: perform_action, "hand.chanyun" :),
		(: exert_function, "recover" :),
		(: exert_function, "powerup" :),
	}) );

        setup();
        carry_object("/clone/misc/cloth")->wear();
        
}  
void init()
{
        object ob;
        ::init();
        if( userp(ob = this_player()))
        if(ob->query_temp("山流/舍身崖"))
        {
                remove_call_out("greeting");
                call_out("greeting", 30, ob);
        }
        add_action("do_kill","kill");
        add_action("do_answer","answer");
} 
void greeting(object me)
{
        if(!me ||environment(me)!=environment())
                return ;
        if(!living(me))
                me->revive();
        message_vision(CYN"$N眯着那双又长又细的眼睛，对$n笑了笑说：仁兄果然是同道中人。\n"NOR,this_object(),me);
        message_vision(CYN"$N突然神色肃然，郑重地对$n说：好，如果你愿入山流，自然欢迎加入『山流』！\n（join yang fan）。\n"NOR,this_object(),me);
        return ;
}  
void accept_member(object me)
{
        command("smile");
        command("enroll "+me->query("id"));
        message_vision(HIC"$N凝神片刻又肃然道：近日青龙会与天宗勾结，妄图号令天下黑道，但凡黑道枭雄
无不收到其『青龙令』，阁下务请将『血雨檄』（questnpc）中各方枭雄的青龙令夺之交
与秦歌兄，事关江湖正道兴衰，阁下务须小心行事！\n"NOR,this_object(),me);
        me->delete("入山流");
        me->delete_temp("山流");
        me->set("organization/org_name","山流");
        me->set("organization/org_level",0);
        me->set("organization/属性","正");
        CHANNEL_D->do_sys_channel("info",sprintf("%s，某人秘密加入了正派组织%s。",NATURE_D->game_time(),me->query("organization/org_name")) );
        me->save();
} 
void attempt_join(object me)
{
        if(me->query_temp("山流/舍身崖"))
           accept_member(me);
        else
                message_vision("杨凡细眉一皱，嘟囔道；奇怪，你从哪里冒出来的。\n",this_object());
}  
int do_kill(string arg)
{
        object me; 
        me=this_player();
        if(!arg) return 0;
        if(this_object()==present(arg,environment()))
                me->set("山流/失败",time());
        return 0;
} 
void die()
{
        object me, owner;
        if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed")) {
                me = owner;
        } 
        if ( me->query_temp("天宗/准备杀杨凡") ) 
        	me->set("天宗/入天宗",1);
        ::die();
}  

