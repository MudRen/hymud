
// keeper.c

inherit NPC;
inherit F_VENDOR;
/*
string ask_me(object who);
*/
mixed ask_me(mixed arg);

void create()
{
        set_name("��ף", ({ "keeper" }) );
        set("gender", "����" );
        set("age", 74);
        set("long",
                
"������˿�������ʮ�����ˣ����������͵���Ӱ�����Ȼ��������������������\n");
        set("combat_exp", 1);
        set("attitude", "friendly");
       set("inquiry", (["����":"�Ǻǡ�����Ҫ������Ҫ���˵�Ҫ��Ҫ��?(shenqing)",
]) );
        setup();
}

void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || !present(ob, environment(this_object())) ) return;
        say( "��ף˵������λ" + RANK_D->query_respect(ob)
                + "��������Ǯ�������°ɡ�\n");
}

int accept_object(object who, object ob)
{
        int val;

        val = ob->value();
        if( !val )
                return notify_fail("��ף������Ʒ�ľ��ס�\n");
        else if( val > 100 ) {
                if( (who->query("bellicosity") > 0)
                &&      (random(val/10) > (int)who->query("kar")) )
                        who->add("bellicosity", - 
(random((int)who->query("kar")) + val/1000) );
        }
        say( "��ף˵������л��λ" + RANK_D->query_respect(who)
                + "������һ���ᱣ����ġ�\n");

        return 1;
}
 