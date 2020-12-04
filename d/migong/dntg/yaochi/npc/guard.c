
#include <ansi.h>
inherit NPC;

void create()
{
  string name, id;

  set_name("�����ʿ", ({ "jinjia weishi", "guard", "weishi" }) );
  set("gender", "����" );
  set("long", "

һ���������ݵ��콫������ĸ֮�����������ء�
����ְ�أ����Ὣ�κ�û��������˽�����ڡ�
");
  set("age", 35+random(10));
  set("attitude", "peaceful");
  set("str", 80);
  set("int", 25);
  set("per",21);
  set("combat_exp",100000);
  set("daoxing",100000);
  set("neili",500);
  set("max_neili",500);
  set("force_factor", 50);
  set("max_qi", 900);
  set("max_jing", 600);
  set("max_mana", 400);
  set("mana", 400);
  set("mana_factor", 20);
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
  setup();
 	carry_object("/clone/weapon/club")->wield();
	carry_object(__DIR__"xianpao")->wear();
}

void unconcious() {die();}

int accept_object(object me, object ob)
{

   if ((string)ob->query("id")!="invitation letter") return 0;
   call_out("verify",1,me);  
   return 1;
}      

void verify(object me) {

  if (me->name()!="��Ŵ���") {
    tell_object(me,"��һ̧ͷ�����ֽ����ʿ����һ��������Ŀ������Ͷ����\n");
    command("hmm");
    command("say ������������Ǹ���Ŵ��ɵģ���ô������������");
    message_vision(CYN"$N�ŵû겻���壬����˵�������Ҽ�ģ��ҵ��ϼ�ģ��ҡ�����\n"+
        "��û˵�꣬��һ���̵ض���˽��䡣\n"NOR,me);
    return;
  }

  command("say ԭ���ǳ�Ŵ��ɼݵ���");
  command("bow daxian");
  command("say ������롣����");
  me->set_temp("yaochi_pass",2);
}
