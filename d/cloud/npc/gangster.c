
// gangster.c

inherit NPC;

string kill_passenger(object who);

void create()
{
        set_name("������ǿ��", ({ "gangster" }) );
        set("gender", "����" );
        set("age", 27);
        set("str", 27);
        set("int", 12);
        set("per", 10);
        set("long", @LONG
��ǿ�������˰̣�����������һ���׺ݶ��Ե������ӡ�
LONG
);
        set("attitude", "heroism");
       set("shen_type",-1);

        set("combat_exp", 10000);

//        set("chat_chance", 1);
//        set("chat_msg", ({
//             "ǿ���ȵ���߾����ɽ���ҿ���
//���������ԡ�Ҫ��Ӵ˹���������·�ƣ�\n",
//              "ǿ�������������´�����һ����
//˵����ʶ��ķ���ʮ����·Ǯ�����·��\n",
//        }) );

        set("inquiry", ([
                "��·Ǯ": 
"����Ҳ������Ǯ�����ӣ���ү��ֻҪʮ��������˼һ�¡�\n",
        ]) );

//        set("chat_chance_combat", 1);
//        set("chat_msg_combat", ({
//              "ǿ�������Խ�Ϊ����������Ҫ��������\n",
//              "ǿ���ߺ��������˲����ա�\n",
//        }) );

        set_skill("unarmed", 100);
        set_skill("blade", 40);
        set_skill("dodge", 100);
        set_skill("parry", 100);


        setup();

        add_money("silver", random(5)); 
        carry_object("/clone/weapon/gangdao")->wield();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        object ob;
        ::init();
	ob=this_player();


        if( interactive(ob ) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob->query("marks/ǿ��") ) {
                set("chat_chance", 1);
                set("chat_msg", ({
                        
"ǿ���ȵ���߾����ɽ���ҿ������������ԡ�Ҫ��Ӵ˹������� 
��·�ƣ�\n",
                        
"ǿ�������������´�����һ����˵����ʶ��ķ���ʮ����·Ǯ 
�����·��\n",
                }) );
                kill_passenger(ob);
        }
}

int accept_object(object who, object ob)
{
        if( !who->query("marks/ǿ��") ) {
                if( ob->value() >= 100000 ) {
                        say("ǿ���ӹ�Ǯ���۾��ɵô��ģ����˵�ͷ��˵����
��ү�����������ˣ���������·�����������\n");
                        who->set("marks/ǿ��", 1);
                        return 1;
                } else {
                        say("ǿ�����������˿���ĭ��Ŀ¶�׹⣬˵����
���������ɫ���ǲ�֪����ү��������\n");
                        kill_passenger(who);
                        return 0;
                }
        } else
                
say("ǿ�����зų������Ĺ�ʣ�æ������Ц��������ʶ�࣬�Ժ��Ҳ���
��Ϊ��ġ�\n");
        return 1;
}

string kill_passenger(object who)
{
//        set("pursuer", 1);
        set("attitude", "aggressive");
        set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
                "ǿ�������Խ�Ϊ����������Ҫ��������\n",
                "ǿ���ߺ��������˲����ա�\n",
        }) );
        kill_ob(who);
        return 0;
}

int accept_fight(object me)
{
        command("say ����̫��үͷ�϶�������������");
        command("grin");
        kill_passenger(me);
        return 1;
}

 
