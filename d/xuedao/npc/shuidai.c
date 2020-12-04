// shuidai.c

inherit NPC;
#include <ansi.h>;
void create()
{
       set_name("ˮ�", ({ "shui dai", "shui" }));
       set("long", 
       "�����������桰�仨��ˮ���е����ġ�\n"
       "��������н��ϣ��������壬ˮ��主�׶��ϣ�����ȴ������ɫ��\n");
       set("gender", "����");
       set("nickname", HIC"���½�"NOR);
       set("age", 39);
       set("attitude", "peaceful");
       set("shen_type", 0);
       set("str", 35);
       set("int", 38);
       set("con", 35);
       set("dex", 35);

       set("neili", 55000);
        set("max_neili", 55000);
        set("jing", 28000);
        set("max_jing", 28000);
        set("qi", 28000);
        set("max_qi", 28000);
        set("jiali", 100);


        set("combat_exp", 8000000);
        set("shen_type", 1);
        set("score", 100000);

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.fengxue" :),
                (: perform_action, "sword.wanmei" :),
                (: perform_action, "sword.xuehua" :),
                (: perform_action, "sword.xuehua" :),
                (: perform_action, "unarmed.yanxue" :),
                (: perform_action, "unarmed.ying" :),
                (: perform_action, "unarmed.zhe" :),
                (: perform_action, "unarmed.lang" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :)
        }) );

        set_skill("unarmed", 250);
        set_skill("sword", 380);
        set_skill("force", 320);
        set_skill("parry", 250);
        set_skill("dodge", 250);
        set_skill("literate", 200);

        set_skill("xueshan-sword", 380);
        set_skill("bingxue-xinfa", 380);
        set_skill("snow-zhang", 380);
        set_skill("snowstep", 380);


         set_skill("doom-hand", 380);
        set_skill("hanshan-strike", 380);
        set_skill("snowwhip", 380);
        set_skill("hand", 280);
        set_skill("strike", 280);
        set_skill("whip", 280);
set_skill("mingyu-gong", 380);


        map_skill("sword", "xueshan-sword");
        map_skill("parry", "xueshan-sword");
        map_skill("force", "bingxue-xinfa");
        map_skill("unarmed", "snow-zhang");
        map_skill("dodge", "snowstep");
        map_skill("strike", "hanshan-strike");
        map_skill("hand", "doom-hand");
if (random(3)==0)
{
        map_skill("sword", "mingyu-gong");
        map_skill("parry", "mingyu-gong");
        map_skill("force", "mingyu-gong");
        map_skill("unarmed", "mingyu-gong");
        map_skill("dodge", "snowstep");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.gua" :),
                (: perform_action, "unarmed.moqi" :),
                (: perform_action, "unarmed.qiong" :),
                (: exert_function, "powerup" :),
                (: exert_function, "shield" :),
                (: exert_function, "zu" :)                	
        }) );	
	
}
else
{
	prepare_skill("strike", "hanshan-strike");
	prepare_skill("hand", "doom-hand");
	
}

        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);
       set("chat_chance", 20);
       set("chat_msg", ({
              "ˮ᷼���������Х����磺���仨��ˮ�������������ƾ�����ԶԶ������\n",
	}));

       setup();
       carry_object("/clone/weapon/changjian")->wield();
}

void unconcious()
{
    die();
}
void die()
{
        object ob, me, corpse;
        
        ob = this_object();
        me = query_temp("last_damage_from");
if (!me) return;
              //me->add("score",1);        
        message_vision(RED"$Nһ��ŭ�𣬻�����Ѫֱ����������ȥ!\n"NOR,ob,me);
        


        me->set_temp("killsx4",1);


              ::die();
        return;
}