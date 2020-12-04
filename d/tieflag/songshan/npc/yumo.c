 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int kill_him();
void  smart_fight( object who); 
void create()
{
    set_name("����ħ", ({ "master yumo", "master"}) );
    set("nickname", HIW "��"NOR);
    set("gender", "����" );
    set("reward_npc", 1);
    set("difficulty", 4);
    set("age", 64);
    set("per", 35);
    set("int",30);
    set("class","beggar");
    set("attitude","friendly");
    
    set("max_neili", 1000);
    set("neili", 1000);
    set("force_factor",30);
    
    set("pursuer", 1);
    set("resistance/kee",10);
    set("resistance/gin",10);
    set("resistance/sen",10);
    
    set("long", "�������µ�һ���İ�����ʦ�壬������������ȱ�ǰ�ϰ����δ����ؤ�\n");
    create_family("ؤ��", 6, "ʦ��");
    set("rank_nogen",1);
    set("ranks",({"�������","һ������","��������","��������","�Ĵ�����",
                      "�������","��������","�ߴ�����","�˴�����","�Ŵ�����",
                      "����","������"}));
    set("rank_levels",({ 32000,64000,128000,256000,512000,
                             1024000,1536000,2304000,3456000,
                             5187000,26244000 })); 
    set("combat_exp", 2000000);
	set("str", 60);
	set("int", 69);
	set("con", 60);
	set("dex", 68);

	set("qi", 19500);
	set("max_qi", 19500);
	set("jing", 16900);
	set("max_jing", 16900);
	set("neili", 58000);
	set("max_neili", 58000);
	set("jiali", 150);

	set("combat_exp", 9500000);
	set("score", 200000);
set_skill("qixian-wuxingjian", 380);
set_skill("cuff", 300);
set_skill("cuff", 300);
set_skill("lingshe-quan", 380);
set_skill("zhaosheshu", 380);
set_skill("yangsheshu", 380);
	set_skill("sword", 280);
	set_skill("force", 250);
	set_skill("unarmed", 250);
	set_skill("dodge", 250);
	set_skill("parry", 250);
	set_skill("strike",320);
	set_skill("hand",320);
	set_skill("training",380);
	set_skill("staff", 250);
	set_skill("hamagong", 380);
	set_skill("chanchu-bufa", 380);
	set_skill("shexing-diaoshou", 380);
	set_skill("lingshe-zhangfa", 380);
	set_skill("hamashengong", 380);
	set_skill("xiyu-tiezheng", 380);
set_skill("shentuo-zhang", 380);
	map_skill("strike", "hamagong");
	map_skill("force", "hamagong");
	map_skill("dodge", "chanchu-bufa");
	map_skill("unarmed", "shexing-diaoshou");
	map_skill("hand", "xiyu-tiezheng");
	map_skill("parry", "hamagong");
	map_skill("staff", "lingshe-zhangfa");
	prepare_skill("strike", "hamagong");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "reserve" :),
                (: perform_action, "staff.saoluoye" :),
                (: perform_action, "staff.shewu" :),
                (: perform_action, "staff.shoot" :),
                (: perform_action, "staff.saoluoye" :),
                (: command("unwield shengzhang") :),
                (: command("wield shengzhang") :),
                (: command("zhaoshe") :),
                (: perform_action, "strike.hama" :),                
               (: perform_action, "strike.puji" :),                
	              (: perform_action, "strike.tui" :),                
		          (: perform_action, "strike.zhen " :),                
                (: perform_action, "hand.shewu" :),                
             
        }) );

    setup();
    carry_object("/clone/misc/cloth")->wear();
    carry_object(__DIR__"obj/staff")->wield();
} 
