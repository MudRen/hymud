//Edited by fandog, 02/13/2000
#include <ansi.h>;
inherit NPC;
string ask_me();
string ask_me2();
string ask_book();
string ask_book2();
void do_kill(object ob);
void create ()
{
	object weapon;
	set_name("����", ({"di yun","di"}));
	set("long", "��������ڣ�ȧ��΢�ߣ����ִ�ţ������������³�����ׯ�ں��ӡ�\n");
	set("gender", "����");
	set("age", 24);

	set("combat_exp", 20000000);
	set("str", 125);
	set("int", 125);
	set("con", 125);
	set("dex", 125);
	set("per", 26);
	set_skill("force", 320);
	set_skill("dodge", 320);
	set_skill("sword", 220);
	set_skill("parry", 320);
	set_skill("feixian-steps", 320);
	set("max_qi",20000);
	set("max_jing",20000);
	set("max_neili",30000);
	set("qi",20000);
	set("jing",20000);
	set("neili",30000);

	set_skill("liancheng-jian", 320);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.ci" :),
                (: perform_action, "sword.erguang" :),
                (: perform_action, "sword.gan" :),
                (: perform_action, "sword.qian" :),
                (: perform_action, "sword.qu" :),
                (: perform_action, "sword.zhai" :),
                (: perform_action, "sword.zhu" :),
                (: perform_action, "blade.huan" :),
                (: perform_action, "blade.kuangdao" :),
                (: perform_action, "blade.shendao" :),
                (: perform_action, "blade.xueyu" :),
        
        }) );
 

	set_skill("force", 300);
	set_skill("unarmed", 300);
	set_skill("dodge", 300);
	set_skill("blade", 300);
	set_skill("feixian-steps", 300);
	set_skill("shenzhao-jing", 300);
	set_skill("xue-dao", 300);
	map_skill("force", "shenzhao-jing");
	map_skill("blade", "xue-dao");
	map_skill("parry", "xue-dao");
	map_skill("unarmed", "shenzhao-jing");
	map_skill("dodge", "feixian-steps");
	map_skill("dodge", "feixian-steps");
	map_skill("parry", "liancheng-jian");
	map_skill("sword", "liancheng-jian");  
	set("inquiry", ([
		"ˮ��" : (: ask_me :),
		"����":     (: ask_book :),
		"����":     (: ask_book2 :),
		"���վ�":     (: ask_book2 :),
		"����ɽ":     "����ɽ��������ҷ�ɱ�������ɡ�\n",
	]));
	set("wucan_count", 1);

        set_temp("apply/attack", 120);
        set_temp("apply/defense", 120);
        set_temp("apply/armor", 120);
        set_temp("apply/damage", 520);


	set("baodao_count",1);
	set("book_count",1);
	setup();
	carry_object("/clone/cloth/cloth")->wear();
	if (clonep())
	{
		weapon = new( __DIR__"xblade" );	
		if ( weapon->violate_unique() )
		{
			destruct( weapon );
			weapon = new( "/clone/weapon/changjian" );
		}
		weapon->move(this_object());
		weapon->wield();
	}
} 

