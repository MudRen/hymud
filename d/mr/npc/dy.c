// duanyu.c ����
// COOL@SJ,990827
#include <ansi.h>

inherit NPC;
string ask_duan1();
int ask_duan2();
void create()
{
        set_name("��������", ({"qingnian nanzi", "nanzi", "man"}));
        set("gender", "����");
        set("age", 20);
	set("long", 
		"����һ�����������������ӡ������Լ⣬����һ�������Ĵ�����\n");
        set("attitude", "peaceful");
        set("str", 12);
        set("per", 29);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set("chat_chance", 1);

        set("inquiry", ([
          "���" : (: ask_duan2 :),
           ]));

        set("jing", 10000);
        set("max_jing", 10000);
        set("jingli", 10000);
        set("max_jingli", 10000);
        set("qi", 20000);
        set("max_qi", 20000);
        set("neili", 3000);
        set("max_neili", 30000);
        set("jiali",50);
        
        set("combat_exp", 150000);
                 
        set_skill("force", 100);                
        set_skill("beiming-shengong", 120);     
        set_skill("dodge", 100);                
        set_skill("lingboweibu", 120);         
        set_skill("parry", 100);
        map_skill("force", "beiming-shengong");
        map_skill("dodge", "lingbo-weibu");
        setup();        
	carry_object("/clone/misc/cloth")->wear();        
}



int ask_duan2()
{
        object me,ob,obj,fang;
        int i;
        ob=this_player();
        me=this_object();
           if(!ob->query_temp("killtlbb6"))
{
message_vision("$N�����Ľ�ݹ������𣿡�\n", me, ob);
return 1;	
}     
       if(!ob->query_temp("killtlbb5") && !query("iskillok"))
      {
      message_vision("ͻȻ�Ӹ�������һ������ ˵���� ���������׽�������!\n",this_object(),ob);	
      	fang = load_object(__DIR__"jiumozhi");
	fang->move(environment(ob));	
	fang->kill_ob(ob);
     this_object()->set("iskillok",1);
     set("iskillok",1);
      return 1;
      }	
       
        
    if(!ob->query_temp("killtlbb5"))
{
message_vision("$N����ҶԸ��˴���������û�У���\n", me, ob);
return 1;	
}    

    

        
        if (ob->query_temp("killtlbb5") && ob->query("jinyong/book4")==3){
        message_vision("$N����������������Իر����Ժ󶨵�����\n", me, ob);
if((int)ob->query("jinyong/book4")==3)
{
 	i = 900+random(1200);
	ob->set("jinyong/book4",4);
	ob->add("combat_exp",i+9880);
	ob->add("potential",i*16);
	ob->add("mpgx",10);
	ob->add("expmax",2);


 message_vision("$N��������ȥ�������Ҵ�磬�п���Ҳ�������ɡ�\n", me, ob);
	tell_object (ob,"��Ӯ����"+chinese_number(i+9880)+"�㾭��"+
	           chinese_number(i*16)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");
}




                ob->start_busy(4);
                remove_call_out("dest");
                call_out("dest",3,me,ob);
                return 1;
        }
        else {
           message_vision("$N�ƺ����������˼��������Ҫ��˭��Ī��������ƭ�ҵģ���\n", me, ob);
        }
        return 1;
}

void dest(object me,object ob)
{      
       object room;

       destruct(me);
       return;
}

