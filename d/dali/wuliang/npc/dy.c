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
        set("long", "����һ���������ӣ���ͷɢ������������������ֻϵ��һ���̿㣬¶��\n"
                    "���������ȣ������Լ⣬�����ƺ���Щ����\n");
        set("attitude", "peaceful");
        set("str", 12);
        set("per", 29);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set("chat_chance", 1);

        set("inquiry", ([
          "����" : (: ask_duan1 :),
          "name" : (: ask_duan1 :),
          "���" : (: ask_duan2 :),
          "����" : (: ask_duan2 :),
          "�ȶ���" : (: ask_duan2 :),
          "������" : (: ask_duan2 :),
          "���" : (: ask_duan2 :),
          "���" : (: ask_duan2 :),
          "save" : (: ask_duan2 :),
          "������" : "���������ҹؽ����ġ�\n",
          "��ʦ" : "��....���ҵ�ʦ�������ӡ����Ӻ�ׯ�ӣ����ǵ�ѧ���һ�ûѧȫ�ء�\n",
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
}

string ask_duan1()
{
        object me,ob;
        ob=this_player();
        me=this_object();
          me->set_name("����", ({ "duan yu", "duan","yu"}) );
          me->set("title","���������������");
          ob->set_temp("duanyu/answer1",1);
          return "���±��Ƕ�����";
}

int ask_duan2()
{
        object me,ob,obj,fang;
        int i;
        ob=this_player();
        me=this_object();
        
        
    if(!ob->query_temp("tlbb11"))
{
message_vision("$N�ҵ�����ľ�������ã���������Ϣ�˲�����\n", me, ob);
return 1;	
}    
        
    if(!ob->query_temp("tlbb12"))
{
message_vision("$N�ҵ������������ã���������Ϣ�˲�����\n", me, ob);
return 1;	
} 
        
        if (ob->query_temp("duanyu/answer1") && ob->query("dali/pass")){
        message_vision("$N����������������Իر���׳ʿ��ѧ��֮�ˣ��������о���������\n"
                +"������ã����������㣬�Ա���֮л�⡣��˵�꣬$N�ӻ�������һ�����¡�\n"
                +"ͻȻ��$N��ʧ��ɫ������Ӵ����ô����������ӣ����ˣ����ˣ�Ī�����⣿����\n"
                +"��ȥ�ɣ��������پͿ�����컯�ˡ�˵�꣬$N��������$n��\n", me, ob);
                obj=new(__DIR__"obj/dodge_book");
                obj->move(ob);
if (!ob->query("dali/meet_dy1"))
{
ob->add("kar",2);
ob->add("per",1);
}
if((int)ob->query("jinyong/book4")==1)
{
 	i = 800+random(800);
	ob->set("jinyong/book4",2);
	ob->add("combat_exp",i+9880);
	ob->add("potential",i*13);
	ob->add("mpgx",10);
	ob->add("expmax",2);



	tell_object (ob,"��Ӯ����"+chinese_number(i+9880)+"�㾭��"+
	           chinese_number(i*13)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");
 message_vision("$N��$n˵�����п����������������Ұɡ�\n", me, ob);

      	fang = load_object(__DIR__"nan");
	fang->move(environment(ob));	
	fang->kill_ob(ob);
      	fang = load_object(__DIR__"ye");
	fang->move(environment(ob));	
	fang->kill_ob(ob);
      	fang = load_object(__DIR__"yun");
	fang->move(environment(ob));	
	fang->kill_ob(ob);
}

                ob->delete_temp("duanyu/find2");
                ob->delete_temp("duanyu/answer1");
                ob->set("dali/meet_dy1",1);
                ob->start_busy(4);
//                log_file("quest/lbwb",sprintf("%s(%s)�Ӷ�����ѧ���貨΢���ڣ�%s\n",ob->name(1), capitalize(getuid(ob)), ctime(time())));
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
       room = find_object("/d/dali/wuliang/muwu3");
       room->set("exits/down", "/d/dali/wuliang/midao1");
       
       message_vision("$n��Ȼ�����������������ɣ�������������������˴ӵ������˳��� \n"
       +"$n��ϸһ����ԭ���Ǵ�����Ļ����ޡ�����ʯ�ͷ��衣������ǰ����� \n"
       +"���˸���,���������ӣ��������������ˡ����۽�һƳ��������$n������\n"
       +"��������λ̨�֣�����������������λ̨��Ҳ�������ҵģ���ɱ���Ĵ����\n"
       +"��ǰ���ƿ���ʯ���롣�������͡������������־����壬������������ġ�\n"
       +"����˵����ڶ࣬���»�����Ԯ���������˵ز��˾������������Ҵӵص���\n"
       +"�Ͻ��뿪�ɡ������˵�ͷ���ǣ����Ƿ����͡������������µص��뿪����\n", me, ob);
       destruct(me);
       return;
}

