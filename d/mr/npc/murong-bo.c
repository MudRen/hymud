 // /u/beyond/mr/npc/murong-bo.c  Ľ�ݲ�
// this is made by beyond
// update 1997.6.23
inherit NPC;
inherit F_MASTER;
 string ask_huijia();
#include <ansi.h>
void create()
{
	set_name("Ľ�ݲ�",({"murong bo","murong","bo"}));
        set("title","����Ľ����ү��");
        set("nick","�Ա�֮�� ��ʩ����");
	set("long", 
              "���������ºų��Ա�֮��������֮��Ĺ���Ľ�ݲ���\n"
              "�����ϴ��Ų���һ����Ц�ݡ�\n");
        set("age", 57);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 60);
	set("int", 60);
	set("con", 60);
	set("dex", 60);
	
	set("max_qi", 86500);
	set("max_jing", 86500);
	set("neili", 88500);
	set("max_neili", 88500);
	set("jiali", 50);
	set("combat_exp", 9000000);
	set("score", 50000);                
        set_skill("xingyi-zhang",380);
        set_skill("strike",280);
        set_skill("finger",280);
        set_skill("dodge",280);
        set_skill("force", 280);
	set_skill("canhe-zhi", 380);
	set_skill("murong-jianfa",380);       
        set_skill("shenyuan-gong", 380);
	set_skill("yanling-shenfa", 380);
        set_skill("douzhuan-xingyi", 380);
	set_skill("parry", 320);
	set_skill("sword", 300);
	set_skill("literate", 300);
        set_skill("murong-daofa", 380);
        set_skill("blade",250);
         set_skill("hand", 380);
         set_skill("qxxy-shou", 380);
        set_skill("six-sword",380);       
        map_skill("blade", "murong-daofa");
        map_skill("finger", "canhe-zhi");
        map_skill("hand", "qxxy-shou");
	map_skill("force", "shenyuan-gong");
	map_skill("dodge", "yanling-shenfa");
        map_skill("parry", "douzhuan-xingyi");
	//if (random(3)==0)	map_skill("parry", "murong-jianfa");
	map_skill("sword", "six-sword");
                map_skill("strike", "xingyi-zhang");
       prepare_skill("finger", "canhe-zhi");
        prepare_skill("hand", "qxxy-shou");

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "parry.xingyi" :),
                 (: perform_action, "parry.yihuajiemu" :),
                (: perform_action, "finger.ci" :),
                (: perform_action, "finger.dianxue" :),
                 (: perform_action, "finger.jin" :),
                (: perform_action, "finger.canshang" :),
                 (: perform_action, "finger.lian" :),
                (: perform_action, "sword.lhj" :),
                (: perform_action, "sword.nbajian" :),
                (: perform_action, "sword.tx" :),
                (: perform_action, "sword.wbajian" :),
             		(: command("unwield sword") :),
		               (: command("wield sword") :),  
                (: perform_action, "dodge.yanling" :),                
                   (: perform_action, "strike.riyue" :),
                	(: perform_action, "strike.xingdian" :),
                (: perform_action, "hand.po" :),
                 (: perform_action, "hand.xy" :),
                (: perform_action, "hand.zhai" :),

        }));
                set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);
        create_family("����Ľ��",1,"����");

       	set("inquiry", 
                ([
                        "name" : "�Ҿ����Ա�֮������ʩ����Ĺ���Ľ�ݲ���\n",
                        "here" : "�����������µĲؾ�¥��\n",
                        "rumors" : "����Ľ�ݸ���������֮�д�������ͷ����ү�����������ѽ��\n",
                         "��ͷ���" : (: ask_huijia :),
                ]));
       	setup();
	carry_object("/clone/weapon/gangjian")->wield();
    carry_object("/clone/misc/cloth")->wear();
	
}
void attempt_apprentice(object ob)
{
          object me  = this_player();
 
        string name, new_name;
	name = ob->query("name");
 
        if (present("jiaxin", me))
         {  destruct(present("jiaxin",me));

           command("say �ðɣ���Ȼ" + RANK_D->query_respect(ob) + "���Ҷ����ż�����Ϊ��" +
		"��������������Ҿ�������ɡ�");
 
           new_name = "Ľ��" + name[2..3];
	   ob->set("name", new_name);
           command("say �ӽ��Ժ���ͽ���" + new_name + "��ϣ�����ܰ�Ľ�ݹ�������");
           command("recruit " + ob->query("id"));
           command("chat ����һЦ��˭�� �Ա�֮�� ��ʩ���� ����������");
           command("chat* haha"); 
         }
        else
          command("say ��Ľ�ݲ����������ͽ!");
        return;
           
}
 

