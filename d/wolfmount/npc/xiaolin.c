#include <ansi.h>
inherit NPC;
void create()
{
        set_name("С��", ({ "xiao lin"}) );
        set("gender", "Ů��" );
        set("age", 18);
        set("long","һ�����ľ���Ů���ӣ�������Ҳ�ܺ��ߵ����ӡ�\n");
        set("nickname", MAG"�ճ�����"NOR);
        set("title", "ʥŮ");
        set("attitude", "friendly");
        set("no_arrest",1);
        set("str", 10);
        set("cor", 10);
        set("cps", 10);
        set("agi",10);
        set("int",50);
        set("per",30);
        set("con",10);
        set("dur",10);
        set("fle",10);
        set("tol",10);
set("max_qi", 33500);
        set("jing", 32000);
        set("max_jing", 32000);
        set("neili", 33500);
        set("max_neili", 33500);
        set("jingli", 32000);
        set("max_jingli", 31000);

        set("combat_exp", 3500000);
        set("score", 1000);
        set_skill("persuading", 280);
        set_skill("force", 100);
        set_skill("throwing", 100);
        set_skill("dodge", 100);
        set_skill("finger", 100);
        set_skill("parry", 100);
        set_skill("unarmed", 100);
        set_skill("strike", 100);
        set_skill("sword", 100);
        set_skill("claw", 100);
        set_skill("literate", 200);
        set_skill("mahayana", 250);
        set_skill("jinding-zhang", 300);
        set_skill("jiuyin-baiguzhao", 300);
        set_skill("tiangang-zhi", 200);
        set_skill("huifeng-jian", 290);
        set_skill("zhutian-bu", 100);
        set_skill("linji-zhuang", 320);
        set_skill("feiyu-bian", 300);
        set_skill("bagua-dao", 380);
        set_skill("bagua-zhang", 380);

        set_skill("huixin-strike", 380);
        set_skill("piaoxue-hand", 380);
        set_skill("yinlong-whip", 380);
        set_skill("yitian-jian", 380);
        set_skill("whip", 220);
        set_skill("hand", 220);
        
        map_skill("force","linji-zhuang");
        map_skill("claw","jiuyin-baiguzhao");
        map_skill("dodge","zhutian-bu");
        map_skill("strike","jinding-zhang");
        map_skill("sword","huifeng-jian");
        map_skill("parry","huifeng-jian");
        map_skill("whip","yinlong-whip");

	        map_skill("hand","piaoxue-hand");
        map_skill("strike","huixin-strike");
        map_skill("parry","yinlong-whip");
        map_skill("sword","yitian-jian");
        prepare_skill("strike", "huixin-strike");
        prepare_skill("hand", "piaoxue-hand");
        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
                (: perform_action, "whip.duoming" :),
                (: perform_action, "whip.zhu" :),
                (: perform_action, "strike.cuixin" :),
                (: perform_action, "strike.gu" :),
                (: perform_action, "hand.yun" :),
                (: perform_action, "hand.zhao" :),
                (: perform_action, "finger.lingkong" :),
                (: exert_function, "daxiao" :),
                (: exert_function, "fengyun" :),
                (: exert_function, "longhe" :),
                (: exert_function, "tiandi" :),                                
                (: exert_function, "juemie" :), 
        }) );
        setup();
 carry_object("/clone/weapon/changbian")->wield();
 carry_object(__DIR__"obj/skirt")->wear();
} 
void init()
{
        ::init();
   add_action("do_kill","kill");
        add_action("do_heal","heal");
} 
int do_kill(string arg)
{       object ob;
        if ((arg=="xiao lin") && ob=present("xiao ma",environment(this_object())))
        {
                ob->kill_ob(this_player());
                ob->ccommand("say ����֮Σ��������Ķ�������");
                this_object()->remove_all_killer();
                return 1;
        }
        
        else
        {
                return 0;
        }
} 
int accept_object(object me, object ob)
{
        object sunwaiter;
        if(sunwaiter = present("sun legate", environment(this_object())))
        {
                message_vision("$N�����Աߣ������ȸɵ����ɡ�\n",sunwaiter);
                return notify_fail("\n");
        }
        if(ob->query("name") == HIG"�����"NOR && me->query("marks/ɱ̫��ʹ��"))
        {
                if(me->query_temp("marks/wolf_xiaoma_good"))
                {
                        environment(me)->goodresult_notify(me,this_object(),0);
                }
                else if(me->query_temp("marks/wolf_xiaoma_normal"))
                {
                        environment(me)->normalresult_notify(me,this_object(),0);
                }
                return 1;
        }
        else
                return 0;      
} 
