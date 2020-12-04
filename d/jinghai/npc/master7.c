// master7.c

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("�˳�", ({ "master chu", "master", "chu" }) );
        set("class","jinghai");
        set("title","[��ݲ��������]");


        set("gender", "����" );
        set("age", 28);
        set("attitude", "heroism");

        set("long", "����Ǿ�����ʼ�˷򸾵�С���ӡ�
�����Ǿ����������������������е��塣\n");

        set("combat_exp", 1600000);
        set("str", 40);
        set("per", 26);
        set("max_qi",2000);
        set("qi",2000);
        set("max_jing",2000);
        set("jing",2000);
        set("max_sen",2000);
        set("sen",2000);
        set("neili", 2800);
        set("max_neili", 2500);
        set("atman", 2500);
        set("max_atman", 2500);
        set("mana", 2500);
        set("max_mana", 2500);
        set("force_factor", 50);

        set_skill("jingyiforce",220);
        set_skill("demon-blade",220);
	set_skill("literate",250);
	set_skill("unarmed",200);
	set_skill("dodge",220);
	set_skill("parry",200);
	set_skill("changquan",220);
	set_skill("force",200);
	//set_skill("doomsword",220);
	//set_skill("chilian-shenzhang",220);
	//set_skill("softsword",240);
	//set_skill("nine-moon-sword",255);
	set_skill("luohua-jian",200);
	set_skill("sword",200);
	set_skill("feixian-sword",200);
	set_skill("bat-blade",200);
	set_skill("fengyu-piaoxiang",220);

        map_skill("force","jingyiforce");
        map_skill("dodge","fengyu-piaoxiang");
        map_skill("parry","nine-moon-sword");
        map_skill("sword","nine-moon-sword");

        setup();
        carry_object(__DIR__"obj/qiuyi")->wear();
        carry_object(__DIR__"obj/kao")->wear();
 
}

 
void attempt_apprentice(object ob)
{
        if(ob->query("gender") == "Ů��")
        {
                command("say �Ҳ���Ů���ӣ�ȥ�����ҵ�ʦ���ǰ�.....��");
                command("hehe");
                return;
        }




                command("smile");
                command("say ������ԣ�" + RANK_D->query_respect(ob) + "���Ŭ�������ձ������ɡ�\n");
                command("recruit " + ob->query("id") );

}

int recruit_apprentice(object ob)
{
        ::recruit_apprentice(ob);
        ob->set("class", "jinghai");
        return 1;
}

