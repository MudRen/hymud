#include <ansi.h>
inherit F_MASTER;
inherit NPC;
int leave();
int show_me(); 
void create()
{
        set_name("�����", ({ "master chai","master","chai" }) );
        set("gender", "����" );
        set("long",
                "����ȧ������������һ�����ף������С���ü���Բϣ�˫Ŀϸ������\n΢΢�´���üĿ���������Ź⣬�������Ÿ߸����������Ĺ��ǣ���������\n�ȵ���Ȩ�������ǣ�Ҳ���������Ǿ��ǳ��˿ɱȵ���ʢ������\n");
        set("nickname", HIY"�������"NOR );
        set("apprentice_available", 5);
        set("class","knight");
        create_family("�����", 1, "����֮��");
        set("rank_nogen",1);
        set("ranks",({"����","��ʿ","����","������",HIC"����ͳ��"NOR,RED"������ʹ"NOR,HIR"������ʹ"NOR,HIY"һ�ֲ�����"NOR}));
        set("attitude", "peaceful");
        set("reward_npc", 1);
        set("difficulty", 40);
        set("age", 57);
        set("str", 100);
        set("cps", 100);
        set("int", 100);
        set("per", 10);
        set("cor", 40);
        set("agi", 80);
                
        set("combat_exp", 50000000);

        set("force", 2000);
        set("max_force", 2000);

        set("force_factor", 100);
        set_temp("apply/armor",300);
        set_temp("apply/attack", 200);
        set_temp("apply/damage", 50);
        set("chat_chance", 2);
        set("chat_msg", ({
                "��������۳��״�Ц�������մ�ϲ��ϣ������Ҳ������̤��ԭ֮ʱ��\n",
                "���������ҹ�Ɑ��һ�����£���Ц����׳־���ͺ�²�⣬Ц̸������ūѪ��\n����������������ƣ����յ�����ԭ�˵�Ѫ�ƣ�\n",
                }) ); 

        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "blade.tiandirenmo" :),
                (: perform_action, "dodge.lianhuanbabu" :),
                (: perform_action, "blade.tiandirenmo" :),
        }) );
        set("combat_exp", 50000000);
        set("score", 200000);

        set_skill("dodge", 200);
        set_skill("parry",200);
        set_skill("dodge", 200);
        set_skill("force", 200);
        set_skill("literate", 180);
	set_skill("unarmed",60);
	set_skill("demon-steps",500);
	set_skill("demon-strike",500);
	set_skill("demon-force",500);
	set_skill("blade",250);
	set_skill("demon-blade",550);
	set_skill("xuanyuan-axe",550);
        map_skill("dodge", "demon-steps");
	map_skill("force", "demon-force");
	map_skill("unarmed", "demon-strike");
	map_skill("blade","demon-blade");
	map_skill("axe","xuanyuan-axe");
	map_skill("parry","demon-blade");

