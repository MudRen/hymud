//Writen by lnwm (May.28.1997)
//yunyou.c

inherit NPC;

string do_show();
void create()
{
    set_name("�η���ʿ", ({ "youfang daoshi","daoshi" }) );
    set("gender", "����" );
    set("age", 40);
    set("long",
"��һ���������۵ĵ���,�������糾����,��Ȼ�߹���Զ��·\n"
    );
    set("combat_exp", 100000);
    set("social_exp", 20000);
       set("force_factor", 10);
       set("max_force", 1000);
       set("force", 1000);


    set("inquiry", ([
        "����"          : "�Ҵ����ɽ��,ǡ��·���˵�",     
        "����ͷ��"      : (:do_show:),
        "����"          : "��ѽ,��������һ����",
        "��˭"          : "��˵©����,�Ǻ�,�ҿɲ��ܸ���������˭",
        ]) );

    set("chat_chance", 1);
    set("chat_msg",({
"���ε�ʿ���������˵:����˵�ľ�������ѽ.\n",
"���ε�ʿ�Ĵ�������,��������ʲô����.\n",
"���ε�ʿ̾�˿���:Ϊһ������ͷ��,������������ôԶ��·.\n",
(: random_move :),
        }) );
        
     setup();
     carry_object(__DIR__"obj/daopao")->wear();
}


string do_show()
{
    string msg;
    object ob,me;
    me = this_player();
    ob = this_object();
    command("sigh");
    command("say �Ҿ��ǹܲ�ס�Լ�,��������ҲҪ����˵©");
    command("say ��ʵ������Ҳ�޷�,�ҷ���������֮��,����һλ��ʦ��");
    command("say ���ĵ��Ž�����ң��,������ɽ��ʧ������30����");
    msg = "�����ˣ��ҵ����ˣ��������!!";
    command("shake");
    me->set_temp("marks/yunyou",1);
    call_out("destroy_me",1,ob);
    return msg;
}       

void destroy_me(object ob)
{
    destruct(ob);
}


