// xiaoyaozi.c ��ң��
// zly 7/6/99

#include <ansi.h>
inherit NPC;
string ask_yaoshi();

void create()
{
	set_name("׿����", ({"zuo tianxiong", "zuo"}));
	set("title", HIR"������˷�"NOR);
        set("shen_type", 1);
	set("gender", "����");
	set("attitude", "aggressive");
        set("vendetta/authority",1);
	set("age", 38);
	set("long", 
"����һ����˵�е����ָ��֣�˫Ŀ
�����Ʊգ�����������������\n"
	);

	set("str", 50);
	set("int", 50);
	set("con", 50);
	set("dex", 50);

	  set("qi", 42000);
	set("max_qi", 42000);
	set("jing", 43800);
	set("max_jing", 43800);
	set("neili", 52000);
	set("max_neili", 52000);
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

        set("inquiry", ([
           "Կ��"  : (: ask_yaoshi :),
        ]));

        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/club")->wield();
      
       

} 

string ask_yaoshi()
{
        object me=this_player();
        me->set_temp("tao",1);
        command("hehe");
        command("whisper "+me->query("id")+" ������Ҳ���������ġ�");
        return "˵�꣬͵͵���ɽˮ������һ�ۡ�\n";
}

void unconcious()
{
	die();
}
void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
  	if (!who) return;

  	if((int)who->query("jinyong/book14")==3 )
{
		message_vision("$N˵�����ҵı��ذ���\n" NOR,this_object());
		i = 580+random(2000);
		who->set("jinyong/book14",4);
		who->add("combat_exp",i+12000);
		who->add("potential",i*19);
		who->add("mpgx",10);
		who->add("expmax",2);
		//command("chat "+this_player()->query("name")+"��ɫ���ˣ������Ƕ�ԡ�");
		tell_object (who,"��Ӯ����"+chinese_number(i+12000)+"�㾭��"+
		           chinese_number(i*19)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");

		who->save();
}
        
	::die();
}