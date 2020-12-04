// xiaoyaozi.c ��ң��
// zly 7/6/99

#include <ansi.h>
inherit NPC;
string ask_yaoshi();

void create()
{
	set_name("��ң��", ({"xiaoyao zi", "zi", "xiaoyao"}));
	set("title", HIY"̫������"NOR);
	set("nickname", "��ϼ����");
        set("shen_type", 1);
	set("gender", "����");
	set("attitude", "aggressive");
        set("vendetta/authority",1);
	set("age", 38);
	set("long", 
"����һ������ģ���������ˣ��������ڣ�ҧ��һ�����̹ܣ�˫Ŀ
�����Ʊգ�����������������\n"
	);

	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);

	set("qi", 25000);
	set("max_qi", 25000);
	set("jing", 22400);
	set("max_jing", 22400);
	set("neili", 58000);
	set("max_neili", 58000);
	set("jiali", 300);
	
	set("combat_exp", 3000000);
	set("score", 200000);
	set("shen", 100000);
	 
		set_skill("fengmo-zhang",220);
	set_skill("liuhe-zhang",220);
	set_skill("strike",390);
	set_skill("force", 300);             // �����ڹ�
	set_skill("huntian-qigong", 220);    // ��������
	set_skill("unarmed", 260);           // ����ȭ��
	set_skill("xianglong-zhang", 220);   // ����ʮ����
	set_skill("dodge", 260);      	     // ��������
	set_skill("xiaoyaoyou", 220);        // ��ң��
	set_skill("parry", 260);             // �����м�
	set_skill("staff", 220);             // ��������
	set_skill("dagou-bang", 220);        // �򹷰���
	set_skill("begging", 220);           // �л�����
	set_skill("checking", 220);          // ����;˵
	set_skill("training", 220);         // Ԧ����
	
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "dagou-bang");
	map_skill("staff", "dagou-bang");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "staff.chan" :),
                (: perform_action, "staff.ban" :),
                (: perform_action, "staff.feng" :),
                (: perform_action, "staff.zhuan" :),
                (: perform_action, "staff.luanda" :),
                (: perform_action, "staff.luanda" :),
                (: perform_action, "staff.luanda" :),
                (: perform_action, "staff.wugou" :),                
                (: perform_action, "unarmed.kanglongwuhui" :),                
                (: perform_action, "unarmed.kanglongwuhui" :),                
                (: perform_action, "unarmed.kanglongwuhui" :),                
                (: perform_action, "unarmed.hui" :),                
                (: perform_action, "unarmed.fei" :),                
                (: perform_action, "unarmed.qu" :),                
                (: perform_action, "unarmed.zhen" :),                
                (: perform_action, "unarmed.leiting" :),                
                (: perform_action, "unarmed.xianglong" :),                                
                (: perform_action, "dodge.canghaiyixiao" :),                                
                (: perform_action, "dodge.maishou" :),                                
        }) );

        set("chat_chance", 3);
        set("chat_msg", ({
            "��ң�Ӻٺ�Ц�ŵ������������������Ҫ�úõز���...��˵�꣬��������������ܡ�\n",
        }) );



        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/yanguan")->wield();
        carry_object(__DIR__"obj/shoes")->wear();        
       

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
 who->set_temp("book142",1);
message_vision("$N˵�������л۵�����֪���ˣ������ȥ������\n" NOR,this_object());	
	call_out("leavet",1);
}

void leavet()
{
        object ob = this_object();
 message_vision("$N����������ȥ��\n" NOR,this_object());
        destruct(this_object());
}