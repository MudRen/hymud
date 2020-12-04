#include <ansi.h> 


inherit NPC; 
inherit F_MASTER; 

int ask_me();


void create() 
{ 
        object ob; 
        set_name("���ũ", ({ "tian guinong", "guinong" })); 
        set("gender", "����"); 
        set("nickname", YEL "���ϼ���" NOR); 
        set("title", "�����ű�������"); 
        set("age", 48); 
        set("long", @LONG 
���ũ�Ǹ���òӢ����̸�·��ŵ��������ӣ������е���������
����������Ů�˻�ϲ�ı��£���������˷������������ƭ���֡�
LONG ); 
        set("attitude", "friendly"); 
        set("shen_type", 1); 
        set("str", 32); 
        set("int", 31); 
        set("con", 33); 
        set("dex", 31); 
        
        set("qi", 35500); 
        set("max_qi", 35500); 
        set("jing", 34000); 
        set("max_jing", 34000); 
        set("neili", 36800); 
        set("max_neili", 36800); 
        set("jiali", 200); 
        set("level", 50);
        set("combat_exp", 9500000); 
        set("score", 20000); 
        
        set_skill("force", 260); 
        set_skill("lengyue-shengong", 380); 
        set_skill("dodge", 240); 
        set_skill("sixiang-bufa", 380); 
        set_skill("sword", 260); 
        set_skill("miaojia-jian", 380); 
        set_skill("baisheng-daofa", 380);
        set_skill("blade", 240); 
        set_skill("hujia-daofa", 380); 
        set_skill("strike", 260); 
        set_skill("unarmed", 260); 
        set_skill("cuff", 260); 
        set_skill("tianchang-strike", 380); 
        set_skill("parry", 360); 
        set_skill("literate", 300); 
        set_skill("martial-cognize", 380); 

        set_skill("daojian-guizhen", 380); 
        set_skill("hujia-quan", 380); 
        
set_skill("zileidao", 80); 
        map_skill("force", "lengyue-shengong"); 
        map_skill("dodge", "sixiang-bufa"); 
        map_skill("sword", "miaojia-jian"); 
        map_skill("blade", "hujia-daofa"); 
        map_skill("parry", "miaojia-jian"); 
        map_skill("strike", "tianchang-strike"); 
        map_skill("cuff", "hujia-quan"); 
        
        prepare_skill("strike", "tianchang-strike"); 
        prepare_skill("cuff", "hujia-quan"); 
           

         

        create_family("������", 7, "����"); 

        set("chat_chance_combat", 99); 
        set("chat_msg_combat", ({ 
                (: perform_action, "sword.zhai" :), 
                (: perform_action, "sword.zhu" :), 
                (: perform_action, "sword.jian" :), 
                (: perform_action, "sword.gan" :), 
                	(: perform_action, "sword.lian" :), 
                (: perform_action, "strike.dan" :), 
                	(: perform_action, "dodge.fei" :), 
                (: perform_action, "strike.duo" :), 
                	(: perform_action, "strike.huang" :), 
                (: perform_action, "cuff.kuai" :), 		
                (: exert_function, "recover" :), 
                (: exert_function, "powerup" :), 
        })); 

        set_temp("apply/damage", 100); 
        set_temp("apply/unarmed_damage", 100); 
        set_temp("apply/armor", 200); 
	set_temp("apply/attack",190);
	set_temp("apply/defense",190);
	set_temp("apply/armor",1800);
	set_temp("apply/damage",800);        
        set("master_ob",5);
	setup(); 
        
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear(); 

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
        message_vision(RED"$Nһ��ŭ�𣬻�����Ѫֱ������������!\n"NOR,ob,me);
        


        me->set_temp("killtian",1);


               destruct(ob);
        return;
}