#include <ansi.h>
inherit NPC;
int qi_yun();
void create()
{
        set_name(HIC"������"NOR, ({ "silver ant", "ant" }) );
        set("long",
                "�����ϴ��ż������������·������ϻ����Ÿ�����ߣ����������Ǹ�\n�ð������ɵ�С���֣�ʵ��˵�����Ĺ��ؿɲ���\n");
        set("chat_chance",2);
        set("chat_msg", ({
                "������̧ͷ���������ϵİ��ƣ���̾һ����������ʮ�����ˣ���Ȼ��\n��ǹ���룬�ݺ��ĺ���������ȴ�������Խ�ղ�������Ԫ������̹�\n�������޷��ñ����������ˣ�����ʲô��Ȥ���ԡ���\n",
                "�����Ϻݺݵ��������˵Ľ�ղ�����ôǿ�������װ����ܴ�������͵�㱦�������Ҳ�á���\n"
                                })  ); 
        set("combat_exp", 200000 + random (80000));
        set("max_jing",900);
        set("max_qi",1800);
        set("max_jing",900);
        set("int",38);
        set("str",24);
        set("cor",35);
        
        set_skill("iron-cloth",100);
        set_skill("jin-gang",50);
        set_skill("unarmed",120);
        set_skill("bloodystrike",100);
        map_skill("iron-cloth","jin-gang");
        map_skill("unarmed","bloodystrike");
        set("chat_chance_combat",25);
        set("chat_msg_combat",  ({
                        (:perform_action,"unarmed.fefawubian":),
                }));
/*        set("inquiry", (
                "��ɽ" : (: qi_yun :),
                "lsb" : (: qi_yun :),
                "nndx" : (: qi_yun :),
                "����ʹ" : (: qi_yun :) 
        ]))
*/
        
        setup();
        carry_object("/clone/misc/cloth")->wear();
} 
int accept_object(object who, object ob)
{       
        object jinlian;
        if (ob->query("id")=="9-ring staff") 
        {
                this_player()->set_temp("marks/������",1);
                write("����������һ�£�ϲ���ݺᣬ������������������ɱ���Ǹ����ĸ���\nͺ¿������ʵ��̫����.....��\n");
                command("thank "+this_player()->query("id"));
                return 1;
        }
        if (ob->query("name")==HIW"���÷���"NOR || ob->query("name")=="������") 
        {
                command("thank "+this_player()->query("id"));
                this_player()->set_temp("marks/silverant",1);
                if (ob->query("name")==HIW"���÷���") write("����������һ�£������������õ����÷��飬�ø�����ͺ¿�ްɣ�������.....��\n");
                        else write("����������һ�£������������õ������ӣ��ø�����ͺ¿�ްɣ�������.....��\n");
                return 1;
        }
        write("�����ϻ���ҡ��ҡͷ��\n");
        return 0;
}                 
int qi_yun()
{
        object me;
        object room;
        me = this_player();
        if (me->query("combat_exp")<1000000)
                return 0;
        message_vision("\n\n$N��$n����Ц��������Ҫ�����Ǹ���̬��������$N��ô�������﷢�յ�����\n",this_object(),me);
        message_vision("\n$N"HIR"Խ˵Խ�������ۿ�Ҫ���ɺ������ˣ�\n\n\n"NOR,this_object());
        this_player()->set_temp("marks/silverant",1);
        unconcious();
        return 1;
}    
