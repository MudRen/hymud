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
