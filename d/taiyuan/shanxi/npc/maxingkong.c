inherit NPC;
#include <ansi.h>
int wieldblade();

void create()
{
    set_name("���п�", ({ "ma xingkong", "ma"}) );
    set("nickname", HIW "��������"NOR);
    set("title","������Ӫ�ھ� ����ͷ");
    set("gender", "����" );
    set("class","shaolin");
    set("reward_npc", 1);
    set("difficulty", 10);
    set("age", 45);
    set("per", 15);
    set("agi", 300);
    set("str", 500);
    set("int",30);
    set("ill_boss",5);
    set("attitude","friendly");
    set("max_neili", 3000);
    set("neili", 3000);
    set("atman", 5400);
    set("max_atman", 5400); 
    set("mana", 5000);
    set("max_mana", 5000);
    
    set("long", "
���п��������������Ѻܾã����ϵĹ���Ҳ��������������ͽ��ʢ�����ˣ�\n������������ȴ�ܴ�����˵�����������ֺ�֮�⡣\n");
    
    
    
    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
       // (: perform_action, "unarmed.qianshouqianbian" :),
        (: wieldblade  :),

        //(: perform_action, "dagger.pingshuixiangfeng" :),
             }) );
             
    set("combat_exp", 5000000);
    set("chat_chance", 1);
    set("chat_msg", ({
                "���п�����������һ̽����������һ��"+MAG"�����Ͻ������"NOR+"��ӭ��һ����ñ�ֱ��\n",
            }) ); 
    
set("max_qi", 18000);
	set("max_jing", 18000);
	set("neili", 24000);
	set("max_neili", 24000);
	set("max_neili", 24000);
	set("jiali", 100);
	set("combat_exp", 8500000);
	set("score", 400000);

	set_skill("unarmed", 250);
	set_skill("force", 250);
	set_skill("huagong-dafa", 380);
	set_skill("throwing", 250);
	set_skill("feixing-shu", 380);
	set_skill("dodge", 250);
	set_skill("zhaixinggong", 380);
	set_skill("strike", 250);
	set_skill("chousui-zhang", 380);
	set_skill("claw", 350);
	set_skill("sanyin-wugongzhao", 380);
	set_skill("parry", 200);
	set_skill("staff", 300);
	set_skill("poison", 380);
	set_skill("tianshan-zhang", 380);
	set_skill("chanhun-suo", 380);
	set_skill("whip", 380);
	set_skill("literate", 150);
set_skill("blade", 250);
set_skill("xuantian-strike", 380);
set_skill("bingpo-blade", 380);

	map_skill("whip", "chanhun-suo");
	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "chousui-zhang");
	map_skill("claw", "sanyin-wugongzhao");
	map_skill("parry", "chousui-zhang");
	map_skill("unarmed", "chousui-zhang");
	map_skill("staff", "tianshan-zhang");
	prepare_skill("strike", "chousui-zhang");
	prepare_skill("claw", "sanyin-wugongzhao");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "strike.zhaohuo" :),
                (: perform_action, "strike.biyan" :),
                (: perform_action, "strike.fushidu" :),
                (: perform_action, "strike.sandu" :),
                (: perform_action, "strike.huoqiang" :),
                (: perform_action, "strike.throw" :),
                (: perform_action, "strike.yinhuo" :),
                (: perform_action, "strike.zhaohuo" :),
                (: perform_action, "strike.huoqiu" :),
(: perform_action, "whip.duo" :),
(: perform_action, "whip.huixuan" :),
(: perform_action, "whip.suo" :),
         }) );

   setup();
   carry_object(__DIR__"obj/dragonstaff")->wield();
   carry_object("/clone/misc/cloth")->wear(); 
} 
int wieldblade()
{
command("unwield all");
perform_action("unarmed.qianshouqianbian");
command("wield staff");
return 1;
}
