 inherit NPC;
void create()
{
        set_name("С��", ({ "sad kid","kid" }) );
        set("gender", "����");
        set("age", 6);
        set("long",
                "һ���������С�������Ʋ��ֵ������﹡�ϡ�\n"
        );
        set("combat_exp",1000);
        setup();
        carry_object(__DIR__"obj/liandao")->wield();
}  
