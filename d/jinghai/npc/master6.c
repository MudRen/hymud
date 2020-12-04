inherit NPC;
inherit F_MASTER;

string ask_kao(object me);

void create()
{
        set_name("������", ({ "master song", "master", "song" }) );
        set("class","jinghai");
        create_family("������", 2, "����");
        set("inquiry",([
	"kao" : (: ask_kao :),
	"����" : (: ask_kao :),
]));

        set("gender", "����" );
        set("age", 26);
        set("attitude", "heroism");

        set("long", "һ�������ܲ��׽ӽ��������ˡ�
�����Ǿ��������Ŷ����ӡ�\n");

        set("combat_exp", 1800000);

        set("str", 40);
	set("kar",45);
        set("per", 26);

	set("max_qi",2500);
	set("max_jing",2500);
	set("max_sen",2500);

        set("neili", 4800);
        set("max_neili", 4800);
        set("atman", 4500);
        set("max_atman", 4500);
        set("mana", 4500);
        set("max_mana", 4500);
        set("force_factor", 150);

        set_skill("jingyiforce",220);
        set_skill("demon-blade",220);
        set_skill("literate",250);
        set_skill("unarmed",200);
        set_skill("dodge",220);
        set_skill("parry",220);
        set_skill("force",220);
        //set_skill("doomsword",220);
        //set_skill("chilian-shenzhang",220);
        //set_skill("softsword",240);
        //set_skill("nine-moon-sword",220);
        //set_skill("luohua-jian",200);
        set_skill("blade",220);
        set_skill("sword",220);
        set_skill("feixian-sword",220);
        set_skill("bat-blade",220);
        set_skill("fengyu-piaoxiang",220);
	set_skill("changquan",220);

	map_skill("unarmed","changquan");
        map_skill("force","jingyiforce");
        map_skill("dodge","fengyu-piaoxiang");
        map_skill("parry","feixian-sword");
        map_skill("sword","feixian-sword");

        setup();
        carry_object("/clone/weapon/gangjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
 
}

void attempt_apprentice(object ob)
{
/*
        if(ob->query("gender") == "Ů��")
        {
                command("say �Ҳ���Ů���ӣ�����........��");
                command("grin");
                return;
        }

	command("��������ŭ�ĺ��������ҹ��������ң�");
	return;
*/
	if(ob->query("class") != "jinghai")
		return;

	if(ob->query_skill("jingyiforce",1) < 110)
	{
		command("say ��ġ������ڹ�������̫���ȥ�ú�������˵�ɡ�");
		return;
	}


        else
        {
                command("smile");
                command("say ������ԣ�" + RANK_D->query_respect(ob) + "���Ŭ�������ձ������ɡ�\n");
                command("recruit " + ob->query("id") );
        }
}

int recruit_apprentice(object ob)
{
        ::recruit_apprentice(ob);
        ob->set("class", "jinghai");
        return 1;
}

string ask_kao(object me)
{
	object ob;

	if(!me || (me->query("class") != "jinghai"))
		return 0;

	if(me->query("quest/jinghai_quest/quest") != "ץ��")
		return "û�²��ú�������Ҫ�Ƕ�����ʲô��";

	ob = new(__DIR__"obj/kao");
	if(!ob)
		return 0;

	ob->move(this_object());

	command(sprintf("give liao kao to %s",me->query("id")));
	return "��Щ�˶������׼���֮ͽ��ҪС�����¡�";
}
