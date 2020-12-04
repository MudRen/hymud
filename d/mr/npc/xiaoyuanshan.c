// qiao-feng.c

#include <ansi.h>;
inherit NPC;
inherit F_MASTER;
int ask_duan2();
string ask_me();

void create()
{
	set_name("��Զɽ", ({"xiao yuanshan", "yuanshan", "xiao"}));
	set("nickname", "�ڲ�������");
	set("gender", "����");
	set("age", 29);
	set("long", 
"��Զɽ�������������ˣ������溺��ʦ��ϰ�䣬�书���ɹ���һ�������ܻ�
����ɺ���ʵ��׾��ܽ�ͷ�����Һܵ���̫�����ʶ�����ɹ�̫�����Σ�����
ɺ���ܽ�ͷ\n");
	set("attitude", "peaceful");
	set("class", "beggar");
 	set("beggarlvl", 10);
	
	set("str", 330);
	set("int", 24);
	set("con", 330);
	set("dex", 324);

        set("qi", 132500);
	set("max_qi", 132500);
	set("jing", 133800);
	set("max_jing", 133800);
	set("neili", 333000);
	set("max_neili", 333000);
	set("jiali", 300);
	
	set("combat_exp", 9000000);
	set("score", 200000);
	set("shen", 100000);
	 
		set_skill("fengmo-zhang",380);
	set_skill("liuhe-zhang",380);
	set_skill("strike",390);
	set_skill("force", 250);             // �����ڹ�
	set_skill("huntian-qigong", 380);    // ��������
	set_skill("unarmed", 300);           // ����ȭ��
	set_skill("xianglong-zhang", 380);   // ����ʮ����
	set_skill("dodge", 200);      	     // ��������
	set_skill("xiaoyaoyou", 380);        // ��ң��
	set_skill("parry", 300);             // �����м�
	set_skill("staff", 300);             // ��������
	set_skill("dagou-bang", 380);        // �򹷰���
	set_skill("begging", 200);           // �л�����
	set_skill("checking", 300);          // ����;˵
	set_skill("training", 300);         // Ԧ����
	
	set_skill("yuejia-qiang", 380);        // �򹷰���
	set_skill("suohou-gong", 380);        // �򹷰���
set_skill("chansi-shou", 380);        // �򹷰���
set_skill("claw", 380);        // �򹷰���
set_skill("hand", 380);        // �򹷰���	
set_skill("club", 380);        // �򹷰���		
	
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "dagou-bang");
	map_skill("staff", "dagou-bang");
	map_skill("strike", "xianglong-zhang");
map_skill("claw", "suohou-gong");
map_skill("hand", "chansi-shou");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.mielong" :),
                (: perform_action, "unarmed.mielong" :),
                (: perform_action, "unarmed.kanglongwuhui" :),                
                (: perform_action, "unarmed.hui" :),                
                (: perform_action, "unarmed.fei" :),                
                (: perform_action, "unarmed.qu" :),                
                (: perform_action, "unarmed.zhen" :),                
                (: perform_action, "unarmed.leiting" :),                
                (: perform_action, "unarmed.xianglong" :),                                
                (: perform_action, "dodge.gjtq" :),     
                (: perform_action, "dodge.canghaiyixiao" :),                                
                (: perform_action, "dodge.maishou" :),                                
        }) );
	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",500);
	set_temp("apply/damage",400);
        set("inquiry", ([
          "��ͷ���" : (: ask_duan2 :),
           ]));



	setup();
	
	//carry_object(__DIR__"obj/lvyv_bang");
	carry_object("/clone/misc/cloth")->wear();
//      carry_object(BOOK_DIR"stick_book")->wear();
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
who->set_temp("killtlbb83",1);
	 call_out("leavet",1);
}

void leavet()
{
        object ob = this_object();
message_vision(HIG"$N��һ�������У���һ��ɨ����ɮ����..\n"NOR NOR,this_object());
        destruct(this_object());
}
