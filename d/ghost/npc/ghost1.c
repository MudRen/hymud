#include <ansi.h>
inherit NPC; 
void create()
{
        object          biao, bag; 
        set_name("����ʹ��", ({ "ghost" }) );
        set("gender", "����");
        set("per", 1);
        set("class", "ghost");
        create_family("����ɽׯ", 2, "����");
        set("combat_exp", 50000);
        set("long",
                "��������Ȼ�ѱ���һ����ƽ�ˡ�\n"
        );
        set("no_arrest",1);
        set_skill("move", 50);
        set_skill("dodge", 100);

        set_skill("sword", 340);
        set_skill("three-sword", 320);

        map_skill("sword", "three-sword");
        setup();
        carry_object(__DIR__"obj/clip2")->wield();
        carry_object(__DIR__"obj/cloth")->wear();
} 
void init()
{
        object          me; 
        ::init();
        if( interactive(me = this_player()) && !is_fighting() ) {
                add_action("do_accept", "accept");
                add_action("do_tell", "tell");
                call_out("greeting", 1, me);
        }
} 
int do_tell(string arg)
{
        string  obname, things;
        if(!arg || sscanf(arg, "%s %s", obname, things)!=2 )
                return notify_fail("tell <��> <��>\n");
        if(!this_player()->query_temp("marks/test")) return 0;
        this_player()->set_temp("marks/test", 0);
        if(obname == "ghost") {
                if(things == "no face" || things == "û����Ŀ" || things == "֪������") {
                        remove_call_out("do_test");
                        message_vision(HIY "\n$N��ɫ��ü�Ϊ�ѿ�����$n˵��������Թ�ȥ�ˡ�\n"NOR, this_object(), this_player());
                        this_player()->set_temp("marks/��Լ", 1);
        if(!this_player()->query("m_success/����ʹ��"))
        {
                this_player()->set("m_success/����ʹ��",1);
                this_player()->add("score",500); 
        }
                        return 1;
                }
        }
        return 0;
} 
int greeting(object me)
{
        if( (string)me->query("family/family_name")!="����ɽׯ" ) 
                message_vision(HIY "\n$N��$n˵��������ĺ�Լ���ҡ�\n"NOR, this_object(), me);
        else 
                message_vision(HIY "\n$N��$n˵����û�±��ȥ���ߡ�\n"NOR, this_object(), me);
        return 1;
} 
int accept_object(object who, object ob)
{
        if( (string)ob->name() == "����ɽׯ��Լ") {
                message_vision(HIY "\n$N�ӹ���Լ��$n˵��������Թ�ȥ�ˡ�\n"NOR, this_object(), who);
                who->set_temp("marks/��Լ", 1);
                return 1;
        } else {
                say(HIY "\n����ʹ��˵��������ʲô����û�к�Լ�������Թ�ȥ��\n"NOR);
                return 0;
        }
        return 0;
}  
int do_accept(string arg)
{
        if( arg != "test" ) {
                return notify_fail("��Ҫ����ʲô��\n");
        }
        remove_call_out("do_test");
        message_vision( HIY "$N˵�����ã����������ʱ��׼����\n"NOR, this_object());
        this_player()->set_temp("marks/test", 1);
        call_out("do_test", 15, this_player());
        return 1;
} 
int do_test(object me)
{
        int     kee; 
        if(objectp(me)) {
                me->set_temp("marks/test", 0);
                if(environment(me) == environment()) {
                        message_vision(HIY "\n$N˵����׼���ˣ�������һ�У�\n"NOR, this_object());
                        kee = (int)me->query("qi");
                        COMBAT_D->do_attack(this_object(), me, query_temp("weapon"));
                        if( (int)me->query("qi") < kee  || !present(me, environment())) { 
                                message_vision(HIY "\n$N˵��������һ�ж��Ӳ��£������Բ�������\n"NOR, this_object());
                                return 1;
                        }
                        else {
                                message_vision(HIY "\n$N��$n˵�����ù�������Թ�ȥ�ˡ�\n"NOR, this_object(), me);
                                me->set_temp("marks/��Լ", 1);
                                return 1;
                        }
                }
        }
        return 0;
}      
