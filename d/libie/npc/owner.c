#include <ansi.h>
inherit NPC;  
void create()
{
        set_name("��ջ�ϰ�", ({ "lao ban","owner" }) );
        set("long",
                "һ���ʷ����ֵ������ˡ�"); 
        set("attitude", "friendly"); 
        set("str", 20);
        set("cor", 10);
        set("agi", 10); 
        set("combat_exp", random(5000)); 
/*      set_skill("unarmed",150);
        set_skill("parry",150);
        set_skill("dodge",150);
*/      
        set("chat_chance", 1);
        set("chat_msg", ({
"�ϰ���Ź�̨̾������˵�ͷ��ô�õ��ˣ���ô���ǽ��ڴ���أ�\n"
        }) );
        set_temp("����",10);
        
        
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
} 
void init()
{
        ::init();
    add_action("do_give","give");
} 
int do_give(string arg)
{       string objectname, acceptor;
        object ob,who,cloth;
        int val;
        
        if( sscanf(arg, "%s to %s", objectname, acceptor)<2 ) 
                return 0;
        if(acceptor!="��ջ�ϰ�"&&acceptor!="lao ban"&&acceptor!="owner")
                return 0; 
   who=this_player();
        ob=present(objectname,who);
        if(!objectp(ob)) return 0;
        val=ob->value();
        if (!val) return 0;
        if ((val<10000) ||!query_temp("����"))
        {
        message_vision(YEL "��ջ�ϰ�ڰ���Ц��������ô�ҵ���\n"NOR,who);
                return 1;
        }
        add_temp("����",-1);
        message_vision("$N�ó�"+ob->query("name")+"����ջ�ϰ塣\n",who);
        destruct(ob);
    message_vision(HIY "��ջ�ϰ�Ц���Կ�������˵������˵��˵��\n",who);
    tell_object(who,HIY "��ջ�ϰ���㸽��˵������λ"+RANK_D->query_respect(who)+"�����С��ү��û���⣬��������Ϳ����ˡ�\n");
        tell_object(who,HIY"��ջ�ϰ�ݸ���һ����С����װ����\n"NOR);
        cloth=new(__DIR__"obj/waitercloth");
        cloth->move(who);
        who->set_temp("libie/��������",1);
        return 1;
}
        
/*
int accept_object(object who, object ob)
{       
        int val;
        val=ob->value();
        if (val>10000)
        {
                say(HIG"�ϰ�Ц���Կ���������ͷ��������˵��˵����ʲôҪ���еģ���\n"NOR);
                add_action("do_answer","answer");
        }
*/   