set("pubmaster",1);
        set("max_neili", 55000);
        set("neili", 55000);
        set("force_factor", 30);
	set("max_qi",19999);
        set("max_jing",19999);
	set("eff_qi",19999);
	set("qi",19999);
	set("eff_jing",19999);
	set("jing",19999);
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 600);
        setup();
        carry_object(__DIR__"obj/mangpao")->wear();
        carry_object(__DIR__"obj/panguaxe")->wield();
        carry_object(__DIR__"obj/lightcup");
} 
void reset()
{
        set("apprentice_available", 5);
} 
int show_me() {
        object ob,me;
        me=this_player();
        ob=this_object();
        if (me->query("class")!="knight") {
                command("say �����廨���Ǳ���֮��������Ҵ���ʲô��");
                return 1;
        }
        
        if (me->query("marks/���ΰ�ɱ")) {
                command("say Ϊʦ������͸����������еĹؼ�����?");
                return 1;
        }
        
        command("say �廨��ԭ���置�¹�֮�����������ӽ���ȥ�ߴ�ݼ���ʳ������廨����");
        command("say ���ҿ���ֵĹ��������޵У��廨�����¹�֮��ʵ����ͳ��");
        command("say Ϊʦѧ�ô��պ�Ǳ�����У����������ϲ��Ʊ�һ�������ڶԵ�ʱ���������Ρ�");
        command("say ����������������ѧ��ɱ֮����ΪʦҲ�ɴ�����յ��¹�֮����");
        command("hmm");
        command("say ��Ϊʦ����Ĳ��Ʊ��㲻�����ã��������������������֮��Ц�ҿ�����޼���");
        tell_object(me,WHT"ѧ���¹�֮��������Ϊʦ�Ĳ��Ʊ̣����Ը�⣿��accept yes or no��\n"NOR);
        me->set_temp("kuaihuo/a_sk1",1);
        return 1;
} 
int do_accept(string arg)
{
    if(!this_player()->query_temp("kuaihuo/a_sk1")) return 0;
    if( arg == "no" )
    {
        command("say �ã���ͽ��������ֵĹ����㷢�����ˡ�");
        return 1;
    }
    else if( arg == "yes" )
    {
        command("say �˸���־��˵������Ҳ�ܽ��˼�������");
        tell_object(this_player(),"������ڰ���ʹ�ù�����ϲ��Ʊ��ˡ�\n");
        this_player()->set("marks/���ΰ�ɱ",1);
        return 1;
     }
    else  return 0;
}   
void attempt_apprentice(object ob)
{
        if( query("apprentice_available") ) 
        {
                if( find_call_out("do_recruit") != -1 )
                        command("say ������һ��һ������\n");
                else
                        call_out("do_recruit", 2, ob);
        } 
        else {
                command("say �Ϸ��Ѿ��չ��˵��ӣ����������ˡ�\n");
        }
} 
void do_recruit(object me)
{
        if( (string)me->query("class") != "knight" )
        {
            command("say ��ֻ�ձ��ŵ��ӣ��㻹����Ѱ��ʦ�ɣ�\n");
        }
        else if (!me->query("m_success/¥����Ե"))
        {
                command("say �Ϸ���֮����˵�ɣ�\n");
        }
        else if(!me->query_temp("marks/knight_win_dugu"))
        {
                switch ( random(2) )
                {
                        case 0:
                                command("say ���Ź��ɭ�ϣ��ȴ�Ӯ���ʦ���������ң�\n");
                                break;
                        case 1:
                                command("say ѧ��Ҫѭ�򽥽����㻹�Ǵ�û��������ɡ�\n");
                                break;
                }
        }
        else
        {
                command("say ������Ӣ�ţ���������ϣ������һ���������˰����Ǻǣ�\n");
           command("recruit " + me->query("id") );
        }
} 
void init()
{       
        object me;
        ::init();
        me = this_player();
        if( interactive(me) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 0, me);
        }
        add_action("do_answer","answer");
        add_action("do_accept","accept");
} 
void greeting(object me)
{
        object *inv;
        int i;
        object ob;
        ob = this_object();
        if( userp(me))
        {
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                {
                        if(inv[i]->query("owner")=="������" && (int)inv[i]->query("equipped"))
                        {
                                if (!me->query_temp("marks/chai_talkto_you"))
                                {
                                        message_vision(HIY"$NĿ���絶���������˹��������� \n"NOR,ob);
                                        message_vision(HIY"$N��׵��������ȥ��֪������ȥ�ٻ�����ױ��ϲ���Ƕ����ˣ�֪��ô��\n��answer yes or not) ��\n"NOR,ob);
                                        me->set_temp("marks/chai_talkto_you",1);
                                }
                                else
                                {
                                        message_vision(HIY"$N�ʵ��������������������\n"NOR,ob);    
                                }
                        }
           }
        }
} 
int do_answer(string arg)
{    
        object me;
        
        me=this_player();
        if (!arg) return notify_fail("�ش�ʲô��\n");
        if (!me->query_temp("marks/chai_talkto_you")) return notify_fail("�ش�ʲô��\n");
        if (arg == "yes")
        {
                message_vision("$N�Ϲ��Ͼ�����Ӧ����Ӧ��\n",me);
                me->set_temp("marks/chai_get_command",1);
                return 1;
        }
        else if (arg == "no")
        {
                message_vision("$N����΢һ��ԥ������ \n",me);
                message_vision("$N��ɫһ�����ô�ĵ������������Ļ����㵽���Ǻ��ˣ� ������ \n",this_object());
                me->delete_temp("marks/chai_talkto_you");
                this_object()->kill_ob(me);
                me->kill_ob(this_object());
                return 1;
        }
        else
                return notify_fail("�ش�ʲô��\n");
} 
int accept_object(object me, object obj)
{       
        object npc;
        object book;
        object *inv;
        int i;
        int j;
        j = 0;
        npc = this_object();
        if( userp(me))
        {
                inv = all_inventory(me);
           for(i=0; i<sizeof(inv); i++)
                {
                        if(inv[i]->query("owner")=="������" && (int)inv[i]->query("equipped"))
                        {
                                j = 1;
                        }
                }
        }
        if (me->query_temp("marks/knight_kill_wang") && obj->query("name") == "��ľ�����" && j == 1)
        {
                message_vision(HIY"$N��Ȼվ�𣬿������������������\n"NOR,npc);
                message_vision(HIY"$N�Բ�üһ���������Ц��������������Ī��������֪���ٺ٣����� \n"NOR,npc);
                message_vision(HIY"$N��������$n�ļ������ã��������Ϊ���������һ� ������ ��\n�Ȿ������Ǳ��õ����������ֺ����ں�ɽ��������˴����������޵б�����\n�����˴󹦣�����ȥ���аɣ� \n"NOR,npc,me);
                book = new(__DIR__"obj/book1");
                if (book) book->move(me);
                if (!me->query("m_success/¥����Ե"))
                {
                        me->add("score",200);
                        me->set("m_success/¥����Ե",1);
                }
                return 1;
        }
        else
                return notify_fail("���������΢Ц��ĬȻ���\n");     
} 
int leave() {
        if (this_player()->query("class")!="knight") return 0;
        message_vision(CYN"$Nһ������$n��ƨ���ϡ�\n"NOR, this_object(),this_player());
        message_vision(CYN"$N˵���Ժ������ԯ��ʹ�������ɱ���ҡ�\n"NOR,this_object(),this_player());
        message_vision(CYN"$N˵�������������廨��Ҳ�����¡�\n"NOR,this_object(),this_player());
        return 1;
}  
