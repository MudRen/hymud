// master4.c

inherit NPC;
inherit F_MASTER;

string ask_kao(object me);

void create()
{
        set_name("������", ({ "master zhong", "master", "zhong" }) );
        set("class","jinghai");
        create_family("������", 3, "������ȸ������");
        set("inquiry",([
	"kao" : (: ask_kao :),
	"����" : (: ask_kao :),
]));

        set("gender", "Ů��" );
        set("age", 25);
        set("attitude", "peaceful");

        set("long", "����һλ�ڽ������������꣬���˸о���
�����������ɵ�����Ů�ӣ������Ǿ�����ȸ��������\n");

        set("combat_exp", 800000);
        set("str", 30);
        set("per", 21);
        set("max_qi",2000);
        set("max_jing",2000);
        set("max_sen",2000);

        set("neili", 4500);
        set("max_neili", 4500);
        set("atman", 2500);
        set("max_atman", 2500);
        set("mana", 2500);
        set("max_mana", 2500);
        set("force_factor", 150);

        set_skill("jingyiforce",110);
        set_skill("demon-blade",100);
	set_skill("blade",120);
        set_skill("literate",120);
        set_skill("unarmed",120);
        set_skill("dodge",120);
        set_skill("parry",120);
        set_skill("force",120);
	//set_skill("doomsword",120);
        //set_skill("chilian-shenzhang",120);
        //set_skill("softsword",120);
        //set_skill("nine-moon-sword",140);
        //set_skill("luohua-jian",100);
        set_skill("sword",120);
        set_skill("feixian-sword",100);
        set_skill("bat-blade",100);
        set_skill("fengyu-piaoxiang",120);
	set_skill("changquan",120);

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
        if(ob->query("gender") == "����")
        {
                command("say ������е��ӣ�ȥ�����ҵ�ʦ���ǰɡ�");
                return;
        }

        else
        {
                command("smile");
                command("say �ܺã�" + RANK_D->query_respect(ob) + "���Ŭ�������ձض��гɡ�\n");
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
