// huatiegan.c

inherit NPC;
#include <ansi.h>
void create()
{
       set_name("������", ({ "Hua tiegan", "hua" }));
       set("long", 
       "�����������桰�仨��ˮ���е��϶���\n"
       "��������н��ϣ��������壬������һ����ƽǹ���ų���ƽ�޵С���������Ϊ��ȴ��զ�ġ�\n");
       set("gender", "����");
       set("nickname", HIR"��ƽ�޵�"NOR);
       set("age", 45);
       set("attitude", "peaceful");
       set("shen_type", 0);
       set("str", 35);
       set("int", 38);
       set("con", 35);
       set("dex", 35);
   set("qi", 32000);
	set("max_qi", 22000);
	set("jing", 23800);
	set("max_jing", 23800);
	set("neili", 22000);
	set("max_neili", 22000);
	set("jiali", 200);
	
	set("combat_exp", 1500000);
	set("score", 200000);
	set("shen", 100000);
	 	set_skill("fengmo-zhang",180);
	set_skill("liuhe-zhang",180);
set_skill("dagou-bang",80);
	set_skill("strike",190);
	set_skill("force", 250);             // 
	set_skill("force", 180);             // �����ڹ�
	set_skill("huntian-qigong", 330);    // ��������
	set_skill("dodge", 150);      	     // ��������
	set_skill("xiaoyaoyou", 320);        // ��ң��
	set_skill("parry", 150);             // �����м�
	set_skill("hand", 200);              // �����ַ�

	set_skill("blade", 180);             // ��������
	set_skill("liuhe-dao", 280);       // �������ϵ�
	set_skill("begging", 200);           // �л�����
	set_skill("checking", 200);          // ����;˵
	set_skill("training", 200);          // Ԧ����
	set_skill("strike",285);  // �����Ʒ�

	set_skill("xianglong-zhang",285);

	map_skill("strike","lianhua-zhang");
	prepare_skill("strike","lianhua-zhang");

	
	map_skill("force", "huntian-qigong");
	map_skill("hand",  "suohou-gong");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("blade", "liuhe-blade");
	map_skill("parry", "yuejia-qiang");

	set_skill("yuejia-qiang", 380);        // �򹷰���
	set_skill("suohou-gong", 380);        // �򹷰���
set_skill("chansi-shou", 380);        // �򹷰���
set_skill("claw", 380);        // �򹷰���
set_skill("hand", 380);        // �򹷰���	
set_skill("club", 380);        // �򹷰���		
map_skill("parry", "yuejia-qiang");
map_skill("club", "yuejia-qiang");
map_skill("claw", "suohou-gong");
map_skill("hand", "chansi-shou");

	prepare_skill("hand",  "chansi-shou");
prepare_skill("claw",  "suohou-gong");


       set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "club.gong" :),
                (: perform_action, "club.qldj" :),
                (: perform_action, "club.zhtx" :),
                (: command("unwield yuejia qiang") :),
                (: command("wield yuejia qiang") :),
                (: perform_action, "claw.suo" :),
                (: perform_action, "hand.qin" :),                
                (: perform_action, "hand.qinna" :),                
                (: perform_action, "dodge.gjtq" :),                                
                (: perform_action, "dodge.canghaiyixiao" :),                                
                (: perform_action, "dodge.maishou" :),                                
        }) );
	setup();
       set("chat_chance", 20);
       set("chat_msg", ({
              "�����ɻ�������������Х���糱ӿ�������仨������ˮ���������˶�����\n",
       }));

       setup();
       carry_object("/clone/weapon/changqiang")->wield();
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
        


        me->set_temp("killsx2",1);


              ::die();
        return;
}