string ask_huijia()
{
	int i;
	object fang,who,where;
object me=this_player();
object ob = this_object();
	who=me;
	where = environment(who);

if(!me->query_temp("killtlbb81") )
return "��˵�������������֣�����ȥ�������ɡ�����\n";

if(!me->query_temp("killtlbb82") )
return "��˵�����Ϲ������֣�����ȥ�������ɡ�����\n";
if((int)me->query("jinyong/book4")>8 )
return "���Ѿ������ˡ�����\n";
if(me->query("jinyong/book4")!=8 )
return "�Ҳ�֪��ʲô��ͷ�����°�������\n";



if(me->is_fighting() )
return "������ս�����ء�����\n";

      if(!query("iskillok"))
      {
      message_vision("ͻȻ����Χɱ����һ���ڲ������� ˵�����ҵĴ���� �����ҵ��� !\n",this_object(),who);	
      	fang = load_object("/d/mr/npc/xiaoyuanshan");
	fang->move(environment(who));	
	fang->kill_ob(who);

     this_object()->set("iskillok",1);
     set("iskillok",1);
return "�Ҿ��Ǵ�ͷ��硣 \n";
      }	

        fang = present("xiao yuanshan",where);
	if(fang)
	{
		who->start_busy(3);
return "�ȶԸ���Զɽ�� \n";
	}

if(!me->query_temp("killtlbb83") )
return "����ҶԸ�����Զɽ�˲�?\n";

me->set_temp("killtlbb84",1);
kill_ob(me);
return "��Ȼ��֪�����ҵ����� ��Ҳȥ����.\n";
}

void unconcious()
{
	die();
}
void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
  	
  	if (!who) return;


  	if(who->query_temp("killtlbb84") && !query("iskillok1"))
	{
      message_vision(HIR"$N˵������Ҫ����.....\n" NOR,this_object());
      message_vision(HIR"$N����ת���ƹ����³�һ����Ѫ...�־��������ˡ�\n" NOR,this_object());
	who->start_busy(6);
	this_object()->set("qi", 59000);
	this_object()->set("eff_qi", 59000);
	this_object()->set("max_qi", 59000);
	this_object()->set("jing", 59200);
	this_object()->set("max_jing", 59200);
	this_object()->set("neili", 57500);
	this_object()->set("max_neili", 57500);
     this_object()->set("iskillok1",1);
     set("iskillok1",1);	
     this_object()->kill_ob(who);
     who->kill_ob(this_object());
	return;
	}
  	if(((int)who->query("jinyong/book4")>=9) || !who->query_temp("killtlbb84"))
	{
//::die();	
	}
        else if(who) {
        	message_vision(RED"$N˵������ƭ�˰��ϣ������������ɹ������ϣ��ز����ˣ������� .....\n"NOR NOR,this_object());
		i = 800+random(2000);
		who->set("jinyong/book4",9);
		who->add("combat_exp",i+30000);
		who->add("potential",i*25);
		who->add("mpgx",10);
		who->add("expmax",2);
		//command("chat "+this_player()->query("name")+"��ɫ���ˣ������Ƕ�ԡ�");
		tell_object (who,"��Ӯ����"+chinese_number(i+30000)+"�㾭��"+
		           chinese_number(i*45)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");
		who->save();
        }
	 call_out("leavet",1);

}
void leavet()
{
        object ob = this_object();
	message_vision(HIG"$N��һ�������У���һ��ɨ����ɮ����..\n"NOR NOR,this_object());

        destruct(this_object());
}
