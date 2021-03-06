#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("何太冲", ({ "he taichong", "he", "taichong" }));
        set("long", "一个五十多岁的中年男子，眉头紧锁，原来\n"
                    "这就是昆仑派的掌门，人称“铁琴先生”的\n"
                    "何太冲，至六大门派围攻光明顶之后，被赵\n"
                    "用计擒拿，关押在这里。\n");
        set("title", "昆仑派第三代掌门");
        set("nickname", WHT "铁琴先生" NOR);
        set("gender", "男性");
        set("age", 58);
        set("attitude", "peaceful");
        set("shen_type", -1);

        set("per", 30);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        
        set("max_qi", 8500);
        set("max_jing", 8200);
        set("neili", 8000);
        set("max_neili", 8000);
        set("jiali", 100);
        set("combat_exp", 1400000);


	set("jiali", 50);

	set("score", 40000);

	set_skill("taiji-shengong", 180);
	set_skill("art", 280);
	set_skill("literate", 200);
	set_skill("force", 200);
	set_skill("xuantian-wuji", 220);
	set_skill("dodge", 240);
	set_skill("taxue-wuhen", 220);
	set_skill("strike", 320);
	set_skill("kunlun-zhang", 220);
	set_skill("parry", 265);
	set_skill("sword", 275);
	set_skill("liangyi-jian", 225);
	set_skill("xunlei-jian", 225);
	set_skill("mantian-huayu", 225);
	set_skill("throwing", 160);
	set_skill("cuff", 155);
	set_skill("zhentian-quan", 220);
set_skill("qixian-jian", 280);
	set_skill("goplaying", 280);
	set_skill("luteplaying", 280);

        set_skill("finger", 180);
	set_skill("hand", 180);	
	map_skill("throwing", "mantian-huayu");
	map_skill("force", "xuantian-wuji");
	map_skill("dodge", "taxue-wuhen");
	map_skill("cuff", "zhentian-quan");
	map_skill("parry", "liangyi-jian");
	map_skill("sword", "liangyi-jian");

	prepare_skill("leg", "chuanyun-tui");
	prepare_skill("strike", "kunlun-zhang");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                                (: perform_action, "sword.hebi ban" :),
            		(: command("perform sword.hebi ban") :),
                                (: perform_action, "sword.hebi ban" :),
            		(: command("perform sword.hebi ban") :),            			
                (: perform_action, "strike.diezhang" :),
                	(: perform_action, "throwing.huayu" :),
                 	(: perform_action, "strike.liuyun" :),
(: perform_action, "strike.yixing" :),  
                (: command("unwield qin") :),
                (: command("wield qin") :),
                (: perform_action, "sword.jianqin" :),
                (: perform_action, "sword.ren" :),
                (: perform_action, "sword.feixue" :),
                (: perform_action, "sword.juedi" :),
                (: perform_action, "parry.tianwaifeiyin" :),
        }) );

        create_family("昆仑派", 3, "掌门");

        setup();
        carry_object("/clone/cloth/cloth")->wear();
        carry_object("/clone/weapon/zhujian")->wield(); 
}

void init()
{
        add_action("begin","bi");
}

int accept_fight(object who)
{
        command("say 哼，如我何太冲内力尚在，也由不得你猖狂。");
        return 0;
}

int accept_hit(object who)
{
        command("say 哼，如我何太冲内力尚在，也由不得你猖狂。");
        return 0;
}

int accept_kill(object who)
{
        command("heng");
        command("say 我何太冲被你们用诡计擒住，早就没想过要继续存活，要杀就动手吧。");
        return notify_fail("刹那间你只觉下不了手。\n");
}

int accept_ansuan(object who)
{
        return notify_fail("你刚想暗算，可是只见楼上人影晃动，根本看不清楚。\n");
}

int begin()
{
        object weapon;
        object me=this_player();
        object obj=this_object();

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
        {
                command("say 我内力全失，现在只能和你比剑！");
                return notify_fail("看起来何太冲并不想跟你较量。\n");
        }

        command("heng");
        command("say 进招吧！");
        message_vision(HIY "$N话音未落，单手一抖，手中竹剑对准$n" HIY
                           "当胸斜斜刺出！正是昆仑嫡传的两仪剑法。\n" NOR,
                           obj, this_player());

        me->set_temp("bi",1);
        set("anti",me);
        obj->kill_ob(this_player());
        this_player()->kill_ob(obj);
        return 1;
}

void die()
{
        if (objectp(query("anti")))
        {
                message_vision(CYN "\n赵敏皱了皱眉头，低声骂道：“废物！”\n" NOR,
                                   this_object());

                query("anti")->set_temp("win_he",1);
                query("anti")->delete_temp("bi");
        }
::die();
}

