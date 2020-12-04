// qiangdao.c 强盗
// lag.2000/3/17

inherit NPC;
#include <ansi.h>
#include "/quest/givegift.c"
void move();

void create()
{       object me;
        int myskill;
        me=this_player();
        myskill=me->query_skill("force");
        set_name(HIC "姑苏慕容叛徒首领" NOR, ({ me->query("id")+"-pantu"}));
        set("title",me->query("name")+"定下的");
        set("gender", "男性");
        set("age", 28);
        set("long", "他是一个姑苏慕容叛徒。\n");
        
        set("attitude", "peaceful");
        set("qi", me->query("qi"));
        set("max_qi", me->query("max_qi"));
        set("jing", me->query("jing"));
        set("neili", me->query("neili"));
        set("max_neili", me->query("max_neili"));
        set("max_jing", me->query("max_jing"));
        set("str", me->query("str"));
        set("dex", me->query("dex"));
        set("per", me->query("per"));
        set("killer",me->query("id"));
        set("combat_exp", me->query("combat_exp"));
// 加下面5句是让强盗自动走，增添玩家做机器人的困难！-糖圆SMILE
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({

                (: perform_action, "finger.dianxue" :),
                (: perform_action, "finger.dianxue" :),
                (: perform_action, "sword.kuangjian" :),
                (: perform_action, "sword.qixing" :),
                (: perform_action, "sword.lianhuan" :),
                (: perform_action, "dodge.yanling" :),                
                (: perform_action, "dodge.yanling" :),                
        }));
            /* set("chat_chance", 30);
             set("chat_msg", ({
              (: random_move :)
        }) );*/


        set_skill("hand", myskill * 3 / 4);
        set_skill("staff", myskill * 3 / 4);
        set_skill("dodge", myskill * 3 / 4);
        set_skill("finger", myskill * 3 / 4);
        set_skill("sword", myskill * 3 / 4);
        set_skill("unarmed", myskill* 3 / 4);
        set_skill("parry", myskill* 3 / 4);
        set_skill("force", myskill* 3 / 4);
        set_skill("blade", myskill* 3 / 4);
        set_skill("strike", myskill* 3 / 4);
        set_skill("xingyi-zhang", myskill* 3 / 4);
        set_skill("canhe-zhi", myskill* 3 / 4);
        set_skill("murong-jianfa", myskill* 3 / 4);
        set_skill("shenyuan-gong", myskill* 3 / 4);
        set_skill("yanling-shenfa", myskill* 3 / 4);
        //set_skill("douzhuan-xingyi", myskill* 3 / 4);
        map_skill("blade", "murong-daofa");
        map_skill("finger", "canhe-zhi");
	map_skill("force", "shenyuan-gong");
	map_skill("dodge", "yanling-shenfa");
        map_skill("parry", "murong-jianfa");
	map_skill("sword", "murong-jianfa");

	prepare_skill("finger","canhe-zhi");
        set_temp("apply/attack", 100);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 200);
        set_temp("apply/damage", 250);
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/gangjian")->wield();

}

void init()
{
        remove_call_out("leave");
        call_out("leave",120);
}

void leave()
{
        object ob = this_object();
        if (!ob->is_fighting()) {
                message_vision(HIC "姑苏慕容叛徒首领钻进路边的杂草，不见了。\n" NOR,this_object());
                destruct(this_object());
                }
        else call_out("leave",30);
}
void unconcious()
{
    die();
}

void die()
{
	   object n_money;
   int kar, exp, pot;
        object me = this_object()->query_temp("last_damage_from");
        object corpse,zhi;      

if (me)
{
	   kar = random(me->query("kar")) * 10;
if (kar >500) kar=500;
if (kar <150) kar=150;
   exp = 550 + kar;
   pot = 400 + random(kar);

        message_vision(HIR "\n姑苏慕容叛徒倒在地上，挣扎了几下就死了。\n" NOR,me);
        message_vision(HIG "\n"+me->query("name")+"从叛徒的身上找到了大燕传国玉玺。\n" NOR,me);
        if (me->query("kill_mr") == 1 && this_object()->query_temp("owner/id") == me->query("id")) {
exp=exp/2+88;
if( me->query("family/family_name") == "姑苏慕容")
addnl(me,"exp",exp);
                me->add("score",50);
                me->delete("quest");
                me->delete("kill_mr");
       if (me->query_temp("mrjob"))
       {
       message_vision(HIR "你通过这件事得知 段誉的事，应该去找阿碧！\n" NOR,me);
//command("say 段誉的事，去找阿碧吧！\n");	
me->set_temp("killtlbb6",1);
       	//me->set_temp("killtlbb6",1);
       }

                me->add("score",2);
                }

        corpse = new("/clone/misc/corpse");
        corpse->set("name",HIW "姑苏慕容叛徒的尸体" NOR);
        corpse->set("long","他是一个曾经无恶不做的姑苏慕容叛徒，\n然而，他已经死了，剩下一具丑陋的尸体。\n");
        corpse->move(environment(this_object()));
        corpse->set_max_encumbrance(1000);        
        me->add("MKS", 1);
}
        destruct(this_object());
}


