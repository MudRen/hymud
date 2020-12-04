// zhongling.c

inherit NPC;

void create()
{
        set_name("����", ({ "zhong ling","zhong" }) );
        set("gender", "Ů��" );
        set("age", 15);
        set("str", 16);
        set("con", 24);
        set("dex", 11);
        set("per", 27);
        set("int", 24);

        set("chat_chance", 1);
        set("chat_msg", ({
                "�����������������Ҫ���ҵ�������������ͺ��ˡ���\n",
        }) );

        set("inquiry", ([
                "����" : "�θ���أ������Ķ���",
                "����" : "�Ҿ������鰡��",
                "�ʱ���" : "�ʱ��������衣",
                "�����" : "��������ҵ���",
                "here" : "��������ٹȡ�",
                "ľ����" : "ľ���屻���ں����ʯ�����ȥ������",
        ]));

        set("attitude", "friendly");

        set("max_neili", 2000);
        set("neili", 2000);
        set("max_qi", 2000);
        set("qi", 2000);

        set("force_factor", 10);

        set("combat_exp", 35000);

        set_skill("finger", 60);
        set_skill("parry", 90);
        set_skill("dodge", 50);
        set_skill("sword", 30);
        set_skill("force", 50);
        set_skill("sun-finger",90);

        map_skill("finger", "sun-finger");
        map_skill("parry", "sun-finger");

        setup();

        carry_object("/d/wanjiegu/npc/obj/moon-dress")->wear();
        carry_object("/d/wanjiegu/npc/obj/shoes")->wear();
        carry_object("/d/wanjiegu/npc/obj/xiu-scarf")->wear();
}

void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) ) {
        message_vision("�����$N˵������ȥ��ľ��㣬ľ��㱻���ں����ʯ���\n",ob);
        }
}

int accept_object(object who, object ob)
{
        object *inv, sh;
        int i;

        inv = all_inventory(this_object());

        if (ob->query("id") == "shandian diao") {
            tell_object(who,"����˵����лл������һ�����������\n");
            tell_object(who,"����˵�����´����������ʱ�����������Ѿ��ؼ��ˡ�\n");
            who->set_temp("tlbb12",1);
            if(!sizeof(inv) )
                for ( i=0; i< sizeof(inv); i++ )
                    if ( inv[i]->name() == "�廨Ь" ) {
                        destruct(inv[i]);
                        tell_object("who, ��������һ˫�廨Ь��\n");
                        sh = new("/d/wanjiegu/npc/obj/shoes2");
                        tell_object(who, "����˵���������ҵ�һ˫�廨Ь���������������\n");
                        who->set_temp("tlbb12",1);
                        sh->move(who);
                        return 1;
                    }
            return 1;
        }
        return 0;
}

void die()
{
        int i;
        object killer;

        if(objectp(killer = query_temp("last_damage_from")))
            killer->set("marks/murder_zhongling", 1);
        message_vision("����������˵����ԭ�����������һ��ģ�\n", killer);

        ::die();
}

