 inherit NPC;
#define MONEY_VALUE 300000
#include <ansi.h> 
void create()
{
        set_name("���ƹ�", ({ "han zhanggui","zhanggui","han" }) );
        set("nickname","һ���");
        set("gender", "����" );
        set("age", 54);
        set("str", 22);
        set("cor", 30);
        set("cps", 30);
        set("int", 26);
        set("per", 23);
        set("con", 24);
        set("spi", 30);
        set("kar", 25);
        set("long",
"һ�����ӣ��������������������߽���������Ҫ˵��ʲô����ͷ�Ľ�\n�����ˡ�\n"); 
        set("combat_exp", 10000);
        set("no_arrest",1);
        set("inquiry", ([
                "����" : "������Ⱥɽ����������������Ӱ��ȥ���٣�\n",
                "rob" : "������Ⱥɽ����������������Ӱ��ȥ���٣�\n",
        ]) );
        setup();
        carry_object("/clone/misc/cloth")->wear();
} 
void init()
{
        object  ob;
        ::init();
        ob = this_player();
        call_out("greeting", 1, ob);
} 
int greeting(object ob)
{       
        if (random(100)>70 )
        {
        if(NATURE_D->get_current_day_phase() == 0)
     if ( 2>1 )
                {
                        message_vision("$N���ϸ�����һ�ֹ����Ц�ݡ�\n",this_object(),ob);
                        command("whisper "+ob->query("id")+" ������һ��纫��Ҳ�Ǻڵ��ϵĽǶ���\n�����ʹ��ˣ���ϴ�ֲ����ˣ�����������\n");
                        ob->set_temp("marks/���ƹ����",1);
                        command("grin");
                        return 1; 
                }
                else 
                {
                        command("heihei");
                        command("say С�����к�Щ�ö���������ô������ʵ�ڲ����㣬��Щ\n�����Ϲٲ�Ҳ�࣬��ү�������������ơ�");
                        return 1;
                }
        }
        else
                return 0;
} 
int accept_object(object me, object obj)
{       object hhs;
        object han;
        object room;
        
        han = this_object();
        room = environment(han);
        if (obj->query("name")=="��ƿ÷") {
                message_vision("$N��$n��Ц�ţ���ž����һ����һ�ο�ˮ�������ϡ�\n",han,me);
                me->set_temp("marks/��ƿ÷",1);
                return 1;
        }
        if (obj->query("name")=="������") {
                message_vision("$N��$nҡҡͷ������̾Ϣ���������Ź��ڴֲڣ����ã����ã���\n",han,me);
                return 1;
        } 
        if(NATURE_D->get_current_day_phase() == 0) 
        if ( 2>1 )
        { 
                if( (int) obj->value() >= (MONEY_VALUE+ random(MONEY_VALUE)) && !room->query("gived") && me->query_temp("marks/���ƹ����") && me->query_temp("marks/��ƿ÷"))
                {
                        command("grin");
                   command("say С������˽������ŮҲ������޵����������ͺ�ɢ��\n����Щ�ܹ��õ��ɺ�ҩ,��ңɢ��\n");
                        hhs = new(__DIR__"obj/hehesan");
                        if(hhs)
                        hhs->move(me);
                        room->set("gived",1);
                        message_vision("$N�ó�"+HIY "�����ͺ�ɢ"NOR+"��$n��\n",this_object(),me);
                        return 1;       
                }
                else
                {
                        command("heihei");
                        command("say ��л��λ" + RANK_D->query_respect(me) +"��ͷһ�μ���������ô�󷽵ģ�");
                        return 1;
                }
        }
        else
        {
                command("heihei");
                command("say ��л��λ" + RANK_D->query_respect(me) +"��ͷһ�μ���������ô�󷽵ģ�");
                return 1;
        }
        return 0;
} 
