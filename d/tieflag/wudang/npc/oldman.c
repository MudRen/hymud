 inherit NPC;
void create()
{
        set_name("����", ({ "old man", "man" }) );
        set("gender", "����");
        set("age", 54);
        set("long",
                "��λ�������������Եõس��ź��̡�\n"
        );
        set_skill("dagger", 10+random(50));
        setup();
        carry_object(__DIR__"obj/yandou")->wield();
}    
