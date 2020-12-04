
// monk.c

inherit NPC;

void create()
{
	set_name("��Ե����", ({ "monk" }) );
	set("gender", "����" );
	set("age", 46);
	set("str", 29);
	set("cor", 26);
	set("cps", 29);
	set("int", 22);
	set("per", 18);
	set("spi", 23);
	set("kar", 25);
	set("con", 27);
	set("long", @LONG
    ������Ǵ��ϱ�ɽ�������ģ���Ժ���ڴ˻�Եʩի��
LONG
);
	set("attitude", "friendly");
	set("chat_chance_combat", 15);
	set("chat_msg_combat", ({
		"���е����ҷ�ȱ�����ס�ֲ�������ҡ�\n"
	}) );
	set("inquiry", ([
		"ɽ����": "ƶɮ����ɽ�������ģ��Ӵ����б��ǡ�",
	]) );

        set("atman", 1000);
        set("max_atman", 1000);

        set("force", 500);
        set("max_force", 500);
        set("force_factor", 2);

        set("mana", 100);
        set("max_mana", 100);

        set("combat_exp", 10000);

        set_skill("staff", 60);
        set_skill("unarmed", 80);
        set_skill("force", 60);
        set_skill("dodge", 40);
        set_skill("literate", 50);
        set_skill("parry", 60);



	setup();

        carry_object("/clone/misc/cloth")->wear();
}

int accept_fight(object me)
{
        if( (string)me->query("class")=="bonze" )
                command("say �����ӷ𣡳����˽��ǿ�񶷣�ƶɮ����Υ����档");
        else
                command("say ʩ����Ȼ�����գ�ƶɮ������ǣ�Ҳ���ؽ����ˡ�");
	return 0;
}

void greeting(object ob)
{
        if( !ob || !present(ob, environment(this_object())) ) return;
        say( "����˵������λ" + RANK_D->query_respect(ob)
                + "��������Ǯ�ɡ�\n");
}

int accept_object(object who, object ob)
{
        int val;

        val = ob->value();
        if( !val )
                return notify_fail("���²�����Ʒ�ľ��ס�\n");
        else if( val > 100 ) {
                if( (who->query("bellicosity") > 0)
                &&      (random(val/10) > (int)who->query("kar")) )
                        who->add("bellicosity", - 
(random((int)who->query("kar")) + val/1000) );
        }
        say( "����˵������л��λ" + RANK_D->query_respect(who)
                + "������һ���ᱣ����ġ�\n");

        return 1;
}

