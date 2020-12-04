// qiaoshou.c
#include <ansi.h>

inherit NPC;

string ask_me(object who);

void create()
{
        set("nickname", "Ů�����");
        set_name("��������", ({ "qiaoshou meimei", "meimei" }) );
        set("gender", "Ů��" );
        set("age", 16);

        set("long",@LONG
���������Ǵ�ͬ�������������ֱ����ˡ���
���׸�ĸ˫����������һ����֯����������
ѧ����һ�ֺõ��ֱ༼������˴�Ҷ�����
Ϊ���������á���������������ʵ�������
�����ǵ��ˡ�
LONG );

        set("combat_exp", 1000);
 
        set("chat_chance", 10);
        set("chat_msg", ({
                (: random_move :)
        }) );

        set("per",35);
        set("str", 20);
        set_skill("unarmed",50);
        setup();
 
        set("inquiry", ([
                "��֯" : "���Ьÿ��ʮ��ͭǮ��",
                "bian" : "���Ьÿ��ʮ��ͭǮ��",
                                "qu" : (: ask_me :),
                                "ȡ" : (: ask_me :),
]) );

        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        object ob;

        ::init();
        if ( interactive(ob = this_player()) )
        {
                remove_call_out("greeting");
                call_out("greeting", 2, ob);
        }
}
 
void greeting(object ob)
{
        if (ob->query_temp("quest_hlc_ok"))
    {
                tell_object(ob, CYN+this_object()->name()+"˵�������Ĳ�Ь���Ѿ�����ˣ�������ȡ (qu) �ɡ�\n"NOR);
        }
        else command(sprintf("wanfu %s", ob->query("id"))); 
}

int accept_fight(object me)
{
        command("say �����СŮ����ʲô��С���ҵ��ٸ�ȥ���㣡\n");
        return 0;
}
 
int accept_kill(object me)
{
        command("say ����СŮ�Ӷ���ɱ�����ߣ�\n");
        command(sprintf("say �Ժ���%s�����鷳СŮ�ӣ�",RANK_D->query_respect(me)));
                me->set("quest_hlc_hatemm", time()+600+random(600));
        return 0;
}

private void hlc_ok(object me,object ob)
{
        object *inv;
        int i;

        inv = all_inventory(ob);
        if( sizeof(inv)-1 >= 1 ) 
        {
                for(i=0; i<sizeof(inv); i++) 
                {
                        if( inv[i]->name() == "������" && 
                                inv[i]->query_master() == me->query("id") ) 
                                destruct(inv[i]);
                }
        }

        tell_object(me, "�����ʱ���࣬"+ob->name()+"�Ĳ�Ь���������ˡ�\n");

        me->delete_temp("quest_hlc_money");
        me->set_temp("quest_hlc_ok", 1);
        ob->stop_busy();
}

int accept_object(object me, object ob)
{
        object npc=this_object();
        object *inv;
        int i, num;

        if (time()<(int)me->query("quest_hlc_hatemm", 1))
        {
                write(CYN+npc->name()+"����˵�����ղŻ���ɱСŮ���أ������Ҫ���Ұ�æ��\n"NOR);
                return 0;
        }
        else me->delete("quest_hlc_hatemm");

        if (npc->is_busy())
        {
                write(CYN+npc->name()+"˵���������ڱ��Ь�������ȵ�һ�ᡣ\n"NOR);
                return 0;
        }

        if (ob->query("money_id"))
        {
                if (!me->query_temp("quest_hlc_money"))
                {
                        if (ob->value()==10)
                        {
                                write(CYN+npc->name()+"˵�����õģ���Ѻ����ݸ�СŮ�ӡ�\n"NOR);
                                me->set_temp("quest_hlc_money", 1);
                                return 1;
                        }
                        write(CYN+npc->name()+"˵�������Ьÿ��ʮ��ͭǮ��\n"NOR);
                        return 0;
                }
                write(CYN+npc->name()+"˵������������Ǯ�������ٸ���СŮ��Ц���ˣ�\n"NOR);
                return 1;
        }

        if(!me->query_temp("quest_hlc_money"))
        {
                command("shake");
                write(CYN+npc->name()+"˵�������Ьÿ��ʮ��ͭǮ����\n"NOR);
                return 0;
        }

        if (ob->name()!="������") return 0;

        if (ob->query_master() != me->query("id"))
        {
                write(CYN+npc->name()+"˵����"+RANK_D->query_respect(me)
                        +"��ô�ѱ��˵ĺ����������ˣ�\n"NOR);
                return 0;
        }

        inv = all_inventory(npc);
        num=0;

        if( sizeof(inv)-1 >= 1 ) 
        {
                for(i=0; i<sizeof(inv); i++) 
                {
                        if( inv[i]->name() == "������" && 
                                inv[i]->query_master() == me->query("id") ) 
                                num++;
                  }
        }

        if (!num)
        {
                num++;
                write(CYN+npc->name()+"˵����һ�Ѻ�����ֻ�����Ь�档\n"NOR);
                return 1;
        }
        else if (num>2)
        {
                command("hehe");
                write(CYN+npc->name()+"˵����������ô������ݣ����Ҹ�������ϯ��\n"NOR);
                return 0;
        }

        num++;

        write(CYN+npc->name()+"˵����СŮ����Ͱ������Ь��\n"NOR);
        message_vision("$N�ӹ�$n���еĺ����ݣ���ʼϸ�ĵر��Ь��\n", npc, me);

        call_out("hlc_ok",random(3)+4,me,npc);
        npc->start_busy(10);
        return 1;
}

string ask_me(object who)
{
        object xie;

        if (!who->query_temp("quest_hlc_ok"))
        {
                if (!random(3) && who->query("gender")=="����")
                {
                        command("shy");
                        return "ȡ��Ȣ������˵ҪȢСŮ����\n"
                                +"��ϧ����˵�Ҳ��ܼ޸���ң��������������ˡ�\n";
                }
                return 0;
        }

        if (is_busy()) this_object()->stop_busy();

        who->delete_temp("quest_hlc_ok");
        xie=new("/d/huashan/obj/xie");
        xie->set_master(who->query("id"));
        xie->move(who);

        return "�����Ь���һ����������Ь�������������֣��Ǻǡ�\n";
}

