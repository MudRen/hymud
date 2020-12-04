// Jay 3/17/96
#include <ansi.h>
inherit NPC;
int ask_supu();
int ask_parent();
int ask_gaochang();
inherit F_UNIQUE;
void create()
{
        set_name("������", ({ "li wenxiu", "li", "wenxiu"}));
        set("gender", "Ů��");
        set("title", "��ԭ�ϵ�������");
        set("unique", 1);
        set("age", 18);
        set("long", "
���ǰ���������Ů������С������������ԭ�ϡ���Ϊ������úã�
�����ǳ�֮Ϊ��ԭ�ϵ�����������ò��������ɫ�л�ɢ����һ�ɲ���Ӣ����\n");
        set("attitude", "friendly");
        set("combat_exp", 510000);
        set("shen", 5000);
        set("env/wimpy", 30);
        set("str", 19);
        set("int", 24);
        set("con", 22);
        set("dex", 26);
        set("max_qi", 9050);
        set("max_jing", 9050);
        set("neili", 8250);
        set("max_neili", 8250);
        set("jiali", 20);
        set_skill("cuff", 200);
        set_skill("taiji-quan", 205);
        set_skill("xinyuegong", 210);
        set_skill("force", 200);
        set_skill("taiji-shengong", 200);
        set_skill("parry", 200);
        set_skill("hammer", 200);
        set_skill("dodge", 200);
        map_skill("force", "taiji-shengong");
        map_skill("hammer", "xinyuegong");        
        map_skill("dodge", "xinyuegong");
        map_skill("parry", "xinyuegong");
        map_skill("cuff", "taiji-quan");        
        prepare_skill("cuff", "taiji-quan");
        set("inquiry", ([
             "����" : (: ask_supu :),
                "��ĸ" : (: ask_parent :),
            "��������" : "������������ÿͣ�����������ҵ����ơ�\n",
            "������" : "��үү���Ҵ�С����������Ψһ�����ˡ����ǵ�������ڲ�ԭ�Ķ������ϡ�\n",
            "��������" : "�ҵ����Ѿ����ˣ�������ǿ��ɱ���ġ�\n",
            "����С��������" : "������Ҳ���ˣ����ҵ���һ�𱻺����ġ�\n",
            "����ǿ��" : "�Ҳ�֪������ΪʲôҪɱ���Ұְ����裬���ǻ�Ҫɱ���ҡ�\n",
        ]) );
        set("chat_chance", 10);
        set("chat_msg", ({
            "����������س����������������װ����������꣬����������ͣ���\n",
            (: random_move :),  
            "���������������������ҹ����ɳĮ���У��Һ�������Ը��Ը�⣿��\n", 
            (: random_move :),
            "��������ų������������װ������������˭��˭��һʱ��֪����\n", 
            (: random_move :),
            "������ĸ�����������������Ҫ���ɳĮ��Ϊ��԰��ֻ��һ�Ժ��˾���һ�𡣡�\n",           
        }) );
        setup();
        carry_object(__DIR__"obj/chui")->wield();
        carry_object(__DIR__"obj/qun")->wear();
}

void init()
{
        object ob = this_player();
          if(environment(this_object())->query("short")=="��ʯΧ��"){
                set("chat_chance", 0);
                remove_call_out("back");
                call_out("back", 180, this_object());
                }
        if(interactive(ob) && !is_fighting() && ob->query_temp("li_meet") == 1
           && environment(this_object())->query("short") == "��ʯΧ��") {
                command("hi "+ (string)ob->query("id"));
                command("say ����ô��ô�ò�������");
                remove_call_out("greeting");
                call_out("greeting", 3, ob);
                }   
        if(interactive(ob) && !is_fighting() && ob->query_temp("li_meet") == 3) {
                command("xixi " + ob->query("id"));
                command("say ��ô������ûƭ��ɣ� ");
                }   
     add_action("do_yes","yes");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;                       
        message_vision("$N�����־��ֿ��˿������Ŷ�$n���ص�һЦ��\n",this_object(), ob);
        ob->add_temp("li_meet", 1);                
        command("whisper "+ob->query("id")+" �־�����ط���֪�������벻��(yes)ȥ������");
}

int do_yes()
{
   object me = this_player();
   if(me->query_temp("li_meet") != 2) return 0;
   message_vision(CYN"$N��æ��$n���˵�ͷ��������鷳�����ˡ�\n"NOR,me, this_object());
   me->set_leader(this_object());
   message_vision("$N������ʼ����$nһ���ж���\n",me, this_object());
   this_object()->set_temp("go", 1);	
   call_out("going", 4, this_object(), me);
   return 1;
}

void going(object ob, object me)
{
   ob->force_me("xixi " + me->query("id"));
   message_vision("$N��$nһ��������ɳĮ��ȥ��\n",me, ob);	
   ob->force_me("go north");
   ob->force_me("go north");
   destruct(ob);
}

int accept_object(object who, object ob)
{
        if( !who || environment(who) != environment() ) {return 0;}
        if ( !objectp(ob) ) {return 0; }
        if ( !present(ob, who) ) return notify_fail("��û�����������");
        if (userp(ob)) {
               command("? " + who->query("id"));
               command("say �����ѱ��˴��ΰ���");
               return notify_fail("��⣬�����ˣ�\n");
               }
        if ((string)ob->query("id") == "shou juan"){

        if ((int)who->query("jinyong/book6")==1 && !(int)who->query_temp("killltl3")) {
               command("? " + who->query("id"));
               command("say �Ȱ��Ұѳ´ﺣ�������ɱ�˰�");
               return notify_fail("���������� ���ڵ��Ļ��˵��£�\n");
               }

        if ((int)who->query("jinyong/book6")==1 && !(int)who->query_temp("killltl2")) {
               command("? " + who->query("id"));
               command("say �Ȱ��ҰѶ�ͬ�������ɱ�˰�");
               return notify_fail("���������� ���ڵ��Ļ��˵��£�\n");
               }

                command("ah "+(string)who->query("id"));
                command("say �����ҵ��־������ô�õ��ģ�\n");
                if(!ob->query("blooded")) who->set_temp("no_quest", 1); 
                set("chat_chance", 0);                              
                remove_call_out("ask_meet");
                call_out("ask_meet", 4, this_object(), who, ob);
            return 1;
        }        
        command("smile "+ (string)who->query("id"));
        command("say лл���������Ҳ�������Ķ�����");
        return 0;
}

void ask_meet(object me, object who, object ob)
{
int i;
    if(interactive(who) && !is_fighting()) {
      if(!who->query_temp("no_quest")){    
        command("Ү�����־��ϵĵ�ͼ������");
        command("say �����ɣ���һ���ȥ��ʯΧ�ӵ��ң�������Ҫ�Ȼؼ�����");      


        if(who->query("jinyong/book6")==1)
{
	i = 300+random(800);
	who->set("jinyong/book6",2);
	who->add("combat_exp",i+9880);
	who->add("potential",i*14);
	who->add("mpgx",10);
	who->add("expmax",2);
 message_vision(CYN"$N��$n˵������һ���л��ԵĻ��˲����Ǹ��ط���ҪС������\n"NOR, me, who);
	tell_object (who,"��Ӯ����"+chinese_number(i+9880)+"�㾭��"+
	           chinese_number(i*14)+"��Ǳ��"+"ʮ�����ɹ��� ����ɳ����ޣ���\n");
        who->save();
 }

        who->set_temp("li_meet", 1);
        message_vision("$N΢΢һЦ��ת���뿪�ˡ�\n",me);
        tell_room(environment(me), me->query("name")+"����ææ�����˹�����\n", ({me}));	
        me->move("/d/hj/room-ji1");
        remove_call_out("do_send");
        call_out("do_send", 60+random(100), me);
        me->set("chat_chance", 50);
        return;
        }
      else{
        who->delete_temp("no_quest");
        command("say лл����������һ��С���������°ɡ�");
        new("/d/hj/obj/hebao")->move(who);
        message_vision("$N΢΢һЦ������$nһ��С�ɰ�������ת���뿪�ˡ�\n",me, who);
        destruct(ob);
        me->set("chat_chance", 50);
        return;
        }
    }
    destruct(ob);
    me->set("chat_chance", 50);
}

void back(object me)
{
        command("say �������ǲ������á�");      
        message_vision("$N�������������죬ת���뿪�ˡ�\n",me);
        destruct(me);
        return; 
}

int do_send(object me)
{
    object where;
    where = environment(me); 
    if(where->query("short") == "��ʯΧ��") return 0;
    else {
       tell_room(environment(me), me->query("name")+"����ææ���뿪�ˡ�\n", ({me}));	
       me->move("/d/hj/hswz");
       tell_room(environment(me), me->query("name")+"����ææ�����˹�����\n", ({me}));	
       return 1;
       }
}


int ask_supu()
{
 say("��������Ȼ��˵�������Ҷ�ʱ�Ļ�飬�����ںͰ�����һ���ˣ�\n");
 this_player()->set_temp("marks/��1", 1);
 return 1;
}

int ask_parent()
{
object map;
object me;
me=this_player(); 

 say("������˵������ĸ֮�𣬲������졣\n");
 return 1;

}