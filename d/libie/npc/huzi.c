#include <ansi.h>
inherit NPC;
void wake();
int cured(); 
void create()
{       set_name("С����", ({ "xiao huzi", "huzi" }) );
        set("long",                "����һ����ͺ���Ĳ��죬���Ѿ�������Ѫ������һϢ�ˣ�\n�����ƺ������Ծ��Σ�����죩������ϣ����������֮ǰ�ܸ�����˭�����֡�\n");
        set("attitude", "heroism");
        set("age", 17);
        set("str", 27);
        set("cor", 26);
        set("cps", 25);
        set("con", 1);
        set("jing", 100);
        set("qi", 100);
        set("jing", 100);
        set("eff_jing", 100);
        set("eff_qi", 100);
        set("eff_jing", 100);
        set("title", "����");
        set("disable_type", HIR "<���Բ���>"NOR);
        set("combat_exp", random(10000)); 
        set_skill("unarmed", 70+random(100));
        set_skill("staff", 70+random(100));
        set_skill("parry", 70+random(100));
        set_skill("dodge", 70+random(100));
        set_skill("move", 100+random(100)); 
        set_temp("apply/attack", 70);
        set_temp("apply/dodge", 70);
        set_temp("apply/parry", 70);
        set_temp("apply/damage", random(100));
        set_temp("apply/armor", 70);
        set_temp("apply/move", 100);
        set("chat_chance", 1); 
        setup();
                this_object()->disable_player(" <���Բ���>");
                this_object()->set_temp("is_unconcious",1);
                set_temp("block_msg/all", 1);
} 
void init()
{
    ::init();
        if(!this_player()->query_temp("libie/���_����ʬ��")) {
                call_out("die", 1, this_object());
    } else {
            call_out("die", 60, this_object());
    }
}
 
void heart_beat()
{
        object ob,me,room;
         
        room=environment();
        ob=this_object();
        me=ob->query("������");
        if(living(ob))
        if(present(me,room))
        {       
                
                if(!me->query_temp("libie/���_��С����"))
                        {
                        me->set_temp("libie/���_��С����", 1);
                message("vision",HIR"\n����ԡѪ��С�����۵����һ�����Ѫ����ȵ���������ߡ��� �����߰���\n�԰�С�����ֻ��˹�ȥ��\n"NOR, me);
                        ob->disable_player(" <���Բ���>");
                        ob->set_temp("is_unconcious",1);
                        }
                else    {
                        message_vision(HIR"С����������ת�����³�����Ѫ������ס$N������������\n"NOR, me);
                if( (me->query("combat_exp") > 800000))
                                {
                                message_vision(HIR"��λ" + RANK_D->query_respect(me) + "������Σ������������ȥ...��..��..\n"NOR, me);
                                me->set("libie/���_С���ӵľ���", 1);
                                }
                        else    message("vision",HIR"��л��λ" + RANK_D->query_respect(me) + "��...��...����...����...����...\n"NOR, me);
                        if( !me->query("libie/���һ"))
                                {
                                me->set("libie/���һ",1);
                                me->add("score", 100);
                    me->add("combat_exp", 500);
                                }
                        ob->die();
                        }
        }
        else ob->unconcious();
        ::heart_beat();
}     
