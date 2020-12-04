 inherit NPC;
inherit F_VENDOR; 
void create()
{
        set_name("������", ({ "seller", "jadeseller" }) );
        set("gender", "����" );
        set("age", 49);
        set("title", "�����鱦");
        set("long", "����һλ�ʷ����ֵ��ƹ�\n");
        set("combat_exp", 1000000);
        set("reward_npc", 1);
        set("difficulty", 6);
        set("str", 60);
        set("attitude", "friendly");
        set_skill("dodge", 100);
        set_skill("parry", 120);
        set("vendor_goods", ({
                __DIR__"obj/jade1",
                __DIR__"obj/jade2",
                __DIR__"obj/jade3",
                __DIR__"obj/jade4",
        })); 
        setup();
        carry_object("/clone/misc/cloth")->wear();
} 
void init()
{
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_buy", "buy");add_action("do_list", "list");
        add_action("do_sell","sell");
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(10) ) {
                case 0:
                        say( " ���ƹ�Ц�ŵ�����λ"
                                + RANK_D->query_respect(ob)
                                + "�������� \n");
                        break;
                case 1:
                        say( " ���ƹ�Ц�ŵ�����λ"
                                + RANK_D->query_respect(ob)
                                + "�����Ǽ���֮���һ��ɡ� \n");
                        break;
                case 2:
                        say( " ���ƹ��������˵������λ"
                                + RANK_D->query_respect(ob)
                                + "��������������ר���޷�����\n�ġ������챦��....�ٺ�.... \n");
                        break; 
        }
} 
int do_sell(string arg)
{
        object ob;
        int value;
        if( !arg || !(ob = present(arg, this_player())) )
                return notify_fail("��Ҫ����ʲ����Ʒ��\n");
        if( this_player()->is_busy() )
                return notify_fail("����һ��������û����ɣ���������Ʒ��\n");
        if( ob->query("money_id") )     return notify_fail("��Ҫ����Ǯ����\n");
        value = ob->query("value");
        if( !(value/10) ) return notify_fail("������������ֵ�ܶ�Ǯ��\n");
        if (!ob->query("thief_obj"))
        {
                return notify_fail("���ƹ�ҡͷ�������겻��������Ʒ��\n");
        }
        message_vision("$N�����ϵ�" + ob->query("name") + "͵͵�������ƹ�....\n",this_player());
        command("whisper "+this_player()->query("id")+" �ֽ���̫���ۣ�Ǯ��ת�����Ϲ����е����ϡ�\n");
        command("snicker");
        this_player()->add("deposit",value/10);
        destruct(ob);
        this_player()->start_busy(1);
        return 1;
}
