
inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
   set_name("�˿�",({ "liao kong","liao","kong"}));
        set("gender", "����" );
        set("age", 52);
   set("long", "�����Ǿ�����Ժ�������˿մ�ʦ��\n");
   set("class","bonze"); 
   set("combat_exp",1500000);
   set("str", 28);
   set("per", 25);
   
   set_skill("dodge",400);
   set_skill("parry",400);
   set_skill("force",400);
   set_skill("staff",400);
   set_skill("cuff",400);
   set_skill("finger",400);
   set_skill("strike",400);

        set("max_qi",  18000);
        set("max_jing", 18000);
        set("neili", 35000);
        set("max_neili", 35000);
        set("jiali", 100);
        set("combat_exp", 8500000);
        set("score", 500000);

        set_skill("necromancy", 380);
        set_skill("force", 200);
        set_skill("xiaowuxiang", 380);
        set_skill("dodge", 200);
        set_skill("shenkong-xing", 380);
        set_skill("unarmed", 200);
        set_skill("yujiamu-quan", 380);
        set_skill("strike", 320);
        set_skill("parry", 200);
        set_skill("cuff", 200);
        set_skill("sword", 200);
        set_skill("mingwang-jian", 380);
        set_skill("lamaism", 380);
        set_skill("literate", 100);
        set_skill("staff", 100);
        set_skill("xiangmo-chu", 380 );
        set_skill("strike", 300 );
        set_skill("huoyan-dao", 380);
	set_skill("dashou-yin", 320);
	        set_skill("xiangmo-chu", 380);
        set_skill("magic", 380);
        set_skill("kwan-yin-spells", 380);
map_skill("magic", "kwan-yin-spells");
map_skill("cuff", "yujiamu-quan");
map_skill("hand", "dashou-yin");

    map_skill("force", "xiaowuxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("unarmed", "yujiamu-quan");
        map_skill("parry", "huoyan-dao");
        map_skill("sword", "mingwang-jian");
        map_skill("staff", "xiangmo-chu");
        map_skill("strike","huoyan-dao");
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 250);

if (random(3)==0)
{
map_skill("unarmed", "longxiang");
map_skill("parry", "longxiang");
	set("chat_chance_combat", 99);  
	set("chat_msg_combat", ({
                (: perform_action, "strike.fen" :),
                (: perform_action, "strike.honglian" :),
                (: perform_action, "strike.xiuluo" :),
                (: perform_action, "strike.yan" :),
                (: perform_action, "unarmed.die" :),
                (: perform_action, "unarmed.ji" :),
                (: perform_action, "unarmed.tun" :),
                (: perform_action, "unarmed.zhen" :),
                (: perform_action, "magic.ni" :),
                (: perform_action, "magic.hong" :),
                (: perform_action, "magic.ba" :),
                (: perform_action, "magic.an" :), 
                (: perform_action, "dodge.tianmaxingkong" :),
	}) );

}	
else
{

	set("chat_chance_combat", 99);  
	set("chat_msg_combat", ({
                (: perform_action, "strike.fen" :),
                (: perform_action, "strike.honglian" :),
                (: perform_action, "strike.xiuluo" :),
                (: perform_action, "strike.yan" :),
                (: perform_action, "cuff.chen" :),
                (: perform_action, "cuff.jiang" :),
                (: perform_action, "hand.dashouyin" :),
                (: perform_action, "hand.jingang" :),
                (: perform_action, "hand.yin" :),
                (: perform_action, "magic.ni" :),
                (: perform_action, "magic.hong" :),
                (: perform_action, "magic.ba" :),
                (: perform_action, "magic.an" :), 
                (: perform_action, "dodge.tianmaxingkong" :),
	}) );
}

   
   create_family("������Ժ",3,"����");
  

   setup();
  
}

