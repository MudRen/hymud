// zhangcui.c
#include "ansi.h"
inherit NPC;
inherit F_MASTER;
string ask_huijia2()
{
 object ob,me=this_player();
 int i;
i=query_temp("marks/bing");
//if(!i=0)

if(!me->query_temp("marks/bing"))
{
write("лл�����޼ɻ���,�Ȿ�����������.\n");
ob=new("/d/binghuodao/npc/obj/force_book");
me->set_temp("marks/bing/zhang",1);
ob->move(me);
return "\n";
}
else 
{
return "�޼ɳ�ȥ��,��û����,���������Ұ�.\n";
}
}



string ask_huijia()
{
 object me,ob,ob1,ob3;
int a,b;
// object *ob_list;
// int i;
int i;
me=this_player();
a=me->query_temp("marks/bing");
b=me->query("mufa");
//if(a=0)
if(!me->query_temp("marks/bing"))
{
return "�޼��ҵ�����?\n";}
//else if(!me->query_temp("marks/bing"))
else if(!me->query("mufa"))
{return "ľ���������.\n";}
else
{ob=new("/d/binghuodao/npc/zhangcui");
ob->move("/d/binghuodao/road11");
ob1=new("/d/binghuodao/npc/susu");
ob3=new("/d/binghuodao/npc/wuji");
ob1->move("/d/binghuodao/road11");
ob3->move("/d/binghuodao/road11");
write("�����߰�.\n");
destruct(present("mufa",me));
ob->move("/d/binghuodao/mufa");
ob1->move("/d/binghuodao/mufa");
ob3->move("/d/binghuodao/mufa");
me->move("/d/binghuodao/mufa");
me->delete_temp("marks/bing");
me->delete("mufa");
tell_object(me, BLU "���ں��Ϻ����˺ܾúܾ�.......\n" NOR ) ;
call_out("goto_taohua",20,me);
}
return "�߰�.\n";
}
void goto_taohua (object ob)
{
object ob1,ob2,ob3;   
object who;
int i;
who=ob;
tell_object(ob , "������ͣ����һ����ۡ������´�����\n" ) ;
   ob->move ("/d/tanggu/gangkou") ;
ob2=new("/d/binghuodao/npc/zhangcui");
ob2->move("/d/tanggu/gangkou");
ob1=new("/d/binghuodao/npc/susu");
ob1->move("/d/tanggu/gangkou");
ob3=new("/d/binghuodao/npc/wuji");
ob3->move("/d/tanggu/gangkou");
destruct(ob1);
destruct(ob2);
destruct(ob3);

  	if(!who->query("jinyong/book12") && who->query("combat_exp",1) > 500000)
{
		i = 900+random(2000);
		who->set("jinyong/book12",1);
		who->add("combat_exp",i+9000);
		who->add("potential",i*18);
		who->add("mpgx",10);
		who->add("expmax",2);
		//command("chat "+this_player()->query("name")+"��ɫ���ˣ������Ƕ�ԡ�");
		tell_object (who,"��Ӯ����"+chinese_number(i+9000)+"�㾭��"+
		           chinese_number(i*18)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");
		who->save();
}

tell_object(ob,"лл������ǻص�����.����Щ��������.���Ǿʹ˸��.\n");
//tell_object(ob,"���Ǿʹ˸��.\n");
if(!ob->query("send_zhang"))
{ob->set("send_zhang",1);
ob->add("combat_exp",500);}
else {ob->add("combat_exp",1);}
ob->delete("mufa");
ob->delete_temp("marks/bing");
}

string ask_zhaochuan()
{
object me;
me = this_player () ;

if (!present("mu chai", me) && !present("chang teng",me))
{
//write("������û�в��ϣ�\n");
return "������û�в��ϣ�\n";
}
if (present("mu chai", me) && present("chang teng",me))
{
write("һ��ľ������֪ͨ��.\n");
destruct(present("mu chai",me));
destruct(present("chang teng",me));
call_out("make_chuan",20,me);
return "һ��ľ������֪ͨ��.��\n";

}
}

void make_chuan(object who,object me)
{
object ob;
me = this_player () ;
tell_object(who,"������.\n");
ob=new("/d/binghuodao/npc/obj/chuan");
ob->move(me);
//ob->move("/d/binghuodao/road11");
me->delete_temp("teng");
me->delete_temp("mutou");
me->set("mufa",1);
}



void create()
{
set_name("�Ŵ�ɽ", ({ "zhang cuishan", "zhang" }));  
set("nickname","�䵱����");
        set("long", 
                "�����������������ӡ��䵱����֮�е��Ŵ�ɽ��\n"
                "��һ���ɸɾ����İ�ɫ���ۡ�\n");
        set("gender", "����");
        set("age",31);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 28);
        set("int", 35);
        set("con", 28);
        set("dex", 28);
        set("max_qi", 5000);
        set("max_jing", 5000);
        set("neili", 5500);
        set("max_neili", 5500);
        set("jiali", 150);
        set("combat_exp", 1500000);
        set("score", 600000);
        set("per", 28);

        set_skill("force", 200);
        set_skill("taiji-shengong", 200);
        set_skill("dodge", 180);
        set_skill("tiyunzong", 180);
        set_skill("unarmed", 200);
        set_skill("taiji-quan", 200);
        set_skill("parry", 200);
        set_skill("sword", 200);
        set_skill("taiji-jian", 200);
        set_skill("taoism", 200);
        set_skill("literate", 200);

        map_skill("force", "taiji-shengong");
        map_skill("dodge", "tiyunzong");
        map_skill("unarmed", "taiji-quan");
        map_skill("parry", "taiji-quan");
        map_skill("sword", "taiji-jian");

        create_family("�䵱��", 2, "����");
set("inquiry", ([
        "���޼�" : (:ask_huijia2:) ,
        "������" : (:ask_huijia:) ,
        "�촬" : (:ask_zhaochuan:) ,
         ]) );
        setup();

        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.zhen" :),
                (: exert_function, "recover" :),
        }) );

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/binghuodao/npc/obj/skin")->wear();

}
void attempt_apprentice(object ob)
{
                command("say ����������Ŀ�ٻ�ȥ��ʦ�������˼��ˣ���λ�����ͽ��");
                return;

}
