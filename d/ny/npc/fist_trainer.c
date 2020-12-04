
// trainer.c

inherit NPC;

void create()
{
        set_name("���ʨ", ({ "trainer", "lee" }) );
        set("title", "ȭ������");
        set("gender", "����" );
        set("age", 28);
        set("str", 26);
        set("int", 14);
        set("long",
                
"���ʨ�Ǹ����������Ĵ��ͷ��������ѵ�����ĵ�����ϰ��������ȭ\n"
                "����(liuh-ken)��\n" );
        set("combat_exp", 3000);
        set("attitude", "heroism");

        set("force", 120);
        set("max_force", 120);
        set("force_factor", 1);

        set("inquiry", ([
                "here": "���ﵱȻ�Ǵ�����ݣ���Ȼ�������\n",
                "name": "����������־ͽл�ʨ���˳����ͷ�ı����ҡ�\n",
                "����ȭ��": "Ŷ....˵��������С������ȭ����ûѧ�õ���, 
�������ͽ��������ﴫ�ա�\n"
        ]) );

        set_skill("unarmed", 130);

        set_skill("dodge", 130);
    

        setup();
}

int recognize_apprentice(object ob)
{
        if( (string)ob->query("family/family_name")=="��ɽ����" ) return 1;
        command("say �Բ�����λ" + RANK_D->query_respect(ob) + 
"��������������ݵĵ��ӡ�");
        return notify_fail( "���ʨ��Ը�����ȭ����\n");
}

int accept_fight(object me)
{
        if( (string)me->query("family/family_name")=="��ɽ����" ) {
                command("nod");
                command("say ���аɡ�");
                return 1;
        }
        command("say �����Ը����������������Ŀ��˹��С�");
        return 0;
}
 
