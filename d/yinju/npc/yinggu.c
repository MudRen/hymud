inherit NPC;
#include <ansi.h>
string ask_me();
string ask_book();
string ask_yideng();
void create()
{
        set_name("Ӣ��", ({ "ying gu", "gu" }));
        set("nickname", HIR"������" NOR );
        set("gender", "Ů��");
        set("age", 41);
        set("long", 
        "����ɫ������������ʮ�����껪������˼�ǹ��ȣ������ޱ����������\n");
        set("combat_exp", 1000000);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 25);
        set("int", 25);
        set("con", 35);
        set("dex", 35);
        set("book_count", 1);
        set("max_qi", 51500);
        set("max_jing", 51500);
        set("neili", 61000);
        set("max_neili", 61000);
        set("jiali", 100);
        set("combat_exp", 9500000);
  set_skill("unarmed", 300);
        set_skill("force", 300);
        set_skill("dodge", 300);
        set_skill("parry", 350);
        set_skill("cuff", 300);
        set_skill("strike", 350);
        set_skill("sword", 300);
        set_skill("staff", 350);
        set_skill("finger", 320);
        set_skill("finger", 380);
	set_skill("kurong-changong", 301);
        set_skill("tiannan-step", 380);
        set_skill("jinyu-quan", 380);
        set_skill("wuluo-zhang", 380);
        set_skill("duanjia-sword", 380);
        set_skill("yiyang-zhi", 380);
//        set_skill("sun-finger", 100);
	set_skill("literate", 300);
	set_skill("wuluo-zhang", 200);
	set_skill("feifeng-whip", 300);
	map_skill("unarmed", "yiyang-zhi");
	map_skill("force", "kurong-changong");
	map_skill("dodge", "tiannan-step");
	map_skill("finger", "yiyang-zhi");
	map_skill("cuff", "jinyu-quan");
	map_skill("strike", "wuluo-zhang");
	map_skill("parry", "yiyang-zhi");
	map_skill("sword", "duanjia-sword");
	map_skill("staff", "duanjia-sword");
	prepare_skill("cuff", "jinyu-quan");
	prepare_skill("strike", "wuluo-zhang");
set("book_count",1);
set("yideng_count",1);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "finger.sandie" :),
                (: perform_action, "finger.dian" :),
                (: perform_action, "finger.jian" :),
                (: perform_action, "finger.qian" :),
                (: perform_action, "finger.sandie" :),
                (: perform_action, "sword.fenglei" :),
                (: perform_action, "sword.jingtian" :),
                (: perform_action, "sword.feilong" :),   
                	(: perform_action, "sword.ailao" :),
                		(: perform_action, "sword.xswy" :) ,            
                (: perform_action, "dodge.huadie" :),
                
                (: exert_function, "powerup" :),
                (: exert_function, "ku" :),
                (: exert_function, "rong" :),
        }) );

        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 3200);
        set_temp("apply/damage", 3200);
 
             
        set("inquiry", ([
		"һ��" : (:ask_me:),
              "�ϵ�" : (:ask_me:),
                   "�ܲ�ͨ"     : "�����������������",
                "������"     : "����Ϻ��У����ƴȱ���\n",
                "�Ҷ�"   : (: ask_yideng :),
                "��������"   : (: ask_book :),
	  ]) );

        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}
void init()
{
	object ob;
	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) 
       {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
 add_action("do_answer", "answer");
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
        command("say �����޲�֪������������֮ʣ����������֮ʣ����������֮ʣ�������Ｘ�Σ�");
	return;
}
int do_answer(string arg)
{
      object ob;
      object me=this_player();
          if( arg=="23" )
        { 
          if (query("book_count") < 1)
          {
	   command("say �����������Ѱ��ؼ��͸����������ڴ˴���");
            return 1;
          }
	   me->set_temp("book571",1);
	   add("book_count", -1);
          ob=new("/d/yinju/npc/obj/book");
                 ob->move(me);
          command("say û�뵽���㾹Ȼ����ˡ���Ȼ�������Ҳ����Ե����һ�������顣\n");

         }
         else 
             command("say ���ˣ������ˡ�\n");
        return 1;
}
string ask_me()
{
	 object me,ob;
	 me=this_player();
         if (query("yideng_count") < 1)
          {
return "Ӣ����ü��$N˵�������Ѿ��������ˡ�\n";     
          }
          if (!me->query_temp("book571"))
          {
	   command("say �����޲�֪������������֮ʣ����������֮ʣ����������֮ʣ�������Ｘ�Σ�");
            return "Ӣ����ü��$N˵�����Ȼش��ҵ�����ɡ�\n";     
          }
 
        add("yideng_count", -1);
        ob=new("/d/yinju/npc/obj/bunan");
        ob->move(me);
     return "Ӣ����ü��$N˵����ʮ���ˣ�����ҰѲ��Ҹ������˰ɡ�\n";     
       
}
string ask_book()
{
	mapping fam; 
	object ob;

	if ( (!(fam = this_player()->query("family")) ||
		fam["family_name"] != "����μ�") ||
		(query("book_count") < 1) ) 
		return RANK_D->query_respect(this_player()) + 
		"˵ʲô����ʵ�ڲ����ס�";

	if (this_player()->query_skill("literate",1) < 100)
		return RANK_D->query_respect(this_player()) + 
		"��Ҫ���飿�㻹���������ء�";
	add("book_count", -1);
	ob = new("/d/sdxl/heizhao/npc/lbook4");
	ob->move(this_player());
	command("rumor "+this_player()->query("name")+"�õ�������������\n");
	return "�ðɣ��Ȿ���������������û�ȥ�ú����С�\n";
}

string ask_yideng()
{
	mapping fam; 
	object ob;
	
	if (query("yideng_count") < 1)
		return RANK_D->query_respect(this_player()) + 
		"��˵ʲô����һ�ƴ�ʦ���ǿɱ����ҡ�";
	add("yideng_count", -1);
	ob = new("/d/sdxl/heizhao/npc/obj/whiteobj");
	ob->move(this_player());
	ob = new("/d/sdxl/heizhao/npc/obj/yellowobj");
	ob->move(this_player());
	ob = new("/d/sdxl/heizhao/npc/obj/redobj");
	ob->move(this_player());
	return "����������ðɣ��������Ҷ����㣬��Ե���ȥ�����ɡ�\n";
}

      

void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
  	if (!who) return;
 		who->set_temp("book572",1);
		


	call_out("leavet",0);
}


void leavet()
{
        object ob = this_object();
 message_vision("$N̾�˿������뿪�����\n" NOR,this_object());
        destruct(this_object());
}