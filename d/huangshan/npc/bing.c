 inherit NPC;
#include <ansi.h>
void create()
{
        set_name("����", ({ "bingbing","bing" }) );
        set("gender", "Ů��" );
        set("age", 15);
        set("per", 37);
        set("attitude", "peaceful");
        set("chat_chance", 10);
        set("chat_msg", ({
                (: random_move :),
        }) ); 
        set("long",     "��ʵ���Ǹ�����������Ϊ�ٵ�Ů�ˣ��������ᣬ�ǳ����ᡣ
����Ƥ����΢�Ե�̫�԰���һЩ��ȴʹ����������������
�����۾�Ҳ���Ǻ��Ӱ㴿��������ȴ�ִ�����˵������������\n");
        setup();
        carry_object("/clone/misc/cloth")->wear();
}
void init()
{
        object me;
        me = this_player();
        if(interactive(me) 
        && me->query_temp("friend_to_xiao")) call_out("ask_him", 1,me );  
} 
int ask_him(object me)
{
        if(environment(me) == environment())
        {
        tell_object(me,name()+"�����Ҹ����ң����Ȼ���ˣ�����������ܵ�����
��û���߽⡣\n");
        me->set_temp("listened",1);
        };
return 1;
}       
