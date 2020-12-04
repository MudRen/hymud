inherit NPC;
#include <ansi.h>
void create()
{
	set_name("�Է�", ({ "qiao fu", "qiao" }));
	set("title",  "������󽫾�" );
	set("long", 
"�����Ǵ������ԭ�󽫾���һ�ƴ�ʦ���Ĵ����֮һ��
��������һ���ɲ���������һ����ͷ����������ɫ��
׳����̬������������������Ǵ󽫾��а������硣��
�����ֲ����Ѷ�����ɽ�ּ��Բ񣬱ص����Ǹ�߳���
�Ƶ�ͳ����˧��\n");
              set("nickname", HIY "���Ը���" NOR );   
        set("gender", "����");
        set("age", 45);

        set("class", "officer");
        set("attitude", "friendly");
        set("shen_type", 1);
        set("per", 25);
        set("str", 30);
        set("int", 20);
        set("con", 25);
        set("dex", 25);     
        set("max_qi", 21000);
        set("max_jing", 21500);
        set("neili", 22000);
        set("max_neili", 22000);
        set("jiali", 50);
        set("combat_exp", 3500000);
        set("score", 100000);


        set("inquiry", ([
                "һ�ƴ�ʦ"   : "ʦ�������˼������档\n",
                "������"     : "������ʦ�����������䡣\n",
                "������"     : "������ʦ�����������ӡ�\n",
        ]) );
   set_skill("unarmed", 200);
        set_skill("force", 200);
        set_skill("dodge", 200);
        set_skill("parry", 150);
        set_skill("cuff", 200);
        set_skill("strike", 150);
        set_skill("sword", 200);
        set_skill("staff", 150);
        set_skill("finger", 220);
        set_skill("finger", 280);
	set_skill("kurong-changong", 301);
        set_skill("tiannan-step", 280);
        set_skill("jinyu-quan", 280);
        set_skill("wuluo-zhang", 280);
        set_skill("duanjia-sword", 380);
        set_skill("yiyang-zhi", 280);
//        set_skill("sun-finger", 100);
	set_skill("literate", 200);
	set_skill("wuluo-zhang", 200);
	set_skill("feifeng-whip", 300);
	map_skill("unarmed", "yiyang-zhi");
	map_skill("force", "kurong-changong");
	map_skill("dodge", "tiannan-step");
	map_skill("finger", "yiyang-zhi");
	map_skill("cuff", "jinyu-quan");
	map_skill("strike", "wuluo-zhang");
	map_skill("parry", "yiyang-zhi");
	map_skill("sword", "duanjia-sword");
	map_skill("staff", "duanjia-sword");
	prepare_skill("cuff", "jinyu-quan");
	prepare_skill("strike", "wuluo-zhang");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "finger.sandie" :),
                (: perform_action, "finger.dian" :),
                (: perform_action, "finger.jian" :),
                (: perform_action, "finger.qian" :),
                (: perform_action, "finger.sandie" :),
                (: perform_action, "sword.fenglei" :),
                (: perform_action, "sword.jingtian" :),
                (: perform_action, "sword.feilong" :),   
                	(: perform_action, "sword.ailao" :),
                		(: perform_action, "sword.xswy" :) ,            
                (: perform_action, "dodge.huadie" :),
                
                (: exert_function, "powerup" :),
                (: exert_function, "ku" :),
                (: exert_function, "rong" :),
        }) );
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 1200);
        set_temp("apply/damage", 1100);

        setup();
        carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
}
        
void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
  	if (!who) return;
 		who->set_temp("book571",1);
		


	::die();
}