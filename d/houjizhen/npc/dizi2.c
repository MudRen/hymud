// dizi2.c
//by dicky

inherit NPC;

void create()
{
        set_name("����ؤ", ({ "lao qigai", "qigai", "beggar" }) );
        set("long","����һ��������ؤ�����������ƣ����޲Բԣ���Ȼ���������ٷ�˪��\n");
	
        set("gender", "����");
        set("age", 60);
        set("attitude", "peaceful");
        set("shen_type", 0);
        set("str", 20);
        set("int", 16);
        set("con", 20);
        set("dex", 20);

        set("max_qi", 600);
        set("max_jing", 600);
        set("neili", 600);
        set("max_neili", 600);
        set("jiali", 30);
        set("combat_exp", 20000);

        set_skill("force", 70);
        set_skill("dodge", 70);
        set_skill("unarmed", 70);
        set_skill("parry", 70);


        setup();
 
}

