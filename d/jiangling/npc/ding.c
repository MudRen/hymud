//Edited by fandog, 01/31/2000

inherit NPC;
#include <ansi.h>
void destroying(object, object);

void create ()
{
	set_name("����", ({"ding dian","ding","dian"}));
	set("long", "
����������ף�ͷ��������ֱ���������������ò�������ֱ��ͬ��ɽ��
��Ұ�ˡ����������������ͣ����ù��д������������������ϡ����ϡ�
���ϣ����ǿ���޴��Ѫ�ۡ�\n");
	set("gender", "����");
	set("age", 30);
	set("combat_exp", 5000000);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 28);
	set("per", 24);
        set_skill("parry", 380);
	set_skill("force", 380);
	set_skill("unarmed", 380);
	set_skill("dodge", 380);
	set_skill("taixuan-gong", 550);
	set_skill("feixian-steps", 580);
	set_skill("shenzhao-jing", 580);
	map_skill("force", "shenzhao-jing");
	map_skill("parry", "taixuan-gong");
	map_skill("unarmed", "shenzhao-jing");
	map_skill("dodge", "feixian-steps");
	set("chat_chance", 10);
	set("chat_msg", ({
"��������̾��һ��������̾Ϣ�У��������ˡ�����֮�⡣\n",
"������ǹ���һ˿΢Ц������Զ����¥ɴ������һ���ʻ���\n",
"�������������ô�����ǣ�������ģ��ѵ������ѵ������˲���\n",
"�����૵������������˲���Ҳ���������������\n",
}) );
	set("inquiry", ([
		"��˪��" : "������������Ȼ��ָ��ָ��������С¥�Ĵ��ڣ�ɶҲ��˵�ˡ�\n",

	]));
    set("max_neili",80000);
        set("neili",80000);
        set("max_qi",36800);
        set("max_jing",36800);
        set("jing",36800);
        set("qi",36800);
        set("eff_jingli",38000);
        set("jingli",38000);
        set("jiali",100);
	set("szj/passed", 1);
	set("szj/over200", 1);
	set("book_count", 1);
	set("chat_chance_combat", 90);
       set("chat_msg_combat", ({
                (: perform_action, "unarmed.wu" :),
                (: perform_action, "unarmed.ying" :),
                (: perform_action, "parry.po" :),
                (: perform_action, "parry.jing" :),
                (: perform_action, "parry.xuan" :),
                (: perform_action, "parry.po" :),
                (: perform_action, "parry.taixuan" :),
               
        }) );
	set_temp("apply/attack", 200);
	set_temp("apply/defense", 200);
	set_temp("apply/armor", 2000);
	set_temp("apply/damage", 2000);
        set("combat_exp", 9900000);
        set("shen_type", 1);
	setup();
	carry_object("/d/jiangling/obj/qiuyi")->wear();
}




int accept_object(object me, object obj)
{
	int i;
	object fang;
	object who;
	object where = environment(me);
	who=me;
        if ((string)obj->query("id")=="lu juhua") {
        message("vision",me->name()+"������һ���̾ջ���\n",environment(me),
            ({me}));
        if(!this_object()->query("book_count")) {
		command("say ���Ѿ����˸�˪���ӻ��ˣ�����������ˡ�");
		return 0;
	}
        command("touch "+me->query("id"));
        command("say ��λ"+RANK_D->query_respect(me)+"��˪���������ӻ��İ�,�ˣ����ǿ��ǿ�����ԧ�졣");

      if(!query("iskillok"))
      {
      message_vision("ͻȻ������ͻȻɱ������Ѫ������ɮ ��$n˵���� �����վ���������!\n",this_object(),who);	
      	fang = load_object(__DIR__"baoxiang");
	fang->move(environment(who));	
	fang->kill_ob(who);
      	fang = load_object(__DIR__"shanyong");
	fang->move(environment(who));	
	fang->kill_ob(who);
     this_object()->set("iskillok",1);
     set("iskillok",1);
      return 0;
      }	


        fang = present("shan yong",where);
	if(fang)
	{
		who->start_busy(3);
		message_vision("$N��$n˵���� ��λ"+ RANK_D->query_respect(who) +"�Ȱ���ս�����°ɡ�\n",this_object(),who);
		return 0;
	}

        fang = present("bao xiang",where);
	if(fang)
	{
		who->start_busy(3);
		message_vision("$N��$n˵���� ��λ"+ RANK_D->query_respect(who) +"�Ȱ���ս�ܱ���ɡ�\n",this_object(),who);
		return 0;
	}
	
		  	if((!(int)who->query_temp("killxs2")))
	{
		message_vision("$N��$n˵���� ����ҶԸ�����������?\n",this_object(),who);
		return 0;	
	}
	
		  	if((!(int)who->query_temp("killxs1")))
	{
		message_vision("$N��$n˵���� ����ҶԸ��˱�������?\n",this_object(),who);
		return 0;	
	}
	

	  	if(((int)who->query("jinyong/book3")==1))
	{
command("thank " + who->query("id"));
	message_vision("$N��$n˵���� ��л$n�����Ҵ����������ɮ��\n",this_object(),who);
	message_vision("$N��$n˵���� ��Ѫ������������ ϣ��$n���Ұ����˽��˰ɡ�\n",this_object(),who);
	
	i = 400+random(800);
	who->set("jinyong/book3",2);
	who->add("combat_exp",i+10880);
	who->add("potential",i*12);
	who->add("mpgx",10);
	who->add("expmax",2);

	tell_object (who,"��Ӯ����"+chinese_number(i+10880)+"�㾭��"+
	           chinese_number(i*12)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");
	who->save();	
	}
		if (present("shenzhao jing", me)) {
		command("say �����ϲ����������վ���");
		return 0;
	}


	if (!present("shenzhao jing", me)) {
		if (me->query("szj/passed")) {
		        new("/clone/book/shenzhao-jing")->move(me);
	        	message_vision("$n�ݸ�$Nһ�����վ���\n", me, this_object() );
		        command("say ��λ"+RANK_D->query_respect(me)+"����̫��л����,�Ȿ�ڹ��ķ�ϣ�����ܺú���ϧ��");
			this_object()->set("book_count", 0);
		} else if ((int)me->query("szj/failed") < 4 && me->query("kar") > 40 && !random(30)) {
		        new("/clone/book/shenzhao-jing")->move(me);
	        	message_vision("$n�ݸ�$Nһ�����վ���\n", me, this_object() );
		        command("say ��λ"+RANK_D->query_respect(me)+"����̫��л����,�Ȿ�ڹ��ķ�ϣ�����ܺú���ϧ��");
			this_object()->set("book_count", 0);
			me->delete("szj/failed");
			me->set("szj/passed", 1);
		} else {
			command("sigh "+me->query("id"));
			command("say �����޳��ʵ��ûʲô���Ը�����ˡ�");
			if (me->query("szj/failed") < 5)
				me->add("szj/failed", 1);
		}
	}
        remove_call_out("destroying");
        call_out("destroying", 1, this_object(), obj);
        return 1;
        }
        return 0;
}

void destroying(object me,object obj)
{
        destruct(obj);
        return;
}
