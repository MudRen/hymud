 // XXDER@FY
inherit NPC;
void create()
{
        set_name("���" , ({ "yaner", "yan er", "girl" }) );
        set("long", "һλʮһ�����СѾͷ��������Ū���ϵ�һ���ݱ����ơ�\n");
        set("attitude", "friendly");
/*      set("max_gin", 500);
        set("max_kee", 500);
        set("max_sen", 500); */
        set("age", 11);
        set("gender", "Ů��" );
        set("chat_chance", 20);
/*      set("str", 35);
        set("cor", 30);
        set("cps", 25); */
        set("combat_exp", 5000);
        set_skill("dodge", 50+random(50));
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/mazha");
}      
