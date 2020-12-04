 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors. 
inherit NPC;
#include <ansi.h>
void create()
{
        set_name("�����", ({ "figure"}) );
        set("nickname", HIR "��������"NOR);
        set("gender", "����" );
        set("age", 41);
        set("per", 30);
        set("agi",25);
        set("int",30);
        set("cor",40);
        set("attitude","friendly");
        set("bellicosity",30000);
        set("cps",200);
        set("max_neili", 2000);
        set("neili", 2000);
        set("force_factor", 90);
        set("mana",2000);
        set("max_mana",2000);
        set("atman",500);
        set("max_atman",500);
        set("str",40);
        set("figure_friend",1);
        
        set("resistance/gin",50);
        set("resistance/kee",50);
        set("resistance/sen",50);
        
        set("long",
"���˵����ϴ��źڲ���ߣ����ǹ��¿������Ե����������졣������Ŀ��������
������б����һ���䵶��������׺������������
\n"
        );
       set("qi", 25000);
	set("max_qi", 25000);
	set("jing", 22400);
	set("max_jing", 22400);
	set("neili", 58000);
	set("max_neili", 58000);
	set("jiali", 300);
	
	set("combat_exp", 8000000);
	set("score", 200000);
	set("shen", 100000);
	 
		set_skill("fengmo-zhang",380);
	set_skill("liuhe-zhang",380);
	set_skill("strike",390);
	set_skill("force", 300);             // �����ڹ�
	set_skill("huntian-qigong", 380);    // ��������
	set_skill("unarmed", 260);           // ����ȭ��
	set_skill("xianglong-zhang", 380);   // ����ʮ����
	set_skill("dodge", 260);      	     // ��������
	set_skill("xiaoyaoyou", 380);        // ��ң��
	set_skill("parry", 260);             // �����м�
	set_skill("staff", 380);             // ��������
	set_skill("dagou-bang", 380);        // �򹷰���
	set_skill("begging", 380);           // �л�����
	set_skill("checking", 380);          // ����;˵
	set_skill("training", 380);         // Ԧ����
	
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
                (: command("unwield yuzhu zhang") :),
                (: command("wield yuzhu zhang") :),
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
        
        setup();
        carry_object("/clone/misc/cloth")->wear();
        //carry_object("/obj/weapon/sword_katana")->wield();
                
} 
void init()
{
        object ob; 
        ::init();
        add_action("do_get","get");
        if( interactive(ob = this_player())) 
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
} 
void greeting(object ob)
{   
        if( !interactive(ob) || environment(ob) != environment() ){
           return;
        }
        if (!ob->query("figure_friend")){
            message_vision("$N�е���ɱ��\n", this_object() );
                this_object()->kill_ob(ob);
                ob->kill_ob(this_object());
        }
        return;
} 
int do_get(string arg)
{
if(!arg) return 0;
message_vision("$NЦ����û����ô���˵��°ɣ�\n",this_object(),this_player());
if (!this_player()->is_busy()) this_player()->start_busy(1);
return 1;
}     
