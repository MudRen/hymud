 inherit NPC;
void create()
{
    set_name("��ũ", ({ "old farmer", "farmer" }) );
    set("gender", "����");
    set("age", 46);
    set("long",
        "һλ�����ʮ��ũ��\n"
        );
    set_skill("blade", 10+random(50));
    setup();
    carry_object(__DIR__"obj/liandao")->wield();
} 
int accept_object(object who, object ob)
{
    object          book1;
    object          book2;
    if( ob->name() == "����") {
        say("��ũ�ӹ�������˵������л��λ" + RANK_D->query_respect(who) + "�����������ء�\n");
        if( present("rice", ob) && present("qing cai", ob)) {
            say("��λ" + RANK_D->query_respect(who) +"����ϰ��֮�ˣ�����������ܶ������ã������¡�\n");
            book1 = new(__DIR__"obj/book");
            book1->move(who);
            book2 = new(__DIR__"obj/book");
            book2->move(who);
            return 1;
        }
        else {
            say("��ũ�򿪷������˿���˵�����ף���λ" + RANK_D->query_respect(who) + 
                "���ҵ���Ц������û�з���ѽ��\n");
            return 1;
        }
    }
    return 0;
}    
