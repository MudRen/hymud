//
// zhou.c �ܲ�ͨ

#include <ansi.h>;

inherit NPC;
void create()
{
int i,k,a,b,c,d,e,f,temp;
	set_name("�ܲ�ͨ", ({ "zhou botong", "zhou", "bo tong" }));
	set("gender", "����");
	set("nickname", CYN "����ͯ" NOR ) ;
	set("title", "ȫ��̵�һ������") ;
	set("age", 45);
	set("long",
		"�������˳ơ�����ͯ�����ܲ�ͨ��\n"
		"��һ���ɷ���ǵ����ӣ��������������ʮ���ꡣ������������ʵ�Ѿ������ϡ�ˡ�\n"
	);

	set("combat_exp", 25000000);
	set("shen_type", 1);

	set("max_qi", 35000);
	set("max_jing", 35000);
	set("neili", 54000);
	set("max_neili", 54000);
//	set("jiali", 0);
	set("per",39);
d=60+random(60);
set("str",d);
set("dex",d);
set("int",d);
set("con",d);
set("per",d);
set("kar",d);
        set("szj/passed",1);
        set("double_attack",1);
        set("breakup", 1);
        set("szj/over200", 1);
        set("jiuyin/full", 1);
        set("jiuyin/shang", 1);
        set("jiuyin/xia", 1);
  set_skill("force", 380);
        set_skill("xiantian-qigong", 360);    //��������
        set_skill("sword", 380);
        set_skill("quanzhen-jian",380);  //ȫ�潣
        set_skill("dodge", 260);
        set_skill("jinyan-gong", 380);   //���㹦
        set_skill("parry", 280);
        set_skill("unarmed",280);
        set_skill("haotian-zhang", 380);    //�����
        set_skill("array",380);
        set_skill("qixing-array",380);
set_skill("kongming-quan",380);
set_skill("qixing-jian",380);
set_skill("qixing-shou",380);
set_skill("hand", 300);
        set_skill("literate",220);
        set_skill("strike",350);
        set_skill("taoism",380);
        set_skill("finger",200);
        set_skill("sun-finger",200);  //һ��ָ
        map_skill("force", "xiantian-qigong");
        map_skill("sword", "quanzhen-jian");
        map_skill("dodge", "jinyan-gong");
        map_skill("parry", "xiantian-qigong");
        map_skill("strike", "haotian-zhang");
        map_skill("finger","sun-finger");
        map_skill("unarmed","kongming-quan");
if (random(2)==0)	        map_skill("unarmed","xiantian-qigong");


 set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: exert_function, "hup" :),
                (: exert_function, "recover" :),
                (: perform_action, "sword.ding" :),
                (: perform_action, "sword.jianqi" :),
                (: perform_action, "sword.sanqing" :),
                (: perform_action, "sword.tonggui" :),                
                (: perform_action, "sword.qixing" :),
                (: perform_action, "sword.qixinggongyue" :),
                (: perform_action, "unarmed.kong" :),
                (: perform_action, "unarmed.luanwu" :),                	
                (: perform_action, "unarmed.quan" :), 	
                (: perform_action, "unarmed.ming" :), 		
                (: perform_action, "unarmed.ruo" :),                	                	

                (: perform_action, "unarmed.dang" :),
                (: perform_action, "unarmed.shen" :),                	
                (: perform_action, "unarmed.fen" :), 	
                (: perform_action, "unarmed.hun" :), 		
                (: perform_action, "unarmed.jian" :),                	                	

                (: exert_function, "shield" :),                
                (: exert_function, "xiantiandafa" :),                
                (: exert_function, "powerup" :),                
        }));

	set("inquiry", ([
		"�����澭" : "����������ʲ�ӣ��ҾͲ��������ˡ�\n",
		"����"     : "�ҶԲ���������",
		"��"       : "��Ҫ���ң����������ˣ�\n",
		"�ݰ��ֵ�" : "�����ҵİݰ��ֵܹ����������Ǹ���Ӣ�ۡ���������������������",
		"����"     : "�����ҵİݰ��ֵܹ����������Ǹ���Ӣ�ۡ���������������������",
		"����"     : "��СѾͷ����飬�ұȲ�������",
	]) );
	create_family("ȫ���", 1, "����");
	set_temp("apply/attack", 200);
	set_temp("apply/defense", 200);
	set_temp("apply/armor", 1510);
	set_temp("apply/damage", 1515);


	setup();

	carry_object("/clone/cloth/cloth")->wear();
}
int accept_object(object who, object ob)
{
	if (ob->query("id") == "du she")
	{
		message_vision("$N�ó�һ������������ͯ����ǰ���˻Σ�����������
����ͯ�ŵ�����������������⣡���ܱߺ������͸�ˣ�����ͯ�ⷬ�����ˣ�\n\n
��������Զȥ�����ڲ������š�\n" ,who);
		destruct(this_object());
		return 0;
	}
	if (ob->query("id") == "mi" && !userp(ob))
	{
		if(who->query_temp("marks/mihave") )
		{
			message_vision("����ͯ�ӹ����ۣ����˵�˵�����ã��ã��á�\n\n",who);
			if(who->query("combat_exp") < 100000)
			{
				tell_object(who,HIW"��ľ��������ˣ�\n���Ǳ�������ˣ�\n" NOR);
				who->add("combat_exp",100+random(50));
				who->add("potential",30+random(30));
			}
			else
			who->add("potential",random(1));
			who->set_temp("marks/mihave",0);
			who->add("marks/mi",1);
			if((who->query("marks/mi"))>60 && who->query("age")>39)
			{
				tell_object(who, HIG "���������䣬���Եø��������ˣ�\n" NOR);
				who->add("mud_age",-86400);
				who->delete("last_slp");
				who->delete("jingzuo_time");
				who->add("marks/mi_age",1);
				who->set("marks/mi",0);
			}
		}

		else
		{
			message_vision( HIY"����ͯ�ӹ����ۣ���$N���˸�������Ц������������Ҳ���������ģ����԰ײ��ԡ�\n\n"NOR,who);
		}
		call_out("delmi",2);
		return 1;
	}
	return 0;
}
int delmi()
{
	object obj2;
	obj2=present("mi", this_object());
	destruct(obj2);
	return 1;      
}


void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
  	if (!who) return;

  	if((int)who->query("jinyong/book10")==6 && who->query_temp("book51071"))
{
		message_vision("$N˵����������Ȼ������ң������Һ������˳�\n" NOR,this_object());
		message_vision("$N˵�����������۷�����Ҿ���ȵ����ˣ���ȥ�����ɣ�\n" NOR,this_object());
who->set_temp("book51072",1);
}
     
	call_out("leavet",1);
}
void leavet()
{
        object ob = this_object();
 message_vision("$N�����ȥ���ˣ�\n" NOR,this_object());
        destruct(this_object());
}
