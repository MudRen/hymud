inherit NPC;
#include "/d/migong/romnpc2.c"
#include <allnpc.h>

void create()
{
        set_name("�����", ({"lingkong zi", "zi"}));
        set("age", 90);
	set("attitude", "peaceful");
        set("gender", "����");
	set("class", "yaomo");
	set("title", "��ɽ�Ĳ�");
	set("nickname", "���׻���");
        set("str", 20);
        set("int", 20);
        set("per", 30);
        set("con", 20);
	set("max_jing", 1500);
        set("max_qi",2000);
        set("max_jing", 2000);
        set("combat_exp", 1000000);
  set("combat_exp", 42000000);


        set("neili", 1000);
        set("max_neili", 1000);
        set("neili",1500);
        set("max_neili", 1500);
        set("mana_factor", 100);
        set_skill("unarmed", 200);
        set_skill("force", 200);
        set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("spells", 200);
	set_skill("staff", 200);
        setup();
initlvl((550+random(550)),42);
	carry_object("/d/qujing/jingjiling/obj/zhang")->wield();
	carry_object("/d/qujing/jingjiling/obj/cloth")->wear();
}
int accept_fight(object ob)
{
	object me = this_object();
        object who=this_player();

        if(me->is_fighting() )
                return notify_fail("����Ӷ���˵��û���Ϸ���æ����ô��\n");
        if( (int)me->query("qi")*100/(int)me->query("max_qi") < 30 )
                return notify_fail("����Ӷ���˵���Ϸ��左�������Ȳ��ã��Ȳ��á�\n");

        if( who->query_temp("poem_hui") ) {

        command("say �ã��ã������д����գ��㵽Ϊֹ��\n");
	reset_me ();
	call_out ("check_fight",1,who);
        return 1;
        }
        command("say �Ҵ��Ϸ���һ����\n");
        who->set_temp("answer_hui", 1);
        call_out("ask_poem", 3, who);
        return 0;
}

void ask_poem(object who)
{
        object me=this_object();
        message_vision("$N��$n�ʵ��������³���ɽ�����¾���ʲô��\n", me, who);
        message_vision("$N˵���Ϸ�������ʮ���ڻش�(answer)��\n", me);
        me->set_temp("check_answer", 1);
        call_out("say_answer", 30);
        return;
}
void say_answer(object who)
{
    if(!who) return;
        command("sigh");
        command("say ���ⶼ��֪�����Ϸ�м����һ����\n");
        this_object()->delete_temp("check_answer");
        who->delete_temp("answer_hui");
        return ;
}

void init()
{
        add_action("do_answer", "answer");
}

int do_answer(string arg)
{
        object where=environment(this_object());

        if( !(this_object()->query_temp("check_answer") ) )
                return notify_fail("ʲô��\n");

        if( !arg ) return notify_fail("��˵ʲô��\n");

        message_vision("$N������ǡ�" + arg + "����\n", this_player());

        if( this_player()->query_temp("answer_hui") ) {

                if( strsrch(arg, "��ã�ƺ���") >=0  ) {
                command("haha");
                command("say ���������Ϸ����������С�\n");
                this_player()->set_temp("poem_hui", 1);
                this_player()->delete_temp("answer_hui");
                this_object()->delete_temp("check_answer");
  this_player()->set_temp("obstacle/jingjiling/"+this_object()->query("id"),1);
  this_object()->announce_success(this_player());                
this_object()->kill_ob(this_player());
        remove_call_out("say_answer");
                return 1;
                }else{
                command("sigh");
                command("say ���ԣ����ԣ�\n");
                return 1;
                }
        }else{
        command("sigh " + this_player()->query("id") );
        command("say ���죬���죡");
        return 1;
        }
}

