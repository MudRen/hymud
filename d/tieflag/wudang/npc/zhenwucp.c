 inherit NPC;
#include <ansi.h>
inherit F_MASTER;
void create()
{
    set_name(HIY"����۾�"NOR, ({ "master zhenwu", "master", "zhenwu" }) ); 
    set("gender", "����");
    set("age", 99);
    set("long", "����Ϊ����ǵۣ������䵱��Ϊ����������ʦ����ħ�����˵��̳��Ĵ���\n");
    set("attitude", "peaceful");
    set("str", 6000);
    set("cor", 30);
    set("int", 24);
    set("cps", 30);
    set("qi", 28000);
	set("max_qi", 28000);
	set("jing", 28000);
	set("max_jing", 28000);
	set("neili", 55000);
	set("max_neili", 55000);
	set("jiali", 100);
	set("combat_exp", 9000000);
	set("score", 600000);
	set("shen", 200000);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.zong" :),
                (: perform_action, "unarmed.zhenup" :),
                (: perform_action, "unarmed.tu" :),
                (: perform_action, "unarmed.zhan" :),
                (: perform_action, "unarmed.ji" :),
                (: perform_action, "unarmed.jielidali" :),
                (: perform_action, "hand.leiting" :),
                (: perform_action, "hand.mian" :),
                (: perform_action, "strike.zheng" :),	
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.chan" :),
                (: perform_action, "sword.chanup" :),
                (: perform_action, "sword.sui" :),
                (: perform_action, "sword.lian" :),
                (: perform_action, "sword.zhenwu" :),
                (: perform_action, "sword.lian" :),                
        }) );
set_skill("claw", 250);
set_skill("strike", 380);
	set_skill("force", 550);
	set_skill("taiji-shengong", 380);
	set_skill("dodge", 150);
	set_skill("tiyunzong", 380);
	set_skill("unarmed", 200);
	set_skill("taiji-quan", 380);
	set_skill("parry", 300);
	set_skill("sword", 300);
	set_skill("taiji-jian", 380);
	set_skill("liangyi-jian", 150);
	set_skill("wudang-array", 380);
	set_skill("array",100);
	set_skill("taoism", 500);
	set_skill("literate", 200);
	set_skill("yitian-tulong", 380);
	set_skill("juehu-shou", 380);
	set_skill("raozhi-roujian", 380);
	set_skill("wudang-mianzhang", 380);
	set_skill("hand", 280);
	set_skill("paiyun-shou", 380);
	set_skill("shenmen-jian", 380);
	set_skill("yitian-zhang", 280);
	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-quan");
	map_skill("sword", "taiji-jian");
		map_skill("hand", "paiyun-shou");
    set("no_shown",1);
    set("rank_nogen",1);
    create_family("�䵱��", 1, "������ʦ"); 
    set("ranks",({"����","����","����","�۾�"}));
    set("rank_levels",({320000,5187000,26244000}));
    setup();
}
int accept_fight(object me)
{
    return 0;
}

void init()
{
    add_action("do_look","look");
} 
int do_look(string arg)
{
    if (arg == "master zhenwu" || arg == "zhenwu" || arg =="master")
    {
        write(HIY "����Ϊ����ǵۣ������䵱��Ϊ����������ʦ����ħ�����˵��̳��Ĵ��񡣡�\n"NOR);
        return 1;
    }
    return 0;
}    
