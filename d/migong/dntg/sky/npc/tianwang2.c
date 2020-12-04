//sgzl 

#include <ansi.h>
inherit NPC;
#include "huoyannpc2.h"
 
void create()
{
        set_name("ħ���", ({ "moli hong", "guangmu tianwang", "hong", "tianwang" }) );
        set("gender", "����" );
	set("long",
		"ħ���Ľ�֮һ��ʹһ�˷��컭ꪣ�����һ��ɡ����Ի������Ԫɡ����\n"
                "ɡ�����鴩�ɣ�����ĸ�̣���ĸ�̣�ҹ���飬�ٳ��飬�ٻ��飬��ˮ\n"
                "�飬�����飬�����飬�����飬�����顣�������鴩�ɡ�װ��Ǭ����\n"
                "���֣����ɡ���ҳţ��ſ�ʱ���ذ��������޹⣬תһתǬ���ζ���\n"
	);
	set("age",50);
	set("title", "��Ŀ����");
	set("attitude", "heroism");
	set("str",40);
	set("int",30);
	set("max_qi",1100);
	set("qi",1100);
	set("max_jing",1100);
	set("jing",1100);
	set("combat_exp",2000000);
    set("daoxing",1500000);
	set("neili",2500);
	set("max_neili",1500);
	set("mana",2500);
	set("max_mana",1600);
	set("force_factor", 80);
	set("mana_factor",80);
	
        set("eff_dx", 450000);
        set("nkgain", 500);

	set_skill("force", 250);
	set_skill("club", 300);
	set_skill("parry", 180);
	set_skill("dodge", 180);
	set_skill("yijinjing", 301);
	set_skill("hunyuan-yiqi", 200);
	set_skill("weituo-chu", 300);
	set_skill("shaolin-shenfa", 180);

	map_skill("force", "yijinjing");
	map_skill("club",  "weituo-chu");
	map_skill("parry", "weituo-chu");
	map_skill("dodge", "shaolin-shenfa");

	set_skill("blade", 150);
	set_skill("claw", 150);
	set_skill("club", 150);
	set_skill("cuff", 150);
	set_skill("finger", 150);
	set_skill("hand", 150);
	set_skill("staff", 150);
	set_skill("strike", 150);
	set_skill("sword", 150);

	set_skill("banruo-zhang", 190);
	set_skill("cibei-dao", 190);
	set_skill("damo-jian", 190);
	set_skill("fengyun-shou", 190);
	set_skill("fumo-jian", 190);
	set_skill("jingang-quan", 199);
	set_skill("longzhua-gong", 190);
	set_skill("luohan-quan", 190);
	set_skill("nianhua-zhi", 190);
	set_skill("pudu-zhang", 190);
	set_skill("qianye-shou", 190);
	set_skill("sanhua-zhang", 190);
	set_skill("weituo-gun", 390);
	set_skill("wuchang-zhang", 190);
	set_skill("xiuluo-dao", 190);
	set_skill("yingzhua-gong", 190);
	set_skill("yizhi-chan", 200);
	set_skill("zui-gun", 200);
	set_skill("buddhism", 200);
	map_skill("blade", "cibei-dao");
	map_skill("claw", "longzhua-gong");
	map_skill("club", "weituo-chu");
	map_skill("cuff", "luohan-quan");
	map_skill("finger", "nianhua-zhi");
	map_skill("hand", "fengyun-shou");
	map_skill("staff", "weituo-gun");
	map_skill("strike", "sanhua-zhang");
	map_skill("sword", "fumo-jian");

     set("chat_chance_combat", 90);
     set("chat_msg_combat", ({
                (: perform_action, "finger.fuxue" :),
                (: perform_action, "finger.fuxue" :),
                (: perform_action, "club.leidong" :),
                (: perform_action, "club.zuijiu" :),
                            }) );
        set_temp("apply/attack", 150);
        set_temp("apply/defense", 100);
        set_temp("apply/armor", 100);
        set_temp("apply/damage", 100);
	set("inquiry", ([
		"name" : "���¹�Ŀ����ħ��죬��ʥ�Ͱ��ض����š�",
		"here" : "������Ƕ�����, ���ھ�������ˡ�",
	]) );

	setup();
	carry_object(__DIR__"obj/dragonstick")->wield();
	carry_object(__DIR__"obj/jinjia")->wear();
}

void hurting(object me, object ob)
{
   int n;
   
   remove_call_out("hurting");
   
   if(environment(me)!=environment(ob) || !me->is_fighting()) return;
   if(me->is_busy()) {
      call_out("hurting",6+random(5),me,ob);
      return;
   }
   
   message_vision(HIY"$n�ӻ��г����Ԫɡ���������˼��������Ԫɡ�����޵�������$N������\n"NOR,ob,me);
   n = 10 - (int)ob->query("daoxing")/(1 + (int)me->query("daoxing") ) -
      (int)ob->query("combat_exp")/(1+(int)me->query("combat_exp") );
   if(random(n)){
      me->start_busy( 60/ ((int)me->query_kar()+1));
      ob->start_busy(60/((int)ob->query_kar()+1) +1);
      message_vision("���$N����ס����ʱ�ж����ã�\n",ob);
   }
   else {
      me->start_busy( 30/ ( (int)me->query_kar()+1) );
      message_vision("$N����Ծ����Ԫɡ������������һ����\n",ob);
   }
   call_out("hurting",6+random(5),me,ob);
}

