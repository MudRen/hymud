// lutianshu.c

inherit NPC;
#include <ansi.h>;
void create()
{
       set_name("½����", ({ "Lu tianshu", "lu" }));
       set("long", 
       "�����������桰�仨��ˮ���е��ϴ�\n"
       "��������н��ϣ��������壬½�������������ƣ�����������\n");
       set("gender", "����");
       set("nickname", HIG"����½��"NOR);
       set("age", 51);
       set("attitude", "peaceful");
       set("shen_type", 0);
       set("str", 35);
       set("int", 38);
       set("con", 35);
       set("dex", 35);

         set("qi", 29000);
        set("max_qi", 29000);
        set("jing", 29000);
        set("max_jing", 29000);
        set("neili", 29500);
        set("max_neili", 29500);
        set("jiali", 160);
        set("level", 40);
        set("combat_exp", 8000000);

        set_skill("force", 380);
        set_skill("lengyue-shengong", 380);
        set_skill("blade", 460);
        set_skill("baisheng-daofa", 460);
        set_skill("hujia-daofa", 380);
        set_skill("zileidao", 380);
        set_skill("dodge", 380);
        set_skill("sixiang-bufa", 380);
        set_skill("parry", 380);
        set_skill("strike", 380);
        set_skill("tianchang-strike", 380);
        set_skill("cuff", 380);
        set_skill("hujia-quan", 380);
        set_skill("throwing", 400);
        set_skill("mantian-xing", 400);
        set_skill("literate", 380);
        set_skill("martial-cognize", 240);

        map_skill("force", "lengyue-shengong");
        map_skill("blade", "zileidao");
        map_skill("dodge", "sixiang-bufa");
        map_skill("parry", "baisheng-daofa");
        map_skill("strike", "tianchang-strike");
        map_skill("cuff", "hujia-quan");
        //map_skill("throwing", "mantian-xing");

        prepare_skill("strike", "tianchang-strike");
        prepare_skill("cuff",   "hujia-quan");

        //create_family("�������", 7, "����");



        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "blade.huanying" :),
                 (: perform_action, "blade.posui" :),
                (: perform_action, "blade.tulong" :),                 	
                (: perform_action, "cuff.kuai" :),
                (: perform_action, "strike.huang" :),
                (: perform_action, "dodge.fei" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }));
	set_temp("apply/attack",190);
	set_temp("apply/defense",190);
	set_temp("apply/armor",1800);
	set_temp("apply/damage",800);      
       set("chat_chance", 20);
       set("chat_msg", ({
              "½��������������������Х�����䡫������ˮ������Х���ۻ룬ԶԶȺɽ��Ӧ������\n",
	}));

       setup();
       carry_object("/clone/weapon/gangdao")->wield();
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
        


        me->set_temp("killsx1",1);


               ::die();
        return;
}