string ask_me()
{
	mapping fam; 
	object ob;
	
	if (query("wucan_count") < 1)
		return "ˮ�Ϲ������ѩ������ң�";

	add("wucan_count", -1);
	this_player()->set_temp("marks/wucan", 1);
	return "ˮ�Ϲ������ѩ������ң�����ʲô�����Ӹ���ô��";
}
int accept_object(object who, object ob)
{
	object obj;
	int i;
        object me;
        me=who;
        if( !me || environment(me) != environment() ) return 0;
	if ( !objectp(ob) ) return 0; 
	if ( !present(ob, me) ) return notify_fail("��û�����������");
	if ( (string)ob->query("id") == "wan zhenshan") 
	{
		write(HIC "\n����˵������λ" + RANK_D->query_respect(me)+"����˴����£�����ʵ��֪����Ϊ����\n");
		write(HIC "\n���ƴ�ϲ�����������벻����Ҳ�н��죡����\n"NOR);
                call_out("destroying", 1, this_object(), ob);
		me->set_temp("marks/lianchenpu",1);
        return 1;
        }

	if (ob->query("id") != "da chang")
		return notify_fail("�����ⶫ����ʲô�ã�");
	message_vision("����Ц��˵������лл�㣡��λ" + RANK_D->query_respect(ob) +"���������ˡ���\n", who);
	if (!who->query_temp("marks/wucan"))
	{
		return 1;
	}
	obj = new(__DIR__"wucanyi");
	this_player()->delete_temp("marks/wucan");
	if ( obj->violate_unique() || uptime() < 300)
	{
		destruct( obj );
		return 1;
	}
	message_vision("���ƶ�$N˵����������ڲ���Ҳ������ʲô�������ı�����ɣ������ƴӻ����ͳ�һ�Ų����۵Ķ������ݵ�$N�����ϡ�\n", who);
	obj->move(this_player());
	return 1;
}



void do_kill(object ob)
{
	object me, room1;       
	me = this_object();
//	room1 = environment(me);
 
//	if (room1->query("no_fight"))
//	    room1->set("no_fight", 0);
 
	if (interactive(ob))
	{
		command("say ����������Ҵ��ҽ��׵����⣬������������\n");
		me->set_leader(ob);
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	}
 
}	


string ask_book2()
{
	object ob, me;
	int i;
	object fang;
	me = this_player();
	if (!me->query_temp("marks/lianchenpu",1)) return "���Ȱ��Ұ�����ɽ�����ץ���ɣ� \n";
	if (!me->query_temp("tssword",1)) return "������ҵ���ʫ��������? \n";
	
	  	if(((int)me->query("combat_exp",1)<=1000000))
	{
		message_vision("$N��$n˵���� ����书̫���ˣ����书�õ������ɣ�\n",this_object(),me);
                return " ��ȥ�ɡ�\n";	
	}
	
	  	if(((int)me->query("jinyong/book3")>=1))
	{
		message_vision("$N��$n˵���� �Ҳ����Ѿ�����ȥ�ȶ���������? \n",this_object(),me);
                return " ��ȥ�ɡ�\n";	
	}
	
	if((int)(me->query("shen")<100000))
		return "������ˣ���ʲô�ʸ�ȥ�ȶ����?\n";

   	else 
	{
        command("bow " + me->query("id"));
	message_vision("$N��$n˵���� ��л�������г��ˡ�\n",this_object(),me);
	message_vision("$N��$n˵���� �Ҵ�綡�䱻���ڽ���֪���У������ȥ�������ɡ�\n",this_object(),me);


	
	i = 200+random(800);
	me->set("jinyong/book3",1);
	me->add("combat_exp",i+9880);
	me->add("potential",i*12);
	me->add("mpgx",10);
	me->add("expmax",2);

	tell_object (me,"��Ӯ����"+chinese_number(i+9880)+"�㾭��"+
	           chinese_number(i*12)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");
	}

}


string ask_book()
{
	object ob, me;
	
	me = this_player();
	if (!me->query_temp("marks/lianchenpu",1)) return "��˵ʲô? \n";
	if((int)(me->query("shen")<100000))
		return "����������С֮�֣�����������ɽ�ڶ���\n";

   	else 
	{
		if(query("book_count") > 0)
		{		
		write(HIC "����˵��ת�������ɽʬ�����ѳ�һ���ƾ��鱾�����˸��㡣\n");
	    		call_out("waiting",0,me,ob);
			add("book_count", -1);
    			ob = new ("/clone/book/lian_book");
    			ob->move(this_player());
			command("rumor "+me->query("name")+"�õ����ǽ�������\n");
			return "�Ȿ���ǽ��ױ��⹷����ռ��ʱ�ˣ����ھ�������ɡ�\n";
		}
		else return "�������ˣ��������ǽ����Ѳ��ڴ˴���\n";
	}

}

void destroying(object me, object obj)
{
        destruct(obj);
        return;
}
