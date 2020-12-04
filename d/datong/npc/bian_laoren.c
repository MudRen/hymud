// bian_laoren.c
#include <ansi.h>

inherit NPC;

string ask_me(object who);

void create()
{
        set("nickname", "�ܹ��ɽ�");
        set_name("�ֱ�����", ({ "shoubian laoren", "laoren" }) );
        set("gender", "����" );
        set("age", 61);

        set("long",@LONG
��λ�����Ǵ�ͬ��һ���ֹ��յ�ĵ�������
�ļ�����������˵����������һ��Ů������
�ڸ�����֯���ɡ�������ƺ��������ɻ
Ҳ����������æ����̫���˰ɡ�
LONG );

        set("combat_exp", 20000);
 
        set("chat_chance", 8);
        set("chat_msg", ({

                (: random_move :)
        }) );

        set("per",20);
        set("str", 30);
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
                tell_object(ob, CYN+this_object()->name()+"˵������Ь���Ѿ���������ˣ�������ȡ (qu) �ɡ�\n"NOR);
        }
        //else command(sprintf("wanfu %s", ob->query("id"))); 
}

int accept_fight(object me)
{
        command("say ���������ʲô���Ҷ�һ���Ϲ�ͷ�ˣ�\n");
        return 0;
}
 
int accept_kill(object me)
{
        command("say ��������ͷ�Ӷ���ɱ����\n");
        command(sprintf("say %s�����鷳�ң�",RANK_D->query_respect(me)));
                me->set("quest_hlc_hateyy", time()+600+random(600));
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

        tell_object(me, "�����"+ob->name()+"�Ĳ�ЬӦ�ñ����ˡ�\n");

        me->delete_temp("quest_hlc_money");
        me->set_temp("quest_hlc_ok", 1);
        ob->stop_busy();
}

int accept_object(object me, object ob)
{
        object npc=this_object();
        object *inv;
        int i, num;

        if (time()<(int)me->query("quest_hlc_hateyy", 1))
        {
                write(CYN+npc->name()+"��ü˵�����ղŻ���ɱ�ң���������Ұ�æ��\n"NOR);
                return 0;
        }
        else me->delete("quest_hlc_hateyy");

        if (npc->is_busy())
        {
                write(CYN+npc->name()+"˵����������æ�������ȵ�һ�ᡣ\n"NOR);
                return 0;
        }

        if (ob->query("money_id"))
        {
                if (!me->query_temp("quest_hlc_money"))
                {
                        if (ob->value()==10)
                        {
                                write(CYN+npc->name()+"˵�����õģ���Ѻ����ݸ��Ұɡ�\n"NOR);
                                me->set_temp("quest_hlc_money", 1);
                                return 1;
                        }
                        write(CYN+npc->name()+"˵�������Ьÿ��ʮ��ͭǮ��\n"NOR);
                        return 0;
                }
                write(CYN+npc->name()+"˵���������������ٸ�Ǯ���޹�����»���Ҳ�Ҫ��\n"NOR);
                return 0;
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
                        +"��ô�ѱ��˵ĺ����������ˣ���̫�ð�����\n"NOR );
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
                write(CYN+npc->name()+"˵����һ�Ѻ�����ֻ�����Ь�ס�\n"NOR);
                return 1;
        }
        else if (num>2)
        {
                command("hehe");
                write(CYN+npc->name()+"˵������������ô��ɲݣ����Ҹ������ñ��\n"NOR);
                return 0;
        }

        num++;

        write(CYN+npc->name()+"˵�����������Ѳݣ��Ҿ͸������Ь��\n"NOR);
        message_vision("$N�ӹ�$n���еĺ����ݣ���ʼ���ĵر��Ь��\n", npc, me);

        call_out("hlc_ok",random(4)+6,me,npc);
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
                        return "Ȣ���������Ļ�˵�ģ��Ҽҹ�Ů���������żҡ���\n";
                }
                return 0;
        }

        if (is_busy()) this_object()->stop_busy();

        who->delete_temp("quest_hlc_ok");
        xie=new(__DIR__"obj/xie");
        xie->set_master(who->query("id"));
        xie->move(who);

        return "������Ь������˵��Ь�����������֣��Ǻǡ�\n";
}

