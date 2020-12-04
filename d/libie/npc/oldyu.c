#include <ansi.h>
inherit NPC; 
int lian();
int yang();
int killhim(); 
void create()
{
        set_name("����ͷ", ({ "old yu", "yu" }) );
        set("gender", "����" );
        set("age", 65);
        set("str", 27);
        set("max_qi", 2000);
        set("int", 12);
        set("per", 10);
        set("long", @LONG
һ���׷��ԲԵ����ߣ������������㣬�ƺ��л�Ҫ˵��
LONG
);
        set("attitude", "peaceful"); 
        set("combat_exp", 10000);
        set("bellicosity", 0);
        set("chat_chance", 1);
        set("chat_msg", ({
"����ͷ��������������ʯ�������ţ�����һ����Ʈ�䣬�ճյ���
С�����ɵû��Ż��������������޶����������ڵ��㰡������\n"
        }) );
        set("inquiry", ([
                "����" : (: lian :),
                "lian gu" : (: lian :),
                "���" : (: yang :),
                "yang" : (: yang :),
                "yang zheng" : (: yang :),
                "������" : (: killhim :),
                "di" : (: killhim :),
                "di qinglin" : (: killhim :),
        ]));
        set("��",1);
        setup(); 
        add_money("coin", 50); 
        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/bishou2")->wield();
}
int accept_fight(object me)
{
        command("say ��ͷ�����������Ķ��֣�");
        return 0;
}
 
int lian()
{
    message_vision("����ͷ����Ť��ͷȥ�������ڻ����ֵ��������ţ������˲�ˮ�����д���λ" + RANK_D->query_respect(this_player()) + "��\n", this_player());
    return 1;
} 
int killhim()
{
    message_vision(HIR"\n����ͷһ�㣬������ȳ������һ���ʹ�\n����ͷ�޺������ڰ�����ƴ�ˣ���ԩ���Ҽ�С��޼ҿɹ飬\n�ֺ��������ǿ����Ĺ�Ů�����ڸ���ƴ�˰�������\n\n"NOR, this_player());
    this_player()->receive_wound("qi", this_player()->query("eff_qi")/2);
    return 1;
} 
int yang()
{
    string msg; 
         
    if( this_player()->query_temp("libie/���_����"))
    {
        message_vision(HIY"����ͷãȻ��˵�����Ų��Ǹ��������ѵ����ϴ����ˣ�\n"NOR,this_player());
        return 1;
    }
    if( !this_player()->query("marks/���"))
    
    
    {
        msg =HIY "����ͷ���Ǻǡ�ɵЦ�������������Ҽ�С�����ǰ�����ȥ�참�ˣ�\nȥץһ������������������ʲô�����ү��"NOR;
        if (query("��"))
        {
            msg += HIY"���ˣ������ﻹ��С��ŵ�һ\n���š�˵�Ǹ�һλ����ʿ����" + RANK_D->query_respect(this_player()) + "��ô����answer yes or no��\n"NOR;
                add_action("do_answer", "answer");
        }
        msg += "\n";
        message_vision(msg,this_player());      
        return 1;
    }
    
    
        message_vision(HIY"����ͷ������̧ͷ�ʵ�����λ" + RANK_D->query_respect(this_player()) +"�ǡ�������\n"NOR, this_player());
        return 1;
    
     
} 
int do_answer(string arg)
{
    if( arg == "no" )
    {
        message_vision(MAG"\n$Nɦ��ɦͷ��С������" + RANK_D->query_self(this_player()) + "���������У��θ�����ʿ�Ծӡ�\n"NOR, this_player());
        message_vision(MAG"����ͷĿ��ͣ�ͣ�����̾�˿�����תͷ���\n"NOR, this_player());
        this_player()->delete_temp("libie/���_С���ӵľ���");
        this_player()->set("marks/���","ʧ��");
        return 1;
    }
    else if( arg == "yes" )
    {
        message_vision(GRN "\n$N�����������һ���ִ����" + RANK_D->query_self(this_player()) + "���䲻�ţ��������Σ�������ұ�����֮�£�\n\n"NOR, this_player());
        
        if (this_player()->query("combat_exp")<1000000) {
                message_vision(HIC"����ͷ�ֿ��˿�$N��̾�˿���˵���������㣬�Ҳ����ġ���\n"NOR,this_player());
                return 1;
                } 
        if(!this_player()->query("libie/���_��������ͷ"))
        {
                this_player()->set("libie/���_��������ͷ", 1);
                this_player()->add("score", 100);
                this_player()->add("potential", 100);
        }
        message_vision(HIY"����ͷ��ʱϲЦ�տ���Ĩ���۽ǵ��Ứ��������ʿ���������ҽ������ž������棬��\n�Ͽɵ��ҵ��Ҽ�С�������װ���\n����ͷת��������ݡ�\n"NOR,this_player());
        this_player()->set_temp("libie/���_ȡ��",1);
        this_object()->move("/d/libie/neishi");
        return 1;
    }
    else
    return 0;
} 
int give_letter(object me)
{       object letter;
        
        if(!present(me,environment())) return 0;
    message_vision(HIR"����ͷ��ΡΡ�ĵݸ�$Nһ���ţ�����ʿ�Ĵ����£�С�϶�Ω����������λ����ܱ����ˡ�\n"NOR,me);
        letter=new(__DIR__"obj/letter");
        letter->move(me);
        letter->set("������",me);
        this_object()->delete("��");
        me->delete_temp("libie/���_ȡ��");
        me->set_temp("libie/���_����",1);
        return 1;
}          
