#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("������", ({ "zhu qiqi","zhu" }) );
        set("gender", "Ů��" );
        set("title", "�����С��" );
        set("nickname", HIC"��������������"NOR );
        set("long",
                "���°�ȹ��һ������ȴ����͸�죬��̬��ȣ����ݽ�������ʵ���޷����ݣ�\n�����ۼ���˭Ҳ�����˼侹����˾�ɫ��\n"
                );
        set("attitude", "peaceful");
        set("class","legend");
        set("age", 19);
//      set("str", 15);
        set("cps", 15);
        set("int", 0);
        set("per", 70);
        set("combat_exp", 600000);
/*        set("force", 200);
        set("max_force", 200);
        set("mana", 100);
        set("max_mana", 100);
        set("max_kee", 400);
        set("max_gin", 400);
        set("max_sen", 400);
        set("force_factor", 10); */
        set("chat_chance", 1);
        set("chat_msg", ({
                "��������Ŀ���ᣬ������������Ĺ���û���ĵģ�����ǰ׷ɷɣ�������ô�ˡ����� \n",
                "�����߲��˲����ᣬ�૵�����è����è���Ƥè����Ҫ����ͷ�ֲ�֪�����Ķ�ȥ�ˣ�\n",
                "��������ĿԲ��������һ������������Ҫ����������������ħ���ã����������ᱻץס��\n",
                }) ); 
        set_skill("unarmed", 150);
        set_skill("dodge", 150);
        set_skill("parry", 150);
        set_skill("move", 150);
        set_skill("fall-steps", 100);
        set_skill("meihua-shou", 100);
        map_skill("dodge", "fall-steps");
        map_skill("unarmed", "meihua-shou");
        set("chat_chance_combat",50);
        set("chat_msg_combat",({
                      (:perform_action,"dodge.luoyeqiufeng":),
        }));
                
        setup();
        carry_object("/clone/misc/cloth")->wear();
} 
int accept_object(object me, object obj)
{       
        if( obj->query("name") == WHT"���"NOR && obj->query("owner") == "����" )
        {
                message_vision("$N�����赣���ϲ�������۵ÿ޳�����������\n",this_object());
                if(me->query_temp("marks/chai_get_jade"))
                {
                        message_vision("$N��$n˵���������ң���Ҫ�����˱��׷ɷɸ�ƭ�ˣ�����\n",this_object(),me);
                        me->set_temp("marks/jade_to_zhu",1);
                        me->delete_temp("marks/chai_get_jade");
                        return 1;
                }
                else
                {
                        tell_object(me,"��������Ŀ���᣺����û��������...��...\n");
                        return 1;
                }
        }
        else
        {
                tell_object(me,"������ҡ��ҡͷ������������һ�ۣ�\n");
                return 0;
        }       
}
