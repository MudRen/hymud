//created by vikee
//2000.10

#include <ansi.h>
inherit NPC;
#include "huoyannpc2.h"
void create()
{
        set_name("ħ����", ({ "moli shou", "chiguo tianwang", "shou", "tianwang", "wang" }) );
        set("gender", "����" );
        set("long","
�Ĵ�����֮һ�����ű����󹬰�ȫ���ص�����ͬС�ɡ���
���书�ƺ�������һ�ɣ������������������ɱ�־��У���
û����֪����ʲô��Ҳ������Ϊ��ˣ���ʲŷ�����������
���Ρ�\n"
        );
	set("class", "xian");
	set("title", "�ֹ�����");
        set("age",43);
        set("str",30);
        set("int",37);
        set("max_qi",1200);
        set("qi",1100);
        set("max_jing",1100);
        set("jing",1100);
        set("combat_exp",2000000);
        set("daoxing",1500000);
        set("neili",2500);
        set("max_neili",1500);
        set("mana",2500);
        set("max_mana",1500);
        set("force_factor", 70);
        set("mana_factor",80);

        set("eff_dx", 450000);
        set("nkgain", 450);

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
                "name" : "���¾��ǳֹ���������ʥ�Ͱ��ر����š�",
                "here" : "������Ǳ����ţ������Ǻ󹬽��ء�",
        ]) );
        setup();
	carry_object(__DIR__"obj/dragonstick")->wield();
	carry_object(__DIR__"obj/jinjia")->wear();
}
void hurting(object me, object ob)
{
   int n;
   string *parts;

   remove_call_out("hurting");
   if(environment(me)!=environment(ob) || !me->is_fighting()) return;
   if(me->is_busy() ){
      call_out("hurting",9+random(6),me,ob);
      return;
   }
   message_vision(HIW"$n������ȡ�������������ڿ��У�����һֻ���󣻿���Ѫ�裬������������$Nҧ����\n"NOR,ob,me);
   n = 2 + ob->query("daoheng")/ (me->query("daoheng")+1);
   n += ob->query("combat_exp")/ (me->query("combat_exp")+1);
  if(random(n)){
      message_vision("$N���һ�����󵨣�\n�������ŵ���æ���ħ���ٵ����С�\n",ob);
      me->start_busy(2);
   }
   else {
      parts = ob->query("limbs");
      message_vision("���$N"+parts[random(sizeof(parts))]+"��һ��ҧ��Ѫ��ģ����\n",ob);
      ob->receive_wound("qi",ob->query("max_qi")/5,me);
   }
   call_out("hurting", random(6)+9,me, ob);
}
