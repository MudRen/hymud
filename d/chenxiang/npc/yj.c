 // (C)1998-2000 Tie Yu
#include <ansi.h>
inherit NPC;
int tell_him();
void create()
{
    set_name("Ԭ��", ({ "queen yuanji","yuanji" }) );
    set("gender", "Ů��" );
    set("long","Ԭ���ǵ�����ϵ��³裬������ò�Ƿ������һ�ͨ�������ʷ�顣\n");
    set("age", 25);
    set("combat_exp", 500);
    set("attitude", "friendly");
    set("per",30);
    set("chat_chance", 1);
    set("chat_msg", ({
        "Ԭ��������꣬�����̾�˿��������������ƺ��л������ĳ\n",
            }) );
    set("inquiry", ([
        "�岨����" : (: tell_him :),
        "qingbo" : (: tell_him:),
        ])); 
    setup();
    carry_object(__DIR__"obj/scloth")->wear();
} 
int tell_him()
{
    object me;
    me =this_player();
        if (me->query("m_success/����Ԭ��")==1) {
        message_vision("$N˵��лл������������žۡ�\n",this_object());
        return 1;
        }
        if (me->query("m_success/����Ԭ��")==2) {
        message_vision("$N���ĵ������ˣ����ˡ�\n",this_object());
        return 1;
        }
        if (me->query("m_success/����Ԭ��")==3) {
        message_vision("$Nŭ���������С�ˣ������Һ͹��ӡ�\n",this_object());
        this_object()->kill_ob(this_player());
        return 1;
   }
    
    tell_object(me,"Ԭ�������ؿ����㣺�㣮���㣮����ʶ�岨���ӣ�\n");
    tell_object(me,"Ԭ�����㷭���������ƣ���ָ��ָ�����ϴ���һ��СԲ���ӵ��������������
�岨���ӡ�\n");
    me->set_temp("marks/yuanji",1);
    return 1;
} 
int accept_object(object me, object obj)
{
    object ob; 
    if(me->query_temp("marks/ami") &&
       obj->query("real_lawan_id")==me->query("id"))
    {
        command("say ������̫���ˣ���л��λ" + RANK_D->query_respect(me) + "\n");
        command("say �����ڿ��Ժ��岨�����ž��ˣ�\n");
        ob = new(__DIR__"obj/mirror");  
        command("say �����ˣ�û��ʲô����л��ģ�����СԲ���Ӿ͸���������ɣ�\n");              
        if(!me->query("m_success/����Ԭ��")) {
            me->set("m_success/����Ԭ��",1);
            tell_object(me,HIR"��⿪������Ԭ��֮�ա�\n"NOR);
                        switch( random(4)){
                        case 0: me->add("score",1000);
                                tell_object(me,HIW"������������ˡ�\n"NOR);
                        case 1: me->add("max_neili",10);
                                me->set("Add_force",10);
                                tell_object(me,HIW"������������ˡ�\n"NOR);
                                break;
                        case 2: me->add("max_atman",5);
                                me->set("Add_atman",5);
                                tell_object(me,HIW"������������ˡ�\n"NOR);
                                break;
                        case 3: me->add("max_mana",5);
                                me->set("Add_mana",5);
                                tell_object(me,HIW"��ķ��������ˡ�\n"NOR);
                                break;
                        default: break;
                }
        }    
        ob->move(environment());
   me->delete_temp("marks/ami");
        me->delete_temp("marks/asked_yaofang");
        me->delete_temp("marks/yaofang");
        me->delete_temp("marks/qingbo");
        me->delete_temp("marks/yuanji");
        me->delete_temp("marks/jiuye");
        call_out("ddddd",1);
        return 1;
    }
    return 0;
} 
int ddddd()
{
    destruct(this_object());
    return 1;
}    
