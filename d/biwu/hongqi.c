// sample master.c code
// xiake island master.c
#include <ansi.h>
inherit NPC;
//inherit F_MASTER;

void consider();

void create()
{
	set_name("���߹�", ({"hong qigong", "hong", "qigong"}));
	set("title", HIG"��ؤ"NOR);
	set("gender", "����");
	set("age", 75);
set("beggarlvl",9);
	set("long", 
		"������ؤ���ʮ���ΰ������ųơ���ؤ���ĺ��߹���ү�ӡ�\n");
	set("attitude", "peaceful");
        set("class", "beggar");
	
	set("str", 130);
	set("int", 134);
	set("con", 130);
	set("dex", 134);

	set("chat_chance", 1);
	set("chat_msg", ({
		"���߹�̾�˿�����������������ʱ���ٳԵ��ض����ġ��л�������������\n",
		"���߹�˵�������׻�˵�����ڽ��ϡ��������Ͻл��ص��������ݿ�������\n",
		"���߹��૵���������ؤ��ġ�����ʮ���ơ���������Ե����Ʒ�����\n",
	}));
	set("qi", 359000);
	set("max_qi", 359000);
	set("jing", 359400);
	set("max_jing", 359400);
	set("neili", 368000);
	set("max_neili", 368000);
	set("jiali", 500);
//	        set_temp("no_kill",1);
	set("combat_exp", 15000000);
	set("score", 500000);
	set("shen", 100000);
	         set("szj/passed",1);
        set("double_attack",1);
        set("breakup", 1);
        set("szj/over500", 1);
        set("jiuyin/full", 1);
        set("jiuyin/shang", 1);
        set("jiuyin/xia", 1);
        set("xlz/hang", 1);
         set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 2500);
        set_temp("apply/damage", 2500);
	set_skill("force", 1100);             // �����ڹ�
	set_skill("huntian-qigong", 1100);    // ��������
	set_skill("unarmed", 1100);           // ����ȭ��
	set_skill("xianglong-zhang", 1100);   // ����ʮ����
	set_skill("dodge", 1100);      	     // ��������
	set_skill("xiaoyaoyou", 1150);        // ��ң��
	set_skill("parry", 1100);             // �����м�
	set_skill("staff", 1100);             // ��������
	set_skill("dagou-bang", 1100);        // �򹷰���
	set_skill("begging", 1100);           // �л�����
	set_skill("checking", 1150);          // ����;˵
	set_skill("training", 1150);         // Ԧ����
	
	map_skill("force", "huntian-qigong");
	map_skill("unarmed", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "dagou-bang");
	map_skill("staff", "dagou-bang");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "staff.ban" :),
                (: perform_action, "staff.zhuang" :),
                (: perform_action, "staff.feng" :),
                (: perform_action, "staff.duo" :),
                (: perform_action, "staff.chan" :),
                (: perform_action, "staff.luanda" :),
                (: perform_action, "staff.wugou" :),                
                (: command("unwield staff") :),
                (: command("wield staff") :),
                (: perform_action, "unarmed.kanglongwuhui" :),                
                (: perform_action, "unarmed.leiting" :),                
                (: perform_action, "unarmed.xianglong" :),                                
                (: perform_action, "dodge.canghaiyixiao" :),                                
        }) );
	setup();
	
    carry_object("/p/item/ritemtz3/wstaff34")->wield();
    carry_object("/p/item/ritemtz3/ahands32")->wear();
    carry_object("/kungfu/class/gaibang/obj/jiaohuaji");
}

