// gunu.c 
// dicky.c


#include <ansi.h>;
inherit NPC;

void create()
{
	set_name("��Ů", ({ "gu nv", "girl"}));
	set("nickname", HIG"���Ĺ�Ů"NOR);
	set("long", 
"��Ů��ִ�����ڿ�ջ�⣬�۾������Ķ��ſ�ջ�������ڳԺȵ���Ⱥ��\n"
"ÿ���˶������Լ�������ڱ��˿��������˷�ʱ�䣬��ȴ���ú���Ҫ��\n");
	set("gender", "Ů��");
	set("age", 28);
	set("title", HIB"�����Ź�"NOR);
	set("attitude", "heroism");
	set("shen_type", 1);
	set("str", 30);
	set("int", 40);
	set("con", 30);
	set("dex", 30);	
        set("per", 21);

        set("combat_exp", 800000);
        set("combat_exp", 6500000);
        set("per", 29);
        set("str", 35);
        set("max_qi",35000);
        set("max_jing",35000);
        set("max_sen",35000);
        set("neili", 50000);
        set("max_neili", 50000);
        set("atman", 50000);
        set("max_atman", 50000);
        set("mana", 50000);
        set("max_mana", 50000);
        set("force_factor", 350);




set_skill("jinshe-jian",380);
set_skill("liancheng-jian",380);
set_skill("hujia-daofa",380);


set_skill("ningxue-shenzhua",380);
set_skill("tiexian-quan",380);
set_skill("demon-strike",380);
set_skill("nine-moon-claw",380);
set_skill("ill-quan",380);
set_skill("doomstrike",380);
set_skill("deisword",380);
set_skill("cloudstaff",380);
set_skill("siqi-sword",380);
set_skill("sharen-sword",380);
set_skill("chaos-steps",380);
set_skill("longfenghuan",380);
set_skill("blood-sword",380);
set_skill("luoriquan",380);
set_skill("jueqing-bian",380);
set_skill("qinnashou",380);
set_skill("taixuan-gong",380);

        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 600);
        set_temp("apply/damage", 650);
        set_skill("jingyiforce",380);
        set_skill("demon-blade",280);
        set_skill("literate",380);
        set_skill("unarmed",380);
        set_skill("dodge",290);
        set_skill("parry",280);
	set_skill("force",380);
	set_skill("blade",280);
	set_skill("changquan",380);
        //set_skill("doomsword",380);
        //set_skill("chilian-shenzhang",380);
        //set_skill("softsword",280);
        //set_skill("nine-moon-sword",380);
        set_skill("luohua-jian",380);
        set_skill("sword",380);
        set_skill("feixian-sword",380);
        set_skill("bat-blade",380);
        set_skill("fengyu-piaoxiang",390);

        map_skill("unarmed","changquan");
        map_skill("sword","jinshe-jian");
        map_skill("force","taixuan-gong");
        map_skill("dodge","fengyu-piaoxiang");
        map_skill("parry","liancheng-jian");
      set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: exert_function, "hun" :),
                (: exert_function, "jing" :),
                (: exert_function, "po" :),
                (: exert_function, "taixuan" :),		
                (: exert_function, "xuan" :),			
                (: perform_action, "unarmed.yuhuan" :),
                (: perform_action, "sword.kuangwu" :),
                (: perform_action, "sword.wan" :),
                (: perform_action, "sword.kun" :),	
                (: perform_action, "sword.shi" :),	
                (: perform_action, "sword.suo" :),	                	
                (: perform_action, "parry.ci" :),
                (: perform_action, "parry.erguang" :),
(: perform_action, "parry.gan" :),
(: perform_action, "parry.qian" :),
(: perform_action, "parry.qu" :),		             
(: perform_action, "parry.zhai" :),		             
(: perform_action, "parry.zhu" :),		             	             
(: perform_action, "dodge.zonghengsihai" :),		             	             
(: perform_action, "dodge.zonghengsihai" :),		             	              
        }) );

	set("chat_chance", 1);
	set("chat_msg", ({
		"��Ů�޺޵�˵��:Ϊ����ȴ�ٰ�Ī��ĳ�Թ������Ը�������һ���ӡ�\n",
	}) );
	set("inquiry", ([
		"����" : "ɱһ����Ҫ����ô�����㰮��һ���ˣ��������������\n",
		"�ܾ�" : "��С�ҾͶ��ñ����Լ�����֪��Ҫ�벻���˾ܾ�����õİ취�����Ⱦܾ����ˡ�\n",
		"����" : "����������˵�������㲻�ܹ���ӵ�е�ʱ����Ψһ�������ľ������Լ���Ҫ���ǡ�\n",
		"����" : "�����Ů���ǲ����ң������������Ѿ�����֪���������һ�����̲�ס���㣬��һ��Ҫƭ�ҡ�����������಻��Ը��Ҳ��Ҫ������������˲����ҡ�\n",
	]));

        setup();

        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/gangjian")->wield();
}


