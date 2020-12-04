#include <ansi.h>
inherit NPC;

void create()
{
  set_name("��Ů", ({ "xian nu", "xian"}) );
  set("gender", "Ů��" );
  set("age", 18);
  set("str", 30);
  set("per", 30);
  set("int", 30);
  set("attitude", "friendly");
  
    set("combat_exp", 500000);
  set("daoxing", 300000);



	set("max_qi", 38000);
	set("max_jing", 38000);
	set("neili", 34000);
	set("max_neili", 34000);
	set("max_neili", 34000);
	set("jiali", 100);
	set("combat_exp", 18500000);
	set("score", 400000);

	set_skill("unarmed", 1250);
	set_skill("force", 1250);
	set_skill("huagong-dafa", 1380);
	set_skill("throwing", 1250);
	set_skill("feixing-shu", 1380);
	set_skill("dodge", 1250);
	set_skill("zhaixinggong", 1380);
	set_skill("strike", 1250);
	set_skill("chousui-zhang", 1380);
	set_skill("claw", 1350);
	set_skill("sanyin-wugongzhao", 1380);
	set_skill("parry", 1200);
	set_skill("staff", 1300);
	set_skill("poison", 1380);
	set_skill("tianshan-zhang", 1380);
	set_skill("chanhun-suo", 1380);
	set_skill("whip", 1380);
	set_skill("literate", 1150);
set_skill("blade", 1250);
set_skill("xuantian-strike", 1380);
set_skill("bingpo-blade", 1380);

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

        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 300);

  setup();

             carry_object(__DIR__"obj/luoyi")->wear();
             carry_object(__DIR__"obj/rose")->wear();

  carry_object(__DIR__"obj/wuchou.c")->wield();
}

void init( )

{
	object ob;	
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
ob->start_busy(1);
        call_out("hunting",0);
        }
	if(!environment()->query("no_fight") )
        call_out("hunting",0);
}

void hunting()
{
	int i;
        object *ob;
        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
        if( !ob[i]->is_character() || ob[i]==this_object() || !living(ob[i])) continue;
        if(ob[i]->query("vendetta/authority")) continue;
if(wizardp(ob[i])) continue;
         if(!userp(ob[i])) continue;
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
        call_out("check",0);
        }
}